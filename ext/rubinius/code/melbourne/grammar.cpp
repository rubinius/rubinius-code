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
static NODE *parser_attrset(rb_parser_state*, NODE*, ID);
static void rb_parser_backref_error(rb_parser_state*, NODE*);
static NODE *parser_node_assign(rb_parser_state*, NODE*, NODE*);
static NODE *parser_new_op_assign(rb_parser_state*, NODE*, ID, NODE*);
static NODE *parser_new_attr_op_assign(rb_parser_state*, NODE*, ID, ID, NODE*);
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

void *pt_allocate(rb_parser_state *parser_state, int size) {
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

void pt_free(rb_parser_state *parser_state) {
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
#define new_attr_op_assign(l,a,o,r) parser_new_attr_op_assign(parser_state, l, a, o, r)
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
#define attrset(a, b)             parser_attrset(parser_state, a, b)
#define match_op(a, b)            parser_match_op(parser_state, a, b)
#define new_yield(n)              parser_new_yield(parser_state, n)
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
#define TOK_INTERN(mb)        parser_intern3(tok(), toklen(), parser_state->enc)

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


#line 476 "grammar.cpp" /* yacc.c:339  */

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
    keyword_class = 258,
    keyword_module = 259,
    keyword_def = 260,
    keyword_undef = 261,
    keyword_begin = 262,
    keyword_rescue = 263,
    keyword_ensure = 264,
    keyword_end = 265,
    keyword_if = 266,
    keyword_unless = 267,
    keyword_then = 268,
    keyword_elsif = 269,
    keyword_else = 270,
    keyword_case = 271,
    keyword_when = 272,
    keyword_while = 273,
    keyword_until = 274,
    keyword_for = 275,
    keyword_break = 276,
    keyword_next = 277,
    keyword_redo = 278,
    keyword_retry = 279,
    keyword_in = 280,
    keyword_do = 281,
    keyword_do_cond = 282,
    keyword_do_block = 283,
    keyword_do_LAMBDA = 284,
    keyword_return = 285,
    keyword_yield = 286,
    keyword_super = 287,
    keyword_self = 288,
    keyword_nil = 289,
    keyword_true = 290,
    keyword_false = 291,
    keyword_and = 292,
    keyword_or = 293,
    keyword_not = 294,
    modifier_if = 295,
    modifier_unless = 296,
    modifier_while = 297,
    modifier_until = 298,
    modifier_rescue = 299,
    keyword_alias = 300,
    keyword_defined = 301,
    keyword_BEGIN = 302,
    keyword_END = 303,
    keyword__LINE__ = 304,
    keyword__FILE__ = 305,
    keyword__ENCODING__ = 306,
    tIDENTIFIER = 307,
    tFID = 308,
    tGVAR = 309,
    tIVAR = 310,
    tCONSTANT = 311,
    tCVAR = 312,
    tLABEL = 313,
    tINTEGER = 314,
    tFLOAT = 315,
    tRATIONAL = 316,
    tIMAGINARY = 317,
    tSTRING_CONTENT = 318,
    tCHAR = 319,
    tNTH_REF = 320,
    tBACK_REF = 321,
    tREGEXP_END = 322,
    tUPLUS = 323,
    tUMINUS = 324,
    tPOW = 325,
    tCMP = 326,
    tEQ = 327,
    tEQQ = 328,
    tNEQ = 329,
    tGEQ = 330,
    tLEQ = 331,
    tANDOP = 332,
    tOROP = 333,
    tMATCH = 334,
    tNMATCH = 335,
    tDOT2 = 336,
    tDOT3 = 337,
    tAREF = 338,
    tASET = 339,
    tLSHFT = 340,
    tRSHFT = 341,
    tCOLON2 = 342,
    tCOLON3 = 343,
    tOP_ASGN = 344,
    tASSOC = 345,
    tLPAREN = 346,
    tLPAREN_ARG = 347,
    tRPAREN = 348,
    tLBRACK = 349,
    tLBRACE = 350,
    tLBRACE_ARG = 351,
    tSTAR = 352,
    tDSTAR = 353,
    tAMPER = 354,
    tLAMBDA = 355,
    tSYMBEG = 356,
    tSTRING_BEG = 357,
    tXSTRING_BEG = 358,
    tREGEXP_BEG = 359,
    tWORDS_BEG = 360,
    tQWORDS_BEG = 361,
    tSYMBOLS_BEG = 362,
    tQSYMBOLS_BEG = 363,
    tSTRING_DBEG = 364,
    tSTRING_DEND = 365,
    tSTRING_DVAR = 366,
    tSTRING_END = 367,
    tLAMBEG = 368,
    tLOWEST = 369,
    tUMINUS_NUM = 370,
    tLAST_TOKEN = 371
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 427 "grammar.y" /* yacc.c:355  */

    VALUE val;
    NODE *node;
    ID id;
    int num;
    const struct vtable* vars;

#line 638 "grammar.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (rb_parser_state* parser_state);



/* Copy the second part of user declarations.  */

#line 654 "grammar.cpp" /* yacc.c:358  */

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
#define YYLAST   11154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  201
/* YYNRULES -- Number of rules.  */
#define YYNRULES  624
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1056

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   371

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     143,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   142,   129,     2,     2,     2,   127,   122,     2,
     138,   139,   125,   123,   136,   124,   135,   126,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   117,   141,
     119,   115,   118,   116,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   140,   121,     2,   137,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   132,   120,   133,   130,     2,     2,     2,
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
     128,   131
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   578,   578,   578,   603,   610,   614,   618,   622,   628,
     630,   629,   641,   664,   671,   675,   679,   683,   689,   694,
     693,   703,   703,   707,   711,   718,   723,   727,   732,   737,
     745,   753,   758,   767,   768,   774,   779,   796,   801,   806,
     811,   816,   821,   826,   831,   834,   839,   846,   847,   851,
     855,   859,   863,   866,   874,   875,   878,   879,   886,   885,
     900,   907,   912,   920,   925,   932,   937,   944,   949,   954,
     958,   962,   968,   969,   975,   976,   982,   986,   990,   994,
     998,  1002,  1006,  1010,  1014,  1018,  1024,  1025,  1031,  1035,
    1041,  1045,  1051,  1055,  1059,  1063,  1067,  1071,  1075,  1081,
    1087,  1094,  1099,  1104,  1108,  1112,  1116,  1120,  1126,  1132,
    1139,  1143,  1146,  1150,  1154,  1160,  1161,  1162,  1163,  1168,
    1175,  1176,  1179,  1183,  1186,  1190,  1190,  1196,  1197,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1225,  1228,  1228,  1228,
    1229,  1229,  1230,  1230,  1230,  1231,  1231,  1231,  1231,  1232,
    1232,  1232,  1232,  1233,  1233,  1233,  1234,  1234,  1234,  1234,
    1235,  1235,  1235,  1235,  1236,  1236,  1236,  1236,  1237,  1237,
    1237,  1237,  1238,  1238,  1238,  1238,  1239,  1239,  1242,  1247,
    1253,  1258,  1264,  1285,  1290,  1295,  1300,  1305,  1310,  1315,
    1321,  1327,  1331,  1335,  1339,  1343,  1347,  1351,  1355,  1359,
    1363,  1367,  1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,
    1403,  1407,  1417,  1421,  1425,  1429,  1433,  1437,  1441,  1445,
    1445,  1450,  1456,  1462,  1470,  1471,  1475,  1479,  1485,  1491,
    1492,  1495,  1496,  1497,  1501,  1505,  1511,  1516,  1520,  1525,
    1530,  1533,  1533,  1545,  1551,  1555,  1561,  1565,  1569,  1578,
    1589,  1590,  1593,  1602,  1611,  1617,  1618,  1619,  1620,  1621,
    1622,  1623,  1624,  1625,  1626,  1627,  1632,  1631,  1651,  1651,
    1655,  1655,  1659,  1663,  1667,  1671,  1679,  1683,  1687,  1691,
    1695,  1699,  1699,  1704,  1708,  1712,  1718,  1719,  1726,  1730,
    1738,  1746,  1746,  1746,  1753,  1753,  1753,  1760,  1767,  1772,
    1774,  1771,  1791,  1790,  1807,  1812,  1806,  1829,  1828,  1845,
    1844,  1862,  1863,  1862,  1878,  1882,  1886,  1890,  1896,  1904,
    1910,  1916,  1922,  1928,  1934,  1940,  1946,  1952,  1958,  1965,
    1971,  1972,  1973,  1976,  1977,  1980,  1981,  1990,  1991,  1997,
    1998,  2001,  2005,  2011,  2015,  2021,  2025,  2030,  2035,  2039,
    2043,  2048,  2053,  2057,  2063,  2067,  2071,  2075,  2081,  2086,
    2091,  2095,  2099,  2103,  2107,  2111,  2115,  2119,  2123,  2127,
    2131,  2135,  2139,  2143,  2147,  2153,  2154,  2160,  2165,  2169,
    2176,  2180,  2187,  2192,  2199,  2205,  2211,  2214,  2219,  2211,
    2231,  2235,  2241,  2245,  2252,  2251,  2266,  2277,  2281,  2288,
    2297,  2304,  2303,  2313,  2312,  2321,  2326,  2325,  2335,  2334,
    2343,  2347,  2351,  2363,  2362,  2375,  2374,  2388,  2396,  2397,
    2400,  2412,  2415,  2419,  2423,  2426,  2430,  2433,  2437,  2440,
    2441,  2445,  2448,  2460,  2461,  2462,  2468,  2474,  2496,  2556,
    2560,  2567,  2570,  2576,  2577,  2583,  2587,  2594,  2597,  2605,
    2609,  2615,  2619,  2626,  2629,  2636,  2639,  2650,  2653,  2660,
    2663,  2670,  2673,  2696,  2698,  2697,  2709,  2715,  2720,  2708,
    2736,  2737,  2738,  2739,  2742,  2749,  2750,  2751,  2752,  2755,
    2781,  2782,  2788,  2789,  2790,  2791,  2794,  2795,  2796,  2797,
    2798,  2801,  2802,  2803,  2804,  2805,  2806,  2807,  2810,  2816,
    2824,  2828,  2834,  2835,  2838,  2843,  2842,  2851,  2858,  2864,
    2872,  2876,  2880,  2884,  2890,  2895,  2900,  2904,  2908,  2912,
    2916,  2920,  2924,  2928,  2932,  2936,  2940,  2944,  2948,  2952,
    2957,  2963,  2968,  2973,  2978,  2985,  2986,  2993,  2998,  3008,
    3009,  3017,  3024,  3029,  3036,  3041,  3048,  3052,  3063,  3067,
    3078,  3079,  3082,  3087,  3093,  3101,  3109,  3113,  3124,  3128,
    3139,  3140,  3143,  3151,  3158,  3159,  3162,  3173,  3177,  3183,
    3189,  3189,  3213,  3214,  3220,  3221,  3227,  3231,  3235,  3241,
    3242,  3243,  3246,  3247,  3248,  3249,  3252,  3253,  3254,  3257,
    3258,  3261,  3262,  3265,  3266,  3269,  3272,  3275,  3276,  3277,
    3280,  3281,  3284,  3285,  3288
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "keyword_class", "keyword_module",
  "keyword_def", "keyword_undef", "keyword_begin", "keyword_rescue",
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
  "tRSHFT", "tCOLON2", "tCOLON3", "tOP_ASGN", "tASSOC", "tLPAREN",
  "tLPAREN_ARG", "tRPAREN", "tLBRACK", "tLBRACE", "tLBRACE_ARG", "tSTAR",
  "tDSTAR", "tAMPER", "tLAMBDA", "tSYMBEG", "tSTRING_BEG", "tXSTRING_BEG",
  "tREGEXP_BEG", "tWORDS_BEG", "tQWORDS_BEG", "tSYMBOLS_BEG",
  "tQSYMBOLS_BEG", "tSTRING_DBEG", "tSTRING_DEND", "tSTRING_DVAR",
  "tSTRING_END", "tLAMBEG", "tLOWEST", "'='", "'?'", "':'", "'>'", "'<'",
  "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "tUMINUS_NUM",
  "'!'", "'~'", "tLAST_TOKEN", "'{'", "'}'", "'['", "'.'", "','", "'`'",
  "'('", "')'", "']'", "';'", "' '", "'\\n'", "$accept", "program", "$@1",
  "top_compstmt", "top_stmts", "top_stmt", "$@2", "bodystmt", "compstmt",
  "stmts", "stmt_or_begin", "$@3", "stmt", "$@4", "command_asgn", "expr",
  "expr_value", "command_call", "block_command", "cmd_brace_block", "@5",
  "fcall", "command", "mlhs", "mlhs_inner", "mlhs_basic", "mlhs_item",
  "mlhs_head", "mlhs_post", "mlhs_node", "lhs", "cname", "cpath", "fname",
  "fsym", "fitem", "undef_list", "$@6", "op", "reswords", "arg", "$@7",
  "arg_value", "aref_args", "paren_args", "opt_paren_args",
  "opt_call_args", "call_args", "command_args", "@8", "block_arg",
  "opt_block_arg", "args", "mrhs_arg", "mrhs", "primary", "@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "@19",
  "@20", "@21", "@22", "@23", "$@24", "$@25", "primary_value", "k_begin",
  "k_if", "k_unless", "k_while", "k_until", "k_case", "k_for", "k_class",
  "k_module", "k_def", "k_end", "then", "do", "if_tail", "opt_else",
  "for_var", "f_marg", "f_marg_list", "f_margs", "block_args_tail",
  "opt_block_args_tail", "block_param", "opt_block_param",
  "block_param_def", "opt_bv_decl", "bv_decls", "bvar", "lambda", "@26",
  "@27", "@28", "f_larglist", "lambda_body", "do_block", "@29",
  "block_call", "method_call", "@30", "@31", "@32", "@33", "brace_block",
  "@34", "@35", "case_body", "cases", "opt_rescue", "exc_list", "exc_var",
  "opt_ensure", "literal", "strings", "string", "string1", "xstring",
  "regexp", "words", "word_list", "word", "symbols", "symbol_list",
  "qwords", "qsymbols", "qword_list", "qsym_list", "string_contents",
  "xstring_contents", "regexp_contents", "string_content", "@36", "@37",
  "@38", "@39", "string_dvar", "symbol", "sym", "dsym", "numeric",
  "simple_numeric", "user_variable", "keyword_variable", "var_ref",
  "var_lhs", "backref", "superclass", "$@40", "f_arglist", "args_tail",
  "opt_args_tail", "f_args", "f_bad_arg", "f_norm_arg", "f_arg_item",
  "f_arg", "f_label", "f_kw", "f_block_kw", "f_block_kwarg", "f_kwarg",
  "kwrest_mark", "f_kwrest", "f_opt", "f_block_opt", "f_block_optarg",
  "f_optarg", "restarg_mark", "f_rest_arg", "blkarg_mark", "f_block_arg",
  "opt_f_block_arg", "singleton", "$@41", "assoc_list", "assocs", "assoc",
  "operation", "operation2", "operation3", "dot_or_colon", "opt_terms",
  "opt_nl", "rparen", "rbracket", "trailer", "term", "terms", "none", YY_NULLPTR
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
     365,   366,   367,   368,   369,    61,    63,    58,    62,    60,
     124,    94,    38,    43,    45,    42,    47,    37,   370,    33,
     126,   371,   123,   125,    91,    46,    44,    96,    40,    41,
      93,    59,    32,    10
};
# endif

#define YYPACT_NINF -831

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-831)))

