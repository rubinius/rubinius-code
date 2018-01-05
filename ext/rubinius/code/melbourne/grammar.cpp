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

#ifndef RE_OPTION_PEG
#define RE_OPTION_PEG                (8)
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


#line 495 "grammar.cpp" /* yacc.c:339  */

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
    keyword_fun = 261,
    keyword_undef = 262,
    keyword_begin = 263,
    keyword_rescue = 264,
    keyword_ensure = 265,
    keyword_end = 266,
    keyword_if = 267,
    keyword_unless = 268,
    keyword_then = 269,
    keyword_elsif = 270,
    keyword_else = 271,
    keyword_case = 272,
    keyword_when = 273,
    keyword_while = 274,
    keyword_until = 275,
    keyword_for = 276,
    keyword_break = 277,
    keyword_next = 278,
    keyword_redo = 279,
    keyword_retry = 280,
    keyword_in = 281,
    keyword_do = 282,
    keyword_do_cond = 283,
    keyword_do_block = 284,
    keyword_do_LAMBDA = 285,
    keyword_return = 286,
    keyword_yield = 287,
    keyword_super = 288,
    keyword_self = 289,
    keyword_nil = 290,
    keyword_true = 291,
    keyword_false = 292,
    keyword_and = 293,
    keyword_or = 294,
    keyword_not = 295,
    modifier_if = 296,
    modifier_unless = 297,
    modifier_while = 298,
    modifier_until = 299,
    modifier_rescue = 300,
    keyword_alias = 301,
    keyword_defined = 302,
    keyword_BEGIN = 303,
    keyword_END = 304,
    keyword__LINE__ = 305,
    keyword__FILE__ = 306,
    keyword__ENCODING__ = 307,
    tIDENTIFIER = 308,
    tFID = 309,
    tGVAR = 310,
    tIVAR = 311,
    tCONSTANT = 312,
    tCVAR = 313,
    tLABEL = 314,
    tINTEGER = 315,
    tFLOAT = 316,
    tRATIONAL = 317,
    tIMAGINARY = 318,
    tSTRING_CONTENT = 319,
    tCHAR = 320,
    tNTH_REF = 321,
    tBACK_REF = 322,
    tREGEXP_END = 323,
    tUPLUS = 324,
    tUMINUS = 325,
    tPOW = 326,
    tCMP = 327,
    tEQ = 328,
    tEQQ = 329,
    tNEQ = 330,
    tGEQ = 331,
    tLEQ = 332,
    tANDOP = 333,
    tOROP = 334,
    tMATCH = 335,
    tNMATCH = 336,
    tDOT2 = 337,
    tDOT3 = 338,
    tAREF = 339,
    tASET = 340,
    tLSHFT = 341,
    tRSHFT = 342,
    tANDDOT = 343,
    tCOLON2 = 344,
    tCOLON3 = 345,
    tOP_ASGN = 346,
    tASSOC = 347,
    tLPAREN = 348,
    tLPAREN_ARG = 349,
    tRPAREN = 350,
    tLBRACK = 351,
    tLBRACE = 352,
    tLBRACE_ARG = 353,
    tSTAR = 354,
    tDSTAR = 355,
    tAMPER = 356,
    tLAMBDA = 357,
    tSYMBEG = 358,
    tSTRING_BEG = 359,
    tXSTRING_BEG = 360,
    tREGEXP_BEG = 361,
    tWORDS_BEG = 362,
    tQWORDS_BEG = 363,
    tSYMBOLS_BEG = 364,
    tQSYMBOLS_BEG = 365,
    tSTRING_DBEG = 366,
    tSTRING_DEND = 367,
    tSTRING_DVAR = 368,
    tSTRING_END = 369,
    tLAMBEG = 370,
    tLABEL_END = 371,
    tLOWEST = 372,
    tUMINUS_NUM = 373,
    tLAST_TOKEN = 374
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 446 "grammar.y" /* yacc.c:355  */

    VALUE val;
    NODE *node;
    ID id;
    int num;
    const struct vtable* vars;

#line 661 "grammar.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (rb_parser_state* parser_state);



/* Copy the second part of user declarations.  */

#line 677 "grammar.cpp" /* yacc.c:358  */

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
#define YYLAST   11157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  212
/* YYNRULES -- Number of rules.  */
#define YYNRULES  639
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1077

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     146,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   144,   132,     2,     2,     2,   130,   125,     2,
     140,   141,   128,   126,   138,   127,   145,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   143,
     122,   118,   121,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   137,     2,   142,   124,     2,   139,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   135,   123,   136,   133,     2,     2,     2,
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
     115,   116,   117,   131,   134
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   605,   605,   605,   630,   637,   641,   645,   649,   655,
     657,   656,   668,   691,   698,   702,   706,   710,   716,   721,
     720,   730,   730,   734,   738,   745,   750,   754,   759,   764,
     772,   780,   785,   794,   795,   801,   806,   823,   828,   833,
     838,   843,   848,   853,   858,   861,   866,   873,   874,   878,
     882,   886,   890,   893,   901,   902,   905,   906,   913,   912,
     927,   934,   939,   947,   952,   959,   964,   971,   976,   981,
     985,   989,   995,   996,  1002,  1003,  1009,  1013,  1017,  1021,
    1025,  1029,  1033,  1037,  1041,  1045,  1051,  1052,  1058,  1062,
    1068,  1072,  1078,  1082,  1086,  1090,  1094,  1098,  1102,  1108,
    1114,  1121,  1126,  1131,  1135,  1139,  1143,  1147,  1153,  1159,
    1166,  1170,  1173,  1177,  1181,  1187,  1188,  1189,  1190,  1195,
    1202,  1203,  1206,  1210,  1213,  1217,  1217,  1223,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1255,  1255,  1255,
    1256,  1256,  1257,  1257,  1257,  1258,  1258,  1258,  1258,  1258,
    1259,  1259,  1259,  1259,  1260,  1260,  1260,  1261,  1261,  1261,
    1261,  1262,  1262,  1262,  1262,  1263,  1263,  1263,  1263,  1264,
    1264,  1264,  1264,  1265,  1265,  1265,  1265,  1266,  1266,  1269,
    1274,  1280,  1285,  1291,  1312,  1317,  1322,  1327,  1332,  1337,
    1342,  1348,  1354,  1358,  1362,  1366,  1370,  1374,  1378,  1382,
    1386,  1390,  1394,  1398,  1402,  1406,  1410,  1414,  1418,  1422,
    1426,  1430,  1434,  1444,  1448,  1452,  1456,  1460,  1464,  1468,
    1472,  1472,  1477,  1483,  1489,  1497,  1498,  1502,  1506,  1512,
    1518,  1519,  1522,  1523,  1524,  1528,  1532,  1538,  1543,  1547,
    1552,  1557,  1560,  1560,  1572,  1578,  1582,  1588,  1592,  1596,
    1605,  1616,  1617,  1620,  1629,  1638,  1644,  1645,  1646,  1647,
    1648,  1649,  1650,  1651,  1652,  1653,  1654,  1659,  1658,  1678,
    1678,  1683,  1687,  1682,  1692,  1696,  1700,  1704,  1712,  1716,
    1720,  1724,  1728,  1732,  1732,  1737,  1741,  1745,  1751,  1752,
    1759,  1763,  1771,  1779,  1779,  1779,  1786,  1786,  1786,  1793,
    1800,  1805,  1807,  1804,  1824,  1823,  1840,  1839,  1859,  1858,
    1875,  1880,  1874,  1896,  1901,  1895,  1916,  1917,  1916,  1933,
    1937,  1941,  1945,  1951,  1959,  1965,  1971,  1977,  1983,  1989,
    1995,  2001,  2007,  2013,  2020,  2027,  2033,  2034,  2035,  2038,
    2039,  2042,  2043,  2052,  2053,  2059,  2060,  2063,  2067,  2073,
    2077,  2083,  2087,  2092,  2097,  2101,  2105,  2110,  2115,  2119,
    2125,  2129,  2133,  2137,  2143,  2148,  2153,  2157,  2161,  2165,
    2169,  2173,  2177,  2181,  2185,  2189,  2193,  2197,  2201,  2205,
    2209,  2215,  2216,  2222,  2227,  2231,  2238,  2242,  2249,  2254,
    2261,  2267,  2273,  2276,  2281,  2284,  2273,  2299,  2303,  2309,
    2313,  2320,  2319,  2334,  2345,  2349,  2356,  2365,  2372,  2371,
    2381,  2380,  2389,  2394,  2393,  2403,  2402,  2411,  2415,  2419,
    2431,  2430,  2443,  2442,  2456,  2464,  2465,  2468,  2480,  2483,
    2487,  2491,  2494,  2498,  2501,  2505,  2508,  2509,  2513,  2516,
    2528,  2529,  2530,  2536,  2544,  2570,  2630,  2634,  2641,  2644,
    2650,  2651,  2657,  2661,  2668,  2671,  2679,  2683,  2689,  2693,
    2700,  2703,  2710,  2713,  2724,  2727,  2734,  2737,  2744,  2747,
    2770,  2772,  2771,  2783,  2789,  2793,  2797,  2801,  2782,  2820,
    2821,  2822,  2823,  2826,  2833,  2834,  2835,  2836,  2839,  2846,
    2847,  2853,  2854,  2855,  2856,  2859,  2860,  2861,  2862,  2863,
    2866,  2867,  2868,  2869,  2870,  2871,  2872,  2875,  2881,  2889,
    2893,  2899,  2900,  2904,  2903,  2913,  2919,  2925,  2925,  2939,
    2943,  2947,  2951,  2957,  2962,  2967,  2971,  2975,  2979,  2983,
    2987,  2991,  2995,  2999,  3003,  3007,  3011,  3015,  3019,  3024,
    3030,  3035,  3040,  3045,  3052,  3053,  3060,  3068,  3072,  3082,
    3083,  3091,  3099,  3104,  3111,  3116,  3123,  3127,  3138,  3142,
    3153,  3154,  3157,  3162,  3169,  3176,  3183,  3187,  3198,  3202,
    3213,  3214,  3217,  3225,  3232,  3233,  3236,  3247,  3251,  3257,
    3263,  3263,  3287,  3288,  3294,  3295,  3301,  3305,  3309,  3313,
    3319,  3320,  3321,  3324,  3325,  3326,  3327,  3330,  3331,  3332,
    3335,  3336,  3339,  3343,  3349,  3350,  3356,  3357,  3360,  3361,
    3364,  3367,  3370,  3371,  3372,  3375,  3376,  3379,  3380,  3383
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end-of-input\"", "error", "$undefined", "keyword_class",
  "keyword_module", "keyword_def", "keyword_fun", "keyword_undef",
  "keyword_begin", "keyword_rescue", "keyword_ensure", "keyword_end",
  "keyword_if", "keyword_unless", "keyword_then", "keyword_elsif",
  "keyword_else", "keyword_case", "keyword_when", "keyword_while",
  "keyword_until", "keyword_for", "keyword_break", "keyword_next",
  "keyword_redo", "keyword_retry", "keyword_in", "keyword_do",
  "keyword_do_cond", "keyword_do_block", "keyword_do_LAMBDA",
  "keyword_return", "keyword_yield", "keyword_super", "keyword_self",
  "keyword_nil", "keyword_true", "keyword_false", "keyword_and",
  "keyword_or", "keyword_not", "modifier_if", "modifier_unless",
  "modifier_while", "modifier_until", "modifier_rescue", "keyword_alias",
  "keyword_defined", "keyword_BEGIN", "keyword_END", "keyword__LINE__",
  "keyword__FILE__", "keyword__ENCODING__", "tIDENTIFIER", "tFID", "tGVAR",
  "tIVAR", "tCONSTANT", "tCVAR", "tLABEL", "tINTEGER", "tFLOAT",
  "tRATIONAL", "tIMAGINARY", "tSTRING_CONTENT", "tCHAR", "tNTH_REF",
  "tBACK_REF", "tREGEXP_END", "tUPLUS", "tUMINUS", "tPOW", "tCMP", "tEQ",
  "tEQQ", "tNEQ", "tGEQ", "tLEQ", "tANDOP", "tOROP", "tMATCH", "tNMATCH",
  "tDOT2", "tDOT3", "tAREF", "tASET", "tLSHFT", "tRSHFT", "tANDDOT",
  "tCOLON2", "tCOLON3", "tOP_ASGN", "tASSOC", "tLPAREN", "tLPAREN_ARG",
  "tRPAREN", "tLBRACK", "tLBRACE", "tLBRACE_ARG", "tSTAR", "tDSTAR",
  "tAMPER", "tLAMBDA", "tSYMBEG", "tSTRING_BEG", "tXSTRING_BEG",
  "tREGEXP_BEG", "tWORDS_BEG", "tQWORDS_BEG", "tSYMBOLS_BEG",
  "tQSYMBOLS_BEG", "tSTRING_DBEG", "tSTRING_DEND", "tSTRING_DVAR",
  "tSTRING_END", "tLAMBEG", "tLABEL_END", "tLOWEST", "'='", "'?'", "':'",
  "'>'", "'<'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "tUMINUS_NUM", "'!'", "'~'", "tLAST_TOKEN", "'{'", "'}'", "'['", "','",
  "'`'", "'('", "')'", "']'", "';'", "' '", "'.'", "'\\n'", "$accept",
  "program", "$@1", "top_compstmt", "top_stmts", "top_stmt", "$@2",
  "bodystmt", "compstmt", "stmts", "stmt_or_begin", "$@3", "stmt", "$@4",
  "command_asgn", "expr", "expr_value", "command_call", "block_command",
  "cmd_brace_block", "@5", "fcall", "command", "mlhs", "mlhs_inner",
  "mlhs_basic", "mlhs_item", "mlhs_head", "mlhs_post", "mlhs_node", "lhs",
  "cname", "cpath", "fname", "fsym", "fitem", "undef_list", "$@6", "op",
  "reswords", "arg", "$@7", "arg_value", "aref_args", "paren_args",
  "opt_paren_args", "opt_call_args", "call_args", "command_args", "@8",
  "block_arg", "opt_block_arg", "args", "mrhs_arg", "mrhs", "primary",
  "@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "@20", "@21", "@22", "@23", "@24", "@25", "@26", "@27",
  "$@28", "primary_value", "k_begin", "k_if", "k_unless", "k_while",
  "k_until", "k_case", "k_for", "k_class", "k_module", "k_def", "k_fun",
  "k_end", "then", "do", "if_tail", "opt_else", "for_var", "f_marg",
  "f_marg_list", "f_margs", "block_args_tail", "opt_block_args_tail",
  "block_param", "opt_block_param", "block_param_def", "opt_bv_decl",
  "bv_decls", "bvar", "lambda", "@29", "@30", "@31", "@32", "f_larglist",
  "lambda_body", "do_block", "@33", "block_call", "method_call", "@34",
  "@35", "@36", "@37", "brace_block", "@38", "@39", "case_body", "cases",
  "opt_rescue", "exc_list", "exc_var", "opt_ensure", "literal", "strings",
  "string", "string1", "xstring", "regexp", "words", "word_list", "word",
  "symbols", "symbol_list", "qwords", "qsymbols", "qword_list",
  "qsym_list", "string_contents", "xstring_contents", "regexp_contents",
  "string_content", "@40", "@41", "@42", "@43", "@44", "@45",
  "string_dvar", "symbol", "sym", "dsym", "numeric", "simple_numeric",
  "user_variable", "keyword_variable", "var_ref", "var_lhs", "backref",
  "superclass", "$@46", "f_arglist", "@47", "args_tail", "opt_args_tail",
  "f_args", "f_bad_arg", "f_norm_arg", "f_arg_asgn", "f_arg_item", "f_arg",
  "f_label", "f_kw", "f_block_kw", "f_block_kwarg", "f_kwarg",
  "kwrest_mark", "f_kwrest", "f_opt", "f_block_opt", "f_block_optarg",
  "f_optarg", "restarg_mark", "f_rest_arg", "blkarg_mark", "f_block_arg",
  "opt_f_block_arg", "singleton", "$@48", "assoc_list", "assocs", "assoc",
  "operation", "operation2", "operation3", "dot_or_colon", "call_op",
  "call_op2", "opt_terms", "opt_nl", "rparen", "rbracket", "trailer",
  "term", "terms", "none", YY_NULLPTR
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
     365,   366,   367,   368,   369,   370,   371,   372,    61,    63,
      58,    62,    60,   124,    94,    38,    43,    45,    42,    47,
      37,   373,    33,   126,   374,   123,   125,    91,    44,    96,
      40,    41,    93,    59,    32,    46,    10
};
# endif

#define YYPACT_NINF -837

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-837)))

