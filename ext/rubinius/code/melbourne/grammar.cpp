/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 13 "grammar.y" /* yacc.c:339  */


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


#line 491 "grammar.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END_OF_INPUT = 0,
    keyword_class = 258,
    keyword_module = 259,
    keyword_def = 260,
    keyword_defm = 261,
    keyword_fun = 262,
    keyword_funm = 263,
    keyword_undef = 264,
    keyword_begin = 265,
    keyword_rescue = 266,
    keyword_ensure = 267,
    keyword_end = 268,
    keyword_if = 269,
    keyword_unless = 270,
    keyword_then = 271,
    keyword_elsif = 272,
    keyword_else = 273,
    keyword_case = 274,
    keyword_when = 275,
    keyword_while = 276,
    keyword_until = 277,
    keyword_for = 278,
    keyword_break = 279,
    keyword_next = 280,
    keyword_redo = 281,
    keyword_retry = 282,
    keyword_in = 283,
    keyword_do = 284,
    keyword_do_cond = 285,
    keyword_do_block = 286,
    keyword_do_LAMBDA = 287,
    keyword_return = 288,
    keyword_yield = 289,
    keyword_super = 290,
    keyword_self = 291,
    keyword_nil = 292,
    keyword_true = 293,
    keyword_false = 294,
    keyword_and = 295,
    keyword_or = 296,
    keyword_not = 297,
    modifier_if = 298,
    modifier_unless = 299,
    modifier_while = 300,
    modifier_until = 301,
    modifier_rescue = 302,
    keyword_alias = 303,
    keyword_defined = 304,
    keyword_BEGIN = 305,
    keyword_END = 306,
    keyword__LINE__ = 307,
    keyword__FILE__ = 308,
    keyword__ENCODING__ = 309,
    tIDENTIFIER = 310,
    tFID = 311,
    tGVAR = 312,
    tIVAR = 313,
    tCONSTANT = 314,
    tCVAR = 315,
    tLABEL = 316,
    tINTEGER = 317,
    tFLOAT = 318,
    tRATIONAL = 319,
    tIMAGINARY = 320,
    tSTRING_CONTENT = 321,
    tCHAR = 322,
    tNTH_REF = 323,
    tBACK_REF = 324,
    tREGEXP_END = 325,
    tUPLUS = 326,
    tUMINUS = 327,
    tPOW = 328,
    tCMP = 329,
    tEQ = 330,
    tEQQ = 331,
    tNEQ = 332,
    tGEQ = 333,
    tLEQ = 334,
    tANDOP = 335,
    tOROP = 336,
    tMATCH = 337,
    tNMATCH = 338,
    tDOT2 = 339,
    tDOT3 = 340,
    tAREF = 341,
    tASET = 342,
    tLSHFT = 343,
    tRSHFT = 344,
    tANDDOT = 345,
    tCOLON2 = 346,
    tCOLON3 = 347,
    tOP_ASGN = 348,
    tASSOC = 349,
    tLPAREN = 350,
    tLPAREN_ARG = 351,
    tRPAREN = 352,
    tLBRACK = 353,
    tLBRACE = 354,
    tLBRACE_ARG = 355,
    tSTAR = 356,
    tDSTAR = 357,
    tAMPER = 358,
    tLAMBDA = 359,
    tSYMBEG = 360,
    tSTRING_BEG = 361,
    tXSTRING_BEG = 362,
    tREGEXP_BEG = 363,
    tWORDS_BEG = 364,
    tQWORDS_BEG = 365,
    tSYMBOLS_BEG = 366,
    tQSYMBOLS_BEG = 367,
    tSTRING_DBEG = 368,
    tSTRING_DEND = 369,
    tSTRING_DVAR = 370,
    tSTRING_END = 371,
    tLAMBEG = 372,
    tLABEL_END = 373,
    tLOWEST = 374,
    tUMINUS_NUM = 375,
    tLAST_TOKEN = 376
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 442 "grammar.y" /* yacc.c:355  */

    VALUE val;
    NODE *node;
    ID id;
    int num;
    const struct vtable* vars;

#line 659 "grammar.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (rb_parser_state* parser_state);



/* Copy the second part of user declarations.  */

#line 675 "grammar.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  149
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  220
/* YYNRULES -- Number of rules.  */
#define YYNRULES  652
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1103

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   376

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     148,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   146,   134,     2,     2,     2,   132,   127,     2,
     142,   143,   130,   128,   140,   129,   147,   131,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   122,   145,
     124,   120,   123,   121,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   139,     2,   144,   126,     2,   141,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,   125,   138,   135,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   133,   136
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   603,   603,   603,   628,   635,   639,   643,   647,   653,
     655,   654,   666,   689,   696,   700,   704,   708,   714,   719,
     718,   728,   728,   732,   736,   743,   748,   752,   757,   762,
     770,   778,   783,   792,   793,   799,   804,   821,   826,   831,
     836,   841,   846,   851,   856,   859,   864,   871,   872,   876,
     880,   884,   888,   891,   899,   900,   903,   904,   911,   910,
     925,   932,   937,   945,   950,   957,   962,   969,   974,   979,
     983,   987,   993,   994,  1000,  1001,  1007,  1011,  1015,  1019,
    1023,  1027,  1031,  1035,  1039,  1043,  1049,  1050,  1056,  1060,
    1066,  1070,  1076,  1080,  1084,  1088,  1092,  1096,  1100,  1106,
    1112,  1119,  1124,  1129,  1133,  1137,  1141,  1145,  1151,  1157,
    1164,  1168,  1171,  1175,  1179,  1185,  1186,  1187,  1188,  1193,
    1200,  1201,  1204,  1208,  1211,  1215,  1215,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1253,  1253,  1253,
    1254,  1254,  1255,  1255,  1255,  1256,  1256,  1256,  1256,  1257,
    1257,  1257,  1258,  1258,  1258,  1258,  1259,  1259,  1259,  1260,
    1260,  1260,  1260,  1261,  1261,  1261,  1261,  1262,  1262,  1262,
    1262,  1263,  1263,  1263,  1263,  1264,  1264,  1264,  1264,  1265,
    1265,  1268,  1273,  1279,  1284,  1290,  1311,  1316,  1321,  1326,
    1331,  1336,  1341,  1347,  1353,  1357,  1361,  1365,  1369,  1373,
    1377,  1381,  1385,  1389,  1393,  1397,  1401,  1405,  1409,  1413,
    1417,  1421,  1425,  1429,  1433,  1443,  1447,  1451,  1455,  1459,
    1463,  1467,  1471,  1471,  1476,  1482,  1488,  1496,  1497,  1501,
    1505,  1511,  1517,  1518,  1521,  1522,  1523,  1527,  1531,  1537,
    1542,  1546,  1551,  1556,  1559,  1559,  1571,  1577,  1581,  1587,
    1591,  1595,  1604,  1615,  1616,  1619,  1628,  1637,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1658,
    1657,  1677,  1677,  1682,  1686,  1681,  1691,  1695,  1699,  1703,
    1711,  1715,  1719,  1723,  1727,  1731,  1731,  1736,  1740,  1744,
    1750,  1751,  1758,  1762,  1770,  1778,  1778,  1778,  1785,  1785,
    1785,  1792,  1799,  1804,  1806,  1803,  1823,  1822,  1839,  1838,
    1858,  1857,  1874,  1879,  1873,  1895,  1900,  1894,  1916,  1921,
    1915,  1937,  1942,  1936,  1957,  1958,  1957,  1974,  1975,  1974,
    1991,  1995,  1999,  2003,  2009,  2017,  2023,  2029,  2035,  2041,
    2047,  2053,  2059,  2065,  2071,  2078,  2085,  2092,  2099,  2105,
    2106,  2107,  2110,  2111,  2114,  2115,  2124,  2125,  2131,  2132,
    2135,  2139,  2145,  2149,  2155,  2159,  2164,  2169,  2173,  2177,
    2182,  2187,  2191,  2197,  2201,  2205,  2209,  2215,  2220,  2225,
    2229,  2233,  2237,  2241,  2245,  2249,  2253,  2257,  2261,  2265,
    2269,  2273,  2277,  2281,  2287,  2288,  2294,  2299,  2303,  2310,
    2314,  2321,  2326,  2333,  2339,  2345,  2348,  2353,  2356,  2345,
    2371,  2375,  2381,  2385,  2392,  2391,  2406,  2417,  2421,  2428,
    2437,  2444,  2443,  2453,  2452,  2461,  2466,  2465,  2475,  2474,
    2483,  2487,  2491,  2503,  2502,  2515,  2514,  2528,  2536,  2537,
    2540,  2552,  2555,  2559,  2563,  2566,  2570,  2573,  2577,  2580,
    2581,  2585,  2588,  2600,  2601,  2602,  2608,  2616,  2642,  2702,
    2706,  2713,  2716,  2722,  2723,  2729,  2733,  2740,  2743,  2751,
    2755,  2761,  2765,  2772,  2775,  2782,  2785,  2796,  2799,  2806,
    2809,  2816,  2819,  2842,  2844,  2843,  2855,  2861,  2865,  2869,
    2873,  2854,  2892,  2893,  2894,  2895,  2898,  2905,  2906,  2907,
    2908,  2911,  2918,  2919,  2925,  2926,  2927,  2928,  2931,  2932,
    2933,  2934,  2935,  2938,  2939,  2940,  2941,  2942,  2943,  2944,
    2947,  2953,  2961,  2965,  2971,  2972,  2976,  2975,  2985,  2991,
    2997,  2997,  3011,  3015,  3019,  3023,  3029,  3034,  3039,  3043,
    3047,  3051,  3055,  3059,  3063,  3067,  3071,  3075,  3079,  3083,
    3087,  3091,  3096,  3102,  3107,  3112,  3117,  3124,  3125,  3132,
    3140,  3144,  3154,  3155,  3163,  3171,  3176,  3183,  3188,  3195,
    3199,  3210,  3214,  3225,  3226,  3229,  3234,  3241,  3248,  3255,
    3259,  3270,  3274,  3285,  3286,  3289,  3297,  3304,  3305,  3308,
    3319,  3323,  3329,  3335,  3335,  3359,  3360,  3366,  3367,  3373,
    3377,  3381,  3385,  3391,  3392,  3393,  3396,  3397,  3398,  3399,
    3402,  3403,  3404,  3407,  3408,  3411,  3415,  3421,  3422,  3428,
    3429,  3432,  3433,  3436,  3439,  3442,  3443,  3444,  3447,  3448,
    3451,  3452,  3455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end-of-input\"", "error", "$undefined", "keyword_class",
  "keyword_module", "keyword_def", "keyword_defm", "keyword_fun",
  "keyword_funm", "keyword_undef", "keyword_begin", "keyword_rescue",
  "keyword_ensure", "keyword_end", "keyword_if", "keyword_unless",
  "keyword_then", "keyword_elsif", "keyword_else", "keyword_case",
  "keyword_when", "keyword_while", "keyword_until", "keyword_for",
  "keyword_break", "keyword_next", "keyword_redo", "keyword_retry",
  "keyword_in", "keyword_do", "keyword_do_cond", "keyword_do_block",
  "keyword_do_LAMBDA", "keyword_return", "keyword_yield", "keyword_super",
  "keyword_self", "keyword_nil", "keyword_true", "keyword_false",
  "keyword_and", "keyword_or", "keyword_not", "modifier_if",
  "modifier_unless", "modifier_while", "modifier_until", "modifier_rescue",
  "keyword_alias", "keyword_defined", "keyword_BEGIN", "keyword_END",
  "keyword__LINE__", "keyword__FILE__", "keyword__ENCODING__",
  "tIDENTIFIER", "tFID", "tGVAR", "tIVAR", "tCONSTANT", "tCVAR", "tLABEL",
  "tINTEGER", "tFLOAT", "tRATIONAL", "tIMAGINARY", "tSTRING_CONTENT",
  "tCHAR", "tNTH_REF", "tBACK_REF", "tREGEXP_END", "tUPLUS", "tUMINUS",
  "tPOW", "tCMP", "tEQ", "tEQQ", "tNEQ", "tGEQ", "tLEQ", "tANDOP", "tOROP",
  "tMATCH", "tNMATCH", "tDOT2", "tDOT3", "tAREF", "tASET", "tLSHFT",
  "tRSHFT", "tANDDOT", "tCOLON2", "tCOLON3", "tOP_ASGN", "tASSOC",
  "tLPAREN", "tLPAREN_ARG", "tRPAREN", "tLBRACK", "tLBRACE", "tLBRACE_ARG",
  "tSTAR", "tDSTAR", "tAMPER", "tLAMBDA", "tSYMBEG", "tSTRING_BEG",
  "tXSTRING_BEG", "tREGEXP_BEG", "tWORDS_BEG", "tQWORDS_BEG",
  "tSYMBOLS_BEG", "tQSYMBOLS_BEG", "tSTRING_DBEG", "tSTRING_DEND",
  "tSTRING_DVAR", "tSTRING_END", "tLAMBEG", "tLABEL_END", "tLOWEST", "'='",
  "'?'", "':'", "'>'", "'<'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "tUMINUS_NUM", "'!'", "'~'", "tLAST_TOKEN", "'{'", "'}'",
  "'['", "','", "'`'", "'('", "')'", "']'", "';'", "' '", "'.'", "'\\n'",
  "$accept", "program", "$@1", "top_compstmt", "top_stmts", "top_stmt",
  "$@2", "bodystmt", "compstmt", "stmts", "stmt_or_begin", "$@3", "stmt",
  "$@4", "command_asgn", "expr", "expr_value", "command_call",
  "block_command", "cmd_brace_block", "@5", "fcall", "command", "mlhs",
  "mlhs_inner", "mlhs_basic", "mlhs_item", "mlhs_head", "mlhs_post",
  "mlhs_node", "lhs", "cname", "cpath", "fname", "fsym", "fitem",
  "undef_list", "$@6", "op", "reswords", "arg", "$@7", "arg_value",
  "aref_args", "paren_args", "opt_paren_args", "opt_call_args",
  "call_args", "command_args", "@8", "block_arg", "opt_block_arg", "args",
  "mrhs_arg", "mrhs", "primary", "@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "@20", "@21", "@22",
  "@23", "@24", "@25", "@26", "@27", "@28", "@29", "@30", "@31", "$@32",
  "@33", "$@34", "primary_value", "k_begin", "k_if", "k_unless", "k_while",
  "k_until", "k_case", "k_for", "k_class", "k_module", "k_def", "k_defm",
  "k_fun", "k_funm", "k_end", "then", "do", "if_tail", "opt_else",
  "for_var", "f_marg", "f_marg_list", "f_margs", "block_args_tail",
  "opt_block_args_tail", "block_param", "opt_block_param",
  "block_param_def", "opt_bv_decl", "bv_decls", "bvar", "lambda", "@35",
  "@36", "@37", "@38", "f_larglist", "lambda_body", "do_block", "@39",
  "block_call", "method_call", "@40", "@41", "@42", "@43", "brace_block",
  "@44", "@45", "case_body", "cases", "opt_rescue", "exc_list", "exc_var",
  "opt_ensure", "literal", "strings", "string", "string1", "xstring",
  "regexp", "words", "word_list", "word", "symbols", "symbol_list",
  "qwords", "qsymbols", "qword_list", "qsym_list", "string_contents",
  "xstring_contents", "regexp_contents", "string_content", "@46", "@47",
  "@48", "@49", "@50", "@51", "string_dvar", "symbol", "sym", "dsym",
  "numeric", "simple_numeric", "user_variable", "keyword_variable",
  "var_ref", "var_lhs", "backref", "superclass", "$@52", "f_arglist",
  "@53", "args_tail", "opt_args_tail", "f_args", "f_bad_arg", "f_norm_arg",
  "f_arg_asgn", "f_arg_item", "f_arg", "f_label", "f_kw", "f_block_kw",
  "f_block_kwarg", "f_kwarg", "kwrest_mark", "f_kwrest", "f_opt",
  "f_block_opt", "f_block_optarg", "f_optarg", "restarg_mark",
  "f_rest_arg", "blkarg_mark", "f_block_arg", "opt_f_block_arg",
  "singleton", "$@54", "assoc_list", "assocs", "assoc", "operation",
  "operation2", "operation3", "dot_or_colon", "call_op", "call_op2",
  "opt_terms", "opt_nl", "rparen", "rbracket", "trailer", "term", "terms",
  "none", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
      61,    63,    58,    62,    60,   124,    94,    38,    43,    45,
      42,    47,    37,   375,    33,   126,   376,   123,   125,    91,
      44,    96,    40,    41,    93,    59,    32,    46,    10
};
# endif

#define YYPACT_NINF -844

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-844)))