#define YYTABLE_NINF -625

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-625)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -831,   119,  2781,  -831,  7467,  -831,  -831,  -831,  6982,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  7582,  7582,  -831,  -831,
    7582,  4123,  3712,  -831,  -831,  -831,  -831,   277,  6847,    38,
    -831,    57,  -831,  -831,  -831,  3027,  3849,  -831,  -831,  3164,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  8962,  8962,
      78,  5191,  9077,  7927,  8272,  7245,  -831,  6712,  -831,  -831,
    -831,   164,   196,   227,   259,   667,  9192,  8962,  -831,    32,
    -831,   943,  -831,   457,  -831,  -831,    62,   396,   293,  -831,
     291,  9307,  -831,   316,  3006,   228,   395,  -831,  9077,  9077,
    -831,  -831,  6092,  9418,  9529,  9640,  6576,    35,    61,  -831,
    -831,   341,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,    29,    43,  -831,   370,   361,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   330,  -831,
    -831,  -831,  -831,   358,  8962,   444,  5332,  8962,  8962,  8962,
    8962,  -831,   398,  3006,   418,  -831,  -831,   384,   479,    16,
      24,   434,    41,   404,  -831,  -831,  -831,  5977,  -831,  7582,
    7582,  -831,  -831,  6207,  -831,  9077,   764,  -831,   394,   416,
    5473,  -831,  -831,  -831,   422,   424,    62,  -831,   552,   472,
     594,  7697,  -831,  5191,   415,    32,  -831,   943,    38,   441,
    -831,   457,    38,   425,   -20,   -15,  -831,   418,   431,   -15,
    -831,    38,   522,   667,  9751,   451,  -831,   606,   616,   657,
     681,  -831,  -831,  -831,  -831,  -831,  -831,   579,  -831,   583,
     608,   525,   468,   684,   478,    33,   490,   711,   497,    52,
     545,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  6322,  9077,
    9077,  9077,  9077,  7697,  9077,  9077,  -831,  -831,  -831,   521,
    -831,  -831,  -831,  8387,  -831,  5191,  7356,   487,  8387,  8962,
    8962,  8962,  8962,  8962,  8962,  8962,  8962,  8962,  8962,  8962,
    8962,  8962,  8962,  8962,  8962,  8962,  8962,  8962,  8962,  8962,
    8962,  8962,  8962,  8962,  8962, 10034,  7582, 10113,  4538,   457,
      71,    71,  9077,  9077,    32,   607,   488,   577,  -831,  -831,
     697,   615,    81,    87,    99,   369,   393,  9077,   295,  -831,
     110,   702,  -831,  -831,  -831,  -831,    73,   156,   206,   218,
     229,   239,   246,   322,   376,  -831,  -831,  -831,    35,  -831,
    -831, 10192,  -831,  -831,  9192,  9192,  -831,  -831,   207,  -831,
    -831,  -831,  8962,  8962,  7812,  -831,  -831, 10271,  7582, 10350,
    8962,  8962,  8042,  -831,    38,   517,  -831,  -831,    38,  -831,
     526,   529,  -831,   328,  -831,  -831,  -831,  -831,  -831,  6982,
    -831,  8962,  5606,   563, 10271, 10350,  8962,   943,   565,    38,
    -831,  -831,  6437,   562,    38,  -831,  -831,  8157,  -831,  -831,
    8272,  -831,  -831,  -831,   394,   713,  -831,  -831,   566,  9751,
   10429,  7582, 10508,  1097,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,   283,  -831,  -831,   581,
    -831,  -831,  -831,   410,  -831,   591,  -831,  8962,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,    21,    21,  -831,
    -831,    21,  8962,  -831,   599,   627,  -831,  -831,    38,  9751,
     634,  -831,  -831,  -831,   673,  2535,  -831,  -831,   472,  2132,
    2132,  2132,  2132,  1037,  1037,  2629,  1938,  2132,  2132,  3143,
    3143,   555,   555, 11011,  1037,  1037,   922,   922,   755,   432,
     432,   472,   472,   472,  4260,  3301,  4397,  3438,   424,   670,
    -831,    38,   643,  -831,   666,  -831,   424,  3986,   795,   804,
    -831,  4679,   808,  4961,   132,   132,   607,  8502,   795,   118,
   10587,  7582, 10666,  -831,   457,  -831,   713,  -831,    32,  -831,
    -831,  -831, 10745,  7582, 10192,  4538,  9077,  1186,  -831,  -831,
    -831,  2329,  -831,  2005,  -831,  3006,  6982,  2869,  -831,  8962,
     418,  -831,   404,  2890,  3575,    38,   240,   241,  -831,  -831,
    -831,  -831,  7812,  8042,  -831,  -831,  9077,  3006,   691,  -831,
    -831,  -831,  3006,  5606,    36,  -831,  -831,   -15,  9751,   566,
     412,   288,    38,   303,   319,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,   925,  -831,  -831,  -831,  -831,  -831,  1398,  -831,
    -831,  -831,  -831,   718,  -831,   690,  8962,  -831,   706,   792,
     710,  -831,   714,   801,   723,   809,  -831,  -831,   540,  -831,
    -831,  -831,  -831,  -831,   472,  -831,   972,  5747,  -831,  -831,
    5473,    21,  5747,   729,  8617,  -831,   566,  9751,  9192,  8962,
     750,  9192,  9192,  -831,   521,   424,   734,   698,  9192,  9192,
    -831,   521,   424,  -831,  -831,  8732,   854,  -831,   245,  -831,
     854,  -831,  -831,  -831,  -831,   795,    70,  -831,   185,   222,
      38,   127,   149,  9077,    32,  -831,  9077,  4538,   412,   288,
    -831,    38,   795,   328,  1398,  4538,    32,  7117,  -831,    61,
     396,  -831,  8962,  -831,  -831,  -831,  8962,  8962,   242,  8962,
    8962,   739,   328,  -831,   743,  -831,  -831,   380,   925,   482,
    -831,   749,    38,  -831,    38,    63,  8962,  1398,  -831,  -831,
     505,  -831,  -831,  -831,   180,  -831,  1398,  -831,  -831,   800,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,    38,
     767,   774,   754,  9862,  -831,   759,   710,  -831,   768,   769,
    -831,   762,   890,   773,  5473,   898,  8962,   778,   566,  3006,
    8962,  -831,  3006,  -831,  3006,  -831,  -831,  -831,  9192,  -831,
    3006,  -831,  3006,  -831,  -831,   599,  -831,   825,  -831,  5076,
     908,  -831,  9077,   795,  -831,   795,  5747,  5747,  -831,  8847,
    4820,   243,   132,  -831,    32,   795,  -831,  -831,  -831,    38,
     795,  -831,  -831,  -831,  -831,  3006,  8962,  8042,  -831,  -831,
      38,   918,   783,  1075,  -831,   784,  5747,  5473,  -831,  -831,
    -831,  -831,   789,   790,  -831,   710,  -831,   796,  -831,   799,
    -831,   796,  5862,   818,  -831,  9862,  1398,  -831,   884,   758,
     505,  -831,  -831,  1398,  -831,   800,  -831,   433,  -831,  -831,
     816,  -831,   817,  3006,  -831,  3006,  9973,    71,  -831,  -831,
    5747,  -831,  -831,    71,  -831,  -831,   795,   795,  -831,   534,
    -831,  4538,  -831,  -831,  -831,  -831,  1186,  -831,   819,   918,
     620,  -831,  -831,   942,   821,  1398,  -831,   800,  -831,  -831,
     800,  -831,   800,  -831,  -831,   847,  -831,   758,  -831,   823,
     824,  -831, 10824,  -831,   710,   827,  -831,   828,   827,  -831,
     831,  -831,  -831,  -831,   912,  -831,   777,   616,   657,   681,
    4538,  -831,  4679,  -831,  -831,  -831,  -831,  -831,  5747,   795,
    4538,   918,   819,   918,   840,  -831,  -831,   796,   842,   796,
     796,  -831,  1398,  -831,   800,  -831,   850,   859,  -831,   800,
    -831,   800,  -831,  -831,   433,   713, 10903,  7582, 10982,   804,
     245,   795,  -831,   795,   819,   918,  -831,   800,  -831,  -831,
    -831,   827,   862,   827,   827,  -831,    54,   288,    38,    89,
     107,  -831,  -831,  -831,  -831,   819,   796,  -831,   800,  -831,
    -831,  -831,   123,  -831,   827,  -831
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,   346,   347,   348,     0,   339,
     340,   341,   344,   342,   343,   345,   334,   335,   336,   337,
     297,   261,   261,   512,   511,   513,   514,   613,     0,   613,
      10,     0,   516,   515,   517,   599,   601,   508,   507,   600,
     510,   502,   503,   504,   505,   453,   522,   523,     0,     0,
       0,     0,   288,   624,   624,    84,   406,   479,   477,   479,
     481,   461,   473,   467,   475,     0,     0,     0,     3,   611,
       6,     9,    33,    44,    47,    55,   261,    54,     0,    72,
       0,    76,    86,     0,    52,   242,     0,   286,     0,     0,
     311,   314,   611,     0,     0,     0,     0,    56,   306,   275,
     276,   452,   454,   277,   278,   279,   281,   280,   282,   450,
     451,   449,   500,   518,   519,   283,     0,   284,    60,     5,
       8,   167,   178,   168,   191,   164,   184,   174,   173,   194,
     195,   189,   172,   171,   166,   192,   196,   197,   176,   165,
     179,   183,   185,   177,   170,   186,   193,   188,   187,   180,
     190,   175,   163,   182,   181,   162,   169,   160,   161,   157,
     158,   159,   115,   117,   116,   152,   153,   148,   130,   131,
     132,   139,   136,   138,   133,   134,   154,   155,   140,   141,
     145,   149,   135,   137,   127,   128,   129,   142,   143,   144,
     146,   147,   150,   151,   156,   120,   122,   124,    26,   118,
     119,   121,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,   243,   266,    70,   260,   624,     0,   518,
     519,     0,   284,   624,   594,    71,    69,   613,    68,     0,
     624,   430,    67,   613,   614,     0,     0,    21,   239,     0,
       0,   334,   335,   297,   300,   431,     0,   218,     0,   219,
     294,     0,    19,     0,     0,   611,    15,    18,   613,    74,
      14,   290,   613,     0,   617,   617,   244,     0,     0,   617,
     592,   613,     0,     0,     0,    82,   338,     0,    92,    93,
     100,   308,   407,   497,   496,   498,   495,     0,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,    51,   233,   234,   620,   621,     4,   622,   612,     0,
       0,     0,     0,     0,     0,     0,   435,   433,   420,    61,
     305,   414,   416,     0,    88,     0,    80,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   428,   624,   426,     0,    53,
       0,     0,     0,     0,   611,     0,   612,     0,   360,   359,
       0,     0,   518,   519,   284,   110,   111,     0,     0,   113,
       0,     0,   518,   519,   284,   327,   187,   180,   190,   175,
     157,   158,   159,   115,   116,   590,   329,   589,     0,   610,
     609,     0,   307,   455,     0,     0,   125,   597,   294,   267,
     598,   263,     0,     0,     0,   257,   265,   428,   624,   426,
       0,     0,     0,   258,   613,     0,   299,   262,   613,   252,
     624,   624,   251,   613,   304,    50,    23,    25,    24,     0,
     301,     0,     0,     0,   428,   426,     0,    17,     0,   613,
     292,    13,   612,    73,   613,   289,   295,   619,   618,   245,
     619,   247,   296,   593,     0,    99,   501,    90,    85,     0,
     428,   624,   426,   550,   483,   486,   484,   499,   480,   456,
     478,   457,   458,   482,   459,   460,     0,   463,   469,     0,
     470,   465,   466,     0,   471,     0,   472,     0,   623,     7,
      27,    28,    29,    30,    31,    48,    49,   624,   624,    58,
      62,   624,     0,    34,   271,     0,    43,   270,   613,     0,
      78,    89,    46,    45,     0,   198,   266,    42,   216,   223,
     228,   229,   230,   225,   227,   237,   238,   231,   232,   209,
     210,   235,   236,   613,   224,   226,   220,   221,   222,   211,
     212,   213,   214,   215,   602,   604,   603,   605,     0,   261,
     425,   613,   602,   604,   603,   605,     0,   261,     0,   624,
     351,     0,   350,     0,     0,     0,     0,     0,     0,   294,
     428,   624,   426,   319,   324,   110,   111,   112,     0,   525,
     322,   524,   428,   624,   426,     0,     0,   550,   331,   602,
     603,   261,    35,   200,    41,   208,     0,   198,   596,     0,
     268,   264,   624,   602,   603,   613,   602,   603,   595,   298,
     615,   248,   253,   255,   303,    22,     0,   240,     0,    32,
     423,   421,   207,     0,    75,    16,   291,   617,     0,    83,
      96,    98,   613,   602,   603,   556,   553,   552,   551,   554,
     561,   570,     0,   581,   571,   585,   584,   580,   550,   408,
     549,   411,   555,   557,   559,   535,   563,   568,   624,   573,
     624,   578,   535,   583,   535,     0,   533,   487,     0,   462,
     464,   474,   468,   476,   217,   398,   613,     0,   396,   395,
       0,   624,     0,   274,     0,    87,    81,     0,     0,     0,
       0,     0,     0,   429,    65,     0,     0,   432,     0,     0,
     427,    63,   624,   349,   287,   624,   624,   441,   624,   352,
     624,   354,   312,   353,   315,     0,     0,   318,   606,   293,
     613,   602,   603,     0,     0,   527,     0,     0,   110,   111,
     114,   613,     0,   613,   550,     0,     0,     0,   250,   417,
      57,   249,     0,   126,   269,   259,     0,     0,   432,     0,
       0,   624,   613,    11,     0,   246,    91,    94,     0,   372,
     363,   365,   613,   361,   613,     0,     0,     0,   542,   562,
       0,   531,   588,   572,     0,   532,     0,   545,   582,     0,
     547,   586,   488,   490,   491,   492,   485,   493,   394,   613,
       0,   557,   379,   565,   566,   624,   624,   576,   379,   379,
     377,   400,     0,     0,     0,     0,     0,   272,    79,   199,
       0,    40,   205,    39,   206,    66,   424,   616,     0,    37,
     203,    38,   204,    64,   422,   442,   443,   624,   444,     0,
     624,   357,     0,     0,   355,     0,     0,     0,   317,     0,
       0,   432,     0,   325,     0,     0,   432,   328,   591,   613,
       0,   529,   332,   418,   419,   201,     0,   254,   302,    20,
     613,     0,   370,     0,   558,     0,     0,     0,   409,   574,
     534,   560,   535,   535,   569,   624,   587,   535,   579,   535,
     557,   535,     0,     0,   397,     0,   385,   387,     0,   564,
       0,   375,   376,     0,   390,     0,   392,     0,   436,   434,
       0,   415,   273,   241,    36,   202,     0,     0,   446,   358,
       0,    12,   448,     0,   309,   310,     0,     0,   268,   624,
     320,     0,   526,   323,   528,   330,   550,   362,   373,     0,
     368,   364,   410,     0,     0,     0,   538,     0,   540,   530,
       0,   546,     0,   543,   548,     0,   399,   575,   378,   379,
     379,   294,   428,   567,   624,   379,   577,   379,   379,   404,
     401,   402,   405,    59,     0,   445,     0,   101,   102,   109,
       0,   447,     0,   313,   316,   438,   439,   437,     0,     0,
       0,     0,   371,     0,   366,   413,   412,   535,   535,   535,
     535,   489,     0,   382,     0,   384,   606,   293,   374,     0,
     391,     0,   388,   393,     0,   108,   428,   624,   426,   624,
     624,     0,   326,     0,   369,     0,   539,     0,   536,   541,
     544,   379,   379,   379,   379,   403,   606,   107,   613,   602,
     603,   440,   356,   321,   333,   367,   535,   383,     0,   380,
     386,   389,   432,   537,   379,   381
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -831,  -831,  -831,  -389,  -831,    34,  -831,  -555,   -49,  -831,
     573,  -831,    11,  -831,  -308,   -28,   -85,    44,  -831,  -313,
    -831,   633,   -11,   911,  -139,    -7,   -65,  -831,  -426,    -9,
    1708,  -331,   919,   -46,  -831,    -6,  -831,  -831,     2,  -831,
    1072,  -831,   939,  -831,   -48,   320,  -344,    65,    10,  -831,
    -383,  -200,     9,  -831,  -301,    14,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,    74,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,   176,  -316,  -540,    15,  -662,  -831,
    -808,  -792,   265,   348,   -31,  -831,  -436,  -831,  -406,  -831,
      25,  -831,  -831,  -831,  -831,  -831,  -831,   290,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,   -90,  -831,  -831,  -559,  -831,
      22,  -831,  -831,  -831,  -831,  -831,  -831,   949,  -831,  -831,
    -831,  -831,   746,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
     993,  -831,  -143,  -831,  -831,  -831,  -831,  -831,     6,  -831,
      13,  -831,   -17,  1294,  1501,   962,  1790,  1583,  -831,  -831,
     125,  -455,  -261,  -424,  -830,   313,  -709,   108,  -242,   279,
     165,  -831,  -831,  -831,  -428,  -723,  -800,   170,   296,  -831,
    -606,  -831,  -631,  -628,  -831,  -831,  -831,    84,  -403,  -831,
    -284,  -831,   669,   -56,   -26,    37,  -545,  -232,    -3,   -13,
      -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    68,    69,    70,   239,   568,   569,   255,
     256,   448,   257,   439,    72,    73,   360,    74,    75,   510,
     691,   246,    77,    78,   258,    79,    80,    81,   468,    82,
     212,   379,   380,   195,   196,   197,   198,   606,   557,   200,
      84,   441,   214,   263,   231,   749,   428,   429,   228,   229,
     216,   415,   430,   516,   517,    85,   358,   262,   454,   626,
     362,   846,   363,   847,   733,   988,   737,   734,   931,   595,
     597,   747,   936,   248,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   714,   571,   722,   843,   844,   371,
     770,   771,   772,   958,   897,   799,   687,   688,   800,   970,
     971,   281,   282,   473,   775,   659,   878,   322,   511,    97,
      98,   712,   705,   566,   558,   320,   508,   507,   578,   987,
     716,   837,   917,   921,    99,   100,   101,   102,   103,   104,
     105,   293,   486,   106,   297,   107,   108,   295,   299,   289,
     287,   291,   478,   678,   677,   792,   892,   796,   109,   288,
     110,   111,   112,   219,   220,   115,   221,   222,   590,   736,
     745,   880,   778,   746,   662,   890,   664,   665,   666,   667,
     804,   805,   668,   669,   670,   671,   807,   808,   672,   673,
     674,   675,   676,   781,   398,   596,   268,   431,   224,   118,
     630,   560,   401,   306,   425,   426,   707,   459,   572,   366,
     260
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     119,   235,   254,   238,   361,   211,   211,   364,   402,   211,
     199,   286,   561,    71,   201,    71,   327,   725,   660,   618,
     522,   202,   237,   423,   261,   217,   217,   527,   318,   217,
     199,   611,   232,   461,   201,   724,   365,   463,   120,   611,
     742,   202,   785,   639,   259,   573,   275,   587,   300,   661,
     396,   266,   270,   628,   840,   810,   308,   618,   845,   199,
     359,   359,   264,   888,   359,   941,   307,  -105,   881,   276,
     758,   559,   690,   567,   615,   692,    86,   972,    86,   938,
     809,   215,   225,   570,   570,   226,   319,   316,   316,   307,
     218,   218,   876,   696,   218,   276,   489,   767,   199,   685,
     223,   223,  -104,   966,   223,  -520,  -101,   276,   276,   276,
     301,   588,  -102,  -521,   449,   495,   457,   601,  -520,     3,
    -106,   460,   399,   458,  -109,    86,   218,   642,   458,   277,
     421,  -101,  -521,   559,   250,   567,  -103,   265,   269,  -102,
     218,   686,   660,  -108,  -101,   490,   480,   992,   483,   886,
     487,   -73,  -104,   886,   487,   277,  -109,   254,  -102,   721,
    -512,   631,   218,   218,   496,   -92,   218,   370,   381,   381,
     400,   883,   -87,   304,  -106,   305,   877,   901,   902,   -93,
     889,   234,   855,   941,   972,   851,   518,   881,   631,   240,
     860,   443,  -602,   317,   317,  -105,   856,  -105,   318,   451,
     230,  1024,   966,   660,   254,   433,   849,   435,  -512,   467,
    -105,   304,   304,   305,   305,   416,   211,   -92,   211,   211,
     618,   416,   888,   -93,   500,   501,   502,   503,   432,   589,
    -104,   423,  -104,  1045,   774,  -100,   217,   730,   217,   611,
     611,   881,   452,  -511,   764,   464,   259,  -107,  -106,   741,
    -106,   304,   307,   305,   -99,   814,   466,   949,   806,   842,
     839,   740,   447,   -95,  -103,   810,  -103,   985,  -103,   886,
     434,   818,   810,   304,   810,   305,   254,   574,   575,   655,
      86,   359,   359,   359,   359,   -97,   505,   506,   276,   660,
     960,  -511,   424,  -513,   427,   453,   446,   967,   631,   455,
     881,   218,   656,   218,   218,  -514,   292,   218,   576,   218,
     631,   223,   930,   223,    86,  -338,  -516,   520,   259,    71,
     859,   -96,  -108,  -602,   504,    86,  -515,    86,   -95,   759,
     760,   866,   515,  -517,   359,   359,  1008,   515,   294,   998,
     276,  -513,   499,   680,   -97,   211,   474,   585,   277,   584,
     680,   586,   885,  -514,   432,  -104,  -106,  -103,   -98,   565,
    -603,   307,  -338,  -338,  -516,   314,   315,   513,   875,   296,
     986,   810,   523,   810,  -515,  -293,   989,   591,   810,   -94,
     810,  -517,    86,   218,   218,   218,   218,    86,   218,   218,
     522,   825,   475,   893,   476,  -599,  1032,   218,   833,    86,
     277,   298,   218,   565,   467,   765,  -432,   211,   323,  -506,
     850,   787,   755,   790,   836,   233,   432,   810,   -95,  -600,
     234,   565,  -293,  -293,   321,   679,  -603,   324,   416,   416,
     218,   328,    86,   625,   -97,  1023,   218,   218,  -606,   -95,
     119,   199,   -95,    58,   803,   201,   -95,   565,   602,   604,
     405,   218,   202,    71,   467,   -97,  -506,  -506,   -97,   404,
     211,   619,   -97,  -509,   618,   621,   406,  -432,   806,   432,
     624,   234,   964,   474,   565,   806,  -109,   806,   218,   218,
    -509,   660,   355,   276,   611,   969,   634,   646,   647,   648,
     649,   636,   218,  1052,   314,   315,   233,  -100,   612,  -606,
     408,  -599,   329,  -506,  -506,   689,   689,  -599,   413,   689,
     703,  -509,  -432,   412,  -432,  -432,    86,   700,   710,   475,
     414,   476,   718,   420,   720,  -600,    86,  -509,  -509,   356,
     357,  -600,   440,   276,   645,   706,   646,   647,   648,   649,
     422,   637,   329,   277,  -606,   218,  -606,  -606,   442,   839,
    -602,   577,   682,   748,   450,   695,   -72,   352,   353,   354,
     227,   755,   230,   650,   462,   456,   417,   717,   743,   704,
     211,   723,   723,   766,   806,   651,   806,   711,   465,   432,
     484,   806,   211,   806,   565,   735,   726,   469,   474,   706,
     488,   432,   482,   277,   793,   794,   565,   795,   762,   751,
     753,   980,   491,   654,   655,    46,    47,   982,   199,   494,
     416,   750,   201,   418,   419,   497,   706,   509,   871,   202,
     806,   946,   948,   521,   577,   329,   951,   656,   953,   498,
     954,   119,   467,   579,   475,    76,   476,    76,   812,   444,
     583,   813,   474,   815,    71,    86,   474,    86,   852,    76,
      76,   854,   276,    76,   803,   218,   620,   826,   803,   863,
     811,   803,   622,   803,   748,   623,   782,   218,   782,    86,
     218,   474,   645,  1038,   646,   647,   648,   649,   350,   351,
     352,   353,   354,   446,    76,    76,   418,   445,   475,   689,
     476,   477,   475,   470,   476,   479,   629,   633,   -87,    76,
     218,   862,   638,  -518,   706,   359,   761,    86,   359,  -108,
     751,   276,   277,   838,   841,   706,   841,   475,   841,   476,
     481,    76,    76,   681,   515,    76,    41,    42,    43,    44,
     -99,   853,   708,   683,   631,  -266,  1026,  1028,  1029,  1030,
     471,   472,   523,   861,  -519,   821,   823,   474,   811,   199,
    -518,  -518,   829,   831,   727,   709,   993,   923,  -104,   416,
     803,    86,   803,   694,    86,   910,    86,   803,  -284,   803,
     697,   277,   218,   811,   474,   218,   218,   904,   906,   -95,
     858,  -106,   218,   218,   580,  1053,   663,   828,   698,   592,
     919,  -519,  -519,   475,   802,   476,   485,   926,   927,   868,
    -294,   929,   -97,   782,   782,   713,   803,   218,  -423,   874,
     218,    86,   715,  -103,   359,  -284,  -284,   276,   436,    86,
     475,   719,   476,   492,   763,   329,   777,   943,   944,   437,
     438,   581,   582,   776,   -94,   918,   593,   594,   922,    76,
     342,   343,   780,   955,   783,   962,   784,  -294,  -294,   723,
     786,   932,   645,   788,   646,   647,   648,   649,   650,   789,
      76,   791,    76,    76,  1016,  -267,    76,   820,    76,   839,
     651,   981,   914,    76,   827,   867,   869,   899,   350,   351,
     352,   353,   354,   782,    76,   873,    76,   894,    86,   895,
     896,   652,   593,   594,   887,   900,   934,   891,   654,   655,
     908,   848,   218,   907,   903,   905,   909,   937,   911,   276,
     663,  1017,  1018,    86,  -268,   916,   218,   920,   857,   939,
      86,    86,   656,   942,    86,   945,   947,   841,  1003,  1005,
     276,  1019,   950,  1020,  1010,   952,  1012,  1013,   956,  1021,
     961,    76,    76,    76,    76,    76,    76,    76,    76,   973,
      86,    86,   995,  -269,   996,   991,    76,  1001,    76,  1002,
    1004,    76,   782,  1009,  1011,   773,    86,  1014,  1015,   957,
     645,   663,   646,   647,   648,   649,  1025,   645,  1027,   646,
     647,   648,   649,   309,   310,   311,   312,   313,  -602,    76,
     976,    76,   329,   267,    86,    76,    76,  -603,  1048,   801,
    1047,  1049,  1050,  1051,   368,    86,   211,   342,   343,   768,
      76,   965,   706,   968,   385,   432,   768,   717,   841,   924,
     565,   925,   769,  1055,   645,   635,   646,   647,   648,   649,
     650,   933,   834,   870,   798,  1042,   935,    76,    76,  1035,
     864,  1041,   651,   493,   349,   350,   351,   352,   353,   354,
     403,    76,   290,   997,    86,   999,    86,   663,   397,   884,
    1000,   990,    86,   652,    86,   963,   959,   598,     0,   653,
     654,   655,     0,   882,     0,    76,     0,     0,     0,     0,
       0,   773,   872,     0,     0,    76,     0,     0,   213,   213,
     663,   218,   213,     0,   656,     0,     0,   657,     0,   663,
       0,     0,   983,   984,    76,     0,     0,   329,     0,     0,
    1031,     0,  1033,     0,     0,   234,     0,     0,     0,  1034,
     247,   249,   342,   343,     0,   213,   213,   645,     0,   646,
     647,   648,   649,     0,     0,  1046,     0,     0,   302,   303,
       0,     0,     0,   407,     0,     0,   409,   410,   411,   645,
       0,   646,   647,   648,   649,   650,  1054,   347,   348,   349,
     350,   351,   352,   353,   354,  1022,   768,   651,     0,     0,
       0,     0,   940,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   773,     0,   773,     0,   652,     0,
       0,     0,     0,     0,   653,   654,   655,  1043,     0,  1044,
       0,     0,     0,     0,    76,     0,    76,     0,     0,   801,
       0,     0,     0,     0,    76,     0,   801,     0,     0,   656,
       0,     0,   657,     0,     0,     0,    76,     0,    76,    76,
       0,     0,     0,     0,     0,   658,     0,     0,   645,     0,
     646,   647,   648,   649,   650,     0,     0,     0,     0,   663,
       0,     0,   773,   994,     0,     0,   651,     0,   663,    76,
       0,     0,   514,     0,     0,     0,    76,   526,     0,     0,
       0,     0,     0,     0,     0,     0,   213,   652,     0,   213,
     213,   213,   302,   653,   654,   655,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   113,   213,
       0,   213,   213,     0,   773,     0,   773,     0,   656,     0,
       0,   657,     0,     0,     0,   801,     0,     0,     0,     0,
      76,     0,     0,    76,   744,    76,     0,     0,     0,     0,
       0,    76,     0,     0,    76,    76,     0,     0,   773,     0,
       0,    76,    76,     0,     0,   113,     0,     0,     0,   278,
       0,     0,   608,   610,     0,     0,     0,     0,     0,     0,
       0,   267,     0,     0,     0,     0,    76,     0,     0,    76,
      76,     0,     0,     0,     0,   278,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,   372,   382,   382,
     382,     0,     0,     0,     0,   213,   610,     0,     0,   267,
     525,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
     645,   693,   646,   647,   648,   649,   650,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,     0,   651,     0,
       0,     0,    76,     0,     0,    76,   603,   605,     0,    76,
      76,     0,     0,    76,   607,   213,   213,     0,     0,   652,
     213,     0,   603,   605,   213,   653,   654,   655,     0,     0,
     113,     0,     0,   114,     0,   114,     0,     0,     0,    76,
      76,     0,     0,   627,     0,     0,   526,     0,   632,     0,
     656,     0,     0,   657,     0,    76,     0,     0,     0,   213,
       0,     0,   213,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,   113,     0,   113,   754,     0,
       0,     0,   114,    76,     0,     0,   279,     0,     0,     0,
       0,   610,   267,     0,    76,     0,     0,     0,   278,   684,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,   213,   117,     0,   117,     0,     0,
       0,     0,     0,     0,   373,   383,   383,   383,     0,     0,
       0,     0,   113,     0,     0,   779,     0,   113,     0,     0,
       0,     0,     0,    76,     0,    76,     0,     0,     0,   113,
     278,    76,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   817,   117,     0,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
      76,     0,   113,   213,   835,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   374,   384,   384,     0,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
      83,     0,    83,     0,     0,   879,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   213,     0,
       0,   114,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,   114,     0,   114,   912,     0,     0,     0,    83,
       0,     0,     0,   278,     0,     0,   213,     0,     0,     0,
     607,   819,     0,   822,   824,   279,     0,     0,     0,     0,
     830,   832,     0,     0,     0,     0,     0,   213,   928,   117,
       0,     0,   116,     0,   116,     0,     0,     0,     0,     0,
       0,   369,     0,     0,     0,     0,   267,     0,     0,   114,
       0,     0,     0,   278,   114,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   865,     0,   114,   279,   822,   824,
       0,   830,   832,     0,   117,     0,   117,     0,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,   114,
       0,     0,     0,     0,     0,   113,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   113,
       0,   117,   913,     0,     0,     0,   117,     0,     0,     0,
     915,     0,     0,     0,     0,     0,     0,     0,   117,   280,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,   278,     0,     0,     0,     0,     0,   915,   213,
       0,   117,     0,   114,     0,     0,     0,     0,    83,     0,
       0,     0,     0,   114,     0,     0,     0,     0,     0,    83,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,   113,     0,   113,     0,     0,     0,
       0,   278,     0,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,   330,
     331,   332,   333,   334,   335,   336,    83,   338,   339,     0,
     279,    83,     0,   342,   343,   117,     0,     0,     0,     0,
     116,   113,     0,    83,     0,   117,   524,     0,     0,   113,
       0,   116,     0,   116,     0,     0,     0,     0,     0,   752,
       0,     0,   280,     0,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,    83,     0,     0,     0,
       0,     0,   114,     0,   114,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,   213,
     342,   343,     0,     0,     0,     0,   114,   382,   116,     0,
       0,     0,   280,   116,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,     0,
       0,   344,     0,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   113,   114,     0,     0,     0,     0,   279,
     113,   113,     0,     0,   113,     0,     0,     0,   116,     0,
      83,     0,     0,     0,   117,     0,   117,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   113,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   382,
       0,   114,     0,   114,     0,     0,     0,     0,   279,     0,
       0,     0,   329,  -625,  -625,  -625,  -625,   334,   335,     0,
     977,  -625,  -625,     0,   113,     0,   117,   342,   343,     0,
       0,   280,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,     0,     0,   114,     0,
       0,     0,   116,     0,     0,     0,   114,     0,     0,     0,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,   797,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,   117,   113,   117,   113,     0,     0,    83,
     280,    83,   113,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,   117,  -624,
       0,     0,     0,     0,     0,     0,     0,  -624,  -624,  -624,
     114,    83,  -624,  -624,  -624,     0,  -624,   114,   114,     0,
       0,   114,     0,     0,     0,  -624,  -624,     0,     0,     0,
       0,   116,     0,   116,     0,     0,  -624,  -624,     0,  -624,
    -624,  -624,  -624,  -624,     0,     0,     0,   114,   114,     0,
       0,     0,     0,     0,     0,   116,   384,     0,     0,     0,
       0,     0,     0,   114,     0,    83,   383,   117,    83,     0,
      83,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -624,   978,     0,     0,
       0,   114,   117,   116,     0,     0,     0,     0,     0,   117,
     117,     0,   114,   117,     0,     0,     0,     0,     0,  -624,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,   117,
     117,  -624,  -624,     0,  -624,     0,     0,   230,  -624,     0,
    -624,     0,  -624,     0,     0,   117,     0,   116,   384,     0,
     116,   114,   116,   114,     0,     0,     0,     0,     0,   114,
       0,   114,     0,     0,     0,     0,     0,     0,     0,   979,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,    83,    83,     0,     0,    83,     0,
       0,     0,     0,   117,     0,   117,     0,     0,     0,     0,
       0,   117,     0,   117,     0,     0,     0,     0,     0,   699,
       0,     0,     0,     0,    83,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,   116,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,     0,
     342,   343,     0,     0,   975,     0,     0,     0,    83,   116,
       0,     0,     0,     0,     0,     0,   116,   116,     0,    83,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   344,     0,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,   116,   116,     0,     0,
       0,  -243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,     0,     0,    83,     0,
      83,     0,     0,     0,     0,     0,    83,     0,    83,   329,
     330,   331,   332,   333,   334,   335,     0,     0,   338,   339,
     116,     0,     0,     0,   342,   343,     0,     0,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,   116,     0,     0,     0,     0,     0,   116,     0,
     116,  -624,     4,     0,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    -606,     0,     0,     0,     0,     0,     0,     0,  -606,  -606,
    -606,     0,     0,  -606,  -606,  -606,     0,  -606,     0,    65,
      66,    67,     0,   699,     0,     0,  -606,  -606,  -606,  -606,
       0,     0,  -624,     0,  -624,     0,     0,  -606,  -606,     0,
    -606,  -606,  -606,  -606,  -606,     0,     0,     0,     0,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,     0,     0,   342,   343,     0,     0,     0,     0,
    -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,
    -606,  -606,  -606,     0,     0,  -606,  -606,  -606,     0,   756,
    -606,     0,     0,     0,     0,   344,  -606,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
    -606,     0,     0,  -606,     0,  -105,  -606,  -606,  -606,  -606,
    -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,     0,     0,
       0,     0,  -606,  -606,  -606,  -606,  -606,  -506,     0,  -606,
    -606,  -606,     0,  -606,     0,  -506,  -506,  -506,     0,     0,
    -506,  -506,  -506,     0,  -506,     0,     0,     0,     0,     0,
       0,     0,  -506,     0,  -506,  -506,  -506,     0,     0,     0,
       0,     0,     0,     0,  -506,  -506,     0,  -506,  -506,  -506,
    -506,  -506,     0,     0,     0,     0,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
       0,   342,   343,     0,     0,     0,     0,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
       0,     0,  -506,  -506,  -506,     0,  -506,  -506,     0,     0,
       0,     0,   344,  -506,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,  -506,     0,     0,
    -506,     0,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,     0,     0,     0,     0,     0,
    -506,  -506,  -506,  -506,  -509,     0,  -506,  -506,  -506,     0,
    -506,     0,  -509,  -509,  -509,     0,     0,  -509,  -509,  -509,
       0,  -509,     0,     0,     0,     0,     0,     0,     0,  -509,
       0,  -509,  -509,  -509,     0,     0,     0,     0,     0,     0,
       0,  -509,  -509,     0,  -509,  -509,  -509,  -509,  -509,     0,
       0,     0,     0,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,  -625,  -625,     0,     0,   342,   343,
       0,     0,     0,     0,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,     0,     0,  -509,
    -509,  -509,     0,  -509,  -509,     0,     0,     0,     0,     0,
    -509,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,  -509,     0,     0,  -509,     0,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,     0,     0,     0,     0,     0,  -509,  -509,  -509,
    -509,  -607,     0,  -509,  -509,  -509,     0,  -509,     0,  -607,
    -607,  -607,     0,     0,  -607,  -607,  -607,     0,  -607,     0,
       0,     0,     0,     0,     0,     0,     0,  -607,  -607,  -607,
    -607,     0,     0,     0,     0,     0,     0,     0,  -607,  -607,
       0,  -607,  -607,  -607,  -607,  -607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,     0,     0,  -607,  -607,  -607,     0,
       0,  -607,     0,     0,     0,     0,     0,  -607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -607,     0,     0,  -607,     0,     0,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,     0,
       0,     0,     0,  -607,  -607,  -607,  -607,  -607,  -608,     0,
    -607,  -607,  -607,     0,  -607,     0,  -608,  -608,  -608,     0,
       0,  -608,  -608,  -608,     0,  -608,     0,     0,     0,     0,
       0,     0,     0,     0,  -608,  -608,  -608,  -608,     0,     0,
       0,     0,     0,     0,     0,  -608,  -608,     0,  -608,  -608,
    -608,  -608,  -608,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,     0,     0,  -608,  -608,  -608,     0,     0,  -608,     0,
       0,     0,     0,     0,  -608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -608,     0,
       0,  -608,     0,     0,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,     0,     0,     0,     0,
    -608,  -608,  -608,  -608,  -608,  -293,     0,  -608,  -608,  -608,
       0,  -608,     0,  -293,  -293,  -293,     0,     0,  -293,  -293,
    -293,     0,  -293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -293,  -293,  -293,     0,     0,     0,     0,     0,
       0,     0,  -293,  -293,     0,  -293,  -293,  -293,  -293,  -293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,     0,     0,
    -293,  -293,  -293,     0,   757,  -293,     0,     0,     0,     0,
       0,  -293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -293,     0,     0,  -293,     0,
    -107,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,     0,     0,     0,     0,     0,  -293,  -293,
    -293,  -293,  -431,     0,  -293,  -293,  -293,     0,  -293,     0,
    -431,  -431,  -431,     0,     0,  -431,  -431,  -431,     0,  -431,
       0,     0,     0,     0,     0,     0,     0,     0,  -431,  -431,
    -431,     0,     0,     0,     0,     0,     0,     0,     0,  -431,
    -431,     0,  -431,  -431,  -431,  -431,  -431,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,     0,     0,  -431,  -431,  -431,
       0,     0,  -431,     0,     0,     0,     0,     0,  -431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -431,     0,     0,     0,     0,     0,  -431,     0,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
       0,     0,     0,     0,  -431,  -431,  -431,  -431,  -431,  -285,
     230,  -431,  -431,  -431,     0,  -431,     0,  -285,  -285,  -285,
       0,     0,  -285,  -285,  -285,     0,  -285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -285,  -285,  -285,     0,
       0,     0,     0,     0,     0,     0,  -285,  -285,     0,  -285,
    -285,  -285,  -285,  -285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,     0,     0,  -285,  -285,  -285,     0,     0,  -285,
       0,     0,     0,     0,     0,  -285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -285,
       0,     0,  -285,     0,     0,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,     0,     0,     0,
       0,     0,  -285,  -285,  -285,  -285,  -421,     0,  -285,  -285,
    -285,     0,  -285,     0,  -421,  -421,  -421,     0,     0,  -421,
    -421,  -421,     0,  -421,     0,     0,     0,     0,     0,     0,
       0,     0,  -421,  -421,  -421,     0,     0,     0,     0,     0,
       0,     0,     0,  -421,  -421,     0,  -421,  -421,  -421,  -421,
    -421,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,     0,
       0,  -421,  -421,  -421,     0,     0,  -421,     0,     0,     0,
       0,     0,  -421,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -421,     0,     0,     0,
       0,     0,  -421,     0,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,     0,     0,     0,     0,  -421,  -421,
    -421,  -421,  -421,  -300,  -421,  -421,  -421,  -421,     0,  -421,
       0,  -300,  -300,  -300,     0,     0,  -300,  -300,  -300,     0,
    -300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -300,  -300,     0,     0,     0,     0,     0,     0,     0,     0,
    -300,  -300,     0,  -300,  -300,  -300,  -300,  -300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,  -300,  -300,     0,     0,  -300,  -300,
    -300,     0,     0,  -300,     0,     0,     0,     0,     0,  -300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -300,     0,     0,     0,     0,     0,  -300,
       0,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,     0,     0,     0,     0,     0,  -300,  -300,  -300,  -300,
    -606,   227,  -300,  -300,  -300,     0,  -300,     0,  -606,  -606,
    -606,     0,     0,     0,  -606,  -606,     0,  -606,     0,     0,
       0,     0,     0,     0,     0,     0,  -606,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -606,  -606,     0,
    -606,  -606,  -606,  -606,  -606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,
    -606,  -606,  -606,     0,     0,  -606,  -606,  -606,     0,   701,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -606,     0,     0,     0,     0,  -105,  -606,     0,  -606,  -606,
    -606,  -606,  -606,  -606,  -606,  -606,  -606,  -606,     0,     0,
       0,     0,  -606,  -606,  -606,  -606,   -96,  -293,     0,  -606,
       0,  -606,     0,  -606,     0,  -293,  -293,  -293,     0,     0,
       0,  -293,  -293,     0,  -293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -293,  -293,     0,  -293,  -293,  -293,
    -293,  -293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
       0,     0,  -293,  -293,  -293,     0,   702,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -293,     0,     0,
       0,     0,  -107,  -293,     0,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,     0,     0,     0,     0,     0,
    -293,  -293,  -293,   -98,     0,     0,  -293,     0,  -293,   251,
    -293,     5,     6,     7,     8,     9,  -624,  -624,  -624,    10,
      11,     0,     0,  -624,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,   252,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,     0,    45,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,    51,
      52,     0,    53,    54,     0,    55,     0,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -624,
     251,  -624,     5,     6,     7,     8,     9,     0,     0,  -624,
      10,    11,     0,  -624,  -624,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,    29,   252,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
      51,    52,     0,    53,    54,     0,    55,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -624,   251,  -624,     5,     6,     7,     8,     9,     0,     0,
    -624,    10,    11,     0,     0,  -624,    12,  -624,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,    29,   252,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,     0,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,    51,    52,     0,    53,    54,     0,    55,     0,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -624,   251,  -624,     5,     6,     7,     8,     9,     0,
       0,  -624,    10,    11,     0,     0,  -624,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,   252,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     5,
       6,     7,     8,     9,     0,  -624,  -624,    10,    11,    65,
      66,    67,    12,     0,    13,    14,    15,    16,    17,    18,
      19,     0,  -624,     0,  -624,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,    29,   252,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,     0,
      45,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,    54,     0,    55,     0,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,    65,    66,    67,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,  -624,     0,  -624,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,   252,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,   253,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
    -624,     0,  -624,   251,  -624,     5,     6,     7,     8,     9,
       0,     0,     0,    10,    11,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,    28,    29,   252,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,    54,     0,    55,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,  -624,     0,  -624,   251,  -624,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
     252,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,     0,
      55,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,     0,     0,  -624,     4,     0,     5,
       6,     7,     8,     9,  -624,     0,  -624,    10,    11,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,     0,
      45,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,    51,    52,     0,
      53,    54,     0,    55,     0,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,     0,     0,  -624,
       0,     0,     0,     0,     0,     0,     0,  -624,   251,  -624,
       5,     6,     7,     8,     9,     0,     0,  -624,    10,    11,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,   252,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     5,     6,     7,     8,     9,
       0,     0,     0,    10,    11,    65,    66,    67,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,  -624,     0,
    -624,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,    28,    29,   252,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,    54,     0,    55,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,  -624,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,    66,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,  -624,     0,  -624,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   204,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   207,   208,   209,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,   210,    67,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
     234,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,    66,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,   304,     0,   305,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,     0,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
       0,     0,     0,    10,    11,    65,    66,    67,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
     234,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,    51,    52,     0,    53,    54,     0,    55,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      65,    66,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,   498,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,   252,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   498,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   145,   146,   147,   386,
     387,   388,   389,   152,   153,   154,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   390,   391,   392,   393,   163,
      37,    38,   394,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,   174,   175,     0,     0,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,     0,     0,     0,
       0,     0,     0,   194,   395,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   283,   284,   164,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,   194,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   236,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,   174,   175,     0,     0,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,     0,     0,
       0,     0,     0,     0,   194,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,   194,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,   174,   175,     0,     0,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,     5,     6,
       7,     0,     9,     0,   194,     0,    10,    11,     0,     0,
       0,    12,     0,    13,    14,    15,   241,   242,    18,    19,
       0,     0,     0,     0,     0,   243,   244,   245,    23,    24,
      25,    26,     0,     0,   203,     0,     0,     0,     0,     0,
       0,   271,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,     0,     0,   206,    52,     0,    53,
      54,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,     0,
       0,     0,    12,   273,    13,    14,    15,   241,   242,    18,
      19,   274,     0,     0,     0,     0,   243,   244,   245,    23,
      24,    25,    26,     0,     0,   203,     0,     0,     0,     0,
       0,     0,   271,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,     0,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,   206,    52,     0,
      53,    54,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
       0,     0,     0,    12,   273,    13,    14,    15,    16,    17,
      18,    19,   519,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,    66,    67,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     204,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,   207,
     208,   209,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,    66,    67,    12,     0,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     204,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,   609,
     208,   209,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,   241,   242,
      18,    19,     0,     0,     0,     0,     0,   243,   244,   245,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   204,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   207,   208,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,   210,    67,    12,     0,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     204,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,     0,
     208,   209,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,   241,   242,
      18,    19,     0,     0,     0,     0,     0,   243,   244,   245,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   204,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   609,   208,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,   210,    67,    12,     0,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     204,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,     0,
     208,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   512,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,   210,    67,    12,     0,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,   207,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,   241,   242,
      18,    19,     0,     0,     0,     0,     0,   243,   244,   245,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   816,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,   210,    67,    12,     0,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,   512,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,   241,   242,
      18,    19,     0,     0,     0,     0,     0,   243,   244,   245,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   609,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,   210,    67,    12,     0,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,     0,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    65,    66,    67,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,   206,    52,     0,    53,    54,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   210,    67,    12,     0,    13,    14,    15,   241,   242,
      18,    19,     0,     0,     0,     0,     0,   243,   244,   245,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,   271,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,   325,    52,
       0,    53,    54,     0,   326,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,     0,    12,   273,    13,    14,    15,   241,
     242,    18,    19,     0,     0,     0,     0,     0,   243,   244,
     245,    23,    24,    25,    26,     0,     0,   203,     0,     0,
       0,     0,     0,     0,   271,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,     0,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   367,     0,     0,    51,
      52,     0,    53,    54,     0,    55,     0,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,     0,     0,     0,    12,   273,    13,    14,    15,
     241,   242,    18,    19,     0,     0,     0,     0,     0,   243,
     244,   245,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   271,     0,     0,    32,    33,
      34,   375,    36,    37,    38,   376,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   377,     0,     0,   378,     0,     0,
     206,    52,     0,    53,    54,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,    10,    11,     0,     0,     0,    12,   273,    13,    14,
      15,   241,   242,    18,    19,     0,     0,     0,     0,     0,
     243,   244,   245,    23,    24,    25,    26,     0,     0,   203,
       0,     0,     0,     0,     0,     0,   271,     0,     0,    32,
      33,    34,   375,    36,    37,    38,   376,    40,     0,    41,
      42,    43,    44,     0,    45,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   378,     0,
       0,   206,    52,     0,    53,    54,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     9,     0,
       0,     0,    10,    11,     0,     0,     0,    12,   273,    13,
      14,    15,   241,   242,    18,    19,     0,     0,     0,     0,
       0,   243,   244,   245,    23,    24,    25,    26,     0,     0,
     203,     0,     0,     0,     0,     0,     0,   271,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,   325,    52,     0,    53,    54,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,     0,     0,     0,    12,   273,
      13,    14,    15,   241,   242,    18,    19,     0,     0,     0,
       0,     0,   243,   244,   245,    23,    24,    25,    26,     0,
       0,   203,     0,     0,     0,     0,     0,     0,   271,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,    45,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     898,     0,     0,   206,    52,     0,    53,    54,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       9,     0,     0,     0,    10,    11,     0,     0,     0,    12,
     273,    13,    14,    15,   241,   242,    18,    19,     0,     0,
       0,     0,     0,   243,   244,   245,    23,    24,    25,    26,
       0,     0,   203,     0,     0,     0,     0,     0,     0,   271,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   974,     0,     0,   206,    52,     0,    53,    54,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,   554,   555,     0,     0,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   174,   175,     0,     0,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   562,   563,     0,     0,   564,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   174,   175,     0,     0,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   599,   563,     0,     0,   600,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   613,   555,     0,     0,   614,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   616,   563,     0,     0,   617,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,   174,
     175,     0,     0,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   640,   555,     0,     0,   641,     0,   194,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,   174,   175,
       0,     0,   176,   177,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     643,   563,     0,     0,   644,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,   174,   175,     0,
       0,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   728,
     555,     0,     0,   729,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,   174,   175,     0,     0,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   731,   563,
       0,     0,   732,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,   174,   175,     0,     0,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   738,   555,     0,
       0,   739,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,   174,   175,     0,     0,   176,   177,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,  1006,   555,     0,     0,
    1007,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   174,   175,     0,     0,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,  1036,   555,     0,     0,  1037,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   174,   175,     0,     0,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,  1039,   563,     0,     0,  1040,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     0,     0,   342,   343,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,   344,     0,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234
};