#define YYTABLE_NINF -640

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-640)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -837,   134,  2842,  -837,  7514,  -837,  -837,  -837,  -837,  7125,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  7631,  7631,  -837,
    -837,  7631,  4204,  3787,  -837,  -837,  -837,  -837,   359,  6988,
      -1,  -837,    40,  -837,  -837,  -837,  3092,  3926,  -837,  -837,
    3231,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  9035,
    9035,   105,  5294,   190,  7982,  8333,  2720,  -837,  6851,  -837,
    -837,  -837,    50,    72,   145,   159,   834,  9152,  9035,  -837,
     487,  -837,  1075,  -837,   497,  -837,  -837,    61,   216,   137,
    -837,   214,  9386,  -837,   255,  2430,   477,   539,  -837,  9269,
    9269,  -837,  -837,  6221,  9499,  9612,  9725,  6713,  7262,   381,
      73,  -837,  -837,   356,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,    46,   223,  -837,   347,   436,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,   345,  -837,  -837,  -837,  -837,   367,  9035,   455,  5438,
    9035,  9035,  9035,  -837,  9035,  -837,   403,  2430,   437,  -837,
    -837,   399,   675,    31,   290,   452,   293,   409,  -837,  -837,
    -837,  6104,  -837,  7631,  7631,  -837,  -837,  6338,  -837,  9269,
     576,  -837,   413,   420,  5582,  -837,  -837,  -837,   439,   446,
      61,  -837,   703,   501,   608,  7748,  -837,  5294,   447,   487,
    -837,  1075,    -1,   492,  -837,    -1,  9269,   456,   261,   303,
    -837,   437,   485,   303,  -837,    -1,   566,   834,  9838,   506,
    -837,   713,   815,   833,   835,  -837,  -837,  -837,  -837,  -837,
    -837,   445,  -837,   504,   710,   480,   512,   722,   520,    43,
     533,   850,   535,    47,   579,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  6455,  9269,  9269,  9269,  9269,  7748,  9269,  9269,
    -837,  -837,  -837,   558,  -837,  -837,  -837,  8450,  -837,  5294,
    7394,   529,  8450,  9035,  9035,  9035,  9035,  9035,  9035,  9035,
    9035,  9035,  9035,  9035,  9035,  9035,  9035,  9035,  9035,  9035,
    9035,  9035,  9035,  9035,  9035,  9035,  9035,  9035,  9035,  -837,
    2525,  7631,  -837, 10127,  4628,   497,    98,    98,  9269,  9269,
     487,   640,   525,   616,  -837,  -837,   885,   649,    64,    77,
      82,   780,   923,  9269,    60,  -837,   580,   906,  -837,  -837,
    -837,  -837,    21,    26,    54,    62,    65,   286,   294,   305,
     309,  -837,  -837,  -837,   312,  -837,  -837,  -837, 10208,  -837,
    -837,  9152,  9152,  -837,  -837,   299,  -837,  -837,  -837,   574,
    9035,  9035,  7865,  -837,  -837, 10289,  7631, 10370,  9035,  9035,
    8099,  -837,    -1,   557,  -837,  -837,    -1,  -837,   565,   567,
    -837,   382,  -837,  -837,  -837,  -837,  -837,  7125,  -837,  9035,
    5726,   573, 10289, 10370,  9035,  1075,   583,    -1,  -837,  -837,
    6572,   582,  -837,   497,  -837,  8216,  -837,  -837,  8333,  -837,
    -837,  -837,   413,   912,  -837,  -837,   593,  9838, 10451,  7631,
   10532,  1416,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,   488,  -837,  -837,   570,  -837,  -837,
    -837,   496,  -837,   589,  -837,  9035,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,   184,   184,  -837,  -837,   184,
    9035,  -837,   599,   610,  -837,  -837,    -1,  9838,   614,  -837,
    -837,  -837,   639,  2065,  -837,  -837,   501,  3070,  3070,  3070,
    3070,  1245,  1245,  3209,  2931,  3070,  3070,  2555,  2555,   783,
     783,  2369,  1245,  1245,  1036,  1036,  1191,    58,    58,   501,
     501,   501,  4343,  3370,  4482,  3509,   446,   628,  -837,    -1,
     660,  -837,   752,  -837,   446,  4065,   782,   747,  -837,  4772,
     785,  5060,   263,   263,   640,  8567,   782,    83, 10613,  7631,
   10694,  -837,   497,  -837,   912,  -837,  -837,  -837, 10775,  7631,
   10208,  4628,  9269,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    1734,  -837,  2181,  -837,  2430,  7125,  9035,  2246,  -837,  9035,
     437,  -837,   409,  2953,  3648,    -1,   368,   371,  -837,  -837,
    -837,  -837,  7865,  8099,  -837,  -837,  9269,  2430,   664,  -837,
    -837,  -837,  2430,  5726,   334,  -837,    -1,   303,  9838,   593,
     400,   357,    -1,   393,   432,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  1099,  -837,  -837,  -837,  -837,  -837,  1449,  -837,
    -837,  -837,  -837,  -837,   678,  -837,   665,  9035,  -837,   672,
     758,   680,  -837,   681,   773,   693,   786,  -837,  -837,  1043,
    -837,  -837,  -837,  -837,  -837,   501,  -837,  1295,  5870,  -837,
    -837,  5582,   184,  5870,   706,  8684,  -837,   593,  9838,  9152,
    9035,   721,  9152,  9152,  -837,   558,   446,   720,   828,  9152,
    9152,  -837,   558,   446,  -837,  -837,  8801,   829,  -837,   547,
    -837,   829,  -837,  -837,  -837,  -837,   782,   333,  -837,    88,
     272,    -1,    97,   101,  9269,   487,  9269,  4628,   991,   357,
    -837,    -1,   782,   382,   715,  7262,   715,  -837,    73,   216,
    -837,  9035,  -837,  -837,  -837,  -837,  9035,  9035,   431,  9035,
    9035,   728,   382,  -837,   737,  -837,  -837,  -837,   465,  1099,
     638,  -837,   741,    -1,  -837,    -1,  -837,  9035,  1449,  -837,
    -837,   607,  -837,  -837,  -837,   341,  -837,  1449,  -837,  -837,
    1188,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
      -1,   759,   763,   746,  9951,  -837,   751,   680,  -837,   753,
     762,  -837,   742,   890,   771,  5582,   905,  9035,   788,   593,
    2430,  9035,  -837,  2430,  -837,  2430,  -837,  -837,  -837,  9152,
    -837,  2430,  -837,  2430,  -837,  -837,   599,  -837,   826,  -837,
    5177,   917,  -837,  9269,   782,  -837,   782,  5870,  5870,  -837,
    8918,  4916,   116,   263,  4628,   487,   782,  -837,  -837,  -837,
    1449,  4628,  1449,  -837,  4628,  -837,  -837,  2430,  9035,  8099,
    -837,  -837,    -1,  1426,   790,  1352,  -837,   791,    76,  -837,
    -837,  -837,   796,   801,  -837,   680,  -837,   803,  -837,   813,
    -837,   803,  -837,   830,  -837,  9951,  1449,  -837,   898,   966,
     607,  -837,  -837,  1449,  -837,  1188,  -837,  1028,  -837,  -837,
     820,  -837,   819,  2430,  -837,  2430, 10064,    98,  -837,  -837,
    5870,  -837,  -837,    98,  -837,  -837,   782,   782,  -837,   114,
    -837,   782,  -837,  -837,    -1,   782,   487,   715,   782,  -837,
     824,  1426,   727,  -837,  -837,  5870,  5582,  -837,  1449,  -837,
    1188,  -837,  -837,  1188,  -837,  1188,  -837,  -837,  -837,  -837,
     966,  -837,   831,   838,  -837, 10856,  -837,   680,   841,  -837,
     843,   841,  -837,   358,  -837,  -837,  -837,   911,  -837,   976,
     121,   183,   200,  4628,  -837,  4772,  -837,  -837,  -837,  -837,
    -837,  5870,  -837,  -837,  -837,  -837,  4628,  -837,  1426,   824,
    1426,   844,   960,   849,   803,   852,   803,   803,  5987,  1449,
    -837,  1188,  -837,   857,   859,  -837,  1188,  -837,  1188,  -837,
    -837,  1028,  -837,   219, 10937,  7631, 11018,   747,   547,   782,
     782,   824,  1426,  -837,  -837,  -837,  1188,  -837,  -837,  -837,
     894,   841,   872,   841,   841,  -837,   156,   166,    -1,   342,
     344,  -837,  -837,  -837,  -837,   824,   803,  -837,  -837,  1188,
    -837,  -837,  -837,   349,  -837,   841,  -837
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,   351,   352,   353,   354,     0,
     344,   345,   346,   349,   347,   348,   350,   339,   340,   341,
     342,   299,   262,   262,   521,   520,   522,   523,   628,     0,
     628,    10,     0,   525,   524,   526,   610,   612,   517,   516,
     611,   519,   511,   512,   513,   514,   460,   531,   532,     0,
       0,     0,     0,   291,   639,   639,    84,   412,   486,   484,
     486,   488,   468,   480,   474,   482,     0,     0,     0,     3,
     626,     6,     9,    33,    44,    47,    55,   262,    54,     0,
      72,     0,    76,    86,     0,    52,   243,     0,   287,     0,
       0,   313,   316,   626,     0,     0,     0,     0,     0,    56,
     308,   276,   277,   459,   461,   278,   279,   280,   282,   281,
     283,   457,   458,   456,   509,   527,   528,   284,     0,   285,
      60,     5,     8,   167,   179,   168,   169,   192,   164,   185,
     175,   174,   195,   196,   190,   173,   172,   166,   193,   197,
     198,   177,   165,   180,   184,   186,   178,   171,   187,   194,
     189,   188,   181,   191,   176,   163,   183,   182,   162,   170,
     160,   161,   157,   158,   159,   115,   117,   116,   152,   153,
     148,   130,   131,   132,   139,   136,   138,   133,   134,   154,
     155,   140,   141,   145,   149,   135,   137,   127,   128,   129,
     142,   143,   144,   146,   147,   150,   151,   156,   120,   122,
     124,    26,   118,   119,   121,   123,     0,     0,     0,     0,
       0,     0,     0,   484,     0,   257,     0,   244,   267,    70,
     261,   639,     0,   527,   528,     0,   285,   639,   604,    71,
      69,   628,    68,     0,   639,   437,    67,   628,   629,     0,
       0,    21,   240,     0,     0,   339,   340,   299,   302,   438,
       0,   219,     0,   220,   296,     0,    19,     0,     0,   626,
      15,    18,   628,    74,    14,   628,     0,     0,   632,   632,
     245,     0,     0,   632,   602,   628,     0,     0,     0,    82,
     343,     0,    92,    93,   100,   310,   413,   506,   505,   507,
     504,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   510,    51,   234,   235,   635,   636,
       4,   637,   627,     0,     0,     0,     0,     0,     0,     0,
     442,   440,   427,    61,   307,   421,   423,     0,    88,     0,
      80,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   623,
     435,   639,   622,   433,     0,    53,     0,     0,     0,     0,
     626,     0,   627,     0,   366,   365,     0,     0,   527,   528,
     285,   110,   111,     0,     0,   113,   535,     0,   527,   528,
     285,   328,   188,   181,   191,   176,   157,   158,   159,   115,
     116,   600,   330,   599,     0,   333,   625,   624,     0,   309,
     462,     0,     0,   125,   607,   296,   268,   609,   264,     0,
       0,     0,     0,   258,   266,   435,   639,   433,     0,     0,
       0,   259,   628,     0,   301,   263,   628,   253,   639,   639,
     252,   628,   306,    50,    23,    25,    24,     0,   303,     0,
       0,     0,   435,   433,     0,    17,     0,   628,   294,    13,
     627,    73,   290,   292,   297,   634,   633,   246,   634,   248,
     298,   603,     0,    99,   510,    90,    85,     0,   435,   639,
     433,   559,   490,   493,   491,   508,   487,   463,   485,   464,
     465,   489,   466,   467,     0,   470,   476,     0,   477,   472,
     473,     0,   478,     0,   479,     0,   638,     7,    27,    28,
      29,    30,    31,    48,    49,   639,   639,    58,    62,   639,
       0,    34,   272,     0,    43,   271,   628,     0,    78,    89,
      46,    45,     0,   199,   267,    42,   217,   224,   229,   230,
     231,   226,   228,   238,   239,   232,   233,   210,   211,   236,
     237,   628,   225,   227,   221,   222,   223,   212,   213,   214,
     215,   216,   613,   615,   614,   616,     0,   262,   432,   628,
     613,   615,   614,   616,     0,   262,     0,   639,   357,     0,
     356,     0,     0,     0,     0,     0,     0,   296,   435,   639,
     433,   321,   326,   110,   111,   112,   533,   324,   435,   639,
     433,     0,     0,   331,   621,   620,   336,   334,   613,   614,
     262,    35,   201,    41,   209,     0,     0,   199,   606,     0,
     269,   265,   639,   613,   614,   628,   613,   614,   605,   300,
     630,   249,   254,   256,   305,    22,     0,   241,     0,    32,
     430,   428,   208,     0,    75,    16,   628,   632,     0,    83,
     617,    98,   628,   613,   614,   565,   562,   561,   560,   563,
     571,   580,     0,   591,   581,   595,   594,   590,   559,   414,
     558,   418,   564,   566,   567,   569,   544,   573,   578,   639,
     583,   639,   588,   544,   593,   544,     0,   542,   494,     0,
     469,   471,   481,   475,   483,   218,   404,   628,     0,   402,
     401,     0,   639,     0,   275,     0,    87,    81,     0,     0,
       0,     0,     0,     0,   436,    65,     0,     0,   439,     0,
       0,   434,    63,   639,   355,   288,   639,   639,   448,   639,
     358,   639,   360,   314,   359,   317,     0,     0,   320,   617,
     295,   628,   613,   614,     0,     0,     0,     0,   110,   111,
     114,   628,     0,   628,   537,     0,   537,   251,   424,    57,
     250,     0,   126,   608,   270,   260,     0,     0,   439,     0,
       0,   639,   628,    11,     0,   293,   247,    91,   439,     0,
     378,   369,   371,   628,   367,   628,   415,     0,     0,   551,
     572,     0,   540,   598,   582,     0,   541,     0,   554,   592,
       0,   556,   596,   495,   499,   500,   501,   492,   502,   400,
     628,     0,   567,   385,   575,   576,   639,   639,   586,   385,
     385,   383,   406,     0,     0,     0,     0,     0,   273,    79,
     200,     0,    40,   206,    39,   207,    66,   431,   631,     0,
      37,   204,    38,   205,    64,   429,   449,   450,   639,   451,
       0,   639,   363,     0,     0,   361,     0,     0,     0,   319,
       0,     0,   439,     0,     0,     0,     0,   439,   329,   601,
     559,     0,   559,   337,     0,   425,   426,   202,     0,   255,
     304,    20,   628,     0,   376,     0,   568,     0,     0,   584,
     543,   570,   544,   544,   579,   639,   597,   544,   589,   544,
     567,   544,   496,     0,   403,     0,   391,   393,     0,   574,
       0,   381,   382,     0,   396,     0,   398,     0,   443,   441,
       0,   422,   274,   242,    36,   203,     0,     0,   453,   364,
       0,    12,   455,     0,   311,   312,     0,     0,   269,   639,
     322,     0,   534,   325,   628,     0,     0,   537,     0,   368,
     379,     0,   374,   370,   417,     0,     0,   416,     0,   547,
       0,   549,   539,     0,   555,     0,   552,   557,   497,   405,
     585,   384,   385,   385,   296,   435,   577,   639,   385,   587,
     385,   385,   410,   628,   408,   411,    59,     0,   452,     0,
     527,   528,   285,     0,   454,     0,   315,   318,   445,   446,
     444,     0,   327,   536,   332,   538,     0,   335,     0,   377,
       0,   372,     0,     0,   544,   544,   544,   544,     0,     0,
     388,     0,   390,   617,   295,   380,     0,   397,     0,   394,
     399,     0,   407,   296,   435,   639,   433,   639,   639,     0,
       0,   375,     0,   420,   419,   548,     0,   545,   550,   553,
       0,   385,   385,   385,   385,   409,   617,   295,   628,   613,
     614,   447,   362,   323,   338,   373,   544,   498,   389,     0,
     386,   392,   395,   439,   546,   385,   387
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -837,  -837,  -837,  -372,  -837,    27,  -837,  -574,   745,  -837,
     553,  -837,    70,  -837,  -320,    35,   -64,    53,  -837,  -241,
    -837,   426,    -4,   920,  -166,    11,   -72,  -837,  -438,     8,
    1713,  -333,   921,   -36,  -837,     4,  -837,  -837,  -306,  -837,
     881,  -837,   -52,  -837,   -68,   296,  -346,   160,     2,  -837,
    -354,  -226,    28,  -837,  -324,   -54,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,     3,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   111,  -337,
    -539,   -22,  -656,  -837,  -816,  -825,   241,   326,   124,  -837,
    -415,  -837,  -669,  -837,    -7,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,   267,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
     -94,  -837,  -837,  -565,  -837,    -8,  -837,  -837,  -837,  -837,
    -837,  -837,   929,  -837,  -837,  -837,  -837,   736,  -837,  -837,
    -837,  -837,  -837,  -837,   827,   979,  -837,  -157,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,     9,  -837,    14,  -837,   -29,
    1085,  1360,   944,  1838,  1527,  -837,  -837,  -690,  -837,  -445,
     174,  -584,  -836,  -575,  -136,  -741,   245,   -35,   253,   136,
    -837,  -837,  -837,   -81,  -702,  -808,   144,   265,  -837,  -579,
    -837,  -518,  -649,  -837,  -837,  -837,   135,  -395,  -837,  -277,
    -837,  -837,   -83,  -837,   -28,    20,   551,  -558,  -213,   -59,
       7,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    69,    70,    71,   243,   576,   577,   259,
     260,   456,   261,   447,    73,    74,   366,    75,    76,   518,
     702,   250,    78,    79,   262,    80,    81,    82,   476,    83,
     216,   385,   386,   198,   199,   200,   201,   615,   202,   203,
      85,   449,   218,   267,   235,   758,   436,   437,   232,   233,
     220,   423,   438,   524,   525,    86,   364,   265,   266,   646,
     636,   368,   857,   369,   858,   744,  1001,   747,   745,   601,
     603,   754,   607,   756,   755,   947,   252,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   725,   579,
     733,   854,   855,   377,   781,   782,   783,   971,   907,   810,
     698,   699,   811,   983,   984,   285,   286,   481,   786,   888,
     669,   957,   326,   519,    99,   100,   723,   716,   574,   566,
     324,   516,   515,   586,  1000,   727,   848,   927,   931,   101,
     102,   103,   104,   105,   106,   107,   297,   494,   108,   301,
     109,   110,   299,   303,   293,   291,   295,   486,   689,   688,
     803,   902,   968,  1018,   807,   111,   292,   112,   113,   114,
     223,   224,   117,   225,   226,   597,   746,   871,   872,   890,
     789,   671,   672,   673,   900,   675,   676,   677,   678,   815,
     816,   679,   680,   681,   682,   818,   819,   683,   684,   685,
     686,   687,   792,   404,   602,   272,   439,   228,   120,   640,
     568,   606,   600,   408,   310,   433,   434,   718,   467,   580,
     372,   264
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,   431,   280,   271,   363,    87,   409,    87,   535,   322,
     331,   311,   530,   215,   215,   569,   407,   215,   204,   736,
     222,   222,   290,   205,   222,   236,   367,   752,   280,   370,
     581,   122,   796,   241,   311,   628,   670,   304,   204,   649,
     280,   280,   280,   205,   735,   221,   221,   891,   239,   221,
     242,   595,   270,   274,   565,    87,   469,   573,   950,   281,
     471,   402,   405,   263,   279,   371,   874,   768,   621,   953,
     222,   851,    72,   628,    72,   856,   621,   312,   638,   323,
     625,   985,   268,   567,   785,   281,   575,   784,   320,   707,
    -101,   457,   222,   222,   778,   898,   222,   376,   387,   387,
     320,   701,   573,  -102,   703,   979,   955,   497,  -109,  -108,
    -521,   503,   578,   593,  -105,  -520,   887,   594,   820,   565,
     305,   573,  -529,  -104,   365,   365,  1009,  -106,   365,   333,
     850,   610,   585,   652,     3,  -101,   488,  -529,   491,   427,
     495,   903,  -103,  -522,   495,   238,   565,   573,   567,  -101,
     575,  -523,   227,   227,  -525,   414,   227,   498,   416,   417,
     418,   504,   254,   526,  -101,   891,  -521,   911,   912,   453,
    -105,  -520,   565,   866,   573,   244,   641,   219,   229,   821,
    -107,   230,   322,   862,   -92,  1041,   356,   357,   358,   269,
     273,   956,   953,   867,   296,   985,   321,  -102,   480,  -522,
     311,   234,   -92,   641,   784,   884,   475,  -523,   321,   893,
    -525,   979,    87,   431,  -109,   -93,   298,  1065,   899,   424,
    -100,   -99,   891,   670,   280,   424,   -96,   215,  -613,   215,
     215,   459,   440,  -108,   222,   -95,   222,   222,   628,   -97,
     222,   308,   222,   741,   309,   325,   962,    87,   474,   508,
     509,   510,   511,   751,   -94,   327,   898,  1006,    87,   221,
      87,   221,   488,   696,  -101,   750,   460,  -101,   263,   222,
     829,   774,   441,   896,   443,   522,   280,   896,   621,   621,
     534,   281,   565,   998,   573,   891,   944,   825,   946,   300,
     941,   732,   565,   590,   573,   472,  -613,   945,  -107,  -105,
     948,   463,  -105,   302,   582,   583,  -614,   697,   784,  -107,
     784,   311,  -107,   641,  -530,    87,   222,   222,   222,   222,
      87,   222,   222,   641,   940,   455,  -102,   973,  1025,  -102,
     222,  -289,    87,   281,   980,   222,  -289,   691,   528,   507,
     263,  -102,   584,  -109,   691,   674,  -109,   578,   365,   365,
     365,   365,   328,   513,   514,   523,  -104,   215,  -106,   440,
     523,   -93,  -108,  -103,   222,  -108,   227,    87,   227,   618,
     620,   222,   222,   332,   999,  -524,   784,  1011,   271,  1015,
     521,  -530,    72,  -526,   429,   531,   222,   512,   821,   530,
     454,   432,   896,   435,  -515,   821,   765,   821,  -518,   465,
     861,   604,   847,   365,   365,   475,   308,   466,  -102,   309,
     -98,  -109,  -614,   620,   222,   222,   271,  -108,   592,   -95,
     318,   319,   215,   280,   440,   670,   -96,   670,    77,   222,
      77,  -524,  1040,   784,   776,   784,   424,   424,   411,  -526,
    1052,   468,   665,    77,    77,  -295,  -295,    77,   121,   466,
    -515,   635,   -73,    87,  -518,   475,   204,   605,   -97,   769,
      59,   205,   770,    87,   611,   613,   666,   784,   704,   359,
     406,   860,   -87,   280,   836,   215,   308,   440,    77,   309,
     281,   844,   222,   413,   628,  -104,  -104,  -106,  -104,  -106,
    -106,   -94,  -103,    77,  -295,  -103,  1031,  -614,   714,   237,
    1073,   821,  -295,   821,   238,   238,   721,   237,   821,   482,
     821,   -95,   415,   700,   700,    77,    77,   700,   -96,    77,
      72,   420,   878,   734,   734,   621,   362,   412,   238,   421,
     281,   -95,   674,   534,   -95,   318,   319,   422,   -96,   -95,
    -613,   -96,   757,   428,   482,   765,   -96,   430,   490,  -103,
     -97,   821,   482,   448,  -109,   450,   483,   622,   484,   485,
     482,   812,   853,   850,   763,  -343,  -343,   764,   482,   715,
     -97,   711,   333,   -97,  -100,   728,   777,   722,   -97,   231,
     620,   271,    87,   -94,    87,   215,   234,   440,   458,   717,
     993,   483,   222,   484,   280,   215,   995,   440,   464,   483,
     647,   484,   222,   -94,    87,   222,   -94,   483,   760,   484,
     -72,   -94,   759,   737,  -343,   483,   817,   484,   487,   762,
     424,   470,  -343,   473,   204,   790,   492,   359,   360,   205,
     308,   444,   690,   309,   496,    77,   475,   753,   482,   222,
     693,   121,   445,   446,   477,   717,    87,   499,   837,   502,
     505,   281,   674,   828,   280,   757,   517,    77,   585,    77,
      77,   674,   814,    77,   875,    77,   660,   529,   506,   565,
      77,   772,   717,   587,   846,   591,   361,   793,   661,   793,
     863,    77,   865,    77,   362,   483,   864,   484,   487,  1058,
     616,   655,    77,   656,   657,   658,   659,   738,   630,   454,
     700,    87,   596,   632,    87,   633,    87,   664,   665,   639,
     895,   281,   222,    72,   692,   222,   222,   822,   643,   873,
     -87,   760,   222,   222,   849,   852,  -108,   852,   565,   852,
     573,   648,   666,   694,   674,   889,   674,  -267,    77,    77,
      77,    77,    77,    77,    77,    77,   -99,   222,   705,   222,
      87,   719,   708,    77,   523,    77,   726,   709,    77,   641,
     280,   717,   531,   359,   425,   832,   834,   771,  -430,   424,
     812,   717,   840,   842,   482,   922,   883,   812,  -104,   365,
     655,   365,   656,   657,   658,   659,   482,    77,   442,   933,
      77,   359,   452,   724,    77,    77,   787,   258,   -95,   730,
     773,   359,   478,   788,   734,   822,   942,  -610,   938,    77,
     791,   794,   426,   461,   793,   793,   462,   909,   795,   797,
     362,   483,   674,   484,   489,   817,   799,   271,    87,   977,
     822,   800,   817,   483,   817,   484,   493,    77,    77,   802,
     426,   831,   222,   720,  -268,   850,   928,   859,   362,   932,
     479,   280,    77,    87,   333,   870,   222,   798,   362,   801,
      87,    87,   838,   868,    87,  1010,   879,    87,  -515,  -515,
    -106,   814,   280,   881,    87,   814,    77,    87,   814,   885,
     814,   905,   904,   812,   906,   917,    77,  1005,   365,   910,
     -97,   913,   924,   793,    42,    43,    44,    45,   217,   217,
     915,   918,   217,  -527,  -527,    77,  1036,   919,   970,   354,
     355,   356,   357,   358,   482,  -610,   921,  -515,   926,   839,
    -610,  -528,  -528,  -285,  -285,  -515,  -269,   930,   951,   989,
     251,   253,   954,    87,   958,   217,   217,   852,   817,   960,
     817,   963,   813,   914,   916,   817,  -103,   817,   306,   307,
    -611,   965,  -527,   969,   258,   974,   986,  -270,    87,    87,
    -527,   483,  1008,   484,   500,   934,   -94,   935,  1033,  1019,
    -528,  1043,  -285,   359,   588,   793,  1021,   943,  -528,  1026,
    -285,  1028,  1042,   629,   814,  1044,   814,   631,   817,   451,
    1046,   814,   634,   814,   359,   598,    87,  -613,    87,  -614,
    -296,  -296,   258,  1032,    87,    77,  1067,    77,   644,    87,
    1069,  -518,  -518,   645,   374,    77,  1062,   391,  -617,   845,
     882,    87,   589,   809,  1055,    77,   876,    77,    77,  1061,
     362,   215,   410,   440,   814,   728,   852,   501,   222,   294,
     419,   403,   897,   599,   894,   901,   976,   996,   997,  -296,
     972,   362,  1002,   892,   359,   975,  1004,  -296,  -611,  1007,
    -518,     0,    77,  -611,   359,  1034,   959,   961,  -518,    77,
       0,   964,     0,   966,   258,   967,     0,   706,   717,  -617,
    -617,   982,     0,   656,   657,   658,   659,   115,   217,   115,
       0,   217,   217,   217,     0,   306,  1020,  1022,   804,   805,
       0,   806,  1027,   599,  1029,  1030,     0,   333,     0,    47,
      48,   362,   217,  1035,   217,   217,   313,   314,   315,   316,
     317,   362,   346,   347,    77,     0,  -617,    77,  -617,    77,
       0,  -613,     0,     0,     0,    77,  -617,   115,    77,    77,
       0,   282,     0,     0,     0,    77,    77,     0,     0,     0,
    1063,  1064,   655,     0,   656,   657,   658,   659,   978,     0,
     981,   353,   354,   355,   356,   357,   358,   282,     0,     0,
      77,     0,    77,    77,     0,  1068,  1070,  1071,  1072,   378,
     388,   388,   388,     0,     0,     0,     0,     0,  1045,  1047,
    1048,  1049,   779,     0,     0,     0,     0,   775,   780,  1076,
       0,     0,     0,  1014,     0,  1016,     0,     0,   217,     0,
    1017,     0,     0,   533,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
    1074,   655,   217,   656,   657,   658,   659,   660,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,   661,
       0,     0,   333,     0,  1051,    77,  1053,     0,     0,     0,
       0,     0,     0,  1054,     0,     0,    77,   346,   347,    77,
       0,   662,     0,    77,    77,     0,     0,    77,   664,   665,
      77,  1066,   612,   614,   115,     0,     0,    77,     0,     0,
      77,   617,   217,   217,   869,     0,     0,   217,     0,   612,
     614,   217,     0,   666,  1075,     0,   333,   354,   355,   356,
     357,   358,     0,   880,   729,     0,   731,     0,     0,   115,
     637,   346,   347,     0,   886,   642,     0,     0,     0,     0,
     115,     0,   115,     0,     0,     0,   217,     0,   655,   217,
     656,   657,   658,   659,   660,     0,    77,     0,     0,     0,
     217,     0,   116,   282,   116,     0,   661,     0,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,    77,    77,     0,     0,     0,   695,     0,   662,     0,
       0,     0,     0,     0,   663,   664,   665,   115,     0,     0,
       0,   217,   115,     0,     0,   655,     0,   656,   657,   658,
     659,     0,   116,     0,   115,   282,   283,     0,     0,    77,
     666,    77,     0,   667,     0,     0,     0,    77,     0,     0,
       0,     0,    77,   949,     0,     0,     0,     0,     0,     0,
       0,   238,   283,   823,    77,   779,   824,     0,   826,   115,
       0,   952,     0,     0,   379,   389,   389,   389,     0,     0,
       0,    77,     0,     0,     0,     0,   217,     0,     0,   655,
     217,   656,   657,   658,   659,   660,     0,     0,     0,   655,
     217,   656,   657,   658,   659,     0,     0,   661,     0,     0,
       0,     0,     0,     0,     0,  1003,     0,   217,     0,     0,
     217,     0,   655,     0,   656,   657,   658,   659,   660,   662,
       0,     0,     0,   217,   217,   663,   664,   665,     0,   779,
     661,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,   119,     0,     0,     0,   115,     0,     0,     0,     0,
       0,   666,   662,     0,   667,   115,     0,     0,   663,   664,
     665,     0,     0,     0,     0,     0,   668,     0,   217,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,   116,
     920,     0,     0,     0,   666,     0,     0,   667,     0,   119,
       0,     0,     0,   284,     0,     0,   217,     0,     0,     0,
     617,   830,     0,   833,   835,   929,     0,     0,     0,     0,
     841,   843,   936,   937,   116,     0,   939,   217,     0,   284,
       0,     0,   282,     0,     0,   116,     0,   116,     0,     0,
       0,   380,   390,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,     0,
       0,     0,   877,     0,     0,     0,     0,   833,   835,     0,
     841,   843,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,   115,     0,   217,     0,
       0,     0,   116,     0,     0,   994,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,   116,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1012,  1013,     0,     0,     0,     0,     0,     0,   217,     0,
       0,     0,   923,     0,     0,    84,     0,    84,     0,     0,
     925,     0,     0,     0,   116,     0,     0,     0,   115,     0,
       0,     0,     0,   282,  -639,     0,   119,     0,  1037,     0,
    1038,   217,     0,  -639,  -639,  -639,  1039,     0,  -639,  -639,
    -639,     0,  -639,     0,     0,     0,     0,     0,     0,   925,
     217,  -639,  -639,  1050,     0,    84,     0,     0,     0,     0,
       0,   119,  -639,  -639,     0,  -639,  -639,  -639,  -639,  -639,
       0,     0,   119,   115,   119,     0,   115,     0,   115,     0,
       0,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,   375,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,  -639,  -639,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,   283,     0,   119,
     118,     0,   118,     0,   119,     0,  -639,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -639,
    -639,     0,     0,     0,   234,  -639,     0,  -639,     0,  -639,
    -639,     0,     0,     0,     0,     0,     0,   283,     0,     0,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   388,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,     0,   217,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,     0,     0,   116,
       0,   116,   115,   115,     0,     0,   115,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   115,    84,     0,   115,
       0,   116,     0,     0,     0,     0,     0,     0,    84,     0,
      84,     0,     0,     0,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,     0,     0,
     388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   284,     0,     0,     0,   283,     0,
       0,   990,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   115,    84,     0,     0,   532,     0,   118,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,   116,     0,
       0,   116,     0,   116,     0,     0,     0,     0,   283,     0,
       0,     0,     0,     0,     0,     0,     0,    84,   115,     0,
     115,     0,   118,     0,     0,     0,   115,     0,     0,     0,
       0,   115,     0,   118,     0,   118,     0,     0,     0,     0,
       0,     0,     0,   115,     0,     0,   119,   116,   119,     0,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,     0,
     118,   346,   347,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,    84,     0,     0,     0,   118,     0,     0,
     119,     0,     0,    84,   389,   284,     0,     0,     0,     0,
       0,     0,     0,     0,   348,   116,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,   118,  -244,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,   808,   116,   116,     0,
       0,   116,     0,     0,   116,   119,   761,     0,   119,     0,
     119,   116,     0,     0,   116,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   389,     0,   346,   347,     0,
       0,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   991,     0,   118,     0,
     116,   710,    84,     0,    84,     0,     0,     0,   118,     0,
     348,     0,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,    84,   116,   116,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
       0,     0,   346,   347,     0,     0,     0,     0,     0,     0,
       0,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   116,     0,   116,    84,     0,     0,     0,
       0,   116,     0,     0,     0,   348,   116,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   119,   116,     0,
       0,     0,     0,     0,   119,   119,     0,     0,   119,     0,
       0,   119,     0,     0,     0,     0,     0,     0,   119,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,    84,     0,    84,   118,     0,   118,
       0,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   390,     0,     0,     0,     0,     0,     0,   118,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   992,     0,   346,   347,   119,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   119,     0,     0,     0,     0,   348,     0,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,     0,   238,   346,   347,     0,     0,
     119,     0,   119,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,   119,     0,     0,   118,     0,    84,   118,
       0,   118,     0,     0,     0,   119,     0,     0,     0,   348,
       0,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      84,    84,     0,     0,    84,     0,     0,    84,   562,   563,
       0,     0,   564,     0,    84,   118,     0,    84,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     0,     0,   177,   178,     0,     0,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,  -640,  -640,   988,
       0,   346,   347,    84,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,     0,
       0,     0,     0,   118,   197,     0,     0,     0,    84,    84,
       0,     0,     0,     0,     0,     0,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,   118,     0,
       0,     0,     0,     0,     0,   118,   118,     0,     0,   118,
       0,     0,   118,     0,     0,     0,    84,     0,    84,   118,
       0,     0,   118,     0,    84,     0,     0,     0,     0,    84,
       0,     0,     0,     5,     6,     7,     8,     0,    10,     0,
       0,    84,    11,    12,     0,     0,     0,    13,     0,    14,
      15,    16,   245,   246,    19,    20,     0,     0,     0,     0,
       0,   247,   248,   249,    24,    25,    26,    27,     0,     0,
     206,     0,     0,     0,     0,     0,     0,   275,   118,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,     0,    46,    47,    48,     0,     0,
       0,     0,     0,   118,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,   209,    53,     0,    54,    55,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   118,     0,   118,     0,     0,     0,     0,     0,   118,
       0,     0,  -639,     4,   118,     5,     6,     7,     8,     9,
      10,   277,     0,     0,    11,    12,   118,     0,   278,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
       0,     0,    28,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,     0,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    52,    53,     0,    54,    55,
       0,    56,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,  -617,     0,     0,     0,     0,     0,     0,
       0,     0,  -617,  -617,  -617,     0,     0,  -617,  -617,  -617,
       0,  -617,     0,    66,    67,    68,     0,     0,     0,     0,
    -617,  -617,  -617,  -617,     0,  -639,     0,     0,  -639,     0,
       0,  -617,  -617,     0,  -617,  -617,  -617,  -617,  -617,     0,
       0,     0,   333,   334,   335,   336,   337,   338,   339,   340,
       0,   342,   343,     0,     0,     0,     0,   346,   347,     0,
       0,     0,     0,     0,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,  -617,  -617,  -617,     0,     0,  -617,
    -617,  -617,  -617,     0,   766,  -617,     0,     0,     0,     0,
       0,  -617,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,  -617,     0,     0,  -617,     0,
       0,  -105,  -617,  -617,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,     0,     0,     0,     0,  -617,  -617,
    -617,  -617,  -515,     0,  -617,  -617,  -617,     0,  -617,  -617,
       0,  -515,  -515,  -515,     0,     0,  -515,  -515,  -515,     0,
    -515,     0,     0,     0,     0,     0,     0,     0,  -515,     0,
    -515,  -515,  -515,     0,     0,     0,     0,     0,     0,     0,
    -515,  -515,     0,  -515,  -515,  -515,  -515,  -515,     0,     0,
       0,   333,  -640,  -640,  -640,  -640,   338,   339,     0,     0,
    -640,  -640,     0,     0,     0,     0,   346,   347,     0,     0,
       0,     0,     0,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,     0,     0,  -515,  -515,
    -515,  -515,     0,  -515,  -515,     0,     0,     0,     0,     0,
    -515,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,  -515,     0,     0,  -515,     0,     0,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,     0,     0,     0,     0,     0,  -515,  -515,
    -515,  -518,     0,  -515,  -515,  -515,     0,  -515,  -515,     0,
    -518,  -518,  -518,     0,     0,  -518,  -518,  -518,     0,  -518,
       0,     0,     0,     0,     0,     0,     0,  -518,     0,  -518,
    -518,  -518,     0,     0,     0,     0,     0,     0,     0,  -518,
    -518,     0,  -518,  -518,  -518,  -518,  -518,     0,     0,     0,
     333,   334,   335,   336,   337,   338,   339,     0,     0,   342,
     343,     0,     0,     0,     0,   346,   347,     0,     0,     0,
       0,     0,  -518,  -518,  -518,  -518,  -518,  -518,  -518,  -518,
    -518,  -518,  -518,  -518,  -518,     0,     0,  -518,  -518,  -518,
    -518,     0,  -518,  -518,     0,     0,     0,     0,     0,  -518,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,  -518,     0,     0,  -518,     0,     0,  -518,
    -518,  -518,  -518,  -518,  -518,  -518,  -518,  -518,  -518,  -518,
    -518,  -518,     0,     0,     0,     0,     0,  -518,  -518,  -518,
    -618,     0,  -518,  -518,  -518,     0,  -518,  -518,     0,  -618,
    -618,  -618,     0,     0,  -618,  -618,  -618,     0,  -618,     0,
       0,     0,     0,     0,     0,     0,     0,  -618,  -618,  -618,
    -618,     0,     0,     0,     0,     0,     0,     0,  -618,  -618,
       0,  -618,  -618,  -618,  -618,  -618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,     0,     0,  -618,  -618,  -618,  -618,
       0,     0,  -618,     0,     0,     0,     0,     0,  -618,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -618,     0,     0,  -618,     0,     0,     0,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,     0,     0,     0,     0,  -618,  -618,  -618,  -618,  -619,
       0,  -618,  -618,  -618,     0,  -618,  -618,     0,  -619,  -619,
    -619,     0,     0,  -619,  -619,  -619,     0,  -619,     0,     0,
       0,     0,     0,     0,     0,     0,  -619,  -619,  -619,  -619,
       0,     0,     0,     0,     0,     0,     0,  -619,  -619,     0,
    -619,  -619,  -619,  -619,  -619,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,     0,     0,  -619,  -619,  -619,  -619,     0,
       0,  -619,     0,     0,     0,     0,     0,  -619,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -619,     0,     0,  -619,     0,     0,     0,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
       0,     0,     0,     0,  -619,  -619,  -619,  -619,  -295,     0,
    -619,  -619,  -619,     0,  -619,  -619,     0,  -295,  -295,  -295,
       0,     0,  -295,  -295,  -295,     0,  -295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -295,  -295,  -295,     0,
       0,     0,     0,     0,     0,     0,  -295,  -295,     0,  -295,
    -295,  -295,  -295,  -295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,     0,     0,  -295,  -295,  -295,  -295,     0,   767,
    -295,     0,     0,     0,     0,     0,  -295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -295,     0,     0,  -295,     0,     0,  -107,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,     0,
       0,     0,     0,     0,  -295,  -295,  -295,  -438,     0,  -295,
    -295,  -295,     0,  -295,  -295,     0,  -438,  -438,  -438,     0,
       0,  -438,  -438,  -438,     0,  -438,     0,     0,     0,     0,
       0,     0,     0,     0,  -438,  -438,  -438,     0,     0,     0,
       0,     0,     0,     0,     0,  -438,  -438,     0,  -438,  -438,
    -438,  -438,  -438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -438,  -438,
    -438,  -438,  -438,  -438,  -438,  -438,  -438,  -438,  -438,  -438,
    -438,     0,     0,  -438,  -438,  -438,  -438,     0,     0,  -438,
       0,     0,     0,     0,     0,  -438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -438,
       0,     0,     0,     0,     0,     0,  -438,     0,  -438,  -438,
    -438,  -438,  -438,  -438,  -438,  -438,  -438,  -438,     0,     0,
       0,     0,  -438,  -438,  -438,  -438,  -286,   234,  -438,  -438,
    -438,     0,  -438,  -438,     0,  -286,  -286,  -286,     0,     0,
    -286,  -286,  -286,     0,  -286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -286,  -286,  -286,     0,     0,     0,
       0,     0,     0,     0,  -286,  -286,     0,  -286,  -286,  -286,
    -286,  -286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
       0,     0,  -286,  -286,  -286,  -286,     0,     0,  -286,     0,
       0,     0,     0,     0,  -286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -286,     0,
       0,  -286,     0,     0,     0,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,     0,     0,     0,
       0,     0,  -286,  -286,  -286,  -428,     0,  -286,  -286,  -286,
       0,  -286,  -286,     0,  -428,  -428,  -428,     0,     0,  -428,
    -428,  -428,     0,  -428,     0,     0,     0,     0,     0,     0,
       0,     0,  -428,  -428,  -428,     0,     0,     0,     0,     0,
       0,     0,     0,  -428,  -428,     0,  -428,  -428,  -428,  -428,
    -428,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,     0,
       0,  -428,  -428,  -428,  -428,     0,     0,  -428,     0,     0,
       0,     0,     0,  -428,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -428,     0,     0,
       0,     0,     0,     0,  -428,     0,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,     0,     0,     0,     0,
    -428,  -428,  -428,  -428,  -302,  -428,  -428,  -428,  -428,     0,
    -428,  -428,     0,  -302,  -302,  -302,     0,     0,  -302,  -302,
    -302,     0,  -302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -302,  -302,     0,     0,     0,     0,     0,     0,
       0,     0,  -302,  -302,     0,  -302,  -302,  -302,  -302,  -302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,     0,     0,
    -302,  -302,  -302,  -302,     0,     0,  -302,     0,     0,     0,
       0,     0,  -302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -302,     0,     0,     0,
       0,     0,     0,  -302,     0,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,  -302,  -302,     0,     0,     0,     0,     0,
    -302,  -302,  -302,  -617,   231,  -302,  -302,  -302,     0,  -302,
    -302,     0,  -617,  -617,  -617,     0,     0,     0,  -617,  -617,
       0,  -617,     0,     0,     0,     0,     0,     0,     0,     0,
    -617,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -617,  -617,     0,  -617,  -617,  -617,  -617,  -617,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,  -617,  -617,  -617,     0,     0,  -617,
    -617,  -617,  -617,     0,   712,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -617,     0,     0,     0,     0,
       0,  -105,  -617,     0,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,     0,     0,     0,     0,  -617,  -617,
    -617,   -96,  -295,     0,  -617,     0,  -617,     0,  -617,  -617,
       0,  -295,  -295,  -295,     0,     0,     0,  -295,  -295,     0,
    -295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -295,  -295,     0,  -295,  -295,  -295,  -295,  -295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,     0,     0,  -295,  -295,
    -295,  -295,     0,   713,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -295,     0,     0,     0,     0,     0,
    -107,  -295,     0,  -295,  -295,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,     0,     0,     0,     0,     0,  -295,  -295,
     -98,     0,     0,  -295,     0,  -295,     0,  -295,  -295,   255,
       0,     5,     6,     7,     8,     9,    10,  -639,  -639,  -639,
      11,    12,     0,     0,  -639,    13,     0,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,     0,     0,     0,    29,    30,   256,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,     0,    46,    47,    48,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    52,    53,     0,    54,    55,     0,    56,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -639,     0,   255,  -639,     5,     6,     7,     8,     9,
      10,     0,     0,  -639,    11,    12,     0,  -639,  -639,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
       0,     0,    28,     0,     0,     0,     0,     0,    29,    30,
     256,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,     0,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    52,    53,     0,    54,    55,
       0,    56,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -639,     0,   255,  -639,     5,
       6,     7,     8,     9,    10,     0,     0,  -639,    11,    12,
       0,     0,  -639,    13,  -639,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,     0,     0,
       0,     0,    29,    30,   256,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
       0,    46,    47,    48,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    52,
      53,     0,    54,    55,     0,    56,     0,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -639,
       0,   255,  -639,     5,     6,     7,     8,     9,    10,     0,
       0,  -639,    11,    12,     0,     0,  -639,    13,     0,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,     0,     0,     0,     0,    29,    30,   256,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,     0,    46,    47,    48,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    52,    53,     0,    54,    55,     0,    56,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       5,     6,     7,     8,     9,    10,     0,  -639,  -639,    11,
      12,    66,    67,    68,    13,     0,    14,    15,    16,    17,
      18,    19,    20,  -639,     0,     0,  -639,     0,    21,    22,
      23,    24,    25,    26,    27,     0,     0,    28,     0,     0,
       0,     0,     0,    29,    30,   256,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,     0,    46,    47,    48,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      52,    53,     0,    54,    55,     0,    56,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    66,    67,
      68,    13,     0,    14,    15,    16,    17,    18,    19,    20,
    -639,     0,     0,  -639,     0,    21,    22,    23,    24,    25,
      26,    27,     0,     0,    28,     0,     0,     0,     0,     0,
      29,    30,   256,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,     0,    46,
      47,    48,     0,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,   257,    53,     0,
      54,    55,     0,    56,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,     0,     0,
       0,     0,     0,     0,     0,  -639,     0,  -639,     0,   255,
    -639,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,     0,     0,     0,    13,     0,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,     0,     0,     0,    29,    30,   256,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,     0,    46,    47,    48,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    52,    53,     0,    54,    55,     0,    56,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     0,     0,     0,     0,     0,     0,     0,  -639,
       0,  -639,     0,   255,  -639,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
       0,     0,    28,     0,     0,     0,     0,     0,    29,    30,
     256,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,     0,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    52,    53,     0,    54,    55,
       0,    56,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,     0,     0,  -639,     0,
       0,     0,     0,     0,     0,  -639,     0,     4,  -639,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
       0,     0,     0,    13,     0,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,     0,     0,    28,     0,     0,     0,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
       0,    46,    47,    48,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    52,
      53,     0,    54,    55,     0,    56,     0,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
       0,     0,  -639,     0,     0,     0,     0,     0,     0,  -639,
       0,   255,  -639,     5,     6,     7,     8,     9,    10,     0,
       0,  -639,    11,    12,     0,     0,     0,    13,     0,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,     0,     0,     0,     0,    29,    30,   256,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,     0,    46,    47,    48,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    52,    53,     0,    54,    55,     0,    56,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    66,    67,    68,    13,     0,    14,    15,    16,    17,
      18,    19,    20,  -639,     0,     0,  -639,     0,    21,    22,
      23,    24,    25,    26,    27,     0,     0,    28,     0,     0,
       0,     0,     0,    29,    30,   256,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,     0,    46,    47,    48,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      52,    53,     0,    54,    55,     0,    56,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,  -639,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,    10,     0,     0,     0,    11,    12,    66,    67,
      68,    13,     0,    14,    15,    16,    17,    18,    19,    20,
    -639,     0,     0,  -639,     0,    21,    22,    23,    24,    25,
      26,    27,     0,     0,   206,     0,     0,     0,     0,     0,
       0,    30,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   207,    42,    43,    44,    45,     0,    46,
      47,    48,     0,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,   209,    53,     0,
      54,    55,     0,   210,   211,   212,    57,    58,   213,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     0,    10,
       0,     0,     0,    11,    12,    66,   214,    68,    13,     0,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
     238,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,     0,     0,     0,     0,     0,    30,     0,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,     0,    46,    47,    48,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,   209,    53,     0,    54,    55,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,    10,     0,     0,     0,
      11,    12,    66,    67,    68,    13,     0,    14,    15,    16,
      17,    18,    19,    20,   308,     0,     0,   309,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,     0,     0,     0,     0,    30,     0,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,     0,    46,    47,    48,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,   209,    53,     0,    54,    55,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    66,
      67,    68,    13,     0,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,   238,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,     0,
      46,    47,    48,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    52,    53,
       0,    54,    55,     0,    56,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    66,    67,    68,    13,
       0,    14,    15,    16,    17,    18,    19,    20,   506,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
       0,     0,    28,     0,     0,     0,     0,     0,    29,    30,
     256,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,     0,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    52,    53,     0,    54,    55,
       0,    56,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,     0,     0,   148,   149,   150,   392,   393,   394,
     395,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,   160,   161,   396,   397,   398,   399,   166,    38,    39,
     400,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,     0,   177,   178,     0,     0,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,     0,     0,     0,
       0,     0,   197,   401,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   287,   288,   167,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,   177,   178,     0,     0,   179,   180,   181,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,     0,     0,     0,     0,     0,
     197,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,     0,     0,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   240,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,   177,   178,
       0,     0,   179,   180,   181,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,     0,     0,     0,     0,     0,   197,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     0,     0,   177,   178,     0,     0,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,     0,
       0,     0,     0,     0,   197,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,     0,   177,   178,     0,     0,   179,   180,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,     0,     5,     6,     7,
       8,   197,    10,     0,     0,     0,    11,    12,     0,     0,
       0,    13,     0,    14,    15,    16,   245,   246,    19,    20,
       0,     0,     0,     0,     0,   247,   248,   249,    24,    25,
      26,    27,     0,     0,   206,     0,     0,     0,     0,     0,
       0,   275,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,     0,    46,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,     0,   209,    53,     0,
      54,    55,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,     0,     0,   277,    11,    12,     0,     0,
       0,    13,   527,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,    27,     0,     0,    28,     0,     0,     0,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,     0,    46,
      47,    48,     0,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    52,    53,     0,
      54,    55,     0,    56,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     0,    10,
       0,     0,     0,    11,    12,    66,    67,    68,    13,     0,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,   206,     0,     0,     0,     0,     0,     0,    30,     0,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     207,    42,    43,    44,    45,     0,    46,    47,    48,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,   209,    53,     0,    54,    55,     0,
     210,   211,   212,    57,    58,   213,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    66,   214,    68,    13,     0,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,     0,     0,     0,    29,    30,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,     0,    46,    47,    48,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    52,    53,     0,    54,    55,     0,    56,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     0,    10,     0,     0,     0,    11,    12,    66,
      67,    68,    13,     0,    14,    15,    16,   245,   246,    19,
      20,     0,     0,     0,     0,     0,   247,   248,   249,    24,
      25,    26,    27,     0,     0,   206,     0,     0,     0,     0,
       0,     0,    30,     0,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   207,    42,    43,    44,    45,     0,
      46,    47,    48,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,   209,    53,
       0,    54,    55,     0,   619,   211,   212,    57,    58,   213,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     0,
      10,     0,     0,     0,    11,    12,    66,   214,    68,    13,
       0,    14,    15,    16,   245,   246,    19,    20,     0,     0,
       0,     0,     0,   247,   248,   249,    24,    25,    26,    27,
       0,     0,   206,     0,     0,     0,     0,     0,     0,    30,
       0,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,   207,    42,    43,    44,    45,     0,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,   209,    53,     0,    54,    55,
       0,   210,   211,     0,    57,    58,   213,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     0,    10,     0,     0,
       0,    11,    12,    66,   214,    68,    13,     0,    14,    15,
      16,   245,   246,    19,    20,     0,     0,     0,     0,     0,
     247,   248,   249,    24,    25,    26,    27,     0,     0,   206,
       0,     0,     0,     0,     0,     0,    30,     0,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   207,    42,
      43,    44,    45,     0,    46,    47,    48,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,   209,    53,     0,    54,    55,     0,     0,   211,
     212,    57,    58,   213,    60,    61,    62,    63,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,    10,     0,     0,     0,    11,    12,
      66,   214,    68,    13,     0,    14,    15,    16,   245,   246,
      19,    20,     0,     0,     0,     0,     0,   247,   248,   249,
      24,    25,    26,    27,     0,     0,   206,     0,     0,     0,
       0,     0,     0,    30,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   207,    42,    43,    44,    45,
       0,    46,    47,    48,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,   209,
      53,     0,    54,    55,     0,   619,   211,     0,    57,    58,
     213,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       0,    10,     0,     0,     0,    11,    12,    66,   214,    68,
      13,     0,    14,    15,    16,   245,   246,    19,    20,     0,
       0,     0,     0,     0,   247,   248,   249,    24,    25,    26,
      27,     0,     0,   206,     0,     0,     0,     0,     0,     0,
      30,     0,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   207,    42,    43,    44,    45,     0,    46,    47,
      48,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,     0,     0,   209,    53,     0,    54,
      55,     0,     0,   211,     0,    57,    58,   213,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     0,    10,     0,
       0,     0,    11,    12,    66,   214,    68,    13,     0,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
     206,     0,     0,     0,     0,     0,     0,    30,     0,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,     0,    46,    47,    48,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,     0,     0,   209,    53,     0,    54,    55,     0,   520,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     0,    10,     0,     0,     0,    11,
      12,    66,   214,    68,    13,     0,    14,    15,    16,   245,
     246,    19,    20,     0,     0,     0,     0,     0,   247,   248,
     249,    24,    25,    26,    27,     0,     0,   206,     0,     0,
       0,     0,     0,     0,    30,     0,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,     0,    46,    47,    48,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
     209,    53,     0,    54,    55,     0,   210,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,    10,     0,     0,     0,    11,    12,    66,   214,
      68,    13,     0,    14,    15,    16,   245,   246,    19,    20,
       0,     0,     0,     0,     0,   247,   248,   249,    24,    25,
      26,    27,     0,     0,   206,     0,     0,     0,     0,     0,
       0,    30,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,     0,    46,
      47,    48,     0,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,   209,    53,     0,
      54,    55,     0,   827,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     0,    10,
       0,     0,     0,    11,    12,    66,   214,    68,    13,     0,
      14,    15,    16,   245,   246,    19,    20,     0,     0,     0,
       0,     0,   247,   248,   249,    24,    25,    26,    27,     0,
       0,   206,     0,     0,     0,     0,     0,     0,    30,     0,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,     0,    46,    47,    48,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,   209,    53,     0,    54,    55,     0,
     520,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,    10,     0,     0,     0,
      11,    12,    66,   214,    68,    13,     0,    14,    15,    16,
     245,   246,    19,    20,     0,     0,     0,     0,     0,   247,
     248,   249,    24,    25,    26,    27,     0,     0,   206,     0,
       0,     0,     0,     0,     0,    30,     0,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,     0,    46,    47,    48,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,   209,    53,     0,    54,    55,     0,   619,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     0,    10,     0,     0,     0,    11,    12,    66,
     214,    68,    13,     0,    14,    15,    16,   245,   246,    19,
      20,     0,     0,     0,     0,     0,   247,   248,   249,    24,
      25,    26,    27,     0,     0,   206,     0,     0,     0,     0,
       0,     0,    30,     0,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,     0,
      46,    47,    48,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,   209,    53,
       0,    54,    55,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     0,
      10,     0,     0,     0,    11,    12,    66,   214,    68,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
       0,     0,   206,     0,     0,     0,     0,     0,     0,    30,
       0,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,     0,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,   209,    53,     0,    54,    55,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     0,    10,     0,     0,
       0,    11,    12,    66,   214,    68,    13,     0,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,     0,     0,    28,
       0,     0,     0,     0,     0,     0,    30,     0,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,     0,    46,    47,    48,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,   209,    53,     0,    54,    55,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,    10,     0,     0,     0,    11,    12,
      66,    67,    68,    13,     0,    14,    15,    16,   245,   246,
      19,    20,     0,     0,     0,     0,     0,   247,   248,   249,
      24,    25,    26,    27,     0,     0,   206,     0,     0,     0,
       0,     0,     0,   275,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
       0,    46,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,     0,   329,
      53,     0,    54,    55,     0,   330,     0,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     0,    10,     0,     0,
       0,    11,    12,     0,     0,     0,    13,   277,    14,    15,
      16,   245,   246,    19,    20,     0,     0,     0,     0,     0,
     247,   248,   249,    24,    25,    26,    27,     0,     0,   206,
       0,     0,     0,     0,     0,     0,   275,     0,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,     0,    46,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   373,
       0,     0,    52,    53,     0,    54,    55,     0,    56,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     0,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
     277,    14,    15,    16,   245,   246,    19,    20,     0,     0,
       0,     0,     0,   247,   248,   249,    24,    25,    26,    27,
       0,     0,   206,     0,     0,     0,     0,     0,     0,   275,
       0,     0,    33,    34,    35,   381,    37,    38,    39,   382,
      41,     0,    42,    43,    44,    45,     0,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   383,     0,
       0,     0,   384,     0,     0,   209,    53,     0,    54,    55,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     0,    10,     0,     0,     0,    11,    12,     0,
       0,     0,    13,   277,    14,    15,    16,   245,   246,    19,
      20,     0,     0,     0,     0,     0,   247,   248,   249,    24,
      25,    26,    27,     0,     0,   206,     0,     0,     0,     0,
       0,     0,   275,     0,     0,    33,    34,    35,   381,    37,
      38,    39,   382,    41,     0,    42,    43,    44,    45,     0,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,     0,   209,    53,
       0,    54,    55,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,    10,     0,     0,     0,
      11,    12,     0,     0,     0,    13,   277,    14,    15,    16,
     245,   246,    19,    20,     0,     0,     0,     0,     0,   247,
     248,   249,    24,    25,    26,    27,     0,     0,   206,     0,
       0,     0,     0,     0,     0,   275,     0,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,     0,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
       0,   329,    53,     0,    54,    55,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     0,    10,
       0,     0,     0,    11,    12,     0,     0,     0,    13,   277,
      14,    15,    16,   245,   246,    19,    20,     0,     0,     0,
       0,     0,   247,   248,   249,    24,    25,    26,    27,     0,
       0,   206,     0,     0,     0,     0,     0,     0,   275,     0,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,     0,    46,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   908,     0,     0,   209,    53,     0,    54,    55,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,    10,     0,     0,     0,    11,    12,     0,     0,
       0,    13,   277,    14,    15,    16,   245,   246,    19,    20,
       0,     0,     0,     0,     0,   247,   248,   249,    24,    25,
      26,    27,     0,     0,   206,     0,     0,     0,     0,     0,
       0,   275,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,     0,    46,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   987,     0,     0,   209,    53,     0,
      54,    55,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
     570,   571,     0,     0,   572,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   168,   169,   170,   171,
     172,   173,   174,   175,   176,     0,     0,   177,   178,     0,
       0,   179,   180,   181,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   608,   571,     0,     0,   609,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,   177,   178,
       0,     0,   179,   180,   181,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   623,   563,     0,     0,   624,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,   172,   173,   174,   175,   176,     0,     0,   177,
     178,     0,     0,   179,   180,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   626,   571,     0,     0,   627,   197,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     0,     0,
     177,   178,     0,     0,   179,   180,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   650,   563,     0,     0,   651,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,   177,   178,     0,     0,   179,   180,   181,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   653,   571,     0,     0,   654,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,     0,   177,   178,     0,     0,   179,   180,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   739,   563,     0,     0,
     740,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,     0,   177,   178,     0,     0,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   742,   571,     0,
       0,   743,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,     0,   177,   178,     0,     0,   179,   180,
     181,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   748,   563,
       0,     0,   749,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     0,     0,   177,   178,     0,     0,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,  1023,
     563,     0,     0,  1024,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,     0,   177,   178,     0,     0,
     179,   180,   181,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
    1056,   563,     0,     0,  1057,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,   170,   171,
     172,   173,   174,   175,   176,     0,     0,   177,   178,     0,
       0,   179,   180,   181,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,  1059,   571,     0,     0,  1060,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,   177,   178,
       0,     0,   179,   180,   181,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,     0,     0,     0,     0,     0,   197
};

