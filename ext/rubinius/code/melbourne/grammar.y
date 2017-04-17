/***********************************************************************

  parse.y -

  $Author: matz $
  $Date: 2004/11/29 06:13:51 $
  created at: Fri May 28 18:02:42 JST 1993

  Copyright (C) 1993-2003 Yukihiro Matsumoto

**********************************************************************/

%{

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

#include <string.h>

#include "namespace.h"
#include "melbourne.hpp"
#include "grammar.hpp"
#include "parser_state.hpp"
#include "visitor.hpp"
#include "symbols.hpp"

namespace MELBOURNE {

#undef TRUE
#undef FALSE

#define TRUE  true
#define FALSE false

#define TAB_WIDTH 8

#define numberof(array) (int)(sizeof(array) / sizeof((array)[0]))

static void parser_prepare(rb_parser_state*);
static int parser_yyerror(rb_parser_state*, const char *);
#define yy_error(msg)   parser_yyerror(parser_state, msg)
#define yyerror         parser_yyerror


#define is_notop_id(id) ((id)>tLAST_TOKEN)
#define is_local_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_LOCAL)
#define is_global_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_GLOBAL)
#define is_instance_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_INSTANCE)
#define is_attrset_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_ATTRSET)
#define is_const_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_CONST)
#define is_class_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_CLASS)
#define is_junk_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_JUNK)

#define is_asgn_or_id(id) ((is_notop_id(id)) && \
        (((id)&ID_SCOPE_MASK) == ID_GLOBAL || \
         ((id)&ID_SCOPE_MASK) == ID_INSTANCE || \
         ((id)&ID_SCOPE_MASK) == ID_CLASS))

# define SET_LEX_STATE(ls)  (lex_state = (lex_state_e)(ls))

static int yylex(void*, void *);

#define BITSTACK_PUSH(stack, n)   ((stack) = ((stack)<<1)|((n)&1))
#define BITSTACK_POP(stack)       ((stack) = (stack) >> 1)
#define BITSTACK_LEXPOP(stack)    ((stack) = ((stack) >> 1) | ((stack) & 1))
#define BITSTACK_SET_P(stack)     ((stack)&1)

#define COND_PUSH(n)    BITSTACK_PUSH(cond_stack, (n))
#define COND_POP()      BITSTACK_POP(cond_stack)
#define COND_LEXPOP()   BITSTACK_LEXPOP(cond_stack)
#define COND_P()        BITSTACK_SET_P(cond_stack)

#define CMDARG_PUSH(n)  BITSTACK_PUSH(cmdarg_stack, (n))
#define CMDARG_POP()    BITSTACK_POP(cmdarg_stack)
#define CMDARG_LEXPOP() BITSTACK_LEXPOP(cmdarg_stack)
#define CMDARG_P()      BITSTACK_SET_P(cmdarg_stack)

static int parser_arg_ambiguous(rb_parser_state*, char);
#define arg_ambiguous(c)   parser_arg_ambiguous(parser_state, c)

static void parser_token_info_push(rb_parser_state*, const char *);
static void parser_token_info_pop(rb_parser_state*, const char *);
#define token_info_push(token)  (RTEST(ruby_verbose) \
                                 ? parser_token_info_push(parser_state, token) \
                                 : (void)0)
#define token_info_pop(token)   (RTEST(ruby_verbose) \
                                 ? parser_token_info_pop(parser_state, token) \
                                 : (void)0)

static NODE *parser_cond(rb_parser_state*, NODE*);
static NODE *parser_logop(rb_parser_state*, enum node_type, NODE*, NODE*);

static NODE *parser_newline_node(rb_parser_state*,NODE*);
static void fixpos(NODE*,NODE*);

static int parser_value_expr(rb_parser_state*, NODE*);
static void parser_void_expr0(rb_parser_state*, NODE*);
static NODE* remove_begin(NODE*);
static void parser_void_stmts(rb_parser_state*, NODE*);

static void parser_block_dup_check(rb_parser_state*, NODE*, NODE*);
static NODE *parser_block_append(rb_parser_state*, NODE*, NODE*);
static NODE *parser_list_append(rb_parser_state*, NODE*, NODE*);
static NODE *list_concat(NODE*,NODE*);
static NODE *parser_arg_append(rb_parser_state*, NODE*, NODE*);
static NODE *parser_arg_concat(rb_parser_state*, NODE*, NODE*);
static NODE *parser_literal_concat(rb_parser_state*, NODE*, NODE*);
static int parser_literal_concat0(rb_parser_state*, VALUE, VALUE);
static NODE *parser_new_evstr(rb_parser_state*, NODE*);
static NODE *parser_evstr2dstr(rb_parser_state*, NODE*);
static NODE *parser_call_bin_op(rb_parser_state*, NODE*, ID, NODE*);
static NODE *parser_call_uni_op(rb_parser_state*, NODE*, ID);
static NODE *parser_new_args(rb_parser_state*, NODE*, NODE*, ID, NODE*, NODE*);
static NODE *parser_new_args_tail(rb_parser_state*, NODE*, ID, ID);
static NODE *splat_array(NODE*);

static NODE *parser_negate_lit(rb_parser_state*, NODE*);
static NODE *parser_ret_args(rb_parser_state*, NODE*);
static NODE *arg_blk_pass(NODE*,NODE*);
static NODE *parser_new_yield(rb_parser_state*, NODE*);
static NODE *parser_dsym_node(rb_parser_state*, NODE*);

static NODE *parser_gettable(rb_parser_state*,ID);
#define gettable(i) parser_gettable((rb_parser_state*)parser_state, i)
static NODE *parser_assignable(rb_parser_state*, ID, NODE*);
static ID parser_formal_argument(rb_parser_state*, ID);
static ID parser_shadowing_lvar(rb_parser_state*, ID);
static bool parser_lvar_defined(rb_parser_state*, ID);
static void parser_new_bv(rb_parser_state*, ID);
static const struct vtable* parser_bv_push(rb_parser_state*);
static void parser_bv_pop(rb_parser_state*, const struct vtable*);
static bool parser_in_block(rb_parser_state*);
static bool parser_bv_defined(rb_parser_state*, ID);
static int parser_bv_var(rb_parser_state*, ID);
static NODE *parser_aryset(rb_parser_state*, NODE*, NODE*);
static NODE *parser_attrset(rb_parser_state*, NODE*, ID, ID);
static void rb_parser_backref_error(rb_parser_state*, NODE*);
static NODE *parser_node_assign(rb_parser_state*, NODE*, NODE*);
static NODE *parser_new_op_assign(rb_parser_state*, NODE*, ID, NODE*);
static NODE *parser_new_attr_op_assign(rb_parser_state*, NODE*, ID, ID, ID, NODE*);
static NODE *parser_new_const_op_assign(rb_parser_state*, NODE*, ID, NODE*);

static NODE *parser_match_op(rb_parser_state*, NODE*, NODE*);
static int parser_arg_var(rb_parser_state*, ID);
static int parser_local_var(rb_parser_state*, ID);
static ID parser_internal_id(rb_parser_state*);

static void parser_local_push(rb_parser_state*, int cnt);
static void parser_local_pop(rb_parser_state*);
static bool parser_local_id(rb_parser_state*, ID);
static ID* parser_local_tbl(rb_parser_state*);
static ID convert_op(ID id);

static void parser_heredoc_dedent(rb_parser_state*, NODE*);
#define heredoc_dedent(str)   parser_heredoc_dedent(parser_state, (str))

rb_parser_state *parser_alloc_state() {
  rb_parser_state *parser_state = (rb_parser_state*)calloc(1, sizeof(rb_parser_state));

  lex_pbeg = 0;
  lex_p = 0;
  lex_pend = 0;
  parse_error = false;

  lex_io_buf = 0;
  lex_io_index = 0;
  lex_io_total = 0;
  lex_io_count = 0;

  eofp = false;
  command_start = true;
  class_nest = 0;
  in_single = 0;
  in_def = 0;
  brace_nest = 0;
  compile_for_eval = 0;
  cur_mid = 0;
  heredoc_end = 0;
  heredoc_indent = 0;
  heredoc_line_indent = 0;
  tokenbuf = NULL;
  tokidx = 0;
  toksiz = 0;
  locals_table = 0;
  memory_cur = NULL;
  memory_last_addr = NULL;
  current_pool = 0;
  pool_size = 0;
  memory_size = 204800;
  memory_pools = NULL;
  emit_warnings = 0;
  verbose = RTEST(ruby_verbose);
  start_lines = new std::list<StartPosition>;

  processor = 0;
  references = rb_ary_new();

  parser_state->enc = parser_utf8_encoding();

  return parser_state;
}

void *pt_allocate(rb_parser_state* parser_state, int size) {
  void *cur;

  if(!memory_cur || ((memory_cur + size) >= memory_last_addr)) {
    if(memory_cur) current_pool++;

    if(current_pool == pool_size) {
      pool_size += 10;
      if(memory_pools) {
        memory_pools = (void**)realloc(memory_pools, sizeof(void*) * pool_size);
      } else {
        memory_pools = (void**)malloc(sizeof(void*) * pool_size);
      }
    }
    memory_pools[current_pool] = malloc(memory_size);
    memory_cur = (char*)memory_pools[current_pool];
    memory_last_addr = memory_cur + memory_size - 1;
  }

  cur = (void*)memory_cur;
  memory_cur = memory_cur + size;

  return cur;
}

void pt_free(rb_parser_state* parser_state) {
  int i;

  free(tokenbuf);
  local_vars_free(locals_table);

  delete start_lines;

  if(lex_io_buf) free(lex_io_buf);

  if(!memory_pools) return;

  for(i = 0; i <= current_pool; i++) {
    free(memory_pools[i]);
  }
  free(memory_pools);
}

#define SHOW_PARSER_WARNS 0

static void rb_compile_warn(const char *file, int line, const char *fmt, ...);
static void rb_compile_warning(const char *file, int line, const char *fmt, ...);

static int rb_compile_error(rb_parser_state* parser_state, const char *fmt, ...) {
  va_list ar;
  char msg[256];
  int count;

  va_start(ar, fmt);
  count = vsnprintf(msg, 256, fmt, ar);
  va_end(ar);

  yy_error(msg);

  return count;
}

static void
rb_name_error(ID id, const char *fmt, ...)
{
  char msg[BUFSIZ];
  VALUE exc, argv[2];
  va_list args;

  va_start(args, fmt);
  vsnprintf(msg, BUFSIZ, fmt, args);
  argv[0] = rb_str_new2(msg);
  va_end(args);

  argv[1] = ID2SYM(id);
  exc = rb_class_new_instance(2, argv, rb_eNameError);
  rb_exc_raise(exc);
}

static int _debug_print(const char *fmt, ...) {
#if SHOW_PARSER_WARNS
  va_list ar;
  int i;

  va_start(ar, fmt);
  i = vprintf(fmt, ar);
  va_end(ar);
  return i;
#else
  return 0;
#endif
}

#define rb_warn _debug_print
#define rb_warning _debug_print

void push_start_line(rb_parser_state* parser_state, int line, const char* which) {
  start_lines->push_back(StartPosition(line, which));
}

#define PUSH_LINE(which) push_start_line((rb_parser_state*)parser_state, sourceline, which)

void pop_start_line(rb_parser_state* parser_state) {
  start_lines->pop_back();
}

#define POP_LINE() pop_start_line((rb_parser_state*)parser_state)

static ID rb_id_attrset(ID);

static int scan_oct(const char *start, size_t len, size_t *retlen);
static int scan_hex(const char *start, size_t len, size_t *retlen);

#define logop(t, a, b)            parser_logop(parser_state, t, a, b)
#define cond(n)                   parser_cond(parser_state, n)
#define newline_node(n)           parser_newline_node(parser_state, n)
#define void_stmts(n)             parser_void_stmts(parser_state, n)
#define block_dup_check(a, b)     parser_block_dup_check(parser_state, a, b)
#define block_append(a, b)        parser_block_append(parser_state, a, b)
#define arg_append(a, b)          parser_arg_append(parser_state, a, b)
#define arg_concat(a, b)          parser_arg_concat(parser_state, a, b)
#define list_append(l, i)         parser_list_append(parser_state, l, i)
#define node_assign(a, b)         parser_node_assign(parser_state, a, b)
#define new_op_assign(l, o, r)    parser_new_op_assign(parser_state, l, o, r)
#define new_attr_op_assign(l,t,a,o,r) parser_new_attr_op_assign(parser_state, l, t, a, o, r)
#define new_const_op_assign(l,o,r)  parser_new_const_op_assign(parser_state, l, o, r)
#define call_bin_op(a, s, b)      parser_call_bin_op(parser_state, a, s, b)
#define call_uni_op(n, s)         parser_call_uni_op(parser_state, n, s)
#define new_args(f,o,r,p,t)       parser_new_args(parser_state, f, o, r, p, t)
#define new_args_tail(k,kr,b)     parser_new_args_tail(parser_state, k, kr, b)
#define negate_lit(n)             parser_negate_lit(parser_state, n)
#define ret_args(n)               parser_ret_args(parser_state, n)
#define assignable(a, b)          parser_assignable(parser_state, a, b)
#define formal_argument(n)        parser_formal_argument(parser_state, n)
#define lvar_defined(n)           parser_lvar_defined(parser_state, n)
#define shadowing_lvar(n)         parser_shadowing_lvar(parser_state, n)
#define new_bv(n)                 parser_new_bv(parser_state, n)
#define bv_push()                 parser_bv_push(parser_state)
#define bv_pop(l)                 parser_bv_pop(parser_state, l)
#define in_block()                parser_in_block(parser_state)
#define bv_defined(n)             parser_bv_defined(parser_state, n)
#define bv_var(n)                 parser_bv_var(parser_state, n)
#define aryset(a, b)              parser_aryset(parser_state, a, b)
#define attrset(n, q, id)         parser_attrset(parser_state, n, q, id)
#define match_op(a, b)            parser_match_op(parser_state, a, b)
#define new_yield(n)              parser_new_yield(parser_state, n)
#define dsym_node(n)              parser_dsym_node(parser_state, n)
#define evstr2dstr(n)             parser_evstr2dstr(parser_state, n)
#define literal_concat(a, b)      parser_literal_concat(parser_state, a, b)
#define literal_concat0(a, b)     parser_literal_concat0(parser_state, a, b)
#define new_evstr(n)              parser_new_evstr(parser_state, n)

#define value_expr(n)             parser_value_expr(parser_state, n)
#define void_expr0(n)             parser_void_expr0(parser_state, n)
#define void_expr(n)              void_expr0(((n) = remove_begin(n)))

#define local_tbl()               parser_local_tbl(parser_state)
#define arg_var(a)                parser_arg_var(parser_state, a)
#define local_var(a)              parser_local_var(parser_state, a)
#define internal_id()             parser_internal_id(parser_state)

#define compile_error(s)          rb_compile_error(parser_state, s)
#define rb_backref_error(s)       rb_parser_backref_error(parser_state, s)

#define get_id(id)                (id)
#define get_value(value)          (value)

#define local_push(cnt)           parser_local_push(parser_state, cnt)
#define local_pop()               parser_local_pop(parser_state)
#define local_id(i)               parser_local_id(parser_state, i)

#define rb_warn0(fmt)             rb_compile_warn(sourcefile, sourceline, fmt)
#define rb_warnI(fmt,a)           rb_compile_warn(sourcefile, sourceline, fmt, a)
#define rb_warnS(fmt,a)           rb_compile_warn(sourcefile, sourceline, fmt, a)
#define rb_warning0(fmt)          rb_compile_warning(sourcefile, sourceline, fmt)
#define rb_warningS(fmt,a)        rb_compile_warning(sourcefile, sourceline, fmt, a)


#ifndef RE_OPTION_IGNORECASE
#define RE_OPTION_IGNORECASE         (1)
#endif

#ifndef RE_OPTION_EXTENDED
#define RE_OPTION_EXTENDED           (2)
#endif

#ifndef RE_OPTION_MULTILINE
#define RE_OPTION_MULTILINE          (4)
#endif

/* Must match up with options/kcode definitions in regexp.rb and regexp.cpp */
#define RE_OPTION_DONT_CAPTURE_GROUP (128)
#define RE_OPTION_CAPTURE_GROUP      (256)
#define RE_KCODE_NONE                (1 << 9)
#define RE_KCODE_EUC                 (2 << 9)
#define RE_KCODE_SJIS                (3 << 9)
#define RE_KCODE_UTF8                (4 << 9)
#define RE_OPTION_ONCE               (8192)

#define NODE_STRTERM NODE_ZARRAY        /* nothing to gc */
#define NODE_HEREDOC NODE_ARRAY         /* 1, 3 to gc */
#define SIGN_EXTEND(x,n) (((1<<((n)-1))^((x)&~(~0<<(n))))-(1<<((n)-1)))
#define nd_func u1.id
#if SIZEOF_SHORT != 2
#define nd_term(node) SIGN_EXTEND((node)->u2.id, (CHAR_BIT*2))
#else
#define nd_term(node) ((signed short)(node)->u2.id)
#endif
#define nd_paren(node) (char)((node)->u2.id >> (CHAR_BIT*2))
#define nd_nest u3.cnt

#define UTF8_ENC()            (parser_state->utf8 ? parser_state->utf8 : \
                                (parser_state->utf8 = parser_utf8_encoding()))
#define STR_NEW(p,n)          parser_enc_str_new((p), (n), parser_state->enc)
#define STR_NEW0()            parser_enc_str_new(0, 0, parser_state->enc)
#define STR_NEW2(p)           parser_enc_str_new((p), strlen(p), parser_state->enc)
#define STR_NEW3(p,n,e,func)  parser_str_new(parser_state, (p), (n), (e), \
                                            (func), parser_state->enc)
#define ENC_SINGLE(cr)        ((cr)==ENC_CODERANGE_7BIT)
#define TOK_INTERN()          parser_intern3(tok(), toklen(), parser_state->enc)

#define NEW_BLOCK_VAR(b, v)   NEW_NODE(NODE_BLOCK_PASS, 0, b, v)
#define NEW_REQ_KW            NEW_LIT(ID2SYM(parser_intern("*")))

/* Older versions of Yacc set YYMAXDEPTH to a very low value by default (150,
   for instance).  This is too low for Ruby to parse some files, such as
   date/format.rb, therefore bump the value up to at least Bison's default. */
#ifdef OLD_YACC
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif
#endif

%}

%pure-parser
%parse-param {rb_parser_state* parser_state}
%lex-param {rb_parser_state* parser_state}

%union {
    VALUE val;
    NODE *node;
    ID id;
    int num;
    const struct vtable* vars;
}

%token
  keyword_class
  keyword_module
  keyword_def
  keyword_defm
  keyword_fun
  keyword_funm
  keyword_undef
  keyword_begin
  keyword_rescue
  keyword_ensure
  keyword_end
  keyword_if
  keyword_unless
  keyword_then
  keyword_elsif
  keyword_else
  keyword_case
  keyword_when
  keyword_while
  keyword_until
  keyword_for
  keyword_break
  keyword_next
  keyword_redo
  keyword_retry
  keyword_in
  keyword_do
  keyword_do_cond
  keyword_do_block
  keyword_do_LAMBDA
  keyword_return
  keyword_yield
  keyword_super
  keyword_self
  keyword_nil
  keyword_true
  keyword_false
  keyword_and
  keyword_or
  keyword_not
  modifier_if
  modifier_unless
  modifier_while
  modifier_until
  modifier_rescue
  keyword_alias
  keyword_defined
  keyword_BEGIN
  keyword_END
  keyword__LINE__
  keyword__FILE__
  keyword__ENCODING__

%token <id>   tIDENTIFIER tFID tGVAR tIVAR tCONSTANT tCVAR tLABEL
%token <node> tINTEGER tFLOAT tRATIONAL tIMAGINARY tSTRING_CONTENT tCHAR
%token <node> tNTH_REF tBACK_REF
%token <num>  tREGEXP_END

%type <node> singleton strings string string1 xstring regexp
%type <node> string_contents xstring_contents regexp_contents string_content
%type <node> words symbols symbol_list qwords qsymbols word_list qword_list qsym_list word
%type <node> literal numeric simple_numeric dsym cpath
%type <node> top_compstmt top_stmts top_stmt
%type <node> bodystmt compstmt stmts stmt_or_begin stmt expr arg primary command command_call method_call
%type <node> expr_value arg_value primary_value fcall
%type <node> if_tail opt_else case_body cases opt_rescue exc_list exc_var opt_ensure
%type <node> args call_args opt_call_args
%type <node> paren_args opt_paren_args args_tail opt_args_tail block_args_tail opt_block_args_tail
%type <node> command_args aref_args opt_block_arg block_arg var_ref var_lhs
%type <node> command_asgn mrhs mrhs_arg superclass block_call block_command
%type <node> f_block_optarg f_block_opt
%type <node> f_arglist f_args f_arg f_arg_item f_optarg f_marg f_marg_list f_margs
%type <node> assoc_list assocs assoc undef_list backref string_dvar for_var
%type <node> block_param opt_block_param block_param_def f_opt
%type <node> f_kwarg f_kw f_block_kwarg f_block_kw
%type <node> bv_decls opt_bv_decl bvar
%type <node> lambda f_larglist lambda_body
%type <node> brace_block cmd_brace_block do_block lhs none fitem
%type <node> mlhs mlhs_head mlhs_basic mlhs_item mlhs_node mlhs_post mlhs_inner
%type <id>   fsym keyword_variable user_variable sym symbol operation operation2 operation3
%type <id>   cname fname op f_rest_arg f_block_arg opt_f_block_arg f_norm_arg f_bad_arg
%type <id>   f_kwrest f_label f_arg_asgn call_op call_op2

%token END_OF_INPUT 0   "end-of-input"
%token tUPLUS           /* unary+ */
%token tUMINUS          /* unary- */
%token tPOW             /* ** */
%token tCMP             /* <=> */
%token tEQ              /* == */
%token tEQQ             /* === */
%token tNEQ             /* != */
%token tGEQ             /* >= */
%token tLEQ             /* <= */
%token tANDOP           /* && */
%token tOROP            /* || */
%token tMATCH           /* =~ */
%token tNMATCH          /* !~ */
%token tDOT2            /* .. */
%token tDOT3            /* ... */
%token tAREF            /* [] */
%token tASET            /* []= */
%token tLSHFT           /* << */
%token tRSHFT           /* >> */
%token tANDDOT          /* &. */
%token tCOLON2          /* :: */
%token tCOLON3          /* :: at EXPR_BEG */
%token <id> tOP_ASGN    /* +=, -=  etc. */
%token tASSOC           /* => */
%token tLPAREN          /* ( */
%token tLPAREN_ARG      /* ( */
%token tRPAREN          /* ) */
%token tLBRACK          /* [ */
%token tLBRACE          /* { */
%token tLBRACE_ARG      /* { arg */
%token tSTAR            /* * */
%token tDSTAR           /* **arg */
%token tAMPER           /* & */
%token tLAMBDA          /* -> */
%token tSYMBEG tSTRING_BEG tXSTRING_BEG tREGEXP_BEG tWORDS_BEG tQWORDS_BEG tSYMBOLS_BEG tQSYMBOLS_BEG
%token tSTRING_DBEG tSTRING_DEND tSTRING_DVAR tSTRING_END tLAMBEG tLABEL_END

/*
 *      precedence table
 */

%nonassoc tLOWEST
%nonassoc tLBRACE_ARG

%nonassoc  modifier_if modifier_unless modifier_while modifier_until
%left  keyword_or keyword_and
%right keyword_not
%nonassoc keyword_defined
%right '=' tOP_ASGN
%left modifier_rescue
%right '?' ':'
%nonassoc tDOT2 tDOT3
%left  tOROP
%left  tANDOP
%nonassoc  tCMP tEQ tEQQ tNEQ tMATCH tNMATCH
%left  '>' tGEQ '<' tLEQ
%left  '|' '^'
%left  '&'
%left  tLSHFT tRSHFT
%left  '+' '-'
%left  '*' '/' '%'
%right tUMINUS_NUM tUMINUS
%right tPOW
%right '!' '~' tUPLUS

%token tLAST_TOKEN

%%
program         : {
                    SET_LEX_STATE(EXPR_BEG);
                    local_push(0);
                    class_nest = 0;
                  }
                  top_compstmt
                  {
                    if($2 && !compile_for_eval) {
                      /* last expression should not be void */
                      if(nd_type($2) != NODE_BLOCK) {
                        void_expr($2);
                      } else {
                        NODE *node = $2;
                        while(node->nd_next) {
                          node = node->nd_next;
                        }
                        void_expr(node->nd_head);
                      }
                    }
                    top_node = block_append(top_node, $2);
                    class_nest = 0;
                    local_pop();
                  }
                ;

top_compstmt    : top_stmts opt_terms
                  {
                    void_stmts($1);
                    $$ = $1;
                  }
                ;

top_stmts       : none
                  {
                    $$ = NEW_BEGIN(0);
                  }
                | top_stmt
                  {
                    $$ = newline_node($1);
                  }
                | top_stmts terms top_stmt
                  {
                    $$ = block_append($1, newline_node($3));
                  }
                | error top_stmt
                  {
                    $$ = remove_begin($2);
                  }
                ;

top_stmt        : stmt
                | keyword_BEGIN
                  {
                    if(in_def || in_single) {
                      yy_error("BEGIN in method");
                    }
                  }
                  '{' top_compstmt '}'
                  {
                    $$ = NEW_PREEXE($4);
                  }
                ;

bodystmt        : compstmt
                  opt_rescue
                  opt_else
                  opt_ensure
                  {
                    $$ = $1;
                    if($2) {
                      $$ = NEW_RESCUE($1, $2, $3);
                    } else if($3) {
                      rb_warn("else without rescue is useless");
                      $$ = block_append($$, $3);
                    }
                    if($4) {
                      if($$) {
                        $$ = NEW_ENSURE($$, $4);
                      } else {
                        $$ = block_append($4, NEW_NIL());
                      }
                    }
                    fixpos($$, $1);
                  }
                ;

compstmt        : stmts opt_terms
                  {
                    void_stmts($1);
                    $$ = $1;
                  }
                ;

stmts           : none
                  {
                    $$ = NEW_BEGIN(0);
                  }
                | stmt_or_begin
                  {
                    $$ = newline_node($1);
                  }
                | stmts terms stmt_or_begin
                  {
                    $$ = block_append($1, newline_node($3));
                  }
                | error stmt
                  {
                    $$ = remove_begin($2);
                  }
                ;

stmt_or_begin   : stmt
                  {
                    $$ = $1;
                  }
                | keyword_BEGIN
                  {
                    yy_error("BEGIN is permitted only at toplevel");
                  }
                '{' top_compstmt '}'
                  {
                    $$ = NEW_BEGIN(0);
                  }
                ;