static const yytype_int16 yycheck[] =
{
       2,    27,    51,    29,    89,    16,    17,    92,    98,    20,
       8,    57,   356,     2,     8,     4,    81,   576,   473,   422,
     328,     8,    28,   223,    52,    16,    17,   328,    76,    20,
      28,   414,    22,   265,    28,   575,    92,   269,     4,   422,
     595,    28,   670,   469,    51,   361,    55,   378,    65,   473,
      96,    53,    54,   442,   716,   686,    69,   460,   720,    57,
      88,    89,    53,   786,    92,   873,    69,    13,   777,    55,
     615,   355,   508,   357,   418,   511,     2,   907,     4,   871,
     686,    16,    17,    13,    13,    20,    76,    26,    26,    92,
      16,    17,    29,   519,    20,    81,    63,   642,    96,    78,
      16,    17,    13,   903,    20,    89,    25,    93,    94,    95,
      66,     1,    25,    89,   253,    63,   136,   401,    89,     0,
      13,   136,    87,   143,    25,    51,    52,   471,   143,    55,
      89,   115,    89,   417,    56,   419,    13,    53,    54,   115,
      66,   120,   597,    25,   115,   112,   289,   939,   291,   780,
     293,   115,    25,   784,   297,    81,   115,   206,   115,    27,
      87,   445,    88,    89,   112,   136,    92,    93,    94,    95,
     135,   777,   136,   141,    25,   143,   113,   805,   806,   136,
     786,   143,   737,   991,  1014,   730,   325,   896,   472,   132,
     745,   240,   138,   132,   132,   141,   741,   143,   246,   255,
     138,   993,  1002,   658,   253,   233,   136,   235,   135,   274,
      25,   141,   141,   143,   143,   217,   227,   136,   229,   230,
     623,   223,   945,   136,   309,   310,   311,   312,   230,   119,
     141,   431,   143,  1025,   658,   136,   227,   581,   229,   622,
     623,   950,   255,    87,   633,   271,   253,    25,   141,   593,
     143,   141,   255,   143,   136,   691,   273,   885,   686,    14,
      15,   592,   251,   136,   141,   896,   143,   929,    25,   900,
     233,   697,   903,   141,   905,   143,   325,   362,   363,    99,
     206,   309,   310,   311,   312,   136,   314,   315,   274,   744,
     896,   135,   227,    87,   229,   258,    89,   903,   582,   262,
    1009,   227,   122,   229,   230,    87,   142,   233,   364,   235,
     594,   227,   852,   229,   240,    87,    87,   326,   325,   308,
     744,   136,   115,   138,   313,   251,    87,   253,    25,    89,
      89,    89,   323,    87,   362,   363,   964,   328,   142,   945,
     326,   135,   308,   486,    25,   356,    63,    52,   274,   377,
     493,    56,   780,   135,   356,   115,   115,   115,   136,   357,
     138,   364,   134,   135,   135,    37,    38,   323,   774,   142,
     929,  1002,   328,  1004,   135,    87,   931,   380,  1009,   136,
    1011,   135,   308,   309,   310,   311,   312,   313,   314,   315,
     698,   704,   109,   799,   111,    26,  1002,   323,   711,   325,
     326,   142,   328,   401,   469,   637,    26,   418,   115,    87,
     726,   672,   612,   674,   715,   138,   418,  1048,   115,    26,
     143,   419,   134,   135,    28,   142,   138,   136,   430,   431,
     356,   115,   358,   439,   115,   990,   362,   363,    26,   136,
     442,   439,   139,   102,   686,   439,   143,   445,   404,   405,
      89,   377,   439,   442,   519,   136,    87,   135,   139,    89,
     471,   424,   143,    87,   867,   428,   136,    87,   896,   471,
     433,   143,   900,    63,   472,   903,   115,   905,   404,   405,
      87,   936,    87,   469,   867,    52,   449,    54,    55,    56,
      57,   454,   418,  1038,    37,    38,   138,   136,   414,    87,
      56,   132,    70,   134,   135,   507,   508,   138,    90,   511,
     558,   135,   132,   115,   134,   135,   442,   543,   566,   109,
     136,   111,   571,    89,   573,   132,   452,   134,   135,   134,
     135,   138,   138,   519,    52,   561,    54,    55,    56,    57,
     136,   457,    70,   469,   132,   471,   134,   135,   132,    15,
     138,    17,   142,   601,   139,   518,   115,   125,   126,   127,
     138,   761,   138,    58,   133,   140,    87,   569,   596,   559,
     581,   574,   575,   638,  1002,    70,  1004,   567,    56,   581,
     112,  1009,   593,  1011,   582,   588,   577,   136,    63,   615,
     112,   593,    67,   519,    54,    55,   594,    57,   626,   601,
     606,   917,   112,    98,    99,    65,    66,   923,   606,   112,
     612,   601,   606,   134,   135,    70,   642,    96,   136,   606,
    1048,   882,   883,   136,    17,    70,   887,   122,   889,   141,
     891,   633,   697,    56,   109,     2,   111,     4,   687,    87,
      25,   690,    63,   692,   633,   571,    63,   573,   733,    16,
      17,   736,   638,    20,   896,   581,   139,   705,   900,   749,
     686,   903,   136,   905,   712,   136,   668,   593,   670,   595,
     596,    63,    52,  1017,    54,    55,    56,    57,   123,   124,
     125,   126,   127,    89,    51,    52,   134,   135,   109,   691,
     111,   112,   109,    87,   111,   112,   133,   132,   136,    66,
     626,   747,   136,    87,   730,   733,   622,   633,   736,   115,
     712,   697,   638,   715,   716,   741,   718,   109,   720,   111,
     112,    88,    89,   142,   715,    92,    59,    60,    61,    62,
     136,   734,    89,   142,  1018,   136,   997,   998,   999,  1000,
     134,   135,   698,   746,    87,   701,   702,    63,   774,   747,
     134,   135,   708,   709,   578,    89,   136,   842,   115,   761,
    1002,   687,  1004,   136,   690,   814,   692,  1009,    87,  1011,
     136,   697,   698,   799,    63,   701,   702,   808,   809,   136,
     743,   115,   708,   709,    87,  1046,   473,    89,   115,    87,
     839,   134,   135,   109,   686,   111,   112,   846,   847,   762,
      87,   850,   136,   805,   806,    10,  1048,   733,   138,   772,
     736,   737,     8,   115,   842,   134,   135,   803,    54,   745,
     109,    13,   111,   112,   133,    70,   136,   876,   877,    65,
      66,   134,   135,   115,   136,   837,   134,   135,   840,   206,
      85,    86,   136,   892,    52,    87,   136,   134,   135,   852,
     136,   854,    52,    52,    54,    55,    56,    57,    58,   136,
     227,    52,   229,   230,    87,   136,   233,   117,   235,    15,
      70,   920,   828,   240,   140,   136,   133,   803,   123,   124,
     125,   126,   127,   885,   251,   136,   253,   120,   814,   115,
     136,    91,   134,   135,   786,   136,   859,   789,    98,    99,
      10,   725,   828,   141,   136,   136,   133,   870,    10,   895,
     597,   134,   135,   839,   136,    90,   842,     9,   742,   136,
     846,   847,   122,   139,   850,   136,   136,   929,   959,   960,
     916,   980,   136,   982,   965,   136,   967,   968,   120,   988,
      56,   308,   309,   310,   311,   312,   313,   314,   315,   133,
     876,   877,    10,   136,   133,   136,   323,   110,   325,   136,
     136,   328,   964,   136,   136,   652,   892,   136,    56,   895,
      52,   658,    54,    55,    56,    57,   136,    52,   136,    54,
      55,    56,    57,    40,    41,    42,    43,    44,   138,   356,
     916,   358,    70,    54,   920,   362,   363,   138,   136,   686,
    1031,  1032,  1033,  1034,    93,   931,  1017,    85,    86,    91,
     377,   903,  1038,   905,    95,  1017,    91,  1019,  1020,   843,
    1018,   845,    97,  1054,    52,   452,    54,    55,    56,    57,
      58,   855,   712,   768,   686,  1020,   860,   404,   405,  1014,
     750,  1019,    70,   297,   122,   123,   124,   125,   126,   127,
     101,   418,    59,   945,   980,   947,   982,   744,    96,   780,
     952,   936,   988,    91,   990,   900,   896,   398,    -1,    97,
      98,    99,    -1,   777,    -1,   442,    -1,    -1,    -1,    -1,
      -1,   768,   769,    -1,    -1,   452,    -1,    -1,    16,    17,
     777,  1017,    20,    -1,   122,    -1,    -1,   125,    -1,   786,
      -1,    -1,   926,   927,   471,    -1,    -1,    70,    -1,    -1,
    1002,    -1,  1004,    -1,    -1,   143,    -1,    -1,    -1,  1011,
      48,    49,    85,    86,    -1,    53,    54,    52,    -1,    54,
      55,    56,    57,    -1,    -1,  1027,    -1,    -1,    66,    67,
      -1,    -1,    -1,   204,    -1,    -1,   207,   208,   209,    52,
      -1,    54,    55,    56,    57,    58,  1048,   120,   121,   122,
     123,   124,   125,   126,   127,   989,    91,    70,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   871,    -1,   873,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,  1021,    -1,  1023,
      -1,    -1,    -1,    -1,   571,    -1,   573,    -1,    -1,   896,
      -1,    -1,    -1,    -1,   581,    -1,   903,    -1,    -1,   122,
      -1,    -1,   125,    -1,    -1,    -1,   593,    -1,   595,   596,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    52,    -1,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,   936,
      -1,    -1,   939,   940,    -1,    -1,    70,    -1,   945,   626,
      -1,    -1,   323,    -1,    -1,    -1,   633,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    91,    -1,   207,
     208,   209,   210,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     2,    -1,     4,   227,
      -1,   229,   230,    -1,   991,    -1,   993,    -1,   122,    -1,
      -1,   125,    -1,    -1,    -1,  1002,    -1,    -1,    -1,    -1,
     687,    -1,    -1,   690,   138,   692,    -1,    -1,    -1,    -1,
      -1,   698,    -1,    -1,   701,   702,    -1,    -1,  1025,    -1,
      -1,   708,   709,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,   413,   414,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   422,    -1,    -1,    -1,    -1,   733,    -1,    -1,   736,
     737,    -1,    -1,    -1,    -1,    81,    -1,    -1,   745,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,   323,   457,    -1,    -1,   460,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,    -1,   356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,    -1,    -1,
      52,   512,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,   839,    -1,    -1,   842,   404,   405,    -1,   846,
     847,    -1,    -1,   850,   412,   413,   414,    -1,    -1,    91,
     418,    -1,   420,   421,   422,    97,    98,    99,    -1,    -1,
     206,    -1,    -1,     2,    -1,     4,    -1,    -1,    -1,   876,
     877,    -1,    -1,   441,    -1,    -1,   577,    -1,   446,    -1,
     122,    -1,    -1,   125,    -1,   892,    -1,    -1,    -1,   457,
      -1,    -1,   460,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   471,    -1,   251,    -1,   253,   609,    -1,
      -1,    -1,    51,   920,    -1,    -1,    55,    -1,    -1,    -1,
      -1,   622,   623,    -1,   931,    -1,    -1,    -1,   274,   497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,   512,     2,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,    -1,
      -1,    -1,   308,    -1,    -1,   666,    -1,   313,    -1,    -1,
      -1,    -1,    -1,   980,    -1,   982,    -1,    -1,    -1,   325,
     326,   988,    -1,   990,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   694,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   577,
    1017,    -1,   358,   581,   715,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,   593,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    -1,
      -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,   623,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
       2,    -1,     4,    -1,    -1,   776,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,   666,    -1,
      -1,   240,    -1,    -1,    -1,    -1,   452,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,   816,    -1,    -1,    -1,    51,
      -1,    -1,    -1,   469,    -1,    -1,   694,    -1,    -1,    -1,
     698,   699,    -1,   701,   702,   274,    -1,    -1,    -1,    -1,
     708,   709,    -1,    -1,    -1,    -1,    -1,   715,   849,   206,
      -1,    -1,     2,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,   867,    -1,    -1,   308,
      -1,    -1,    -1,   519,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,   752,    -1,   325,   326,   756,   757,
      -1,   759,   760,    -1,   251,    -1,   253,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,   358,
      -1,    -1,    -1,    -1,    -1,   571,    -1,   573,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   816,   595,
      -1,   308,   820,    -1,    -1,    -1,   313,    -1,    -1,    -1,
     828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,   326,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,   849,    -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,
      -1,    -1,   638,    -1,    -1,    -1,    -1,    -1,   866,   867,
      -1,   358,    -1,   442,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   687,    -1,    -1,   690,    -1,   692,    -1,    -1,    -1,
      -1,   697,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   308,    79,    80,    -1,
     519,   313,    -1,    85,    86,   442,    -1,    -1,    -1,    -1,
     240,   737,    -1,   325,    -1,   452,   328,    -1,    -1,   745,
      -1,   251,    -1,   253,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,   469,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   358,    -1,    -1,    -1,
      -1,    -1,   571,    -1,   573,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,  1017,
      85,    86,    -1,    -1,    -1,    -1,   595,   803,   308,    -1,
      -1,    -1,   519,   313,    -1,    -1,    -1,    -1,   814,    -1,
      -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,
      -1,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   839,   633,    -1,    -1,    -1,    -1,   638,
     846,   847,    -1,    -1,   850,    -1,    -1,    -1,   358,    -1,
     442,    -1,    -1,    -1,   571,    -1,   573,    -1,    -1,    -1,
     452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     876,   877,    -1,    -1,    -1,    -1,    -1,    -1,   595,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   892,    -1,   687,   895,
      -1,   690,    -1,   692,    -1,    -1,    -1,    -1,   697,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
     916,    79,    80,    -1,   920,    -1,   633,    85,    86,    -1,
      -1,   638,    -1,    -1,    -1,   931,    -1,    -1,    -1,    -1,
      -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,   737,    -1,
      -1,    -1,   452,    -1,    -1,    -1,   745,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   678,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     687,    -1,    -1,   690,   980,   692,   982,    -1,    -1,   571,
     697,   573,   988,    -1,   990,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   595,   803,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   814,    -1,    -1,    -1,    -1,
     737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   745,     0,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,
     839,   633,    13,    14,    15,    -1,    17,   846,   847,    -1,
      -1,   850,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,   571,    -1,   573,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,   876,   877,    -1,
      -1,    -1,    -1,    -1,    -1,   595,   803,    -1,    -1,    -1,
      -1,    -1,    -1,   892,    -1,   687,   895,   814,   690,    -1,
     692,    -1,    -1,    -1,    -1,    -1,   698,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,   916,    -1,    -1,
      -1,   920,   839,   633,    -1,    -1,    -1,    -1,    -1,   846,
     847,    -1,   931,   850,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   737,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   745,    -1,    -1,    -1,    -1,    -1,   876,
     877,   132,   133,    -1,   135,    -1,    -1,   138,   139,    -1,
     141,    -1,   143,    -1,    -1,   892,    -1,   687,   895,    -1,
     690,   980,   692,   982,    -1,    -1,    -1,    -1,    -1,   988,
      -1,   990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   916,
      -1,    -1,    -1,   920,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   931,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   814,    -1,    -1,    -1,    -1,   737,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   745,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,
      -1,    -1,    -1,    -1,   846,   847,    -1,    -1,   850,    -1,
      -1,    -1,    -1,   980,    -1,   982,    -1,    -1,    -1,    -1,
      -1,   988,    -1,   990,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,   876,   877,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     892,    -1,    -1,    -1,   814,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    86,    -1,    -1,   916,    -1,    -1,    -1,   920,   839,
      -1,    -1,    -1,    -1,    -1,    -1,   846,   847,    -1,   931,
     850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,   876,   877,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   892,    -1,    -1,    -1,    -1,    -1,   980,    -1,
     982,    -1,    -1,    -1,    -1,    -1,   988,    -1,   990,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    79,    80,
     920,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      -1,   931,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     980,    -1,   982,    -1,    -1,    -1,    -1,    -1,   988,    -1,
     990,     0,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      10,    -1,    -1,    13,    14,    15,    -1,    17,    -1,   128,
     129,   130,    -1,    44,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,   141,    -1,   143,    -1,    -1,    37,    38,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    85,    86,    87,    -1,    89,
      90,    -1,    -1,    -1,    -1,   116,    96,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
     110,    -1,    -1,   113,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,     0,    -1,   139,
     140,   141,    -1,   143,    -1,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    86,    87,    -1,    89,    90,    -1,    -1,
      -1,    -1,   116,    96,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,   110,    -1,    -1,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,     0,    -1,   139,   140,   141,    -1,
     143,    -1,     8,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    85,
      86,    87,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      96,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,     0,    -1,   139,   140,   141,    -1,   143,    -1,     8,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,   113,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,     0,    -1,
     139,   140,   141,    -1,   143,    -1,     8,     9,    10,    -1,
      -1,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    85,    86,    87,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,   113,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,     0,    -1,   139,   140,   141,
      -1,   143,    -1,     8,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    86,    87,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,     0,    -1,   139,   140,   141,    -1,   143,    -1,
       8,     9,    10,    -1,    -1,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    85,    86,    87,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,     0,
     138,   139,   140,   141,    -1,   143,    -1,     8,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    86,    87,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,   113,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,     0,    -1,   139,   140,
     141,    -1,   143,    -1,     8,     9,    10,    -1,    -1,    13,
      14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    85,    86,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,   133,
     134,   135,   136,     0,   138,   139,   140,   141,    -1,   143,
      -1,     8,     9,    10,    -1,    -1,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    86,
      87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
       0,   138,   139,   140,   141,    -1,   143,    -1,     8,     9,
      10,    -1,    -1,    -1,    14,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    85,    86,    87,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,     0,    -1,   139,
      -1,   141,    -1,   143,    -1,     8,     9,    10,    -1,    -1,
      -1,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,    -1,    -1,   139,    -1,   141,     1,
     143,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      92,    -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
       1,   143,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,     1,   143,     3,     4,     5,     6,     7,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,    -1,    64,    65,    66,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,     1,   143,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,   128,
     129,   130,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,   141,    -1,   143,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,
      94,    95,    -1,    97,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,   128,   129,   130,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,   141,    -1,   143,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   141,     1,   143,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,   141,     1,   143,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      97,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,    -1,    -1,   133,     1,    -1,     3,
       4,     5,     6,     7,   141,    -1,   143,    11,    12,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,
      94,    95,    -1,    97,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,     1,   143,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,   141,    -1,
     143,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,   141,    -1,   143,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
     143,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,   141,    -1,   143,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
     143,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,   141,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,   130,     3,     4,
       5,    -1,     7,    -1,   137,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,   128,    18,    19,    20,    21,    22,    23,
      24,   136,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,
      94,    95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,   128,    18,    19,    20,    21,    22,
      23,    24,   136,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   128,   129,   130,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     128,   129,   130,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,   128,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      92,    -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,   128,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,   128,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    91,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,   128,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,   128,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
     128,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,   129,   130,    52,    53,    -1,    -1,    56,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,    52,    53,    -1,    -1,    56,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   129,   130,    52,    53,    -1,    -1,    56,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,    52,    53,    -1,    -1,    56,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    -1,   129,
     130,    52,    53,    -1,    -1,    56,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    79,    80,
      -1,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,   129,   130,
      52,    53,    -1,    -1,    56,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,    52,
      53,    -1,    -1,    56,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,   130,    52,    53,
      -1,    -1,    56,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,   129,   130,    52,    53,    -1,
      -1,    56,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    79,    80,    -1,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,   129,   130,    52,    53,    -1,    -1,
      56,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,   129,   130,    52,    53,    -1,    -1,    56,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,    52,    53,    -1,    -1,    56,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   145,   146,     0,     1,     3,     4,     5,     6,     7,
      11,    12,    16,    18,    19,    20,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    59,    60,    61,    62,    64,    65,    66,    68,    69,
      88,    91,    92,    94,    95,    97,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   128,   129,   130,   147,   148,
     149,   156,   158,   159,   161,   162,   165,   166,   167,   169,
     170,   171,   173,   174,   184,   199,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   253,   254,   268,
     269,   270,   271,   272,   273,   274,   277,   279,   280,   292,
     294,   295,   296,   297,   298,   299,   300,   301,   333,   344,
     149,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    56,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    79,    80,    83,    84,    85,    86,
      97,    98,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   129,   130,   137,   177,   178,   179,   180,   182,
     183,   292,   294,    39,    58,    88,    91,    97,    98,    99,
     129,   166,   174,   184,   186,   191,   194,   196,   217,   297,
     298,   300,   301,   331,   332,   191,   191,   138,   192,   193,
     138,   188,   192,   138,   143,   338,    54,   179,   338,   150,
     132,    21,    22,    30,    31,    32,   165,   184,   217,   184,
      56,     1,    47,    91,   152,   153,   154,   156,   168,   169,
     344,   159,   201,   187,   196,   331,   344,   186,   330,   331,
     344,    46,    88,   128,   136,   173,   199,   217,   297,   298,
     301,   245,   246,    54,    55,    57,   177,   284,   293,   283,
     284,   285,   142,   275,   142,   281,   142,   278,   142,   282,
     296,   161,   184,   184,   141,   143,   337,   342,   343,    40,
      41,    42,    43,    44,    37,    38,    26,   132,   188,   192,
     259,    28,   251,   115,   136,    91,    97,   170,   115,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    85,    86,   116,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    87,   134,   135,   200,   159,
     160,   160,   204,   206,   160,   337,   343,    88,   167,   174,
     217,   233,   297,   298,   301,    52,    56,    85,    88,   175,
     176,   217,   297,   298,   301,   176,    33,    34,    35,    36,
      49,    50,    51,    52,    56,   138,   177,   299,   328,    87,
     135,   336,   259,   271,    89,    89,   136,   186,    56,   186,
     186,   186,   115,    90,   136,   195,   344,    87,   134,   135,
      89,    89,   136,   195,   191,   338,   339,   191,   190,   191,
     196,   331,   344,   159,   339,   159,    54,    65,    66,   157,
     138,   185,   132,   152,    87,   135,    89,   156,   155,   168,
     139,   337,   343,   339,   202,   339,   140,   136,   143,   341,
     136,   341,   133,   341,   338,    56,   296,   170,   172,   136,
      87,   134,   135,   247,    63,   109,   111,   112,   286,   112,
     286,   112,    67,   286,   112,   112,   276,   286,   112,    63,
     112,   112,   112,   276,   112,    63,   112,    70,   141,   149,
     160,   160,   160,   160,   156,   159,   159,   261,   260,    96,
     163,   252,    97,   161,   186,   196,   197,   198,   168,   136,
     173,   136,   158,   161,   174,   184,   186,   198,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,    52,    53,    56,   182,   258,   334,
     335,   190,    52,    53,    56,   182,   257,   334,   151,   152,
      13,   229,   342,   229,   160,   160,   337,    17,   262,    56,
      87,   134,   135,    25,   159,    52,    56,   175,     1,   119,
     302,   342,    87,   134,   135,   213,   329,   214,   336,    52,
      56,   334,   161,   184,   161,   184,   181,   184,   186,    97,
     186,   194,   331,    52,    56,   190,    52,    56,   332,   339,
     139,   339,   136,   136,   339,   179,   203,   184,   147,   133,
     334,   334,   184,   132,   339,   154,   339,   331,   136,   172,
      52,    56,   190,    52,    56,    52,    54,    55,    56,    57,
      58,    70,    91,    97,    98,    99,   122,   125,   138,   249,
     305,   307,   308,   309,   310,   311,   312,   313,   316,   317,
     318,   319,   322,   323,   324,   325,   326,   288,   287,   142,
     286,   142,   142,   142,   184,    78,   120,   240,   241,   344,
     240,   164,   240,   186,   136,   339,   172,   136,   115,    44,
     338,    89,    89,   188,   192,   256,   338,   340,    89,    89,
     188,   192,   255,    10,   228,     8,   264,   344,   152,    13,
     152,    27,   230,   342,   230,   262,   196,   228,    52,    56,
     190,    52,    56,   208,   211,   342,   303,   210,    52,    56,
     175,   190,   151,   159,   138,   304,   307,   215,   188,   189,
     192,   344,    44,   179,   186,   195,    89,    89,   340,    89,
      89,   331,   159,   133,   147,   341,   170,   340,    91,    97,
     234,   235,   236,   309,   307,   248,   115,   136,   306,   186,
     136,   327,   344,    52,   136,   327,   136,   306,    52,   136,
     306,    52,   289,    54,    55,    57,   291,   301,   237,   239,
     242,   309,   311,   312,   314,   315,   318,   320,   321,   324,
     326,   338,   152,   152,   240,   152,    97,   186,   172,   184,
     117,   161,   184,   161,   184,   163,   188,   140,    89,   161,
     184,   161,   184,   163,   189,   186,   198,   265,   344,    15,
     232,   344,    14,   231,   232,   232,   205,   207,   228,   136,
     229,   340,   160,   342,   160,   151,   340,   228,   339,   307,
     151,   342,   177,   259,   251,   184,    89,   136,   339,   133,
     236,   136,   309,   136,   339,   242,    29,   113,   250,   186,
     305,   310,   322,   324,   313,   318,   326,   311,   319,   324,
     309,   311,   290,   242,   120,   115,   136,   238,    88,   217,
     136,   327,   327,   136,   238,   136,   238,   141,    10,   133,
     152,    10,   186,   184,   161,   184,    90,   266,   344,   152,
       9,   267,   344,   160,   228,   228,   152,   152,   186,   152,
     230,   212,   342,   228,   339,   228,   216,   339,   235,   136,
      97,   234,   139,   152,   152,   136,   306,   136,   306,   327,
     136,   306,   136,   306,   306,   152,   120,   217,   237,   321,
     324,    56,    87,   314,   318,   311,   320,   324,   311,    52,
     243,   244,   308,   133,    88,   174,   217,   297,   298,   301,
     229,   152,   229,   228,   228,   232,   262,   263,   209,   151,
     304,   136,   235,   136,   309,    10,   133,   311,   324,   311,
     311,   110,   136,   238,   136,   238,    52,    56,   327,   136,
     238,   136,   238,   238,   136,    56,    87,   134,   135,   152,
     152,   152,   228,   151,   235,   136,   306,   136,   306,   306,
     306,   311,   324,   311,   311,   244,    52,    56,   190,    52,
      56,   264,   231,   228,   228,   235,   311,   238,   136,   238,
     238,   238,   340,   306,   311,   238
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   144,   146,   145,   147,   148,   148,   148,   148,   149,
     150,   149,   151,   152,   153,   153,   153,   153,   154,   155,
     154,   157,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   158,   158,   159,   159,   159,
     159,   159,   159,   160,   161,   161,   162,   162,   164,   163,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   167,   168,   168,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   170,   171,   171,
     172,   172,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   176,   176,   176,   177,   177,   177,   177,   177,
     178,   178,   179,   179,   180,   181,   180,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   185,
     184,   184,   184,   186,   187,   187,   187,   187,   188,   189,
     189,   190,   190,   190,   190,   190,   191,   191,   191,   191,
     191,   193,   192,   194,   195,   195,   196,   196,   196,   196,
     197,   197,   198,   198,   198,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   200,   199,   201,   199,
     202,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   203,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   204,   205,   199,   206,   207,   199,   199,   199,   208,
     209,   199,   210,   199,   211,   212,   199,   213,   199,   214,
     199,   215,   216,   199,   199,   199,   199,   199,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   229,   229,   230,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   237,   237,   237,   237,   238,   238,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   240,   240,   241,   241,   241,
     242,   242,   243,   243,   244,   244,   246,   247,   248,   245,
     249,   249,   250,   250,   252,   251,   253,   253,   253,   253,
     254,   255,   254,   256,   254,   254,   257,   254,   258,   254,
     254,   254,   254,   260,   259,   261,   259,   262,   263,   263,
     264,   264,   265,   265,   265,   266,   266,   267,   267,   268,
     268,   268,   269,   270,   270,   270,   271,   272,   273,   274,
     274,   275,   275,   276,   276,   277,   277,   278,   278,   279,
     279,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     284,   285,   285,   286,   287,   286,   288,   289,   290,   286,
     291,   291,   291,   291,   292,   293,   293,   293,   293,   294,
     295,   295,   296,   296,   296,   296,   297,   297,   297,   297,
     297,   298,   298,   298,   298,   298,   298,   298,   299,   299,
     300,   300,   301,   301,   302,   303,   302,   302,   304,   304,
     305,   305,   305,   305,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   308,   308,   308,   308,   309,   309,   310,   310,   311,
     311,   312,   313,   313,   314,   314,   315,   315,   316,   316,
     317,   317,   318,   318,   319,   320,   321,   321,   322,   322,
     323,   323,   324,   324,   325,   325,   326,   327,   327,   328,
     329,   328,   330,   330,   331,   331,   332,   332,   332,   333,
     333,   333,   334,   334,   334,   334,   335,   335,   335,   336,
     336,   337,   337,   338,   338,   339,   340,   341,   341,   341,
     342,   342,   343,   343,   344
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       3,     5,     6,     5,     5,     5,     5,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     0,
       4,     6,     1,     1,     1,     2,     4,     2,     3,     1,
       1,     1,     1,     2,     4,     2,     1,     2,     2,     4,
       1,     0,     2,     2,     2,     1,     1,     2,     3,     4,
       1,     1,     3,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     3,
       0,     4,     3,     3,     2,     3,     3,     1,     4,     3,
       1,     0,     6,     4,     3,     2,     1,     2,     2,     6,
       6,     0,     0,     7,     0,     0,     7,     5,     4,     0,
       0,     9,     0,     6,     0,     0,     8,     0,     5,     0,
       6,     0,     0,     9,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     5,     1,     2,     1,
       1,     1,     3,     1,     3,     1,     4,     6,     3,     5,
       2,     4,     1,     3,     4,     2,     2,     1,     2,     0,
       6,     8,     4,     6,     4,     2,     6,     2,     4,     6,
       2,     4,     2,     4,     1,     1,     1,     3,     1,     4,
       1,     3,     1,     3,     1,     1,     0,     0,     0,     5,
       4,     1,     3,     3,     0,     5,     2,     4,     5,     5,
       2,     0,     5,     0,     5,     3,     0,     4,     0,     4,
       2,     1,     4,     0,     5,     0,     5,     5,     1,     1,
       6,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     0,     3,     1,     2,     3,     3,     0,     3,     3,
       3,     3,     3,     0,     3,     0,     3,     0,     2,     0,
       2,     0,     2,     1,     0,     3,     0,     0,     0,     6,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     2,     3,     2,
       4,     2,     2,     1,     2,     0,     6,     8,     4,     6,
       4,     6,     2,     4,     6,     2,     4,     2,     4,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     2,     1,     2,     1,     1,     3,     1,     3,
       1,     1,     2,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     1,     2,     2,     1,     1,
       0,     4,     1,     2,     1,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     2,     2,     0,     1,     1,
       1,     1,     1,     2,     0
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
#line 578 "grammar.y" /* yacc.c:1661  */
    {
                    lex_state = EXPR_BEG;
                    local_push(0);
                    class_nest = 0;
                  }
#line 4584 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 584 "grammar.y" /* yacc.c:1661  */
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
#line 4606 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 604 "grammar.y" /* yacc.c:1661  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4615 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 611 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4623 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 615 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4631 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 619 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4639 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 623 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4647 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 630 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single) {
                      yy_error("BEGIN in method");
                    }
                  }