static const yytype_int16 yycheck[] =
{
       2,   227,    56,    55,    87,     2,   100,     4,   332,    77,
      82,    70,   332,    17,    18,   361,    99,    21,     9,   584,
      17,    18,    58,     9,    21,    23,    90,   601,    82,    93,
     367,     4,   681,    29,    93,   430,   481,    66,    29,   477,
      94,    95,    96,    29,   583,    17,    18,   788,    28,    21,
      30,   384,    54,    55,   360,    52,   269,   363,   883,    56,
     273,    97,    98,    52,    56,    93,   756,   625,   422,   885,
      67,   727,     2,   468,     4,   731,   430,    70,   450,    77,
     426,   917,    54,   360,   668,    82,   363,   662,    27,   527,
      26,   257,    89,    90,   652,   797,    93,    94,    95,    96,
      27,   516,   408,    26,   519,   913,    30,    64,    26,    26,
      89,    64,    14,    53,    26,    89,   785,    57,   697,   425,
      67,   427,    91,    26,    89,    90,   951,    26,    93,    71,
      16,   408,    18,   479,     0,    14,   293,    91,   295,   222,
     297,   810,    26,    89,   301,   146,   452,   453,   425,   118,
     427,    89,    17,    18,    89,   207,    21,   114,   210,   211,
     212,   114,    57,   329,   118,   906,   145,   816,   817,   252,
      14,   145,   478,   747,   480,   135,   453,    17,    18,   697,
      14,    21,   250,   741,   138,  1010,   128,   129,   130,    54,
      55,   115,  1008,   751,   144,  1031,   135,    14,   281,   145,
     259,   140,   138,   480,   779,   780,   278,   145,   135,   788,
     145,  1019,   209,   439,    14,   138,   144,  1042,   797,   221,
     138,   138,   963,   668,   278,   227,   138,   231,   140,   233,
     234,   259,   234,    14,   231,   138,   233,   234,   633,   138,
     237,   143,   239,   589,   146,    29,   895,   244,   277,   313,
     314,   315,   316,   599,   138,   118,   958,   947,   255,   231,
     257,   233,   419,    79,   143,   598,   259,   146,   257,   266,
     708,   643,   237,   791,   239,   327,   330,   795,   632,   633,
     332,   278,   588,   939,   590,  1026,   870,   702,   872,   144,
     864,    28,   598,   376,   600,   275,   140,   871,    26,   143,
     874,   266,   146,   144,   368,   369,   140,   123,   883,   143,
     885,   370,   146,   590,    91,   312,   313,   314,   315,   316,
     317,   318,   319,   600,   863,   255,   143,   906,   977,   146,
     327,   141,   329,   330,   913,   332,   146,   494,   330,   312,
     329,   118,   370,   143,   501,   481,   146,    14,   313,   314,
     315,   316,   138,   318,   319,   327,    14,   361,    14,   361,
     332,   138,   143,    14,   361,   146,   231,   364,   233,   421,
     422,   368,   369,   118,   939,    89,   951,   952,   430,   958,
     327,    91,   312,    89,    91,   332,   383,   317,   906,   709,
      91,   231,   910,   233,    89,   913,   622,   915,    89,   138,
     737,    89,   726,   368,   369,   477,   143,   146,   118,   146,
     138,   118,   140,   465,   411,   412,   468,   118,   383,    26,
      38,    39,   426,   477,   426,   870,    26,   872,     2,   426,
       4,   145,  1006,  1008,   647,  1010,   438,   439,    91,   145,
    1019,   138,   101,    17,    18,    88,    89,    21,   450,   146,
     145,   447,   118,   450,   145,   527,   447,   145,    26,    91,
     104,   447,    91,   460,   411,   412,   125,  1042,   520,    88,
      89,   138,   138,   527,   715,   479,   143,   479,    52,   146,
     477,   722,   479,   138,   879,   143,   118,   143,   146,   118,
     146,    26,   143,    67,   137,   146,   138,   140,   566,   140,
    1058,  1019,   145,  1021,   146,   146,   574,   140,  1026,    64,
    1028,   118,    57,   515,   516,    89,    90,   519,   118,    93,
     450,   118,    91,   582,   583,   879,   145,    91,   146,    92,
     527,   138,   668,   585,   141,    38,    39,   138,   138,   146,
     140,   141,   610,    91,    64,   771,   146,   138,    68,   118,
     118,  1069,    64,   140,   118,   135,   111,   422,   113,   114,
      64,   697,    15,    16,   616,    88,    89,   619,    64,   567,
     138,   551,    71,   141,   138,   577,   648,   575,   146,   140,
     632,   633,   579,   118,   581,   589,   140,   589,   141,   569,
     927,   111,   589,   113,   648,   599,   933,   599,   142,   111,
     465,   113,   599,   138,   601,   602,   141,   111,   610,   113,
     118,   146,   610,   585,   137,   111,   697,   113,   114,   615,
     622,   136,   145,    57,   615,   677,   114,    88,    89,   615,
     143,    55,   144,   146,   114,   209,   708,   602,    64,   636,
     144,   643,    66,    67,   138,   625,   643,   114,   716,   114,
      71,   648,   788,   705,   708,   723,    98,   231,    18,   233,
     234,   797,   697,   237,   758,   239,    59,   138,   143,   975,
     244,   636,   652,    57,   726,    26,   137,   679,    71,   681,
     744,   255,   746,   257,   145,   111,   745,   113,   114,  1035,
     116,    53,   266,    55,    56,    57,    58,   586,   141,    91,
     702,   698,   122,   138,   701,   138,   703,   100,   101,   136,
     791,   708,   709,   643,   144,   712,   713,   697,   135,   755,
     138,   723,   719,   720,   726,   727,   118,   729,  1034,   731,
    1036,   138,   125,   144,   870,   787,   872,   138,   312,   313,
     314,   315,   316,   317,   318,   319,   138,   744,   138,   746,
     747,    91,   138,   327,   726,   329,     9,   118,   332,  1036,
     814,   741,   709,    88,    89,   712,   713,   632,   140,   771,
     906,   751,   719,   720,    64,   827,   138,   913,   118,   744,
      53,   746,    55,    56,    57,    58,    64,   361,   237,   853,
     364,    88,    89,    11,   368,   369,   118,    52,   138,    14,
     136,    88,    89,   138,   863,   785,   865,    27,   860,   383,
     138,    53,   137,   262,   816,   817,   265,   814,   138,   138,
     145,   111,   958,   113,   114,   906,    53,   879,   825,   910,
     810,   138,   913,   111,   915,   113,   114,   411,   412,    53,
     137,   120,   839,    91,   138,    16,   848,   736,   145,   851,
     137,   905,   426,   850,    71,   140,   853,   683,   145,   685,
     857,   858,   142,   752,   861,   138,   138,   864,    88,    89,
     118,   906,   926,   136,   871,   910,   450,   874,   913,   138,
     915,   118,   123,  1019,   138,   143,   460,   946,   853,   138,
     138,   138,   839,   895,    60,    61,    62,    63,    17,    18,
     138,    11,    21,    88,    89,   479,   989,   136,   905,   126,
     127,   128,   129,   130,    64,   135,    11,   137,    92,    91,
     140,    88,    89,    88,    89,   145,   138,    10,   138,   926,
      49,    50,   141,   930,   138,    54,    55,   939,  1019,   138,
    1021,   138,   697,   819,   820,  1026,   118,  1028,    67,    68,
      27,   138,   137,   123,   209,    57,   136,   138,   955,   956,
     145,   111,   138,   113,   114,   854,   138,   856,    57,   138,
     137,    11,   137,    88,    89,   977,   138,   866,   145,   138,
     145,   138,   138,   432,  1019,   136,  1021,   436,  1069,   244,
     138,  1026,   441,  1028,    88,    89,   993,   140,   995,   140,
      88,    89,   257,   983,  1001,   579,   112,   581,   457,  1006,
     138,    88,    89,   460,    94,   589,  1038,    96,    27,   723,
     779,  1018,   137,   697,  1031,   599,   759,   601,   602,  1037,
     145,  1035,   103,  1035,  1069,  1037,  1038,   301,  1035,    60,
     213,    97,   797,   137,   791,   800,   910,   936,   937,   137,
     906,   145,   941,   788,    88,    89,   945,   145,   135,   948,
     137,    -1,   636,   140,    88,    89,   892,   893,   145,   643,
      -1,   897,    -1,   899,   329,   901,    -1,   526,  1058,    88,
      89,    53,    -1,    55,    56,    57,    58,     2,   207,     4,
      -1,   210,   211,   212,    -1,   214,   972,   973,    55,    56,
      -1,    58,   978,   137,   980,   981,    -1,    71,    -1,    66,
      67,   145,   231,   137,   233,   234,    41,    42,    43,    44,
      45,   145,    86,    87,   698,    -1,   135,   701,   137,   703,
      -1,   140,    -1,    -1,    -1,   709,   145,    52,   712,   713,
      -1,    56,    -1,    -1,    -1,   719,   720,    -1,    -1,    -1,
    1039,  1040,    53,    -1,    55,    56,    57,    58,   913,    -1,
     915,   125,   126,   127,   128,   129,   130,    82,    -1,    -1,
     744,    -1,   746,   747,    -1,  1051,  1052,  1053,  1054,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,  1014,  1015,
    1016,  1017,    93,    -1,    -1,    -1,    -1,   646,    99,  1075,
      -1,    -1,    -1,   958,    -1,   960,    -1,    -1,   327,    -1,
     965,    -1,    -1,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
    1066,    53,   361,    55,    56,    57,    58,    59,    -1,    -1,
      -1,   825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    71,    -1,  1019,   839,  1021,    -1,    -1,    -1,
      -1,    -1,    -1,  1028,    -1,    -1,   850,    86,    87,   853,
      -1,    93,    -1,   857,   858,    -1,    -1,   861,   100,   101,
     864,  1046,   411,   412,   209,    -1,    -1,   871,    -1,    -1,
     874,   420,   421,   422,   753,    -1,    -1,   426,    -1,   428,
     429,   430,    -1,   125,  1069,    -1,    71,   126,   127,   128,
     129,   130,    -1,   772,   579,    -1,   581,    -1,    -1,   244,
     449,    86,    87,    -1,   783,   454,    -1,    -1,    -1,    -1,
     255,    -1,   257,    -1,    -1,    -1,   465,    -1,    53,   468,
      55,    56,    57,    58,    59,    -1,   930,    -1,    -1,    -1,
     479,    -1,     2,   278,     4,    -1,    71,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,   955,   956,    -1,    -1,    -1,   505,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   312,    -1,    -1,
      -1,   520,   317,    -1,    -1,    53,    -1,    55,    56,    57,
      58,    -1,    52,    -1,   329,   330,    56,    -1,    -1,   993,
     125,   995,    -1,   128,    -1,    -1,    -1,  1001,    -1,    -1,
      -1,    -1,  1006,   882,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    82,   698,  1018,    93,   701,    -1,   703,   364,
      -1,    99,    -1,    -1,    94,    95,    96,    97,    -1,    -1,
      -1,  1035,    -1,    -1,    -1,    -1,   585,    -1,    -1,    53,
     589,    55,    56,    57,    58,    59,    -1,    -1,    -1,    53,
     599,    55,    56,    57,    58,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   944,    -1,   616,    -1,    -1,
     619,    -1,    53,    -1,    55,    56,    57,    58,    59,    93,
      -1,    -1,    -1,   632,   633,    99,   100,   101,    -1,    93,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     2,
      -1,     4,    -1,    -1,    -1,   450,    -1,    -1,    -1,    -1,
      -1,   125,    93,    -1,   128,   460,    -1,    -1,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,   140,    -1,   677,    -1,
      -1,    -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     825,    -1,    -1,    -1,   125,    -1,    -1,   128,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,   705,    -1,    -1,    -1,
     709,   710,    -1,   712,   713,   850,    -1,    -1,    -1,    -1,
     719,   720,   857,   858,   244,    -1,   861,   726,    -1,    82,
      -1,    -1,   527,    -1,    -1,   255,    -1,   257,    -1,    -1,
      -1,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,
      -1,    -1,   761,    -1,    -1,    -1,    -1,   766,   767,    -1,
     769,   770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,    -1,   581,    -1,   787,    -1,
      -1,    -1,   312,    -1,    -1,   930,    -1,   317,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,   329,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     955,   956,    -1,    -1,    -1,    -1,    -1,    -1,   827,    -1,
      -1,    -1,   831,    -1,    -1,     2,    -1,     4,    -1,    -1,
     839,    -1,    -1,    -1,   364,    -1,    -1,    -1,   643,    -1,
      -1,    -1,    -1,   648,     0,    -1,   209,    -1,   993,    -1,
     995,   860,    -1,     9,    10,    11,  1001,    -1,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,   878,
     879,    27,    28,  1018,    -1,    52,    -1,    -1,    -1,    -1,
      -1,   244,    38,    39,    -1,    41,    42,    43,    44,    45,
      -1,    -1,   255,   698,   257,    -1,   701,    -1,   703,    -1,
      -1,    -1,    -1,   708,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,    -1,    94,    -1,    -1,
     450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     460,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   747,    -1,    -1,    -1,    -1,   477,    -1,   312,
       2,    -1,     4,    -1,   317,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   329,   330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,    -1,    -1,   140,   141,    -1,   143,    -1,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,
      52,   364,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     825,    -1,    -1,    -1,    -1,    -1,  1035,    -1,    -1,    -1,
      -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   850,    -1,    -1,    -1,   579,
      -1,   581,   857,   858,    -1,    -1,   861,    -1,    -1,   864,
      -1,    -1,    -1,    -1,    -1,    -1,   871,   244,    -1,   874,
      -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
     905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   643,   477,    -1,    -1,    -1,   648,    -1,
      -1,   926,    -1,    -1,    -1,   930,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     955,   956,   329,    -1,    -1,   332,    -1,   209,    -1,    -1,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,   698,    -1,
      -1,   701,    -1,   703,    -1,    -1,    -1,    -1,   708,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,   993,    -1,
     995,    -1,   244,    -1,    -1,    -1,  1001,    -1,    -1,    -1,
      -1,  1006,    -1,   255,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1018,    -1,    -1,   579,   747,   581,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
     312,    86,    87,    -1,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   450,    -1,    -1,    -1,   329,    -1,    -1,
     643,    -1,    -1,   460,   814,   648,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   825,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   364,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     850,    -1,    -1,    -1,    -1,    -1,   689,   857,   858,    -1,
      -1,   861,    -1,    -1,   864,   698,    45,    -1,   701,    -1,
     703,   871,    -1,    -1,   874,   708,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   905,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,   747,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   926,    -1,   450,    -1,
     930,    45,   579,    -1,   581,    -1,    -1,    -1,   460,    -1,
     119,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,   601,   955,   956,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   814,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   825,   993,    -1,   995,   643,    -1,    -1,    -1,
      -1,  1001,    -1,    -1,    -1,   119,  1006,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   850,  1018,    -1,
      -1,    -1,    -1,    -1,   857,   858,    -1,    -1,   861,    -1,
      -1,   864,    -1,    -1,    -1,    -1,    -1,    -1,   871,    -1,
      -1,   874,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   698,    -1,    -1,   701,    -1,   703,   579,    -1,   581,
      -1,    -1,   709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,   601,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   926,    -1,    86,    87,   930,    -1,    -1,
     747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   643,   955,   956,    -1,    -1,    -1,    -1,   119,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,   146,    86,    87,    -1,    -1,
     993,    -1,   995,    -1,    -1,    -1,    -1,    -1,  1001,    -1,
      -1,    -1,    -1,  1006,    -1,    -1,   698,    -1,   825,   701,
      -1,   703,    -1,    -1,    -1,  1018,    -1,    -1,    -1,   119,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,   850,    -1,    -1,    -1,    -1,    -1,    -1,
     857,   858,    -1,    -1,   861,    -1,    -1,   864,    53,    54,
      -1,    -1,    57,    -1,   871,   747,    -1,   874,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,   926,
      -1,    86,    87,   930,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,    -1,
      -1,    -1,    -1,   825,   139,    -1,    -1,    -1,   955,   956,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,   850,    -1,
      -1,    -1,    -1,    -1,    -1,   857,   858,    -1,    -1,   861,
      -1,    -1,   864,    -1,    -1,    -1,   993,    -1,   995,   871,
      -1,    -1,   874,    -1,  1001,    -1,    -1,    -1,    -1,  1006,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,  1018,    12,    13,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,   930,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,   955,   956,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   993,    -1,   995,    -1,    -1,    -1,    -1,    -1,  1001,
      -1,    -1,     0,     1,  1006,     3,     4,     5,     6,     7,
       8,   131,    -1,    -1,    12,    13,  1018,    -1,   138,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    99,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      -1,    18,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,   143,    -1,    -1,   146,    -1,
      -1,    38,    39,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    89,    -1,    91,    92,    -1,    -1,    -1,    -1,
      -1,    98,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,     0,    -1,   141,   142,   143,    -1,   145,   146,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      88,    89,    -1,    91,    92,    -1,    -1,    -1,    -1,    -1,
      98,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,     0,    -1,   141,   142,   143,    -1,   145,   146,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    88,
      89,    -1,    91,    92,    -1,    -1,    -1,    -1,    -1,    98,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
       0,    -1,   141,   142,   143,    -1,   145,   146,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    88,    89,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   135,   136,   137,   138,     0,
      -1,   141,   142,   143,    -1,   145,   146,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   115,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,     0,    -1,
     141,   142,   143,    -1,   145,   146,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    86,    87,    88,    89,    -1,    91,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,     0,    -1,   141,
     142,   143,    -1,   145,   146,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,     0,   140,   141,   142,
     143,    -1,   145,   146,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    88,    89,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,     0,    -1,   141,   142,   143,
      -1,   145,   146,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,     0,   140,   141,   142,   143,    -1,
     145,   146,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,     0,   140,   141,   142,   143,    -1,   145,
     146,    -1,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,   118,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,     0,    -1,   141,    -1,   143,    -1,   145,   146,
      -1,     9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
     118,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,    -1,    -1,   141,    -1,   143,    -1,   145,   146,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,     1,   146,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    -1,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    99,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,     1,   146,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    13,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      94,    -1,    96,    97,    -1,    99,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,     1,   146,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    13,    -1,    -1,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,   131,   132,   133,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,   143,    -1,    -1,   146,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,   131,   132,
     133,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
     143,    -1,    -1,   146,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    99,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,   143,    -1,     1,
     146,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
      -1,   143,    -1,     1,   146,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    99,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,     1,   146,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      94,    -1,    96,    97,    -1,    99,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,     1,   146,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,   131,   132,   133,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,   143,    -1,    -1,   146,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    12,    13,   131,   132,
     133,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
     143,    -1,    -1,   146,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    12,    13,   131,   132,   133,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
     146,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    -1,    65,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      12,    13,   131,   132,   133,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,   143,    -1,    -1,   146,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,   131,
     132,   133,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,   146,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    -1,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    97,    -1,    99,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,   131,   132,   133,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,   143,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    99,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   132,   133,    -1,    -1,    -1,
      -1,    -1,   139,   140,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    -1,    -1,    -1,    -1,    -1,
     139,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    -1,    -1,    -1,    -1,    -1,   139,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,    -1,
      -1,    -1,    -1,    -1,   139,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,   132,   133,    -1,     3,     4,     5,
       6,   139,     8,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,   131,    12,    13,    -1,    -1,
      -1,    17,   138,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    99,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    12,    13,   131,   132,   133,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,   131,   132,   133,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,   131,
     132,   133,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    97,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    12,    13,   131,   132,   133,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    99,   100,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    12,    13,   131,   132,   133,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,
     131,   132,   133,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      94,    -1,    96,    97,    -1,    99,   100,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    13,   131,   132,   133,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    12,    13,   131,   132,   133,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    12,
      13,   131,   132,   133,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    12,    13,   131,   132,
     133,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    99,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    12,    13,   131,   132,   133,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    -1,    65,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      99,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      12,    13,   131,   132,   133,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,   131,
     132,   133,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    -1,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    97,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    12,    13,   131,   132,   133,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    12,    13,   131,   132,   133,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    -1,    65,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,
     131,   132,   133,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      94,    -1,    96,    97,    -1,    99,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,   131,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
     131,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,   131,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    -1,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,
      -1,    96,    97,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,   131,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    94,    -1,    96,    97,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,   131,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    -1,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,   131,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    53,    54,    -1,    -1,    57,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    53,    54,    -1,    -1,    57,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,   132,   133,    53,    54,    -1,    -1,    57,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,    53,    54,    -1,    -1,    57,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    53,    54,    -1,    -1,    57,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,   132,   133,    53,    54,    -1,    -1,
      57,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   132,   133,    53,    54,    -1,
      -1,    57,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    53,    54,
      -1,    -1,    57,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,    53,
      54,    -1,    -1,    57,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,   132,   133,
      53,    54,    -1,    -1,    57,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    53,    54,    -1,    -1,    57,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    -1,    -1,    -1,    -1,    -1,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   148,   149,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    17,    19,    20,    21,    22,    23,    24,
      25,    31,    32,    33,    34,    35,    36,    37,    40,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    60,    61,    62,    63,    65,    66,    67,    69,
      70,    90,    93,    94,    96,    97,    99,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   131,   132,   133,   150,
     151,   152,   159,   161,   162,   164,   165,   168,   169,   170,
     172,   173,   174,   176,   177,   187,   202,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   261,
     262,   276,   277,   278,   279,   280,   281,   282,   285,   287,
     288,   302,   304,   305,   306,   307,   308,   309,   310,   311,
     345,   358,   152,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    57,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    80,    81,    84,
      85,    86,    87,    99,   100,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   132,   133,   139,   180,   181,
     182,   183,   185,   186,   302,   304,    40,    59,    90,    93,
      99,   100,   101,   104,   132,   169,   177,   187,   189,   194,
     197,   199,   223,   307,   308,   310,   311,   343,   344,   194,
     194,   140,   195,   196,   140,   191,   195,   140,   146,   352,
      55,   182,   352,   153,   135,    22,    23,    31,    32,    33,
     168,   187,   223,   187,    57,     1,    48,    93,   155,   156,
     157,   159,   171,   172,   358,   204,   205,   190,   199,   343,
     358,   189,   342,   343,   358,    47,    90,   131,   138,   176,
     202,   223,   307,   308,   311,   252,   253,    55,    56,    58,
     180,   292,   303,   291,   292,   293,   144,   283,   144,   289,
     144,   286,   144,   290,   306,   164,   187,   187,   143,   146,
     351,   356,   357,    41,    42,    43,    44,    45,    38,    39,
      27,   135,   191,   195,   267,    29,   259,   118,   138,    93,
      99,   173,   118,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    86,    87,   119,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    88,
      89,   137,   145,   349,   203,   162,   163,   163,   208,   210,
     163,   351,   357,    90,   170,   177,   223,   240,   307,   308,
     311,    53,    57,    86,    90,   178,   179,   223,   307,   308,
     311,   179,    34,    35,    36,    37,    50,    51,    52,    53,
      57,   140,   180,   309,   340,   180,    89,   349,   350,   267,
     279,    91,    91,   138,   189,    57,   189,   189,   189,   291,
     118,    92,   138,   198,   358,    89,   137,   349,    91,    91,
     138,   198,   194,   352,   353,   194,   193,   194,   199,   343,
     358,   162,   353,   162,    55,    66,    67,   160,   140,   188,
     135,   155,    89,   349,    91,   159,   158,   171,   141,   351,
     357,   353,   353,   162,   142,   138,   146,   355,   138,   355,
     136,   355,   352,    57,   306,   173,   175,   138,    89,   137,
     349,   254,    64,   111,   113,   114,   294,   114,   294,   114,
      68,   294,   114,   114,   284,   294,   114,    64,   114,   114,
     114,   284,   114,    64,   114,    71,   143,   152,   163,   163,
     163,   163,   159,   162,   162,   269,   268,    98,   166,   260,
      99,   164,   189,   199,   200,   201,   171,   138,   176,   138,
     161,   164,   177,   187,   189,   201,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,    53,    54,    57,   185,   266,   346,   347,   193,
      53,    54,    57,   185,   265,   346,   154,   155,    14,   236,
     356,   236,   163,   163,   351,    18,   270,    57,    89,   137,
     349,    26,   162,    53,    57,   178,   122,   312,    89,   137,
     349,   216,   341,   217,    89,   145,   348,   219,    53,    57,
     346,   164,   187,   164,   187,   184,   116,   187,   189,    99,
     189,   197,   343,    53,    57,   193,    53,    57,   344,   353,
     141,   353,   138,   138,   353,   182,   207,   187,   150,   136,
     346,   346,   187,   135,   353,   157,   206,   343,   138,   175,
      53,    57,   193,    53,    57,    53,    55,    56,    57,    58,
      59,    71,    93,    99,   100,   101,   125,   128,   140,   257,
     316,   318,   319,   320,   321,   322,   323,   324,   325,   328,
     329,   330,   331,   334,   335,   336,   337,   338,   296,   295,
     144,   294,   144,   144,   144,   187,    79,   123,   247,   248,
     358,   247,   167,   247,   189,   138,   353,   175,   138,   118,
      45,   352,    91,    91,   191,   195,   264,   352,   354,    91,
      91,   191,   195,   263,    11,   235,     9,   272,   358,   155,
      14,   155,    28,   237,   356,   237,   270,   199,   235,    53,
      57,   193,    53,    57,   212,   215,   313,   214,    53,    57,
     178,   193,   154,   162,   218,   221,   220,   191,   192,   195,
     358,    45,   182,   189,   189,   198,    91,    91,   354,    91,
      91,   343,   162,   136,   150,   353,   355,   173,   354,    93,
      99,   241,   242,   243,   320,   318,   255,   118,   138,   317,
     189,   138,   339,   358,    53,   138,   339,   138,   317,    53,
     138,   317,    53,   297,    55,    56,    58,   301,   311,   244,
     246,   249,   321,   323,   324,   326,   327,   330,   332,   333,
     336,   338,   352,   155,   155,   247,   155,    99,   189,   175,
     187,   120,   164,   187,   164,   187,   166,   191,   142,    91,
     164,   187,   164,   187,   166,   192,   189,   201,   273,   358,
      16,   239,   358,    15,   238,   239,   239,   209,   211,   235,
     138,   236,   354,   163,   356,   163,   154,   354,   235,   353,
     140,   314,   315,   180,   314,   267,   259,   187,    91,   138,
     353,   136,   243,   138,   320,   138,   353,   249,   256,   189,
     316,   322,   334,   336,   325,   330,   338,   323,   331,   336,
     321,   323,   298,   249,   123,   118,   138,   245,    90,   223,
     138,   339,   339,   138,   245,   138,   245,   143,    11,   136,
     155,    11,   189,   187,   164,   187,    92,   274,   358,   155,
      10,   275,   358,   163,   235,   235,   155,   155,   189,   155,
     237,   154,   356,   235,   318,   154,   318,   222,   154,   353,
     242,   138,    99,   241,   141,    30,   115,   258,   138,   317,
     138,   317,   339,   138,   317,   138,   317,   317,   299,   123,
     223,   244,   333,   336,    57,    89,   326,   330,   323,   332,
     336,   323,    53,   250,   251,   319,   136,    90,   177,   223,
     307,   308,   311,   236,   155,   236,   235,   235,   239,   270,
     271,   213,   235,   353,   235,   356,   314,   235,   138,   242,
     138,   320,   155,   155,   323,   336,   323,   323,   300,   138,
     245,   138,   245,    53,    57,   339,   138,   245,   138,   245,
     245,   138,   352,    57,    89,   137,   349,   155,   155,   155,
     154,   242,   138,    11,   136,   317,   138,   317,   317,   317,
     155,   323,   336,   323,   323,   251,    53,    57,   193,    53,
      57,   272,   238,   235,   235,   242,   323,   112,   245,   138,
     245,   245,   245,   354,   317,   323,   245
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   147,   149,   148,   150,   151,   151,   151,   151,   152,
     153,   152,   154,   155,   156,   156,   156,   156,   157,   158,
     157,   160,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   161,   161,   162,   162,   162,
     162,   162,   162,   163,   164,   164,   165,   165,   167,   166,
     168,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     178,   178,   179,   179,   179,   180,   180,   180,   180,   180,
     181,   181,   182,   182,   183,   184,   183,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   187,   187,   187,   189,   190,   190,   190,   190,   191,
     192,   192,   193,   193,   193,   193,   193,   194,   194,   194,
     194,   194,   196,   195,   197,   198,   198,   199,   199,   199,
     199,   200,   200,   201,   201,   201,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   203,   202,   204,
     202,   205,   206,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   207,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   208,   209,   202,   210,   211,   202,   202,
     202,   212,   213,   202,   214,   202,   215,   202,   216,   202,
     217,   218,   202,   219,   220,   202,   221,   222,   202,   202,
     202,   202,   202,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   236,   236,   237,
     237,   238,   238,   239,   239,   240,   240,   241,   241,   242,
     242,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     244,   244,   244,   244,   245,   245,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   247,   247,   248,   248,   248,   249,   249,   250,   250,
     251,   251,   253,   254,   255,   256,   252,   257,   257,   258,
     258,   260,   259,   261,   261,   261,   261,   262,   263,   262,
     264,   262,   262,   265,   262,   266,   262,   262,   262,   262,
     268,   267,   269,   267,   270,   271,   271,   272,   272,   273,
     273,   273,   274,   274,   275,   275,   276,   276,   276,   277,
     278,   278,   278,   279,   280,   281,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   287,   288,   288,
     289,   289,   290,   290,   291,   291,   292,   292,   293,   293,
     294,   295,   294,   296,   297,   298,   299,   300,   294,   301,
     301,   301,   301,   302,   303,   303,   303,   303,   304,   305,
     305,   306,   306,   306,   306,   307,   307,   307,   307,   307,
     308,   308,   308,   308,   308,   308,   308,   309,   309,   310,
     310,   311,   311,   313,   312,   312,   314,   315,   314,   316,
     316,   316,   316,   317,   317,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     319,   319,   319,   319,   320,   320,   321,   322,   322,   323,
     323,   324,   325,   325,   326,   326,   327,   327,   328,   328,
     329,   329,   330,   330,   331,   332,   333,   333,   334,   334,
     335,   335,   336,   336,   337,   337,   338,   339,   339,   340,
     341,   340,   342,   342,   343,   343,   344,   344,   344,   344,
     345,   345,   345,   346,   346,   346,   346,   347,   347,   347,
     348,   348,   349,   349,   350,   350,   351,   351,   352,   352,
     353,   354,   355,   355,   355,   356,   356,   357,   357,   358
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     3,     5,     6,     5,     5,     5,     5,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       0,     4,     6,     1,     1,     1,     2,     4,     2,     3,
       1,     1,     1,     1,     2,     4,     2,     1,     2,     2,
       4,     1,     0,     2,     2,     2,     1,     1,     2,     3,
       4,     1,     1,     3,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       3,     0,     0,     5,     3,     3,     2,     3,     3,     1,
       4,     3,     1,     0,     6,     4,     3,     2,     1,     2,
       2,     6,     6,     0,     0,     7,     0,     0,     7,     5,
       4,     0,     0,     9,     0,     6,     0,     7,     0,     5,
       0,     0,     7,     0,     0,     7,     0,     0,     9,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     4,     6,     3,     5,     2,     4,     1,     3,
       4,     2,     2,     1,     2,     0,     6,     8,     4,     6,
       4,     2,     6,     2,     4,     6,     2,     4,     2,     4,
       1,     1,     1,     3,     1,     4,     1,     4,     1,     3,
       1,     1,     0,     0,     0,     0,     6,     4,     1,     3,
       3,     0,     5,     2,     4,     5,     5,     2,     0,     5,
       0,     5,     3,     0,     4,     0,     4,     2,     1,     4,
       0,     5,     0,     5,     5,     1,     1,     6,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     0,     3,
       1,     2,     3,     3,     0,     3,     3,     3,     3,     3,
       0,     3,     0,     3,     0,     2,     0,     2,     0,     2,
       1,     0,     3,     0,     0,     0,     0,     0,     8,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     3,     0,     3,     4,
       2,     2,     1,     2,     0,     6,     8,     4,     6,     4,
       6,     2,     4,     6,     2,     4,     2,     4,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     2,     1,     2,     1,     1,     3,     1,     3,
       1,     1,     2,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     1,     2,     2,     1,     1,
       0,     4,     1,     2,     1,     3,     3,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       2,     2,     0,     1,     1,     1,     1,     1,     2,     0
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
#line 605 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_BEG);
                    local_push(0);
                    class_nest = 0;
                  }