stmt            : keyword_alias fitem {SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);} fitem
                  {
                    $$ = NEW_ALIAS($2, $4);
                  }
                | keyword_alias tGVAR tGVAR
                  {
                    $$ = NEW_VALIAS($2, $3);
                  }
                | keyword_alias tGVAR tBACK_REF
                  {
                    char buf[2];
                    buf[0] = '$';
                    buf[1] = (char)$3->nd_nth;
                    $$ = NEW_VALIAS($2, parser_intern2(buf, 2));
                  }
                | keyword_alias tGVAR tNTH_REF
                  {
                    yy_error("can't make alias for the number variables");
                    $$ = NEW_BEGIN(0);
                  }
                | keyword_undef undef_list
                  {
                    $$ = $2;
                  }
                | stmt modifier_if expr_value
                  {
                    $$ = NEW_IF(cond($3), remove_begin($1), 0);
                    fixpos($$, $3);
                  }
                | stmt modifier_unless expr_value
                  {
                    $$ = NEW_UNLESS(cond($3), remove_begin($1), 0);
                    fixpos($$, $3);
                  }
                | stmt modifier_while expr_value
                  {
                    if($1 && nd_type($1) == NODE_BEGIN) {
                      $$ = NEW_WHILE(cond($3), $1->nd_body, 0);
                    } else {
                      $$ = NEW_WHILE(cond($3), $1, 1);
                    }
                  }
                | stmt modifier_until expr_value
                  {
                    if($1 && nd_type($1) == NODE_BEGIN) {
                      $$ = NEW_UNTIL(cond($3), $1->nd_body, 0);
                    } else {
                      $$ = NEW_UNTIL(cond($3), $1, 1);
                    }
                  }
                | stmt modifier_rescue stmt
                  {
                    NODE *resq = NEW_RESBODY(0, remove_begin($3), 0);
                    $$ = NEW_RESCUE(remove_begin($1), resq, 0);
                  }
                | keyword_END '{' compstmt '}'
                  {
                    if(in_def || in_single) {
                      rb_warn("END in method; use at_exit");
                    }

                    $$ = NEW_POSTEXE(NEW_NODE(NODE_SCOPE,
                            0 /* tbl */, $3 /* body */, 0 /* args */));
                  }
                | command_asgn
                | mlhs '=' command_call
                  {
                    value_expr($3);
                    $1->nd_value = $3;
                    $$ = $1;
                  }
                | var_lhs tOP_ASGN command_call
                  {
                    value_expr($3);
                    $$ = new_op_assign($1, $2, $3);
                  }
                | primary_value '[' opt_call_args rbracket tOP_ASGN command_call
                  {
                    NODE *args;

                    value_expr($6);
                    if(!$3) $3 = NEW_ZARRAY();
                    args = arg_concat($3, $6);
                    if($5 == tOROP) {
                      $5 = 0;
                    } else if($5 == tANDOP) {
                      $5 = 1;
                    } else {
                      $5 = convert_op($5);
                    }
                    $$ = NEW_OP_ASGN1($1, $5, args);
                    fixpos($$, $1);
                  }
                | primary_value call_op tIDENTIFIER tOP_ASGN command_call
                  {
                    value_expr($5);
                    $$ = new_attr_op_assign($1, $2, $3, $4, $5);
                  }
                | primary_value call_op tCONSTANT tOP_ASGN command_call
                  {
                    value_expr($5);
                    $$ = new_attr_op_assign($1, $2, $3, $4, $5);
                  }
                | primary_value tCOLON2 tCONSTANT tOP_ASGN command_call
                  {
                    $$ = NEW_COLON2($1, $3);
                    $$ = new_const_op_assign($$, $4, $5);
                  }
                | primary_value tCOLON2 tIDENTIFIER tOP_ASGN command_call
                  {
                    value_expr($5);
                    $$ = new_attr_op_assign($1, parser_intern("::"), $3, $4, $5);
                  }
                | backref tOP_ASGN command_call
                  {
                    rb_backref_error($1);
                    $$ = NEW_BEGIN(0);
                  }
                | lhs '=' mrhs
                  {
                    value_expr($3);
                    $$ = node_assign($1, $3);
                  }
                | mlhs '=' mrhs_arg
                  {
                    $1->nd_value = $3;
                    $$ = $1;
                  }
                | expr
                ;

command_asgn    : lhs '=' command_call
                  {
                    value_expr($3);
                    $$ = node_assign($1, $3);
                  }
                | lhs '=' command_asgn
                  {
                    value_expr($3);
                    $$ = node_assign($1, $3);
                  }
                ;

expr            : command_call
                | expr keyword_and expr
                  {
                    $$ = logop(NODE_AND, $1, $3);
                  }
                | expr keyword_or expr
                  {
                    $$ = logop(NODE_OR, $1, $3);
                  }
                | keyword_not opt_nl expr
                  {
                    $$ = call_uni_op(cond($3), '!');
                  }
                | '!' command_call
                  {
                    $$ = call_uni_op(cond($2), '!');
                  }
                | arg
                ;

expr_value      : expr
                  {
                    value_expr($1);
                    $$ = $1;
                    if(!$$) $$ = NEW_NIL();
                  }
                ;

command_call    : command
                | block_command
                ;

block_command   : block_call
                | block_call call_op2 operation2 command_args
                  {
                    $$ = NEW_QCALL($2, $1, $3, $4);
                  }
                ;

cmd_brace_block : tLBRACE_ARG
                  {
                    $<vars>1 = bv_push();
                    $<num>$ = sourceline;
                  }
                  opt_block_param
                  compstmt
                  '}'
                  {
                    $$ = NEW_ITER($3, $4);
                    nd_set_line($$, $<num>2);
                    bv_pop($<vars>1);
                  }
                ;

fcall           : operation
                  {
                    $$ = NEW_FCALL($1, 0);
                    nd_set_line($$, tokline);
                  }
                ;

command         : fcall command_args       %prec tLOWEST
                  {
                    $$ = $1;
                    $$->nd_args = $2;
                 }
                | fcall command_args cmd_brace_block
                  {
                    block_dup_check($2, $3);
                    $1->nd_args = $2;
                    $3->nd_iter = $1;
                    $$ = $3;
                    fixpos($$, $1);
                 }
                | primary_value call_op operation2 command_args     %prec tLOWEST
                  {
                    $$ = NEW_QCALL($2, $1, $3, $4);
                    fixpos($$, $1);
                  }
                | primary_value call_op operation2 command_args cmd_brace_block
                  {
                    block_dup_check($4, $5);
                    $5->nd_iter = NEW_QCALL($2, $1, $3, $4);
                    $$ = $5;
                    fixpos($$, $1);
                 }
                | primary_value tCOLON2 operation2 command_args %prec tLOWEST
                  {
                    $$ = NEW_CALL($1, $3, $4);
                    fixpos($$, $1);
                  }
                | primary_value tCOLON2 operation2 command_args cmd_brace_block
                  {
                    block_dup_check($4, $5);
                    $5->nd_iter = NEW_CALL($1, $3, $4);
                    $$ = $5;
                    fixpos($$, $1);
                  }
                | keyword_super command_args
                  {
                    $$ = NEW_SUPER($2);
                    fixpos($$, $2);
                  }
                | keyword_yield command_args
                  {
                    $$ = new_yield($2);
                    fixpos($$, $2);
                  }
                | keyword_return call_args
                  {
                    $$ = NEW_RETURN(ret_args($2));
                  }
                | keyword_break call_args
                  {
                    $$ = NEW_BREAK(ret_args($2));
                  }
                | keyword_next call_args
                  {
                    $$ = NEW_NEXT(ret_args($2));
                  }
                ;

mlhs            : mlhs_basic
                | tLPAREN mlhs_inner rparen
                  {
                    $$ = $2;
                  }
                ;

mlhs_inner      : mlhs_basic
                | tLPAREN mlhs_inner rparen
                  {
                    $$ = NEW_MASGN(NEW_LIST($2), 0);
                  }
                ;

mlhs_basic      : mlhs_head
                  {
                    $$ = NEW_MASGN($1, 0);
                  }
                | mlhs_head mlhs_item
                  {
                    $$ = NEW_MASGN(list_append($1, $2), 0);
                  }
                | mlhs_head tSTAR mlhs_node
                  {
                    $$ = NEW_MASGN($1, $3);
                  }
                | mlhs_head tSTAR mlhs_node ',' mlhs_post
                  {
                    $$ = NEW_MASGN($1, NEW_POSTARG($3, $5));
                  }
                | mlhs_head tSTAR
                  {
                    $$ = NEW_MASGN($1, -1);
                  }
                | mlhs_head tSTAR ',' mlhs_post
                  {
                    $$ = NEW_MASGN($1, NEW_POSTARG(-1, $4));
                  }
                | tSTAR mlhs_node
                  {
                    $$ = NEW_MASGN(0, $2);
                  }
                | tSTAR mlhs_node ',' mlhs_post
                  {
                    $$ = NEW_MASGN(0, NEW_POSTARG($2, $4));
                  }
                | tSTAR
                  {
                    $$ = NEW_MASGN(0, -1);
                  }
                | tSTAR ',' mlhs_post
                  {
                    $$ = NEW_MASGN(0, NEW_POSTARG(-1, $3));
                  }
                ;

mlhs_item       : mlhs_node
                | tLPAREN mlhs_inner rparen
                  {
                    $$ = $2;
                  }
                ;

mlhs_head       : mlhs_item ','
                  {
                    $$ = NEW_LIST($1);
                  }
                | mlhs_head mlhs_item ','
                  {
                    $$ = list_append($1, $2);
                  }
                ;

mlhs_post       : mlhs_item
                  {
                    $$ = NEW_LIST($1);
                  }
                | mlhs_post ',' mlhs_item
                  {
                    $$ = list_append($1, $3);
                  }
                ;

mlhs_node       : user_variable
                  {
                    $$ = assignable($1, 0);
                  }
                | keyword_variable
                  {
                    $$ = assignable($1, 0);
                  }
                | primary_value '[' opt_call_args rbracket
                  {
                    $$ = aryset($1, $3);
                  }
                | primary_value call_op tIDENTIFIER
                  {
                    $$ = attrset($1, $2, $3);
                  }
                | primary_value tCOLON2 tIDENTIFIER
                  {
                    $$ = attrset($1, parser_intern("::"), $3);
                  }
                | primary_value call_op tCONSTANT
                  {
                    $$ = attrset($1, $2, $3);
                  }
                | primary_value tCOLON2 tCONSTANT
                  {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    $$ = NEW_CDECL(0, 0, NEW_COLON2($1, $3));
                  }
                | tCOLON3 tCONSTANT
                  {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    $$ = NEW_CDECL(0, 0, NEW_COLON3($2));
                  }
                | backref
                  {
                    rb_backref_error($1);
                    $$ = NEW_BEGIN(0);
                  }
                ;

lhs             : user_variable
                  {
                    $$ = assignable($1, 0);
                    if(!$$) $$ = NEW_BEGIN(0);
                  }
                | keyword_variable
                  {
                    $$ = assignable($1, 0);
                    if(!$$) $$ = NEW_BEGIN(0);
                  }
                | primary_value '[' opt_call_args rbracket
                  {
                    $$ = aryset($1, $3);
                  }
                | primary_value call_op tIDENTIFIER
                  {
                    $$ = attrset($1, $2, $3);
                  }
                | primary_value tCOLON2 tIDENTIFIER
                  {
                    $$ = attrset($1, parser_intern("::"), $3);
                  }
                | primary_value call_op tCONSTANT
                  {
                    $$ = attrset($1, $2, $3);
                  }
                | primary_value tCOLON2 tCONSTANT
                  {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    $$ = NEW_CDECL(0, 0, NEW_COLON2($1, $3));
                  }
                | tCOLON3 tCONSTANT
                  {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    $$ = NEW_CDECL(0, 0, NEW_COLON3($2));
                  }
                | backref
                  {
                    rb_backref_error($1);
                    $$ = NEW_BEGIN(0);
                  }
                ;

cname           : tIDENTIFIER
                  {
                    yy_error("class/module name must be CONSTANT");
                  }
                | tCONSTANT
                ;

cpath           : tCOLON3 cname
                  {
                    $$ = NEW_COLON3($2);
                  }
                | cname
                  {
                    $$ = NEW_COLON2(0, $$);
                  }
                | primary_value tCOLON2 cname
                  {
                    $$ = NEW_COLON2($1, $3);
                  }
                ;

fname           : tIDENTIFIER
                | tCONSTANT
                | tFID
                | op
                  {
                    SET_LEX_STATE(EXPR_ENDFN);
                    $$ = convert_op($1);
                  }
                | reswords
                  {
                    SET_LEX_STATE(EXPR_ENDFN);
                    $$ = $<id>1;
                  }
                ;

fsym            : fname
                | symbol
                ;

fitem           : fsym
                  {
                    $$ = NEW_LIT(ID2SYM($1));
                  }
                | dsym
                ;

undef_list      : fitem
                  {
                    $$ = NEW_UNDEF($1);
                  }
                | undef_list ',' {SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);} fitem
                  {
                    $$ = block_append($1, NEW_UNDEF($4));
                  }
                ;

op              : '|'           { $$ = '|'; }
                | '^'           { $$ = '^'; }
                | '&'           { $$ = '&'; }
                | tCMP          { $$ = tCMP; }
                | tEQ           { $$ = tEQ; }
                | tEQQ          { $$ = tEQQ; }
                | tMATCH        { $$ = tMATCH; }
                | tNMATCH       { $$ = tNMATCH; }
                | '>'           { $$ = '>'; }
                | tGEQ          { $$ = tGEQ; }
                | '<'           { $$ = '<'; }
                | tLEQ          { $$ = tLEQ; }
                | tNEQ          { $$ = tNEQ; }
                | tLSHFT        { $$ = tLSHFT; }
                | tRSHFT        { $$ = tRSHFT; }
                | '+'           { $$ = '+'; }
                | '-'           { $$ = '-'; }
                | '*'           { $$ = '*'; }
                | tSTAR         { $$ = '*'; }
                | '/'           { $$ = '/'; }
                | '%'           { $$ = '%'; }
                | tPOW          { $$ = tPOW; }
                | tDSTAR        { $$ = tDSTAR; }
                | '!'           { $$ = '!'; }
                | '~'           { $$ = '~'; }
                | tUPLUS        { $$ = tUPLUS; }
                | tUMINUS       { $$ = tUMINUS; }
                | tAREF         { $$ = tAREF; }
                | tASET         { $$ = tASET; }
                | '`'           { $$ = '`'; }
                ;

reswords        : keyword__LINE__ | keyword__FILE__ | keyword__ENCODING__
                | keyword_BEGIN | keyword_END
                | keyword_alias | keyword_and | keyword_begin
                | keyword_break | keyword_case | keyword_class | keyword_def
                | keyword_defm | keyword_fun | keyword_funm
                | keyword_defined | keyword_do | keyword_else | keyword_elsif
                | keyword_end | keyword_ensure | keyword_false
                | keyword_for | keyword_in | keyword_module | keyword_next
                | keyword_nil | keyword_not | keyword_or | keyword_redo
                | keyword_rescue | keyword_retry | keyword_return | keyword_self
                | keyword_super | keyword_then | keyword_true | keyword_undef
                | keyword_when | keyword_yield | keyword_if | keyword_unless
                | keyword_while | keyword_until
                ;

arg             : lhs '=' arg
                  {
                    value_expr($3);
                    $$ = node_assign($1, $3);
                  }
                | lhs '=' arg modifier_rescue arg
                  {
                    value_expr($3);
                    $3 = NEW_RESCUE($3, NEW_RESBODY(0, $5, 0), 0);
                    $$ = node_assign($1, $3);
                  }
                | var_lhs tOP_ASGN arg
                  {
                    value_expr($3);
                    $$ = new_op_assign($1, $2, $3);
                  }
                | var_lhs tOP_ASGN arg modifier_rescue arg
                  {
                    value_expr($3);
                    $3 = NEW_RESCUE($3, NEW_RESBODY(0, $5, 0), 0);
                    new_op_assign($1, $2, $3);
                  }
                | primary_value '[' opt_call_args rbracket tOP_ASGN arg
                  {
                    NODE *args;

                    value_expr($6);
                    if(!$3) $3 = NEW_ZARRAY();
                    if(nd_type($3) == NODE_BLOCK_PASS) {
                      args = NEW_ARGSCAT($3, $6);
                    } else {
                      args = arg_concat($3, $6);
                    }
                    if($5 == tOROP) {
                      $5 = 0;
                    } else if($5 == tANDOP) {
                      $5 = 1;
                    } else {
                      $5 = convert_op($5);
                    }
                    $$ = NEW_OP_ASGN1($1, $5, args);
                    fixpos($$, $1);
                  }
                | primary_value call_op tIDENTIFIER tOP_ASGN arg
                  {
                    value_expr($5);
                    $$ = new_attr_op_assign($1, $2, $3, $4, $5);
                  }
                | primary_value call_op tCONSTANT tOP_ASGN arg
                  {
                    value_expr($5);
                    $$ = new_attr_op_assign($1, $2, $3, $4, $5);
                  }
                | primary_value tCOLON2 tIDENTIFIER tOP_ASGN arg
                  {
                    value_expr($5);
                    $$ = new_attr_op_assign($1, parser_intern("::"), $3, $4, $5);
                  }
                | primary_value tCOLON2 tCONSTANT tOP_ASGN arg
                  {
                    $$ = NEW_COLON2($1, $3);
                    $$ = new_const_op_assign($$, $4, $5);
                  }
                | tCOLON3 tCONSTANT tOP_ASGN arg
                  {
                    $$ = NEW_COLON3($2);
                    $$ = new_const_op_assign($$, $3, $4);
                  }
                | backref tOP_ASGN arg
                  {
                    rb_backref_error($1);
                    $$ = NEW_BEGIN(0);
                  }
                | arg tDOT2 arg
                  {
                    value_expr($1);
                    value_expr($3);
                    $$ = NEW_DOT2($1, $3);
                  }
                | arg tDOT3 arg
                  {
                    value_expr($1);
                    value_expr($3);
                    $$ = NEW_DOT3($1, $3);
                  }
                | arg '+' arg
                  {
                    $$ = call_bin_op($1, '+', $3);
                  }
                | arg '-' arg
                  {
                    $$ = call_bin_op($1, '-', $3);
                  }
                | arg '*' arg
                  {
                    $$ = call_bin_op($1, '*', $3);
                  }
                | arg '/' arg
                  {
                    $$ = call_bin_op($1, '/', $3);
                  }
                | arg '%' arg
                  {
                    $$ = call_bin_op($1, '%', $3);
                  }
                | arg tPOW arg
                  {
                    $$ = call_bin_op($1, tPOW, $3);
                  }
                | tUMINUS_NUM simple_numeric tPOW arg
                  {
                    $$ = NEW_CALL(call_bin_op($2, tPOW, $4), tUMINUS, 0);
                  }
                | tUPLUS arg
                  {
                    $$ = call_uni_op($2, tUPLUS);
                  }
                | tUMINUS arg
                  {
                    $$ = call_uni_op($2, tUMINUS);
                  }
                | arg '|' arg
                  {
                    $$ = call_bin_op($1, '|', $3);
                  }
                | arg '^' arg
                  {
                    $$ = call_bin_op($1, '^', $3);
                  }
                | arg '&' arg
                  {
                    $$ = call_bin_op($1, '&', $3);
                  }
                | arg tCMP arg
                  {
                    $$ = call_bin_op($1, tCMP, $3);
                  }
                | arg '>' arg
                  {
                    $$ = call_bin_op($1, '>', $3);
                  }
                | arg tGEQ arg
                  {
                    $$ = call_bin_op($1, tGEQ, $3);
                  }
                | arg '<' arg
                  {
                    $$ = call_bin_op($1, '<', $3);
                  }
                | arg tLEQ arg
                  {
                    $$ = call_bin_op($1, tLEQ, $3);
                  }
                | arg tEQ arg
                  {
                    $$ = call_bin_op($1, tEQ, $3);
                  }
                | arg tEQQ arg
                  {
                    $$ = call_bin_op($1, tEQQ, $3);
                  }
                | arg tNEQ arg
                  {
                    $$ = call_bin_op($1, tNEQ, $3);
                  }
                | arg tMATCH arg
                  {
                    /* TODO */
                    $$ = match_op($1, $3);
                    /*
                    if(nd_type($1) == NODE_LIT && TYPE($1->nd_lit) == T_REGEXP) {
                      $$ = reg_named_capture_assign($1->nd_lit, $$);
                    }
                    */
                  }
                | arg tNMATCH arg
                  {
                    $$ = call_bin_op($1, tNMATCH, $3);
                  }
                | '!' arg
                  {
                    $$ = call_uni_op(cond($2), '!');
                  }
                | '~' arg
                  {
                    $$ = call_uni_op($2, '~');
                  }
                | arg tLSHFT arg
                  {
                    $$ = call_bin_op($1, tLSHFT, $3);
                  }
                | arg tRSHFT arg
                  {
                    $$ = call_bin_op($1, tRSHFT, $3);
                  }
                | arg tANDOP arg
                  {
                    $$ = logop(NODE_AND, $1, $3);
                  }
                | arg tOROP arg
                  {
                    $$ = logop(NODE_OR, $1, $3);
                  }
                | keyword_defined opt_nl {in_defined = 1;} arg
                  {
                    in_defined = 0;
                    $$ = NEW_DEFINED($4);
                  }
                | arg '?' arg opt_nl ':' arg
                  {
                    value_expr($1);
                    $$ = NEW_IF(cond($1), $3, $6);
                    fixpos($$, $1);
                  }
                | primary
                  {
                    $$ = $1;
                  }
                ;

arg_value       : arg
                  {
                    value_expr($1);
                    $$ = $1;
                    if(!$$) $$ = NEW_NIL();
                  }
                ;

aref_args       : none
                | args trailer
                  {
                    $$ = $1;
                  }
                | args ',' assocs trailer
                  {
                    $$ = arg_append($1, NEW_HASH($3));
                  }
                | assocs trailer
                  {
                    $$ = NEW_LIST(NEW_HASH($1));
                  }
                ;

paren_args      : '(' opt_call_args rparen
                  {
                    $$ = $2;
                  }
                ;

opt_paren_args  : none
                | paren_args
                ;

opt_call_args   : none
                | call_args
                | args ','
                  {
                    $$ = $1;
                  }
                | args ',' assocs ','
                  {
                    $$ = arg_append($1, NEW_HASH($3));
                  }
                | assocs ','
                  {
                    $$ = NEW_LIST(NEW_HASH($1));
                  }
                ;

call_args       : command
                  {
                    value_expr($1);
                    $$ = NEW_LIST($1);
                  }
                | args opt_block_arg
                  {
                    $$ = arg_blk_pass($1, $2);
                  }
                | assocs opt_block_arg
                  {
                    $$ = NEW_LIST($1 ? NEW_HASH($1) : 0);
                    $$ = arg_blk_pass($$, $2);
                  }
                | args ',' assocs opt_block_arg
                  {
                    $$ = $3 ? arg_append($1, NEW_HASH($3)) : $1;
                    $$ = arg_blk_pass($$, $4);
                  }
                | block_arg
                ;

command_args    : {
                    $<val>$ = cmdarg_stack;
                    CMDARG_PUSH(1);
                  }
                  call_args
                  {
                    /* CMDARG_POP() */
                    cmdarg_stack = $<val>1;
                    $$ = $2;
                  }
                ;

block_arg       : tAMPER arg_value
                  {
                    $$ = NEW_BLOCK_PASS($2);
                  }
                ;

opt_block_arg   : ',' block_arg
                  {
                    $$ = $2;
                  }
                | none
                  {
                    $$ = 0;
                  }
                ;

args            : arg_value
                  {
                    $$ = NEW_LIST($1);
                  }
                | tSTAR arg_value
                  {
                    $$ = NEW_SPLAT($2);
                  }
                | args ',' arg_value
                  {
                    NODE *n1;
                    if((n1 = splat_array($1)) != 0) {
                      $$ = list_append(n1, $3);
                    } else {
                      $$ = arg_append($1, $3);
                    }
                  }
                | args ',' tSTAR arg_value
                  {
                    NODE *n1;
                    if((nd_type($4) == NODE_ARRAY) && (n1 = splat_array($1)) != 0) {
                      $$ = list_concat(n1, $4);
                    } else {
                      $$ = arg_concat($1, $4);
                    }
                  }
                ;

mrhs_arg        : mrhs
                | arg_value
                ;

mrhs            : args ',' arg_value
                  {
                    NODE *n1;
                    if((n1 = splat_array($1)) != 0) {
                      $$ = list_append(n1, $3);
                    } else {
                      $$ = arg_append($1, $3);
                    }
                  }
                | args ',' tSTAR arg_value
                  {
                    NODE *n1;
                    if(nd_type($4) == NODE_ARRAY && (n1 = splat_array($1)) != 0) {
                      $$ = list_concat(n1, $4);
                    } else {
                      $$ = arg_concat($1, $4);
                    }
                  }
                | tSTAR arg_value
                  {
                    $$ = NEW_SPLAT($2);
                  }
                ;