#define YYTABLE_NINF -653

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-653)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -844,   142,  2995,  -844,  7575,  -844,  -844,  -844,  -844,  -844,
    -844,  7057,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  7692,
    7692,  -844,  -844,  7692,  4108,  3685,  -844,  -844,  -844,  -844,
      25,  6918,    10,  -844,    58,  -844,  -844,  -844,  2758,  3826,
    -844,  -844,  3121,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  9096,  9096,   153,  5210,   254,  8043,  8394,  7335,  -844,
    6779,  -844,  -844,  -844,   174,   240,   242,   275,   617,  9213,
    9096,  -844,   332,  -844,  1079,  -844,   435,  -844,  -844,   102,
     210,   311,  -844,   297,  9447,  -844,   323,  3381,    49,   415,
    -844,  9330,  9330,  -844,  -844,  6145,  9560,  9673,  9786,  6639,
    6639,  7196,  7196,    35,   108,  -844,  -844,   348,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,   465,
     506,  -844,   425,   580,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,   301,  -844,  -844,
    -844,  -844,   372,  9096,   476,  5356,  9096,  9096,  9096,  -844,
    9096,  -844,   407,  3381,   448,  -844,  -844,   408,   558,    39,
     359,   472,   362,   426,  -844,  -844,  -844,  6028,  -844,  7692,
    7692,  -844,  -844,  6262,  -844,  9330,   468,  -844,   430,   450,
    5502,  -844,  -844,  -844,   458,   467,   102,  -844,   618,   517,
     626,  7809,  -844,  5210,   469,   332,  -844,  1079,    10,   499,
    -844,    10,  9330,   481,   260,   326,  -844,   448,   485,   326,
    -844,    10,   569,   617,  9899,   490,  -844,   702,   715,   795,
     811,  -844,  -844,  -844,  -844,  -844,  -844,   502,  -844,   555,
     750,   313,   522,   754,   523,    83,   526,   815,   528,    91,
     574,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  6379,  9330,
    9330,  9330,  9330,  7809,  9330,  9330,  -844,  -844,  -844,   554,
    -844,  -844,  -844,  8511,  -844,  5210,  7455,   524,  8511,  9096,
    9096,  9096,  9096,  9096,  9096,  9096,  9096,  9096,  9096,  9096,
    9096,  9096,  9096,  9096,  9096,  9096,  9096,  9096,  9096,  9096,
    9096,  9096,  9096,  9096,  9096,  -844,  2205,  7692,  -844, 10188,
    4538,   435,   122,   122,  9330,  9330,   332,   642,   520,   616,
    -844,  -844,   877,   656,    69,    81,    88,   700,   782,  9330,
     352,  -844,   578,   907,  -844,  -844,  -844,  -844,    22,    45,
      54,    59,    85,   244,   318,   321,   343,  -844,  -844,  -844,
     357,  -844,   357,  -844,  -844,  -844,  -844, 10269,  -844,  -844,
    9213,  9213,  -844,  -844,   420,  -844,  -844,  -844,   479,  9096,
    9096,  7926,  -844,  -844, 10350,  7692, 10431,  9096,  9096,  8160,
    -844,    10,   560,  -844,  -844,    10,  -844,   564,   567,  -844,
     344,  -844,  -844,  -844,  -844,  -844,  7057,  -844,  9096,  5648,
     572, 10350, 10431,  9096,  1079,   577,    10,  -844,  -844,  6496,
     571,  -844,   435,  -844,  8277,  -844,  -844,  8394,  -844,  -844,
    -844,   430,   973,  -844,  -844,   581,  9899, 10512,  7692, 10593,
    1305,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,    57,  -844,  -844,   579,  -844,  -844,  -844,
     356,  -844,   592,  -844,  9096,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,    65,    65,  -844,  -844,    65,  9096,
    -844,   600,   602,  -844,  -844,    10,  9899,   608,  -844,  -844,
    -844,   631,  1905,  -844,  -844,   517,  3663,  3663,  3663,  3663,
    1098,  1098,  3804,  2411,  3663,  3663,  3522,  3522,  1005,  1005,
    2834,  1098,  1098,   939,   939,  1107,   378,   378,   517,   517,
     517,  4249,  3262,  4390,  3403,   467,   610,  -844,    10,   688,
    -844,   705,  -844,   467,  3967,   741,   747,  -844,  4684,   758,
    4976,    30,    30,   642,  8628,   741,   120, 10674,  7692, 10755,
    -844,   435,  -844,   973,  -844,  -844,  -844, 10836,  7692, 10269,
    4538,  9330,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  1739,  -844,  3099,  -844,  3381,  7057,  9096,  3240,
    -844,  9096,   448,  -844,   426,  2571,  3544,    10,   423,   454,
    -844,  -844,  -844,  -844,  7926,  8160,  -844,  -844,  9330,  3381,
     644,  -844,  -844,  -844,  3381,  5648,    24,  -844,    10,   326,
    9899,   581,   316,   546,    10,   412,   421,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  1102,  -844,  -844,  -844,  -844,  -844,
    1542,  -844,  -844,  -844,  -844,  -844,   660,  -844,   643,  9096,
    -844,   646,   733,   654,  -844,   662,   748,   675,   757,  -844,
    -844,   945,  -844,  -844,  -844,  -844,  -844,   517,  -844,  1195,
    5794,  -844,  -844,  5502,    65,  5794,   678,  8745,  -844,   581,
    9899,  9213,  9096,   697,  9213,  9213,  -844,   554,   467,   679,
     763,  9213,  9213,  -844,   554,   467,  -844,  -844,  8862,   809,
    -844,   533,  -844,   809,  -844,  -844,  -844,  -844,   741,   168,
    -844,    75,   151,    10,   330,   333,  9330,   332,  9330,  4538,
     884,   546,  -844,    10,   741,   344,   696,  7196,   696,  7196,
     696,   696,  -844,   108,   210,  -844,  9096,  -844,  -844,  -844,
    -844,  9096,  9096,   466,  9096,  9096,   706,   344,  -844,   712,
    -844,  -844,  -844,   433,  1102,   718,  -844,   719,    10,  -844,
      10,  -844,  9096,  1542,  -844,  -844,    95,  -844,  -844,  -844,
      50,  -844,  1542,  -844,  -844,  1552,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,    10,   727,   720,   737, 10012,
    -844,   738,   654,  -844,   740,   751,  -844,   710,   847,   746,
    5502,   875,  9096,   756,   581,  3381,  9096,  -844,  3381,  -844,
    3381,  -844,  -844,  -844,  9213,  -844,  3381,  -844,  3381,  -844,
    -844,   600,  -844,   796,  -844,  5093,   886,  -844,  9330,   741,
    -844,   741,  5794,  5794,  -844,  8979,  4830,   353,    30,  4538,
     332,   741,  -844,  -844,  -844,  1542,  4538,  1542,  -844,  4538,
    -844,  4538,  4538,  -844,  -844,  3381,  9096,  8160,  -844,  -844,
      10,   934,   760,  1245,  -844,   762,    87,  -844,  -844,  -844,
     768,   769,  -844,   654,  -844,   774,  -844,   775,  -844,   774,
    -844,   792,  -844, 10012,  1542,  -844,   859,   982,    95,  -844,
    -844,  1542,  -844,  1552,  -844,   981,  -844,  -844,   789,  -844,
     780,  3381,  -844,  3381, 10125,   122,  -844,  -844,  5794,  -844,
    -844,   122,  -844,  -844,   741,   741,  -844,   110,  -844,   741,
    -844,  -844,    10,   741,   332,   696,   741,   696,   741,   741,
    -844,   797,   934,   776,  -844,  -844,  5794,  5502,  -844,  1542,
    -844,  1552,  -844,  -844,  1552,  -844,  1552,  -844,  -844,  -844,
    -844,   982,  -844,   799,   800,  -844, 10917,  -844,   654,   804,
    -844,   806,   804,  -844,   371,  -844,  -844,  -844,   890,  -844,
    1037,   135,   167,   218,  4538,  -844,  4684,  -844,  -844,  -844,
    -844,  -844,  5794,  -844,  -844,  -844,  -844,  4538,  -844,  4538,
    -844,  -844,   934,   797,   934,   812,   940,   816,   774,   819,
     774,   774,  5911,  1542,  -844,  1552,  -844,   824,   827,  -844,
    1552,  -844,  1552,  -844,  -844,   981,  -844,   245, 10998,  7692,
   11079,   747,   533,   741,   741,   741,   797,   934,  -844,  -844,
    -844,  1552,  -844,  -844,  -844,   857,   804,   833,   804,   804,
    -844,    60,   253,    10,   269,   287,  -844,  -844,  -844,  -844,
    -844,   797,   774,  -844,  -844,  1552,  -844,  -844,  -844,   302,
    -844,   804,  -844
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,   362,   363,   364,   365,   366,
     367,     0,   355,   356,   357,   360,   358,   359,   361,   350,
     351,   352,   353,   301,   264,   264,   534,   533,   535,   536,
     641,     0,   641,    10,     0,   538,   537,   539,   623,   625,
     530,   529,   624,   532,   524,   525,   526,   527,   473,   544,
     545,     0,     0,     0,     0,   293,   652,   652,    84,   425,
     499,   497,   499,   501,   481,   493,   487,   495,     0,     0,
       0,     3,   639,     6,     9,    33,    44,    47,    55,   264,
      54,     0,    72,     0,    76,    86,     0,    52,   245,     0,
     289,     0,     0,   315,   318,   639,     0,     0,     0,     0,
       0,     0,     0,    56,   310,   278,   279,   472,   474,   280,
     281,   282,   284,   283,   285,   470,   471,   469,   522,   540,
     541,   286,     0,   287,    60,     5,     8,   167,   181,   168,
     169,   170,   171,   194,   164,   187,   177,   176,   197,   198,
     192,   175,   174,   166,   195,   199,   200,   179,   165,   182,
     186,   188,   180,   173,   189,   196,   191,   190,   183,   193,
     178,   163,   185,   184,   162,   172,   160,   161,   157,   158,
     159,   115,   117,   116,   152,   153,   148,   130,   131,   132,
     139,   136,   138,   133,   134,   154,   155,   140,   141,   145,
     149,   135,   137,   127,   128,   129,   142,   143,   144,   146,
     147,   150,   151,   156,   120,   122,   124,    26,   118,   119,
     121,   123,     0,     0,     0,     0,     0,     0,     0,   497,
       0,   259,     0,   246,   269,    70,   263,   652,     0,   540,
     541,     0,   287,   652,   617,    71,    69,   641,    68,     0,
     652,   450,    67,   641,   642,     0,     0,    21,   242,     0,
       0,   350,   351,   301,   304,   451,     0,   221,     0,   222,
     298,     0,    19,     0,     0,   639,    15,    18,   641,    74,
      14,   641,     0,     0,   645,   645,   247,     0,     0,   645,
     615,   641,     0,     0,     0,    82,   354,     0,    92,    93,
     100,   312,   426,   519,   518,   520,   517,     0,   516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     523,    51,   236,   237,   648,   649,     4,   650,   640,     0,
       0,     0,     0,     0,     0,     0,   455,   453,   440,    61,
     309,   434,   436,     0,    88,     0,    80,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   636,   448,   652,   635,   446,
       0,    53,     0,     0,     0,     0,   639,     0,   640,     0,
     379,   378,     0,     0,   540,   541,   287,   110,   111,     0,
       0,   113,   548,     0,   540,   541,   287,   330,   190,   183,
     193,   178,   157,   158,   159,   115,   116,   613,   332,   612,
       0,   335,     0,   338,   341,   638,   637,     0,   311,   475,
       0,     0,   125,   620,   298,   270,   622,   266,     0,     0,
       0,     0,   260,   268,   448,   652,   446,     0,     0,     0,
     261,   641,     0,   303,   265,   641,   255,   652,   652,   254,
     641,   308,    50,    23,    25,    24,     0,   305,     0,     0,
       0,   448,   446,     0,    17,     0,   641,   296,    13,   640,
      73,   292,   294,   299,   647,   646,   248,   647,   250,   300,
     616,     0,    99,   523,    90,    85,     0,   448,   652,   446,
     572,   503,   506,   504,   521,   500,   476,   498,   477,   478,
     502,   479,   480,     0,   483,   489,     0,   490,   485,   486,
       0,   491,     0,   492,     0,   651,     7,    27,    28,    29,
      30,    31,    48,    49,   652,   652,    58,    62,   652,     0,
      34,   274,     0,    43,   273,   641,     0,    78,    89,    46,
      45,     0,   201,   269,    42,   219,   226,   231,   232,   233,
     228,   230,   240,   241,   234,   235,   212,   213,   238,   239,
     641,   227,   229,   223,   224,   225,   214,   215,   216,   217,
     218,   626,   628,   627,   629,     0,   264,   445,   641,   626,
     628,   627,   629,     0,   264,     0,   652,   370,     0,   369,
       0,     0,     0,     0,     0,     0,   298,   448,   652,   446,
     323,   328,   110,   111,   112,   546,   326,   448,   652,   446,
       0,     0,   333,   634,   633,   344,   336,   347,   339,   342,
     626,   627,   264,    35,   203,    41,   211,     0,     0,   201,
     619,     0,   271,   267,   652,   626,   627,   641,   626,   627,
     618,   302,   643,   251,   256,   258,   307,    22,     0,   243,
       0,    32,   443,   441,   210,     0,    75,    16,   641,   645,
       0,    83,   630,    98,   641,   626,   627,   578,   575,   574,
     573,   576,   584,   593,     0,   604,   594,   608,   607,   603,
     572,   427,   571,   431,   577,   579,   580,   582,   557,   586,
     591,   652,   596,   652,   601,   557,   606,   557,     0,   555,
     507,     0,   482,   484,   494,   488,   496,   220,   417,   641,
       0,   415,   414,     0,   652,     0,   277,     0,    87,    81,
       0,     0,     0,     0,     0,     0,   449,    65,     0,     0,
     452,     0,     0,   447,    63,   652,   368,   290,   652,   652,
     461,   652,   371,   652,   373,   316,   372,   319,     0,     0,
     322,   630,   297,   641,   626,   627,     0,     0,     0,     0,
     110,   111,   114,   641,     0,   641,   550,     0,   550,     0,
     550,   550,   253,   437,    57,   252,     0,   126,   621,   272,
     262,     0,     0,   452,     0,     0,   652,   641,    11,     0,
     295,   249,    91,   452,     0,   391,   382,   384,   641,   380,
     641,   428,     0,     0,   564,   585,     0,   553,   611,   595,
       0,   554,     0,   567,   605,     0,   569,   609,   508,   512,
     513,   514,   505,   515,   413,   641,     0,   580,   398,   588,
     589,   652,   652,   599,   398,   398,   396,   419,     0,     0,
       0,     0,     0,   275,    79,   202,     0,    40,   208,    39,
     209,    66,   444,   644,     0,    37,   206,    38,   207,    64,
     442,   462,   463,   652,   464,     0,   652,   376,     0,     0,
     374,     0,     0,     0,   321,     0,     0,   452,     0,     0,
       0,     0,   452,   331,   614,   572,     0,   572,   345,     0,
     348,     0,     0,   438,   439,   204,     0,   257,   306,    20,
     641,     0,   389,     0,   581,     0,     0,   597,   556,   583,
     557,   557,   592,   652,   610,   557,   602,   557,   580,   557,
     509,     0,   416,     0,   404,   406,     0,   587,     0,   394,
     395,     0,   409,     0,   411,     0,   456,   454,     0,   435,
     276,   244,    36,   205,     0,     0,   466,   377,     0,    12,
     468,     0,   313,   314,     0,     0,   271,   652,   324,     0,
     547,   327,   641,     0,     0,   550,     0,   550,     0,     0,
     381,   392,     0,   387,   383,   430,     0,     0,   429,     0,
     560,     0,   562,   552,     0,   568,     0,   565,   570,   510,
     418,   598,   397,   398,   398,   298,   448,   590,   652,   398,
     600,   398,   398,   423,   641,   421,   424,    59,     0,   465,
       0,   540,   541,   287,     0,   467,     0,   317,   320,   458,
     459,   457,     0,   329,   549,   334,   551,     0,   337,     0,
     340,   343,     0,   390,     0,   385,     0,     0,   557,   557,
     557,   557,     0,     0,   401,     0,   403,   630,   297,   393,
       0,   410,     0,   407,   412,     0,   420,   298,   448,   652,
     446,   652,   652,     0,     0,     0,   388,     0,   433,   432,
     561,     0,   558,   563,   566,     0,   398,   398,   398,   398,
     422,   630,   297,   641,   626,   627,   460,   375,   325,   346,
     349,   386,   557,   511,   402,     0,   399,   405,   408,   452,
     559,   398,   400
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -844,  -844,  -844,  -366,  -844,    62,  -844,  -546,    34,  -844,
     507,  -844,    41,  -844,  -292,    29,   -64,   -65,  -844,  -572,
    -844,  2092,   -10,   881,  -161,    36,   -33,  -844,  -401,     1,
     983,  -315,   880,   -52,  -844,   -17,  -844,  -844,   146,  -844,
     744,  -844,  1888,  -844,   -45,   251,  -361,    92,    -6,  -844,
    -368,  -215,    61,  -844,  -318,   -19,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,     3,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,   184,  -362,  -536,   -63,
    -625,  -844,  -812,  -843,   206,   295,   335,  -844,  -418,  -844,
    -678,  -844,   -49,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
     235,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -101,  -844,
    -844,  -541,  -844,   -43,  -844,  -844,  -844,  -844,  -844,  -844,
     913,  -844,  -844,  -844,  -844,   726,  -844,  -844,  -844,  -844,
    -844,  -844,   803,   972,  -844,  -114,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,     4,  -844,    51,  -844,    -1,   672,  1187,
     504,  1367,  1482,  -844,  -844,  -605,  -844,  -386,  -543,  -597,
    -839,  -488,   232,  -698,   334,   -80,   241,   123,  -844,  -844,
    -844,  -107,  -720,  -601,   128,   255,  -844,  -549,  -844,  -400,
    -651,   961,  -844,  -844,    13,  -409,  -844,  -328,  -844,   663,
     -87,  -844,   -42,    -3,  -231,  -620,  -254,   -71,    14,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    71,    72,    73,   249,   585,   586,   265,
     266,   465,   267,   456,    75,    76,   372,    77,    78,   527,
     714,    79,    80,    81,   268,    82,    83,    84,   485,    85,
     222,   391,   392,   204,   205,   206,   207,   627,   208,   209,
      87,   458,   224,   273,   241,   773,   445,   446,   238,   239,
     226,   432,   447,   533,   534,    88,   370,   271,   272,   658,
     648,   374,   872,   375,   873,   756,  1022,   759,   757,   610,
     612,   766,   616,   768,   618,   770,   619,   771,   767,   965,
     769,   967,   258,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   737,   588,   745,   869,
     870,   383,   796,   797,   798,   992,   925,   825,   710,   711,
     826,  1004,  1005,   291,   292,   490,   801,   906,   681,   978,
     332,   528,   103,   104,   735,   728,   583,   575,   330,   525,
     524,   595,  1021,   739,   863,   945,   949,   105,   106,   107,
     108,   109,   110,   111,   303,   503,   112,   307,   113,   114,
     305,   309,   299,   297,   301,   495,   701,   700,   818,   920,
     989,  1042,   822,   115,   298,   116,   117,   118,   229,   230,
     121,   231,   232,   606,   758,   886,   887,   908,   804,   683,
     684,   685,   918,   687,   688,   689,   690,   830,   831,   691,
     692,   693,   694,   833,   834,   695,   696,   697,   698,   699,
     807,   410,   611,   278,   448,   234,   124,   652,   577,   615,
     609,   417,   316,   442,   443,   730,   476,   589,   378,   270
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     125,   317,   369,   418,   311,    89,   578,    89,   296,   221,
     221,   590,   451,   221,   247,   210,   416,   783,   440,   242,
     544,   478,   228,   228,   317,   480,   228,   245,   373,   248,
     640,   376,   233,   233,   328,   210,   233,   470,   576,   286,
     471,   584,   811,    74,   793,    74,   539,   408,   411,   413,
     414,   337,   748,   377,   276,   280,   747,    89,   971,   285,
     744,   287,   211,   633,   764,   286,   126,   310,   640,   275,
     279,   633,   228,   329,   637,   604,  -105,   286,   286,   286,
     227,   227,   211,   800,   227,   661,   318,   287,   264,   622,
     269,   974,   916,   650,   228,   228,  1006,  -101,   228,   382,
     393,   393,   466,  -105,   682,   909,   576,   713,   584,  -102,
     715,   225,   235,  -534,   866,   236,  -109,   274,   871,   976,
     371,   371,   905,   491,   371,   365,   415,   664,   865,  1033,
     594,   326,  -542,   877,   653,   719,  -533,   326,   587,  -354,
    -354,   436,     3,   882,   -73,  -535,   708,   921,  -108,   506,
    -536,  -101,   813,   677,   816,   851,   672,   512,   244,  -101,
     835,   653,   859,   889,   -87,   891,   892,   243,   673,  -534,
     492,   462,   493,   244,   535,   314,  -538,   678,   315,  -107,
     929,   930,   368,  -102,   587,   497,   799,   500,  -354,   504,
     709,  1066,  -533,   504,   317,   250,  -354,   676,   677,   507,
     489,  -535,  -626,   702,   977,  -105,  -536,   513,  -105,   -92,
     641,   328,   260,   881,   643,   -96,  1006,  -626,    89,   646,
     974,   -93,   678,   468,  1091,   433,   909,   221,  -100,   221,
     221,   433,  -538,   440,  -109,   656,   640,   753,   449,   327,
     228,   331,   228,   228,   240,   327,   228,   763,   228,   264,
     233,   484,   233,    89,   911,   517,   518,   519,   520,   916,
     -99,  -108,   983,   917,    89,   286,    89,   314,   530,  -107,
     315,   653,   450,   540,   452,   228,   633,   633,   481,   469,
    -101,   653,   483,  -101,   460,  -104,   909,   287,   962,   789,
     964,   -98,   762,  -627,   682,   599,   840,   264,   227,   269,
     227,   472,   464,  -106,   718,   317,   799,   902,   875,   836,
     591,   592,  -102,   314,   497,  -102,   315,   286,  -103,   844,
     302,    89,   228,   228,   228,   228,    89,   228,   228,   441,
    1000,   444,  1019,   959,   593,  -537,   228,   537,    89,   287,
     963,   228,   958,   966,   -96,   968,   969,  1049,   371,   371,
     371,   371,   909,   522,   523,   623,   625,   221,  -104,    74,
    1027,  -106,  1029,  -109,   521,   449,  -109,   980,   982,   264,
     228,   269,   985,    89,   987,   994,   988,   228,   228,   491,
     516,  -103,  1001,   499,   324,   325,   304,   876,   306,   703,
    -108,  -537,   228,  -108,   532,  -627,   703,  -291,  -107,   532,
     474,  -107,  -291,   371,   371,   791,   914,   602,   475,  -539,
     914,   603,  -528,   799,  -104,   799,  1020,  -104,   601,   780,
     862,   308,   491,   228,   228,   221,   492,   790,   493,   539,
    1039,   333,  -106,   449,  -531,  -106,   -96,   334,   228,   647,
     -95,   422,  1000,   338,   634,   433,   433,  -103,   613,   -97,
    -103,   339,  -543,   484,    61,   438,   -96,   125,  -626,   -96,
     210,   -94,    89,  1099,   -96,  -539,   477,   286,  -528,   492,
     -95,   493,    89,   -97,   475,   324,   325,   314,   221,  -102,
     315,  1064,  -109,  1065,   799,  1035,   449,   659,   640,   287,
    -531,   228,   244,   -94,  1077,  1070,  1072,  1073,  1074,   682,
      74,   682,   705,   484,   614,   365,   366,   211,   362,   363,
     364,  1055,   574,   463,   243,   582,   784,   286,   420,   244,
     746,   746,   712,   712,   836,   453,   712,   429,   914,   633,
     726,   836,   -95,   836,   884,   424,   454,   455,   733,   287,
    -108,   -97,   430,  -104,   799,   491,   799,   785,   431,  1100,
     868,   865,   -95,   -94,   367,   -95,   898,   723,  -542,   896,
     -95,   -97,   368,   582,   -97,   437,   439,   904,   491,   -97,
     727,   780,   457,   -94,  -106,   729,   -94,   772,   734,   799,
     574,   -94,   582,  1014,   740,  -101,  -103,   459,   221,  1016,
     339,    89,   492,    89,   493,   496,   449,   628,   221,  -543,
     237,   228,   832,   409,   409,   -92,   449,   574,   582,   240,
     777,   228,   467,    89,   228,   492,   774,   493,   494,   -72,
     775,   491,   741,   479,   743,   473,  -102,   792,   482,   829,
     486,   210,   433,   574,   729,   582,  -297,  -297,   501,   505,
     765,   286,   508,   836,   511,   836,   -93,   514,   365,   434,
     836,   228,   836,   125,   526,   749,   540,   786,    89,   847,
     849,   729,   594,   287,   538,   515,   855,   857,   492,   970,
     493,   496,   893,   421,   119,   596,   119,   787,   211,    44,
      45,    46,    47,   852,   600,  -297,   879,   484,  -627,   808,
     772,   808,   878,  -297,   880,   836,    74,   435,  1083,   913,
    -109,   286,   605,   642,   644,   368,   837,   645,   365,   461,
     651,   -87,   712,    89,   655,   888,    89,   890,    89,   463,
    -100,   660,   686,   287,   228,   704,   119,   228,   228,  -623,
     288,  1024,   653,   775,   228,   228,   864,   867,   706,   867,
    -269,   867,   717,   574,   838,   582,  -108,   839,   720,   841,
     729,   721,  -443,   574,   736,   582,   288,   435,   738,   228,
     729,   228,    89,   223,   223,   368,   -99,   223,   384,   394,
     394,   394,   394,   667,   742,   668,   669,   670,   671,   750,
     802,   731,   788,   803,   433,   371,   806,   371,   809,   942,
    -528,  -528,   365,   487,   810,   257,   259,   837,   732,   532,
     223,   223,   812,   814,   951,  -540,  -540,   746,  -104,   960,
     286,  -624,   817,   312,   313,   815,   491,   832,  -270,   846,
     491,   998,   837,   853,   832,  -106,   832,   865,   -95,   808,
     808,   667,   927,   668,   669,   670,   671,  -623,   885,  -528,
     923,   488,  -623,    89,   829,   -97,   897,  -528,   829,   368,
     899,   829,   922,   829,  -540,   935,   854,   228,   901,   903,
     936,   946,  -540,   492,   950,   493,   498,   492,    89,   493,
     502,   228,  -531,  -531,   938,    89,    89,   924,   928,    89,
     931,   491,    89,  -103,   937,  -541,  -541,   119,   939,    89,
     944,   933,    89,  1026,    89,    89,  -271,   371,   948,   947,
     972,  -287,  -287,   -94,   286,   975,   954,   955,   979,   981,
     957,   808,   686,  -630,   984,   986,  1034,   990,   995,  -624,
    -272,  -531,   119,  1060,  -624,   286,   991,  1007,   492,  -531,
     493,   509,   874,   119,  -541,   119,   832,  1032,   832,  1043,
    1045,   827,  -541,   832,  1050,   832,  1052,  1010,   883,  1057,
    -287,    89,  1067,  1068,  1069,   867,   288,   223,  -287,  1071,
     223,   223,   223,   829,   312,   829,  -626,   365,   597,  -627,
     829,  1093,   829,  1095,  -630,  -630,   657,   380,   397,    89,
      89,   223,  1015,   223,   223,    86,   860,    86,   832,   667,
     119,   668,   669,   670,   671,   119,   808,   365,   607,  1087,
     900,  1056,   819,   820,   824,   821,  1080,   119,   288,   894,
    1036,  1037,   339,    49,    50,   829,   598,    89,  1086,    89,
     419,  -630,   428,  -630,   368,    89,  -626,   352,   353,   794,
      89,  -630,    89,   510,   300,   686,  1003,    86,   668,   669,
     670,   671,   119,   828,   686,    89,   608,   912,  1061,   221,
    1062,   997,   993,   952,   368,   953,  1063,   449,   910,   740,
     867,   412,   228,  -298,  -298,   961,   359,   360,   361,   362,
     363,   364,   365,   996,     0,   617,  1075,   223,   339,   381,
     729,     0,   542,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,     0,
       0,   223,  -298,     0,     0,     0,     0,   686,     0,   686,
    -298,   608,   319,   320,   321,   322,   323,   365,  1058,   368,
       0,   119,     0,   360,   361,   362,   363,   364,  1017,  1018,
       0,   119,   574,  1023,     0,     0,   915,  1025,     0,   919,
    1028,     0,  1030,  1031,     0,     0,   827,   667,   288,   668,
     669,   670,   671,   827,   624,   626,     0,     0,     0,   932,
     934,   339,     0,   629,   223,   223,  1059,     0,     0,   223,
     339,   624,   626,   223,   368,     0,   352,   353,     0,   120,
       0,   120,     0,     0,     0,   352,   353,   794,    86,     0,
       0,     0,   649,   795,   574,     0,   582,   654,   288,     0,
       0,   686,     0,     0,     0,     0,     0,     0,   223,     0,
       0,   223,     0,   357,   358,   359,   360,   361,   362,   363,
     364,     0,   223,    86,     0,   360,   361,   362,   363,   364,
       0,   120,     0,     0,    86,   289,    86,  1088,  1089,  1090,
     667,     0,   668,   669,   670,   671,   672,     0,   707,     0,
     119,     0,   119,     0,     0,   999,     0,  1002,   673,     0,
       0,   289,     0,   223,     0,   827,     0,     0,     0,     0,
       0,     0,   119,   385,   395,   395,   395,   395,     0,     0,
     674,     0,     0,     0,     0,     0,   675,   676,   677,     0,
     667,    86,   668,   669,   670,   671,    86,     0,     0,     0,
       0,     0,     0,  1038,     0,  1040,     0,     0,    86,     0,
    1041,   541,   678,     0,     0,   679,     0,   119,  1044,  1046,
       0,     0,   288,     0,  1051,     0,  1053,  1054,   223,     0,
     794,     0,   223,   244,     0,     0,   973,     0,     0,     0,
       0,     0,   223,    86,     0,     0,     0,     0,     0,     0,
     667,     0,   668,   669,   670,   671,   672,     0,     0,   122,
       0,   122,   223,     0,     0,   223,     0,  1076,   673,  1078,
       0,     0,   119,     0,     0,   119,  1079,   119,   223,   223,
       0,     0,   288,     0,     0,     0,     0,     0,     0,     0,
     674,     0,   120,     0,     0,  1092,   675,   676,   677,     0,
       0,  1094,  1096,  1097,  1098,     0,     0,     0,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,  1101,
       0,   119,   678,   223,     0,   679,  1102,   120,     0,     0,
       0,     0,    86,     0,     0,     0,     0,   680,   120,     0,
     120,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,   223,     0,     0,     0,   629,   845,     0,   848,   850,
       0,   289,     0,     0,     0,   856,   858,     0,     0,     0,
       0,     0,   223,     0,   123,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   394,     0,     0,     0,   120,     0,     0,     0,     0,
     120,     0,   119,     0,     0,     0,     0,     0,     0,     0,
     895,     0,   120,   289,     0,   848,   850,     0,   856,   858,
       0,     0,     0,     0,     0,     0,   123,   119,     0,     0,
     290,     0,     0,     0,   119,   119,   223,     0,   119,     0,
       0,   119,     0,     0,     0,     0,     0,   120,   119,     0,
       0,   119,     0,   119,   119,     0,   290,     0,     0,     0,
       0,    86,     0,    86,     0,     0,     0,     0,   386,   396,
     396,     0,   122,     0,     0,     0,   223,     0,     0,     0,
     941,     0,     0,    86,     0,   394,     0,   667,   943,   668,
     669,   670,   671,   672,     0,     0,     0,   667,     0,   668,
     669,   670,   671,   672,     0,   673,  1011,   122,     0,   223,
     119,     0,     0,     0,     0,   673,     0,     0,   122,     0,
     122,     0,     0,     0,     0,     0,     0,   674,    86,     0,
     943,   223,     0,   675,   676,   677,   120,   674,   119,   119,
       0,     0,     0,     0,   676,   677,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   678,
       0,     0,   679,   289,     0,     0,     0,     0,     0,   678,
       0,     0,     0,     0,     0,   122,   119,     0,   119,     0,
     122,     0,     0,    86,   119,     0,    86,   123,    86,   119,
       0,   119,   122,     0,   541,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,   289,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,   122,     0,  -652,
       0,     0,    86,   123,     0,   123,     0,     0,     0,     0,
    -652,  -652,  -652,     0,     0,  -652,  -652,  -652,     0,  -652,
       0,     0,     0,     0,     0,     0,   290,     0,  -652,  -652,
       0,     0,     0,     0,     0,   120,     0,   120,     0,  -652,
    -652,     0,  -652,  -652,  -652,  -652,  -652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,     0,
     123,     0,     0,   223,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   290,     0,
       0,     0,     0,    86,     0,     0,   122,     0,     0,  -652,
    -652,     0,     0,     0,     0,     0,   122,     0,     0,     0,
       0,     0,   120,     0,     0,     0,     0,   289,    86,     0,
       0,     0,   123,  -652,     0,    86,    86,     0,     0,    86,
       0,     0,    86,     0,     0,     0,     0,     0,     0,    86,
       0,     0,    86,     0,    86,    86,  -652,  -652,     0,     0,
       0,   240,  -652,     0,  -652,     0,  -652,  -652,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,     0,
     120,     0,   120,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1009,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,   277,   120,     0,     0,     0,
       0,   123,   722,     0,     0,   122,     0,   122,     0,    86,
      86,     0,     0,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,   352,   353,     0,     0,    86,     0,    86,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
      86,     0,    86,     0,     0,     0,   395,     0,   290,     0,
       0,     0,   122,     0,     0,    86,   354,   120,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,     0,     0,     0,  -246,     0,     0,     0,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,   120,
     120,     0,     0,   120,     0,     0,   120,     0,     0,     0,
     123,     0,   123,   120,     0,     0,   120,   122,   120,   120,
     122,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,   425,   426,   427,     0,     0,     0,
     395,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
       0,  1012,     0,     0,     0,   120,     0,   123,     0,     0,
       0,     0,   290,   256,   256,     0,     0,     0,   256,   256,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   120,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,   823,     0,     0,     0,     0,   256,   256,
     256,     0,   123,     0,     0,   123,     0,   123,     0,     0,
       0,   120,   290,   120,     0,     0,     0,   122,     0,   120,
       0,     0,     0,     0,   120,     0,   120,     0,     0,     0,
       0,   531,     0,     0,     0,     0,   543,     0,     0,   120,
       0,     0,   122,     0,     0,     0,     0,     0,     0,   122,
     122,   123,     0,   122,     0,     0,   122,     0,     0,     0,
       0,     0,     0,   122,     0,     0,   122,     0,   122,   122,
     571,   572,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,   175,   176,   177,
     178,   179,   180,   181,   182,     0,     0,   183,   184,     0,
       0,   185,   186,   187,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   189,   190,   256,   256,
     256,   396,   256,     0,     0,   122,     0,     0,   630,   632,
       0,     0,   123,     0,     0,     0,     0,   277,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,     0,   201,
     202,     0,     0,   122,   122,     0,   203,   123,     0,     0,
       0,     0,     0,     0,   123,   123,     0,     0,   123,     0,
       0,   123,   632,     0,     0,   277,     0,     0,   123,     0,
       0,   123,     0,   123,   123,     0,   256,     0,     0,     0,
       0,   122,     0,   122,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,   122,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,   396,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,   716,     0,     0,
       0,     0,     0,     0,     0,     0,  1013,     0,   256,     0,
     123,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,     0,   123,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   543,     0,   339,   340,   341,   342,   343,   344,
     345,   346,     0,   348,   349,     0,   123,     0,   123,   352,
     353,     0,     0,     0,   123,     0,     0,     0,     0,   123,
       0,   123,     0,     0,     0,     0,   778,     0,     0,   779,
       0,   256,   256,   256,   123,     0,     0,     0,     0,   256,
     256,   256,   632,   277,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,   256,
       0,  -630,     0,     0,     0,     0,     0,   805,   256,     0,
       0,     0,  -630,  -630,  -630,     0,     0,  -630,  -630,  -630,
       0,  -630,     0,     0,     0,     0,     0,     0,     0,     0,
    -630,  -630,  -630,  -630,     0,   843,   256,     0,     0,     0,
       0,  -630,  -630,     0,  -630,  -630,  -630,  -630,  -630,     0,
       0,   256,     0,     0,     0,     0,   861,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,  -630,  -630,  -630,  -630,  -630,  -630,     0,     0,  -630,
    -630,  -630,  -630,     0,   781,  -630,     0,     0,     0,     0,
       0,  -630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -630,   256,     0,  -630,     0,
     907,  -105,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,  -630,  -630,  -630,     0,     0,     0,     0,  -630,  -630,
    -630,  -630,     0,     0,  -630,  -630,  -630,     0,  -630,  -630,
     256,     0,     0,   256,     0,     0,     0,     0,     0,     0,
     940,     0,     0,     0,     0,     0,   256,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,  -528,     0,
       0,     0,     0,   956,     0,     0,     0,     0,     0,  -528,
    -528,  -528,     0,     0,  -528,  -528,  -528,     0,  -528,     0,
       0,   256,     0,     0,     0,   277,  -528,     0,  -528,  -528,
    -528,     0,     0,     0,     0,     0,     0,     0,  -528,  -528,
       0,  -528,  -528,  -528,  -528,  -528,     0,     0,     0,   256,
       0,     0,   256,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,     0,     0,  -528,  -528,  -528,  -528,
       0,  -528,  -528,     0,     0,     0,     0,     0,  -528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,  -528,   256,   256,  -528,   256,   256,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,     0,     0,     0,   256,     0,  -528,  -528,  -528,     0,
       0,  -528,  -528,  -528,     0,  -528,  -528,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,   256,   352,   353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,     0,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,   256,   256,
       0,     0,     0,     0,     0,  -652,     4,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,     0,    13,
      14,     0,     0,     0,    15,   256,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,     0,   256,    30,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
      54,    55,     0,    56,    57,     0,    58,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -531,     0,     0,     0,     0,     0,     0,    68,    69,
      70,     0,  -531,  -531,  -531,     0,     0,  -531,  -531,  -531,
    -652,  -531,     0,  -652,     0,     0,   776,     0,     0,  -531,
       0,  -531,  -531,  -531,     0,     0,     0,     0,     0,     0,
       0,  -531,  -531,     0,  -531,  -531,  -531,  -531,  -531,     0,
       0,     0,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,   352,   353,     0,
       0,     0,     0,     0,  -531,  -531,  -531,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,     0,     0,  -531,
    -531,  -531,  -531,     0,  -531,  -531,     0,     0,     0,     0,
     354,  -531,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,  -531,     0,     0,  -531,     0,
       0,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,     0,     0,     0,     0,     0,  -531,
    -531,  -531,  -631,     0,  -531,  -531,  -531,     0,  -531,  -531,
       0,     0,     0,  -631,  -631,  -631,     0,     0,  -631,  -631,
    -631,     0,  -631,     0,     0,     0,     0,   722,     0,     0,
       0,  -631,  -631,  -631,  -631,     0,     0,     0,     0,     0,
       0,     0,  -631,  -631,     0,  -631,  -631,  -631,  -631,  -631,
       0,     0,     0,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,   352,   353,
       0,     0,     0,     0,     0,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,  -631,  -631,  -631,     0,     0,
    -631,  -631,  -631,  -631,     0,     0,  -631,     0,     0,     0,
       0,   354,  -631,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,  -631,     0,     0,  -631,
       0,     0,     0,  -631,  -631,  -631,  -631,  -631,  -631,  -631,
    -631,  -631,  -631,  -631,  -631,     0,     0,     0,     0,  -631,
    -631,  -631,  -631,  -632,     0,  -631,  -631,  -631,     0,  -631,
    -631,     0,     0,     0,  -632,  -632,  -632,     0,     0,  -632,
    -632,  -632,     0,  -632,     0,     0,     0,     0,     0,     0,
       0,     0,  -632,  -632,  -632,  -632,     0,     0,     0,     0,
       0,     0,     0,  -632,  -632,     0,  -632,  -632,  -632,  -632,
    -632,     0,     0,     0,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,   352,
     353,     0,     0,     0,     0,     0,  -632,  -632,  -632,  -632,
    -632,  -632,  -632,  -632,  -632,  -632,  -632,  -632,  -632,     0,
       0,  -632,  -632,  -632,  -632,     0,     0,  -632,     0,     0,
       0,     0,   354,  -632,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,  -632,     0,     0,
    -632,     0,     0,     0,  -632,  -632,  -632,  -632,  -632,  -632,
    -632,  -632,  -632,  -632,  -632,  -632,     0,     0,     0,     0,
    -632,  -632,  -632,  -632,  -297,     0,  -632,  -632,  -632,     0,
    -632,  -632,     0,     0,     0,  -297,  -297,  -297,     0,     0,
    -297,  -297,  -297,     0,  -297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -297,  -297,  -297,     0,     0,     0,
       0,     0,     0,     0,  -297,  -297,     0,  -297,  -297,  -297,
    -297,  -297,     0,     0,     0,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,  -653,  -653,     0,     0,
     352,   353,     0,     0,     0,     0,     0,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
       0,     0,  -297,  -297,  -297,  -297,     0,   782,  -297,     0,
       0,     0,     0,     0,  -297,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,  -297,     0,
       0,  -297,     0,     0,  -107,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,  -297,     0,     0,     0,
       0,     0,  -297,  -297,  -297,  -451,     0,  -297,  -297,  -297,
       0,  -297,  -297,     0,     0,     0,  -451,  -451,  -451,     0,
       0,  -451,  -451,  -451,     0,  -451,     0,     0,     0,     0,
       0,     0,     0,     0,  -451,  -451,  -451,     0,     0,     0,
       0,     0,     0,     0,     0,  -451,  -451,     0,  -451,  -451,
    -451,  -451,  -451,     0,     0,     0,   339,  -653,  -653,  -653,
    -653,   344,   345,     0,     0,  -653,  -653,     0,     0,     0,
       0,   352,   353,     0,     0,     0,     0,     0,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,     0,     0,  -451,  -451,  -451,  -451,     0,     0,  -451,
       0,     0,     0,     0,     0,  -451,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,  -451,
       0,     0,     0,     0,     0,     0,  -451,     0,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,     0,     0,
       0,     0,  -451,  -451,  -451,  -451,  -288,   240,  -451,  -451,
    -451,     0,  -451,  -451,     0,     0,     0,  -288,  -288,  -288,
       0,     0,  -288,  -288,  -288,     0,  -288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -288,  -288,  -288,     0,
       0,     0,     0,     0,     0,     0,  -288,  -288,     0,  -288,
    -288,  -288,  -288,  -288,     0,     0,     0,   339,   340,   341,
     342,   343,   344,   345,     0,     0,   348,   349,     0,     0,
       0,     0,   352,   353,     0,     0,     0,     0,     0,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,     0,     0,  -288,  -288,  -288,  -288,     0,     0,
    -288,     0,     0,     0,     0,     0,  -288,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
    -288,     0,     0,  -288,     0,     0,     0,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,     0,
       0,     0,     0,     0,  -288,  -288,  -288,  -441,     0,  -288,
    -288,  -288,     0,  -288,  -288,     0,     0,     0,  -441,  -441,
    -441,     0,     0,  -441,  -441,  -441,     0,  -441,     0,     0,
       0,     0,     0,     0,     0,     0,  -441,  -441,  -441,     0,
       0,     0,     0,     0,     0,     0,     0,  -441,  -441,     0,
    -441,  -441,  -441,  -441,  -441,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -441,  -441,  -441,  -441,  -441,  -441,  -441,  -441,  -441,  -441,
    -441,  -441,  -441,     0,     0,  -441,  -441,  -441,  -441,     0,
       0,  -441,     0,     0,     0,     0,     0,  -441,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -441,     0,     0,     0,     0,     0,     0,  -441,     0,
    -441,  -441,  -441,  -441,  -441,  -441,  -441,  -441,  -441,  -441,
       0,     0,     0,     0,  -441,  -441,  -441,  -441,  -304,  -441,
    -441,  -441,  -441,     0,  -441,  -441,     0,     0,     0,  -304,
    -304,  -304,     0,     0,  -304,  -304,  -304,     0,  -304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -304,  -304,
       0,     0,     0,     0,     0,     0,     0,     0,  -304,  -304,
       0,  -304,  -304,  -304,  -304,  -304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,     0,     0,  -304,  -304,  -304,  -304,
       0,     0,  -304,     0,     0,     0,     0,     0,  -304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -304,     0,     0,     0,     0,     0,     0,  -304,
       0,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,     0,     0,     0,     0,     0,  -304,  -304,  -304,  -630,
     237,  -304,  -304,  -304,     0,  -304,  -304,     0,     0,     0,
    -630,  -630,  -630,     0,     0,     0,  -630,  -630,     0,  -630,
       0,     0,     0,     0,     0,     0,     0,     0,  -630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -630,
    -630,     0,  -630,  -630,  -630,  -630,  -630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,  -630,  -630,  -630,  -630,     0,     0,  -630,  -630,  -630,
    -630,     0,   724,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -630,     0,     0,     0,     0,     0,  -105,
    -630,     0,  -630,  -630,  -630,  -630,  -630,  -630,  -630,  -630,
    -630,  -630,     0,     0,     0,     0,  -630,  -630,  -630,   -96,
    -297,     0,  -630,     0,  -630,     0,  -630,  -630,     0,     0,
       0,  -297,  -297,  -297,     0,     0,     0,  -297,  -297,     0,
    -297,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -297,  -297,     0,  -297,  -297,  -297,  -297,  -297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,  -297,     0,     0,  -297,  -297,
    -297,  -297,     0,   725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -297,     0,     0,     0,     0,     0,
    -107,  -297,     0,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,     0,     0,     0,     0,     0,  -297,  -297,
     -98,     0,     0,  -297,     0,  -297,     0,  -297,  -297,   261,
       0,     5,     6,     7,     8,     9,    10,    11,    12,  -652,
    -652,  -652,    13,    14,     0,     0,  -652,    15,     0,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,     0,     0,
      30,     0,     0,     0,     0,     0,    31,    32,   262,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,     0,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,    54,    55,     0,    56,    57,     0,    58,
       0,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -652,     0,   261,  -652,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,  -652,    13,    14,
       0,  -652,  -652,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,     0,     0,    30,     0,     0,     0,
       0,     0,    31,    32,   262,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
       0,    48,    49,    50,     0,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,    54,
      55,     0,    56,    57,     0,    58,     0,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -652,
       0,   261,  -652,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,  -652,    13,    14,     0,     0,  -652,    15,
    -652,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
       0,     0,    30,     0,     0,     0,     0,     0,    31,    32,
     262,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,     0,    48,    49,    50,
       0,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,    54,    55,     0,    56,    57,
       0,    58,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -652,     0,   261,  -652,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,  -652,
      13,    14,     0,     0,  -652,    15,     0,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     0,    30,     0,
       0,     0,     0,     0,    31,    32,   262,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,    54,    55,     0,    56,    57,     0,    58,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,   261,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,  -652,  -652,    13,    14,    68,
      69,    70,    15,     0,    16,    17,    18,    19,    20,    21,
      22,  -652,     0,     0,  -652,     0,    23,    24,    25,    26,
      27,    28,    29,     0,     0,    30,     0,     0,     0,     0,
       0,    31,    32,   262,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,     0,
      48,    49,    50,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,    54,    55,
       0,    56,    57,     0,    58,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,   261,     0,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,    13,    14,    68,    69,    70,    15,
       0,    16,    17,    18,    19,    20,    21,    22,  -652,     0,
       0,  -652,     0,    23,    24,    25,    26,    27,    28,    29,
       0,     0,    30,     0,     0,     0,     0,     0,    31,    32,
     262,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,     0,    48,    49,    50,
       0,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,   263,    55,     0,    56,    57,
       0,    58,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,     0,     0,     0,     0,
       0,     0,     0,  -652,     0,  -652,     0,   261,  -652,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
      13,    14,     0,     0,     0,    15,     0,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     0,    30,     0,
       0,     0,     0,     0,    31,    32,   262,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,    54,    55,     0,    56,    57,     0,    58,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    70,     0,     0,     0,     0,     0,     0,     0,  -652,
       0,  -652,     0,   261,  -652,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,    13,    14,     0,     0,
       0,    15,     0,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,     0,     0,    30,     0,     0,     0,     0,     0,
      31,    32,   262,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,     0,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,    54,    55,     0,
      56,    57,     0,    58,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    70,     0,     0,
    -652,     0,     0,     0,     0,     0,     0,  -652,     0,     4,
    -652,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,    13,    14,     0,     0,     0,    15,     0,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,     0,     0,
      30,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,     0,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,    54,    55,     0,    56,    57,     0,    58,
       0,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    69,    70,     0,     0,  -652,     0,     0,     0,
       0,     0,     0,  -652,     0,   261,  -652,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,  -652,    13,    14,
       0,     0,     0,    15,     0,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,     0,     0,    30,     0,     0,     0,
       0,     0,    31,    32,   262,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
       0,    48,    49,    50,     0,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,    54,
      55,     0,    56,    57,     0,    58,     0,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,   261,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,    13,    14,    68,    69,    70,
      15,     0,    16,    17,    18,    19,    20,    21,    22,  -652,
       0,     0,  -652,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,    30,     0,     0,     0,     0,     0,    31,
      32,   262,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,     0,    48,    49,
      50,     0,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,    54,    55,     0,    56,
      57,     0,    58,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,  -652,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,    12,     0,
       0,     0,    13,    14,    68,    69,    70,    15,     0,    16,
      17,    18,    19,    20,    21,    22,  -652,     0,     0,  -652,
       0,    23,    24,    25,    26,    27,    28,    29,     0,     0,
     212,     0,     0,     0,     0,     0,     0,    32,     0,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   213,
      44,    45,    46,    47,     0,    48,    49,    50,     0,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,   215,    55,     0,    56,    57,     0,   216,
     217,   218,    59,    60,   219,    62,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    12,     0,     0,     0,    13,
      14,    68,   220,    70,    15,     0,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,   244,     0,    23,    24,
      25,    26,    27,    28,    29,     0,     0,    30,     0,     0,
       0,     0,     0,     0,    32,     0,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,     0,     0,
     215,    55,     0,    56,    57,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    12,     0,     0,     0,    13,    14,    68,    69,
      70,    15,     0,    16,    17,    18,    19,    20,    21,    22,
     314,     0,     0,   315,     0,    23,    24,    25,    26,    27,
      28,    29,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,     0,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,     0,   215,    55,     0,
      56,    57,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,    13,    14,    68,    69,    70,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
     244,     0,    23,    24,    25,    26,    27,    28,    29,     0,
       0,    30,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,     0,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    54,    55,     0,    56,    57,     0,
      58,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
      13,    14,    68,    69,    70,    15,     0,    16,    17,    18,
      19,    20,    21,    22,   515,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     0,    30,     0,
       0,     0,     0,     0,    31,    32,   262,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,    54,    55,     0,    56,    57,     0,    58,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   515,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,     0,   154,   155,   156,   398,   399,   400,   401,   161,
     162,   163,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   402,   403,   404,   405,   172,    40,    41,   406,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,     0,
       0,   183,   184,     0,     0,   185,   186,   187,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     0,   201,   202,     0,     0,     0,     0,     0,
     203,   407,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   293,   294,   173,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,     0,
       0,   183,   184,     0,     0,   185,   186,   187,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     0,   201,   202,     0,     0,     0,     0,     0,
     203,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   246,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,     0,     0,
     183,   184,     0,     0,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,   201,   202,     0,     0,     0,     0,     0,   203,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,     0,     0,   183,
     184,     0,     0,   185,   186,   187,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       0,   201,   202,     0,     0,     0,     0,     0,   203,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,     0,   183,   184,
       0,     0,   185,   186,   187,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,     0,     0,     0,     0,     0,   203,     5,     6,
       7,     8,     9,    10,     0,    12,     0,     0,     0,    13,
      14,     0,     0,     0,    15,     0,    16,    17,    18,   251,
     252,    21,    22,     0,     0,     0,     0,     0,   253,   254,
     255,    26,    27,    28,    29,     0,     0,   212,     0,     0,
       0,     0,     0,     0,   281,     0,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
     215,    55,     0,    56,    57,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    12,     0,     0,   283,    13,
      14,     0,     0,     0,    15,   284,    16,    17,    18,   251,
     252,    21,    22,     0,     0,     0,     0,     0,   253,   254,
     255,    26,    27,    28,    29,     0,     0,   212,     0,     0,
       0,     0,     0,     0,   281,     0,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
     215,    55,     0,    56,    57,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,   283,    13,
      14,     0,     0,     0,    15,   536,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,     0,     0,    30,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
      54,    55,     0,    56,    57,     0,    58,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    12,     0,     0,     0,    13,    14,    68,    69,
      70,    15,     0,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,     0,     0,   212,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   213,    44,    45,    46,    47,     0,    48,
      49,    50,     0,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,     0,   215,    55,     0,
      56,    57,     0,   216,   217,   218,    59,    60,   219,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,    13,    14,    68,   220,    70,    15,     0,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,     0,
       0,    30,     0,     0,     0,     0,     0,    31,    32,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,     0,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    54,    55,     0,    56,    57,     0,
      58,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,    12,     0,     0,     0,
      13,    14,    68,    69,    70,    15,     0,    16,    17,    18,
     251,   252,    21,    22,     0,     0,     0,     0,     0,   253,
     254,   255,    26,    27,    28,    29,     0,     0,   212,     0,
       0,     0,     0,     0,     0,    32,     0,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   213,    44,    45,
      46,    47,     0,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,     0,
       0,   215,    55,     0,    56,    57,     0,   631,   217,   218,
      59,    60,   219,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    12,     0,     0,     0,    13,    14,    68,
     220,    70,    15,     0,    16,    17,    18,   251,   252,    21,
      22,     0,     0,     0,     0,     0,   253,   254,   255,    26,
      27,    28,    29,     0,     0,   212,     0,     0,     0,     0,
       0,     0,    32,     0,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   213,    44,    45,    46,    47,     0,
      48,    49,    50,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,   215,    55,
       0,    56,    57,     0,   216,   217,     0,    59,    60,   219,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
      12,     0,     0,     0,    13,    14,    68,   220,    70,    15,
       0,    16,    17,    18,   251,   252,    21,    22,     0,     0,
       0,     0,     0,   253,   254,   255,    26,    27,    28,    29,
       0,     0,   212,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   213,    44,    45,    46,    47,     0,    48,    49,    50,
       0,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,   215,    55,     0,    56,    57,
       0,     0,   217,   218,    59,    60,   219,    62,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    12,     0,     0,
       0,    13,    14,    68,   220,    70,    15,     0,    16,    17,
      18,   251,   252,    21,    22,     0,     0,     0,     0,     0,
     253,   254,   255,    26,    27,    28,    29,     0,     0,   212,
       0,     0,     0,     0,     0,     0,    32,     0,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   213,    44,
      45,    46,    47,     0,    48,    49,    50,     0,    51,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
       0,     0,   215,    55,     0,    56,    57,     0,   631,   217,
       0,    59,    60,   219,    62,    63,    64,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,     0,    12,     0,     0,     0,    13,    14,
      68,   220,    70,    15,     0,    16,    17,    18,   251,   252,
      21,    22,     0,     0,     0,     0,     0,   253,   254,   255,
      26,    27,    28,    29,     0,     0,   212,     0,     0,     0,
       0,     0,     0,    32,     0,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   213,    44,    45,    46,    47,
       0,    48,    49,    50,     0,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,   215,
      55,     0,    56,    57,     0,     0,   217,     0,    59,    60,
     219,    62,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
       0,    12,     0,     0,     0,    13,    14,    68,   220,    70,
      15,     0,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,   212,     0,     0,     0,     0,     0,     0,
      32,     0,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,     0,    48,    49,
      50,     0,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,   215,    55,     0,    56,
      57,     0,   529,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,    12,     0,
       0,     0,    13,    14,    68,   220,    70,    15,     0,    16,
      17,    18,   251,   252,    21,    22,     0,     0,     0,     0,
       0,   253,   254,   255,    26,    27,    28,    29,     0,     0,
     212,     0,     0,     0,     0,     0,     0,    32,     0,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,     0,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,   215,    55,     0,    56,    57,     0,   216,
       0,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    12,     0,     0,     0,    13,
      14,    68,   220,    70,    15,     0,    16,    17,    18,   251,
     252,    21,    22,     0,     0,     0,     0,     0,   253,   254,
     255,    26,    27,    28,    29,     0,     0,   212,     0,     0,
       0,     0,     0,     0,    32,     0,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,     0,     0,
     215,    55,     0,    56,    57,     0,   842,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    12,     0,     0,     0,    13,    14,    68,   220,
      70,    15,     0,    16,    17,    18,   251,   252,    21,    22,
       0,     0,     0,     0,     0,   253,   254,   255,    26,    27,
      28,    29,     0,     0,   212,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,     0,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,     0,   215,    55,     0,
      56,    57,     0,   529,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,     0,    12,
       0,     0,     0,    13,    14,    68,   220,    70,    15,     0,
      16,    17,    18,   251,   252,    21,    22,     0,     0,     0,
       0,     0,   253,   254,   255,    26,    27,    28,    29,     0,
       0,   212,     0,     0,     0,     0,     0,     0,    32,     0,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,     0,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,   215,    55,     0,    56,    57,     0,
     631,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,    12,     0,     0,     0,
      13,    14,    68,   220,    70,    15,     0,    16,    17,    18,
     251,   252,    21,    22,     0,     0,     0,     0,     0,   253,
     254,   255,    26,    27,    28,    29,     0,     0,   212,     0,
       0,     0,     0,     0,     0,    32,     0,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,     0,
       0,   215,    55,     0,    56,    57,     0,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    12,     0,     0,     0,    13,    14,    68,
     220,    70,    15,     0,    16,    17,    18,    19,    20,    21,
      22,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,     0,     0,   212,     0,     0,     0,     0,
       0,     0,    32,     0,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,     0,
      48,    49,    50,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,   215,    55,
       0,    56,    57,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
      12,     0,     0,     0,    13,    14,    68,   220,    70,    15,
       0,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,     0,    23,    24,    25,    26,    27,    28,    29,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,     0,    48,    49,    50,
       0,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,   215,    55,     0,    56,    57,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    12,     0,     0,
       0,    13,    14,    68,    69,    70,    15,     0,    16,    17,
      18,   251,   252,    21,    22,     0,     0,     0,     0,     0,
     253,   254,   255,    26,    27,    28,    29,     0,     0,   212,
       0,     0,     0,     0,     0,     0,   281,     0,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,     0,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,   335,    55,     0,    56,    57,     0,   336,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
      12,     0,     0,     0,    13,    14,     0,     0,     0,    15,
     283,    16,    17,    18,   251,   252,    21,    22,     0,     0,
       0,     0,     0,   253,   254,   255,    26,    27,    28,    29,
       0,     0,   212,     0,     0,     0,     0,     0,     0,   281,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,     0,    48,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   379,     0,     0,    54,    55,     0,    56,    57,
       0,    58,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    12,     0,     0,     0,    13,    14,     0,
       0,     0,    15,   283,    16,    17,    18,   251,   252,    21,
      22,     0,     0,     0,     0,     0,   253,   254,   255,    26,
      27,    28,    29,     0,     0,   212,     0,     0,     0,     0,
       0,     0,   281,     0,     0,    35,    36,    37,   387,    39,
      40,    41,   388,    43,     0,    44,    45,    46,    47,     0,
      48,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   389,     0,     0,     0,   390,     0,     0,   215,    55,
       0,    56,    57,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,    12,     0,     0,     0,
      13,    14,     0,     0,     0,    15,   283,    16,    17,    18,
     251,   252,    21,    22,     0,     0,     0,     0,     0,   253,
     254,   255,    26,    27,    28,    29,     0,     0,   212,     0,
       0,     0,     0,     0,     0,   281,     0,     0,    35,    36,
      37,   387,    39,    40,    41,   388,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   390,     0,
       0,   215,    55,     0,    56,    57,     0,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     5,     6,     7,     8,     9,    10,     0,    12,
       0,     0,     0,    13,    14,     0,     0,     0,    15,   283,
      16,    17,    18,   251,   252,    21,    22,     0,     0,     0,
       0,     0,   253,   254,   255,    26,    27,    28,    29,     0,
       0,   212,     0,     0,     0,     0,     0,     0,   281,     0,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,   335,    55,     0,    56,    57,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    12,     0,     0,     0,    13,    14,     0,     0,
       0,    15,   283,    16,    17,    18,   251,   252,    21,    22,
       0,     0,     0,     0,     0,   253,   254,   255,    26,    27,
      28,    29,     0,     0,   212,     0,     0,     0,     0,     0,
       0,   281,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   926,     0,     0,   215,    55,     0,
      56,    57,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    12,     0,     0,     0,    13,
      14,     0,     0,     0,    15,   283,    16,    17,    18,   251,
     252,    21,    22,     0,     0,     0,     0,     0,   253,   254,
     255,    26,    27,    28,    29,     0,     0,   212,     0,     0,
       0,     0,     0,     0,   281,     0,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1008,     0,     0,
     215,    55,     0,    56,    57,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,   579,   580,     0,     0,   581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,   174,
     175,   176,   177,   178,   179,   180,   181,   182,     0,     0,
     183,   184,     0,     0,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,   201,   202,   620,   580,     0,     0,   621,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,     0,
       0,   183,   184,     0,     0,   185,   186,   187,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     0,   201,   202,   635,   572,     0,     0,   636,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,   180,   181,   182,
       0,     0,   183,   184,     0,     0,   185,   186,   187,   188,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,     0,   201,   202,   638,   580,     0,     0,
     639,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,   175,   176,   177,   178,   179,   180,   181,
     182,     0,     0,   183,   184,     0,     0,   185,   186,   187,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,   201,   202,   662,   572,     0,
       0,   663,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,     0,     0,   183,   184,     0,     0,   185,   186,
     187,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,   201,   202,   665,   580,
       0,     0,   666,   203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   174,   175,   176,   177,   178,   179,
     180,   181,   182,     0,     0,   183,   184,     0,     0,   185,
     186,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,     0,   201,   202,   751,
     572,     0,     0,   752,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,     0,     0,   183,   184,     0,     0,
     185,   186,   187,   188,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,     0,   201,   202,
     754,   580,     0,     0,   755,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,   175,   176,   177,
     178,   179,   180,   181,   182,     0,     0,   183,   184,     0,
       0,   185,   186,   187,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,     0,   201,
     202,   760,   572,     0,     0,   761,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,     0,   183,   184,
       0,     0,   185,   186,   187,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
     201,   202,  1047,   572,     0,     0,  1048,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   175,
     176,   177,   178,   179,   180,   181,   182,     0,     0,   183,
     184,     0,     0,   185,   186,   187,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       0,   201,   202,  1081,   572,     0,     0,  1082,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,   176,   177,   178,   179,   180,   181,   182,     0,     0,
     183,   184,     0,     0,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,   201,   202,  1084,   580,     0,     0,  1085,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,     0,
       0,   183,   184,     0,     0,   185,   186,   187,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     0,   201,   202,     0,     0,     0,     0,     0,
     203
};