#line 4621 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 611 "grammar.y" /* yacc.c:1661  */
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
#line 4643 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 631 "grammar.y" /* yacc.c:1661  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4652 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 638 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4660 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 642 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4668 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 646 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4676 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 650 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4684 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 657 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single) {
                      yy_error("BEGIN in method");
                    }
                  }
#line 4694 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 663 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_PREEXE((yyvsp[-1].node));
                  }
#line 4702 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 672 "grammar.y" /* yacc.c:1661  */
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
#line 4724 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 692 "grammar.y" /* yacc.c:1661  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4733 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 699 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4741 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 703 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4749 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 707 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4757 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 711 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4765 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 717 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4773 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 721 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("BEGIN is permitted only at toplevel");
                  }
#line 4781 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 725 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4789 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 730 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);}
#line 4795 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 731 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ALIAS((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4803 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 735 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 4811 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 739 "grammar.y" /* yacc.c:1661  */
    {
                    char buf[2];
                    buf[0] = '$';
                    buf[1] = (char)(yyvsp[0].node)->nd_nth;
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), parser_intern2(buf, 2));
                  }
#line 4822 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 746 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("can't make alias for the number variables");
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4831 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 751 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4839 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 755 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4848 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 760 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4857 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 765 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4869 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 773 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4881 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 781 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *resq = NEW_RESBODY(0, remove_begin((yyvsp[0].node)), 0);
                    (yyval.node) = NEW_RESCUE(remove_begin((yyvsp[-2].node)), resq, 0);
                  }