primary         : literal
                | strings
                | xstring
                | regexp
                | words
                | qwords
                | symbols
                | qsymbols
                | var_ref
                | backref
                | tFID
                  {
                    $$ = NEW_FCALL($1, 0);
                  }
                | k_begin
                  {
                    $<val>1 = cmdarg_stack;
                    cmdarg_stack = 0;
                    $<num>$ = sourceline;
                  }
                  bodystmt
                  k_end
                  {
                    cmdarg_stack = $<val>1;
                    if($3 == NULL) {
                      $$ = NEW_NIL();
                    } else {
                      if(nd_type($3) == NODE_RESCUE || nd_type($3) == NODE_ENSURE) {
                        nd_set_line($3, $<num>2);
                      }
                      $$ = NEW_BEGIN($3);
                    }
                    nd_set_line($$, $<num>2);
                  }
                | tLPAREN_ARG {SET_LEX_STATE(EXPR_ENDARG);} rparen
                  {
                    $$ = 0;
                  }
                | tLPAREN_ARG
                  {
                    $<val>1 = cmdarg_stack;
                    cmdarg_stack = 0;
                  }
                expr {SET_LEX_STATE(EXPR_ENDARG);} rparen
                  {
                    cmdarg_stack = $<val>1;
                    $$ = $3;
                  }
                | tLPAREN compstmt ')'
                  {
                    $$ = $2;
                  }
                | primary_value tCOLON2 tCONSTANT
                  {
                    $$ = NEW_COLON2($1, $3);
                  }
                | tCOLON3 tCONSTANT
                  {
                    $$ = NEW_COLON3($2);
                  }
                | tLBRACK aref_args ']'
                  {
                    if($2 == 0) {
                      $$ = NEW_ZARRAY(); /* zero length array*/
                    } else {
                      $$ = $2;
                    }
                  }
                | tLBRACE assoc_list '}'
                  {
                    $$ = NEW_HASH($2);
                  }
                | keyword_return
                  {
                    $$ = NEW_RETURN(0);
                  }
                | keyword_yield '(' call_args rparen
                  {
                    $$ = new_yield($3);
                  }
                | keyword_yield '(' rparen
                  {
                    $$ = NEW_YIELD(0, Qfalse);
                  }
                | keyword_yield
                  {
                    $$ = NEW_YIELD(0, Qfalse);
                  }
                | keyword_defined opt_nl '(' {in_defined = 1;} expr rparen
                  {
                    in_defined = 0;
                    $$ = NEW_DEFINED($5);
                  }
                | keyword_not '(' expr rparen
                  {
                    $$ = call_uni_op(cond($3), '!');
                  }
                | keyword_not '(' rparen
                  {
                    $$ = call_uni_op(cond(NEW_NIL()), '!');
                  }
                | fcall brace_block
                  {
                    $2->nd_iter = $1;
                    $$ = $2;
                    fixpos($2->nd_iter, $2);
                  }
                | method_call
                | method_call brace_block
                  {
                    block_dup_check($1->nd_args, $2);
                    $2->nd_iter = $1;
                    $$ = $2;
                    fixpos($$, $1);
                  }
                | tLAMBDA lambda
                  {
                    $$ = $2;
                  }
                | k_if expr_value then
                  compstmt
                  if_tail
                  k_end
                  {
                    $$ = NEW_IF(cond($2), $4, $5);
                    fixpos($$, $2);
                  }
                | k_unless expr_value then
                  compstmt
                  opt_else
                  k_end
                  {
                    $$ = NEW_UNLESS(cond($2), $4, $5);
                    fixpos($$, $2);
                  }
                | k_while {COND_PUSH(1);} expr_value do {COND_POP();}
                  compstmt
                  k_end
                  {
                    $$ = NEW_WHILE(cond($3), $6, 1);
                    fixpos($$, $3);
                  }
                | k_until {COND_PUSH(1);} expr_value do {COND_POP();}
                  compstmt
                  k_end
                  {
                    $$ = NEW_UNTIL(cond($3), $6, 1);
                    fixpos($$, $3);
                  }
                | k_case expr_value opt_terms
                  case_body
                  k_end
                  {
                    $$ = NEW_CASE($2, $4);
                    fixpos($$, $2);
                  }
                | k_case opt_terms case_body k_end
                  {
                    $$ = NEW_CASE(0, $3);
                  }
                | k_for for_var keyword_in
                  {COND_PUSH(1);}
                  expr_value do
                  {COND_POP();}
                  compstmt
                  k_end
                  {
                    /*
                     *  for a, b, c in e
                     *  #=>
                     *  e.each{|*x| a, b, c = x
                     *
                     *  for a in e
                     *  #=>
                     *  e.each{|x| a, = x}
                     */
                    $$ = NEW_FOR($2, $5, $8);
                    fixpos($$, $2);
                  }
                | k_class cpath superclass
                  {
                    if(in_def || in_single)
                      yy_error("class definition in method body");
                    class_nest++;
                    local_push(0);
                    $<num>$ = sourceline;
                  }
                  bodystmt
                  k_end
                  {
                    $$ = NEW_CLASS($2, $5, $3);
                    nd_set_line($$, $<num>4);
                    local_pop();
                    class_nest--;
                  }
                | k_class tLSHFT expr
                  {
                    $<num>$ = (in_def << 1) | in_single;
                    in_def = 0;
                    in_single = 0;
                    class_nest++;
                    local_push(0);
                  }
                  term
                  bodystmt
                  k_end
                  {
                    $$ = NEW_SCLASS($3, $6);
                    fixpos($$, $3);
                    local_pop();
                    class_nest--;
                    in_def = ($<num>4 >> 1) & 1;
                    in_single = $<num>4 & 1;
                  }
                | k_module cpath
                  {
                    if(in_def || in_single)
                      yy_error("module definition in method body");
                    class_nest++;
                    local_push(0);
                    $<num>$ = sourceline;
                  }
                  bodystmt
                  k_end
                  {
                    $$ = NEW_MODULE($2, $4);
                    nd_set_line($$, $<num>3);
                    local_pop();
                    class_nest--;
                  }
                | k_def fname
                  {
                    $<id>$ = cur_mid;
                    cur_mid = $2;
                    local_push(0);
                  }
                  {
                    $<num>$ = in_def;
                    in_def = 1;
                  }
                  f_arglist
                  bodystmt
                  k_end
                  {
                    NODE* body = remove_begin($6);
                    $$ = NEW_DEFN($2, $5, body, NOEX_PRIVATE);
                    nd_set_line($$, $<num>1);
                    local_pop();
                    in_def = $<num>4 & 1;
                    cur_mid = $<id>3;
                  }
                | k_defm fname
                  {
                    $<id>$ = cur_mid;
                    cur_mid = $2;
                    local_push(0);
                  }
                  {
                    $<num>$ = in_def;
                    in_def = 1;
                  }
                  f_arglist
                  bodystmt
                  k_end
                  {
                    NODE* body = remove_begin($6);
                    $$ = NEW_DEFNM($2, $5, body, NOEX_PRIVATE);
                    nd_set_line($$, $<num>1);
                    local_pop();
                    in_def = $<num>4 & 1;
                    cur_mid = $<id>3;
                  }
                | k_fun fname
                  {
                    $<id>$ = cur_mid;
                    cur_mid = $2;
                    local_push(0);
                  }
                  {
                    $<num>$ = in_def;
                    in_def = 1;
                  }
                  f_arglist
                  bodystmt
                  k_end
                  {
                    NODE* body = remove_begin($6);
                    $$ = NEW_FUN($2, $5, body, NOEX_PRIVATE);
                    nd_set_line($$, $<num>1);
                    local_pop();
                    in_def = $<num>4 & 1;
                    cur_mid = $<id>3;
                  }
                | k_funm fname
                  {
                    $<id>$ = cur_mid;
                    cur_mid = $2;
                    local_push(0);
                  }
                  {
                    $<num>$ = in_def;
                    in_def = 1;
                  }
                  f_arglist
                  bodystmt
                  k_end
                  {
                    NODE* body = remove_begin($6);
                    $$ = NEW_FUNM($2, $5, body, NOEX_PRIVATE);
                    nd_set_line($$, $<num>1);
                    local_pop();
                    in_def = $<num>4 & 1;
                    cur_mid = $<id>3;
                  }
                | k_def singleton dot_or_colon {SET_LEX_STATE(EXPR_FNAME);} fname
                  {
                    $<num>4 = in_single;
                    in_single = 1;
                    SET_LEX_STATE(EXPR_ENDFN | EXPR_LABEL); /* force for args */
                    local_push(0);
                  }
                  f_arglist
                  bodystmt
                  k_end
                  {
                    NODE* body = remove_begin($8);
                    $$ = NEW_DEFS($2, $5, $7, body);
                    nd_set_line($$, $<num>1);
                    local_pop();
                    in_single = $<num>4 & 1;
                  }
                | k_defm singleton dot_or_colon {SET_LEX_STATE(EXPR_FNAME);} fname
                  {
                    $<num>4 = in_single;
                    in_single = 1;
                    SET_LEX_STATE(EXPR_ENDFN | EXPR_LABEL); /* force for args */
                    local_push(0);
                  }
                  f_arglist
                  bodystmt
                  k_end
                  {
                    NODE* body = remove_begin($8);
                    $$ = NEW_DEFSM($2, $5, $7, body);
                    nd_set_line($$, $<num>1);
                    local_pop();
                    in_single = $<num>4 & 1;
                  }
                | keyword_break
                  {
                    $$ = NEW_BREAK(0);
                  }
                | keyword_next
                  {
                    $$ = NEW_NEXT(0);
                  }
                | keyword_redo
                  {
                    $$ = NEW_REDO();
                  }
                | keyword_retry
                  {
                    $$ = NEW_RETRY();
                  }
                ;

primary_value   : primary
                  {
                    value_expr($1);
                    $$ = $1;
                    if(!$$) $$ = NEW_NIL();
                  }
                ;

k_begin         : keyword_begin
                  {
                    token_info_push("begin");
                  }
                ;

k_if            : keyword_if
                  {
                    token_info_push("if");
                  }
                ;

k_unless        : keyword_unless
                  {
                    token_info_push("unless");
                  }
                ;

k_while         : keyword_while
                  {
                    token_info_push("while");
                  }
                ;

k_until         : keyword_until
                  {
                    token_info_push("until");
                  }
                ;

k_case          : keyword_case
                  {
                    token_info_push("case");
                  }
                ;

k_for           : keyword_for
                  {
                    token_info_push("for");
                  }
                ;

k_class         : keyword_class
                  {
                    token_info_push("class");
                  }
                ;

k_module        : keyword_module
                  {
                    token_info_push("module");
                  }
                ;

k_def           : keyword_def
                  {
                    token_info_push("def");
                    $<num>$ = sourceline;
                  }
                ;

k_defm          : keyword_defm
                  {
                    token_info_push("defm");
                    $<num>$ = sourceline;
                  }
                ;

k_fun           : keyword_fun
                  {
                    token_info_push("fun");
                    $<num>$ = sourceline;
                  }
                ;

k_funm          : keyword_funm
                  {
                    token_info_push("funm");
                    $<num>$ = sourceline;
                  }
                ;

k_end           : keyword_end
                  {
                    token_info_pop("end");
                  }
                ;

then            : term
                | keyword_then
                | term keyword_then
                ;

do              : term
                | keyword_do_cond
                ;

if_tail         : opt_else
                | keyword_elsif expr_value then
                  compstmt
                  if_tail
                  {
                    $$ = NEW_IF(cond($2), $4, $5);
                    fixpos($$, $2);
                  }
                ;

opt_else        : none
                | keyword_else compstmt
                  {
                    $$ = $2;
                  }
                ;

for_var         : lhs
                | mlhs
                ;

f_marg          : f_norm_arg
                  {
                    $$ = assignable($1, 0);
                  }
                | tLPAREN f_margs rparen
                  {
                    $$ = $2;
                  }
                ;

f_marg_list     : f_marg
                  {
                    $$ = NEW_LIST($1);
                  }
                | f_marg_list ',' f_marg
                  {
                    $$ = list_append($1, $3);
                  }
                ;

f_margs         : f_marg_list
                  {
                    $$ = NEW_MASGN($1, 0);
                  }
                | f_marg_list ',' tSTAR f_norm_arg
                  {
                    $$ = assignable($4, 0);
                    $$ = NEW_MASGN($1, $$);
                  }
                | f_marg_list ',' tSTAR f_norm_arg ',' f_marg_list
                  {
                    $$ = assignable($4, 0);
                    $$ = NEW_MASGN($1, NEW_POSTARG($$, $6));
                  }
                | f_marg_list ',' tSTAR
                  {
                    $$ = NEW_MASGN($1, -1);
                  }
                | f_marg_list ',' tSTAR ',' f_marg_list
                  {
                    $$ = NEW_MASGN($1, NEW_POSTARG(-1, $5));
                  }
                | tSTAR f_norm_arg
                  {
                    $$ = assignable($2, 0);
                    $$ = NEW_MASGN(0, $$);
                  }
                | tSTAR f_norm_arg ',' f_marg_list
                  {
                    $$ = assignable($2, 0);
                    $$ = NEW_MASGN(0, NEW_POSTARG($$, $4));
                  }
                | tSTAR
                  {
                    $$ = NEW_MASGN(0, -1);
                  }
                | tSTAR ',' f_marg_list
                  {
                    $$ = NEW_MASGN(0, NEW_POSTARG(-1, $3));
                  }
                ;

block_args_tail : f_block_kwarg ',' f_kwrest opt_f_block_arg
                  {
                    $$ = new_args_tail($1, $3, $4);
                  }
                | f_block_kwarg opt_f_block_arg
                  {
                    $$ = new_args_tail($1, 0, $2);
                  }
                | f_kwrest opt_f_block_arg
                  {
                    $$ = new_args_tail(0, $1, $2);
                  }
                | f_block_arg
                  {
                    $$ = new_args_tail(0, 0, $1);
                  }
                ;

opt_block_args_tail : ',' block_args_tail
                  {
                    $$ = $2;
                  }
                | /* none */
                  {
                    $$ = new_args_tail(0, 0, 0);
                  }
                ;

block_param     : f_arg ',' f_block_optarg ',' f_rest_arg opt_block_args_tail
                  {
                    $$ = new_args($1, $3, $5, 0, $6);
                  }
                | f_arg ',' f_block_optarg ',' f_rest_arg ',' f_arg opt_block_args_tail
                  {
                    $$ = new_args($1, $3, $5, $7, $8);
                  }
                | f_arg ',' f_block_optarg opt_block_args_tail
                  {
                    $$ = new_args($1, $3, 0, 0, $4);
                  }
                | f_arg ',' f_block_optarg ',' f_arg opt_block_args_tail
                  {
                    $$ = new_args($1, $3, 0, $5, $6);
                  }
                | f_arg ',' f_rest_arg opt_block_args_tail
                  {
                    $$ = new_args($1, 0, $3, 0, $4);
                  }
                | f_arg ','
                  {
                    $$ = new_args($1, 0, 1, 0, new_args_tail(0, 0, 0));
                  }
                | f_arg ',' f_rest_arg ',' f_arg opt_block_args_tail
                  {
                    $$ = new_args($1, 0, $3, $5, $6);
                  }
                | f_arg opt_block_args_tail
                  {
                    $$ = new_args($1, 0, 0, 0, $2);
                  }
                | f_block_optarg ',' f_rest_arg opt_block_args_tail
                  {
                    $$ = new_args(0, $1, $3, 0, $4);
                  }
                | f_block_optarg ',' f_rest_arg ',' f_arg opt_block_args_tail
                  {
                    $$ = new_args(0, $1, $3, $5, $6);
                  }
                | f_block_optarg opt_block_args_tail
                  {
                    $$ = new_args(0, $1, 0, 0, $2);
                  }
                | f_block_optarg ',' f_arg opt_block_args_tail
                  {
                    $$ = new_args(0, $1, 0, $3, $4);
                  }
                | f_rest_arg opt_block_args_tail
                  {
                    $$ = new_args(0, 0, $1, 0, $2);
                  }
                | f_rest_arg ',' f_arg opt_block_args_tail
                  {
                    $$ = new_args(0, 0, $1, $3, $4);
                  }
                | block_args_tail
                  {
                    $$ = new_args(0, 0, 0, 0, $1);
                  }
                ;

opt_block_param : none
                | block_param_def
                  {
                    command_start = TRUE;
                  }
                ;

block_param_def : '|' opt_bv_decl '|'
                  {
                    // This is deliberately different than MRI.
                    $$ = $2 ? NEW_ARGS_AUX(0, $2) : 0;
                  }
                | tOROP
                  {
                    $$ = 0;
                  }
                | '|' block_param opt_bv_decl '|'
                  {
                    // This is deliberately different than MRI.
                    $$ = $3 ? NEW_ARGS_AUX($2, $3) : $2;
                  }
                ;

opt_bv_decl     : opt_nl
                  {
                    $$ = 0;
                  }
                | opt_nl ';' bv_decls opt_nl
                  {
                    // This is deliberately different than MRI.
                    $$ = $3;
                  }
                ;

bv_decls        : bvar
                  {
                    // This is deliberately different than MRI.
                    $$ = NEW_LIST($1);
                  }
                | bv_decls ',' bvar
                  {
                    // This is deliberately different than MRI.
                    $$ = list_append($1, $3);
                  }
                ;

bvar            : tIDENTIFIER
                  {
                    new_bv(get_id($1));
                    // This is deliberately different than MRI.
                    $$ = NEW_LIT(ID2SYM(get_id($1)));
                  }
                | f_bad_arg
                  {
                    $$ = 0;
                  }
                ;

lambda          : {
                    $<vars>$ = bv_push();
                  }
                  {
                    $<num>$ = lpar_beg;
                    lpar_beg = ++paren_nest;
                  }
                  f_larglist
                  {
                    $<num>$ = sourceline;
                  }
                  {
                    $<val>$ = cmdarg_stack;
                    cmdarg_stack = 0;
                  }
                  lambda_body
                  {
                    lpar_beg = $<num>2;
                    cmdarg_stack = $<val>5;
                    CMDARG_LEXPOP();
                    $$ = NEW_LAMBDA($3, $6);
                    nd_set_line($$, $<num>4);
                    bv_pop($<vars>1);
                  }
                ;

f_larglist      : '(' f_args opt_bv_decl ')'
                  {
                    $$ = $2;
                  }
                | f_args
                  {
                    $$ = $1;
                  }
                ;

lambda_body     : tLAMBEG compstmt '}'
                  {
                    $$ = $2;
                  }
                | keyword_do_LAMBDA compstmt keyword_end
                  {
                    $$ = $2;
                  }
                ;

do_block        : keyword_do_block
                  {
                    $<vars>1 = bv_push();
                    $<num>$ = sourceline;
                  }
                  opt_block_param
                  compstmt
                  keyword_end
                  {
                    $$ = NEW_ITER($3, $4);
                    nd_set_line($$, $<num>2);
                    bv_pop($<vars>1);
                  }
                ;

block_call      : command do_block
                  {
                    if(nd_type($1) == NODE_YIELD) {
                      compile_error("block given to yield");
                    } else {
                      block_dup_check($1->nd_args, $2);
                    }
                    $2->nd_iter = $1;
                    $$ = $2;
                    fixpos($$, $1);
                  }
                | block_call call_op2 operation2 opt_paren_args
                  {
                    $$ = NEW_QCALL($2, $1, $3, $4);
                  }
                | block_call call_op2 operation2 opt_paren_args brace_block
                  {
                    block_dup_check($4, $5);
                    $5->nd_iter = NEW_QCALL($2, $1, $3, $4);
                    $$ = $5;
                    fixpos($$, $1);
                  }
                | block_call call_op2 operation2 command_args do_block
                  {
                    block_dup_check($4, $5);
                    $5->nd_iter = NEW_QCALL($2, $1, $3, $4);
                    $$ = $5;
                    fixpos($$, $1);
                  }
                ;

method_call     : fcall paren_args
                  {
                    $$ = $1;
                    $$->nd_args = $2;
                    fixpos($$, $2);
                  }
                | primary_value call_op operation2
                  {
                    $<num>$ = sourceline;
                  }
                  opt_paren_args
                  {
                    $$ = NEW_QCALL($2, $1, $3, $5);
                    nd_set_line($$, $<num>4);
                  }
                | primary_value tCOLON2 operation2
                  {
                    $<num>$ = sourceline;
                  }
                  paren_args
                  {
                    $$ = NEW_CALL($1, $3, $5);
                    nd_set_line($$, $<num>4);
                  }
                | primary_value tCOLON2 operation3
                  {
                    $$ = NEW_CALL($1, $3, 0);
                  }
                | primary_value call_op
                  {
                    $<num>$ = sourceline;
                  }
                  paren_args
                  {
                    $$ = NEW_QCALL($2, $1, parser_intern("call"), $4);
                    nd_set_line($$, $<num>3);
                  }
                | primary_value tCOLON2
                  {
                    $<num>$ = sourceline;
                  }
                  paren_args
                  {
                    $$ = NEW_CALL($1, parser_intern("call"), $4);
                    nd_set_line($$, $<num>3);
                  }
                | keyword_super paren_args
                  {
                    $$ = NEW_SUPER($2);
                  }
                | keyword_super
                  {
                    $$ = NEW_ZSUPER();
                  }
                | primary_value '[' opt_call_args rbracket
                  {
                    if($1 && nd_type($1) == NODE_SELF) {
                      $$ = NEW_FCALL(tAREF, $3);
                    } else {
                      $$ = NEW_CALL($1, tAREF, $3);
                    }
                    fixpos($$, $1);
                  }
                ;

brace_block     : '{'
                  {
                    $<vars>1 = bv_push();
                    $<num>$ = sourceline;
                  }
                  opt_block_param
                  compstmt '}'
                  {
                    $$ = NEW_ITER($3, $4);
                    nd_set_line($$, $<num>2);
                    bv_pop($<vars>1);
                  }
                | keyword_do
                  {
                    $<vars>1 = bv_push();
                    $<num>$ = sourceline;
                  }
                  opt_block_param
                  compstmt keyword_end
                  {
                    $$ = NEW_ITER($3, $4);
                    nd_set_line($$, $<num>2);
                    bv_pop($<vars>1);
                  }
                ;

case_body       : keyword_when args then
                  compstmt
                  cases
                  {
                    $$ = NEW_WHEN($2, $4, $5);
                  }
                ;

cases           : opt_else
                | case_body
                ;

opt_rescue      : keyword_rescue exc_list exc_var then
                  compstmt
                  opt_rescue
                  {
                    if($3) {
                      /* TODO NEW_ERRINFO() */
                      $3 = node_assign($3, NEW_GVAR(parser_intern("$!")));
                      $5 = block_append($3, $5);
                    }
                    $$ = NEW_RESBODY($2, $5, $6);
                    fixpos($$, $2 ? $2 : $5);
                  }
                | none
                ;

exc_list        : arg_value
                  {
                    $$ = NEW_LIST($1);
                  }
                | mrhs
                  {
                    if(!($$ = splat_array($1))) $$ = $1;
                  }
                | none
                ;

exc_var         : tASSOC lhs
                  {
                    $$ = $2;
                  }
                | none
                ;

opt_ensure      : keyword_ensure compstmt
                  {
                    $$ = $2;
                  }
                | none
                ;

literal         : numeric
                | symbol
                  {
                    $$ = NEW_LIT(ID2SYM($1));
                  }
                | dsym
                ;

strings         : string
                  {
                    NODE *node = $1;
                    if(!node) {
                      node = NEW_STR(STR_NEW0());
                    } else {
                      node = evstr2dstr(node);
                    }
                    $$ = node;
                  }
                ;

string          : tCHAR
                | string1
                | string string1
                  {
                    $$ = literal_concat($1, $2);
                  }
                ;

string1         : tSTRING_BEG string_contents tSTRING_END
                  {
                    heredoc_dedent($2);
                    heredoc_indent = 0;
                    $$ = $2;
                  }
                ;

xstring         : tXSTRING_BEG xstring_contents tSTRING_END
                  {
                    NODE *node = $2;

                    heredoc_dedent($2);
                    heredoc_indent = 0;

                    if(!node) {
                      node = NEW_XSTR(STR_NEW0());
                    } else {
                      switch(nd_type(node)) {
                      case NODE_STR:
                        nd_set_type(node, NODE_XSTR);
                        break;
                      case NODE_DSTR:
                        nd_set_type(node, NODE_DXSTR);
                        break;
                      default:
                        node = NEW_NODE(NODE_DXSTR, REF(STR_NEW0()), 1, NEW_LIST(node));
                        break;
                      }
                    }
                    $$ = node;
                  }
                ;

regexp          : tREGEXP_BEG regexp_contents tREGEXP_END
                  {
                    intptr_t options = $3;
                    NODE *node = $2;
                    NODE *list, *prev;

                    if(!node) {
                      node = NEW_REGEX(STR_NEW0(), options & ~RE_OPTION_ONCE);
                    } else {
                      switch(nd_type(node)) {
                      case NODE_STR:
                        {
                          nd_set_type(node, NODE_REGEX);
                          node->nd_cnt = options & ~RE_OPTION_ONCE;
                        }
                        break;
                      default:
                        node = NEW_NODE(NODE_DSTR, REF(STR_NEW0()), 1, NEW_LIST(node));
                      case NODE_DSTR:
                        if(options & RE_OPTION_ONCE) {
                          nd_set_type(node, NODE_DREGX_ONCE);
                        } else {
                          nd_set_type(node, NODE_DREGX);
                        }
                        node->nd_cflag = options & ~RE_OPTION_ONCE;
                        for(list = (prev = node)->nd_next; list; list = list->nd_next) {
                          if(nd_type(list->nd_head) == NODE_STR) {
                            VALUE tail = list->nd_head->nd_lit;
                            if(prev && !NIL_P(prev->nd_lit)) {
                              VALUE lit;
                              if(prev == node) {
                                lit = prev->nd_lit;
                              } else {
                                lit = prev->nd_head->nd_lit;
                              }
                              if(!literal_concat0(lit, tail)) {
                                node = 0;
                                break;
                              }
                              rb_str_resize(tail, 0);
                              prev->nd_next = list->nd_next;
                              list = prev;
                            } else {
                              prev = list;
                            }
                          } else {
                            prev = 0;
                          }
                        }
                        if(!node->nd_next) {
                          nd_set_type(node, NODE_REGEX);
                          node->nd_cnt = options & ~RE_OPTION_ONCE;
                        }
                        break;
                      }
                    }
                    $$ = node;
                  }
                ;

words           : tWORDS_BEG ' ' tSTRING_END
                  {
                    $$ = NEW_ZARRAY();
                  }
                | tWORDS_BEG word_list tSTRING_END
                  {
                    $$ = $2;
                  }
                ;

word_list       : /* none */
                  {
                    $$ = 0;
                  }
                | word_list word ' '
                  {
                    $$ = list_append($1, evstr2dstr($2));
                  }
                ;

word            : string_content
                | word string_content
                  {
                    $$ = literal_concat($1, $2);
                  }
                ;

symbols         : tSYMBOLS_BEG ' ' tSTRING_END
                  {
                    $$ = NEW_ZARRAY();
                  }
                | tSYMBOLS_BEG symbol_list tSTRING_END
                  {
                    $$ = $2;
                  }
                ;

symbol_list     : /* none */
                  {
                    $$ = 0;
                  }
                | symbol_list word ' '
                  {
                    $2 = evstr2dstr($2);
                    nd_set_type($2, NODE_DSYM);
                    $$ = list_append($1, $2);
                  }
                ;

qwords          : tQWORDS_BEG ' ' tSTRING_END
                  {
                    $$ = NEW_ZARRAY();
                  }
                | tQWORDS_BEG qword_list tSTRING_END
                  {
                    $$ = $2;
                  }
                ;

qsymbols        : tQSYMBOLS_BEG ' ' tSTRING_END
                  {
                    $$ = NEW_ZARRAY();
                  }
                | tQSYMBOLS_BEG qsym_list tSTRING_END
                  {
                    $$ = $2;
                  }
                ;

qword_list      : /* none */
                  {
                    $$ = 0;
                  }
                | qword_list tSTRING_CONTENT ' '
                  {
                    $$ = list_append($1, $2);
                  }
                ;

qsym_list       : /* none */
                  {
                    $$ = 0;
                  }
                | qsym_list tSTRING_CONTENT ' '
                  {
                    VALUE lit;
                    lit = $2->nd_lit;
                    $2->nd_lit = ID2SYM(parser_intern_str(lit));
                    nd_set_type($2, NODE_LIT);
                    $$ = list_append($1, $2);
                  }
                ;

string_contents : /* none */
                  {
                    $$ = 0;
                  }
                | string_contents string_content
                  {
                    $$ = literal_concat($1, $2);
                  }
                ;

xstring_contents: /* none */
                  {
                    $$ = 0;
                  }
                | xstring_contents string_content
                  {
                    $$ = literal_concat($1, $2);
                  }
                ;

regexp_contents : /* none */
                  {
                    $$ = 0;
                  }
                | regexp_contents string_content
                  {
                    NODE *head = $1, *tail = $2;
                    if(!head) {
                      $$ = tail;
                    } else if(!tail) {
                      $$ = head;
                    } else {
                      switch(nd_type(head)) {
                      case NODE_STR:
                        nd_set_type(head, NODE_DSTR);
                        break;
                      case NODE_DSTR:
                        break;
                      default:
                        head = list_append(NEW_DSTR(STR_NEW0()), head);
                        break;
                      }
                      $$ = list_append(head, tail);
                    }
                  }
                ;

string_content  : tSTRING_CONTENT
                | tSTRING_DVAR
                  {
                    $<node>$ = lex_strterm;
                    lex_strterm = 0;
                    SET_LEX_STATE(EXPR_BEG);
                  }
                  string_dvar
                  {
                    lex_strterm = $<node>2;
                    $$ = NEW_EVSTR($3);
                  }
                | tSTRING_DBEG
                  {
                    $<val>1 = cond_stack;
                    $<val>$ = cmdarg_stack;
                    cond_stack = 0;
                    cmdarg_stack = 0;
                  }
                  {
                    $<node>$ = lex_strterm;
                    lex_strterm = 0;
                  }
                  {
                    $<num>$ = lex_state;
                    SET_LEX_STATE(EXPR_BEG);
                  }
                  {
                    $<num>$ = brace_nest;
                    brace_nest = 0;
                  }
                  {
                    $<num>$ = heredoc_indent;
                    heredoc_indent = 0;
                  }
                  compstmt tSTRING_DEND
                  {
                    cond_stack = $<val>1;
                    cmdarg_stack = $<val>2;
                    lex_strterm = $<node>3;
                    SET_LEX_STATE($<num>4);
                    brace_nest = $<num>5;
                    heredoc_indent = $<num>6;
                    heredoc_line_indent = -1;

                    if($7) $7->flags &= ~NODE_FL_NEWLINE;
                    $$ = new_evstr($7);
                  }
                ;

string_dvar     : tGVAR {$$ = NEW_GVAR($1);}
                | tIVAR {$$ = NEW_IVAR($1);}
                | tCVAR {$$ = NEW_CVAR($1);}
                | backref
                ;

symbol          : tSYMBEG sym
                  {
                    SET_LEX_STATE(EXPR_END);
                    $$ = $2;
                  }
                ;

sym             : fname
                | tIVAR
                | tGVAR
                | tCVAR
                ;

dsym            : tSYMBEG xstring_contents tSTRING_END
                  {
                    SET_LEX_STATE(EXPR_END);
                    $$ = dsym_node($2);
                  }
                ;

numeric         : simple_numeric
                | tUMINUS_NUM simple_numeric   %prec tLOWEST
                  {
                    $$ = negate_lit($2);
                  }
                ;

simple_numeric  : tINTEGER
                | tFLOAT
                | tRATIONAL
                | tIMAGINARY
                ;

user_variable   : tIDENTIFIER
                | tIVAR
                | tGVAR
                | tCONSTANT
                | tCVAR
                ;

keyword_variable: keyword_nil {$$ = keyword_nil;}
                | keyword_self {$$ = keyword_self;}
                | keyword_true {$$ = keyword_true;}
                | keyword_false {$$ = keyword_false;}
                | keyword__FILE__ {$$ = keyword__FILE__;}
                | keyword__LINE__ {$$ = keyword__LINE__;}
                | keyword__ENCODING__ {$$ = keyword__ENCODING__;}
                ;