static const yytype_int16 yycheck[] =
{
       2,    72,    89,   104,    69,     2,   367,     4,    60,    19,
      20,   373,   243,    23,    31,    11,   103,   637,   233,    25,
     338,   275,    19,    20,    95,   279,    23,    30,    92,    32,
     439,    95,    19,    20,    79,    31,    23,   268,   366,    58,
     271,   369,   693,     2,   664,     4,   338,    99,   100,   101,
     102,    84,   593,    95,    56,    57,   592,    54,   901,    58,
      30,    58,    11,   431,   610,    84,     4,    68,   477,    56,
      57,   439,    69,    79,   435,   390,    16,    96,    97,    98,
      19,    20,    31,   680,    23,   486,    72,    84,    54,   417,
      54,   903,   812,   459,    91,    92,   935,    28,    95,    96,
      97,    98,   263,    28,   490,   803,   434,   525,   436,    28,
     528,    19,    20,    91,   739,    23,    28,    56,   743,    32,
      91,    92,   800,    66,    95,    90,    91,   488,    18,   972,
      20,    29,    93,   753,   462,   536,    91,    29,    16,    90,
      91,   228,     0,   763,   120,    91,    81,   825,    28,    66,
      91,    16,   695,   103,   697,   727,    61,    66,   148,   120,
     709,   489,   734,   768,   140,   770,   771,   142,    73,   147,
     113,   258,   115,   148,   335,   145,    91,   127,   148,    28,
     831,   832,   147,    16,    16,   299,   674,   301,   139,   303,
     125,  1034,   147,   307,   265,   137,   147,   102,   103,   116,
     287,   147,   142,   146,   117,   145,   147,   116,   148,   140,
     441,   256,    59,   759,   445,   140,  1055,   142,   215,   450,
    1032,   140,   127,   265,  1067,   227,   924,   237,   140,   239,
     240,   233,   147,   448,    16,   466,   645,   598,   240,   137,
     237,    31,   239,   240,   142,   137,   243,   608,   245,   215,
     237,   284,   239,   250,   803,   319,   320,   321,   322,   979,
     140,    16,   913,   812,   261,   284,   263,   145,   333,    16,
     148,   599,   243,   338,   245,   272,   644,   645,   281,   265,
     145,   609,   283,   148,   250,    16,   984,   284,   885,   655,
     887,   140,   607,   142,   680,   382,   714,   263,   237,   263,
     239,   272,   261,    16,   535,   376,   794,   795,   140,   709,
     374,   375,   145,   145,   428,   148,   148,   336,    16,   720,
     146,   318,   319,   320,   321,   322,   323,   324,   325,   237,
     931,   239,   957,   879,   376,    91,   333,   336,   335,   336,
     886,   338,   878,   889,    28,   891,   892,   998,   319,   320,
     321,   322,  1050,   324,   325,   420,   421,   367,    28,   318,
     965,    28,   967,   145,   323,   367,   148,   910,   911,   335,
     367,   335,   915,   370,   917,   924,   919,   374,   375,    66,
     318,    28,   931,    70,    40,    41,   146,   749,   146,   503,
     145,   147,   389,   148,   333,   142,   510,   143,   145,   338,
     140,   148,   148,   374,   375,   659,   806,    55,   148,    91,
     810,    59,    91,   901,   145,   903,   957,   148,   389,   634,
     738,   146,    66,   420,   421,   435,   113,   658,   115,   721,
     979,   120,   145,   435,    91,   148,   120,   140,   435,   456,
      28,   140,  1043,   120,   431,   447,   448,   145,    91,    28,
     148,    73,    93,   486,   106,    93,   140,   459,   142,   143,
     456,    28,   459,  1083,   148,   147,   140,   486,   147,   113,
     140,   115,   469,   140,   148,    40,    41,   145,   488,   120,
     148,  1027,   120,  1029,   972,   973,   488,   474,   897,   486,
     147,   488,   148,   140,  1043,  1038,  1039,  1040,  1041,   885,
     459,   887,   146,   536,   147,    90,    91,   456,   130,   131,
     132,   140,   366,    93,   142,   369,    93,   536,    93,   148,
     591,   592,   524,   525,   924,    57,   528,   120,   928,   897,
     575,   931,   120,   933,   765,    59,    68,    69,   583,   536,
     120,   120,    94,   120,  1032,    66,  1034,    93,   140,  1092,
      17,    18,   140,   120,   139,   143,   787,   560,    93,    93,
     148,   140,   147,   417,   143,    93,   140,   798,    66,   148,
     576,   786,   142,   140,   120,   578,   143,   622,   584,  1067,
     434,   148,   436,   945,   586,   120,   120,   137,   598,   951,
      73,   588,   113,   590,   115,   116,   598,   118,   608,    93,
     142,   598,   709,    99,   100,   140,   608,   461,   462,   142,
     627,   608,   143,   610,   611,   113,   622,   115,   116,   120,
     622,    66,   588,   138,   590,   144,   120,   660,    59,   709,
     140,   627,   634,   487,   637,   489,    90,    91,   116,   116,
     611,   660,   116,  1043,   116,  1045,   140,    73,    90,    91,
    1050,   648,  1052,   655,   100,   594,   721,   644,   655,   724,
     725,   664,    20,   660,   140,   145,   731,   732,   113,   900,
     115,   116,   773,    93,     2,    59,     4,   648,   627,    62,
      63,    64,    65,   728,    28,   139,   757,   720,   142,   691,
     735,   693,   756,   147,   758,  1095,   655,   139,  1059,   806,
     120,   720,   124,   143,   140,   147,   709,   140,    90,    91,
     138,   140,   714,   710,   137,   767,   713,   769,   715,    93,
     140,   140,   490,   720,   721,   146,    54,   724,   725,    29,
      58,   962,  1060,   735,   731,   732,   738,   739,   146,   741,
     140,   743,   140,   597,   710,   599,   120,   713,   140,   715,
     753,   120,   142,   607,    13,   609,    84,   139,    11,   756,
     763,   758,   759,    19,    20,   147,   140,    23,    96,    97,
      98,    99,   100,    55,    16,    57,    58,    59,    60,   595,
     120,    93,   138,   140,   786,   756,   140,   758,    55,   854,
      90,    91,    90,    91,   140,    51,    52,   800,    93,   738,
      56,    57,   140,    55,   868,    90,    91,   878,   120,   880,
     829,    29,    55,    69,    70,   140,    66,   924,   140,   122,
      66,   928,   825,   144,   931,   120,   933,    18,   140,   831,
     832,    55,   829,    57,    58,    59,    60,   137,   142,   139,
     120,   139,   142,   840,   924,   140,   140,   147,   928,   147,
     138,   931,   125,   933,   139,   145,    93,   854,   140,   140,
      13,   863,   147,   113,   866,   115,   116,   113,   865,   115,
     116,   868,    90,    91,   840,   872,   873,   140,   140,   876,
     140,    66,   879,   120,   138,    90,    91,   215,    13,   886,
      94,   140,   889,   964,   891,   892,   140,   868,    12,   865,
     140,    90,    91,   140,   923,   143,   872,   873,   140,   140,
     876,   913,   680,    29,   140,   140,   140,   125,    59,   137,
     140,   139,   250,  1010,   142,   944,   923,   138,   113,   147,
     115,   116,   748,   261,   139,   263,  1043,   140,  1045,   140,
     140,   709,   147,  1050,   140,  1052,   140,   944,   764,    59,
     139,   948,   140,    13,   138,   957,   284,   213,   147,   140,
     216,   217,   218,  1043,   220,  1045,   142,    90,    91,   142,
    1050,   114,  1052,   140,    90,    91,   469,    96,    98,   976,
     977,   237,   948,   239,   240,     2,   735,     4,  1095,    55,
     318,    57,    58,    59,    60,   323,   998,    90,    91,  1062,
     794,  1004,    57,    58,   709,    60,  1055,   335,   336,   774,
     976,   977,    73,    68,    69,  1095,   139,  1014,  1061,  1016,
     107,   137,   219,   139,   147,  1022,   142,    88,    89,    95,
    1027,   147,  1029,   307,    62,   803,    55,    54,    57,    58,
      59,    60,   370,   709,   812,  1042,   139,   806,  1014,  1059,
    1016,   928,   924,   869,   147,   871,  1022,  1059,   803,  1061,
    1062,   100,  1059,    90,    91,   881,   127,   128,   129,   130,
     131,   132,    90,    91,    -1,   412,  1042,   333,    73,    96,
    1083,    -1,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,    -1,
      -1,   367,   139,    -1,    -1,    -1,    -1,   885,    -1,   887,
     147,   139,    43,    44,    45,    46,    47,    90,    91,   147,
      -1,   459,    -1,   128,   129,   130,   131,   132,   954,   955,
      -1,   469,   996,   959,    -1,    -1,   812,   963,    -1,   815,
     966,    -1,   968,   969,    -1,    -1,   924,    55,   486,    57,
      58,    59,    60,   931,   420,   421,    -1,    -1,    -1,   834,
     835,    73,    -1,   429,   430,   431,   139,    -1,    -1,   435,
      73,   437,   438,   439,   147,    -1,    88,    89,    -1,     2,
      -1,     4,    -1,    -1,    -1,    88,    89,    95,   215,    -1,
      -1,    -1,   458,   101,  1058,    -1,  1060,   463,   536,    -1,
      -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,   477,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   488,   250,    -1,   128,   129,   130,   131,   132,
      -1,    54,    -1,    -1,   261,    58,   263,  1063,  1064,  1065,
      55,    -1,    57,    58,    59,    60,    61,    -1,   514,    -1,
     588,    -1,   590,    -1,    -1,   931,    -1,   933,    73,    -1,
      -1,    84,    -1,   529,    -1,  1043,    -1,    -1,    -1,    -1,
      -1,    -1,   610,    96,    97,    98,    99,   100,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,
      55,   318,    57,    58,    59,    60,   323,    -1,    -1,    -1,
      -1,    -1,    -1,   979,    -1,   981,    -1,    -1,   335,    -1,
     986,   338,   127,    -1,    -1,   130,    -1,   655,   993,   994,
      -1,    -1,   660,    -1,   999,    -1,  1001,  1002,   594,    -1,
      95,    -1,   598,   148,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,   608,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    57,    58,    59,    60,    61,    -1,    -1,     2,
      -1,     4,   628,    -1,    -1,   631,    -1,  1043,    73,  1045,
      -1,    -1,   710,    -1,    -1,   713,  1052,   715,   644,   645,
      -1,    -1,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,   215,    -1,    -1,  1071,   101,   102,   103,    -1,
      -1,  1076,  1077,  1078,  1079,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1095,
      -1,   759,   127,   689,    -1,   130,  1101,   250,    -1,    -1,
      -1,    -1,   459,    -1,    -1,    -1,    -1,   142,   261,    -1,
     263,    -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   717,    -1,    -1,    -1,   721,   722,    -1,   724,   725,
      -1,   284,    -1,    -1,    -1,   731,   732,    -1,    -1,    -1,
      -1,    -1,   738,    -1,     2,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   829,    -1,    -1,    -1,   318,    -1,    -1,    -1,    -1,
     323,    -1,   840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     776,    -1,   335,   336,    -1,   781,   782,    -1,   784,   785,
      -1,    -1,    -1,    -1,    -1,    -1,    54,   865,    -1,    -1,
      58,    -1,    -1,    -1,   872,   873,   802,    -1,   876,    -1,
      -1,   879,    -1,    -1,    -1,    -1,    -1,   370,   886,    -1,
      -1,   889,    -1,   891,   892,    -1,    84,    -1,    -1,    -1,
      -1,   588,    -1,   590,    -1,    -1,    -1,    -1,    96,    97,
      98,    -1,   215,    -1,    -1,    -1,   842,    -1,    -1,    -1,
     846,    -1,    -1,   610,    -1,   923,    -1,    55,   854,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    55,    -1,    57,
      58,    59,    60,    61,    -1,    73,   944,   250,    -1,   875,
     948,    -1,    -1,    -1,    -1,    73,    -1,    -1,   261,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    95,   655,    -1,
     896,   897,    -1,   101,   102,   103,   459,    95,   976,   977,
      -1,    -1,    -1,    -1,   102,   103,   469,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,   130,   486,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,   318,  1014,    -1,  1016,    -1,
     323,    -1,    -1,   710,  1022,    -1,   713,   215,   715,  1027,
      -1,  1029,   335,    -1,   721,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1042,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   370,    -1,     0,
      -1,    -1,   759,   261,    -1,   263,    -1,    -1,    -1,    -1,
      11,    12,    13,    -1,    -1,    16,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,   588,    -1,   590,    -1,    40,
      41,    -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,
     318,    -1,    -1,  1059,    -1,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,   336,    -1,
      -1,    -1,    -1,   840,    -1,    -1,   459,    -1,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,
      -1,    -1,   655,    -1,    -1,    -1,    -1,   660,   865,    -1,
      -1,    -1,   370,   114,    -1,   872,   873,    -1,    -1,   876,
      -1,    -1,   879,    -1,    -1,    -1,    -1,    -1,    -1,   886,
      -1,    -1,   889,    -1,   891,   892,   137,   138,    -1,    -1,
      -1,   142,   143,    -1,   145,    -1,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,
     713,    -1,   715,    -1,    -1,    -1,    -1,   720,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,    -1,
      -1,   948,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   459,    -1,    -1,    -1,    57,   759,    -1,    -1,    -1,
      -1,   469,    47,    -1,    -1,   588,    -1,   590,    -1,   976,
     977,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    -1,    88,    89,    -1,    -1,  1014,    -1,  1016,
      -1,    -1,    -1,    -1,    -1,  1022,    -1,    -1,    -1,    -1,
    1027,    -1,  1029,    -1,    -1,    -1,   829,    -1,   536,    -1,
      -1,    -1,   655,    -1,    -1,  1042,   121,   840,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,   872,
     873,    -1,    -1,   876,    -1,    -1,   879,    -1,    -1,    -1,
     588,    -1,   590,   886,    -1,    -1,   889,   710,   891,   892,
     713,    -1,   715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,   216,   217,   218,    -1,    -1,    -1,
     923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   759,    -1,    -1,    -1,
      -1,   944,    -1,    -1,    -1,   948,    -1,   655,    -1,    -1,
      -1,    -1,   660,    51,    52,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,   976,   977,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,   701,    -1,    -1,    -1,    -1,    96,    97,
      98,    -1,   710,    -1,    -1,   713,    -1,   715,    -1,    -1,
      -1,  1014,   720,  1016,    -1,    -1,    -1,   840,    -1,  1022,
      -1,    -1,    -1,    -1,  1027,    -1,  1029,    -1,    -1,    -1,
      -1,   333,    -1,    -1,    -1,    -1,   338,    -1,    -1,  1042,
      -1,    -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,   872,
     873,   759,    -1,   876,    -1,    -1,   879,    -1,    -1,    -1,
      -1,    -1,    -1,   886,    -1,    -1,   889,    -1,   891,   892,
      55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    82,    83,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   101,   102,   216,   217,
     218,   829,   220,    -1,    -1,   948,    -1,    -1,   430,   431,
      -1,    -1,   840,    -1,    -1,    -1,    -1,   439,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,    -1,    -1,   976,   977,    -1,   141,   865,    -1,    -1,
      -1,    -1,    -1,    -1,   872,   873,    -1,    -1,   876,    -1,
      -1,   879,   474,    -1,    -1,   477,    -1,    -1,   886,    -1,
      -1,   889,    -1,   891,   892,    -1,   284,    -1,    -1,    -1,
      -1,  1014,    -1,  1016,    -1,    -1,    -1,    -1,    -1,  1022,
      -1,    -1,    -1,    -1,  1027,    -1,  1029,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   923,    -1,    -1,    -1,  1042,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,   336,    -1,
     948,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,    -1,   976,   977,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   594,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    82,    83,    -1,  1014,    -1,  1016,    88,
      89,    -1,    -1,    -1,  1022,    -1,    -1,    -1,    -1,  1027,
      -1,  1029,    -1,    -1,    -1,    -1,   628,    -1,    -1,   631,
      -1,   429,   430,   431,  1042,    -1,    -1,    -1,    -1,   437,
     438,   439,   644,   645,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     458,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,   477,
      -1,     0,    -1,    -1,    -1,    -1,    -1,   689,   486,    -1,
      -1,    -1,    11,    12,    13,    -1,    -1,    16,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,   717,   514,    -1,    -1,    -1,
      -1,    40,    41,    -1,    43,    44,    45,    46,    47,    -1,
      -1,   529,    -1,    -1,    -1,    -1,   738,    -1,   536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   594,    -1,   117,    -1,
     802,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     628,    -1,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,
     842,    -1,    -1,    -1,    -1,    -1,   644,   645,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   660,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      -1,    -1,    -1,   875,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    -1,    -1,    16,    17,    18,    -1,    20,    -1,
      -1,   689,    -1,    -1,    -1,   897,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,   717,
      -1,    -1,   720,    -1,   722,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     738,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    -1,    88,    89,    90,    91,
      -1,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,
      -1,    -1,   114,   781,   782,   117,   784,   785,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,   802,    -1,   138,   139,   140,    -1,
      -1,   143,   144,   145,    -1,   147,   148,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,   829,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   842,    -1,    -1,    -1,   846,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   875,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   896,   897,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,   923,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,   944,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,   101,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,    -1,    11,    12,    13,    -1,    -1,    16,    17,    18,
     145,    20,    -1,   148,    -1,    -1,    47,    -1,    -1,    28,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,    88,
      89,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
     121,   100,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,   114,    -1,    -1,   117,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,     0,    -1,   143,   144,   145,    -1,   147,   148,
      -1,    -1,    -1,    11,    12,    13,    -1,    -1,    16,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    -1,    88,    89,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    -1,
      88,    89,    90,    91,    -1,    -1,    94,    -1,    -1,    -1,
      -1,   121,   100,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,   114,    -1,    -1,   117,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,     0,    -1,   143,   144,   145,    -1,   147,
     148,    -1,    -1,    -1,    11,    12,    13,    -1,    -1,    16,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,    88,
      89,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      -1,    88,    89,    90,    91,    -1,    -1,    94,    -1,    -1,
      -1,    -1,   121,   100,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   114,    -1,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,     0,    -1,   143,   144,   145,    -1,
     147,   148,    -1,    -1,    -1,    11,    12,    13,    -1,    -1,
      16,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    88,    89,    90,    91,    -1,    93,    94,    -1,
      -1,    -1,    -1,    -1,   100,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   114,    -1,
      -1,   117,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,     0,    -1,   143,   144,   145,
      -1,   147,   148,    -1,    -1,    -1,    11,    12,    13,    -1,
      -1,    16,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,   100,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,     0,   142,   143,   144,
     145,    -1,   147,   148,    -1,    -1,    -1,    11,    12,    13,
      -1,    -1,    16,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    -1,    -1,
      -1,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,   100,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,     0,    -1,   143,
     144,   145,    -1,   147,   148,    -1,    -1,    -1,    11,    12,
      13,    -1,    -1,    16,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    -1,    88,    89,    90,    91,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,     0,   142,
     143,   144,   145,    -1,   147,   148,    -1,    -1,    -1,    11,
      12,    13,    -1,    -1,    16,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    -1,    88,    89,    90,    91,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,     0,
     142,   143,   144,   145,    -1,   147,   148,    -1,    -1,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,
     121,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
       0,    -1,   143,    -1,   145,    -1,   147,   148,    -1,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    -1,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,    -1,    -1,   143,    -1,   145,    -1,   147,   148,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    67,    68,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,   101,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,     1,   148,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      96,    -1,    98,    99,    -1,   101,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,     1,   148,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    67,    68,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,   101,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,     1,   148,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,   101,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,   133,
     134,   135,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,   145,    -1,    -1,   148,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    99,    -1,   101,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    14,    15,   133,   134,   135,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,   145,    -1,
      -1,   148,    -1,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    67,    68,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,   101,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,   145,    -1,     1,   148,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,   101,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,   145,    -1,     1,   148,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    67,
      68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    99,    -1,   101,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,   135,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,     1,
     148,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    67,    68,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,   101,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,     1,   148,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      96,    -1,    98,    99,    -1,   101,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    15,   133,   134,   135,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,   145,
      -1,    -1,   148,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    -1,    67,    68,
      69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      99,    -1,   101,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    14,    15,   133,   134,   135,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,   145,    -1,    -1,   148,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,
      15,   133,   134,   135,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,   148,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    14,    15,   133,   134,
     135,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
     145,    -1,    -1,   148,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    67,
      68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    15,   133,   134,   135,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
     148,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,
     101,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,    15,   133,   134,   135,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,   145,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,   101,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    82,    83,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,    -1,    -1,    -1,    -1,    -1,
     141,   142,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    82,    83,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,    -1,    -1,    -1,    -1,    -1,
     141,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      -1,    -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,    -1,    -1,    -1,    -1,    -1,   141,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,   133,    14,
      15,    -1,    -1,    -1,    19,   140,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,   133,    14,
      15,    -1,    -1,    -1,    19,   140,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,   101,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    14,    15,   133,   134,
     135,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    15,   133,   134,   135,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,
     101,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      14,    15,   133,   134,   135,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    14,    15,   133,
     134,   135,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    99,    -1,   101,   102,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,   133,   134,   135,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    14,    15,   133,   134,   135,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    99,    -1,   101,   102,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,    15,
     133,   134,   135,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      96,    -1,    98,    99,    -1,    -1,   102,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    14,    15,   133,   134,   135,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    -1,    67,    68,
      69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      99,    -1,   101,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    14,    15,   133,   134,   135,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    67,    68,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,   101,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,
      15,   133,   134,   135,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,   101,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    14,    15,   133,   134,
     135,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    67,
      68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    99,    -1,   101,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    14,    15,   133,   134,   135,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,
     101,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      14,    15,   133,   134,   135,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    14,    15,   133,
     134,   135,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,   133,   134,   135,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    67,    68,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    14,    15,   133,   134,   135,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    99,    -1,   101,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    19,
     133,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,
      -1,   101,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    19,   133,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    19,   133,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    19,   133,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,   133,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,   133,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,    55,    56,    -1,    -1,    59,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    82,    83,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,    55,    56,    -1,    -1,    59,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,    55,    56,    -1,    -1,
      59,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,   134,   135,    55,    56,    -1,
      -1,    59,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,    55,    56,
      -1,    -1,    59,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    82,    83,    -1,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,    55,
      56,    -1,    -1,    59,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
      55,    56,    -1,    -1,    59,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    82,    83,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,    55,    56,    -1,    -1,    59,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      -1,    -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,    55,    56,    -1,    -1,    59,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,    55,    56,    -1,    -1,    59,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,    55,    56,    -1,    -1,    59,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    82,    83,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,    -1,    -1,    -1,    -1,    -1,
     141
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   150,   151,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    14,    15,    19,    21,    22,    23,    24,
      25,    26,    27,    33,    34,    35,    36,    37,    38,    39,
      42,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    62,    63,    64,    65,    67,    68,
      69,    71,    72,    92,    95,    96,    98,    99,   101,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   133,   134,
     135,   152,   153,   154,   161,   163,   164,   166,   167,   170,
     171,   172,   174,   175,   176,   178,   179,   189,   204,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   271,   272,   286,   287,   288,   289,   290,
     291,   292,   295,   297,   298,   312,   314,   315,   316,   317,
     318,   319,   320,   321,   355,   368,   154,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    59,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    82,    83,    86,    87,    88,    89,   101,
     102,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   134,   135,   141,   182,   183,   184,   185,   187,   188,
     312,   314,    42,    61,    92,    95,   101,   102,   103,   106,
     134,   171,   179,   189,   191,   196,   199,   201,   231,   317,
     318,   320,   321,   353,   354,   196,   196,   142,   197,   198,
     142,   193,   197,   142,   148,   362,    57,   184,   362,   155,
     137,    24,    25,    33,    34,    35,   170,   189,   231,   189,
      59,     1,    50,    95,   157,   158,   159,   161,   173,   174,
     368,   206,   207,   192,   201,   353,   368,   191,   352,   353,
     368,    49,    92,   133,   140,   178,   204,   231,   317,   318,
     321,   262,   263,    57,    58,    60,   182,   302,   313,   301,
     302,   303,   146,   293,   146,   299,   146,   296,   146,   300,
     316,   166,   189,   189,   145,   148,   361,   366,   367,    43,
      44,    45,    46,    47,    40,    41,    29,   137,   193,   197,
     277,    31,   269,   120,   140,    95,   101,   175,   120,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    88,    89,   121,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    90,    91,   139,   147,   359,
     205,   164,   165,   165,   210,   212,   165,   361,   367,    92,
     172,   179,   231,   250,   317,   318,   321,    55,    59,    88,
      92,   180,   181,   231,   317,   318,   321,   181,    36,    37,
      38,    39,    52,    53,    54,    55,    59,   142,   182,   319,
     350,   182,   350,   182,   182,    91,   359,   360,   277,   289,
      93,    93,   140,   191,    59,   191,   191,   191,   301,   120,
      94,   140,   200,   368,    91,   139,   359,    93,    93,   140,
     200,   196,   362,   363,   196,   195,   196,   201,   353,   368,
     164,   363,   164,    57,    68,    69,   162,   142,   190,   137,
     157,    91,   359,    93,   161,   160,   173,   143,   361,   367,
     363,   363,   164,   144,   140,   148,   365,   140,   365,   138,
     365,   362,    59,   316,   175,   177,   140,    91,   139,   359,
     264,    66,   113,   115,   116,   304,   116,   304,   116,    70,
     304,   116,   116,   294,   304,   116,    66,   116,   116,   116,
     294,   116,    66,   116,    73,   145,   154,   165,   165,   165,
     165,   161,   164,   164,   279,   278,   100,   168,   270,   101,
     166,   191,   201,   202,   203,   173,   140,   178,   140,   163,
     166,   179,   189,   191,   203,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,    55,    56,    59,   187,   276,   356,   357,   195,    55,
      56,    59,   187,   275,   356,   156,   157,    16,   246,   366,
     246,   165,   165,   361,    20,   280,    59,    91,   139,   359,
      28,   164,    55,    59,   180,   124,   322,    91,   139,   359,
     218,   351,   219,    91,   147,   358,   221,   358,   223,   225,
      55,    59,   356,   166,   189,   166,   189,   186,   118,   189,
     191,   101,   191,   199,   353,    55,    59,   195,    55,    59,
     354,   363,   143,   363,   140,   140,   363,   184,   209,   189,
     152,   138,   356,   356,   189,   137,   363,   159,   208,   353,
     140,   177,    55,    59,   195,    55,    59,    55,    57,    58,
      59,    60,    61,    73,    95,   101,   102,   103,   127,   130,
     142,   267,   326,   328,   329,   330,   331,   332,   333,   334,
     335,   338,   339,   340,   341,   344,   345,   346,   347,   348,
     306,   305,   146,   304,   146,   146,   146,   189,    81,   125,
     257,   258,   368,   257,   169,   257,   191,   140,   363,   177,
     140,   120,    47,   362,    93,    93,   193,   197,   274,   362,
     364,    93,    93,   193,   197,   273,    13,   245,    11,   282,
     368,   157,    16,   157,    30,   247,   366,   247,   280,   201,
     245,    55,    59,   195,    55,    59,   214,   217,   323,   216,
      55,    59,   180,   195,   156,   164,   220,   227,   222,   229,
     224,   226,   193,   194,   197,   368,    47,   184,   191,   191,
     200,    93,    93,   364,    93,    93,   353,   164,   138,   152,
     363,   365,   175,   364,    95,   101,   251,   252,   253,   330,
     328,   265,   120,   140,   327,   191,   140,   349,   368,    55,
     140,   349,   140,   327,    55,   140,   327,    55,   307,    57,
      58,    60,   311,   321,   254,   256,   259,   331,   333,   334,
     336,   337,   340,   342,   343,   346,   348,   362,   157,   157,
     257,   157,   101,   191,   177,   189,   122,   166,   189,   166,
     189,   168,   193,   144,    93,   166,   189,   166,   189,   168,
     194,   191,   203,   283,   368,    18,   249,   368,    17,   248,
     249,   249,   211,   213,   245,   140,   246,   364,   165,   366,
     165,   156,   364,   245,   363,   142,   324,   325,   182,   324,
     182,   324,   324,   277,   269,   189,    93,   140,   363,   138,
     253,   140,   330,   140,   363,   259,   266,   191,   326,   332,
     344,   346,   335,   340,   348,   333,   341,   346,   331,   333,
     308,   259,   125,   120,   140,   255,    92,   231,   140,   349,
     349,   140,   255,   140,   255,   145,    13,   138,   157,    13,
     191,   189,   166,   189,    94,   284,   368,   157,    12,   285,
     368,   165,   245,   245,   157,   157,   191,   157,   247,   156,
     366,   245,   328,   156,   328,   228,   156,   230,   156,   156,
     363,   252,   140,   101,   251,   143,    32,   117,   268,   140,
     327,   140,   327,   349,   140,   327,   140,   327,   327,   309,
     125,   231,   254,   343,   346,    59,    91,   336,   340,   333,
     342,   346,   333,    55,   260,   261,   329,   138,    92,   179,
     231,   317,   318,   321,   246,   157,   246,   245,   245,   249,
     280,   281,   215,   245,   363,   245,   366,   324,   245,   324,
     245,   245,   140,   252,   140,   330,   157,   157,   333,   346,
     333,   333,   310,   140,   255,   140,   255,    55,    59,   349,
     140,   255,   140,   255,   255,   140,   362,    59,    91,   139,
     359,   157,   157,   157,   156,   156,   252,   140,    13,   138,
     327,   140,   327,   327,   327,   157,   333,   346,   333,   333,
     261,    55,    59,   195,    55,    59,   282,   248,   245,   245,
     245,   252,   333,   114,   255,   140,   255,   255,   255,   364,
     327,   333,   255
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   149,   151,   150,   152,   153,   153,   153,   153,   154,
     155,   154,   156,   157,   158,   158,   158,   158,   159,   160,
     159,   162,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   163,   163,   164,   164,   164,
     164,   164,   164,   165,   166,   166,   167,   167,   169,   168,
     170,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   175,   175,   176,   176,
     177,   177,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     180,   180,   181,   181,   181,   182,   182,   182,   182,   182,
     183,   183,   184,   184,   185,   186,   185,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   190,   189,   189,   189,   191,   192,   192,   192,
     192,   193,   194,   194,   195,   195,   195,   195,   195,   196,
     196,   196,   196,   196,   198,   197,   199,   200,   200,   201,
     201,   201,   201,   202,   202,   203,   203,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   205,
     204,   206,   204,   207,   208,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   209,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   210,   211,   204,   212,   213,
     204,   204,   204,   214,   215,   204,   216,   204,   217,   204,
     218,   204,   219,   220,   204,   221,   222,   204,   223,   224,
     204,   225,   226,   204,   227,   228,   204,   229,   230,   204,
     204,   204,   204,   204,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     246,   246,   247,   247,   248,   248,   249,   249,   250,   250,
     251,   251,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   254,   254,   254,   254,   255,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   257,   257,   258,   258,   258,   259,
     259,   260,   260,   261,   261,   263,   264,   265,   266,   262,
     267,   267,   268,   268,   270,   269,   271,   271,   271,   271,
     272,   273,   272,   274,   272,   272,   275,   272,   276,   272,
     272,   272,   272,   278,   277,   279,   277,   280,   281,   281,
     282,   282,   283,   283,   283,   284,   284,   285,   285,   286,
     286,   286,   287,   288,   288,   288,   289,   290,   291,   292,
     292,   293,   293,   294,   294,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   301,   301,   302,
     302,   303,   303,   304,   305,   304,   306,   307,   308,   309,
     310,   304,   311,   311,   311,   311,   312,   313,   313,   313,
     313,   314,   315,   315,   316,   316,   316,   316,   317,   317,
     317,   317,   317,   318,   318,   318,   318,   318,   318,   318,
     319,   319,   320,   320,   321,   321,   323,   322,   322,   324,
     325,   324,   326,   326,   326,   326,   327,   327,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   329,   329,   329,   329,   330,   330,   331,
     332,   332,   333,   333,   334,   335,   335,   336,   336,   337,
     337,   338,   338,   339,   339,   340,   340,   341,   342,   343,
     343,   344,   344,   345,   345,   346,   346,   347,   347,   348,
     349,   349,   350,   351,   350,   352,   352,   353,   353,   354,
     354,   354,   354,   355,   355,   355,   356,   356,   356,   356,
     357,   357,   357,   358,   358,   359,   359,   360,   360,   361,
     361,   362,   362,   363,   364,   365,   365,   365,   366,   366,
     367,   367,   368
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     3,     2,     1,
       0,     5,     4,     2,     1,     1,     3,     2,     1,     0,
       5,     0,     4,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     4,     1,     3,     3,     6,     5,     5,     5,
       5,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     4,     0,     5,
       1,     2,     3,     4,     5,     4,     5,     2,     2,     2,
       2,     2,     1,     3,     1,     3,     1,     2,     3,     5,
       2,     4,     2,     4,     1,     3,     1,     3,     2,     3,
       1,     3,     1,     1,     4,     3,     3,     3,     3,     2,
       1,     1,     1,     4,     3,     3,     3,     3,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     3,     5,     6,     5,     5,     5,     5,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     0,     4,     6,     1,     1,     1,     2,     4,
       2,     3,     1,     1,     1,     1,     2,     4,     2,     1,
       2,     2,     4,     1,     0,     2,     2,     2,     1,     1,
       2,     3,     4,     1,     1,     3,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     3,     0,     0,     5,     3,     3,     2,     3,
       3,     1,     4,     3,     1,     0,     6,     4,     3,     2,
       1,     2,     2,     6,     6,     0,     0,     7,     0,     0,
       7,     5,     4,     0,     0,     9,     0,     6,     0,     7,
       0,     5,     0,     0,     7,     0,     0,     7,     0,     0,
       7,     0,     0,     7,     0,     0,     9,     0,     0,     9,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     5,     1,     2,     1,     1,
       1,     3,     1,     3,     1,     4,     6,     3,     5,     2,
       4,     1,     3,     4,     2,     2,     1,     2,     0,     6,
       8,     4,     6,     4,     2,     6,     2,     4,     6,     2,
       4,     2,     4,     1,     1,     1,     3,     1,     4,     1,
       4,     1,     3,     1,     1,     0,     0,     0,     0,     6,
       4,     1,     3,     3,     0,     5,     2,     4,     5,     5,
       2,     0,     5,     0,     5,     3,     0,     4,     0,     4,
       2,     1,     4,     0,     5,     0,     5,     5,     1,     1,
       6,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     0,     3,     1,     2,     3,     3,     0,     3,     3,
       3,     3,     3,     0,     3,     0,     3,     0,     2,     0,
       2,     0,     2,     1,     0,     3,     0,     0,     0,     0,
       0,     8,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     3,
       0,     3,     4,     2,     2,     1,     2,     0,     6,     8,
       4,     6,     4,     6,     2,     4,     6,     2,     4,     2,
       4,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     1,     2,     1,     1,
       3,     1,     3,     1,     1,     2,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     0,     4,     1,     2,     1,     3,     3,
       2,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (parser_state, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, parser_state); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, rb_parser_state* parser_state)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (parser_state);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, rb_parser_state* parser_state)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser_state);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, rb_parser_state* parser_state)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , parser_state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parser_state); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, rb_parser_state* parser_state)
{
  YYUSE (yyvaluep);
  YYUSE (parser_state);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (rb_parser_state* parser_state)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, parser_state);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 603 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_BEG);
                    local_push(0);
                    class_nest = 0;
                  }