#line 4657 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 636 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_PREEXE((yyvsp[-1].node));
                  }
#line 4665 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 645 "grammar.y" /* yacc.c:1661  */
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
#line 4687 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 665 "grammar.y" /* yacc.c:1661  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4696 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 672 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4704 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 676 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4712 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 680 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4720 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 684 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4728 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 690 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4736 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 694 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("BEGIN is permitted only at toplevel");
                  }
#line 4744 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 698 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4752 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 703 "grammar.y" /* yacc.c:1661  */
    {lex_state = EXPR_FNAME;}
#line 4758 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 704 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ALIAS((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4766 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 708 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 4774 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 712 "grammar.y" /* yacc.c:1661  */
    {
                    char buf[2];
                    buf[0] = '$';
                    buf[1] = (char)(yyvsp[0].node)->nd_nth;
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), parser_intern2(buf, 2));
                  }
#line 4785 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 719 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("can't make alias for the number variables");
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4794 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 724 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4802 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 728 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4811 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 733 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4820 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 738 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4832 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 746 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4844 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 754 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *resq = NEW_RESBODY(0, remove_begin((yyvsp[0].node)), 0);
                    (yyval.node) = NEW_RESCUE(remove_begin((yyvsp[-2].node)), resq, 0);
                  }
#line 4853 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 759 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single) {
                      rb_warn("END in method; use at_exit");
                    }

                    (yyval.node) = NEW_POSTEXE(NEW_NODE(NODE_SCOPE,
                            0 /* tbl */, (yyvsp[-1].node) /* body */, 0 /* args */));
                  }