var_ref         : user_variable
                  {
                    if(!($$ = gettable($1))) {
                      $$ = NEW_BEGIN(0);
                    }
                  }
                | keyword_variable
                  {
                    if(!($$ = gettable($1))) {
                      $$ = NEW_BEGIN(0);
                    }
                  }
                ;

var_lhs         : user_variable
                  {
                    $$ = assignable($1, 0);
                  }
                | keyword_variable
                  {
                    $$ = assignable($1, 0);
                  }
                ;

backref         : tNTH_REF
                | tBACK_REF
                ;

superclass      : '<'
                  {
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
                  expr_value term
                  {
                    $$ = $3;
                  }
                | /* none */
                  {
                    yyerrok;
                    $$ = 0;
                  }
                ;

f_arglist       : '(' f_args rparen
                  {
                    $$ = $2;
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
                | {
                    $<num>$ = in_kwarg;
                    in_kwarg = 1;
                    SET_LEX_STATE(lex_state | EXPR_LABEL);  /* force for args */
                  }
                  f_args term
                  {
                    in_kwarg = !!$<num>1;
                    $$ = $2;
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
                ;

args_tail       : f_kwarg ',' f_kwrest opt_f_block_arg
                  {
                    $$ = new_args_tail($1, $3, $4);
                  }
                | f_kwarg opt_f_block_arg
                  {
                    $$ = new_args_tail($1, 0, $2);
                  }
                | f_kwrest opt_f_block_arg
                  {
                    $$ = new_args_tail(0, $1, $2);
                  }
                | f_block_arg
                  {
                    $$ = new_args_tail(0, 0, $1);
                  }
                ;

opt_args_tail   : ',' args_tail
                  {
                    $$ = $2;
                  }
                | /* none */
                  {
                    $$ = new_args_tail(0, 0, 0);
                  }
                ;

f_args          : f_arg ',' f_optarg ',' f_rest_arg opt_args_tail
                  {
                    $$ = new_args($1, $3, $5, 0, $6);
                  }
                | f_arg ',' f_optarg ',' f_rest_arg ',' f_arg opt_args_tail
                  {
                    $$ = new_args($1, $3, $5, $7, $8);
                  }
                | f_arg ',' f_optarg opt_args_tail
                  {
                    $$ = new_args($1, $3, 0, 0, $4);
                  }
                | f_arg ',' f_optarg ',' f_arg opt_args_tail
                  {
                    $$ = new_args($1, $3, 0, $5, $6);
                  }
                | f_arg ',' f_rest_arg opt_args_tail
                  {
                    $$ = new_args($1, 0, $3, 0, $4);
                  }
                | f_arg ',' f_rest_arg ',' f_arg opt_args_tail
                  {
                    $$ = new_args($1, 0, $3, $5, $6);
                  }
                | f_arg opt_args_tail
                  {
                    $$ = new_args($1, 0, 0, 0, $2);
                  }
                | f_optarg ',' f_rest_arg opt_args_tail
                  {
                    $$ = new_args(0, $1, $3, 0, $4);
                  }
                | f_optarg ',' f_rest_arg ',' f_arg opt_args_tail
                  {
                    $$ = new_args(0, $1, $3, $5, $6);
                  }
                | f_optarg opt_args_tail
                  {
                    $$ = new_args(0, $1, 0, 0, $2);
                  }
                | f_optarg ',' f_arg opt_args_tail
                  {
                    $$ = new_args(0, $1, 0, $3, $4);
                  }
                | f_rest_arg opt_args_tail
                  {
                    $$ = new_args(0, 0, $1, 0, $2);
                  }
                | f_rest_arg ',' f_arg opt_args_tail
                  {
                    $$ = new_args(0, 0, $1, $3, $4);
                  }
                | args_tail
                  {
                    $$ = new_args(0, 0, 0, 0, $1);
                  }
                | /* none */
                  {
                    $$ = new_args_tail(0, 0, 0);
                    $$ = new_args(0, 0, 0, 0, $$);
                  }
                ;

f_bad_arg       : tCONSTANT
                  {
                    yy_error("formal argument cannot be a constant");
                    $$ = 0;
                  }
                | tIVAR
                  {
                    yy_error("formal argument cannot be an instance variable");
                    $$ = 0;
                  }
                | tGVAR
                  {
                    yy_error("formal argument cannot be a global variable");
                    $$ = 0;
                  }
                | tCVAR
                  {
                    yy_error("formal argument cannot be a class variable");
                    $$ = 0;
                  }
                ;

f_norm_arg      : f_bad_arg
                | tIDENTIFIER
                  {
                    formal_argument(get_id($1));
                    $$ = $1;
                  }
                ;

f_arg_asgn      : f_norm_arg
                  {
                    ID id = get_id($1);
                    arg_var(id);
                    $$ = $1;
                  }
                ;

f_arg_item      : f_arg_asgn
                  {
                    $$ = NEW_ARGS_AUX($1, 1);
                  }
                | tLPAREN f_margs rparen
                  {
                    ID tid = internal_id();
                    arg_var(tid);
                    $2->nd_value = NEW_LVAR(tid);
                    $$ = NEW_ARGS_AUX(tid, 1);
                    $$->nd_next = $2;
                  }
                ;

f_arg           : f_arg_item
                | f_arg ',' f_arg_item
                  {
                    $$ = $1;
                    $$->nd_plen++;
                    $$->nd_next = block_append($$->nd_next, $3->nd_next);
                  }
                ;

f_label         : tLABEL
                  {
                    ID id = get_id($1);
                    arg_var(formal_argument(id));
                    $$ = $1;
                  }
                ;

f_kw            : f_label arg_value
                  {
                    $$ = assignable($1, $2);
                    $$ = NEW_KW_ARG(0, $$);
                  }
                | f_label
                  {
                    $$ = assignable($1, NEW_REQ_KW);
                    $$ = NEW_KW_ARG(0, $$);
                  }
                ;

f_block_kw      : f_label primary_value
                  {
                    $$ = assignable($1, $2);
                    $$ = NEW_KW_ARG(0, $$);
                  }
                | f_label
                  {
                    $$ = assignable($1, NEW_REQ_KW);
                    $$ = NEW_KW_ARG(0, $$);
                  }
                ;

f_block_kwarg   : f_block_kw
                  {
                    $$ = $1;
                  }
                | f_block_kwarg ',' f_block_kw
                  {
                    NODE *kws = $1;
                    while(kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = $3;
                    $$ = $1;
                  }
                ;

f_kwarg         : f_kw
                  {
                    $$ = $1;
                  }
                | f_kwarg ',' f_kw
                  {
                    NODE *kws = $1;
                    while(kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = $3;
                    $$ = $1;
                  }
                ;

kwrest_mark     : tPOW
                | tDSTAR
                ;

f_kwrest        : kwrest_mark tIDENTIFIER
                  {
                    shadowing_lvar(get_id($2));
                    $$ = $2;
                  }
                | kwrest_mark
                  {
                    $$ = internal_id();
                    arg_var($$);
                  }
                ;

f_opt           : f_arg_asgn '=' arg_value
                  {
                    $$ = assignable($1, $3);
                    $$ = NEW_OPT_ARG(0, $$);
                  }
                ;

f_block_opt     : f_arg_asgn '=' primary_value
                  {
                    $$ = assignable($1, $3);
                    $$ = NEW_OPT_ARG(0, $$);
                  }
                ;

f_block_optarg  : f_block_opt
                  {
                    $$ = $1;
                  }
                | f_block_optarg ',' f_block_opt
                  {
                    NODE *opts = $1;
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = $3;
                    $$ = $1;
                  }
                ;

f_optarg        : f_opt
                  {
                    $$ = $1;
                  }
                | f_optarg ',' f_opt
                  {
                    NODE *opts = $1;
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = $3;
                    $$ = $1;
                  }
                ;

restarg_mark    : '*'
                | tSTAR
                ;

f_rest_arg      : restarg_mark tIDENTIFIER
                  {
                    if(!is_local_id($2)) {
                      yy_error("rest argument must be local variable");
                    }
                    arg_var(shadowing_lvar(get_id($2)));
                    $$ = $2;
                  }
                | restarg_mark
                  {
                    $$ = internal_id();
                    arg_var($$);
                  }
                ;

blkarg_mark     : '&'
                | tAMPER
                ;

f_block_arg     : blkarg_mark tIDENTIFIER
                  {
                    if(!is_local_id($2))
                      yy_error("block argument must be local variable");
                    else if(!in_block() && local_id($2))
                      yy_error("duplicate block argument name");
                    arg_var(shadowing_lvar(get_id($2)));
                    $$ = $2;
                  }
                ;

opt_f_block_arg : ',' f_block_arg
                  {
                    $$ = $2;
                  }
                | none
                  {
                    $$ = 0;
                  }
                ;

singleton       : var_ref
                  {
                    value_expr($1);
                    $$ = $1;
                    if(!$$) $$ = NEW_NIL();
                  }
                | '(' {SET_LEX_STATE(EXPR_BEG);} expr rparen
                  {
                    if($3 == 0) {
                      yy_error("can't define singleton method for ().");
                    } else {
                      switch(nd_type($3)) {
                      case NODE_STR:
                      case NODE_DSTR:
                      case NODE_XSTR:
                      case NODE_DXSTR:
                      case NODE_DREGX:
                      case NODE_LIT:
                      case NODE_ARRAY:
                      case NODE_ZARRAY:
                        yy_error("can't define singleton method for literals");
                      default:
                        value_expr($3);
                        break;
                      }
                    }
                    $$ = $3;
                  }
                ;

assoc_list      : none
                | assocs trailer
                  {
                    $$ = $1;
                  }
                ;

assocs          : assoc
                | assocs ',' assoc
                  {
                    $$ = list_concat($1, $3);
                  }
                ;

assoc           : arg_value tASSOC arg_value
                  {
                    $$ = list_append(NEW_LIST($1), $3);
                  }
                | tLABEL arg_value
                  {
                    $$ = list_append(NEW_LIST(NEW_LIT(ID2SYM($1))), $2);
                  }
                | tSTRING_BEG string_contents tLABEL_END arg_value
                  {
                    $$ = list_append(NEW_LIST(dsym_node($2)), $4);
                  }
                | tDSTAR arg_value
                  {
                    $$ = list_append(NEW_LIST(0), $2);
                  }
                ;

operation       : tIDENTIFIER
                | tCONSTANT
                | tFID
                ;

operation2      : tIDENTIFIER
                | tCONSTANT
                | tFID
                | op
                ;

operation3      : tIDENTIFIER
                | tFID
                | op
                ;

dot_or_colon    : '.'
                | tCOLON2
                ;

call_op         : '.'
                  {
                    $$ = '.';
                  }
                | tANDDOT
                  {
                    $$ = tANDDOT;
                  }
                ;

call_op2        : call_op
                | tCOLON2
                  {
                    $$ = tCOLON2;
                  }
                ;

opt_terms       : /* none */
                | terms
                ;

opt_nl          : /* none */
                | '\n'
                ;

rparen          : opt_nl ')'
                ;

rbracket        : opt_nl ']'
                ;

trailer         : /* none */
                | '\n'
                | ','
                ;

term            : ';' {yyerrok;}
                | '\n'
                ;

terms           : term
                | terms ';' {yyerrok;}
                ;

none            : /* none */ {$$ = 0;}
                ;
%%

#undef parser
#undef yylex
#undef yylval
#define yylval  (*((YYSTYPE*)(lval)))

static int parser_regx_options(rb_parser_state*);
static int parser_tokadd_string(rb_parser_state*, int, int, int, long*, rb_encoding**);
static void parser_tokaddmbc(rb_parser_state*, int c, rb_encoding *);
static int parser_parse_string(rb_parser_state*, NODE*);
static int parser_here_document(rb_parser_state*, NODE*);


#define nextc()                   parser_nextc(parser_state)
#define pushback(c)               parser_pushback(parser_state, (c))
#define newtok()                  parser_newtok(parser_state)
#define tokspace(n)               parser_tokspace(parser_state, (n))
#define tokadd(c)                 parser_tokadd(parser_state, (c))
#define tok_hex(numlen)           parser_tok_hex(parser_state, (numlen))
#define read_escape(flags,e)      parser_read_escape(parser_state, (flags), (e))
#define tokadd_escape(e)          parser_tokadd_escape(parser_state, (e))
#define regx_options()            parser_regx_options(parser_state)
#define tokadd_string(f,t,p,n,e)  parser_tokadd_string(parser_state, (f), (t), (p), (n), (e))
#define parse_string(n)           parser_parse_string(parser_state, (n))
#define tokaddmbc(c, enc)         parser_tokaddmbc(parser_state, (c), (enc))
#define here_document(n)          parser_here_document(parser_state, (n))
#define heredoc_identifier()      parser_heredoc_identifier(parser_state)
#define heredoc_restore(n)        parser_heredoc_restore(parser_state, (n))
#define whole_match_p(e,l,i)      parser_whole_match_p(parser_state, (e), (l), (i))
#define number_literal_suffix(f)  parser_number_literal_suffix(parser_state, (f))
#define set_number_literal(v,t,f) parser_set_number_literal(parser_state, (v), (t), (f))
#define set_integer_literal(v,f)  parser_set_integer_literal(parser_state, (v), (f))

#define set_yylval_str(x)         yylval.node = NEW_STR(x)
#define set_yylval_num(x)         yylval.num = x
#define set_yylval_id(x)          yylval.id = x
#define set_yylval_name(x)        yylval.id = x
#define set_yylval_literal(x)     yylval.node = NEW_LIT(x)
#define set_yylval_number(x)      yylval.node = NEW_NUMBER(x)
#define set_yylval_float(x)       yylval.node = NEW_FLOAT(x)
#define set_yylval_rational(x)    yylval.node = NEW_RATIONAL(x)
#define set_yylval_imaginary(x)   yylval.node = NEW_IMAGINARY(x)
#define set_yylval_node(x)        yylval.node = x
#define yylval_id()               yylval.id

/* We remove any previous definition of `SIGN_EXTEND_CHAR',
   since ours (we hope) works properly with all combinations of
   machines, compilers, `char' and `unsigned char' argument types.
   (Per Bothner suggested the basic approach.)  */
#undef SIGN_EXTEND_CHAR
#if __STDC__
# define SIGN_EXTEND_CHAR(c) ((signed char)(c))
#else  /* not __STDC__ */
/* As in Harbison and Steele.  */
# define SIGN_EXTEND_CHAR(c) ((((unsigned char)(c)) ^ 128) - 128)
#endif

#define parser_encoding_name()    (parser_state->enc->name)
#define parser_mbclen()           parser_enc_mbclen((lex_p-1),lex_pend,parser->enc)
#define parser_precise_mbclen()   parser_enc_precise_mbclen((lex_p-1),lex_pend,parser_state->enc)
#define is_identchar(p,e,enc)     (parser_enc_isalnum(*p,enc) || (*p) == '_' || !ISASCII(*p))
#define parser_is_identchar()     (!eofp && \
                                   is_identchar((lex_p-1),lex_pend,parser_state->enc))

#define parser_isascii() ISASCII(*(lex_p-1))

static int token_info_get_column(rb_parser_state* parser_state, const char *pend) {
  int col = 1;
  const char *p;
  for(p = lex_pbeg; p < pend; p++) {
    if(*p == '\t') {
      col = (((col - 1) / TAB_WIDTH) + 1) * TAB_WIDTH;
    }
    col++;
  }
  return col;
}

static int token_info_has_nonspaces(rb_parser_state* parser_state, const char *pend) {
  const char *p;
  for(p = lex_pbeg; p < pend; p++) {
    if(*p != ' ' && *p != '\t') {
      return 1;
    }
  }
  return 0;
}

static void parser_token_info_push(rb_parser_state* parser_state, const char *token) {
  /* TODO */
}

static void parser_token_info_pop(rb_parser_state* parser_state, const char *token) {
  /* TODO */
}

static int
parser_yyerror(rb_parser_state* parser_state, const char *msg)
{
  create_error(parser_state, (char *)msg);

  return 1;
}

static int
yycompile(rb_parser_state* parser_state, char *f, int line)
{
  int n;
  /* Setup an initial empty scope. */
  heredoc_end = 0;
  lex_strterm = 0;
  ruby__end__seen = 0;
  sourcefile = f;
  command_start = TRUE;
  parser_prepare(parser_state);
  n = yyparse(parser_state);
  ruby_debug_lines = 0;
  compile_for_eval = 0;
  cond_stack = 0;
  cmdarg_stack = 0;
  class_nest = 0;
  in_single = 0;
  in_def = 0;
  cur_mid = 0;

  return n;
}

static rb_encoding*
must_be_ascii_compatible(VALUE s)
{
  rb_encoding *enc = parser_enc_get(s);
  if(!parser_enc_asciicompat(enc)) {
    // TODO: handle this in a way that doesn't leak parser state
    // rb_raise(rb_eArgError, "invalid source encoding");
  }
  return enc;
}

static VALUE
lex_get_str(rb_parser_state* parser_state, VALUE s)
{
  char *beg, *end, *start;
  long len;

  beg = RSTRING_PTR(s);
  len = RSTRING_LEN(s);
  start = beg;
  if(lex_gets_ptr) {
    if(len == lex_gets_ptr) return Qnil;
    beg += lex_gets_ptr;
    len -= lex_gets_ptr;
  }
  end = (char*)memchr(beg, '\n', len);
  if(end) len = ++end - beg;
  lex_gets_ptr += len;
  return REF(rb_str_subseq(s, beg - start, len));
}

static VALUE
lex_getline(rb_parser_state* parser_state)
{
  VALUE line = (*lex_gets)(parser_state, lex_input);
  if(NIL_P(line)) return line;
  must_be_ascii_compatible(line);

  return line;
}

VALUE process_parse_tree(rb_parser_state*, VALUE, NODE*, ID*);

VALUE
string_to_ast(VALUE ptp, VALUE name, VALUE source, VALUE line)
{
  int l = FIX2INT(line);
  VALUE ret;
  rb_parser_state* parser_state = parser_alloc_state();

  lex_input = source;
  lex_gets = lex_get_str;
  lex_gets_ptr = 0;
  processor = ptp;
  rb_funcall(ptp, rb_intern("references="), 1, references);
  sourceline = l - 1;
  compile_for_eval = 1;

  yycompile(parser_state, RSTRING_PTR(name), l);

  if(!parse_error) {
    ret = process_parse_tree(parser_state, ptp, top_node, NULL);
  } else {
    ret = Qnil;
  }
  pt_free(parser_state);
  free(parser_state);
  return ret;
}

#define LEX_IO_BUFLEN  5120

static VALUE parse_io_gets(rb_parser_state* parser_state, VALUE s) {
  VALUE str = Qnil;
  char* p;
  ssize_t n;

  while(true) {
    if(lex_io_total == 0 || lex_io_index == lex_io_total) {
      lex_io_total = read(lex_io, lex_io_buf, LEX_IO_BUFLEN);

      if(lex_io_total == 0) {
        lex_io_total = 0;
        return str;
      } else if(lex_io_total < 0) {
        // TODO raise exception
        return str;
      } else {
        lex_io_index = 0;
      }
    }

    p = (char*)memchr(lex_io_buf + lex_io_index,
                      '\n', lex_io_total - lex_io_index);
    if(p) {
      n = p - lex_io_buf - lex_io_index + 1;
    } else {
      n = lex_io_total - lex_io_index;
    }

    if(str == Qnil) {
      str = REF(parser_enc_str_new(lex_io_buf + lex_io_index,
                                   n, parser_state->enc));
    } else {
      rb_str_cat(str, lex_io_buf + lex_io_index, n);
    }

    if(p) {
      lex_io_index += n;
      lex_io_count += n;
      return str;
    } else {
      lex_io_total = 0;
      lex_io_index = 0;
    }
  }

  return Qnil;
}

VALUE
file_to_ast(VALUE ptp, const char *f, int fd, int start)
{
  VALUE ret;
  rb_parser_state* parser_state = parser_alloc_state();

  lex_input = Qnil;
  lex_io = fd;
  lex_io_buf = (char*)malloc(LEX_IO_BUFLEN);
  lex_gets = parse_io_gets;
  processor = ptp;
  rb_funcall(ptp, rb_intern("references="), 1, references);
  sourceline = start - 1;

  yycompile(parser_state, (char*)f, start);

  if(!parse_error) {
    ret = process_parse_tree(parser_state, ptp, top_node, NULL);

    if(ruby__end__seen && lex_io) {
      rb_funcall(ptp, rb_sData, 1, ULONG2NUM(lex_io_count));
    }
  } else {
    ret = Qnil;
  }

  pt_free(parser_state);
  free(parser_state);
  return ret;
}

#define STR_FUNC_ESCAPE 0x01
#define STR_FUNC_EXPAND 0x02
#define STR_FUNC_REGEXP 0x04
#define STR_FUNC_QWORDS 0x08
#define STR_FUNC_SYMBOL 0x10
#define STR_FUNC_INDENT 0x20
#define STR_FUNC_LABEL  0x40

enum string_type {
  str_squote = (0),
  str_dquote = (STR_FUNC_EXPAND),
  str_xquote = (STR_FUNC_EXPAND),
  str_regexp = (STR_FUNC_REGEXP|STR_FUNC_ESCAPE|STR_FUNC_EXPAND),
  str_sword  = (STR_FUNC_QWORDS),
  str_dword  = (STR_FUNC_QWORDS|STR_FUNC_EXPAND),
  str_ssym   = (STR_FUNC_SYMBOL),
  str_dsym   = (STR_FUNC_SYMBOL|STR_FUNC_EXPAND),
  str_label  = (STR_FUNC_LABEL),
};

static VALUE
parser_str_new(rb_parser_state* parser_state, const char *p, long n,
               rb_encoding *enc, int func, rb_encoding *enc0)
{
  VALUE str;
  str = REF(parser_enc_str_new(p, n, enc));
  if(!(func & STR_FUNC_REGEXP) && parser_enc_asciicompat(enc)) {
    if(parser_enc_str_coderange(str) == ENC_CODERANGE_7BIT) {
      // Do nothing.
    } else if(enc0 == parser_usascii_encoding() && enc != parser_utf8_encoding()) {
      parser_enc_associate(str, parser_ascii8bit_encoding());
    }
  }

  return str;
}

#define lex_goto_eol(parser_state)  (lex_p = lex_pend)
#define lex_eol_p() (lex_p >= lex_pend)
#define peek(c) (lex_p < lex_pend && (c) == *lex_p)
#define peek_n(c,n) (lex_p+(n) < lex_pend && (c) == (unsigned char)lex_p[n])
#define peekc() peekc_n(0)
#define peekc_n(n) (lex_p+(n) < lex_pend ? (unsigned char)lex_p[n] : -1)

static inline int parser_nextc(rb_parser_state* parser_state) {
  int c;

  if(lex_p == lex_pend) {
    VALUE v = lex_nextline;
    lex_nextline = 0;
    if(!v) {
      if(eofp)
        return -1;

      if(!lex_input || NIL_P(v = lex_getline(parser_state))) {
        eofp = true;
        lex_goto_eol(parser_state);
        return -1;
      }
    }

    if(heredoc_end > 0) {
      sourceline = heredoc_end;
      heredoc_end = 0;
    }

    sourceline++;
    line_count++;
    lex_pbeg = lex_p = RSTRING_PTR(v);
    lex_pend = lex_p + RSTRING_LEN(v);
    lex_lastline = v;
  }

  c = (unsigned char)*lex_p++;
  if(c == '\r' && peek('\n')) {
    lex_p++;
    c = '\n';
  }

  return c;
}

static void parser_pushback(rb_parser_state* parser_state, int c) {
  if(c == -1) return;
  lex_p--;
  if(lex_p > lex_pbeg && lex_p[0] == '\n' && lex_p[-1] == '\r') {
    lex_p--;
  }
}

/* Indicates if we're currently at the beginning of a line. */
#define was_bol() (lex_p == lex_pbeg + 1)

/* The token buffer. It's just a global string that has
   functions to build up the string easily. */

#define tokfix() (tokenbuf[tokidx]='\0')
#define tok() tokenbuf
#define toklen() tokidx
#define toklast() (tokidx>0?tokenbuf[tokidx-1]:0)

static char* parser_newtok(rb_parser_state* parser_state) {
  tokidx = 0;
  tokline = sourceline;
  if(!tokenbuf) {
    toksiz = 60;
    tokenbuf = ALLOC_N(char, 60);
  }
  if(toksiz > 4096) {
    toksiz = 60;
    REALLOC_N(tokenbuf, char, 60);
  }
  return tokenbuf;
}

static char * parser_tokspace(rb_parser_state* parser_state, int n) {
  tokidx += n;

  if(tokidx >= toksiz) {
    do {
      toksiz *= 2;
    } while(toksiz < tokidx);
    REALLOC_N(tokenbuf, char, toksiz);
  }
  return &tokenbuf[tokidx-n];
}


static void parser_tokadd(rb_parser_state* parser_state, char c) {
  assert(tokidx < toksiz && tokidx >= 0);
  tokenbuf[tokidx++] = c;
  if(tokidx >= toksiz) {
    toksiz *= 2;
    REALLOC_N(tokenbuf, char, toksiz);
  }
}

static int parser_tok_hex(rb_parser_state* parser_state, size_t *numlen) {
  int c;

  c = scan_hex(lex_p, 2, numlen);
  if(!*numlen) {
    yy_error("invalid hex escape");
    return 0;
  }
  lex_p += *numlen;
  return c;
}

#define tokcopy(n) memcpy(tokspace(n), lex_p - (n), (n))

static int
parser_tokadd_utf8(rb_parser_state* parser_state, rb_encoding** encp,
                   int string_literal, int symbol_literal, int regexp_literal)
{
  /*
   * If string_literal is true, then we allow multiple codepoints
   * in \u{}, and add the codepoints to the current token.
   * Otherwise we're parsing a character literal and return a single
   * codepoint without adding it
   */

  int codepoint;
  size_t numlen;

  if(regexp_literal) {
    tokadd('\\'); tokadd('u');
  }

  if(peek('{')) {  /* handle \u{...} form */
    do {
      if(regexp_literal) tokadd(*lex_p);
      nextc();
      codepoint = scan_hex(lex_p, 6, &numlen);

      if(numlen == 0)  {
        yy_error("invalid Unicode escape");
        return 0;
      }
      if(codepoint > 0x10ffff) {
      yy_error("invalid Unicode codepoint (too large)");
      return 0;
      }

      lex_p += numlen;
      if(regexp_literal) {
        tokcopy((int)numlen);
      } else if(codepoint >= 0x80) {
        *encp = UTF8_ENC();
        if(string_literal) tokaddmbc(codepoint, *encp);
      } else if(string_literal) {
        tokadd(codepoint);
      }
    } while(string_literal && (peek(' ') || peek('\t')));

    if(!peek('}')) {
      yy_error("unterminated Unicode escape");
      return 0;
    }

    if(regexp_literal) tokadd('}');
    nextc();
  } else {
    /* handle \uxxxx form */
    codepoint = scan_hex(lex_p, 4, &numlen);
    if(numlen < 4) {
      yy_error("invalid Unicode escape");
      return 0;
    }
    lex_p += 4;
    if(regexp_literal) {
      tokcopy(4);
    } else if(codepoint >= 0x80) {
      *encp = UTF8_ENC();
      if(string_literal) tokaddmbc(codepoint, *encp);
    } else if(string_literal) {
      tokadd(codepoint);
    }
  }

  return codepoint;
}

#define ESCAPE_CONTROL 1
#define ESCAPE_META    2

static int parser_read_escape(rb_parser_state* parser_state,
                              int flags, rb_encoding **encp)
{
  int c;
  size_t numlen;

  switch(c = nextc()) {
  case '\\':  /* Backslash */
    return c;
  case 'n':   /* newline */
    return '\n';
  case 't':   /* horizontal tab */
    return '\t';
  case 'r':   /* carriage-return */
    return '\r';
  case 'f':   /* form-feed */
    return '\f';
  case 'v':   /* vertical tab */
    return '\13';
  case 'a':   /* alarm(bell) */
    return '\007';
  case 'e':   /* escape */
    return 033;

  case '0': case '1': case '2': case '3': /* octal constant */
  case '4': case '5': case '6': case '7':
    pushback(c);
    c = scan_oct(lex_p, 3, &numlen);
    lex_p += numlen;
    return c;

  case 'x':   /* hex constant */
    c = tok_hex(&numlen);
    if(numlen == 0) return 0;
    return c;

  case 'b':   /* backspace */
    return '\010';

  case 's':   /* space */
    return ' ';

  case 'M':
    if(flags & ESCAPE_META) goto eof;
    if((c = nextc()) != '-') {
      pushback(c);
      goto eof;
    }
    if((c = nextc()) == '\\') {
      if(peek('u')) goto eof;
      return read_escape(flags|ESCAPE_META, encp) | 0x80;
    } else if(c == -1 || !ISASCII(c)) {
      goto eof;
    } else {
      return ((c & 0xff) | 0x80);
    }

  case 'C':
    if((c = nextc()) != '-') {
      pushback(c);
      goto eof;
    }
  case 'c':
    if(flags & ESCAPE_CONTROL) goto eof;
    if((c = nextc())== '\\') {
      if(peek('u')) goto eof;
      c = read_escape(flags|ESCAPE_CONTROL, encp);
    } else if(c == '?') {
      return 0177;
    } else if(c == -1 || !ISASCII(c)) {
      goto eof;
    }
    return c & 0x9f;

  eof:
  case -1:
    yy_error("Invalid escape character syntax");
    return '\0';

  default:
    return c;
  }
}

static void parser_tokaddmbc(rb_parser_state* parser_state, int c, rb_encoding *enc) {
  int len = parser_enc_codelen(c, enc);
  parser_enc_mbcput(c, tokspace(len), enc);
}

static int parser_tokadd_escape(rb_parser_state* parser_state, rb_encoding **encp) {
  int c;
  int flags = 0;
  size_t numlen;

first:
  switch(c = nextc()) {
  case '\n':
    return 0;   /* just ignore */

  case '0': case '1': case '2': case '3': /* octal constant */
  case '4': case '5': case '6': case '7':
    {
      scan_oct(--lex_p, 3, &numlen);
      if(numlen == 0) goto eof;
      lex_p += numlen;
      tokcopy((int)numlen + 1);
    }
    return 0;

  case 'x':   /* hex constant */
    {
      tok_hex(&numlen);
      if(numlen == 0) goto eof;
      tokcopy((int)numlen + 2);
    }
    return 0;

  case 'M':
    if(flags & ESCAPE_META) goto eof;
    if((c = nextc()) != '-') {
      pushback(c);
      goto eof;
    }
    tokcopy(3);
    flags |= ESCAPE_META;
    goto escaped;

  case 'C':
    if(flags & ESCAPE_CONTROL) goto eof;
    if((c = nextc()) != '-') {
      pushback(c);
      goto eof;
    }
    tokcopy(3);
    goto escaped;

  case 'c':
    if(flags & ESCAPE_CONTROL) goto eof;
    tokcopy(2);
    flags |= ESCAPE_CONTROL;
escaped:
    if((c = nextc()) == '\\') {
      goto first;
    } else if(c == -1) goto eof;
    tokadd(c);
    return 0;

eof:
  case -1:
    yy_error("Invalid escape character syntax");
    return -1;

  default:
    tokadd('\\');
    tokadd(c);
  }

  return 0;
}

static int parser_regx_options(rb_parser_state* parser_state) {
    int kcode = 0;
    int options = 0;
    int c;

    /* TODO */
    newtok();
    while(c = nextc(), ISALPHA(c)) {
      switch(c) {
      case 'i':
        options |= RE_OPTION_IGNORECASE;
        break;
      case 'x':
        options |= RE_OPTION_EXTENDED;
        break;
      case 'm':
        options |= RE_OPTION_MULTILINE;
        break;
      case 'o':
        options |= RE_OPTION_ONCE;
        break;
      case 'G':
        options |= RE_OPTION_CAPTURE_GROUP;
        break;
      case 'g':
        options |= RE_OPTION_DONT_CAPTURE_GROUP;
        break;
      case 'n':
        kcode = RE_KCODE_NONE;
        break;
      case 'e':
        kcode = RE_KCODE_EUC;
        break;
      case 's':
        kcode = RE_KCODE_SJIS;
        break;
      case 'u':
        kcode = RE_KCODE_UTF8;
        break;
      default:
        tokadd((char)c);
        break;
      }
    }
    pushback(c);
    if(toklen()) {
      tokfix();
      rb_compile_error(parser_state, "unknown regexp option%s - %s",
                       toklen() > 1 ? "s" : "", tok());
    }
    return options | kcode;
}

static int parser_tokadd_mbchar(rb_parser_state* parser_state, int c) {
  int len = parser_precise_mbclen();
  if(!MBCLEN_CHARFOUND_P(len)) {
    rb_compile_error(parser_state, "invalid multibyte char (%s)", parser_encoding_name());
    return -1;
  }
  tokadd(c);
  lex_p += --len;
  if(len > 0) tokcopy(len);
  return c;
}

#define tokadd_mbchar(c) parser_tokadd_mbchar(parser_state, c)

static inline int simple_re_meta(int c) {
  switch(c) {
    case '$': case '*': case '+': case '.':
    case '?': case '^': case '|':
    case ')': case ']': case '}': case '>':
      return TRUE;
    default:
      return FALSE;
  }
}

static int parser_update_heredoc_indent(rb_parser_state* parser_state, int c) {
  if(heredoc_line_indent == -1) {
    if(c == '\n') heredoc_line_indent = 0;
  } else {
    if(c == ' ') {
      heredoc_line_indent++;
      return TRUE;
    } else if(c == '\t') {
      int w = (heredoc_line_indent / TAB_WIDTH) + 1;
      heredoc_line_indent = w * TAB_WIDTH;
      return TRUE;
    } else if(c != '\n') {
      if(heredoc_indent > heredoc_line_indent) {
        heredoc_indent = heredoc_line_indent;
      }
      heredoc_line_indent = -1;
    }
  }
  return FALSE;
}

static int
parser_tokadd_string(rb_parser_state* parser_state,
                     int func, int term, int paren, long *nest,
                     rb_encoding **encp)
{
  int c;
  int has_nonascii = 0;
  rb_encoding *enc = *encp;
  char *errbuf = 0;
  static const char mixed_msg[] = "%s mixed within %s source";

#define mixed_error(enc1, enc2) if(!errbuf) {  \
        size_t len = sizeof(mixed_msg) - 4;     \
        len += strlen(rb_enc_name(enc1));       \
        len += strlen(rb_enc_name(enc2));       \
        errbuf = ALLOCA_N(char, len);           \
        snprintf(errbuf, len, mixed_msg,        \
                 rb_enc_name(enc1),             \
                 rb_enc_name(enc2));            \
        yy_error(errbuf);                       \
    }
#define mixed_escape(beg, enc1, enc2) do {      \
        const char *pos = lex_p;                \
        lex_p = (beg);                          \
        mixed_error((enc1), (enc2));            \
        lex_p = pos;                            \
    } while(0)

    while((c = nextc()) != -1) {
      if(heredoc_indent > 0) {
        parser_update_heredoc_indent(parser_state, c);
      }
      if(paren && c == paren) {
        ++*nest;
      } else if(c == term) {
        if(!nest || !*nest) {
          pushback(c);
          break;
        }
        --*nest;
      } else if((func & STR_FUNC_EXPAND) && c == '#' && lex_p < lex_pend) {
        int c2 = *lex_p;
        if(c2 == '$' || c2 == '@' || c2 == '{') {
          pushback(c);
          break;
        }
      } else if(c == '\\') {
        const char *beg = lex_p - 1;
        c = nextc();
        switch (c) {
        case '\n':
          if(func & STR_FUNC_QWORDS) break;
          if(func & STR_FUNC_EXPAND) continue;
          tokadd('\\');
          break;

        case '\\':
          if(func & STR_FUNC_ESCAPE) tokadd(c);
          break;

        case 'u':
          if((func & STR_FUNC_EXPAND) == 0) {
            tokadd('\\');
            break;
          }
          parser_tokadd_utf8(parser_state, &enc, 1,
                             func & STR_FUNC_SYMBOL,
                             func & STR_FUNC_REGEXP);
          if(has_nonascii && enc != *encp) {
            mixed_escape(beg, enc, *encp);
          }
          continue;

        default:
          if(c == -1) return -1;
          if(!ISASCII(c)) {
            if((func & STR_FUNC_EXPAND) == 0) tokadd('\\');
            goto non_ascii;
          }
          if(func & STR_FUNC_REGEXP) {
            if(c == term && !simple_re_meta(c)) {
              tokadd(c);
              continue;
            }
            pushback(c);
            if((c = tokadd_escape(&enc)) < 0) {
              return -1;
            }
            if(has_nonascii && enc != *encp) {
              mixed_escape(beg, enc, *encp);
            }
            continue;
          } else if(func & STR_FUNC_EXPAND) {
            pushback(c);
            if(func & STR_FUNC_ESCAPE) tokadd('\\');
            c = read_escape(0, &enc);
          } else if((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
            /* ignore backslashed spaces in %w */
          } else if(c != term && !(paren && c == paren)) {
            tokadd('\\');
            pushback(c);
            continue;
          }
        }
      } else if(!parser_isascii()) {
      non_ascii:
        has_nonascii = 1;
        if(enc != *encp) {
          mixed_error(enc, *encp);
          continue;
        }
        if(tokadd_mbchar(c) == -1) return -1;
        continue;
      } else if((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
        pushback(c);
        break;
      }
      if(c & 0x80) {
        has_nonascii = 1;
        if(enc != *encp) {
          mixed_error(enc, *encp);
          continue;
        }
      }
      tokadd(c);
    }
    *encp = enc;
    return c;
}

#define NEW_STRTERM(func, term, paren) \
  node_newnode(NODE_STRTERM, (VALUE)(func), \
               (VALUE)((term) | ((paren) << (CHAR_BIT * 2))), 0)
#define pslval ((YYSTYPE *)lval)

#define BIT(c, idx) (((c) / 32 - 1 == idx) ? (1U << ((c) % 32)) : 0)
#define SPECIAL_PUNCT(idx) ( \
  BIT('~', idx) | BIT('*', idx) | BIT('$', idx) | BIT('?', idx) | \
  BIT('!', idx) | BIT('@', idx) | BIT('/', idx) | BIT('\\', idx) | \
  BIT(';', idx) | BIT(',', idx) | BIT('.', idx) | BIT('=', idx) | \
  BIT(':', idx) | BIT('<', idx) | BIT('>', idx) | BIT('\"', idx) | \
  BIT('&', idx) | BIT('`', idx) | BIT('\'', idx) | BIT('+', idx) | \
  BIT('0', idx))
const unsigned int ruby_global_name_punct_bits[] = {
    SPECIAL_PUNCT(0),
    SPECIAL_PUNCT(1),
    SPECIAL_PUNCT(2),
};
#undef BIT
#undef SPECIAL_PUNCT

static inline int is_global_name_punct(const int c) {
  if(c <= 0x20 || 0x7e < c) return 0;
  return (ruby_global_name_punct_bits[(c - 0x20) / 32] >> (c % 32)) & 1;
}

static int parser_peek_variable_name(rb_parser_state* parser_state) {
  int c;
  const char *p = lex_p;

  if(p + 1 >= lex_pend) return 0;
  c = *p++;
  switch(c) {
  case '$':
    if((c = *p) == '-') {
      if(++p >= lex_pend) return 0;
      c = *p;
    } else if(is_global_name_punct(c) || ISDIGIT(c)) {
      return tSTRING_DVAR;
    }
    break;
  case '@':
    if((c = *p) == '@') {
      if(++p >= lex_pend) return 0;
      c = *p;
    }
    break;
  case '{':
    lex_p = p;
    command_start = TRUE;
    return tSTRING_DBEG;
  default:
    return 0;
  }
  if(!ISASCII(c) || c == '_' || ISALPHA(c)) return tSTRING_DVAR;

  return 0;
}

static int parser_parse_string(rb_parser_state* parser_state, NODE *quote) {
  int func = (int)quote->nd_func;
  int term = nd_term(quote);
  int paren = nd_paren(quote);
  int c, space = 0;
  rb_encoding* enc = parser_state->enc;

  long start_line = sourceline;

  if(func == -1) return tSTRING_END;
  c = nextc();
  if((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
    do {c = nextc();} while(ISSPACE(c));
    space = 1;
  }
  if(c == term && !quote->nd_nest) {
    if(func & STR_FUNC_QWORDS) {
      quote->nd_func = -1;
      return ' ';
    }
    if(!(func & STR_FUNC_REGEXP)) return tSTRING_END;
    set_yylval_num(regx_options());
    return tREGEXP_END;
  }
  if(space) {
    pushback(c);
    return ' ';
  }
  newtok();
  if((func & STR_FUNC_EXPAND) && c == '#') {
    int t = parser_peek_variable_name(parser_state);
    if(t) return t;
    tokadd('#');
    c = nextc();
  }
  pushback(c);
  if(tokadd_string(func, term, paren, &quote->nd_nest, &enc) == -1) {
    sourceline = nd_line(quote);
    if(func & STR_FUNC_REGEXP) {
      if(eofp)
        rb_compile_error(parser_state, "unterminated regexp meets end of file");
      return tREGEXP_END;
    } else {
      if(eofp)
        rb_compile_error(parser_state, "unterminated string meets end of file");
      return tSTRING_END;
    }
  }

  tokfix();
  set_yylval_str(STR_NEW3(tok(), toklen(), enc, func));
  nd_set_line(pslval->node, start_line);
  return tSTRING_CONTENT;
}

/* Called when the lexer detects a heredoc is beginning. This pulls
   in more characters and detects what kind of heredoc it is. */
static int parser_heredoc_identifier(rb_parser_state* parser_state) {
  int c = nextc(), term, func = 0;
  size_t len;

  if(c == '-') {
    c = nextc();
    func = STR_FUNC_INDENT;
  } else if(c == '~') {
    c = nextc();
    func = STR_FUNC_INDENT;
    heredoc_indent = INT_MAX;
    heredoc_line_indent = 0;
  }
  switch(c) {
  case '\'':
    func |= str_squote; goto quoted;
  case '"':
    func |= str_dquote; goto quoted;
  case '`':
    func |= str_xquote;
  quoted:
    /* The heredoc indent is quoted, so its easy to find, we just
       continue to consume characters into the token buffer until
       we hit the terminating character. */

    newtok();
    tokadd(func);
    term = c;

    /* Where of where has the term gone.. */
    while((c = nextc()) != -1 && c != term) {
      if(tokadd_mbchar(c) == -1) return 0;
    }

    /* Ack! end of file or end of string. */
    if(c == -1) {
      rb_compile_error(parser_state, "unterminated here document identifier");
      return 0;
    }

    break;

  default:
    /* Ok, this is an unquoted heredoc ident. We just consume
       until we hit a non-ident character. */

    /* Do a quick check that first character is actually valid.
       if it's not, then this isn't actually a heredoc at all!
       It sucks that it's way down here in this function that in
       finally bails with this not being a heredoc.*/

    if(!parser_is_identchar()) {
      pushback(c);
      if(func & STR_FUNC_INDENT) {
        pushback(heredoc_indent > 0 ? '~' : '-');
      }
      return 0;
    }

    /* Finally, setup the token buffer and begin to fill it. */
    newtok();
    term = '"';
    tokadd(func |= str_dquote);
    do {
      if(tokadd_mbchar(c) == -1) return 0;
    } while((c = nextc()) != -1 && parser_is_identchar());
    pushback(c);
    break;
  }


  /* Fixup the token buffer, ie set the last character to null. */
  tokfix();
  len = lex_p - lex_pbeg;
  lex_goto_eol(parser_state);

  /* Tell the lexer that we're inside a string now. nd_lit is
     the heredoc identifier that we watch the stream for to
     detect the end of the heredoc. */
  lex_strterm = node_newnode(NODE_HEREDOC,
                             REF(STR_NEW(tok(), toklen())), /* nd_lit */
                             (VALUE)len,                    /* nd_nth */
                             (VALUE)lex_lastline);          /* nd_orig */
  nd_set_line(lex_strterm, sourceline);
  return term == '`' ? tXSTRING_BEG : tSTRING_BEG;
}

static void parser_heredoc_restore(rb_parser_state* parser_state, NODE *here) {
  VALUE line;

  lex_strterm = 0;
  line = here->nd_orig;
  lex_lastline = line;
  lex_pbeg = RSTRING_PTR(line);
  lex_pend = lex_pbeg + RSTRING_LEN(line);
  lex_p = lex_pbeg + here->nd_nth;
  heredoc_end = sourceline;
  sourceline = nd_line(here);
}

static int dedent_pos(const char *str, long len, int width) {
  int i, col = 0;

  for(i = 0; i < len && col < width; i++) {
    if(str[i] == ' ') {
      col++;
    } else if(str[i] == '\t') {
      int n = TAB_WIDTH * (col / TAB_WIDTH + 1);
      if(n > width) break;
      col = n;
    } else {
      break;
    }
  }
  return i;
}

static VALUE parser_heredoc_dedent_string(VALUE input, int width, int first) {
  long len;
  int col;
  char *str, *p, *out_p, *end, *t;

  RSTRING_GETMEM(input, str, len);
  end = &str[len];

  p = str;
  if(!first) {
    p = (char*)memchr(p, '\n', end - p);
    if(!p) return input;
    p++;
  }
  out_p = p;
  while(p < end) {
    col = dedent_pos(p, end - p, width);
    p += col;
    if(!(t = (char*)memchr(p, '\n', end - p)))
    t = end;
    else
    ++t;
    if(p > out_p) memmove(out_p, p, t - p);
    out_p += t - p;
    p = t;
  }
  rb_str_set_len(input, out_p - str);

  return input;
}

static void parser_heredoc_dedent(rb_parser_state* parser_state, NODE *root) {
  NODE *node, *str_node;
  int first = TRUE;
  int indent = heredoc_indent;

  if(indent <= 0) return;

  node = str_node = root;

  while(str_node) {
    VALUE lit = str_node->nd_lit;
    if(NIL_P(parser_heredoc_dedent_string(lit, indent, first)))
    rb_compile_error(parser_state, "dedent failure: %d: %ld", indent, lit);
    first = FALSE;

    str_node = 0;
    while((node = node->nd_next) != 0 && nd_type(node) == NODE_ARRAY) {
      if((str_node = node->nd_head) != 0) {
        int type = nd_type(str_node);
        if(type == NODE_STR || type == NODE_DSTR) break;
      }
    }
  }
}

static int
parser_whole_match_p(rb_parser_state* parser_state, const char *eos, ssize_t len, int indent)
{
  const char *p = lex_pbeg;
  ssize_t n;

  if(indent) {
    while(*p && ISSPACE(*p)) p++;
  }
  n = lex_pend - (p + len);
  if(n < 0) return FALSE;
  if(n > 0 && p[len] != '\n') {
    if(p[len] != '\r') return FALSE;
    if(n <= 1 || p[len+1] != '\n') return FALSE;
  }
  return strncmp(eos, p, len) == 0;
}

#define NUM_SUFFIX_R   (1<<0)
#define NUM_SUFFIX_I   (1<<1)
#define NUM_SUFFIX_ALL 3

static int
parser_number_literal_suffix(rb_parser_state* parser_state, int mask)
{
  int c, result = 0;
  const char *lastp = lex_p;

  while((c = nextc()) != -1) {
    if((mask & NUM_SUFFIX_I) && c == 'i') {
      result |= (mask & NUM_SUFFIX_I);
      mask &= ~NUM_SUFFIX_I;
      /* r after i, rational of complex is disallowed */
      mask &= ~NUM_SUFFIX_R;
      continue;
    }
    if((mask & NUM_SUFFIX_R) && c == 'r') {
      result |= (mask & NUM_SUFFIX_R);
      mask &= ~NUM_SUFFIX_R;
      continue;
    }
    if(!ISASCII(c) || ISALPHA(c) || c == '_') {
      lex_p = lastp;
      return 0;
    }
    pushback(c);
    if(c == '.') {
      c = peekc_n(1);
      if(ISDIGIT(c)) {
        yy_error("unexpected fraction part after numeric literal");
        lex_p += 2;
        while(parser_is_identchar()) nextc();
      }
    }
    break;
  }

  return result;
}

static int
parser_set_number_literal(rb_parser_state* parser_state, VALUE v, int type, int suffix)
{
  if(suffix & NUM_SUFFIX_I) {
    v = rb_funcall(rb_cObject, rb_intern("Complex"), 2, INT2FIX(0), v);
    type = tIMAGINARY;
  }

  switch(type) {
  case tFLOAT:
    set_yylval_float(v);
    break;
  case tINTEGER:
    set_yylval_number(v);
    break;
  case tRATIONAL:
    set_yylval_rational(v);
    break;
  case tIMAGINARY:
    set_yylval_imaginary(v);
    break;
  default:
    set_yylval_literal(v);
    break;
  }

  return type;
}

static int
parser_set_integer_literal(rb_parser_state* parser_state, VALUE v, int suffix)
{
  int type = tINTEGER;
  if(suffix & NUM_SUFFIX_R) {
    v = rb_funcall(rb_cObject, rb_intern("Rational"), 1, v);
    type = tRATIONAL;
  }
  return set_number_literal(v, type, suffix);
}

/* Called when the lexer knows it's inside a heredoc. This function
   is responsible for detecting an expandions (ie #{}) in the heredoc
   and emitting a lex token and also detecting the end of the heredoc. */

static int parser_here_document(rb_parser_state* parser_state, NODE *here) {
  int c, func, indent = 0;
  const char *eos, *p, *pend;
  ssize_t len;
  VALUE str = 0;
  rb_encoding* enc = parser_state->enc;

  /* eos == the heredoc ident that we found when the heredoc started */
  eos = RSTRING_PTR(here->nd_lit);
  len = RSTRING_LEN(here->nd_lit) - 1;

  /* indicates if we should search for expansions. */
  indent = (func = *eos++) & STR_FUNC_INDENT;

  /* Ack! EOF or end of input string! */
  if((c = nextc()) == -1) {
  error:
    rb_compile_error(parser_state, "can't find string \"%s\" anywhere before EOF", eos);
  restore:
    heredoc_restore(lex_strterm);
    return 0;
  }
  /* Gr. not yet sure what was_bol() means other than it seems like
     it means only 1 character has been consumed. */

  if(was_bol() && whole_match_p(eos, len, indent)) {
    heredoc_restore(lex_strterm);
    return tSTRING_END;
  }

  /* If aren't doing expansions, we can just scan until
     we find the identifier. */

  if((func & STR_FUNC_EXPAND) == 0) {
    int end = 0;
    do {
      p = RSTRING_PTR(lex_lastline);
      pend = lex_pend;
      if(pend > p) {
        switch(pend[-1]) {
        case '\n':
          if(--pend == p || pend[-1] != '\r') {
            pend++;
            break;
          }
        case '\r':
          --pend;
        }
      }

      if(heredoc_indent > 0) {
        long i = 0;
        while(p + i < pend && parser_update_heredoc_indent(parser_state, p[i])) {
          i++;
        }
        heredoc_line_indent = 0;
      }

      if(str) {
        rb_str_cat(str, p, pend - p);
      } else {
        str = REF(STR_NEW(p, pend - p));
      }
      if(pend < lex_pend) rb_str_cat(str, "\n", 1);
      lex_goto_eol(parser_state);
      if(nextc() == -1) {
        goto error;
      }
    } while(!(end = whole_match_p(eos, len, indent)));
  } else {
    newtok();
    if(c == '#') {
      int t = parser_peek_variable_name(parser_state);
      if(t) return t;
      tokadd('#');
      c = nextc();
    }

    /* Loop while we haven't found a the heredoc ident. */
    do {
      pushback(c);
      /* Scan up until a \n and fill in the token buffer. */
      if((c = tokadd_string(func, '\n', 0, NULL, &enc)) == -1) {
        if(eofp) goto error;
        goto restore;
      }

      /* We finished scanning, but didn't find a \n, so we setup the node
         and have the lexer file in more. */
      if(c != '\n') {
        set_yylval_str(STR_NEW3(tok(), toklen(), enc, func));
        return tSTRING_CONTENT;
      }

      /* I think this consumes the \n */
      tokadd(nextc());
      if((c = nextc()) == -1) goto error;
    } while(!whole_match_p(eos, len, indent));
    str = REF(STR_NEW3(tok(), toklen(), enc, func));
  }
  heredoc_restore(lex_strterm);
  lex_strterm = NEW_STRTERM(-1, 0, 0);
  set_yylval_str(str);
  return tSTRING_CONTENT;
}

#include "lex.c.blt"

static int parser_arg_ambiguous(rb_parser_state* parser_state, char c) {
  rb_warningS(
    "ambiguous first argument; put parentheses or a space even after `%c' operator", c);

  return 1;
}

static ID parser_formal_argument(rb_parser_state* parser_state, ID lhs) {
  if(!is_local_id(lhs)) {
    yy_error("formal argument must be local variable");
  }
  shadowing_lvar(lhs);
  return lhs;
}

static bool parser_lvar_defined(rb_parser_state* parser_state, ID id) {
  return (in_block() && bv_defined(id)) || local_id(id);
}

static long parser_encode_length(rb_parser_state* parser_state, const char *name, long len) {
  long nlen;

  if(len > 5 && name[nlen = len - 5] == '-') {
    if(strncasecmp(name + nlen + 1, "unix", 4) == 0)
      return nlen;
  }
  if(len > 4 && name[nlen = len - 4] == '-') {
    if(strncasecmp(name + nlen + 1, "dos", 3) == 0)
      return nlen;
    if(strncasecmp(name + nlen + 1, "mac", 3) == 0 &&
        !(len == 8 && strncasecmp(name, "utf8-mac", len) == 0))
      /* exclude UTF8-MAC because the encoding named "UTF8" doesn't exist in Ruby */
      return nlen;
  }
  return len;
}

static void
parser_set_encode(rb_parser_state* parser_state, const char *name)
{
  int idx = parser_enc_find_index(name);
  rb_encoding *enc;

  if(idx < 0) {
    // TODO: handle this in a way that doesn't leak parser state
    // rb_raise(rb_eArgError, "unknown encoding name: %s", name);
    return;
  }

  enc = parser_enc_from_index(idx);
  if(!parser_enc_asciicompat(enc)) {
    // TODO: handle this in a way that doesn't leak parser state
    // rb_raise(rb_eArgError, "%s is not ASCII compatible", parser_enc_name(enc));
    return;
  }

  parser_state->enc = enc;
}

static void
parser_set_compile_option_flag(rb_parser_state* parser_state,
                               const char *name, const char *val)
{
  // TODO: 2.3
}

static void
parser_set_token_info(rb_parser_state* parser_state,
                      const char *name, const char *val)
{
  // TODO: 2.3
}

static int
comment_at_top(rb_parser_state* parser_state)
{
  const char *p = lex_pbeg, *pend = lex_p - 1;
  if(line_count != (has_shebang ? 2 : 1)) return FALSE;
  while(p < pend) {
    if(!ISSPACE(*p)) return FALSE;
    p++;
  }
  return TRUE;
}

typedef long (*rb_magic_comment_length_t)(rb_parser_state* parser_state, const char *name, long len);
typedef void (*rb_magic_comment_setter_t)(rb_parser_state* parser_state, const char *name, const char *val);

static void
magic_comment_encoding(rb_parser_state* parser_state, const char *name, const char *val)
{
  if(!comment_at_top(parser_state)) {
    return;
  }
  parser_set_encode(parser_state, val);
}

struct magic_comment {
    const char *name;
    rb_magic_comment_setter_t func;
    rb_magic_comment_length_t length;
};

static const struct magic_comment magic_comments[4] = {
  {"coding", magic_comment_encoding, parser_encode_length},
  {"encoding", magic_comment_encoding, parser_encode_length},
  {"frozen_string_literal", parser_set_compile_option_flag},
  {"warn_indent", parser_set_token_info},
};

static const char * magic_comment_marker(const char *str, long len) {
  long i = 2;

  while(i < len) {
    switch(str[i]) {
    case '-':
      if(str[i-1] == '*' && str[i-2] == '-') {
        return str + i + 1;
      }
      i += 2;
      break;
    case '*':
      if(i + 1 >= len) return 0;
      if(str[i+1] != '-') {
        i += 4;
      } else if(str[i-1] != '-') {
        i += 2;
      } else {
        return str + i + 2;
      }
      break;
    default:
      i += 3;
      break;
    }
  }
  return 0;
}

static int parser_magic_comment(rb_parser_state* parser_state, const char *str, long len) {
  int indicator = 0;
  VALUE name = 0, val = 0;
  const char *beg, *end, *vbeg, *vend;

#define str_copy(_s, _p, _n) ((_s) \
    ? (void)(rb_str_resize((_s), (_n)), \
    MEMCPY(RSTRING_PTR(_s), (_p), char, (_n)), (_s)) \
    : (void)((_s) = REF(STR_NEW((_p), (_n)))))

  if(len <= 7) return FALSE;

  if(!!(beg = magic_comment_marker(str, len))) {
    if(!(end = magic_comment_marker(beg, str + len - beg))) {
      return FALSE;
    }
    indicator = TRUE;
    str = beg;
    len = end - beg - 3;
  }

  /* %r"([^\\s\'\":;]+)\\s*:\\s*(\"(?:\\\\.|[^\"])*\"|[^\"\\s;]+)[\\s;]*" */
  while(len > 0) {
    const struct magic_comment *p = magic_comments;
    char *s;
    int i;
    long n = 0;

    for(; len > 0 && *str; str++, --len) {
      switch(*str) {
      case '\'': case '"': case ':': case ';':
        continue;
      }
      if(!ISSPACE(*str)) break;
    }
    for(beg = str; len > 0; str++, --len) {
      switch(*str) {
      case '\'': case '"': case ':': case ';':
        break;
      default:
        if(ISSPACE(*str)) break;
        continue;
      }
      break;
    }
    for(end = str; len > 0 && ISSPACE(*str); str++, --len) {
      // nothing
    }
    if(!len) break;
    if(*str != ':') {
      if(!indicator) return FALSE;
      continue;
    }

    do str++; while(--len > 0 && ISSPACE(*str));
    if(!len) break;
    if(*str == '"') {
      for(vbeg = ++str; --len > 0 && *str != '"'; str++) {
        if(*str == '\\') {
          --len;
          ++str;
        }
      }
      vend = str;
      if(len) {
        --len;
        ++str;
      }
    } else {
      for(vbeg = str;
          len > 0 && *str != '"' && *str != ';' && !ISSPACE(*str);
          --len, str++) {
        // nothing
      }
      vend = str;
    }
    if(indicator) {
      while(len > 0 && (*str == ';' || ISSPACE(*str))) --len, str++;
    } else {
      while(len > 0 && (ISSPACE(*str))) --len, str++;
      if(len) return FALSE;
    }

    n = end - beg;
    str_copy(name, beg, n);
    s = RSTRING_PTR(name);
    for(i = 0; i < n; ++i) {
      if(s[i] == '-') s[i] = '_';
    }
    do {
      if(strncasecmp(p->name, s, n) == 0 && !p->name[n]) {
        n = vend - vbeg;
        if(p->length) {
          n = (*p->length)(parser_state, vbeg, n);
        }
        str_copy(val, vbeg, n);
        (*p->func)(parser_state, s, RSTRING_PTR(val));
        break;
      }
    } while(++p < magic_comments + numberof(magic_comments));
  }

  return TRUE;
}

static void
set_file_encoding(rb_parser_state* parser_state, const char *str, const char *send)
{
  int sep = 0;
  const char *beg = str;
  VALUE s;

  for(;;) {
    if(send - str <= 6) return;
    switch(str[6]) {
    case 'C': case 'c': str += 6; continue;
    case 'O': case 'o': str += 5; continue;
    case 'D': case 'd': str += 4; continue;
    case 'I': case 'i': str += 3; continue;
    case 'N': case 'n': str += 2; continue;
    case 'G': case 'g': str += 1; continue;
    case '=': case ':':
      sep = 1;
      str += 6;
      break;
    default:
      str += 6;
      if(ISSPACE(*str)) break;
      continue;
    }
    if(strncasecmp(str-6, "coding", 6) == 0) break;
  }

  for(;;) {
    do {
      if(++str >= send) return;
    } while(ISSPACE(*str));
    if(sep) break;
    if(*str != '=' && *str != ':') return;
    sep = 1;
    str++;
  }

  beg = str;
  while((*str == '-' || *str == '_' || ISALNUM(*str)) && ++str < send) {
    // nothing
  }
  s = REF(rb_str_new(beg, parser_encode_length(parser_state, beg, str - beg)));
  parser_set_encode(parser_state, RSTRING_PTR(s));
  rb_str_resize(s, 0);
}

static void
parser_prepare(rb_parser_state* parser_state)
{
  int c = nextc();
  switch(c) {
  case '#':
    if(peek('!')) has_shebang = 1;
    break;
  case 0xef:    /* UTF-8 BOM marker */
    if(lex_pend - lex_p >= 2 &&
        (unsigned char)lex_p[0] == 0xbb &&
        (unsigned char)lex_p[1] == 0xbf) {
      parser_state->enc = parser_utf8_encoding();
      lex_p += 2;
      lex_pbeg = lex_p;
      return;
    }
    break;
  case EOF:
    return;
  }
  pushback(c);
  parser_state->enc = parser_enc_get(lex_lastline);
}

#define IS_ARG()              lex_state_p(EXPR_ARG_ANY)
#define IS_END()              lex_state_p(EXPR_END_ANY)
#define IS_BEG()              (lex_state_p(EXPR_BEG_ANY) \
                                || lex_state_all_p(EXPR_ARG | EXPR_LABELED))
#define IS_SPCARG(c)          (IS_ARG() && space_seen && !ISSPACE(c))
#define IS_LABEL_POSSIBLE()   ((lex_state_p(EXPR_LABEL | EXPR_ENDFN) && !cmd_state) || \
                                IS_ARG())
#define IS_LABEL_SUFFIX(n)    (peek_n(':',(n)) && !peek_n(':', (n)+1))
#define IS_AFTER_OPERATOR()   lex_state_p(EXPR_FNAME | EXPR_DOT)

#define ambiguous_operator(op, syn) ( \
    rb_warning0("`" op "' after local variable is interpreted as binary operator"), \
    rb_warning0("even though it seems like " syn ""))