#line 4650 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 609 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[0].node) && !compile_for_eval) {
                      /* last expression should not be void */
                      if(nd_type((yyvsp[0].node)) != NODE_BLOCK) {
                        void_expr((yyvsp[0].node));
                      } else {
                        NODE *node = (yyvsp[0].node);
                        while(node->nd_next) {
                          node = node->nd_next;
                        }
                        void_expr(node->nd_head);
                      }
                    }
                    top_node = block_append(top_node, (yyvsp[0].node));
                    class_nest = 0;
                    local_pop();
                  }
#line 4672 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 629 "grammar.y" /* yacc.c:1661  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4681 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 636 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4689 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 640 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4697 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 644 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4705 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 648 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4713 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 655 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single) {
                      yy_error("BEGIN in method");
                    }
                  }
#line 4723 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 661 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_PREEXE((yyvsp[-1].node));
                  }
#line 4731 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 670 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-3].node);
                    if((yyvsp[-2].node)) {
                      (yyval.node) = NEW_RESCUE((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
                    } else if((yyvsp[-1].node)) {
                      rb_warn("else without rescue is useless");
                      (yyval.node) = block_append((yyval.node), (yyvsp[-1].node));
                    }
                    if((yyvsp[0].node)) {
                      if((yyval.node)) {
                        (yyval.node) = NEW_ENSURE((yyval.node), (yyvsp[0].node));
                      } else {
                        (yyval.node) = block_append((yyvsp[0].node), NEW_NIL());
                      }
                    }
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 4753 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 690 "grammar.y" /* yacc.c:1661  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4762 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 697 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4770 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 701 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4778 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 705 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4786 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 709 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4794 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 715 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4802 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 719 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("BEGIN is permitted only at toplevel");
                  }
#line 4810 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 723 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4818 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 728 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);}
#line 4824 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 729 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ALIAS((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4832 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 733 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 4840 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 737 "grammar.y" /* yacc.c:1661  */
    {
                    char buf[2];
                    buf[0] = '$';
                    buf[1] = (char)(yyvsp[0].node)->nd_nth;
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), parser_intern2(buf, 2));
                  }