#line 4890 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 786 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single) {
                      rb_warn("END in method; use at_exit");
                    }

                    (yyval.node) = NEW_POSTEXE(NEW_NODE(NODE_SCOPE,
                            0 /* tbl */, (yyvsp[-1].node) /* body */, 0 /* args */));
                  }
#line 4903 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 796 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 4913 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 802 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4922 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 807 "grammar.y" /* yacc.c:1661  */
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
#line 4943 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 824 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4952 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 829 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4961 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 834 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4970 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 839 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), parser_intern("::"), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4979 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 844 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4988 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 849 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4997 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 854 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 5006 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 862 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5015 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 867 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5024 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 875 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5032 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 879 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5040 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 883 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5048 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 887 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5056 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 894 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 5066 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 907 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5074 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 913 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 5083 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 920 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 5093 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 928 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                    nd_set_line((yyval.node), tokline);
                  }
#line 5102 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 935 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                 }
#line 5111 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 940 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[-2].node)->nd_args = (yyvsp[-1].node);
                    (yyvsp[0].node)->nd_iter = (yyvsp[-2].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-2].node));
                 }
#line 5123 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 948 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5132 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 953 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                 }
#line 5143 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 960 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5152 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 965 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 5163 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 972 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5172 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 977 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_yield((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5181 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 982 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETURN(ret_args((yyvsp[0].node)));
                  }