#define warn_balanced(op, syn) ((void) \
    (!lex_state_of_p(last_state, \
      EXPR_CLASS|EXPR_DOT|EXPR_FNAME|EXPR_ENDFN|EXPR_ENDARG) && \
    space_seen && !ISSPACE(c) && \
    (ambiguous_operator(op, syn), 0)))

static VALUE
parse_rational(rb_parser_state* parser_state, char *str, int len, int seen_point)
{
  VALUE v;
  char *point = &str[seen_point];
  size_t fraclen = len-seen_point-1;
  memmove(point, point+1, fraclen+1);
  v = rb_cstr_to_inum(str, 10, FALSE);
  return rb_rational_new(v,
        rb_funcall(INT2FIX(10), rb_intern("**"), 1, INT2NUM(fraclen)));
}

static int parse_numeric(rb_parser_state* parser_state, int c) {
  int is_float, seen_point, seen_e, nondigit;
  int suffix;

  is_float = seen_point = seen_e = nondigit = 0;
  SET_LEX_STATE(EXPR_END);
  newtok();
  if(c == '-' || c == '+') {
    tokadd(c);
    c = nextc();
  }
  if(c == '0') {
#define no_digits() do {yy_error("numeric literal without digits"); return 0;} while(0)
    int start = toklen();
    c = nextc();
    if(c == 'x' || c == 'X') {
      /* hexadecimal */
      c = nextc();
      if(c != -1 && ISXDIGIT(c)) {
        do {
          if(c == '_') {
            if(nondigit) break;
            nondigit = c;
            continue;
          }
          if(!ISXDIGIT(c)) break;
          nondigit = 0;
          tokadd(c);
        } while((c = nextc()) != -1);
      }
      pushback(c);
      tokfix();
      if(toklen() == start) {
        no_digits();
      } else if(nondigit) {
        goto trailing_uc;
      }
      suffix = number_literal_suffix(NUM_SUFFIX_ALL);
      return set_integer_literal(rb_cstr_to_inum(tok(), 16, FALSE), suffix);
    }
    if(c == 'b' || c == 'B') {
      /* binary */
      c = nextc();
      if(c == '0' || c == '1') {
        do {
          if(c == '_') {
            if(nondigit) break;
            nondigit = c;
            continue;
          }
          if(c != '0' && c != '1') break;
          nondigit = 0;
          tokadd(c);
        } while((c = nextc()) != -1);
      }
      pushback(c);
      tokfix();
      if(toklen() == start) {
        no_digits();
      } else if(nondigit) {
        goto trailing_uc;
      }
      suffix = number_literal_suffix(NUM_SUFFIX_ALL);
      return set_integer_literal(rb_cstr_to_inum(tok(), 2, FALSE), suffix);
    }
    if(c == 'd' || c == 'D') {
      /* decimal */
      c = nextc();
      if(c != -1 && ISDIGIT(c)) {
        do {
          if(c == '_') {
            if(nondigit) break;
            nondigit = c;
            continue;
          }
          if(!ISDIGIT(c)) break;
          nondigit = 0;
          tokadd(c);
        } while((c = nextc()) != -1);
      }
      pushback(c);
      tokfix();
      if(toklen() == start) {
        no_digits();
      } else if(nondigit) {
        goto trailing_uc;
      }
      suffix = number_literal_suffix(NUM_SUFFIX_ALL);
      return set_integer_literal(rb_cstr_to_inum(tok(), 10, FALSE), suffix);
    }
    if(c == '_') {
      /* 0_0 */
      goto octal_number;
    }
    if(c == 'o' || c == 'O') {
      /* prefixed octal */
      c = nextc();
      if(c == -1 || c == '_' || !ISDIGIT(c)) {
        no_digits();
      }
    }
    if(c >= '0' && c <= '7') {
      /* octal */
    octal_number:
      do {
        if(c == '_') {
          if(nondigit) break;
          nondigit = c;
          continue;
        }
        if(c < '0' || c > '9') break;
        if(c > '7') goto invalid_octal;
        nondigit = 0;
        tokadd(c);
      } while((c = nextc()) != -1);
      if(toklen() > start) {
        pushback(c);
        tokfix();
        if(nondigit) goto trailing_uc;
        suffix = number_literal_suffix(NUM_SUFFIX_ALL);
        return set_integer_literal(rb_cstr_to_inum(tok(), 8, FALSE), suffix);
      }
      if(nondigit) {
        pushback(c);
        goto trailing_uc;
      }
    }
    if(c > '7' && c <= '9') {
    invalid_octal:
      yy_error("Invalid octal digit");
    } else if(c == '.' || c == 'e' || c == 'E') {
      tokadd('0');
    } else {
      pushback(c);
      suffix = number_literal_suffix(NUM_SUFFIX_ALL);
      return set_integer_literal(INT2FIX(0), suffix);
    }
  }

  for(;;) {
    switch(c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      nondigit = 0;
      tokadd(c);
      break;

    case '.':
      if(nondigit) goto trailing_uc;
      if(seen_point || seen_e) {
        goto decode_num;
      } else {
        int c0 = nextc();
        if(c0 == -1 || !ISDIGIT(c0)) {
          pushback(c0);
          goto decode_num;
        }
        c = c0;
      }
      seen_point = toklen();
      tokadd('.');
      tokadd(c);
      is_float++;
      nondigit = 0;
      break;

    case 'e':
    case 'E':
      if(nondigit) {
        pushback(c);
        c = nondigit;
        goto decode_num;
      }
      if(seen_e) {
        goto decode_num;
      }
      nondigit = c;
      c = nextc();
      if(c != '-' && c != '+' && !ISDIGIT(c)) {
        pushback(c);
        nondigit = 0;
        goto decode_num;
      }
      tokadd(nondigit);
      seen_e++;
      is_float++;
      tokadd(c);
      nondigit = (c == '-' || c == '+') ? c : 0;
      break;

    case '_': /* `_' in number just ignored */
      if(nondigit) goto decode_num;
      nondigit = c;
      break;

    default:
      goto decode_num;
    }
    c = nextc();
  }

decode_num:
  pushback(c);
  if(nondigit) {
    char tmp[30];
    trailing_uc:
    snprintf(tmp, sizeof(tmp), "trailing `%c' in number", nondigit);
    yy_error(tmp);
  }
  tokfix();
  if(is_float) {
    int type = tFLOAT;
    VALUE v;

    suffix = number_literal_suffix(seen_e ? NUM_SUFFIX_I : NUM_SUFFIX_ALL);
    if(suffix & NUM_SUFFIX_R) {
      type = tRATIONAL;
      v = parse_rational(parser_state, tok(), toklen(), seen_point);
    } else {
      double d = strtod(tok(), 0);
      if(errno == ERANGE) {
        rb_warningS("Float %s out of range", tok());
        errno = 0;
      }
      v = rb_float_new(d);
    }
    return set_number_literal(v, type, suffix);
  }

  suffix = number_literal_suffix(NUM_SUFFIX_ALL);
  return set_integer_literal(rb_cstr_to_inum(tok(), 10, FALSE), suffix);
}