#line 4851 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 744 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("can't make alias for the number variables");
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4860 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 749 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4868 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 753 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4877 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 758 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4886 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 763 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4898 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 771 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4910 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 779 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *resq = NEW_RESBODY(0, remove_begin((yyvsp[0].node)), 0);
                    (yyval.node) = NEW_RESCUE(remove_begin((yyvsp[-2].node)), resq, 0);
                  }
#line 4919 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 784 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single) {
                      rb_warn("END in method; use at_exit");
                    }

                    (yyval.node) = NEW_POSTEXE(NEW_NODE(NODE_SCOPE,
                            0 /* tbl */, (yyvsp[-1].node) /* body */, 0 /* args */));
                  }
#line 4932 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 794 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 4942 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 800 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4951 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 805 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *args;

                    value_expr((yyvsp[0].node));
                    if(!(yyvsp[-3].node)) (yyvsp[-3].node) = NEW_ZARRAY();
                    args = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    if((yyvsp[-1].id) == tOROP) {
                      (yyvsp[-1].id) = 0;
                    } else if((yyvsp[-1].id) == tANDOP) {
                      (yyvsp[-1].id) = 1;
                    } else {
                      (yyvsp[-1].id) = convert_op((yyvsp[-1].id));
                    }
                    (yyval.node) = NEW_OP_ASGN1((yyvsp[-5].node), (yyvsp[-1].id), args);
                    fixpos((yyval.node), (yyvsp[-5].node));
                  }