#line 4866 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 769 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 4876 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 775 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4885 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 780 "grammar.y" /* yacc.c:1661  */
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
#line 4906 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 797 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4915 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 802 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4924 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 807 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4933 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 812 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4942 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 817 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4951 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 822 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4960 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 827 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 4969 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 835 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4978 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 840 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4987 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 848 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4995 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 852 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5003 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 856 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5011 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 860 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5019 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 867 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 5029 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 880 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5037 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 886 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 5046 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 893 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 5056 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 901 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                    nd_set_line((yyval.node), tokline);
                  }
#line 5065 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 908 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                 }
#line 5074 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 913 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[-2].node)->nd_args = (yyvsp[-1].node);
                    (yyvsp[0].node)->nd_iter = (yyvsp[-2].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-2].node));
                 }
#line 5086 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 921 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5095 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 926 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                 }
#line 5106 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 933 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5115 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 938 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 5126 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 945 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5135 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 950 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_yield((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5144 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 955 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETURN(ret_args((yyvsp[0].node)));
                  }
#line 5152 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 959 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BREAK(ret_args((yyvsp[0].node)));
                  }
#line 5160 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 963 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_NEXT(ret_args((yyvsp[0].node)));
                  }
#line 5168 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 970 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5176 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 977 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(NEW_LIST((yyvsp[-1].node)), 0);
                  }