static int parse_qmark(rb_parser_state* parser_state) {
  rb_encoding *enc;
  int c;

  if(IS_END()) {
    SET_LEX_STATE(EXPR_VALUE);
    return '?';
  }
  c = nextc();
  if(c == -1) {
    rb_compile_error(parser_state, "incomplete character syntax");
    return 0;
  }
  if(parser_enc_isspace(c, parser_state->enc)) {
    if(!IS_ARG()) {
      int c2 = 0;
      switch(c) {
        case ' ':
          c2 = 's';
          break;
        case '\n':
          c2 = 'n';
          break;
        case '\t':
          c2 = 't';
          break;
        case '\v':
          c2 = 'v';
          break;
        case '\r':
          c2 = 'r';
          break;
        case '\f':
          c2 = 'f';
          break;
      }
      if(c2) {
        rb_warn("invalid character syntax; use ?\\%c", c2);
      }
    }
  ternary:
    pushback(c);
    SET_LEX_STATE(EXPR_VALUE);
    return '?';
  }
  newtok();
  enc = parser_state->enc;
  if(!parser_isascii()) {
    if(tokadd_mbchar(c) == -1) return 0;
  } else if((parser_enc_isalnum(c, parser_state->enc) || c == '_') &&
             lex_p < lex_pend && is_identchar(lex_p, lex_pend, parser_state->enc)) {
    goto ternary;
  } else if(c == '\\') {
    if(peek('u')) {
      nextc();
      c = parser_tokadd_utf8(parser_state, &enc, 0, 0, 0);
      if(0x80 <= c) {
        tokaddmbc(c, enc);
      } else {
        tokadd(c);
      }
    } else if(!lex_eol_p() && !(c = *lex_p, ISASCII(c))) {
      nextc();
      if(tokadd_mbchar(c) == -1) return 0;
    } else {
      c = read_escape(0, &enc);
      tokadd(c);
    }
  } else {
  tokadd(c);
  }
  tokfix();
  set_yylval_str(STR_NEW3(tok(), toklen(), enc, 0));
  SET_LEX_STATE(EXPR_END);
  return tCHAR;
}

static int
parse_percent(rb_parser_state* parser_state, const int space_seen,
              const enum lex_state_e last_state)
{
  int c;

  if(IS_BEG()) {
    int term;
    int paren;

    c = nextc();
      quotation:
    if(c == -1 || !ISALNUM(c)) {
      term = c;
      c = 'Q';
    } else {
      term = nextc();
      if(parser_enc_isalnum((int)term, parser_state->enc) || !parser_isascii()) {
        yy_error("unknown type of %string");
        return 0;
      }
    }
    if(c == -1 || term == -1) {
      rb_compile_error(parser_state, "unterminated quoted string meets end of file");
      return 0;
    }
    paren = term;
    if(term == '(') term = ')';
    else if(term == '[') term = ']';
    else if(term == '{') term = '}';
    else if(term == '<') term = '>';
    else paren = 0;

    switch(c) {
      case 'Q':
        lex_strterm = NEW_STRTERM(str_dquote, term, paren);
        return tSTRING_BEG;

      case 'q':
        lex_strterm = NEW_STRTERM(str_squote, term, paren);
        return tSTRING_BEG;

      case 'W':
        lex_strterm = NEW_STRTERM(str_dword, term, paren);
        do {c = nextc();} while(ISSPACE(c));
        pushback(c);
        return tWORDS_BEG;

      case 'w':
        lex_strterm = NEW_STRTERM(str_sword, term, paren);
        do {c = nextc();} while(ISSPACE(c));
        pushback(c);
        return tQWORDS_BEG;

      case 'I':
        lex_strterm = NEW_STRTERM(str_dword, term, paren);
        do {c = nextc();} while(ISSPACE(c));
        pushback(c);
        return tSYMBOLS_BEG;

      case 'i':
        lex_strterm = NEW_STRTERM(str_sword, term, paren);
        do {c = nextc();} while(ISSPACE(c));
        pushback(c);
        return tQSYMBOLS_BEG;

      case 'x':
        lex_strterm = NEW_STRTERM(str_xquote, term, paren);
        return tXSTRING_BEG;

      case 'r':
        lex_strterm = NEW_STRTERM(str_regexp, term, paren);
        return tREGEXP_BEG;

      case 's':
        lex_strterm = NEW_STRTERM(str_ssym, term, paren);
        SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);
        return tSYMBEG;

      default:
        yy_error("unknown type of %string");
        return 0;
    }
  }
  if((c = nextc()) == '=') {
    set_yylval_id('%');
    SET_LEX_STATE(EXPR_BEG);
    return tOP_ASGN;
  }
  if(IS_SPCARG(c) || (lex_state_p(EXPR_FITEM) && c == 's')) {
    goto quotation;
  }
  SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
  pushback(c);
  warn_balanced("%%", "string literal");
  return '%';
}

static int tokadd_ident(rb_parser_state* parser_state, int c) {
  do {
    if(tokadd_mbchar(c) == -1) return -1;
    c = nextc();
  } while(parser_is_identchar());
  pushback(c);
  return 0;
}

static ID tokenize_ident(rb_parser_state* parser_state, const enum lex_state_e last_state) {
  ID ident = TOK_INTERN();

  set_yylval_name(ident);

  return ident;
}

const signed char ruby_digit36_to_number_table[] = {
  /*     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f */
  /*0*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*1*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*2*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*3*/  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,
  /*4*/ -1,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
  /*5*/ 25,26,27,28,29,30,31,32,33,34,35,-1,-1,-1,-1,-1,
  /*6*/ -1,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
  /*7*/ 25,26,27,28,29,30,31,32,33,34,35,-1,-1,-1,-1,-1,
  /*8*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*9*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*a*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*b*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*c*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*d*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*e*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  /*f*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

unsigned long
ruby_scan_digits(const char *str, ssize_t len, int base, size_t *retlen, int *overflow)
{
  const char *start = str;
  unsigned long ret = 0, x;
  unsigned long mul_overflow = (~(unsigned long)0) / base;

  *overflow = 0;

  if(!len) {
    *retlen = 0;
    return 0;
  }

  do {
    int d = ruby_digit36_to_number_table[(unsigned char)*str++];
    if(d == -1 || base <= d) {
      --str;
      break;
    }
    if(mul_overflow < ret) {
      *overflow = 1;
    }
    ret *= base;
    x = ret;
    ret += d;
    if(ret < x) {
      *overflow = 1;
    }
  } while(len < 0 || --len);

  *retlen = str - start;
  return ret;
}

static int parse_numvar(rb_parser_state* parser_state) {
  size_t len;
  int overflow;
  unsigned long n = ruby_scan_digits(tok()+1, toklen()-1, 10, &len, &overflow);
  const unsigned long nth_ref_max =
      ((FIXNUM_MAX < INT_MAX) ? FIXNUM_MAX : INT_MAX) >> 1;
  /* NTH_REF is left-shifted to be ORed with back-ref flag and
   * turned into a Fixnum, in compile.c */

  if(overflow || n > nth_ref_max) {
    /* compile_error()? */
    rb_warnS("`%s' is too big for a number variable, always nil", tok());
    return 0;           /* $0 is $PROGRAM_NAME, not NTH_REF */
  } else {
    return (int)n;
  }
}

static int parse_gvar(rb_parser_state* parser_state, const enum lex_state_e last_state) {
  int c;

  SET_LEX_STATE(EXPR_END);
  newtok();
  c = nextc();
  switch(c) {
    case '_':           /* $_: last read line string */
      c = nextc();
      if(parser_is_identchar()) {
        tokadd('$');
        tokadd('_');
        break;
      }
      pushback(c);
      c = '_';
      /* fall through */
    case '~':           /* $~: match-data */
    case '*':           /* $*: argv */
    case '$':           /* $$: pid */
    case '?':           /* $?: last status */
    case '!':           /* $!: error string */
    case '@':           /* $@: error position */
    case '/':           /* $/: input record separator */
    case '\\':          /* $\: output record separator */
    case ';':           /* $;: field separator */
    case ',':           /* $,: output field separator */
    case '.':           /* $.: last read line number */
    case '=':           /* $=: ignorecase */
    case ':':           /* $:: load path */
    case '<':           /* $<: reading filename */
    case '>':           /* $>: default output handle */
    case '\"':          /* $": already loaded files */
      tokadd('$');
      tokadd(c);
      goto gvar;

    case '-':
      tokadd('$');
      tokadd(c);
      c = nextc();
      if(parser_is_identchar()) {
        if(tokadd_mbchar(c) == -1) return 0;
      } else {
        pushback(c);
        pushback('-');
        return '$';
      }
    gvar:
      tokfix();
      set_yylval_name(TOK_INTERN());
      return tGVAR;

    case '&':           /* $&: last match */
    case '`':           /* $`: string before last match */
    case '\'':          /* $': string after last match */
    case '+':           /* $+: string matches last paren. */
      if(lex_state_of_p(last_state, EXPR_FNAME)) {
        tokadd('$');
        tokadd(c);
        goto gvar;
      }
      set_yylval_node(NEW_BACK_REF(c));
      return tBACK_REF;

    case '1': case '2': case '3':
    case '4': case '5': case '6':
    case '7': case '8': case '9':
      tokadd('$');
      do {
        tokadd(c);
        c = nextc();
      } while(c != -1 && ISDIGIT(c));
      pushback(c);
      if(lex_state_of_p(last_state, EXPR_FNAME)) goto gvar;
      tokfix();
      set_yylval_node(NEW_NTH_REF(parse_numvar(parser_state)));
      return tNTH_REF;

    default:
      if(!parser_is_identchar()) {
        if(c == -1 || ISSPACE(c)) {
          rb_compile_error(parser_state,
            "`$' without identifiers is not allowed as a global variable name");
        } else {
          pushback(c);
          rb_compile_error(parser_state, "`$%c' is not allowed as a global variable name", c);
        }
        return 0;
      }
    case '0':
      tokadd('$');
  }

  if(tokadd_ident(parser_state, c)) return 0;
  SET_LEX_STATE(EXPR_END);
  tokenize_ident(parser_state, last_state);
  return tGVAR;
}

static int
parse_atmark(rb_parser_state* parser_state, const enum lex_state_e last_state)
{
    int result = tIVAR;
    int c = nextc();

    newtok();
    tokadd('@');
    if(c == '@') {
        result = tCVAR;
        tokadd('@');
        c = nextc();
    }
    if(c == -1 || ISSPACE(c)) {
      if(result == tIVAR) {
        rb_compile_error(parser_state,
          "`@' without identifiers is not allowed as an instance variable name");
      } else {
        rb_compile_error(parser_state,
          "`@@' without identifiers is not allowed as a class variable name");
      }
      return 0;
    } else if(ISDIGIT(c) || !parser_is_identchar()) {
        pushback(c);
        if(result == tIVAR) {
          rb_compile_error(parser_state,
            "`@%c' is not allowed as an instance variable name", c);
        } else {
          rb_compile_error(parser_state,
            "`@@%c' is not allowed as a class variable name", c);
        }
        return 0;
    }

    if(tokadd_ident(parser_state, c)) return 0;
    SET_LEX_STATE(EXPR_END);
    tokenize_ident(parser_state, last_state);
    return result;
}

static int parse_ident(rb_parser_state* parser_state, int c, int cmd_state) {
  int result = 0;
  int mb = ENC_CODERANGE_7BIT;
  const enum lex_state_e last_state = lex_state;
  ID ident;

  do {
    if(!ISASCII(c)) mb = ENC_CODERANGE_UNKNOWN;
    if(tokadd_mbchar(c) == -1) return 0;
    c = nextc();
  } while(parser_is_identchar());
  if((c == '!' || c == '?') && !peek('=')) {
    tokadd(c);
  } else {
    pushback(c);
  }
  tokfix();

  if(toklast() == '!' || toklast() == '?') {
    result = tFID;
  } else {
    if(lex_state_p(EXPR_FNAME)) {
      int c = nextc();
      if(c == '=' && !peek('~') && !peek('>') &&
        (!peek('=') || (peek_n('>', 1)))) {
        result = tIDENTIFIER;
        tokadd(c);
        tokfix();
      } else {
        pushback(c);
      }
    }
    if(result == 0 && ISUPPER(tok()[0])) {
      result = tCONSTANT;
    } else {
      result = tIDENTIFIER;
    }
  }

  if(IS_LABEL_POSSIBLE()) {
    if(IS_LABEL_SUFFIX(0)) {
      SET_LEX_STATE(EXPR_ARG | EXPR_LABELED);
      nextc();
      set_yylval_name(TOK_INTERN());
      return tLABEL;
    }
  }
  if(mb == ENC_CODERANGE_7BIT && !lex_state_p(EXPR_DOT)) {
    const struct kwtable *kw;

    /* See if it is a reserved word.  */
    kw = rb_reserved_word(tok(), toklen());
    if(kw) {
      enum lex_state_e state = lex_state;
      SET_LEX_STATE(kw->state);
      if(lex_state_of_p(state, EXPR_FNAME)) {
        set_yylval_name(parser_intern2(tok(), toklen()));
        return kw->id[0];
      }
      if(lex_state_p(EXPR_BEG)) {
        command_start = TRUE;
      }
      if(kw->id[0] == keyword_do) {
        if(lpar_beg && lpar_beg == paren_nest) {
          lpar_beg = 0;
          --paren_nest;
          return keyword_do_LAMBDA;
        }
        if(COND_P()) return keyword_do_cond;
        if(CMDARG_P() && !lex_state_of_p(state, EXPR_CMDARG)) {
          return keyword_do_block;
        }
        if(lex_state_of_p(state, (EXPR_BEG | EXPR_ENDARG))) {
          return keyword_do_block;
        }
        return keyword_do;
      }
      if(lex_state_of_p(state, (EXPR_BEG | EXPR_LABELED))) {
        return kw->id[0];
      } else {
        if(kw->id[0] != kw->id[1]) {
          SET_LEX_STATE(EXPR_BEG | EXPR_LABEL);
        }
        return kw->id[1];
      }
    }
  }

  if(lex_state_p(EXPR_BEG_ANY | EXPR_ARG_ANY | EXPR_DOT)) {
    if(cmd_state) {
      SET_LEX_STATE(EXPR_CMDARG);
    } else {
      SET_LEX_STATE(EXPR_ARG);
    }
  } else if(lex_state == EXPR_FNAME) {
    SET_LEX_STATE(EXPR_ENDFN);
  } else {
    SET_LEX_STATE(EXPR_END);
  }

  ident = tokenize_ident(parser_state, last_state);
  if(!lex_state_of_p(last_state, EXPR_DOT | EXPR_FNAME) &&
      (result == tIDENTIFIER) && /* not EXPR_FNAME, not attrasgn */
      lvar_defined(ident)) {
    SET_LEX_STATE(EXPR_END | EXPR_LABEL);
  }

  return result;
}