#line 4972 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 822 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4981 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 827 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4990 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 832 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4999 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 837 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), parser_intern("::"), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5008 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 842 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5017 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 847 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5026 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 852 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 5035 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 860 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5044 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 865 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5053 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 873 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5061 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 877 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5069 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 881 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5077 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 885 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5085 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 892 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 5095 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 905 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5103 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 911 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 5112 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 918 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 5122 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 926 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                    nd_set_line((yyval.node), tokline);
                  }
#line 5131 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 933 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                 }
#line 5140 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 938 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[-2].node)->nd_args = (yyvsp[-1].node);
                    (yyvsp[0].node)->nd_iter = (yyvsp[-2].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-2].node));
                 }
#line 5152 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 946 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5161 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 951 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                 }
#line 5172 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 958 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5181 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 963 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 5192 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 970 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5201 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 975 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_yield((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5210 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 980 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETURN(ret_args((yyvsp[0].node)));
                  }
#line 5218 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 984 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BREAK(ret_args((yyvsp[0].node)));
                  }
#line 5226 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 988 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_NEXT(ret_args((yyvsp[0].node)));
                  }
#line 5234 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 995 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5242 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 1002 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(NEW_LIST((yyvsp[-1].node)), 0);
                  }
#line 5250 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 1008 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 5258 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 1012 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(list_append((yyvsp[-1].node), (yyvsp[0].node)), 0);
                  }