#line 5184 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 983 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 5192 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 987 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(list_append((yyvsp[-1].node), (yyvsp[0].node)), 0);
                  }
#line 5200 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 991 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5208 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 995 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5216 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 999 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-1].node), -1);
                  }
#line 5224 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 1003 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5232 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 1007 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, (yyvsp[0].node));
                  }
#line 5240 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 1011 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5248 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 1015 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 5256 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 1019 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5264 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 1026 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5272 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 1032 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[-1].node));
                  }
#line 5280 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 1036 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 5288 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 1042 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 5296 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 1046 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5304 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 1052 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5312 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 1056 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5320 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 1060 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5328 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 1064 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5336 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 1068 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5344 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 1072 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5352 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 1076 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5362 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 1082 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5372 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 1088 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5381 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 1095 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5390 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 1100 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5399 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 1105 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5407 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 1109 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5415 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 1113 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5423 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 1117 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5431 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 1121 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5441 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 1127 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5451 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 1133 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5460 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 1140 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("class/module name must be CONSTANT");
                  }
#line 5468 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 1147 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 5476 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 1151 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2(0, (yyval.node));
                  }
#line 5484 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 1155 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5492 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 1164 "grammar.y" /* yacc.c:1661  */
    {
                    lex_state = EXPR_ENDFN;
                    (yyval.id) = convert_op((yyvsp[0].id));
                  }
#line 5501 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 1169 "grammar.y" /* yacc.c:1661  */
    {
                    lex_state = EXPR_ENDFN;
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 5510 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 1180 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 5518 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 1187 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNDEF((yyvsp[0].node));
                  }
#line 5526 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 1190 "grammar.y" /* yacc.c:1661  */
    {lex_state = EXPR_FNAME;}
#line 5532 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 1191 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = block_append((yyvsp[-3].node), NEW_UNDEF((yyvsp[0].node)));
                  }
#line 5540 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 1196 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '|'; }
#line 5546 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 1197 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '^'; }
#line 5552 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 1198 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '&'; }
#line 5558 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 1199 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tCMP; }
#line 5564 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 1200 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tEQ; }
#line 5570 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 1201 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tEQQ; }
#line 5576 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 1202 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tMATCH; }
#line 5582 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 1203 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tNMATCH; }
#line 5588 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 1204 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '>'; }
#line 5594 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 1205 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tGEQ; }
#line 5600 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 1206 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '<'; }
#line 5606 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 1207 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tLEQ; }
#line 5612 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 1208 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tNEQ; }
#line 5618 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 1209 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tLSHFT; }
#line 5624 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 1210 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tRSHFT; }
#line 5630 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 1211 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '+'; }
#line 5636 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 1212 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '-'; }
#line 5642 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 1213 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '*'; }
#line 5648 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 1214 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '*'; }
#line 5654 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 1215 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '/'; }
#line 5660 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 1216 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '%'; }
#line 5666 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 1217 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tPOW; }
#line 5672 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 1218 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tDSTAR; }
#line 5678 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 1219 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '!'; }
#line 5684 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 1220 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '~'; }
#line 5690 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 1221 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tUPLUS; }
#line 5696 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 1222 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tUMINUS; }
#line 5702 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 1223 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tAREF; }
#line 5708 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 1224 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = tASET; }
#line 5714 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 1225 "grammar.y" /* yacc.c:1661  */
    { (yyval.id) = '`'; }
#line 5720 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 1243 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5729 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 1248 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    (yyval.node) = node_assign((yyvsp[-4].node), (yyvsp[-2].node));
                  }
#line 5739 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 1254 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5748 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1259 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    new_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].node));
                  }
#line 5758 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1265 "grammar.y" /* yacc.c:1661  */
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
#line 5783 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1286 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5792 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1291 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5801 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1296 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5810 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1301 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5819 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1306 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5828 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1311 "grammar.y" /* yacc.c:1661  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5837 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1316 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT2((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5847 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1322 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT3((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5857 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1328 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '+', (yyvsp[0].node));
                  }
#line 5865 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1332 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '-', (yyvsp[0].node));
                  }
#line 5873 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1336 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '*', (yyvsp[0].node));
                  }
#line 5881 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1340 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '/', (yyvsp[0].node));
                  }
#line 5889 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1344 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '%', (yyvsp[0].node));
                  }
#line 5897 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1348 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node));
                  }
#line 5905 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1352 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL(call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node)), tUMINUS, 0);
                  }
#line 5913 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1356 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUPLUS);
                  }
#line 5921 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1360 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUMINUS);
                  }
#line 5929 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1364 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '|', (yyvsp[0].node));
                  }
#line 5937 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1368 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '^', (yyvsp[0].node));
                  }
#line 5945 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1372 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '&', (yyvsp[0].node));
                  }
#line 5953 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1376 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tCMP, (yyvsp[0].node));
                  }
#line 5961 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1380 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '>', (yyvsp[0].node));
                  }
#line 5969 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1384 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tGEQ, (yyvsp[0].node));
                  }
#line 5977 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1388 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '<', (yyvsp[0].node));
                  }
#line 5985 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1392 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLEQ, (yyvsp[0].node));
                  }
#line 5993 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1396 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQ, (yyvsp[0].node));
                  }
#line 6001 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1400 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQQ, (yyvsp[0].node));
                  }
#line 6009 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1404 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNEQ, (yyvsp[0].node));
                  }
#line 6017 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1408 "grammar.y" /* yacc.c:1661  */
    {
                    /* TODO */
                    (yyval.node) = match_op((yyvsp[-2].node), (yyvsp[0].node));
                    /*
                    if(nd_type($1) == NODE_LIT && TYPE($1->nd_lit) == T_REGEXP) {
                      $$ = reg_named_capture_assign($1->nd_lit, $$);
                    }
                    */
                  }
#line 6031 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1418 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNMATCH, (yyvsp[0].node));
                  }
#line 6039 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1422 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 6047 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1426 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), '~');
                  }
#line 6055 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1430 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLSHFT, (yyvsp[0].node));
                  }
#line 6063 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1434 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tRSHFT, (yyvsp[0].node));
                  }
#line 6071 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1438 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6079 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1442 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6087 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1445 "grammar.y" /* yacc.c:1661  */
    {in_defined = 1;}
#line 6093 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1446 "grammar.y" /* yacc.c:1661  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[0].node));
                  }
#line 6102 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1451 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[-5].node));
                    (yyval.node) = NEW_IF(cond((yyvsp[-5].node)), (yyvsp[-3].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-5].node));
                  }
#line 6112 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1457 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6120 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1463 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6130 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1472 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6138 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1476 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6146 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1480 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6154 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1486 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6162 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1498 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6170 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1502 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6178 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1506 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6186 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1512 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6195 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1517 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_blk_pass((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 6203 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1521 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6212 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1526 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6221 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1533 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.val) = cmdarg_stack;
                    CMDARG_PUSH(1);
                  }
#line 6230 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1538 "grammar.y" /* yacc.c:1661  */
    {
                    /* CMDARG_POP() */
                    cmdarg_stack = (yyvsp[-1].val);
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6240 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1546 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BLOCK_PASS((yyvsp[0].node));
                  }
#line 6248 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1552 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6256 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1556 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 6264 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1562 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6272 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1566 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6280 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1570 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6293 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1579 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((nd_type((yyvsp[0].node)) == NODE_ARRAY) && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6306 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1594 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6319 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1603 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *n1;
                    if(nd_type((yyvsp[0].node)) == NODE_ARRAY && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6332 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1612 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6340 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1628 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                  }
#line 6348 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1632 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cmdarg_stack;
                    cmdarg_stack = 0;
                    (yyval.num) = sourceline;
                  }
#line 6358 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1639 "grammar.y" /* yacc.c:1661  */
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
#line 6375 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1651 "grammar.y" /* yacc.c:1661  */
    {lex_state = EXPR_ENDARG;}
#line 6381 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1652 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 6389 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1655 "grammar.y" /* yacc.c:1661  */
    {lex_state = EXPR_ENDARG;}
#line 6395 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1656 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 6403 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1660 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6411 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1664 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 6419 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1668 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 6427 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1672 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-1].node) == 0) {
                      (yyval.node) = NEW_ZARRAY(); /* zero length array*/
                    } else {
                      (yyval.node) = (yyvsp[-1].node);
                    }
                  }
#line 6439 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1680 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_HASH((yyvsp[-1].node));
                  }
#line 6447 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1684 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETURN(0);
                  }
#line 6455 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1688 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_yield((yyvsp[-1].node));
                  }
#line 6463 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1692 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6471 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1696 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6479 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 1699 "grammar.y" /* yacc.c:1661  */
    {in_defined = 1;}
#line 6485 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1700 "grammar.y" /* yacc.c:1661  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[-1].node));
                  }
#line 6494 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1705 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[-1].node)), '!');
                  }
#line 6502 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1709 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = call_uni_op(cond(NEW_NIL()), '!');
                  }
#line 6510 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1713 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyvsp[0].node)->nd_iter, (yyvsp[0].node));
                  }
#line 6520 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1720 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-1].node));
                  }
#line 6531 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1727 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6539 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1734 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6548 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 1742 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6557 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1746 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6563 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1746 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6569 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1749 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_WHILE(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6578 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1753 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6584 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1753 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6590 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1756 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_UNTIL(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6599 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1763 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CASE((yyvsp[-3].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 6608 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1768 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CASE(0, (yyvsp[-1].node));
                  }
#line 6616 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1772 "grammar.y" /* yacc.c:1661  */
    {COND_PUSH(1);}
#line 6622 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1774 "grammar.y" /* yacc.c:1661  */
    {COND_POP();}
#line 6628 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1777 "grammar.y" /* yacc.c:1661  */
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
#line 6646 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1791 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("class definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6658 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1800 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CLASS((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-3].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6669 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1807 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_def;
                    in_def = 0;
                  }
#line 6678 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1812 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = in_single;
                    in_single = 0;
                    class_nest++;
                    local_push(0);
                  }
#line 6689 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1820 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SCLASS((yyvsp[-5].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-5].node));
                    local_pop();
                    class_nest--;
                    in_def = (yyvsp[-4].num);
                    in_single = (yyvsp[-2].num);
                  }
#line 6702 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1829 "grammar.y" /* yacc.c:1661  */
    {
                    if(in_def || in_single)
                      yy_error("module definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6714 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1838 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MODULE((yyvsp[-3].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6725 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1845 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    in_def++;
                    local_push(0);
                  }
#line 6736 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1854 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFN((yyvsp[-4].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-5].num));
                    local_pop();
                    in_def--;
                    cur_mid = (yyvsp[-3].id);
                  }
#line 6749 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1862 "grammar.y" /* yacc.c:1661  */
    {lex_state = EXPR_FNAME;}
#line 6755 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1863 "grammar.y" /* yacc.c:1661  */
    {
                    in_single++;
                    lex_state = EXPR_ENDFN; /* force for args */
                    local_push(0);
                  }
#line 6765 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1871 "grammar.y" /* yacc.c:1661  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFS((yyvsp[-7].node), (yyvsp[-4].id), (yyvsp[-2].node), body);
                    nd_set_line((yyval.node), (yyvsp[-8].num));
                    local_pop();
                    in_single--;
                  }
#line 6777 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1879 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_BREAK(0);
                  }
#line 6785 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1883 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_NEXT(0);
                  }
#line 6793 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1887 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_REDO();
                  }
#line 6801 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1891 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_RETRY();
                  }
#line 6809 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1897 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6819 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1905 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("begin");
                  }
#line 6827 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1911 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("if");
                  }
#line 6835 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1917 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("unless");
                  }
#line 6843 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1923 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("while");
                  }
#line 6851 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1929 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("until");
                  }
#line 6859 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1935 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("case");
                  }
#line 6867 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1941 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("for");
                  }
#line 6875 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1947 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("class");
                  }
#line 6883 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1953 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("module");
                  }
#line 6891 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1959 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_push("def");
                    (yyval.num) = sourceline;
                  }
#line 6900 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1966 "grammar.y" /* yacc.c:1661  */
    {
                    token_info_pop("end");
                  }
#line 6908 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 356:
#line 1984 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-3].node)), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 6917 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 1992 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6925 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 361:
#line 2002 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 6933 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 2006 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6941 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 2012 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6949 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 2016 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6957 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 2022 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 6965 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 2026 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), (yyval.node));
                  }
#line 6974 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 2031 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-5].node), NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 6983 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 2036 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), -1);
                  }
#line 6991 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 2040 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 6999 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 2044 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN(0, (yyval.node));
                  }
#line 7008 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 2049 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 7017 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 372:
#line 2054 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 7025 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 373:
#line 2058 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7033 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 2064 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7041 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 2068 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 7049 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 2072 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7057 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 2076 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 7065 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 2082 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7073 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 2086 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 7081 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 2092 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7089 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 2096 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7097 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 2100 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7105 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 2104 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7113 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 2108 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7121 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 2112 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 1, 0, new_args_tail(0, 0, 0));
                  }
#line 7129 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 2116 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7137 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 2120 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 7145 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 2124 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7153 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 2128 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7161 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 2132 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7169 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 2136 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7177 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 2140 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7185 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 2144 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7193 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 2148 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 7201 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 2155 "grammar.y" /* yacc.c:1661  */
    {
                    command_start = TRUE;
                  }
#line 7209 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 2161 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX(0, (yyvsp[-1].node)) : 0;
                  }
#line 7218 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 2166 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7226 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 2170 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX((yyvsp[-2].node), (yyvsp[-1].node)) : (yyvsp[-2].node);
                  }
#line 7235 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 2177 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7243 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 2181 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7252 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 2188 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7261 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 2193 "grammar.y" /* yacc.c:1661  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 7270 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 2200 "grammar.y" /* yacc.c:1661  */
    {
                    new_bv(get_id((yyvsp[0].id)));
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIT(ID2SYM(get_id((yyvsp[0].id))));
                  }
#line 7280 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 2206 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7288 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 2211 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.vars) = bv_push();
                  }
#line 7296 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 2214 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = lpar_beg;
                    lpar_beg = ++paren_nest;
                  }
#line 7305 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 2219 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7313 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 2223 "grammar.y" /* yacc.c:1661  */
    {
                    lpar_beg = (yyvsp[-3].num);
                    (yyval.node) = NEW_LAMBDA((yyvsp[-2].node), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7324 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 2232 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 7332 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 2236 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7340 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 2242 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7348 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 2246 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7356 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 2252 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7365 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 2259 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7375 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 2267 "grammar.y" /* yacc.c:1661  */
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
#line 7390 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 2278 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 7398 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 2282 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7409 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 2289 "grammar.y" /* yacc.c:1661  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7420 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 2298 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 7430 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 2304 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7438 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 2308 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7447 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 2313 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7455 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 2317 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7464 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 2322 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].id), 0);
                  }
#line 7472 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 2326 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7480 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 2330 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7489 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 2335 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7497 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 2339 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7506 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 2344 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                  }
#line 7514 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 2348 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZSUPER();
                  }
#line 7522 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 2352 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-3].node) && nd_type((yyvsp[-3].node)) == NODE_SELF) {
                      (yyval.node) = NEW_FCALL(tAREF, (yyvsp[-1].node));
                    } else {
                      (yyval.node) = NEW_CALL((yyvsp[-3].node), tAREF, (yyvsp[-1].node));
                    }
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 7535 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 2363 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7544 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 2369 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7554 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 2375 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7563 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 2381 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7573 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 2391 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_WHEN((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7581 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 2403 "grammar.y" /* yacc.c:1661  */
    {
                    if((yyvsp[-3].node)) {
                      /* TODO NEW_ERRINFO() */
                      (yyvsp[-3].node) = node_assign((yyvsp[-3].node), NEW_GVAR(parser_intern("$!")));
                      (yyvsp[-1].node) = block_append((yyvsp[-3].node), (yyvsp[-1].node));
                    }
                    (yyval.node) = NEW_RESBODY((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-4].node) ? (yyvsp[-4].node) : (yyvsp[-1].node));
                  }
#line 7595 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 2416 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7603 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 2420 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = splat_array((yyvsp[0].node)))) (yyval.node) = (yyvsp[0].node);
                  }
#line 7611 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 445:
#line 2427 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7619 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 2434 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7627 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 2442 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 7635 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 2449 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *node = (yyvsp[0].node);
                    if(!node) {
                      node = NEW_STR(STR_NEW0());
                    } else {
                      node = evstr2dstr(node);
                    }
                    (yyval.node) = node;
                  }
#line 7649 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 455:
#line 2463 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7657 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 456:
#line 2469 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7665 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 457:
#line 2475 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *node = (yyvsp[-1].node);
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
#line 7689 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 458:
#line 2497 "grammar.y" /* yacc.c:1661  */
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
#line 7751 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 459:
#line 2557 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7759 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 460:
#line 2561 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7767 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 461:
#line 2567 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7775 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 462:
#line 2571 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), evstr2dstr((yyvsp[-1].node)));
                  }
#line 7783 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 464:
#line 2578 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7791 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 465:
#line 2584 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7799 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 466:
#line 2588 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7807 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 2594 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7815 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 468:
#line 2598 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[-1].node) = evstr2dstr((yyvsp[-1].node));
                    nd_set_type((yyvsp[-1].node), NODE_DSYM);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7825 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 469:
#line 2606 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7833 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 470:
#line 2610 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7841 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 471:
#line 2616 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7849 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 2620 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7857 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 473:
#line 2626 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7865 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 474:
#line 2630 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7873 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 2636 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7881 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 2640 "grammar.y" /* yacc.c:1661  */
    {
                    VALUE lit;
                    lit = (yyvsp[-1].node)->nd_lit;
                    (yyvsp[-1].node)->nd_lit = ID2SYM(parser_intern_str(lit));
                    nd_set_type((yyvsp[-1].node), NODE_LIT);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7893 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 2650 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7901 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 2654 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7909 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 479:
#line 2660 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7917 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 480:
#line 2664 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7925 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 481:
#line 2670 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 7933 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 482:
#line 2674 "grammar.y" /* yacc.c:1661  */
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
#line 7958 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 484:
#line 2698 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                    lex_state = EXPR_BEG;
                  }
#line 7968 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 485:
#line 2704 "grammar.y" /* yacc.c:1661  */
    {
                    lex_strterm = (yyvsp[-1].node);
                    (yyval.node) = NEW_EVSTR((yyvsp[0].node));
                  }