#line 5189 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 986 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BREAK(ret_args((yyvsp[0].node)));
                  }
#line 5197 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 990 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_NEXT(ret_args((yyvsp[0].node)));
                  }
#line 5205 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 997 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5213 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 1004 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(NEW_LIST((yyvsp[-1].node)), 0);
                  }
#line 5221 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 1010 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 5229 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 1014 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(list_append((yyvsp[-1].node), (yyvsp[0].node)), 0);
                  }
#line 5237 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 1018 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5245 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 1022 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5253 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 1026 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-1].node), -1);
                  }
#line 5261 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 1030 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5269 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 1034 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, (yyvsp[0].node));
                  }
#line 5277 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 1038 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5285 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 1042 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 5293 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 1046 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5301 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 1053 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5309 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 1059 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[-1].node));
                  }
#line 5317 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 1063 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 5325 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 1069 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 5333 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 1073 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5341 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 1079 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5349 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 1083 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5357 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 1087 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5365 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 1091 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5373 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 1095 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), parser_intern("::"), (yyvsp[0].id));
                  }
#line 5381 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 1099 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5389 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 1103 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5399 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 1109 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5409 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 1115 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5418 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 1122 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5427 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 1127 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5436 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 1132 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5444 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 1136 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5452 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 1140 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), parser_intern("::"), (yyvsp[0].id));
                  }