#line 5266 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 1016 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5274 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 1020 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5282 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 1024 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-1].node), -1);
                  }
#line 5290 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 1028 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5298 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 1032 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, (yyvsp[0].node));
                  }
#line 5306 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 1036 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5314 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 1040 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 5322 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 1044 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5330 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 1051 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5338 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 1057 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[-1].node));
                  }
#line 5346 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 1061 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 5354 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 1067 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 5362 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 1071 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5370 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 1077 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5378 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 1081 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5386 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 1085 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5394 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 1089 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5402 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 1093 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), parser_intern("::"), (yyvsp[0].id));
                  }
#line 5410 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 1097 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5418 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 1101 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5428 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 1107 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5438 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 1113 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5447 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 1120 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5456 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 1125 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5465 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 1130 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5473 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 1134 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5481 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 1138 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), parser_intern("::"), (yyvsp[0].id));
                  }
#line 5489 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 1142 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5497 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 1146 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5507 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 1152 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5517 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 1158 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5526 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 1165 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("class/module name must be CONSTANT");
                  }
#line 5534 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 1172 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 5542 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 1176 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2(0, (yyval.node));
                  }
#line 5550 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 1180 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5558 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 1189 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_ENDFN);
                    (yyval.id) = convert_op((yyvsp[0].id));
                  }
#line 5567 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 1194 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_ENDFN);
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 5576 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 1205 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 5584 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 1212 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNDEF((yyvsp[0].node));
                  }
#line 5592 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 1215 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);}
#line 5598 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 1216 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-3].node), NEW_UNDEF((yyvsp[0].node)));
                  }
#line 5606 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 1221 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '|'; }
#line 5612 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 1222 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '^'; }
#line 5618 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 1223 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '&'; }
#line 5624 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 1224 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tCMP; }
#line 5630 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 1225 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tEQ; }
#line 5636 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 1226 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tEQQ; }
#line 5642 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 1227 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tMATCH; }
#line 5648 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 1228 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tNMATCH; }
#line 5654 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 1229 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '>'; }
#line 5660 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 1230 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tGEQ; }
#line 5666 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 1231 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '<'; }
#line 5672 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 1232 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tLEQ; }
#line 5678 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 1233 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tNEQ; }
#line 5684 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 1234 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tLSHFT; }
#line 5690 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 1235 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tRSHFT; }
#line 5696 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 1236 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '+'; }
#line 5702 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 1237 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '-'; }
#line 5708 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 1238 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '*'; }
#line 5714 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 1239 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '*'; }
#line 5720 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 1240 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '/'; }
#line 5726 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 1241 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '%'; }
#line 5732 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 1242 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tPOW; }
#line 5738 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 1243 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tDSTAR; }
#line 5744 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 1244 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '!'; }
#line 5750 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 1245 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '~'; }
#line 5756 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 1246 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tUPLUS; }
#line 5762 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 1247 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tUMINUS; }
#line 5768 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 1248 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tAREF; }
#line 5774 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 1249 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tASET; }
#line 5780 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 1250 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '`'; }
#line 5786 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1269 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5795 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1274 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    (yyval.node) = node_assign((yyvsp[-4].node), (yyvsp[-2].node));
                  }
#line 5805 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1280 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5814 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1285 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    new_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].node));
                  }
#line 5824 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1291 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *args;

                    value_expr((yyvsp[0].node));
                    if(!(yyvsp[-3].node)) (yyvsp[-3].node) = NEW_ZARRAY();
                    if(nd_type((yyvsp[-3].node)) == NODE_BLOCK_PASS) {
                      args = NEW_ARGSCAT((yyvsp[-3].node), (yyvsp[0].node));
                    } else {
                      args = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                    if((yyvsp[-1].id) == tOROP) {
                      (yyvsp[-1].id) = 0;
                    } else if((yyvsp[-1].id) == tANDOP) {
                      (yyvsp[-1].id) = 1;
                    } else {
                      (yyvsp[-1].id) = convert_op((yyvsp[-1].id));
                    }
                    (yyval.node) = NEW_OP_ASGN1((yyvsp[-5].node), (yyvsp[-1].id), args);
                    fixpos((yyval.node), (yyvsp[-5].node));
                  }
#line 5849 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1312 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5858 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1317 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5867 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1322 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), parser_intern("::"), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5876 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1327 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5885 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1332 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5894 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1337 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5903 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1342 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT2((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5913 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1348 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT3((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5923 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1354 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '+', (yyvsp[0].node));
                  }
#line 5931 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1358 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '-', (yyvsp[0].node));
                  }
#line 5939 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1362 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '*', (yyvsp[0].node));
                  }
#line 5947 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1366 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '/', (yyvsp[0].node));
                  }
#line 5955 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1370 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '%', (yyvsp[0].node));
                  }
#line 5963 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1374 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node));
                  }
#line 5971 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1378 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL(call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node)), tUMINUS, 0);
                  }
#line 5979 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1382 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUPLUS);
                  }
#line 5987 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1386 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUMINUS);
                  }
#line 5995 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1390 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '|', (yyvsp[0].node));
                  }
#line 6003 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1394 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '^', (yyvsp[0].node));
                  }
#line 6011 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1398 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '&', (yyvsp[0].node));
                  }
#line 6019 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1402 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tCMP, (yyvsp[0].node));
                  }
#line 6027 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1406 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '>', (yyvsp[0].node));
                  }
#line 6035 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1410 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tGEQ, (yyvsp[0].node));
                  }
#line 6043 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1414 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '<', (yyvsp[0].node));
                  }
#line 6051 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1418 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLEQ, (yyvsp[0].node));
                  }
#line 6059 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1422 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQ, (yyvsp[0].node));
                  }
#line 6067 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1426 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQQ, (yyvsp[0].node));
                  }
#line 6075 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1430 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNEQ, (yyvsp[0].node));
                  }
#line 6083 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1434 "grammar.y" /* yacc.c:1661  */
    {
                    /* TODO */
                    (yyval.node) = match_op((yyvsp[-2].node), (yyvsp[0].node));
                    /*
                    if(nd_type($1) == NODE_LIT && TYPE($1->nd_lit) == T_REGEXP) {
                      $$ = reg_named_capture_assign($1->nd_lit, $$);
                    }
                    */
                  }
#line 6097 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1444 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNMATCH, (yyvsp[0].node));
                  }
#line 6105 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1448 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 6113 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1452 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), '~');
                  }
#line 6121 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1456 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLSHFT, (yyvsp[0].node));
                  }
#line 6129 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1460 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tRSHFT, (yyvsp[0].node));
                  }
#line 6137 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1464 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6145 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1468 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6153 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1471 "grammar.y" /* yacc.c:1661  */
    {in_defined = 1;}
#line 6159 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1472 "grammar.y" /* yacc.c:1661  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[0].node));
                  }
#line 6168 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1477 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-5].node));
                    (yyval.node) = NEW_IF(cond((yyvsp[-5].node)), (yyvsp[-3].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-5].node));
                  }
#line 6178 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1483 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6186 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1489 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6196 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1498 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6204 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1502 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6212 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1506 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6220 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1512 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6228 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1524 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6236 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1528 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6244 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1532 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6252 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1538 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6261 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1543 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_blk_pass((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 6269 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1547 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[-1].node) ? NEW_HASH((yyvsp[-1].node)) : 0);
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6278 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1552 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node) ? arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node))) : (yyvsp[-3].node);
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6287 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1559 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.val) = cmdarg_stack;
                    CMDARG_PUSH(1);
                  }
#line 6296 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1564 "grammar.y" /* yacc.c:1661  */
    {
                    /* CMDARG_POP() */
                    cmdarg_stack = (yyvsp[-1].val);
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6306 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1572 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BLOCK_PASS((yyvsp[0].node));
                  }
#line 6314 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1578 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6322 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1582 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 6330 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1588 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6338 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1592 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6346 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1596 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6359 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1605 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((nd_type((yyvsp[0].node)) == NODE_ARRAY) && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6372 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1620 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6385 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1629 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if(nd_type((yyvsp[0].node)) == NODE_ARRAY && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6398 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1638 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6406 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1654 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                  }
#line 6414 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1658 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cmdarg_stack;
                    cmdarg_stack = 0;
                    (yyval.num) = sourceline;
                  }
#line 6424 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1665 "grammar.y" /* yacc.c:1661  */
    {
                    cmdarg_stack = (yyvsp[-3].val);
                    if((yyvsp[-1].node) == NULL) {
                      (yyval.node) = NEW_NIL();
                    } else {
                      if(nd_type((yyvsp[-1].node)) == NODE_RESCUE || nd_type((yyvsp[-1].node)) == NODE_ENSURE) {
                        nd_set_line((yyvsp[-1].node), (yyvsp[-2].num));
                      }
                      (yyval.node) = NEW_BEGIN((yyvsp[-1].node));
                    }
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                  }
#line 6441 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1677 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_ENDARG);}
#line 6447 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1678 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 6455 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1682 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cmdarg_stack;
                    cmdarg_stack = 0;
                  }
#line 6464 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1686 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_ENDARG);}
#line 6470 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1687 "grammar.y" /* yacc.c:1661  */
    {
                    cmdarg_stack = (yyvsp[-4].val);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 6479 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1692 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6487 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1696 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 6495 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1700 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 6503 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1704 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-1].node) == 0) {
                      (yyval.node) = NEW_ZARRAY(); /* zero length array*/
                    } else {
                      (yyval.node) = (yyvsp[-1].node);
                    }
                  }
#line 6515 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1712 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_HASH((yyvsp[-1].node));
                  }
#line 6523 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 1716 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETURN(0);
                  }
#line 6531 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1720 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_yield((yyvsp[-1].node));
                  }
#line 6539 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1724 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6547 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1728 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6555 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1731 "grammar.y" /* yacc.c:1661  */
    {in_defined = 1;}
#line 6561 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 306:
#line 1732 "grammar.y" /* yacc.c:1661  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[-1].node));
                  }
#line 6570 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1737 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[-1].node)), '!');
                  }
#line 6578 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1741 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond(NEW_NIL()), '!');
                  }
#line 6586 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1745 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyvsp[0].node)->nd_iter, (yyvsp[0].node));
                  }
#line 6596 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1752 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-1].node));
                  }
#line 6607 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1759 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6615 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1766 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6624 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1774 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6633 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1778 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6639 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1778 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6645 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1781 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_WHILE(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6654 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1785 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6660 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1785 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6666 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1788 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNTIL(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6675 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1795 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CASE((yyvsp[-3].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 6684 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1800 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CASE(0, (yyvsp[-1].node));
                  }
#line 6692 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1804 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6698 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1806 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6704 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1809 "grammar.y" /* yacc.c:1661  */
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
                    (yyval.node) = NEW_FOR((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-7].node));
                  }
#line 6722 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1823 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("class definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6734 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1832 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CLASS((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-3].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6745 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1839 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = (in_def << 1) | in_single;
                    in_def = 0;
                    in_single = 0;
                    class_nest++;
                    local_push(0);
                  }
#line 6757 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1849 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SCLASS((yyvsp[-4].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                    local_pop();
                    class_nest--;
                    in_def = ((yyvsp[-3].num) >> 1) & 1;
                    in_single = (yyvsp[-3].num) & 1;
                  }
#line 6770 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1858 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("module definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6782 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1867 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MODULE((yyvsp[-3].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6793 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1874 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    local_push(0);
                  }
#line 6803 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1879 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 1;
                  }
#line 6812 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1886 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFN((yyvsp[-5].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-6].num));
                    local_pop();
                    in_def = (yyvsp[-3].num) & 1;
                    cur_mid = (yyvsp[-4].id);
                  }
#line 6825 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1895 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    local_push(0);
                  }
#line 6835 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1900 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 1;
                  }
#line 6844 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1907 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFNM((yyvsp[-5].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-6].num));
                    local_pop();
                    in_def = (yyvsp[-3].num) & 1;
                    cur_mid = (yyvsp[-4].id);
                  }
#line 6857 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1916 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    local_push(0);
                  }
#line 6867 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1921 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 1;
                  }