static int parser_yylex(rb_parser_state* parser_state) {
  int c;
  int space_seen = 0;
  int cmd_state;
  int label;
  enum lex_state_e last_state;
  int fallthru = FALSE;
  int tok_seen = token_seen;

  if(lex_strterm) {
    int token;
    if(nd_type(lex_strterm) == NODE_HEREDOC) {
      token = here_document(lex_strterm);
      if(token == tSTRING_END) {
        lex_strterm = 0;
        SET_LEX_STATE(EXPR_END);
      }
    } else {
      token = parse_string(lex_strterm);
      if(token == tSTRING_END && (lex_strterm->nd_func & STR_FUNC_LABEL)) {
        if(((lex_state_p(EXPR_BEG | EXPR_ENDFN) && !COND_P()) || IS_ARG()) && IS_LABEL_SUFFIX(0)) {
          nextc();
          token = tLABEL_END;
        }
      }
      if(token == tSTRING_END || token == tREGEXP_END || token == tLABEL_END) {
        lex_strterm = 0;
        SET_LEX_STATE(token == tLABEL_END ? EXPR_BEG|EXPR_LABEL : EXPR_END);
      }
    }
    return token;
  }

  cmd_state = command_start;
  command_start = FALSE;
  token_seen = TRUE;
retry:
  last_state = lex_state;
  switch(c = nextc()) {
  case '\0':                /* NUL */
  case '\004':              /* ^D */
  case '\032':              /* ^Z */
  case -1:                  /* end of script. */
    return 0;

    /* white spaces */
  case ' ': case '\t': case '\f': case '\r':
  case '\13': /* '\v' */
    space_seen = 1;
    goto retry;

  case '#':         /* it's a comment */
    token_seen = tok_seen;
    /* no magic_comment in shebang line */
    if(!parser_magic_comment(parser_state, lex_p, lex_pend - lex_p)) {
      if(comment_at_top(parser_state)) {
        set_file_encoding(parser_state, lex_p, lex_pend);
      }
    }

    lex_p = lex_pend;
    fallthru = TRUE;
    /* fall through */
  case '\n':
    token_seen = tok_seen;
    c = (lex_state_p(EXPR_BEG | EXPR_CLASS | EXPR_FNAME | EXPR_DOT)
        && !lex_state_p(EXPR_LABELED));
    if(c || lex_state_all_p(EXPR_ARG | EXPR_LABELED)) {
      fallthru = FALSE;
      if(!c && in_kwarg) {
        goto normal_newline;
      }
      goto retry;
    }

    while((c = nextc())) {
      switch(c) {
      case ' ': case '\t': case '\f': case '\r':
      case '\13': /* '\v' */
        space_seen = 1;
        break;
      case '&':
      case '.': {
        if(peek('.') == (c == '&')) {
          pushback(c);
          goto retry;
        }
      }
      default:
        --sourceline;
        lex_nextline = lex_lastline;
      case -1:         /* EOF no decrement*/
        lex_goto_eol(parser_state);
        goto normal_newline;
      }
    }

  normal_newline:
    command_start = TRUE;
    SET_LEX_STATE(EXPR_BEG);
    return '\n';

  case '*':
    if((c = nextc()) == '*') {
      if((c = nextc()) == '=') {
        set_yylval_id(tPOW);
        SET_LEX_STATE(EXPR_BEG);
        return tOP_ASGN;
      }
      pushback(c);
      if(IS_SPCARG(c)) {
        rb_warning0("`**' interpreted as argument prefix");
        c = tDSTAR;
      } else if(IS_BEG()) {
        c = tDSTAR;
      } else {
        warn_balanced("**", "argument prefix");
        c = tPOW;
      }
    } else {
      if(c == '=') {
        set_yylval_id('*');
        SET_LEX_STATE(EXPR_BEG);
        return tOP_ASGN;
      }
      pushback(c);
      if(IS_SPCARG(c)){
        rb_warning("`*' interpreted as argument prefix");
        c = tSTAR;
      } else if(IS_BEG()) {
        c = tSTAR;
      } else {
        warn_balanced("*", "argument prefix");
        c = '*';
      }
    }
    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
    return c;

  case '!':
    c = nextc();
    if(IS_AFTER_OPERATOR()) {
      SET_LEX_STATE(EXPR_ARG);
      if(c == '@') {
        return '!';
      }
    } else {
      SET_LEX_STATE(EXPR_BEG);
    }
    if(c == '=') {
      return tNEQ;
    }
    if(c == '~') {
      return tNMATCH;
    }
    pushback(c);
    return '!';

  case '=':
    if(was_bol()) {
      /* skip embedded rd document */
      if(strncmp(lex_p, "begin", 5) == 0 && ISSPACE(lex_p[5])) {
        lex_goto_eol(parser_state);
        for(;;) {
          lex_goto_eol(parser_state);
          c = nextc();
          if(c == -1) {
            rb_compile_error(parser_state, "embedded document meets end of file");
            return 0;
          }
          if(c != '=') continue;
          if(c == '=' && strncmp(lex_p, "end", 3) == 0 &&
              (lex_p + 3 == lex_pend || ISSPACE(lex_p[3]))) {
            break;
          }
        }
        lex_goto_eol(parser_state);
        goto retry;
      }
    }

    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
    if((c = nextc()) == '=') {
      if((c = nextc()) == '=') {
        return tEQQ;
      }
      pushback(c);
      return tEQ;
    }
    if(c == '~') {
      return tMATCH;
    } else if(c == '>') {
      return tASSOC;
    }
    pushback(c);
    return '=';

  case '<':
    last_state = lex_state;
    c = nextc();
    if(c == '<' &&
      !lex_state_p(EXPR_DOT | EXPR_CLASS) &&
      !IS_END() &&
      (!IS_ARG() || lex_state_p(EXPR_LABELED) || space_seen)) {
      int token = heredoc_identifier();
      if(token) return token;
    }
    if(IS_AFTER_OPERATOR()) {
      SET_LEX_STATE(EXPR_ARG);
    } else {
      if(lex_state_p(EXPR_CLASS)) {
        command_start = TRUE;
      }
      SET_LEX_STATE(EXPR_BEG);
    }
    if(c == '=') {
      if((c = nextc()) == '>') {
        return tCMP;
      }
      pushback(c);
      return tLEQ;
    }
    if(c == '<') {
      if((c = nextc()) == '=') {
        set_yylval_id(tLSHFT);
        SET_LEX_STATE(EXPR_BEG);
        return tOP_ASGN;
      }
      pushback(c);
      warn_balanced("<<", "here document");
      return tLSHFT;
    }
    pushback(c);
    return '<';

  case '>':
    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
    if((c = nextc()) == '=') {
      return tGEQ;
    }
    if(c == '>') {
      if((c = nextc()) == '=') {
        set_yylval_id(tRSHFT);
        SET_LEX_STATE(EXPR_BEG);
        return tOP_ASGN;
      }
      pushback(c);
      return tRSHFT;
    }
    pushback(c);
    return '>';

  case '"':
    label = IS_LABEL_POSSIBLE() ? str_label : 0;
    lex_strterm = NEW_STRTERM(str_dquote | label, '"', 0);
    return tSTRING_BEG;

  case '`':
    if(lex_state_p(EXPR_FNAME)) {
      SET_LEX_STATE(EXPR_ENDFN);
      return c;
    }
    if(lex_state_p(EXPR_DOT)) {
      if(cmd_state) {
        SET_LEX_STATE(EXPR_CMDARG);
      } else {
        SET_LEX_STATE(EXPR_ARG);
      }
      return c;
    }
    lex_strterm = NEW_STRTERM(str_xquote, '`', 0);
    return tXSTRING_BEG;

  case '\'':
    label = IS_LABEL_POSSIBLE() ? str_label : 0;
    lex_strterm = NEW_STRTERM(str_squote | label, '\'', 0);
    return tSTRING_BEG;

  case '?':
    return parse_qmark(parser_state);

  case '&':
    if((c = nextc()) == '&') {
      SET_LEX_STATE(EXPR_BEG);
      if((c = nextc()) == '=') {
        set_yylval_id(tANDOP);
        SET_LEX_STATE(EXPR_BEG);
        return tOP_ASGN;
      }
      pushback(c);
      return tANDOP;
    } else if(c == '=') {
      set_yylval_id('&');
      SET_LEX_STATE(EXPR_BEG);
      return tOP_ASGN;
    } else if(c == '.') {
      SET_LEX_STATE(EXPR_DOT);
      return tANDDOT;
    }
    pushback(c);
    if(IS_SPCARG(c)){
      rb_warning("`&' interpreted as argument prefix");
      c = tAMPER;
    } else if(IS_BEG()) {
      c = tAMPER;
    } else {
      warn_balanced("&", "argument prefix");
      c = '&';
    }
    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
    return c;

  case '|':
    if((c = nextc()) == '|') {
      SET_LEX_STATE(EXPR_BEG);
      if((c = nextc()) == '=') {
        set_yylval_id(tOROP);
        SET_LEX_STATE(EXPR_BEG);
        return tOP_ASGN;
      }
      pushback(c);
      return tOROP;
    }
    if(c == '=') {
      set_yylval_id('|');
      SET_LEX_STATE(EXPR_BEG);
      return tOP_ASGN;
    }
    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG|EXPR_LABEL);
    pushback(c);
    return '|';

  case '+':
    c = nextc();
    if(IS_AFTER_OPERATOR()) {
      SET_LEX_STATE(EXPR_ARG);
      if(c == '@') {
        return tUPLUS;
      }
      pushback(c);
      return '+';
    }
    if(c == '=') {
      set_yylval_id('+');
      SET_LEX_STATE(EXPR_BEG);
      return tOP_ASGN;
    }
    if(IS_BEG() || (IS_SPCARG(c) && arg_ambiguous('+'))) {
      SET_LEX_STATE(EXPR_BEG);
      pushback(c);
      if(c != -1 && ISDIGIT(c)) {
        return parse_numeric(parser_state, '+');
      }
      return tUPLUS;
    }
    SET_LEX_STATE(EXPR_BEG);
    pushback(c);
    warn_balanced("+", "unary operator");
    return '+';

  case '-':
    c = nextc();
    if(IS_AFTER_OPERATOR()) {
      SET_LEX_STATE(EXPR_ARG);
      if(c == '@') {
        return tUMINUS;
      }
      pushback(c);
      return '-';
    }
    if(c == '=') {
      set_yylval_id('-');
      SET_LEX_STATE(EXPR_BEG);
      return tOP_ASGN;
    }
    if(c == '>') {
      SET_LEX_STATE(EXPR_ENDFN);
      return tLAMBDA;
    }
    if(IS_BEG() || (IS_SPCARG(c) && arg_ambiguous('-'))) {
      SET_LEX_STATE(EXPR_BEG);
      pushback(c);
      if(c != -1 && ISDIGIT(c)) {
        return tUMINUS_NUM;
      }
      return tUMINUS;
    }
    SET_LEX_STATE(EXPR_BEG);
    pushback(c);
    warn_balanced("-", "unary operator");
    return '-';

  case '.':
    SET_LEX_STATE(EXPR_BEG);
    if((c = nextc()) == '.') {
      if((c = nextc()) == '.') {
        return tDOT3;
      }
      pushback(c);
      return tDOT2;
    }
    pushback(c);
    if(c != -1 && ISDIGIT(c)) {
      yy_error("no .<digit> floating literal anymore; put 0 before dot");
    }
    SET_LEX_STATE(EXPR_DOT);
    return '.';

  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    return parse_numeric(parser_state, c);

  case ')':
  case ']':
    paren_nest--;
  case '}':
    COND_LEXPOP();
    CMDARG_LEXPOP();
    if(c == ')') {
      SET_LEX_STATE(EXPR_ENDFN);
    } else {
      SET_LEX_STATE(EXPR_ENDARG);
    }
    if(c == '}') {
      if(!brace_nest--) c = tSTRING_DEND;
    }
    return c;

  case ':':
    c = nextc();
    if(c == ':') {
      if(IS_BEG() || lex_state_p(EXPR_CLASS) || IS_SPCARG(-1)) {
        SET_LEX_STATE(EXPR_BEG);
        return tCOLON3;
      }
      SET_LEX_STATE(EXPR_DOT);
      return tCOLON2;
    }
    if(IS_END() || ISSPACE(c) || c == '#') {
      pushback(c);
      warn_balanced(":", "symbol literal");
      SET_LEX_STATE(EXPR_BEG);
      return ':';
    }
    switch(c) {
    case '\'':
      lex_strterm = NEW_STRTERM(str_ssym, c, 0);
      break;
    case '"':
      lex_strterm = NEW_STRTERM(str_dsym, c, 0);
      break;
    default:
      pushback(c);
      break;
    }
    SET_LEX_STATE(EXPR_FNAME);
    return tSYMBEG;

  case '/':
    if(IS_BEG()) {
      lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if((c = nextc()) == '=') {
      set_yylval_id('/');
      SET_LEX_STATE(EXPR_BEG);
      return tOP_ASGN;
    }
    pushback(c);
    if(IS_SPCARG(c)) {
      (void)arg_ambiguous('/');
      lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
    warn_balanced("/", "regexp literal");
    return '/';

  case '^':
    if((c = nextc()) == '=') {
      set_yylval_id('^');
      SET_LEX_STATE(EXPR_BEG);
      return tOP_ASGN;
    }
    SET_LEX_STATE(IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG);
    pushback(c);
    return '^';

  case ';':
    SET_LEX_STATE(EXPR_BEG);
    command_start = TRUE;
    return ';';

  case ',':
    SET_LEX_STATE(EXPR_BEG | EXPR_LABEL);
    return ',';

  case '~':
    if(IS_AFTER_OPERATOR()) {
      if((c = nextc()) != '@') {
        pushback(c);
      }
      SET_LEX_STATE(EXPR_ARG);
    } else {
      SET_LEX_STATE(EXPR_BEG);
    }
    return '~';

  case '(':
    if(IS_BEG()) {
      c = tLPAREN;
    } else if(IS_SPCARG(-1)) {
      c = tLPAREN_ARG;
    }
    paren_nest++;
    COND_PUSH(0);
    CMDARG_PUSH(0);
    SET_LEX_STATE(EXPR_BEG | EXPR_LABEL);
    return c;

  case '[':
    paren_nest++;
    if(IS_AFTER_OPERATOR()) {
      SET_LEX_STATE(EXPR_ARG);
      if((c = nextc()) == ']') {
        if((c = nextc()) == '=') {
          return tASET;
        }
        pushback(c);
        return tAREF;
      }
      pushback(c);
      SET_LEX_STATE(lex_state | EXPR_LABEL);
      return '[';
    } else if(IS_BEG()) {
      c = tLBRACK;
    } else if(IS_ARG() && (space_seen || lex_state_p(EXPR_LABELED))) {
      c = tLBRACK;
    }
    SET_LEX_STATE(EXPR_BEG|EXPR_LABEL);
    COND_PUSH(0);
    CMDARG_PUSH(0);
    return c;

  case '{':
    ++brace_nest;
    if(lpar_beg && lpar_beg == paren_nest) {
      SET_LEX_STATE(EXPR_BEG);
      lpar_beg = 0;
      --paren_nest;
      COND_PUSH(0);
      CMDARG_PUSH(0);
      return tLAMBEG;
    }
    if(lex_state_p(EXPR_LABELED)) {
      c = tLBRACE;      /* hash */
    } else if(lex_state_p(EXPR_ARG_ANY | EXPR_END | EXPR_ENDFN)) {
      c = '{';          /* block (primary) */
    } else if(lex_state_p(EXPR_ENDARG)) {
      c = tLBRACE_ARG;  /* block (expr) */
    } else {
      c = tLBRACE;      /* hash */
    }
    COND_PUSH(0);
    CMDARG_PUSH(0);
    SET_LEX_STATE(EXPR_BEG);
    if(c != tLBRACE_ARG) SET_LEX_STATE(lex_state | EXPR_LABEL);
    if(c != tLBRACE) command_start = TRUE;
    return c;

  case '\\':
    c = nextc();
    if(c == '\n') {
      space_seen = 1;
      goto retry; /* skip \\n */
    } else if(c == '(' || c == '{') {
      pushback(c);
      SET_LEX_STATE(EXPR_ENDFN);
      return tLAMBDA;
    }
    pushback(c);
    return '\\';

  case '%':
    return parse_percent(parser_state, space_seen, last_state);

  case '$':
    return parse_gvar(parser_state, last_state);

  case '@':
    return parse_atmark(parser_state, last_state);

  case '_':
    if(was_bol() && whole_match_p("__END__", 7, 0)) {
      ruby__end__seen = 1;
      eofp = true;
      return -1;
    }
    newtok();
    break;

  default:
    if(!parser_is_identchar()) {
      rb_compile_error(parser_state, "Invalid char `\\x%02X' in expression", c);
      return -1;
    }

    newtok();
    break;
  }

  return parse_ident(parser_state, c, cmd_state);
}

#if YYPURE
static int
yylex(void *l, void *p)
#else
yylex(void *p)
#endif
{
  rb_parser_state* parser_state = (rb_parser_state*)p;

  lval = l;
  ((YYSTYPE*)lval)->val = Qundef;

  return parser_yylex(parser_state);
}

VALUE
parser_add_reference(rb_parser_state* parser_state, VALUE obj)
{
  rb_ary_push(references, obj);

  return obj;
}

NODE*
parser_node_newnode(rb_parser_state* parser_state, enum node_type type,
                 VALUE a0, VALUE a1, VALUE a2)
{
  NODE *n = (NODE*)pt_allocate(parser_state, sizeof(NODE));

  n->flags = 0;
  nd_set_type(n, type);
  nd_set_line(n, sourceline);
  n->nd_file = sourcefile;

  n->u1.value = a0;
  n->u2.value = a1;
  n->u3.value = a2;

  return n;
}

enum node_type
nodetype(NODE *node) {  /* for debug */
  return (enum node_type)nd_type(node);
}

int
nodeline(NODE *node) {
  return nd_line(node);
}

static NODE*
parser_newline_node(rb_parser_state* parser_state, NODE *node)
{
  if(node) {
    node = remove_begin(node);
    node->flags |= NODE_FL_NEWLINE;
  }
  return node;
}

static void
fixpos(NODE *node, NODE *orig)
{
  if(!node) return;
  if(!orig) return;
  if(orig == (NODE*)1) return;
  nd_set_line(node, nd_line(orig));
}

/*
static void
parser_warning(rb_parser_state* parser_state, NODE *node, const char *mesg)
{
  int line = ruby_sourceline;
  if(emit_warnings) {
    ruby_sourceline = nd_line(node);
    printf("%s:%li: warning: %s\n", ruby_sourcefile, ruby_sourceline, mesg);
    ruby_sourceline = line;
  }
}
*/

static void
rb_compile_warn(const char *file, int line, const char *fmt, ...)
{
  // TODO
  return;

  char buf[BUFSIZ];
  va_list args;

  if(NIL_P(ruby_verbose)) return;

  snprintf(buf, BUFSIZ, "warning: %s", fmt);

  va_start(args, fmt);
  // compile_warn_print(file, line, buf, args);
  va_end(args);
}

/* rb_compile_warning() reports only in verbose mode */
void
rb_compile_warning(const char *file, int line, const char *fmt, ...)
{
  // TODO
  return;

  char buf[BUFSIZ];
  va_list args;

  snprintf(buf, BUFSIZ, "warning: %s", fmt);

  va_start(args, fmt);
  // compile_warn_print(file, line, buf, args);
  va_end(args);
}

static void
parser_warning(rb_parser_state* parser_state, NODE *node, const char *mesg)
{
  rb_compile_warning(sourcefile, nd_line(node), "%s", mesg);
}
#define parser_warning(node, mesg) parser_warning(parser_state, node, mesg)

static void
parser_warn(rb_parser_state* parser_state, NODE *node, const char *mesg)
{
  rb_compile_warn(sourcefile, nd_line(node), "%s", mesg);
}
#define parser_warn(node, mesg) parser_warn(parser_state, node, mesg)

static NODE*
parser_block_append(rb_parser_state* parser_state, NODE *head, NODE *tail)
{
  NODE *end, *h = head, *nd;

  if(tail == 0) return head;

  if(h == 0) return tail;
  switch(nd_type(h)) {
  case NODE_STR:
  case NODE_LIT:
  case NODE_SELF:
  case NODE_TRUE:
  case NODE_FALSE:
  case NODE_NIL:
    parser_warning(h, "unused literal ignored");
    return tail;
  default:
    h = end = NEW_BLOCK(head);
    end->nd_end = end;
    fixpos(end, head);
    head = end;
    break;
  case NODE_BLOCK:
    end = h->nd_end;
    break;
  }

  nd = end->nd_head;
  switch(nd_type(nd)) {
  case NODE_RETURN:
  case NODE_BREAK:
  case NODE_NEXT:
  case NODE_REDO:
  case NODE_RETRY:
    if(verbose) {
      parser_warning(nd, "statement not reached");
    }
    break;

  default:
    break;
  }

  if(nd_type(tail) != NODE_BLOCK) {
    tail = NEW_BLOCK(tail);
    tail->nd_end = tail;
  }
  end->nd_next = tail;
  h->nd_end = tail->nd_end;
  return head;
}

/* append item to the list */
static NODE*
parser_list_append(rb_parser_state* parser_state, NODE *list, NODE *item)
{
  NODE *last;

  if(list == 0) return NEW_LIST(item);
  if(list->nd_next) {
    last = list->nd_next->nd_end;
  } else {
    last = list;
  }

  list->nd_alen += 1;
  last->nd_next = NEW_LIST(item);
  list->nd_next->nd_end = last->nd_next;
  return list;
}

/* concat two lists */
static NODE*
list_concat(NODE *head, NODE *tail)
{
  NODE *last;

  if(head->nd_next) {
    last = head->nd_next->nd_end;
  } else {
    last = head;
  }

  head->nd_alen += tail->nd_alen;
  last->nd_next = tail;
  if(tail->nd_next) {
    head->nd_next->nd_end = tail->nd_next->nd_end;
  } else {
    head->nd_next->nd_end = tail;
  }

  return head;
}

static int
parser_literal_concat0(rb_parser_state* parser_state, VALUE head, VALUE tail)
{
  if(NIL_P(tail)) return 1;
  if(!parser_enc_compatible(head, tail)) {
    rb_compile_error(parser_state, "string literal encodings differ (%s / %s)",
    parser_enc_name(parser_enc_get(head)),
    parser_enc_name(parser_enc_get(tail)));
    rb_str_resize(head, 0);
    rb_str_resize(tail, 0);
    return 0;
  }
  rb_str_buf_append(head, tail);
  return 1;
}

/* concat two string literals */
static NODE *
parser_literal_concat(rb_parser_state* parser_state, NODE *head, NODE *tail)
{
  enum node_type htype;
  NODE *headlast;
  VALUE lit;

  if(!head) return tail;
  if(!tail) return head;

  htype = (enum node_type)nd_type(head);
  if(htype == NODE_EVSTR) {
    NODE *node = NEW_DSTR(STR_NEW0());
    head = list_append(node, head);
    htype = NODE_DSTR;
  }
  switch(nd_type(tail)) {
  case NODE_STR:
    if(htype == NODE_DSTR
       && (headlast = head->nd_next->nd_end->nd_head)
       && nd_type(headlast) == NODE_STR) {
      htype = NODE_STR;
      lit = headlast->nd_lit;
    } else {
      lit = head->nd_lit;
    }
    if(htype == NODE_STR) {
      if(!literal_concat0(lit, tail->nd_lit)) {
      error:
        return 0;
      }
    } else {
      list_append(head, tail);
    }
    break;

  case NODE_DSTR:
    if(htype == NODE_STR) {
      if(!literal_concat0(head->nd_lit, tail->nd_lit))
        goto error;
      tail->nd_lit = head->nd_lit;
      head = tail;
    } else if(NIL_P(tail->nd_lit)) {
    append:
      head->nd_alen += tail->nd_alen - 1;
      head->nd_next->nd_end->nd_next = tail->nd_next;
      head->nd_next->nd_end = tail->nd_next->nd_end;
    } else if(htype == NODE_DSTR
              && (headlast = head->nd_next->nd_end->nd_head)
              && nd_type(headlast) == NODE_STR) {
      lit = headlast->nd_lit;
      if(!literal_concat0(lit, tail->nd_lit))
      goto error;
      tail->nd_lit = Qnil;
      goto append;
    } else {
      nd_set_type(tail, NODE_ARRAY);
      tail->nd_head = NEW_STR(tail->nd_lit);
      list_concat(head, tail);
    }
    break;

  case NODE_EVSTR:
    if(htype == NODE_STR) {
      nd_set_type(head, NODE_DSTR);
      head->nd_alen = 1;
    }
    list_append(head, tail);
    break;
  }
  return head;
}

static NODE *
parser_evstr2dstr(rb_parser_state* parser_state, NODE *node)
{
  if(nd_type(node) == NODE_EVSTR) {
    node = list_append(NEW_DSTR(STR_NEW0()), node);
  }
  return node;
}

static NODE *
parser_new_evstr(rb_parser_state* parser_state, NODE *node)
{
  NODE *head = node;

  if(node) {
    switch(nd_type(node)) {
    case NODE_STR: case NODE_DSTR: case NODE_EVSTR:
      return node;
    }
  }
  return NEW_EVSTR(head);
}

static NODE *
parser_call_bin_op(rb_parser_state* parser_state, NODE *recv, ID id, NODE *arg1)
{
  value_expr(recv);
  value_expr(arg1);
  return NEW_CALL(recv, convert_op(id), NEW_LIST(arg1));
}

static NODE *
parser_call_uni_op(rb_parser_state* parser_state, NODE *recv, ID id)
{
  value_expr(recv);
  return NEW_CALL(recv, convert_op(id), 0);
}

static const struct {
  ID token;
  const char *name;
} op_tbl[] = {
  {tDOT2,   ".."},
  {tDOT3,   "..."},
  {tPOW,    "**"},
  {tDSTAR,  "**"},
  {tUPLUS,  "+@"},
  {tUMINUS, "-@"},
  {tCMP,    "<=>"},
  {tGEQ,    ">="},
  {tLEQ,    "<="},
  {tEQ,     "=="},
  {tEQQ,    "==="},
  {tNEQ,    "!="},
  {tMATCH,  "=~"},
  {tNMATCH, "!~"},
  {tAREF,   "[]"},
  {tASET,   "[]="},
  {tLSHFT,  "<<"},
  {tRSHFT,  ">>"},
  {tCOLON2, "::"},

  // Added for Rubinius
  {'!',     "!"},
  {'%',     "%"},
  {'&',     "&"},
  {'*',     "*"},
  {'+',     "+"},
  {'-',     "-"},
  {'/',     "/"},
  {'<',     "<"},
  {'>',     ">"},
  {'^',     "^"},
  {'`',     "`"},
  {'|',     "|"},
  {'~',     "~"},
};

#define op_tbl_count numberof(op_tbl)

static ID convert_op(ID id) {
  for(int i = 0; i < op_tbl_count; i++) {
    if(op_tbl[i].token == id) {
      return parser_intern(op_tbl[i].name);
    }
  }
  return id;
}

static NODE*
parser_match_op(rb_parser_state* parser_state, NODE *node1, NODE *node2)
{
  value_expr(node1);
  value_expr(node2);
  if(node1) {
    switch(nd_type(node1)) {
    case NODE_DREGX:
    case NODE_DREGX_ONCE:
      return NEW_MATCH2(node1, node2);

    case NODE_REGEX:
        return NEW_MATCH2(node1, node2);
    }
  }

  if(node2) {
    switch(nd_type(node2)) {
    case NODE_DREGX:
    case NODE_DREGX_ONCE:
      return NEW_MATCH3(node2, node1);

    case NODE_REGEX:
      return NEW_MATCH3(node2, node1);
    }
  }

  return NEW_CALL(node1, convert_op(tMATCH), NEW_LIST(node2));
}

static NODE*
parser_gettable(rb_parser_state* parser_state, ID id)
{
  if(id == keyword_self) {
    return NEW_SELF();
  } else if(id == keyword_nil) {
    return NEW_NIL();
  } else if(id == keyword_true) {
    return NEW_TRUE();
  } else if(id == keyword_false) {
    return NEW_FALSE();
  } else if(id == keyword__FILE__) {
    return NEW_FILE();
  } else if(id == keyword__LINE__) {
    return NEW_NUMBER(INT2FIX(sourceline));
  } else if(id == keyword__ENCODING__) {
    return NEW_ENCODING(STR_NEW2(parser_enc_name(parser_state->enc)));
  } else if(is_local_id(id)) {
    if((in_block() && bv_defined(id)) || local_id(id)) {
      return NEW_LVAR(id);
    }
    /* method call without arguments */
    return NEW_VCALL(id);
  } else if(is_global_id(id)) {
    return NEW_GVAR(id);
  } else if(is_instance_id(id)) {
    return NEW_IVAR(id);
  } else if(is_const_id(id)) {
    return NEW_CONST(id);
  } else if(is_class_id(id)) {
    return NEW_CVAR(id);
  }
  rb_compile_error(parser_state, "identifier %s is not valid", parser_id2name(id));
  return 0;
}

static NODE*
parser_assignable(rb_parser_state* parser_state, ID id, NODE *val)
{
  if(!id) return 0;
  if(id == keyword_self) {
    yy_error("Can't change the value of self");
  } else if(id == keyword_nil) {
    yy_error("Can't assign to nil");
  } else if(id == keyword_true) {
    yy_error("Can't assign to true");
  } else if(id == keyword_false) {
    yy_error("Can't assign to false");
  } else if(id == keyword__FILE__) {
    yy_error("Can't assign to __FILE__");
  } else if(id == keyword__LINE__) {
    yy_error("Can't assign to __LINE__");
  } else if(id == keyword__ENCODING__) {
    yy_error("Can't assign to __ENCODING__");
  } else if(is_local_id(id)) {
    if(!local_id(id)) {
      local_var(id);
    }
    return NEW_LASGN(id, val);
  } else if(is_global_id(id)) {
    return NEW_GASGN(id, val);
  } else if(is_instance_id(id)) {
    return NEW_IASGN(id, val);
  } else if(is_const_id(id)) {
    if(!in_def && !in_single)
      return NEW_CDECL(id, val, 0);
    yy_error("dynamic constant assignment");
  } else if(is_class_id(id)) {
    return NEW_CVASGN(id, val);
  } else {
    rb_compile_error(parser_state, "identifier %s is not valid to set", parser_id2name(id));
  }
  return 0;
}

static ID
parser_shadowing_lvar(rb_parser_state* parser_state, ID name)
{
  if(parser_intern("_") == name) return name;

  if(in_block()) {
    if(bv_var(name)) {
      yy_error("duplicate argument name");
    } else if(bv_defined(name) || local_id(name)) {
      rb_warningS("shadowing outer local variable - %s", parser_id2name(name));
      vtable_add(locals_table->vars, name);
    }
  } else {
    if(local_id(name)) {
      yy_error("duplicate argument name");
    }
  }

  return name;
}

static void
parser_new_bv(rb_parser_state* parser_state, ID name)
{
  if(!name) return;
  if(!is_local_id(name)) {
    rb_compile_error(parser_state, "invalid local variable - %s", parser_id2name(name));
    return;
  }
  shadowing_lvar(name);
  local_var(name);
}

static const struct vtable*
parser_bv_push(rb_parser_state* parser_state) {
  locals_table->args = vtable_alloc(locals_table->args);
  locals_table->vars = vtable_alloc(locals_table->vars);
  return locals_table->args;
}

static void
bv_pop_tables(rb_parser_state* parser_state)
{
  struct vtable *tmp;

  tmp = locals_table->args;
  locals_table->args = locals_table->args->prev;
  vtable_free(tmp);

  tmp = locals_table->vars;
  locals_table->vars = locals_table->vars->prev;
  vtable_free(tmp);
}

static void
parser_bv_pop(rb_parser_state* parser_state, const struct vtable* args) {
  while(locals_table->args != args) {
    bv_pop_tables(parser_state);
    if(!locals_table->args) {
      struct local_vars *local = locals_table->prev;
      free(locals_table);
      locals_table = local;
    }
  }
  bv_pop_tables(parser_state);
}

static bool
parser_in_block(rb_parser_state* parser_state) {
  return locals_table->vars && locals_table->vars->prev;
}

static bool
parser_bv_defined(rb_parser_state* parser_state, ID id)
{
  struct vtable *vars, *args;

  args = locals_table->args;
  vars = locals_table->vars;

  while(vars) {
    if(vtable_included(args, id)) {
      return true;
    }
    if(vtable_included(vars, id)) {
      return true;
    }
    args = args->prev;
    vars = vars->prev;
  }

  return false;
}

static int
parser_bv_var(rb_parser_state* parser_state, ID id)
{
  return vtable_included(locals_table->args, id) ||
            vtable_included(locals_table->vars, id);
}

static NODE *
parser_aryset(rb_parser_state* parser_state, NODE *recv, NODE *idx)
{
  if(recv && nd_type(recv) == NODE_SELF) {
    recv = (NODE *)1;
  }
  return NEW_ATTRASGN(recv, convert_op(tASET), idx);
}

static void
parser_block_dup_check(rb_parser_state* parser_state, NODE *node1, NODE *node2)
{
  if(node2 && node1 && nd_type(node1) == NODE_BLOCK_PASS) {
    compile_error("both block arg and actual block given");
  }
}

static const char id_type_names[][9] = {
  "LOCAL",
  "INSTANCE",
  "",       /* INSTANCE2 */
  "GLOBAL",
  "ATTRSET",
  "CONST",
  "CLASS",
  "JUNK",
};

static ID
rb_id_attrset(ID id)
{
  if(!is_notop_id(id)) {
    switch(id) {
    case tAREF:
    case tASET:
      return tASET; /* only exception */
    }
    rb_name_error(id, "cannot make operator ID :%s attrset", rb_id2name(id));
  } else {
    int scope = (int)(id & ID_SCOPE_MASK);
    switch(scope) {
    case ID_LOCAL:
    case ID_INSTANCE:
    case ID_GLOBAL:
    case ID_CONST:
    case ID_CLASS:
    case ID_JUNK:
      break;
    case ID_ATTRSET:
      return id;
    default:
      rb_name_error(id, "cannot make %s ID %+ld attrset",
                    id_type_names[scope], ID2SYM(id));
    }
  }
  id &= ~ID_SCOPE_MASK;
  id |= ID_ATTRSET;
  return id;
}

static NODE *
parser_attrset(rb_parser_state* parser_state, NODE *recv, ID atype, ID id)
{
  if(recv && nd_type(recv) == NODE_SELF) {
    recv = (NODE *)1;
  }

  if(CALL_Q_P(atype)) {
    return NEW_ANDATTRASGN(recv, rb_id_attrset(id), 0);
  } else {
    return NEW_ATTRASGN(recv, rb_id_attrset(id), 0);
  }
}

static void
rb_parser_backref_error(rb_parser_state* parser_state, NODE *node)
{
  switch(nd_type(node)) {
  case NODE_NTH_REF:
    rb_compile_error(parser_state, "Can't set variable $%u", node->nd_nth);
    break;
  case NODE_BACK_REF:
    rb_compile_error(parser_state, "Can't set variable $%c", (int)node->nd_nth);
    break;
  }
}

static NODE *
parser_arg_concat(rb_parser_state* parser_state, NODE *node1, NODE *node2)
{
  if(!node2) return node1;
  return NEW_ARGSCAT(node1, node2);
}

static NODE *
parser_arg_append(rb_parser_state* parser_state, NODE *node1, NODE *node2)
{
  if(!node1) return NEW_LIST(node2);
  switch(nd_type(node1))  {
  case NODE_ARRAY:
    return list_append(node1, node2);
  case NODE_BLOCK_PASS:
    node1->nd_head = arg_append(node1->nd_head, node2);
    return node1;
  case NODE_ARGSPUSH:
    node1->nd_body = list_append(NEW_LIST(node1->nd_body), node2);
    nd_set_type(node1, NODE_ARGSCAT);
    return node1;
  }
  return NEW_ARGSPUSH(node1, node2);
}

static NODE *
splat_array(NODE* node)
{
  if(nd_type(node) == NODE_SPLAT) node = node->nd_head;
  if(nd_type(node) == NODE_ARRAY) return node;
  return 0;
}

static NODE*
parser_node_assign(rb_parser_state* parser_state, NODE *lhs, NODE *rhs)
{
  if(!lhs) return 0;

  switch(nd_type(lhs)) {
  case NODE_GASGN:
  case NODE_IASGN:
  case NODE_LASGN:
  case NODE_DASGN:
  case NODE_DASGN_CURR:
  case NODE_MASGN:
  case NODE_CDECL:
  case NODE_CVASGN:
    lhs->nd_value = rhs;
    break;

  case NODE_ANDATTRASGN:
  case NODE_ATTRASGN:
  case NODE_CALL:
    lhs->nd_args = arg_append(lhs->nd_args, rhs);
    break;

  default:
    /* should not happen */
    break;
  }

  return lhs;
}

static NODE*
parser_new_op_assign(rb_parser_state* parser_state, NODE *lhs, ID op, NODE *rhs)
{
  NODE *asgn;

  if(lhs) {
    ID vid = lhs->nd_vid;
    if(op == tOROP) {
      lhs->nd_value = rhs;
      asgn = NEW_OP_ASGN_OR(gettable(vid), lhs);
      if(is_asgn_or_id(vid)) {
        asgn->nd_aid = vid;
      }
    } else if(op == tANDOP) {
      lhs->nd_value = rhs;
      asgn = NEW_OP_ASGN_AND(gettable(vid), lhs);
    } else {
      asgn = lhs;
      // TODO: is NEW_LIST(rhs) needed?
      asgn->nd_value = call_bin_op(gettable(vid), op, rhs);
    }
  } else {
    asgn = NEW_BEGIN(0);
  }

  return asgn;
}

static NODE*
parser_new_attr_op_assign(rb_parser_state* parser_state, NODE *lhs,
                          ID atype, ID attr, ID op, NODE *rhs)
{
  NODE *asgn;

  if(op == tOROP) {
    op = 0;
  } else if(op == tANDOP) {
    op = 1;
  } else {
    op = convert_op(op);
  }
  asgn = NEW_OP_ASGN2(lhs, CALL_Q_P(atype), attr, op, rhs);
  fixpos(asgn, lhs);

  return asgn;
}

static NODE*
parser_new_const_op_assign(rb_parser_state* parser_state, NODE *lhs, ID op, NODE *rhs)
{
  NODE *asgn;

  if(op == tOROP) {
    op = 0;
  } else if(op == tANDOP) {
    op = 1;
  } else {
    op = convert_op(op);
  }

  if(lhs) {
    asgn = NEW_OP_CDECL(lhs, op, rhs);
  } else {
    asgn = NEW_BEGIN(0);
  }
  fixpos(asgn, lhs);

  return asgn;
}

static int
parser_value_expr(rb_parser_state* parser_state, NODE *node)
{
  int cond = 0;

  if(!node) {
    rb_warning("empty expression");
  }

  while(node) {
    switch(nd_type(node)) {
    case NODE_RETURN:
    case NODE_BREAK:
    case NODE_NEXT:
    case NODE_REDO:
    case NODE_RETRY:
      if(!cond) yy_error("void value expression");
      /* or "control never reach"? */
      return FALSE;

    case NODE_BLOCK:
      while(node->nd_next) {
        node = node->nd_next;
      }
      node = node->nd_head;
      break;

    case NODE_BEGIN:
      node = node->nd_body;
      break;

    case NODE_IF:
      if(!node->nd_body) {
        node = node->nd_else;
        break;
      } else if(!node->nd_else) {
        node = node->nd_body;
        break;
      }
      if(!value_expr(node->nd_body)) return FALSE;
      node = node->nd_else;
      break;

    case NODE_AND:
    case NODE_OR:
      cond = 1;
      node = node->nd_2nd;
      break;

    default:
      return TRUE;
    }
  }

  return TRUE;
}

static void
parser_void_stmts(rb_parser_state* parser_state, NODE *node)
{
  if(!RTEST(ruby_verbose)) return;
  if(!node) return;
  if(nd_type(node) != NODE_BLOCK) return;

  for(;;) {
    if(!node->nd_next) return;
    void_expr0(node->nd_head);
    node = node->nd_next;
  }
}

static void
parser_void_expr0(rb_parser_state* parser_state, NODE *node)
{
  const char *useless = NULL;

  if(!verbose) return;

  if(!node) return;
  switch(nd_type(node)) {
  case NODE_CALL:
    switch(node->nd_mid) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case tPOW:
    case tUPLUS:
    case tUMINUS:
    case '|':
    case '^':
    case '&':
    case tCMP:
    case '>':
    case tGEQ:
    case '<':
    case tLEQ:
    case tEQ:
    case tNEQ:
      useless = "";
      break;
    }
    break;

  case NODE_LVAR:
  case NODE_DVAR:
  case NODE_GVAR:
  case NODE_IVAR:
  case NODE_CVAR:
  case NODE_NTH_REF:
  case NODE_BACK_REF:
    useless = "a variable";
    break;
  case NODE_CONST:
    useless = "a constant";
    break;
  case NODE_LIT:
  case NODE_STR:
  case NODE_DSTR:
  case NODE_DREGX:
  case NODE_DREGX_ONCE:
    useless = "a literal";
    break;
  case NODE_COLON2:
  case NODE_COLON3:
    useless = "::";
    break;
  case NODE_DOT2:
    useless = "..";
    break;
  case NODE_DOT3:
    useless = "...";
    break;
  case NODE_SELF:
    useless = "self";
    break;
  case NODE_NIL:
    useless = "nil";
    break;
  case NODE_TRUE:
    useless = "true";
    break;
  case NODE_FALSE:
    useless = "false";
    break;
  case NODE_DEFINED:
    useless = "defined?";
    break;
  }

  if(useless) {
    int line = sourceline;

    sourceline = nd_line(node);
    rb_warn("useless use of %s in void context", useless);
    sourceline = line;
  }
}