#line 7977 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 486:
#line 2709 "grammar.y" /* yacc.c:1661  */
    {
                    (yyvsp[0].val) = cond_stack;
                    (yyval.val) = cmdarg_stack;
                    cond_stack = 0;
                    cmdarg_stack = 0;
                  }
#line 7988 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 487:
#line 2715 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                    lex_state = EXPR_BEG;
                  }
#line 7998 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 488:
#line 2720 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.num) = brace_nest;
                    brace_nest = 0;
                  }
#line 8007 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 489:
#line 2725 "grammar.y" /* yacc.c:1661  */
    {
                    cond_stack = (yyvsp[-5].val);
                    cmdarg_stack = (yyvsp[-4].val);
                    lex_strterm = (yyvsp[-3].node);
                    brace_nest = (yyvsp[-2].num);

                    if((yyvsp[-1].node)) (yyvsp[-1].node)->flags &= ~NODE_FL_NEWLINE;
                    (yyval.node) = new_evstr((yyvsp[-1].node));
                  }
#line 8021 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 490:
#line 2736 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_GVAR((yyvsp[0].id));}
#line 8027 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 2737 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_IVAR((yyvsp[0].id));}
#line 8033 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 2738 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = NEW_CVAR((yyvsp[0].id));}
#line 8039 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 2743 "grammar.y" /* yacc.c:1661  */
    {
                    lex_state = EXPR_END;
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8048 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 499:
#line 2756 "grammar.y" /* yacc.c:1661  */
    {
                    lex_state = EXPR_END;
                    // TODO dsym_node($2);
                    if(!((yyval.node) = (yyvsp[-1].node))) {
                      (yyval.node) = NEW_LIT(ID2SYM(parser_intern("")));
                    } else {
                      VALUE lit;

                      switch(nd_type((yyval.node))) {
                      case NODE_DSTR:
                        nd_set_type((yyval.node), NODE_DSYM);
                        break;
                      case NODE_STR:
                        lit = (yyval.node)->nd_lit;
                        (yyval.node)->nd_lit = ID2SYM(parser_intern_str(lit));
                        nd_set_type((yyval.node), NODE_LIT);
                        break;
                      default:
                        (yyval.node) = NEW_NODE(NODE_DSYM, REF(STR_NEW0()), 1, NEW_LIST((yyval.node)));
                        break;
                      }
                    }
                  }
#line 8076 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 501:
#line 2783 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = negate_lit((yyvsp[0].node));
                  }
#line 8084 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 511:
#line 2801 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_nil;}
#line 8090 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 512:
#line 2802 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_self;}
#line 8096 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 513:
#line 2803 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_true;}
#line 8102 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 514:
#line 2804 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword_false;}
#line 8108 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 515:
#line 2805 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__FILE__;}
#line 8114 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 516:
#line 2806 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__LINE__;}
#line 8120 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 517:
#line 2807 "grammar.y" /* yacc.c:1661  */
    {(yyval.id) = keyword__ENCODING__;}
#line 8126 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 518:
#line 2811 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8136 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 519:
#line 2817 "grammar.y" /* yacc.c:1661  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8146 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 520:
#line 2825 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8154 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 521:
#line 2829 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8162 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 524:
#line 2839 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = 0;
                  }
#line 8170 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 525:
#line 2843 "grammar.y" /* yacc.c:1661  */
    {
                    lex_state = EXPR_BEG;
                    command_start = TRUE;
                  }
#line 8179 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 526:
#line 2848 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8187 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 527:
#line 2852 "grammar.y" /* yacc.c:1661  */
    {
                    yyerrok;
                    (yyval.node) = 0;
                  }
#line 8196 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 528:
#line 2859 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    lex_state = EXPR_BEG;
                    command_start = TRUE;
                  }
#line 8206 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 529:
#line 2865 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    lex_state = EXPR_BEG;
                    command_start = TRUE;
                  }
#line 8216 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 530:
#line 2873 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8224 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 531:
#line 2877 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 8232 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 532:
#line 2881 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8240 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 533:
#line 2885 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 8248 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 534:
#line 2891 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8256 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 535:
#line 2895 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 8264 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 536:
#line 2901 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8272 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 537:
#line 2905 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8280 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 538:
#line 2909 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8288 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 539:
#line 2913 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8296 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 540:
#line 2917 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8304 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 541:
#line 2921 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8312 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 542:
#line 2925 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 8320 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 543:
#line 2929 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8328 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 544:
#line 2933 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8336 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 545:
#line 2937 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8344 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 546:
#line 2941 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8352 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 547:
#line 2945 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8360 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 548:
#line 2949 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8368 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 549:
#line 2953 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 8376 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 550:
#line 2957 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                    (yyval.node) = new_args(0, 0, 0, 0, (yyval.node));
                  }
#line 8385 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 551:
#line 2964 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a constant");
                    (yyval.id) = 0;
                  }
#line 8394 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 552:
#line 2969 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be an instance variable");
                    (yyval.id) = 0;
                  }
#line 8403 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 553:
#line 2974 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a global variable");
                    (yyval.id) = 0;
                  }
#line 8412 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 554:
#line 2979 "grammar.y" /* yacc.c:1661  */
    {
                    yy_error("formal argument cannot be a class variable");
                    (yyval.id) = 0;
                  }