#line 6876 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1928 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_FUN((yyvsp[-5].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-6].num));
                    local_pop();
                    in_def = (yyvsp[-3].num) & 1;
                    cur_mid = (yyvsp[-4].id);
                  }
#line 6889 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1937 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    local_push(0);
                  }
#line 6899 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1942 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 1;
                  }
#line 6908 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1949 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_FUNM((yyvsp[-5].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-6].num));
                    local_pop();
                    in_def = (yyvsp[-3].num) & 1;
                    cur_mid = (yyvsp[-4].id);
                  }
#line 6921 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1957 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME);}
#line 6927 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1958 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-1].num) = in_single;
                    in_single = 1;
                    SET_LEX_STATE(EXPR_ENDFN | EXPR_LABEL); /* force for args */
                    local_push(0);
                  }
#line 6938 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1967 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFS((yyvsp[-7].node), (yyvsp[-4].id), (yyvsp[-2].node), body);
                    nd_set_line((yyval.node), (yyvsp[-8].num));
                    local_pop();
                    in_single = (yyvsp[-5].num) & 1;
                  }
#line 6950 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1974 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME);}
#line 6956 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1975 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-1].num) = in_single;
                    in_single = 1;
                    SET_LEX_STATE(EXPR_ENDFN | EXPR_LABEL); /* force for args */
                    local_push(0);
                  }
#line 6967 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1984 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFSM((yyvsp[-7].node), (yyvsp[-4].id), (yyvsp[-2].node), body);
                    nd_set_line((yyval.node), (yyvsp[-8].num));
                    local_pop();
                    in_single = (yyvsp[-5].num) & 1;
                  }
#line 6979 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 350:
#line 1992 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BREAK(0);
                  }
#line 6987 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 1996 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_NEXT(0);
                  }
#line 6995 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 2000 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_REDO();
                  }
#line 7003 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 353:
#line 2004 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETRY();
                  }
#line 7011 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 354:
#line 2010 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 7021 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 355:
#line 2018 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("begin");
                  }
#line 7029 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 356:
#line 2024 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("if");
                  }
#line 7037 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 357:
#line 2030 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("unless");
                  }
#line 7045 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 2036 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("while");
                  }
#line 7053 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 359:
#line 2042 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("until");
                  }
#line 7061 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 360:
#line 2048 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("case");
                  }
#line 7069 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 361:
#line 2054 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("for");
                  }
#line 7077 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 2060 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("class");
                  }
#line 7085 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 2066 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("module");
                  }
#line 7093 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 2072 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("def");
                    (yyval.num) = sourceline;
                  }
#line 7102 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 2079 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("defm");
                    (yyval.num) = sourceline;
                  }
#line 7111 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 2086 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("fun");
                    (yyval.num) = sourceline;
                  }
#line 7120 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 2093 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("funm");
                    (yyval.num) = sourceline;
                  }
#line 7129 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 2100 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_pop("end");
                  }
#line 7137 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 2118 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-3].node)), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 7146 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 2126 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7154 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 2136 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 7162 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 2140 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7170 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 2146 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7178 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 2150 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 7186 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 2156 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 7194 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 2160 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), (yyval.node));
                  }
#line 7203 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 2165 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-5].node), NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 7212 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 2170 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), -1);
                  }
#line 7220 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 2174 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7228 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 2178 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN(0, (yyval.node));
                  }
#line 7237 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 2183 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 7246 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 2188 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 7254 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 2192 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7262 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 2198 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7270 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 2202 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 7278 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 2206 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7286 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 2210 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 7294 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 2216 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7302 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 2220 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 7310 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 2226 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7318 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 2230 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7326 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 2234 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7334 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 2238 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7342 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 2242 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7350 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 2246 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 1, 0, new_args_tail(0, 0, 0));
                  }
#line 7358 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 2250 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7366 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 2254 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 7374 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 2258 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7382 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 2262 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7390 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 2266 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7398 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 2270 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7406 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 2274 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7414 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 2278 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7422 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 2282 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 7430 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 2289 "grammar.y" /* yacc.c:1661  */
    {
                    command_start = TRUE;
                  }
#line 7438 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 2295 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX(0, (yyvsp[-1].node)) : 0;
                  }
#line 7447 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 2300 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7455 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 2304 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX((yyvsp[-2].node), (yyvsp[-1].node)) : (yyvsp[-2].node);
                  }
#line 7464 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 2311 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7472 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 2315 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7481 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 2322 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7490 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 2327 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 7499 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 2334 "grammar.y" /* yacc.c:1661  */
    {
                    new_bv(get_id((yyvsp[0].id)));
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIT(ID2SYM(get_id((yyvsp[0].id))));
                  }
#line 7509 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 2340 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7517 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 2345 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.vars) = bv_push();
                  }
#line 7525 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 2348 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = lpar_beg;
                    lpar_beg = ++paren_nest;
                  }
#line 7534 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 2353 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7542 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 2356 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.val) = cmdarg_stack;
                    cmdarg_stack = 0;
                  }
#line 7551 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 2361 "grammar.y" /* yacc.c:1661  */
    {
                    lpar_beg = (yyvsp[-4].num);
                    cmdarg_stack = (yyvsp[-1].val);
                    CMDARG_LEXPOP();
                    (yyval.node) = NEW_LAMBDA((yyvsp[-3].node), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    bv_pop((yyvsp[-5].vars));
                  }
#line 7564 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 2372 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 7572 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 2376 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7580 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 2382 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7588 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 2386 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7596 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 2392 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7605 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 2399 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7615 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 2407 "grammar.y" /* yacc.c:1661  */
    {
                    if(nd_type((yyvsp[-1].node)) == NODE_YIELD) {
                      compile_error("block given to yield");
                    } else {
                      block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
                    }
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-1].node));
                  }
#line 7630 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 2418 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 7638 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 2422 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7649 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 439:
#line 2429 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7660 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 2438 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 7670 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 441:
#line 2444 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7678 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 2448 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7687 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 2453 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7695 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 444:
#line 2457 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7704 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 445:
#line 2462 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].id), 0);
                  }
#line 7712 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 446:
#line 2466 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7720 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 2470 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7729 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 448:
#line 2475 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7737 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 449:
#line 2479 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7746 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 2484 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                  }
#line 7754 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 451:
#line 2488 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZSUPER();
                  }
#line 7762 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 2492 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-3].node) && nd_type((yyvsp[-3].node)) == NODE_SELF) {
                      (yyval.node) = NEW_FCALL(tAREF, (yyvsp[-1].node));
                    } else {
                      (yyval.node) = NEW_CALL((yyvsp[-3].node), tAREF, (yyvsp[-1].node));
                    }
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 7775 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 453:
#line 2503 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7784 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 454:
#line 2509 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7794 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 455:
#line 2515 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7803 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 456:
#line 2521 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7813 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 457:
#line 2531 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_WHEN((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7821 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 460:
#line 2543 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-3].node)) {
                      /* TODO NEW_ERRINFO() */
                      (yyvsp[-3].node) = node_assign((yyvsp[-3].node), NEW_GVAR(parser_intern("$!")));
                      (yyvsp[-1].node) = block_append((yyvsp[-3].node), (yyvsp[-1].node));
                    }
                    (yyval.node) = NEW_RESBODY((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-4].node) ? (yyvsp[-4].node) : (yyvsp[-1].node));
                  }
#line 7835 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 462:
#line 2556 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7843 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 463:
#line 2560 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = splat_array((yyvsp[0].node)))) (yyval.node) = (yyvsp[0].node);
                  }
#line 7851 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 465:
#line 2567 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7859 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 2574 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7867 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 470:
#line 2582 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 7875 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 2589 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *node = (yyvsp[0].node);
                    if(!node) {
                      node = NEW_STR(STR_NEW0());
                    } else {
                      node = evstr2dstr(node);
                    }
                    (yyval.node) = node;
                  }
#line 7889 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 2603 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7897 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 2609 "grammar.y" /* yacc.c:1661  */
    {
                    heredoc_dedent((yyvsp[-1].node));
                    heredoc_indent = 0;
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7907 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 2617 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *node = (yyvsp[-1].node);

                    heredoc_dedent((yyvsp[-1].node));
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
                    (yyval.node) = node;
                  }
#line 7935 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 2643 "grammar.y" /* yacc.c:1661  */
    {
                    intptr_t options = (yyvsp[0].num);
                    NODE *node = (yyvsp[-1].node);
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
                    (yyval.node) = node;
                  }
#line 7997 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 479:
#line 2703 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 8005 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 480:
#line 2707 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8013 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 481:
#line 2713 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8021 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 482:
#line 2717 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), evstr2dstr((yyvsp[-1].node)));
                  }
#line 8029 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 484:
#line 2724 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8037 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 485:
#line 2730 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 8045 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 486:
#line 2734 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8053 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 487:
#line 2740 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8061 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 488:
#line 2744 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-1].node) = evstr2dstr((yyvsp[-1].node));
                    nd_set_type((yyvsp[-1].node), NODE_DSYM);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 8071 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 489:
#line 2752 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 8079 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 490:
#line 2756 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8087 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 2762 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 8095 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 2766 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8103 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 493:
#line 2772 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8111 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 2776 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 8119 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 495:
#line 2782 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8127 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 496:
#line 2786 "grammar.y" /* yacc.c:1661  */
    {
                    VALUE lit;
                    lit = (yyvsp[-1].node)->nd_lit;
                    (yyvsp[-1].node)->nd_lit = ID2SYM(parser_intern_str(lit));
                    nd_set_type((yyvsp[-1].node), NODE_LIT);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 8139 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 497:
#line 2796 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8147 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 498:
#line 2800 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8155 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 499:
#line 2806 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8163 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 500:
#line 2810 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8171 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 501:
#line 2816 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8179 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 502:
#line 2820 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *head = (yyvsp[-1].node), *tail = (yyvsp[0].node);
                    if(!head) {
                      (yyval.node) = tail;
                    } else if(!tail) {
                      (yyval.node) = head;
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
                      (yyval.node) = list_append(head, tail);
                    }
                  }
#line 8204 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 504:
#line 2844 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                    SET_LEX_STATE(EXPR_BEG);
                  }
#line 8214 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 505:
#line 2850 "grammar.y" /* yacc.c:1661  */
    {
                    lex_strterm = (yyvsp[-1].node);
                    (yyval.node) = NEW_EVSTR((yyvsp[0].node));
                  }
#line 8223 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 506:
#line 2855 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cond_stack;
                    (yyval.val) = cmdarg_stack;
                    cond_stack = 0;
                    cmdarg_stack = 0;
                  }
#line 8234 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 507:
#line 2861 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                  }
#line 8243 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 508:
#line 2865 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = lex_state;
                    SET_LEX_STATE(EXPR_BEG);
                  }
#line 8252 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 509:
#line 2869 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = brace_nest;
                    brace_nest = 0;
                  }
#line 8261 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 510:
#line 2873 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = heredoc_indent;
                    heredoc_indent = 0;
                  }
#line 8270 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 511:
#line 2878 "grammar.y" /* yacc.c:1661  */
    {
                    cond_stack = (yyvsp[-7].val);
                    cmdarg_stack = (yyvsp[-6].val);
                    lex_strterm = (yyvsp[-5].node);
                    SET_LEX_STATE((yyvsp[-4].num));
                    brace_nest = (yyvsp[-3].num);
                    heredoc_indent = (yyvsp[-2].num);
                    heredoc_line_indent = -1;

                    if((yyvsp[-1].node)) (yyvsp[-1].node)->flags &= ~NODE_FL_NEWLINE;
                    (yyval.node) = new_evstr((yyvsp[-1].node));
                  }
#line 8287 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 512:
#line 2892 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_GVAR((yyvsp[0].id));}
#line 8293 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 513:
#line 2893 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_IVAR((yyvsp[0].id));}
#line 8299 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 514:
#line 2894 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_CVAR((yyvsp[0].id));}
#line 8305 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 516:
#line 2899 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_END);
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8314 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 521:
#line 2912 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_END);
                    (yyval.node) = dsym_node((yyvsp[-1].node));
                  }
#line 8323 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 523:
#line 2920 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = negate_lit((yyvsp[0].node));
                  }
#line 8331 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 533:
#line 2938 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_nil;}
#line 8337 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 534:
#line 2939 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_self;}
#line 8343 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 535:
#line 2940 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_true;}
#line 8349 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 536:
#line 2941 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_false;}
#line 8355 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 537:
#line 2942 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__FILE__;}
#line 8361 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 538:
#line 2943 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__LINE__;}
#line 8367 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 539:
#line 2944 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__ENCODING__;}
#line 8373 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 540:
#line 2948 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8383 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 541:
#line 2954 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8393 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 542:
#line 2962 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8401 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 543:
#line 2966 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8409 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 546:
#line 2976 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
#line 8418 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 547:
#line 2981 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8426 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 548:
#line 2985 "grammar.y" /* yacc.c:1661  */
    {
                    yyerrok;
                    (yyval.node) = 0;
                  }
#line 8435 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 549:
#line 2992 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
#line 8445 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 550:
#line 2997 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_kwarg;
                    in_kwarg = 1;
                    SET_LEX_STATE(lex_state | EXPR_LABEL);  /* force for args */
                  }
#line 8455 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 551:
#line 3003 "grammar.y" /* yacc.c:1661  */
    {
                    in_kwarg = !!(yyvsp[-2].num);
                    (yyval.node) = (yyvsp[-1].node);
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
#line 8466 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 552:
#line 3012 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8474 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 553:
#line 3016 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 8482 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 554:
#line 3020 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8490 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 555:
#line 3024 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 8498 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 556:
#line 3030 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8506 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 557:
#line 3034 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 8514 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 558:
#line 3040 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8522 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 559:
#line 3044 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8530 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 560:
#line 3048 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8538 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 561:
#line 3052 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8546 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 562:
#line 3056 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8554 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 563:
#line 3060 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8562 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 564:
#line 3064 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 8570 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 565:
#line 3068 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8578 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 566:
#line 3072 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8586 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 567:
#line 3076 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8594 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 568:
#line 3080 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8602 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 569:
#line 3084 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8610 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 570:
#line 3088 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8618 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 571:
#line 3092 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 8626 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 572:
#line 3096 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                    (yyval.node) = new_args(0, 0, 0, 0, (yyval.node));
                  }
#line 8635 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 573:
#line 3103 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a constant");
                    (yyval.id) = 0;
                  }
#line 8644 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 574:
#line 3108 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be an instance variable");
                    (yyval.id) = 0;
                  }
#line 8653 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 575:
#line 3113 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a global variable");
                    (yyval.id) = 0;
                  }
#line 8662 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 576:
#line 3118 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a class variable");
                    (yyval.id) = 0;
                  }
#line 8671 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 578:
#line 3126 "grammar.y" /* yacc.c:1661  */
    {
                    formal_argument(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8680 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 579:
#line 3133 "grammar.y" /* yacc.c:1661  */
    {
                    ID id = get_id((yyvsp[0].id));
                    arg_var(id);
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8690 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 580:
#line 3141 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ARGS_AUX((yyvsp[0].id), 1);
                  }
#line 8698 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 581:
#line 3145 "grammar.y" /* yacc.c:1661  */
    {
                    ID tid = internal_id();
                    arg_var(tid);
                    (yyvsp[-1].node)->nd_value = NEW_LVAR(tid);
                    (yyval.node) = NEW_ARGS_AUX(tid, 1);
                    (yyval.node)->nd_next = (yyvsp[-1].node);
                  }
#line 8710 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 583:
#line 3156 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                    (yyval.node)->nd_plen++;
                    (yyval.node)->nd_next = block_append((yyval.node)->nd_next, (yyvsp[0].node)->nd_next);
                  }
#line 8720 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 584:
#line 3164 "grammar.y" /* yacc.c:1661  */
    {
                    ID id = get_id((yyvsp[0].id));
                    arg_var(formal_argument(id));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8730 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 585:
#line 3172 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8739 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 586:
#line 3177 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8748 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 587:
#line 3184 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8757 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 588:
#line 3189 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8766 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 589:
#line 3196 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8774 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 590:
#line 3200 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while(kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8787 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 591:
#line 3211 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8795 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 592:
#line 3215 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while(kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8808 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 595:
#line 3230 "grammar.y" /* yacc.c:1661  */
    {
                    shadowing_lvar(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8817 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 596:
#line 3235 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = internal_id();
                    arg_var((yyval.id));
                  }
#line 8826 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 597:
#line 3242 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8835 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 598:
#line 3249 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8844 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 599:
#line 3256 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8852 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 600:
#line 3260 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8865 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 601:
#line 3271 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8873 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 602:
#line 3275 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8886 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 605:
#line 3290 "grammar.y" /* yacc.c:1661  */
    {
                    if(!is_local_id((yyvsp[0].id))) {
                      yy_error("rest argument must be local variable");
                    }
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8898 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 606:
#line 3298 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = internal_id();
                    arg_var((yyval.id));
                  }
#line 8907 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 609:
#line 3309 "grammar.y" /* yacc.c:1661  */
    {
                    if(!is_local_id((yyvsp[0].id)))
                      yy_error("block argument must be local variable");
                    else if(!in_block() && local_id((yyvsp[0].id)))
                      yy_error("duplicate block argument name");
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8920 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 610:
#line 3320 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8928 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 611:
#line 3324 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = 0;
                  }
#line 8936 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 612:
#line 3330 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 8946 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 613:
#line 3335 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_BEG);}
#line 8952 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 614:
#line 3336 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-1].node) == 0) {
                      yy_error("can't define singleton method for ().");
                    } else {
                      switch(nd_type((yyvsp[-1].node))) {
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
                        value_expr((yyvsp[-1].node));
                        break;
                      }
                    }
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8978 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 616:
#line 3361 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8986 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 618:
#line 3368 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_concat((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 8994 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 619:
#line 3374 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST((yyvsp[-2].node)), (yyvsp[0].node));
                  }
#line 9002 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 620:
#line 3378 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(NEW_LIT(ID2SYM((yyvsp[-1].id)))), (yyvsp[0].node));
                  }
#line 9010 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 621:
#line 3382 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(dsym_node((yyvsp[-2].node))), (yyvsp[0].node));
                  }
#line 9018 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 622:
#line 3386 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(0), (yyvsp[0].node));
                  }
#line 9026 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 635:
#line 3412 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = '.';
                  }
#line 9034 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 636:
#line 3416 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = tANDDOT;
                  }
#line 9042 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 638:
#line 3423 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = tCOLON2;
                  }
#line 9050 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 648:
#line 3447 "grammar.y" /* yacc.c:1661  */
    {yyerrok;}
#line 9056 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 651:
#line 3452 "grammar.y" /* yacc.c:1661  */
    {yyerrok;}
#line 9062 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 652:
#line 3455 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = 0;}
#line 9068 "grammar.cpp" /* yacc.c:1661  */
    break;


#line 9072 "grammar.cpp" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parser_state, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parser_state, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parser_state);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, parser_state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parser_state, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parser_state);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, parser_state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3457 "grammar.y" /* yacc.c:1906  */


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