#line 5460 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 1144 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 5468 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 1148 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5478 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 1154 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5488 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 1160 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5497 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 1167 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("class/module name must be CONSTANT");
                  }
#line 5505 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 1174 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 5513 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 1178 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2(0, (yyval.node));
                  }
#line 5521 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 1182 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5529 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 1191 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_ENDFN);
                    (yyval.id) = convert_op((yyvsp[0].id));
                  }
#line 5538 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 1196 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_ENDFN);
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 5547 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 1207 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 5555 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 1214 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNDEF((yyvsp[0].node));
                  }
#line 5563 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 1217 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME | EXPR_FITEM);}
#line 5569 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 1218 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-3].node), NEW_UNDEF((yyvsp[0].node)));
                  }
#line 5577 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 1223 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '|'; }
#line 5583 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 1224 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '^'; }
#line 5589 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 1225 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '&'; }
#line 5595 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 1226 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tCMP; }
#line 5601 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 1227 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tEQ; }
#line 5607 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 1228 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tEQQ; }
#line 5613 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 1229 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tMATCH; }
#line 5619 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 1230 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tNMATCH; }
#line 5625 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 1231 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '>'; }
#line 5631 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 1232 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tGEQ; }
#line 5637 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 1233 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '<'; }
#line 5643 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 1234 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tLEQ; }
#line 5649 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 1235 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tNEQ; }
#line 5655 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 1236 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tLSHFT; }
#line 5661 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 1237 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tRSHFT; }
#line 5667 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 1238 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '+'; }
#line 5673 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 1239 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '-'; }
#line 5679 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 1240 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '*'; }
#line 5685 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 1241 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '*'; }
#line 5691 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 1242 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '/'; }
#line 5697 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 1243 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '%'; }
#line 5703 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 1244 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tPOW; }
#line 5709 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 1245 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tDSTAR; }
#line 5715 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 1246 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '!'; }
#line 5721 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 1247 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '~'; }
#line 5727 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 1248 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tUPLUS; }
#line 5733 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 1249 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tUMINUS; }
#line 5739 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 1250 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tAREF; }
#line 5745 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 1251 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tASET; }
#line 5751 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 1252 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '`'; }
#line 5757 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 1270 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5766 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 1275 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    (yyval.node) = node_assign((yyvsp[-4].node), (yyvsp[-2].node));
                  }
#line 5776 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1281 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5785 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1286 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    new_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].node));
                  }
#line 5795 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1292 "grammar.y" /* yacc.c:1661  */
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
#line 5820 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1313 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5829 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1318 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5838 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1323 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), parser_intern("::"), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5847 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1328 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5856 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1333 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5865 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1338 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5874 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1343 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT2((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5884 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1349 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT3((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5894 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1355 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '+', (yyvsp[0].node));
                  }
#line 5902 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1359 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '-', (yyvsp[0].node));
                  }
#line 5910 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1363 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '*', (yyvsp[0].node));
                  }
#line 5918 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1367 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '/', (yyvsp[0].node));
                  }
#line 5926 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1371 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '%', (yyvsp[0].node));
                  }
#line 5934 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1375 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node));
                  }
#line 5942 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1379 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL(call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node)), tUMINUS, 0);
                  }
#line 5950 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1383 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUPLUS);
                  }
#line 5958 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1387 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUMINUS);
                  }
#line 5966 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1391 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '|', (yyvsp[0].node));
                  }
#line 5974 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1395 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '^', (yyvsp[0].node));
                  }
#line 5982 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1399 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '&', (yyvsp[0].node));
                  }
#line 5990 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1403 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tCMP, (yyvsp[0].node));
                  }
#line 5998 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1407 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '>', (yyvsp[0].node));
                  }
#line 6006 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1411 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tGEQ, (yyvsp[0].node));
                  }
#line 6014 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1415 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '<', (yyvsp[0].node));
                  }
#line 6022 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1419 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLEQ, (yyvsp[0].node));
                  }
#line 6030 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1423 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQ, (yyvsp[0].node));
                  }
#line 6038 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1427 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQQ, (yyvsp[0].node));
                  }
#line 6046 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1431 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNEQ, (yyvsp[0].node));
                  }
#line 6054 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1435 "grammar.y" /* yacc.c:1661  */
    {
                    /* TODO */
                    (yyval.node) = match_op((yyvsp[-2].node), (yyvsp[0].node));
                    /*
                    if(nd_type($1) == NODE_LIT && TYPE($1->nd_lit) == T_REGEXP) {
                      $$ = reg_named_capture_assign($1->nd_lit, $$);
                    }
                    */
                  }
#line 6068 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1445 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNMATCH, (yyvsp[0].node));
                  }
#line 6076 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1449 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 6084 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1453 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), '~');
                  }
#line 6092 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1457 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLSHFT, (yyvsp[0].node));
                  }
#line 6100 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1461 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tRSHFT, (yyvsp[0].node));
                  }
#line 6108 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1465 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6116 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1469 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6124 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1472 "grammar.y" /* yacc.c:1661  */
    {in_defined = 1;}
#line 6130 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1473 "grammar.y" /* yacc.c:1661  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[0].node));
                  }
#line 6139 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1478 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-5].node));
                    (yyval.node) = NEW_IF(cond((yyvsp[-5].node)), (yyvsp[-3].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-5].node));
                  }
#line 6149 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1484 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6157 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1490 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6167 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1499 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6175 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1503 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6183 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1507 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6191 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1513 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6199 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1525 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6207 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1529 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6215 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1533 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6223 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1539 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6232 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1544 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_blk_pass((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 6240 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1548 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[-1].node) ? NEW_HASH((yyvsp[-1].node)) : 0);
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6249 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1553 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node) ? arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node))) : (yyvsp[-3].node);
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6258 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1560 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.val) = cmdarg_stack;
                    CMDARG_PUSH(1);
                  }
#line 6267 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1565 "grammar.y" /* yacc.c:1661  */
    {
                    /* CMDARG_POP() */
                    cmdarg_stack = (yyvsp[-1].val);
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6277 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1573 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BLOCK_PASS((yyvsp[0].node));
                  }
#line 6285 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1579 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6293 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1583 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 6301 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1589 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6309 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1593 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6317 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1597 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6330 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1606 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((nd_type((yyvsp[0].node)) == NODE_ARRAY) && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6343 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1621 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6356 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1630 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if(nd_type((yyvsp[0].node)) == NODE_ARRAY && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6369 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1639 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6377 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1655 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                  }
#line 6385 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1659 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cmdarg_stack;
                    cmdarg_stack = 0;
                    (yyval.num) = sourceline;
                  }
#line 6395 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1666 "grammar.y" /* yacc.c:1661  */
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
#line 6412 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1678 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_ENDARG);}
#line 6418 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1679 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 6426 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1683 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cmdarg_stack;
                    cmdarg_stack = 0;
                  }
#line 6435 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1687 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_ENDARG);}
#line 6441 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1688 "grammar.y" /* yacc.c:1661  */
    {
                    cmdarg_stack = (yyvsp[-4].val);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 6450 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1693 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6458 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1697 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 6466 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1701 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 6474 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1705 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-1].node) == 0) {
                      (yyval.node) = NEW_ZARRAY(); /* zero length array*/
                    } else {
                      (yyval.node) = (yyvsp[-1].node);
                    }
                  }
#line 6486 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1713 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_HASH((yyvsp[-1].node));
                  }
#line 6494 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1717 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETURN(0);
                  }
#line 6502 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1721 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_yield((yyvsp[-1].node));
                  }
#line 6510 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 1725 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6518 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1729 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6526 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1732 "grammar.y" /* yacc.c:1661  */
    {in_defined = 1;}
#line 6532 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1733 "grammar.y" /* yacc.c:1661  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[-1].node));
                  }
#line 6541 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1738 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[-1].node)), '!');
                  }
#line 6549 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 306:
#line 1742 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond(NEW_NIL()), '!');
                  }
#line 6557 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1746 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyvsp[0].node)->nd_iter, (yyvsp[0].node));
                  }
#line 6567 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1753 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-1].node));
                  }
#line 6578 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 1760 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6586 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1767 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6595 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1775 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6604 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1779 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6610 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1779 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6616 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1782 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_WHILE(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6625 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1786 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6631 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1786 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6637 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1789 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNTIL(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6646 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1796 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CASE((yyvsp[-3].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 6655 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1801 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CASE(0, (yyvsp[-1].node));
                  }