#line 8421 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 556:
#line 2987 "grammar.y" /* yacc.c:1661  */
    {
                    formal_argument(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8430 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 557:
#line 2994 "grammar.y" /* yacc.c:1661  */
    {
                    arg_var(get_id((yyvsp[0].id)));
                    (yyval.node) = NEW_ARGS_AUX((yyvsp[0].id), 1);
                  }
#line 8439 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 558:
#line 2999 "grammar.y" /* yacc.c:1661  */
    {
                    ID tid = internal_id();
                    arg_var(tid);
                    (yyvsp[-1].node)->nd_value = NEW_LVAR(tid);
                    (yyval.node) = NEW_ARGS_AUX(tid, 1);
                    (yyval.node)->nd_next = (yyvsp[-1].node);
                  }
#line 8451 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 560:
#line 3010 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                    (yyval.node)->nd_plen++;
                    (yyval.node)->nd_next = block_append((yyval.node)->nd_next, (yyvsp[0].node)->nd_next);
                  }
#line 8461 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 561:
#line 3018 "grammar.y" /* yacc.c:1661  */
    {
                    arg_var(formal_argument(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8470 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 562:
#line 3025 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8479 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 563:
#line 3030 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8488 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 564:
#line 3037 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8497 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 565:
#line 3042 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8506 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 566:
#line 3049 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8514 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 567:
#line 3053 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while (kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8527 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 568:
#line 3064 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8535 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 569:
#line 3068 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while (kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8548 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 572:
#line 3083 "grammar.y" /* yacc.c:1661  */
    {
                    shadowing_lvar(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8557 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 573:
#line 3088 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = internal_id();
                  }
#line 8565 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 574:
#line 3094 "grammar.y" /* yacc.c:1661  */
    {
                    arg_var(get_id((yyvsp[-2].id)));
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8575 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 575:
#line 3102 "grammar.y" /* yacc.c:1661  */
    {
                    arg_var(get_id((yyvsp[-2].id)));
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8585 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 576:
#line 3110 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8593 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 577:
#line 3114 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8606 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 578:
#line 3125 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8614 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 579:
#line 3129 "grammar.y" /* yacc.c:1661  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8627 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 582:
#line 3144 "grammar.y" /* yacc.c:1661  */
    {
                    if(!is_local_id((yyvsp[0].id))) {
                      yy_error("rest argument must be local variable");
                    }
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8639 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 583:
#line 3152 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = internal_id();
                    arg_var((yyval.id));
                  }
#line 8648 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 586:
#line 3163 "grammar.y" /* yacc.c:1661  */
    {
                    if(!is_local_id((yyvsp[0].id)))
                      yy_error("block argument must be local variable");
                    else if(!in_block() && local_id((yyvsp[0].id)))
                      yy_error("duplicate block argument name");
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8661 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 587:
#line 3174 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8669 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 588:
#line 3178 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.id) = 0;
                  }
#line 8677 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 589:
#line 3184 "grammar.y" /* yacc.c:1661  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 8687 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 590:
#line 3189 "grammar.y" /* yacc.c:1661  */
    {lex_state = EXPR_BEG;}
#line 8693 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 591:
#line 3190 "grammar.y" /* yacc.c:1661  */
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
#line 8719 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 593:
#line 3215 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8727 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 595:
#line 3222 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_concat((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 8735 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 596:
#line 3228 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST((yyvsp[-2].node)), (yyvsp[0].node));
                  }
#line 8743 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 597:
#line 3232 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(NEW_LIT(ID2SYM((yyvsp[-1].id)))), (yyvsp[0].node));
                  }
#line 8751 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 598:
#line 3236 "grammar.y" /* yacc.c:1661  */
    {
                    (yyval.node) = list_append(NEW_LIST(0), (yyvsp[0].node));
                  }
#line 8759 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 620:
#line 3280 "grammar.y" /* yacc.c:1661  */
    {yyerrok;}
#line 8765 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 623:
#line 3285 "grammar.y" /* yacc.c:1661  */
    {yyerrok;}
#line 8771 "grammar.cpp" /* yacc.c:1661  */
    break;

  case 624:
#line 3288 "grammar.y" /* yacc.c:1661  */
    {(yyval.node) = 0;}
#line 8777 "grammar.cpp" /* yacc.c:1661  */
    break;


#line 8781 "grammar.cpp" /* yacc.c:1661  */
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
#line 3290 "grammar.y" /* yacc.c:1906  */


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
  const char *beg, *end, *pend;
  rb_encoding* enc = must_be_ascii_compatible(s);

  beg = RSTRING_PTR(s);
  if(lex_gets_ptr) {
    if(RSTRING_LEN(s) == lex_gets_ptr) return Qnil;
    beg += lex_gets_ptr;
  }
  pend = RSTRING_PTR(s) + RSTRING_LEN(s);
  end = beg;
  while(end < pend) {
    if(*end++ == '\n') break;
  }
  lex_gets_ptr = end - RSTRING_PTR(s);
  return REF(parser_enc_str_new(beg, end - beg, enc));
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

enum string_type {
  str_squote = (0),
  str_dquote = (STR_FUNC_EXPAND),
  str_xquote = (STR_FUNC_EXPAND),
  str_regexp = (STR_FUNC_REGEXP|STR_FUNC_ESCAPE|STR_FUNC_EXPAND),
  str_sword  = (STR_FUNC_QWORDS),
  str_dword  = (STR_FUNC_QWORDS|STR_FUNC_EXPAND),
  str_ssym   = (STR_FUNC_SYMBOL),
  str_dsym   = (STR_FUNC_SYMBOL|STR_FUNC_EXPAND),
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

static inline int
parser_nextc(rb_parser_state* parser_state)
{
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

static void
parser_pushback(rb_parser_state* parser_state, int c)
{
  if(c == -1) return;
  lex_p--;
}

/* Indicates if we're currently at the beginning of a line. */
#define was_bol() (lex_p == lex_pbeg + 1)

/* The token buffer. It's just a global string that has
   functions to build up the string easily. */

#define tokfix() (tokenbuf[tokidx]='\0')
#define tok() tokenbuf
#define toklen() tokidx
#define toklast() (tokidx>0?tokenbuf[tokidx-1]:0)

static char*
parser_newtok(rb_parser_state* parser_state)
{
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

static char *
parser_tokspace(rb_parser_state *parser_state, int n)
{
  tokidx += n;

  if(tokidx >= toksiz) {
    do {
      toksiz *= 2;
    } while(toksiz < tokidx);
    REALLOC_N(tokenbuf, char, toksiz);
  }
  return &tokenbuf[tokidx-n];
}


static void parser_tokadd(rb_parser_state* parser_state, char c)
{
  assert(tokidx < toksiz && tokidx >= 0);
  tokenbuf[tokidx++] = c;
  if(tokidx >= toksiz) {
    toksiz *= 2;
    REALLOC_N(tokenbuf, char, toksiz);
  }
}

static int
parser_tok_hex(rb_parser_state *parser_state, size_t *numlen)
{
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
parser_tokadd_utf8(rb_parser_state *parser_state, rb_encoding **encp,
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
  } else {			/* handle \uxxxx form */
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

static int
parser_read_escape(rb_parser_state *parser_state, int flags, rb_encoding **encp)
{
  int c;
  size_t numlen;

  switch(c = nextc()) {
  case '\\':	    /* Backslash */
    return c;

  case 'n':	      /* newline */
    return '\n';

  case 't':	      /* horizontal tab */
    return '\t';

  case 'r':	      /* carriage-return */
    return '\r';

  case 'f':	      /* form-feed */
    return '\f';

  case 'v':	      /* vertical tab */
    return '\13';

  case 'a':	      /* alarm(bell) */
    return '\007';

  case 'e':	      /* escape */
    return 033;

  case '0': case '1': case '2': case '3': /* octal constant */
  case '4': case '5': case '6': case '7':
    if(flags & (ESCAPE_CONTROL|ESCAPE_META)) goto eof;
    pushback(c);
    c = scan_oct(lex_p, 3, &numlen);
    lex_p += numlen;
    return c;

  case 'x':	    /* hex constant */
    if(flags & (ESCAPE_CONTROL|ESCAPE_META)) goto eof;
    c = tok_hex(&numlen);
    if(numlen == 0) return 0;
    return c;

  case 'b':	    /* backspace */
    return '\010';

  case 's':	    /* space */
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

static void
parser_tokaddmbc(rb_parser_state* parser_state, int c, rb_encoding *enc)
{
  int len = parser_enc_codelen(c, enc);
  parser_enc_mbcput(c, tokspace(len), enc);
}

static int
parser_tokadd_escape(rb_parser_state* parser_state, rb_encoding **encp)
{
  int c;
  int flags = 0;
  size_t numlen;

first:
  switch(c = nextc()) {
  case '\n':
    return 0;		/* just ignore */

  case '0': case '1': case '2': case '3': /* octal constant */
  case '4': case '5': case '6': case '7':
    if(flags & (ESCAPE_CONTROL|ESCAPE_META)) goto eof;
    {
      scan_oct(--lex_p, 3, &numlen);
      if(numlen == 0) goto eof;
      lex_p += numlen;
      tokcopy((int)numlen + 1);
    }
    return 0;

  case 'x':	/* hex constant */
    if(flags & (ESCAPE_CONTROL|ESCAPE_META)) goto eof;
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

static int
parser_regx_options(rb_parser_state* parser_state)
{
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

static int
parser_tokadd_mbchar(rb_parser_state *parser_state, int c)
{
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

static int
parser_tokadd_string(rb_parser_state *parser_state,
                     int func, int term, int paren, long *nest, rb_encoding **encp)
{
  int c;
  int has_nonascii = 0;
  rb_encoding *enc = *encp;
  char *errbuf = 0;
  static const char mixed_msg[] = "%s mixed within %s source";

#define mixed_error(enc1, enc2) if(!errbuf) {	\
    size_t len = sizeof(mixed_msg) - 4;	\
    len += strlen(parser_enc_name(enc1));	\
    len += strlen(parser_enc_name(enc2));	\
    errbuf = ALLOCA_N(char, len);		\
    snprintf(errbuf, len, mixed_msg, parser_enc_name(enc1), parser_enc_name(enc2));		\
    yy_error(errbuf);			\
  }

#define mixed_escape(beg, enc1, enc2) do {	\
    const char *pos = lex_p;		\
    lex_p = beg;				\
    mixed_error(enc1, enc2);		\
    lex_p = pos;				\
  } while(0)

  while((c = nextc()) != -1) {
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
      switch(c) {
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
        parser_tokadd_utf8(parser_state, &enc, 1, func & STR_FUNC_SYMBOL,
                           func & STR_FUNC_REGEXP);
        if(has_nonascii && enc != *encp) {
          mixed_escape(beg, enc, *encp);
        }
        continue;

      default:
        if(func & STR_FUNC_REGEXP) {
          pushback(c);
          if((c = tokadd_escape(&enc)) < 0)
          return -1;
          if(has_nonascii && enc != *encp) {
            mixed_escape(beg, enc, *encp);
          }
          continue;
        } else if(func & STR_FUNC_EXPAND) {
          pushback(c);
          if(func & STR_FUNC_ESCAPE) tokadd('\\');
          c = read_escape(0, &enc);
          if(!ISASCII(c)) {
            if(tokadd_mbchar(c) == -1) return -1;
            continue;
          }
        } else if((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
          /* ignore backslashed spaces in %w */
        } else if(c != term && !(paren && c == paren)) {
          tokadd('\\');
          pushback(c);
          continue;
        }
      }
    } else if(!parser_isascii()) {
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

static inline int
is_global_name_punct(const int c)
{
  if(c <= 0x20 || 0x7e < c) return 0;
  return (ruby_global_name_punct_bits[(c - 0x20) / 32] >> (c % 32)) & 1;
}

static int
parser_peek_variable_name(rb_parser_state* parser_state)
{
  int c;
  const char *p = lex_p;

  if(p + 1 >= lex_pend) return 0;
  c = *p++;
  switch(c) {
  case '$':
    if((c = *p) == '-') {
      if (++p >= lex_pend) return 0;
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

static int
parser_parse_string(rb_parser_state* parser_state, NODE *quote)
{
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
static int
parser_heredoc_identifier(rb_parser_state* parser_state)
{
  int c = nextc(), term, func = 0;
  size_t len;

  if(c == '-') {
    c = nextc();
    func = STR_FUNC_INDENT;
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
        pushback('-');
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

static void
parser_heredoc_restore(rb_parser_state* parser_state, NODE *here)
{
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
  if (suffix & NUM_SUFFIX_R) {
    v = rb_funcall(rb_cObject, rb_intern("Rational"), 1, v);
    type = tRATIONAL;
  }
  return set_number_literal(v, type, suffix);
}

/* Called when the lexer knows it's inside a heredoc. This function
   is responsible for detecting an expandions (ie #{}) in the heredoc
   and emitting a lex token and also detecting the end of the heredoc. */

static int
parser_here_document(rb_parser_state* parser_state, NODE *here)
{
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
    } while(!whole_match_p(eos, len, indent));
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

static int
arg_ambiguous()
{
  rb_warning("ambiguous first argument; put parentheses or even spaces");

  return 1;
}

static ID
parser_formal_argument(rb_parser_state* parser_state, ID lhs)
{
  if(!is_local_id(lhs)) {
    yy_error("formal argument must be local variable");
  }
  shadowing_lvar(lhs);
  return lhs;
}

static bool
parser_lvar_defined(rb_parser_state* parser_state, ID id) {
  return (in_block() && bv_defined(id)) || local_id(id);
}

static long
parser_encode_length(rb_parser_state* parser_state, const char *name, long len)
{
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

static int
comment_at_top(rb_parser_state* parser_state)
{
  const char *p = lex_pbeg, *pend = lex_p - 1;
  if(line_count != (has_shebang ? 2 : 1)) return FALSE;
  while(p < pend) {
    if (!ISSPACE(*p)) return FALSE;
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

static const struct magic_comment magic_comments[] = {
    {"coding", magic_comment_encoding, parser_encode_length},
    {"encoding", magic_comment_encoding, parser_encode_length},
};

static const char *
magic_comment_marker(const char *str, long len)
{
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

static int
parser_magic_comment(rb_parser_state* parser_state, const char *str, long len)
{
  VALUE name = 0, val = 0;
  const char *beg, *end, *vbeg, *vend;

#define str_copy(_s, _p, _n) ((_s) \
    ? (void)(rb_str_resize((_s), (_n)), \
    MEMCPY(RSTRING_PTR(_s), (_p), char, (_n)), (_s)) \
    : (void)((_s) = REF(STR_NEW((_p), (_n)))))

  if(len <= 7) return FALSE;
  if(!(beg = magic_comment_marker(str, len))) return FALSE;
  if(!(end = magic_comment_marker(beg, str + len - beg))) return FALSE;
  str = beg;
  len = end - beg - 3;

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
    if(*str != ':') continue;

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
    while(len > 0 && (*str == ';' || ISSPACE(*str))) --len, str++;

    n = end - beg;
    str_copy(name, beg, n);
    s = RSTRING_PTR(name);
    for(i = 0; i < n; ++i) {
      if(s[i] == '-') s[i] = '_';
    }
    do {
      if(strncasecmp(p->name, s, n) == 0) {
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
  case 0xef:		/* UTF-8 BOM marker */
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
#define IS_BEG()              lex_state_p(EXPR_BEG_ANY)
#define IS_SPCARG(c)          (IS_ARG() && space_seen && !ISSPACE(c))
#define IS_LABEL_POSSIBLE()   ((lex_state_p(EXPR_BEG | EXPR_ENDFN) && !cmd_state) \
                                || IS_ARG())
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

static int
parser_yylex(rb_parser_state *parser_state)
{
  int c;
  int space_seen = 0;
  int cmd_state;
  enum lex_state_e last_state;
  rb_encoding *enc;
  int mb;

  if(lex_strterm) {
    int token;
    if(nd_type(lex_strterm) == NODE_HEREDOC) {
      token = here_document(lex_strterm);
      if(token == tSTRING_END) {
        lex_strterm = 0;
        lex_state = EXPR_END;
      }
    } else {
      token = parse_string(lex_strterm);
      if(token == tSTRING_END || token == tREGEXP_END) {
        lex_strterm = 0;
        lex_state = EXPR_END;
      }
    }
    return token;
  }

  cmd_state = command_start;
  command_start = FALSE;
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
    /* no magic_comment in shebang line */
    if(!parser_magic_comment(parser_state, lex_p, lex_pend - lex_p)) {
      if(comment_at_top(parser_state)) {
        set_file_encoding(parser_state, lex_p, lex_pend);
      }
    }

    lex_p = lex_pend;
    /* fall through */
  case '\n':
    if(lex_state_p(EXPR_BEG | EXPR_VALUE | EXPR_CLASS | EXPR_FNAME | EXPR_DOT)) {
      goto retry;
    }

    while((c = nextc())) {
      switch(c) {
      case ' ': case '\t': case '\f': case '\r':
      case '\13': /* '\v' */
        space_seen = 1;
        break;
      case '.': {
        if((c = nextc()) != '.') {
          pushback(c);
          pushback('.');
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
    lex_state = EXPR_BEG;
    return '\n';

  case '*':
    if((c = nextc()) == '*') {
      if((c = nextc()) == '=') {
        set_yylval_id(tPOW);
        lex_state = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(c);
      if (IS_SPCARG(c)) {
        rb_warning0("`**' interpreted as argument prefix");
        c = tDSTAR;
      } else if (IS_BEG()) {
        c = tDSTAR;
      } else {
        warn_balanced("**", "argument prefix");
        c = tPOW;
      }
    } else {
      if(c == '=') {
        set_yylval_id('*');
        lex_state = EXPR_BEG;
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
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    return c;

  case '!':
    c = nextc();
    if(IS_AFTER_OPERATOR()) {
      lex_state = EXPR_ARG;
      if(c == '@') {
        return '!';
      }
    } else {
      lex_state = EXPR_BEG;
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
        for(;;) {
          lex_goto_eol(parser_state);
          c = nextc();
          if(c == -1) {
            rb_compile_error(parser_state, "embedded document meets end of file");
            return 0;
          }
          if(c != '=') continue;
          if(strncmp(lex_p, "end", 3) == 0 &&
              (lex_p + 3 == lex_pend || ISSPACE(lex_p[3]))) {
            break;
          }
        }
        lex_goto_eol(parser_state);
        goto retry;
      }
    }

    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
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
      (!IS_ARG() || space_seen)) {
      int token = heredoc_identifier();
      if(token) return token;
    }
    if(IS_AFTER_OPERATOR()) {
      lex_state = EXPR_ARG;
    } else {
      if(lex_state_p(EXPR_CLASS)) {
        command_start = TRUE;
      }
      lex_state = EXPR_BEG;
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
        lex_state = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(c);
      warn_balanced("<<", "here document");
      return tLSHFT;
    }
    pushback(c);
    return '<';

  case '>':
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    if((c = nextc()) == '=') {
      return tGEQ;
    }
    if(c == '>') {
      if((c = nextc()) == '=') {
        set_yylval_id(tRSHFT);
        lex_state = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(c);
      return tRSHFT;
    }
    pushback(c);
    return '>';

  case '"':
    lex_strterm = NEW_STRTERM(str_dquote, '"', 0);
    return tSTRING_BEG;

  case '`':
    if(lex_state_p(EXPR_FNAME)) {
      lex_state = EXPR_ENDFN;
      return c;
    }
    if(lex_state_p(EXPR_DOT)) {
      if(cmd_state) {
        lex_state = EXPR_CMDARG;
      } else {
        lex_state = EXPR_ARG;
      }
      return c;
    }
    lex_strterm = NEW_STRTERM(str_xquote, '`', 0);
    return tXSTRING_BEG;

  case '\'':
    lex_strterm = NEW_STRTERM(str_squote, '\'', 0);
    return tSTRING_BEG;

  case '?':
    if(IS_END()) {
      lex_state = EXPR_VALUE;
      return '?';
    }
    c = nextc();
    if(c == -1) {
      rb_compile_error(parser_state, "incomplete character syntax");
      return 0;
    }
    if(parser_enc_isspace(c, parser_state->enc)) {
      if(!IS_ARG()){
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
      lex_state = EXPR_VALUE;
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
    lex_state = EXPR_END;
    return tCHAR;

  case '&':
    if((c = nextc()) == '&') {
      lex_state = EXPR_BEG;
      if((c = nextc()) == '=') {
        set_yylval_id(tANDOP);
        lex_state = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(c);
      return tANDOP;
    } else if(c == '=') {
      set_yylval_id('&');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
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
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    return c;

  case '|':
    if((c = nextc()) == '|') {
      lex_state = EXPR_BEG;
      if((c = nextc()) == '=') {
        set_yylval_id(tOROP);
        lex_state = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(c);
      return tOROP;
    }
    if(c == '=') {
      set_yylval_id('|');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
    }
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    pushback(c);
    return '|';

  case '+':
    c = nextc();
    if(IS_AFTER_OPERATOR()) {
      lex_state = EXPR_ARG;
      if(c == '@') {
        return tUPLUS;
      }
      pushback(c);
      return '+';
    }
    if(c == '=') {
      set_yylval_id('+');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
    }
    if(IS_BEG() || (IS_SPCARG(c) && arg_ambiguous())) {
      lex_state = EXPR_BEG;
      pushback(c);
      if(c != -1 && ISDIGIT(c)) {
        c = '+';
        goto start_num;
      }
      return tUPLUS;
    }
    lex_state = EXPR_BEG;
    pushback(c);
    warn_balanced("+", "unary operator");
    return '+';

  case '-':
    c = nextc();
    if(IS_AFTER_OPERATOR()) {
      lex_state = EXPR_ARG;
      if(c == '@') {
        return tUMINUS;
      }
      pushback(c);
      return '-';
    }
    if(c == '=') {
      set_yylval_id('-');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
    }
    if(c == '>') {
      lex_state = EXPR_ENDFN;
      return tLAMBDA;
    }
    if(IS_BEG() || (IS_SPCARG(c) && arg_ambiguous())) {
      lex_state = EXPR_BEG;
      pushback(c);
      if(c != -1 && ISDIGIT(c)) {
        return tUMINUS_NUM;
      }
      return tUMINUS;
    }
    lex_state = EXPR_BEG;
    pushback(c);
    warn_balanced("-", "unary operator");
    return '-';

  case '.':
    lex_state = EXPR_BEG;
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
    lex_state = EXPR_DOT;
    return '.';

  start_num:
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    {
      int is_float, seen_point, seen_e, nondigit, suffix;

      is_float = seen_point = seen_e = nondigit = 0;
      lex_state = EXPR_END;
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

        case '_':      /* `_' in number just ignored */
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
        char *point = &tok()[seen_point];
        size_t fraclen = toklen()-seen_point-1;
        type = tRATIONAL;
        memmove(point, point+1, fraclen+1);
        v = rb_cstr_to_inum(tok(), 10, FALSE);
        v = rb_rational_new(v,
              rb_funcall(INT2FIX(10), rb_intern("**"), 1, INT2NUM(fraclen)));
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

  case ')':
  case ']':
    paren_nest--;
  case '}':
    COND_LEXPOP();
    CMDARG_LEXPOP();
    if(c == ')') {
      lex_state = EXPR_ENDFN;
    } else {
      lex_state = EXPR_ENDARG;
    }
    if(c == '}') {
      if (!brace_nest--) c = tSTRING_DEND;
    }
    return c;

  case ':':
    c = nextc();
    if(c == ':') {
      if(IS_BEG() || lex_state_p(EXPR_CLASS) || IS_SPCARG(-1)) {
        lex_state = EXPR_BEG;
        return tCOLON3;
      }
      lex_state = EXPR_DOT;
      return tCOLON2;
    }
    if(IS_END() || ISSPACE(c)) {
      pushback(c);
      warn_balanced(":", "symbol literal");
      lex_state = EXPR_BEG;
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
    lex_state = EXPR_FNAME;
    return tSYMBEG;

  case '/':
    if(lex_state_p(EXPR_BEG_ANY)) {
      lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if((c = nextc()) == '=') {
      set_yylval_id('/');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
    }
    pushback(c);
    if(IS_SPCARG(c)) {
      (void)arg_ambiguous();
      lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    warn_balanced("/", "regexp literal");
    return '/';

  case '^':
    if((c = nextc()) == '=') {
      set_yylval_id('^');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
    }
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    pushback(c);
    return '^';

  case ';':
    lex_state = EXPR_BEG;
    command_start = TRUE;
    return ';';

  case ',':
    lex_state = EXPR_BEG;
    return ',';

  case '~':
    if(IS_AFTER_OPERATOR()) {
      if((c = nextc()) != '@') {
        pushback(c);
      }
      lex_state = EXPR_ARG;
    } else {
      lex_state = EXPR_BEG;
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
    lex_state = EXPR_BEG;
    return c;

  case '[':
    paren_nest++;
    if(IS_AFTER_OPERATOR()) {
      lex_state = EXPR_ARG;
      if((c = nextc()) == ']') {
        if((c = nextc()) == '=') {
          return tASET;
        }
        pushback(c);
        return tAREF;
      }
      pushback(c);
      return '[';
    } else if(IS_BEG()) {
      c = tLBRACK;
    } else if(IS_ARG() && space_seen) {
      c = tLBRACK;
    }
    lex_state = EXPR_BEG;
    COND_PUSH(0);
    CMDARG_PUSH(0);
    return c;

  case '{':
    ++brace_nest;
    if(lpar_beg && lpar_beg == paren_nest) {
      lex_state = EXPR_BEG;
      lpar_beg = 0;
      --paren_nest;
      COND_PUSH(0);
      CMDARG_PUSH(0);
      return tLAMBEG;
    }
    if(IS_ARG() || lex_state_p(EXPR_END | EXPR_ENDFN)) {
      c = '{';          /* block (primary) */
    } else if(lex_state_p(EXPR_ENDARG)) {
      c = tLBRACE_ARG;  /* block (expr) */
    } else {
      c = tLBRACE;      /* hash */
    }
    COND_PUSH(0);
    CMDARG_PUSH(0);
    lex_state = EXPR_BEG;
    if(c != tLBRACE) command_start = TRUE;
    return c;

  case '\\':
    c = nextc();
    if(c == '\n') {
      space_seen = 1;
      goto retry; /* skip \\n */
    }
    pushback(c);
    return '\\';

  case '%':
    if(lex_state_p(EXPR_BEG_ANY)) {
      intptr_t term;
      intptr_t paren;

      c = nextc();
    quotation:
      if(c == -1 || !ISALNUM(c)) {
        term = c;
        c = 'Q';
      } else {
        term = nextc();
        if(parser_enc_isalnum((int)term, parser_state->enc) || !parser_isascii()) {
          yy_error("unknown type of % string");
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
        do {c = nextc();} while (ISSPACE(c));
        pushback(c);
        return tSYMBOLS_BEG;

      case 'i':
        lex_strterm = NEW_STRTERM(str_sword, term, paren);
        do {c = nextc();} while (ISSPACE(c));
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
        lex_state = EXPR_FNAME;
        return tSYMBEG;

      default:
        yy_error("unknown type of % string");
        return 0;
      }
    }
    if((c = nextc()) == '=') {
      set_yylval_id('%');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
    }
    if(IS_SPCARG(c)) {
      goto quotation;
    }
    lex_state = IS_AFTER_OPERATOR() ? EXPR_ARG : EXPR_BEG;
    pushback(c);
    warn_balanced("%%", "string literal");
    return '%';

  case '$':
    lex_state = EXPR_END;
    newtok();
    c = nextc();
    switch(c) {
    case '_':             /* $_: last read line string */
      c = nextc();
      if(parser_is_identchar()) {
        tokadd('$');
        tokadd('_');
        break;
      }
      pushback(c);
      c = '_';
      /* fall through */
    case '~':   /* $~: match-data */
    case '*':   /* $*: argv */
    case '$':   /* $$: pid */
    case '?':   /* $?: last status */
    case '!':   /* $!: error string */
    case '@':   /* $@: error position */
    case '/':   /* $/: input record separator */
    case '\\':  /* $\: output record separator */
    case ';':   /* $;: field separator */
    case ',':   /* $,: output field separator */
    case '.':   /* $.: last read line number */
    case '=':   /* $=: ignorecase */
    case ':':   /* $:: load path */
    case '<':   /* $<: reading filename */
    case '>':   /* $>: default output handle */
    case '\"':  /* $": already loaded files */
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
      // TODO rb_intern3(tok(), tokidx, current_enc);
      set_yylval_name(parser_intern(tok()));
      return tGVAR;

    case '&':             /* $&: last match */
    case '`':             /* $`: string before last match */
    case '\'':            /* $': string after last match */
    case '+':             /* $+: string matches last paren. */
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
      set_yylval_node(NEW_NTH_REF(atoi(tok()+1)));
      return tNTH_REF;

    default:
      if(!parser_is_identchar()) {
        pushback(c);
        rb_compile_error(parser_state,
                         "`$%c' is not allowed as a global variable name", c);
        return 0;
      }
    case '0':
      tokadd('$');
    }
    break;

  case '@':
    c = nextc();
    newtok();
    tokadd('@');
    if(c == '@') {
      tokadd('@');
      c = nextc();
    }
    if(c != -1 && (ISDIGIT(c) || !parser_is_identchar())) {
      if(tokidx == 1) {
        rb_compile_error(parser_state,
                         "`@%c' is not allowed as an instance variable name", c);
      } else {
        rb_compile_error(parser_state,
                         "`@@%c' is not allowed as a class variable name", c);
      }
      return 0;
    }
    break;

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

  mb = ENC_CODERANGE_7BIT;
  do {
    if(!ISASCII(c)) mb = ENC_CODERANGE_UNKNOWN;
    if(tokadd_mbchar(c) == -1) return 0;
    c = nextc();
  } while(parser_is_identchar());
  switch(tok()[0]) {
  case '@': case '$':
    pushback(c);
    break;
  default:
    if((c == '!' || c == '?') && !peek('=')) {
      tokadd(c);
    } else {
      pushback(c);
    }
  }
  tokfix();
  {
    int result = 0;

    last_state = lex_state;
    switch(tok()[0]) {
    case '$':
      lex_state = EXPR_END;
      result = tGVAR;
      break;
    case '@':
      lex_state = EXPR_END;
      if(tok()[1] == '@') {
        result = tCVAR;
      } else {
        result = tIVAR;
      }
      break;
    default:
      if(toklast() == '!' || toklast() == '?') {
        result = tFID;
      } else {
        if(lex_state_p(EXPR_FNAME)) {
          if((c = nextc()) == '=' && !peek('~') && !peek('>') &&
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
          lex_state = EXPR_BEG;
          nextc();
          set_yylval_name(TOK_INTERN(!ENC_SINGLE(mb)));
          return tLABEL;
        }
      }
      if(mb == ENC_CODERANGE_7BIT && lex_state != EXPR_DOT) {
        const struct kwtable *kw;

        /* See if it is a reserved word.  */
        kw = reserved_word(tok(), toklen());
        if(kw) {
          enum lex_state_e state = lex_state;
          lex_state = kw->state;
          if(lex_state_of_p(state, EXPR_FNAME)) {
            set_yylval_name(parser_intern(kw->name));
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
            if(CMDARG_P() && !lex_state_of_p(state, EXPR_CMDARG))
              return keyword_do_block;
            if(lex_state_of_p(state, EXPR_BEG | EXPR_ENDARG))
              return keyword_do_block;
            return keyword_do;
          }
          if(lex_state_of_p(state, EXPR_BEG | EXPR_VALUE))
            return kw->id[0];
          else {
            if(kw->id[0] != kw->id[1])
              lex_state = EXPR_BEG;
            return kw->id[1];
          }
        }
      }

      if(lex_state_p(EXPR_BEG_ANY | EXPR_ARG_ANY | EXPR_DOT)) {
        if(cmd_state) {
          lex_state = EXPR_CMDARG;
        } else {
          lex_state = EXPR_ARG;
        }
      } else if(lex_state == EXPR_FNAME) {
        lex_state = EXPR_ENDFN;
      } else {
        lex_state = EXPR_END;
      }
    }
    {
      ID ident = TOK_INTERN(!ENC_SINGLE(mb));

      set_yylval_name(ident);
      if(!lex_state_of_p(last_state, EXPR_DOT | EXPR_FNAME) &&
          is_local_id(ident) && lvar_defined(ident)) {
        lex_state = EXPR_END;
      }
    }

    return result;
  }
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
      if (!literal_concat0(lit, tail->nd_lit))
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
  {tDOT2,	  ".."},
  {tDOT3,	  "..."},
  {tPOW,	  "**"},
  {tDSTAR,  "**"},
  {tUPLUS,	"+@"},
  {tUMINUS,	"-@"},
  {tCMP,	  "<=>"},
  {tGEQ,	  ">="},
  {tLEQ,	  "<="},
  {tEQ,	    "=="},
  {tEQQ,	  "==="},
  {tNEQ,	  "!="},
  {tMATCH,	"=~"},
  {tNMATCH,	"!~"},
  {tAREF,	  "[]"},
  {tASET,	  "[]="},
  {tLSHFT,	"<<"},
  {tRSHFT,	">>"},
  {tCOLON2,	"::"},

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
  "",				/* INSTANCE2 */
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
    switch (id) {
    case tAREF:
    case tASET:
      return tASET;	/* only exception */
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
parser_attrset(rb_parser_state* parser_state, NODE *recv, ID id)
{
  if(recv && nd_type(recv) == NODE_SELF) {
    recv = (NODE *)1;
  }
  return NEW_ATTRASGN(recv, rb_id_attrset(id), 0);
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
parser_new_attr_op_assign(rb_parser_state* parser_state,
                          NODE *lhs, ID attr, ID op, NODE *rhs)
{
  NODE *asgn;

  if(op == tOROP) {
    op = 0;
  } else if(op == tANDOP) {
    op = 1;
  } else {
    op = convert_op(op);
  }
  asgn = NEW_OP_ASGN2(lhs, attr, op, rhs);
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
  locals_table = local;
}

static void
parser_local_pop(rb_parser_state* parser_state)
{
  struct local_vars *local = locals_table->prev;
  vtable_free(locals_table->args);
  vtable_free(locals_table->vars);
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
parser_internal_id(rb_parser_state *parser_state)
{
  ID id = (ID)vtable_size(locals_table->args) + (ID)vtable_size(locals_table->vars);
  id += ((tLAST_TOKEN - ID_INTERNAL) >> ID_SCOPE_SHIFT) + 1;
  return ID_INTERNAL | (id << ID_SCOPE_SHIFT);
}

};