static NODE *
remove_begin(NODE *node)
{
  NODE **n = &node, *n1 = node;
  while(n1 && nd_type(n1) == NODE_BEGIN && n1->nd_body) {
    *n = n1 = n1->nd_body;
  }
  return node;
}

static int
assign_in_cond(NODE *node, rb_parser_state* parser_state)
{
  switch(nd_type(node)) {
  case NODE_MASGN:
    yy_error("multiple assignment in conditional");
    return 1;

  case NODE_LASGN:
  case NODE_DASGN:
  case NODE_DASGN_CURR:
  case NODE_GASGN:
  case NODE_IASGN:
    break;

  default:
    return 0;
  }

  if(!node->nd_value) return 1;
  switch(nd_type(node->nd_value)) {
  case NODE_LIT:
  case NODE_STR:
  case NODE_NIL:
  case NODE_TRUE:
  case NODE_FALSE:
    // always warn
    // TODO
    // parser_warn(node->nd_value, "found = in conditional, should be ==");
    return 1;

  case NODE_DSTR:
  case NODE_XSTR:
  case NODE_DXSTR:
  case NODE_EVSTR:
  case NODE_DREGX:
  default:
    break;
  }
  return 1;
}

#define e_option_supplied()   parser_e_option_supplied(parser_state)

static bool
parser_e_option_supplied(rb_parser_state* parser_state)
{
  return strcmp(sourcefile, "-e") == 0;
}

static void
warn_unless_e_option(rb_parser_state* parser_state, NODE *node, const char *str)
{
  if(!e_option_supplied()) parser_warning(node, str);
}

static void
warning_unless_e_option(rb_parser_state* parser_state, NODE *node, const char *str)
{
  if(!e_option_supplied()) parser_warning(node, str);
}

static NODE *cond0(rb_parser_state* parser_state, NODE *node);

static NODE*
range_op(rb_parser_state* parser_state, NODE *node)
{
  if(node == 0) return 0;

  value_expr(node);
  if(nd_type(node) == NODE_LIT && FIXNUM_P(node->nd_lit)) {
    warn_unless_e_option(parser_state, node, "integer literal in conditional range");
    return NEW_CALL(node, tEQ, NEW_LIST(NEW_GVAR(parser_intern("$."))));
  }
  return cond0(parser_state, node);
}

static int
literal_node(NODE *node)
{
  if(!node) return 1;        /* same as NODE_NIL */
  switch(nd_type(node)) {
  case NODE_LIT:
  case NODE_STR:
  case NODE_DSTR:
  case NODE_EVSTR:
  case NODE_DREGX:
  case NODE_DREGX_ONCE:
  case NODE_DSYM:
    return 2;
  case NODE_TRUE:
  case NODE_FALSE:
  case NODE_NIL:
    return 1;
  }
  return 0;
}

static NODE*
cond0(rb_parser_state* parser_state, NODE *node)
{
  if(node == 0) return 0;
  assign_in_cond(node, parser_state);

  switch(nd_type(node)) {
  case NODE_DSTR:
  case NODE_EVSTR:
  case NODE_STR:
    rb_warn0("string literal in condition");
    break;

  case NODE_DREGX:
  case NODE_DREGX_ONCE:
    warning_unless_e_option(parser_state, node, "regex literal in condition");
    return NEW_MATCH2(node, NEW_GVAR(parser_intern("$_")));

  case NODE_AND:
  case NODE_OR:
    node->nd_1st = cond0(parser_state, node->nd_1st);
    node->nd_2nd = cond0(parser_state, node->nd_2nd);
    break;

  case NODE_DOT2:
  case NODE_DOT3:
    node->nd_beg = range_op(parser_state, node->nd_beg);
    node->nd_end = range_op(parser_state, node->nd_end);
    if(nd_type(node) == NODE_DOT2) nd_set_type(node,NODE_FLIP2);
    else if(nd_type(node) == NODE_DOT3) nd_set_type(node, NODE_FLIP3);
    if(!e_option_supplied()) {
      int b = literal_node(node->nd_beg);
      int e = literal_node(node->nd_end);
      if((b == 1 && e == 1) || (b + e >= 2 && verbose)) {
        parser_warn(node, "range literal in condition");
      }
    }
    break;

  case NODE_DSYM:
    parser_warning(node, "literal in condition");
    break;

  case NODE_LIT:
    parser_warning(node, "literal in condition");
    break;

  case NODE_REGEX:
    warn_unless_e_option(parser_state, node, "regex literal in condition");
    nd_set_type(node, NODE_MATCH);
  default:
    break;
  }
  return node;
}

static NODE*
parser_cond(rb_parser_state* parser_state, NODE *node)
{
  if(node == 0) return 0;
  return cond0(parser_state, node);
}

static NODE*
parser_logop(rb_parser_state* parser_state, enum node_type type, NODE *left, NODE *right)
{
  value_expr(left);
  if(left && nd_type(left) == type) {
    NODE *node = left, *second;
    while((second = node->nd_2nd) != 0 && nd_type(second) == type) {
      node = second;
    }
    node->nd_2nd = NEW_NODE(type, second, right, 0);
    return left;
  }
  return NEW_NODE(type, left, right, 0);
}

static void
no_blockarg(rb_parser_state* parser_state, NODE *node)
{
  if(node && nd_type(node) == NODE_BLOCK_PASS) {
    rb_compile_error(parser_state, "block argument should not be given");
  }
}

static NODE *
parser_ret_args(rb_parser_state* parser_state, NODE *node)
{
  if(node) {
    no_blockarg(parser_state, node);
    if(nd_type(node) == NODE_ARRAY) {
      if(node->nd_next == 0) {
        node = node->nd_head;
      } else {
        nd_set_type(node, NODE_VALUES);
      }
    }
  }
  return node;
}

static NODE *
parser_new_yield(rb_parser_state* parser_state, NODE *node)
{
  VALUE state = Qtrue;

  if(node) {
    no_blockarg(parser_state, node);
    if(node && nd_type(node) == NODE_SPLAT) {
      state = Qtrue;
    }
  } else {
    state = Qfalse;
  }
  return NEW_YIELD(node, state);
}


static NODE *
parser_dsym_node(rb_parser_state* parser_state, NODE *node)
{
  if(!node) {
    node = NEW_LIT(ID2SYM(parser_intern("")));
  } else {
    VALUE lit;

    switch(nd_type(node)) {
    case NODE_DSTR:
      nd_set_type(node, NODE_DSYM);
      break;
    case NODE_STR:
      lit = node->nd_lit;
      node->nd_lit = ID2SYM(parser_intern_str(lit));
      nd_set_type(node, NODE_LIT);
      break;
    default:
      node = NEW_NODE(NODE_DSYM, REF(STR_NEW0()), 1, NEW_LIST(node));
      break;
    }
  }
  return node;
}

static NODE*
parser_negate_lit(rb_parser_state* parser_state, NODE *node)
{
  switch(TYPE(node->nd_lit)) {
  case T_FIXNUM:
    node->nd_lit = LONG2FIX(-FIX2LONG(node->nd_lit));
    break;
  case T_BIGNUM:
  case T_RATIONAL:
  case T_COMPLEX:
    node->nd_lit = REF(rb_funcall(node->nd_lit, rb_intern("-@"), 0, 0));
    break;
  case T_FLOAT:
    node->nd_lit = REF(rb_float_new(-NUM2DBL(node->nd_lit)));
    break;
  default:
    break;
  }
  return node;
}

static NODE *
arg_blk_pass(NODE *node1, NODE *node2)
{
  if(node2) {
    node2->nd_head = node1;
    return node2;
  }
  return node1;
}

static NODE*
parser_new_args(rb_parser_state* parser_state, NODE *m, NODE *o, ID r, NODE *p, NODE *tail)
{
  int saved_line = sourceline;
  struct rb_args_info *args = tail->nd_ainfo;

  args->pre_args_num   = m ? rb_long2int(m->nd_plen) : 0;
  args->pre_init       = m ? m->nd_next : 0;

  args->post_args_num  = p ? rb_long2int(p->nd_plen) : 0;
  args->post_init      = p ? p->nd_next : 0;
  args->first_post_arg = p ? p->nd_pid : 0;

  args->rest_arg       = r;

  args->opt_args       = o;

  sourceline = saved_line;
  return tail;
}

static NODE*
parser_new_args_tail(rb_parser_state* parser_state, NODE *k, ID kr, ID b)
{
  int saved_line = sourceline;
  struct rb_args_info *args;
  NODE *kw_rest_arg = 0;
  NODE *node;

  args = (struct rb_args_info *)pt_allocate(parser_state, sizeof(struct rb_args_info));
  MEMZERO(args, struct rb_args_info, 1);
  node = NEW_NODE(NODE_ARGS, 0, 0, args);

  args->block_arg      = b;
  args->kw_args        = k;
  if(kr) {
    if(kr == 1) {
      kw_rest_arg = (NODE*)kr;
    } else {
      arg_var(kr);
      kw_rest_arg  = NEW_DVAR(kr);
    }
  }
  args->kw_rest_arg    = kw_rest_arg;

  sourceline = saved_line;
  return node;
}

static int
parser_arg_var(rb_parser_state* parser_state, ID id)
{
  vtable_add(locals_table->args, id);
  return vtable_size(locals_table->args) - 1;
}

static int
parser_local_var(rb_parser_state* parser_state, ID id)
{
  vtable_add(locals_table->vars, id);
  return vtable_size(locals_table->vars) - 1;
}

static bool
parser_local_id(rb_parser_state* parser_state, ID id)
{
  struct vtable *vars, *args;

  vars = locals_table->vars;
  args = locals_table->args;

  while(vars && vars->prev) {
    vars = vars->prev;
    args = args->prev;
  }

  return (vtable_included(args, id) || vtable_included(vars, id));
}

static void
parser_local_push(rb_parser_state* parser_state, int top)
{
  struct local_vars *local;

  local = ALLOC(struct local_vars);
  local->prev = locals_table;
  local->args = vtable_alloc(0);
  local->vars = vtable_alloc(0);
  local->cmdargs = cmdarg_stack;
  cmdarg_stack = 0;
  locals_table = local;
}

static void
parser_local_pop(rb_parser_state* parser_state)
{
  struct local_vars *local = locals_table->prev;
  vtable_free(locals_table->args);
  vtable_free(locals_table->vars);
  cmdarg_stack = locals_table->cmdargs;
  xfree(locals_table);
  locals_table = local;
}

static ID*
vtable_tblcpy(ID *buf, const struct vtable *src)
{
  int cnt = vtable_size(src);

  if(cnt > 0) {
    buf[0] = cnt;
    for(int i = 0; i < cnt; i++) {
      buf[i] = src->tbl[i];
    }
    return buf;
  }
  return 0;
}

static ID*
parser_local_tbl(rb_parser_state* parser_state)
{
  int arg_cnt = vtable_size(locals_table->args);
  int cnt = arg_cnt + vtable_size(locals_table->vars);
  ID *buf;

  if(cnt <= 0) return 0;
  buf = (ID*)pt_allocate(parser_state, (int)(sizeof(ID) * (cnt + 1)));
  vtable_tblcpy(buf + 1, locals_table->args);
  vtable_tblcpy(buf + arg_cnt + 1, locals_table->vars);
  buf[0] = cnt;
  return buf;
}

VALUE
rb_symbol_new(const char* name, long len, rb_encoding* enc)
{
  VALUE str = parser_enc_str_new(name, len, enc);
  return rb_funcall(str, rb_intern("to_sym"), 0);
}

ID
parser_intern3(const char* name, long len, rb_encoding* enc)
{
  const char *m = name;
  unsigned char c;
  long last;

  VALUE sym = rb_symbol_new(name, len, enc);
  ID id = (SYM2ID(sym) << ID_SCOPE_SHIFT) & ~ID_INTERNAL;

  last = len-1;
  switch(*m) {
  case '$':
    id |= ID_GLOBAL;
    break;
  case '@':
    if(m[1] == '@') {
      m++;
      id |= ID_CLASS;
    } else {
      id |= ID_INSTANCE;
    }
    m++;
    break;
  default:
    c = m[0];
    if(len > 1 && c != '_' && parser_enc_isascii(c, enc) && parser_enc_ispunct(c, enc)) {
      /* operators */
      for(int i = 0; i < op_tbl_count; i++) {
        if(*op_tbl[i].name == *m && strcmp(op_tbl[i].name, m) == 0) {
          return id;
        }
      }
    }

    if(m[last] == '=') {
      id |= ID_ATTRSET;
    } else if(parser_enc_isupper(m[0], enc)) {
      id |= ID_CONST;
    } else {
      id |= ID_LOCAL;
    }
    break;
  }

  return id;
}

ID
parser_intern2(const char* name, long len)
{
  return parser_intern3(name, len, parser_usascii_encoding());
}

ID
parser_intern(const char* name)
{
  return parser_intern2(name, strlen(name));
}

ID
parser_intern_str(VALUE str)
{
  return parser_intern3(RSTRING_PTR(str), RSTRING_LEN(str), parser_enc_get(str));
}

char*
parser_id2name(ID id)
{
  VALUE str = rb_funcall(ID2SYM(id), rb_intern("to_s"), 0);
  return RSTRING_PTR(str);
}

static int
scan_oct(const char *start, size_t len, size_t *retlen)
{
  const char *s = start;
  int retval = 0;

  while(len-- && *s >= '0' && *s <= '7') {
    retval <<= 3;
    retval |= *s++ - '0';
  }
  *retlen = s - start;
  return retval;
}

static int
scan_hex(const char *start, size_t len, size_t *retlen)
{
  static const char hexdigit[] = "0123456789abcdef0123456789ABCDEF";
  const char *s = start;
  int retval = 0;
  const char *tmp;

  while(len-- && *s && (tmp = strchr(hexdigit, *s))) {
    retval <<= 4;
    retval |= (int)((tmp - hexdigit) & 15);
    s++;
  }
  *retlen = s - start;
  return retval;
}

static ID
parser_internal_id(rb_parser_state* parser_state)
{
  ID id = (ID)vtable_size(locals_table->args) + (ID)vtable_size(locals_table->vars);
  id += ((tLAST_TOKEN - ID_INTERNAL) >> ID_SCOPE_SHIFT) + 1;
  return ID_INTERNAL | (id << ID_SCOPE_SHIFT);
}

};