#line 6663 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1805 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6669 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1807 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6675 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1810 "grammar.y" /* yacc.c:1661  */
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
#line 6693 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1824 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("class definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6705 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1833 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CLASS((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-3].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6716 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1840 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = (in_def << 1) | in_single;
                    in_def = 0;
                    in_single = 0;
                    class_nest++;
                    local_push(0);
                  }
#line 6728 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1850 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SCLASS((yyvsp[-4].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                    local_pop();
                    class_nest--;
                    in_def = ((yyvsp[-3].num) >> 1) & 1;
                    in_single = (yyvsp[-3].num) & 1;
                  }
#line 6741 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1859 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("module definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6753 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1868 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MODULE((yyvsp[-3].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6764 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1875 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    local_push(0);
                  }
#line 6774 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1880 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 1;
                  }
#line 6783 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1887 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFN((yyvsp[-5].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-6].num));
                    local_pop();
                    in_def = (yyvsp[-3].num) & 1;
                    cur_mid = (yyvsp[-4].id);
                  }
#line 6796 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1896 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    local_push(0);
                  }
#line 6806 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1901 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 1;
                  }
#line 6815 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1908 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_FUN((yyvsp[-5].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-6].num));
                    local_pop();
                    in_def = (yyvsp[-3].num) & 1;
                    cur_mid = (yyvsp[-4].id);
                  }
#line 6828 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1916 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_FNAME);}
#line 6834 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1917 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-1].num) = in_single;
                    in_single = 1;
                    SET_LEX_STATE(EXPR_ENDFN | EXPR_LABEL); /* force for args */
                    local_push(0);
                  }
#line 6845 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1926 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFS((yyvsp[-7].node), (yyvsp[-4].id), (yyvsp[-2].node), body);
                    nd_set_line((yyval.node), (yyvsp[-8].num));
                    local_pop();
                    in_single = (yyvsp[-5].num) & 1;
                  }
#line 6857 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1934 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BREAK(0);
                  }
#line 6865 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1938 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_NEXT(0);
                  }
#line 6873 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1942 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_REDO();
                  }
#line 6881 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1946 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETRY();
                  }
#line 6889 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1952 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6899 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1960 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("begin");
                  }
#line 6907 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1966 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("if");
                  }
#line 6915 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1972 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("unless");
                  }
#line 6923 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1978 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("while");
                  }
#line 6931 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1984 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("until");
                  }
#line 6939 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1990 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("case");
                  }
#line 6947 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 350:
#line 1996 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("for");
                  }
#line 6955 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 2002 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("class");
                  }
#line 6963 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 2008 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("module");
                  }
#line 6971 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 353:
#line 2014 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("def");
                    (yyval.num) = sourceline;
                  }
#line 6980 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 354:
#line 2021 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("fun");
                    (yyval.num) = sourceline;
                  }
#line 6989 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 355:
#line 2028 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_pop("end");
                  }
#line 6997 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 2046 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-3].node)), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 7006 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 2054 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7014 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 2064 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 7022 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 2068 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7030 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 2074 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7038 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 2078 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 7046 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 2084 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 7054 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 372:
#line 2088 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), (yyval.node));
                  }
#line 7063 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 373:
#line 2093 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-5].node), NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 7072 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 2098 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), -1);
                  }
#line 7080 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 2102 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7088 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 2106 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN(0, (yyval.node));
                  }
#line 7097 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 2111 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 7106 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 2116 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 7114 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 2120 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7122 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 2126 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7130 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 2130 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 7138 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 2134 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7146 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 2138 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 7154 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 2144 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7162 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 2148 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 7170 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 2154 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7178 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 2158 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7186 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 2162 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7194 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 2166 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7202 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 2170 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7210 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 2174 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 1, 0, new_args_tail(0, 0, 0));
                  }
#line 7218 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 2178 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7226 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 2182 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 7234 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 2186 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7242 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 2190 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7250 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 2194 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7258 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 2198 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7266 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 2202 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7274 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 2206 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7282 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 2210 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 7290 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 2217 "grammar.y" /* yacc.c:1661  */
    {
                    command_start = TRUE;
                  }
#line 7298 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 2223 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX(0, (yyvsp[-1].node)) : 0;
                  }
#line 7307 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 2228 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7315 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 2232 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX((yyvsp[-2].node), (yyvsp[-1].node)) : (yyvsp[-2].node);
                  }
#line 7324 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 2239 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7332 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 2243 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7341 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 2250 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7350 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 2255 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 7359 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 2262 "grammar.y" /* yacc.c:1661  */
    {
                    new_bv(get_id((yyvsp[0].id)));
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIT(ID2SYM(get_id((yyvsp[0].id))));
                  }
#line 7369 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 2268 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7377 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 2273 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.vars) = bv_push();
                  }
#line 7385 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 2276 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = lpar_beg;
                    lpar_beg = ++paren_nest;
                  }
#line 7394 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 2281 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7402 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 2284 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.val) = cmdarg_stack;
                    cmdarg_stack = 0;
                  }
#line 7411 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 2289 "grammar.y" /* yacc.c:1661  */
    {
                    lpar_beg = (yyvsp[-4].num);
                    cmdarg_stack = (yyvsp[-1].val);
                    CMDARG_LEXPOP();
                    (yyval.node) = NEW_LAMBDA((yyvsp[-3].node), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    bv_pop((yyvsp[-5].vars));
                  }
#line 7424 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 2300 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 7432 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 2304 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7440 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 2310 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7448 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 2314 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7456 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 2320 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7465 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 2327 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7475 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 2335 "grammar.y" /* yacc.c:1661  */
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
#line 7490 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 2346 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 7498 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 2350 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7509 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 2357 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7520 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 2366 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 7530 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 2372 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7538 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 2376 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7547 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 2381 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7555 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 2385 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7564 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 2390 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].id), 0);
                  }
#line 7572 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 2394 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7580 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 2398 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_QCALL((yyvsp[-2].id), (yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7589 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 2403 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7597 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 2407 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7606 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 2412 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                  }
#line 7614 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 2416 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZSUPER();
                  }
#line 7622 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 439:
#line 2420 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-3].node) && nd_type((yyvsp[-3].node)) == NODE_SELF) {
                      (yyval.node) = NEW_FCALL(tAREF, (yyvsp[-1].node));
                    } else {
                      (yyval.node) = NEW_CALL((yyvsp[-3].node), tAREF, (yyvsp[-1].node));
                    }
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 7635 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 2431 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7644 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 441:
#line 2437 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7654 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 2443 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7663 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 2449 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7673 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 444:
#line 2459 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_WHEN((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7681 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 2471 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-3].node)) {
                      /* TODO NEW_ERRINFO() */
                      (yyvsp[-3].node) = node_assign((yyvsp[-3].node), NEW_GVAR(parser_intern("$!")));
                      (yyvsp[-1].node) = block_append((yyvsp[-3].node), (yyvsp[-1].node));
                    }
                    (yyval.node) = NEW_RESBODY((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-4].node) ? (yyvsp[-4].node) : (yyvsp[-1].node));
                  }
#line 7695 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 449:
#line 2484 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7703 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 2488 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = splat_array((yyvsp[0].node)))) (yyval.node) = (yyvsp[0].node);
                  }
#line 7711 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 2495 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7719 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 454:
#line 2502 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7727 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 457:
#line 2510 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 7735 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 459:
#line 2517 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *node = (yyvsp[0].node);
                    if(!node) {
                      node = NEW_STR(STR_NEW0());
                    } else {
                      node = evstr2dstr(node);
                    }
                    (yyval.node) = node;
                  }
#line 7749 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 462:
#line 2531 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7757 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 463:
#line 2537 "grammar.y" /* yacc.c:1661  */
    {
                    heredoc_dedent((yyvsp[-1].node));
                    heredoc_indent = 0;
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7767 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 464:
#line 2545 "grammar.y" /* yacc.c:1661  */
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
#line 7795 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 465:
#line 2571 "grammar.y" /* yacc.c:1661  */
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
#line 7857 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 466:
#line 2631 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7865 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 2635 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7873 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 468:
#line 2641 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7881 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 469:
#line 2645 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), evstr2dstr((yyvsp[-1].node)));
                  }
#line 7889 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 471:
#line 2652 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7897 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 2658 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7905 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 473:
#line 2662 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7913 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 474:
#line 2668 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7921 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 2672 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-1].node) = evstr2dstr((yyvsp[-1].node));
                    nd_set_type((yyvsp[-1].node), NODE_DSYM);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7931 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 2680 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7939 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 2684 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7947 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 2690 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7955 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 479:
#line 2694 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7963 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 480:
#line 2700 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7971 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 481:
#line 2704 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7979 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 482:
#line 2710 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7987 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 483:
#line 2714 "grammar.y" /* yacc.c:1661  */
    {
                    VALUE lit;
                    lit = (yyvsp[-1].node)->nd_lit;
                    (yyvsp[-1].node)->nd_lit = ID2SYM(parser_intern_str(lit));
                    nd_set_type((yyvsp[-1].node), NODE_LIT);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7999 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 484:
#line 2724 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8007 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 485:
#line 2728 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8015 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 486:
#line 2734 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8023 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 487:
#line 2738 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8031 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 488:
#line 2744 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8039 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 489:
#line 2748 "grammar.y" /* yacc.c:1661  */
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
#line 8064 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 2772 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                    SET_LEX_STATE(EXPR_BEG);
                  }
#line 8074 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 2778 "grammar.y" /* yacc.c:1661  */
    {
                    lex_strterm = (yyvsp[-1].node);
                    (yyval.node) = NEW_EVSTR((yyvsp[0].node));
                  }
#line 8083 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 493:
#line 2783 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cond_stack;
                    (yyval.val) = cmdarg_stack;
                    cond_stack = 0;
                    cmdarg_stack = 0;
                  }
#line 8094 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 2789 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                  }
#line 8103 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 495:
#line 2793 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = lex_state;
                    SET_LEX_STATE(EXPR_BEG);
                  }
#line 8112 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 496:
#line 2797 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = brace_nest;
                    brace_nest = 0;
                  }
#line 8121 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 497:
#line 2801 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = heredoc_indent;
                    heredoc_indent = 0;
                  }
#line 8130 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 498:
#line 2806 "grammar.y" /* yacc.c:1661  */
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
#line 8147 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 499:
#line 2820 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_GVAR((yyvsp[0].id));}
#line 8153 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 500:
#line 2821 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_IVAR((yyvsp[0].id));}
#line 8159 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 501:
#line 2822 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_CVAR((yyvsp[0].id));}
#line 8165 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 503:
#line 2827 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_END);
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8174 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 508:
#line 2840 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_END);
                    (yyval.node) = dsym_node((yyvsp[-1].node));
                  }
#line 8183 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 510:
#line 2848 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = negate_lit((yyvsp[0].node));
                  }
#line 8191 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 520:
#line 2866 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_nil;}
#line 8197 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 521:
#line 2867 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_self;}
#line 8203 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 522:
#line 2868 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_true;}
#line 8209 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 523:
#line 2869 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_false;}
#line 8215 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 524:
#line 2870 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__FILE__;}
#line 8221 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 525:
#line 2871 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__LINE__;}
#line 8227 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 526:
#line 2872 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__ENCODING__;}
#line 8233 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 527:
#line 2876 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8243 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 528:
#line 2882 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8253 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 529:
#line 2890 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8261 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 530:
#line 2894 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8269 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 533:
#line 2904 "grammar.y" /* yacc.c:1661  */
    {
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
#line 8278 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 534:
#line 2909 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8286 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 535:
#line 2913 "grammar.y" /* yacc.c:1661  */
    {
                    yyerrok;
                    (yyval.node) = 0;
                  }
#line 8295 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 536:
#line 2920 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
#line 8305 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 537:
#line 2925 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_kwarg;
                    in_kwarg = 1;
                    SET_LEX_STATE(lex_state | EXPR_LABEL);  /* force for args */
                  }
#line 8315 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 538:
#line 2931 "grammar.y" /* yacc.c:1661  */
    {
                    in_kwarg = !!(yyvsp[-2].num);
                    (yyval.node) = (yyvsp[-1].node);
                    SET_LEX_STATE(EXPR_BEG);
                    command_start = TRUE;
                  }
#line 8326 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 539:
#line 2940 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8334 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 540:
#line 2944 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 8342 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 541:
#line 2948 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8350 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 542:
#line 2952 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 8358 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 543:
#line 2958 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8366 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 544:
#line 2962 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 8374 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 545:
#line 2968 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8382 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 546:
#line 2972 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8390 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 547:
#line 2976 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8398 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 548:
#line 2980 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8406 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 549:
#line 2984 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8414 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 550:
#line 2988 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8422 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 551:
#line 2992 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 8430 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 552:
#line 2996 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8438 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 553:
#line 3000 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8446 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 554:
#line 3004 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8454 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 555:
#line 3008 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8462 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 556:
#line 3012 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8470 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 557:
#line 3016 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8478 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 558:
#line 3020 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 8486 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 559:
#line 3024 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                    (yyval.node) = new_args(0, 0, 0, 0, (yyval.node));
                  }
#line 8495 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 560:
#line 3031 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a constant");
                    (yyval.id) = 0;
                  }
#line 8504 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 561:
#line 3036 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be an instance variable");
                    (yyval.id) = 0;
                  }
#line 8513 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 562:
#line 3041 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a global variable");
                    (yyval.id) = 0;
                  }
#line 8522 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 563:
#line 3046 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a class variable");
                    (yyval.id) = 0;
                  }
#line 8531 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 565:
#line 3054 "grammar.y" /* yacc.c:1661  */
    {
                    formal_argument(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8540 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 566:
#line 3061 "grammar.y" /* yacc.c:1661  */
    {
                    ID id = get_id((yyvsp[0].id));
                    arg_var(id);
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8550 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 567:
#line 3069 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ARGS_AUX((yyvsp[0].id), 1);
                  }
#line 8558 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 568:
#line 3073 "grammar.y" /* yacc.c:1661  */
    {
                    ID tid = internal_id();
                    arg_var(tid);
                    (yyvsp[-1].node)->nd_value = NEW_LVAR(tid);
                    (yyval.node) = NEW_ARGS_AUX(tid, 1);
                    (yyval.node)->nd_next = (yyvsp[-1].node);
                  }
#line 8570 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 570:
#line 3084 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                    (yyval.node)->nd_plen++;
                    (yyval.node)->nd_next = block_append((yyval.node)->nd_next, (yyvsp[0].node)->nd_next);
                  }
#line 8580 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 571:
#line 3092 "grammar.y" /* yacc.c:1661  */
    {
                    ID id = get_id((yyvsp[0].id));
                    arg_var(formal_argument(id));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8590 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 572:
#line 3100 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8599 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 573:
#line 3105 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8608 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 574:
#line 3112 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8617 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 575:
#line 3117 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8626 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 576:
#line 3124 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8634 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 577:
#line 3128 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while(kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8647 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 578:
#line 3139 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8655 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 579:
#line 3143 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while(kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8668 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 582:
#line 3158 "grammar.y" /* yacc.c:1661  */
    {
                    shadowing_lvar(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8677 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 583:
#line 3163 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = internal_id();
                    arg_var((yyval.id));
                  }
#line 8686 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 584:
#line 3170 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8695 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 585:
#line 3177 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8704 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 586:
#line 3184 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8712 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 587:
#line 3188 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8725 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 588:
#line 3199 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8733 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 589:
#line 3203 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8746 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 592:
#line 3218 "grammar.y" /* yacc.c:1661  */
    {
                    if(!is_local_id((yyvsp[0].id))) {
                      yy_error("rest argument must be local variable");
                    }
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8758 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 593:
#line 3226 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = internal_id();
                    arg_var((yyval.id));
                  }
#line 8767 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 596:
#line 3237 "grammar.y" /* yacc.c:1661  */
    {
                    if(!is_local_id((yyvsp[0].id)))
                      yy_error("block argument must be local variable");
                    else if(!in_block() && local_id((yyvsp[0].id)))
                      yy_error("duplicate block argument name");
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8780 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 597:
#line 3248 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8788 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 598:
#line 3252 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = 0;
                  }
#line 8796 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 599:
#line 3258 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 8806 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 600:
#line 3263 "grammar.y" /* yacc.c:1661  */
    {SET_LEX_STATE(EXPR_BEG);}
#line 8812 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 601:
#line 3264 "grammar.y" /* yacc.c:1661  */
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
#line 8838 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 603:
#line 3289 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8846 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 605:
#line 3296 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_concat((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 8854 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 606:
#line 3302 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST((yyvsp[-2].node)), (yyvsp[0].node));
                  }
#line 8862 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 607:
#line 3306 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(NEW_LIT(ID2SYM((yyvsp[-1].id)))), (yyvsp[0].node));
                  }
#line 8870 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 608:
#line 3310 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(dsym_node((yyvsp[-2].node))), (yyvsp[0].node));
                  }
#line 8878 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 609:
#line 3314 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(0), (yyvsp[0].node));
                  }
#line 8886 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 622:
#line 3340 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = '.';
                  }
#line 8894 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 623:
#line 3344 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = tANDDOT;
                  }
#line 8902 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 625:
#line 3351 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = tCOLON2;
                  }
#line 8910 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 635:
#line 3375 "grammar.y" /* yacc.c:1661  */
    {yyerrok;}
#line 8916 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 638:
#line 3380 "grammar.y" /* yacc.c:1661  */
    {yyerrok;}
#line 8922 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 639:
#line 3383 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = 0;}
#line 8928 "grammar.cpp" /* yacc.c:1661  */
    break;


#line 8932 "grammar.cpp" /* yacc.c:1661  */
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
#line 3385 "grammar.y" /* yacc.c:1906  */


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
      case 'p':
        options |= RE_OPTION_PEG;
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
