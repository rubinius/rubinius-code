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


#line 478 "grammar.cpp" /* yacc.c:339  */

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
    tLABEL_END = 369,
    tLOWEST = 370,
    tUMINUS_NUM = 371,
    tLAST_TOKEN = 372
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 429 "grammar.y" /* yacc.c:355  */

    VALUE val;
    NODE *node;
    ID id;
    int num;
    const struct vtable* vars;

#line 641 "grammar.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (rb_parser_state* parser_state);



/* Copy the second part of user declarations.  */

#line 657 "grammar.cpp" /* yacc.c:358  */

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
#define YYLAST   11164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  145
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  201
/* YYNRULES -- Number of rules.  */
#define YYNRULES  625
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1060

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     144,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   143,   130,     2,     2,     2,   128,   123,     2,
     139,   140,   126,   124,   137,   125,   136,   127,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   118,   142,
     120,   116,   119,   117,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   141,   122,     2,   138,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   133,   121,   134,   131,     2,     2,     2,
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
     115,   129,   132
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   580,   580,   580,   605,   612,   616,   620,   624,   630,
     632,   631,   643,   666,   673,   677,   681,   685,   691,   696,
     695,   705,   705,   709,   713,   720,   725,   729,   734,   739,
     747,   755,   760,   769,   770,   776,   781,   798,   803,   808,
     813,   818,   823,   828,   833,   836,   841,   848,   849,   853,
     857,   861,   865,   868,   876,   877,   880,   881,   888,   887,
     902,   909,   914,   922,   927,   934,   939,   946,   951,   956,
     960,   964,   970,   971,   977,   978,   984,   988,   992,   996,
    1000,  1004,  1008,  1012,  1016,  1020,  1026,  1027,  1033,  1037,
    1043,  1047,  1053,  1057,  1061,  1065,  1069,  1073,  1077,  1083,
    1089,  1096,  1101,  1106,  1110,  1114,  1118,  1122,  1128,  1134,
    1141,  1145,  1148,  1152,  1156,  1162,  1163,  1164,  1165,  1170,
    1177,  1178,  1181,  1185,  1188,  1192,  1192,  1198,  1199,  1200,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1226,  1227,  1230,  1230,  1230,
    1231,  1231,  1232,  1232,  1232,  1233,  1233,  1233,  1233,  1234,
    1234,  1234,  1234,  1235,  1235,  1235,  1236,  1236,  1236,  1236,
    1237,  1237,  1237,  1237,  1238,  1238,  1238,  1238,  1239,  1239,
    1239,  1239,  1240,  1240,  1240,  1240,  1241,  1241,  1244,  1249,
    1255,  1260,  1266,  1287,  1292,  1297,  1302,  1307,  1312,  1317,
    1323,  1329,  1333,  1337,  1341,  1345,  1349,  1353,  1357,  1361,
    1365,  1369,  1373,  1377,  1381,  1385,  1389,  1393,  1397,  1401,
    1405,  1409,  1419,  1423,  1427,  1431,  1435,  1439,  1443,  1447,
    1447,  1452,  1458,  1464,  1472,  1473,  1477,  1481,  1487,  1493,
    1494,  1497,  1498,  1499,  1503,  1507,  1513,  1518,  1522,  1527,
    1532,  1535,  1535,  1547,  1553,  1557,  1563,  1567,  1571,  1580,
    1591,  1592,  1595,  1604,  1613,  1619,  1620,  1621,  1622,  1623,
    1624,  1625,  1626,  1627,  1628,  1629,  1634,  1633,  1653,  1653,
    1657,  1657,  1661,  1665,  1669,  1673,  1681,  1685,  1689,  1693,
    1697,  1701,  1701,  1706,  1710,  1714,  1720,  1721,  1728,  1732,
    1740,  1748,  1748,  1748,  1755,  1755,  1755,  1762,  1769,  1774,
    1776,  1773,  1793,  1792,  1809,  1814,  1808,  1831,  1830,  1847,
    1846,  1864,  1865,  1864,  1880,  1884,  1888,  1892,  1898,  1906,
    1912,  1918,  1924,  1930,  1936,  1942,  1948,  1954,  1960,  1967,
    1973,  1974,  1975,  1978,  1979,  1982,  1983,  1992,  1993,  1999,
    2000,  2003,  2007,  2013,  2017,  2023,  2027,  2032,  2037,  2041,
    2045,  2050,  2055,  2059,  2065,  2069,  2073,  2077,  2083,  2088,
    2093,  2097,  2101,  2105,  2109,  2113,  2117,  2121,  2125,  2129,
    2133,  2137,  2141,  2145,  2149,  2155,  2156,  2162,  2167,  2171,
    2178,  2182,  2189,  2194,  2201,  2207,  2213,  2216,  2221,  2213,
    2233,  2237,  2243,  2247,  2254,  2253,  2268,  2279,  2283,  2290,
    2299,  2306,  2305,  2315,  2314,  2323,  2328,  2327,  2337,  2336,
    2345,  2349,  2353,  2365,  2364,  2377,  2376,  2390,  2398,  2399,
    2402,  2414,  2417,  2421,  2425,  2428,  2432,  2435,  2439,  2442,
    2443,  2447,  2450,  2462,  2463,  2464,  2470,  2476,  2498,  2558,
    2562,  2569,  2572,  2578,  2579,  2585,  2589,  2596,  2599,  2607,
    2611,  2617,  2621,  2628,  2631,  2638,  2641,  2652,  2655,  2662,
    2665,  2672,  2675,  2698,  2700,  2699,  2711,  2717,  2722,  2710,
    2738,  2739,  2740,  2741,  2744,  2751,  2752,  2753,  2754,  2757,
    2764,  2765,  2771,  2772,  2773,  2774,  2777,  2778,  2779,  2780,
    2781,  2784,  2785,  2786,  2787,  2788,  2789,  2790,  2793,  2799,
    2807,  2811,  2817,  2818,  2821,  2826,  2825,  2834,  2841,  2847,
    2855,  2859,  2863,  2867,  2873,  2878,  2883,  2887,  2891,  2895,
    2899,  2903,  2907,  2911,  2915,  2919,  2923,  2927,  2931,  2935,
    2940,  2946,  2951,  2956,  2961,  2968,  2969,  2976,  2981,  2991,
    2992,  3000,  3007,  3012,  3019,  3024,  3031,  3035,  3046,  3050,
    3061,  3062,  3065,  3070,  3076,  3084,  3092,  3096,  3107,  3111,
    3122,  3123,  3126,  3134,  3141,  3142,  3145,  3156,  3160,  3166,
    3172,  3172,  3196,  3197,  3203,  3204,  3210,  3214,  3218,  3222,
    3228,  3229,  3230,  3233,  3234,  3235,  3236,  3239,  3240,  3241,
    3244,  3245,  3248,  3249,  3252,  3253,  3256,  3259,  3262,  3263,
    3264,  3267,  3268,  3271,  3272,  3275
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
  "tSTRING_END", "tLAMBEG", "tLABEL_END", "tLOWEST", "'='", "'?'", "':'",
  "'>'", "'<'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "tUMINUS_NUM", "'!'", "'~'", "tLAST_TOKEN", "'{'", "'}'", "'['", "'.'",
  "','", "'`'", "'('", "')'", "']'", "';'", "' '", "'\\n'", "$accept",
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
  "$@18", "@19", "@20", "@21", "@22", "@23", "$@24", "$@25",
  "primary_value", "k_begin", "k_if", "k_unless", "k_while", "k_until",
  "k_case", "k_for", "k_class", "k_module", "k_def", "k_end", "then", "do",
  "if_tail", "opt_else", "for_var", "f_marg", "f_marg_list", "f_margs",
  "block_args_tail", "opt_block_args_tail", "block_param",
  "opt_block_param", "block_param_def", "opt_bv_decl", "bv_decls", "bvar",
  "lambda", "@26", "@27", "@28", "f_larglist", "lambda_body", "do_block",
  "@29", "block_call", "method_call", "@30", "@31", "@32", "@33",
  "brace_block", "@34", "@35", "case_body", "cases", "opt_rescue",
  "exc_list", "exc_var", "opt_ensure", "literal", "strings", "string",
  "string1", "xstring", "regexp", "words", "word_list", "word", "symbols",
  "symbol_list", "qwords", "qsymbols", "qword_list", "qsym_list",
  "string_contents", "xstring_contents", "regexp_contents",
  "string_content", "@36", "@37", "@38", "@39", "string_dvar", "symbol",
  "sym", "dsym", "numeric", "simple_numeric", "user_variable",
  "keyword_variable", "var_ref", "var_lhs", "backref", "superclass",
  "$@40", "f_arglist", "args_tail", "opt_args_tail", "f_args", "f_bad_arg",
  "f_norm_arg", "f_arg_item", "f_arg", "f_label", "f_kw", "f_block_kw",
  "f_block_kwarg", "f_kwarg", "kwrest_mark", "f_kwrest", "f_opt",
  "f_block_opt", "f_block_optarg", "f_optarg", "restarg_mark",
  "f_rest_arg", "blkarg_mark", "f_block_arg", "opt_f_block_arg",
  "singleton", "$@41", "assoc_list", "assocs", "assoc", "operation",
  "operation2", "operation3", "dot_or_colon", "opt_terms", "opt_nl",
  "rparen", "rbracket", "trailer", "term", "terms", "none", YY_NULLPTR
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
     365,   366,   367,   368,   369,   370,    61,    63,    58,    62,
      60,   124,    94,    38,    43,    45,    42,    47,    37,   371,
      33,   126,   372,   123,   125,    91,    46,    44,    96,    40,
      41,    93,    59,    32,    10
};
# endif

#define YYPACT_NINF -807

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-807)))

#define YYTABLE_NINF -626

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-626)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -807,    92,  2799,  -807,  7521,  -807,  -807,  -807,  7032,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  7637,  7637,  -807,  -807,
    7637,  4151,  3737,  -807,  -807,  -807,  -807,     1,  6896,   -19,
    -807,    20,  -807,  -807,  -807,  3047,  3875,  -807,  -807,  3185,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  9029,  9029,
     147,  5227,  9145,  7985,  8333,  7297,  -807,  6760,  -807,  -807,
    -807,    84,   151,   238,   243,   984,  9261,  9029,  -807,     0,
    -807,   880,  -807,   406,  -807,  -807,    74,   184,   274,  -807,
     291,  9377,  -807,   338,  3163,    32,    37,  -807,  9145,  9145,
    -807,  -807,  6135,  9489,  9601,  9713,  6623,    26,    69,  -807,
    -807,   356,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,   201,   430,  -807,   380,   521,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   336,  -807,
    -807,  -807,  -807,   370,  9029,   469,  5369,  9029,  9029,  9029,
    -807,  9029,  -807,   413,  3163,   443,  -807,  -807,   398,   286,
     204,   242,   465,   401,   420,  -807,  -807,  -807,  6019,  -807,
    7637,  7637,  -807,  -807,  6251,  -807,  9145,    66,  -807,   424,
     452,  5511,  -807,  -807,  -807,   450,   467,    74,  -807,   317,
     542,   633,  7753,  -807,  5227,   462,     0,  -807,   880,   -19,
     498,  -807,   406,   -19,   474,    -1,   228,  -807,   443,   484,
     228,  -807,   -19,   575,   984,  9825,   495,  -807,   327,   378,
     440,   553,  -807,  -807,  -807,  -807,  -807,  -807,   524,  -807,
     532,   620,   786,   540,   632,   566,    53,   572,   705,   596,
      67,   602,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  6367,
    9145,  9145,  9145,  9145,  7753,  9145,  9145,  -807,  -807,  -807,
     595,  -807,  -807,  -807,  8449,  -807,  5227,  7409,   588,  8449,
    9029,  9029,  9029,  9029,  9029,  9029,  9029,  9029,  9029,  9029,
    9029,  9029,  9029,  9029,  9029,  9029,  9029,  9029,  9029,  9029,
    9029,  9029,  9029,  9029,  9029,  9029,  2244,  7637, 10111,  4569,
     406,   141,   141,  9145,  9145,     0,   721,   585,   686,  -807,
    -807,   574,   722,    44,    80,   103,   361,   408,  9145,   308,
    -807,   182,   579,  -807,  -807,  -807,  -807,   146,   218,   240,
     248,   280,   345,   353,   455,   463,  -807,  -807,  -807,    26,
    -807,  -807, 10191,  -807,  -807,  9261,  9261,  -807,  -807,   421,
    -807,  -807,  -807,   516,  9029,  9029,  7869,  -807,  -807, 10271,
    7637, 10351,  9029,  9029,  8101,  -807,   -19,   606,  -807,  -807,
     -19,  -807,   611,   615,  -807,   388,  -807,  -807,  -807,  -807,
    -807,  7032,  -807,  9029,  5645,   622, 10271, 10351,  9029,   880,
     628,   -19,  -807,  -807,  6483,   627,   -19,  -807,  -807,  8217,
    -807,  -807,  8333,  -807,  -807,  -807,   424,   599,  -807,  -807,
     630,  9825, 10431,  7637, 10511,   916,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,    55,  -807,
    -807,   631,  -807,  -807,  -807,   508,  -807,   636,  -807,  9029,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   226,
     226,  -807,  -807,   226,  9029,  -807,   639,   644,  -807,  -807,
     -19,  9825,   651,  -807,  -807,  -807,   675,  2887,  -807,  -807,
     542,  3439,  3439,  3439,  3439,   577,   577,  3577,  2001,  3439,
    3439,  3301,  3301,   496,   496, 11020,   577,   577,   758,   758,
     791,   446,   446,   542,   542,   542,  4289,  3323,  4427,  3461,
     467,   653,  -807,   -19,   673,  -807,   710,  -807,   467,  4013,
     803,   811,  -807,  4711,   807,  4995,    64,    64,   721,  8565,
     803,   113, 10591,  7637, 10671,  -807,   406,  -807,   599,  -807,
       0,  -807,  -807,  -807, 10751,  7637, 10191,  4569,  9145,  1219,
    -807,  -807,  -807,  1221,  -807,  1436,  -807,  3163,  7032,  9029,
    3025,  -807,  9029,   443,  -807,   420,  2909,  3599,   -19,   560,
     604,  -807,  -807,  -807,  -807,  7869,  8101,  -807,  -807,  9145,
    3163,   689,  -807,  -807,  -807,  3163,  5645,    19,  -807,  -807,
     228,  9825,   630,   425,    16,   -19,    98,   283,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   902,  -807,  -807,  -807,  -807,
    -807,  1624,  -807,  -807,  -807,  -807,   708,  -807,   688,  9029,
    -807,   690,   780,   709,  -807,   711,   793,   717,   805,  -807,
    -807,   883,  -807,  -807,  -807,  -807,  -807,   542,  -807,  1197,
    5787,  -807,  -807,  5511,   226,  5787,   718,  8681,  -807,   630,
    9825,  9261,  9029,   741,  9261,  9261,  -807,   595,   467,   719,
     713,  9261,  9261,  -807,   595,   467,  -807,  -807,  8797,   847,
    -807,   582,  -807,   847,  -807,  -807,  -807,  -807,   803,   202,
    -807,   102,   172,   -19,   116,   185,  9145,     0,  -807,  9145,
    4569,   425,    16,  -807,   -19,   803,   388,  1624,  4569,     0,
    7168,  -807,    69,   184,  -807,  9029,  -807,  -807,  -807,  -807,
    9029,  9029,   617,  9029,  9029,   727,   388,  -807,   732,  -807,
    -807,   472,   902,   381,  -807,   730,   -19,  -807,   -19,    77,
    9029,  1624,  -807,  -807,   422,  -807,  -807,  -807,    27,  -807,
    1624,  -807,  -807,  1079,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,   -19,   751,   754,   738,  9937,  -807,   743,
     709,  -807,   753,   755,  -807,   736,   878,   759,  5511,   886,
    9029,   761,   630,  3163,  9029,  -807,  3163,  -807,  3163,  -807,
    -807,  -807,  9261,  -807,  3163,  -807,  3163,  -807,  -807,   639,
    -807,   809,  -807,  5111,   892,  -807,  9145,   803,  -807,   803,
    5787,  5787,  -807,  8913,  4853,   276,    64,  -807,     0,   803,
    -807,  -807,  -807,   -19,   803,  -807,  -807,  -807,  -807,  3163,
    9029,  8101,  -807,  -807,   -19,   855,   766,   940,  -807,   764,
    5787,  5511,  -807,  -807,  -807,  -807,   768,   776,  -807,   709,
    -807,   790,  -807,   792,  -807,   790,  5903,   813,  -807,  9937,
    1624,  -807,   874,   649,   422,  -807,  -807,  1624,  -807,  1079,
    -807,   971,  -807,  -807,   801,  -807,   806,  3163,  -807,  3163,
   10049,   141,  -807,  -807,  5787,  -807,  -807,   141,  -807,  -807,
     803,   803,  -807,   442,  -807,  4569,  -807,  -807,  -807,  -807,
    1219,  -807,   808,   855,   449,  -807,  -807,   932,   810,  1624,
    -807,  1079,  -807,  -807,  1079,  -807,  1079,  -807,  -807,   840,
    -807,   649,  -807,   816,   824,  -807, 10831,  -807,   709,   827,
    -807,   828,   827,  -807,   830,  -807,  -807,  -807,   919,  -807,
     668,   378,   440,   553,  4569,  -807,  4711,  -807,  -807,  -807,
    -807,  -807,  5787,   803,  4569,   855,   808,   855,   839,  -807,
    -807,   790,   845,   790,   790,  -807,  1624,  -807,  1079,  -807,
     850,   852,  -807,  1079,  -807,  1079,  -807,  -807,   971,   599,
   10911,  7637, 10991,   811,   582,   803,  -807,   803,   808,   855,
    -807,  1079,  -807,  -807,  -807,   827,   861,   827,   827,  -807,
     186,    16,   -19,   207,   219,  -807,  -807,  -807,  -807,   808,
     790,  -807,  1079,  -807,  -807,  -807,   259,  -807,   827,  -807
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,   346,   347,   348,     0,   339,
     340,   341,   344,   342,   343,   345,   334,   335,   336,   337,
     297,   261,   261,   512,   511,   513,   514,   614,     0,   614,
      10,     0,   516,   515,   517,   600,   602,   508,   507,   601,
     510,   502,   503,   504,   505,   453,   522,   523,     0,     0,
       0,     0,   288,   625,   625,    84,   406,   479,   477,   479,
     481,   461,   473,   467,   475,     0,     0,     0,     3,   612,
       6,     9,    33,    44,    47,    55,   261,    54,     0,    72,
       0,    76,    86,     0,    52,   242,     0,   286,     0,     0,
     311,   314,   612,     0,     0,     0,     0,    56,   306,   275,
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
     477,     0,   256,     0,   243,   266,    70,   260,   625,     0,
     518,   519,     0,   284,   625,   594,    71,    69,   614,    68,
       0,   625,   430,    67,   614,   615,     0,     0,    21,   239,
       0,     0,   334,   335,   297,   300,   431,     0,   218,     0,
     219,   294,     0,    19,     0,     0,   612,    15,    18,   614,
      74,    14,   290,   614,     0,   618,   618,   244,     0,     0,
     618,   592,   614,     0,     0,     0,    82,   338,     0,    92,
      93,   100,   308,   407,   497,   496,   498,   495,     0,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,    51,   233,   234,   621,   622,     4,   623,   613,
       0,     0,     0,     0,     0,     0,     0,   435,   433,   420,
      61,   305,   414,   416,     0,    88,     0,    80,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,   625,   426,     0,
      53,     0,     0,     0,     0,   612,     0,   613,     0,   360,
     359,     0,     0,   518,   519,   284,   110,   111,     0,     0,
     113,     0,     0,   518,   519,   284,   327,   187,   180,   190,
     175,   157,   158,   159,   115,   116,   590,   329,   589,     0,
     611,   610,     0,   307,   455,     0,     0,   125,   597,   294,
     267,   599,   263,     0,     0,     0,     0,   257,   265,   428,
     625,   426,     0,     0,     0,   258,   614,     0,   299,   262,
     614,   252,   625,   625,   251,   614,   304,    50,    23,    25,
      24,     0,   301,     0,     0,     0,   428,   426,     0,    17,
       0,   614,   292,    13,   613,    73,   614,   289,   295,   620,
     619,   245,   620,   247,   296,   593,     0,    99,   501,    90,
      85,     0,   428,   625,   426,   550,   483,   486,   484,   499,
     480,   456,   478,   457,   458,   482,   459,   460,     0,   463,
     469,     0,   470,   465,   466,     0,   471,     0,   472,     0,
     624,     7,    27,    28,    29,    30,    31,    48,    49,   625,
     625,    58,    62,   625,     0,    34,   271,     0,    43,   270,
     614,     0,    78,    89,    46,    45,     0,   198,   266,    42,
     216,   223,   228,   229,   230,   225,   227,   237,   238,   231,
     232,   209,   210,   235,   236,   614,   224,   226,   220,   221,
     222,   211,   212,   213,   214,   215,   603,   605,   604,   606,
       0,   261,   425,   614,   603,   605,   604,   606,     0,   261,
       0,   625,   351,     0,   350,     0,     0,     0,     0,     0,
       0,   294,   428,   625,   426,   319,   324,   110,   111,   112,
       0,   525,   322,   524,   428,   625,   426,     0,     0,   550,
     331,   603,   604,   261,    35,   200,    41,   208,     0,     0,
     198,   596,     0,   268,   264,   625,   603,   604,   614,   603,
     604,   595,   298,   616,   248,   253,   255,   303,    22,     0,
     240,     0,    32,   423,   421,   207,     0,    75,    16,   291,
     618,     0,    83,    96,    98,   614,   603,   604,   556,   553,
     552,   551,   554,   561,   570,     0,   581,   571,   585,   584,
     580,   550,   408,   549,   411,   555,   557,   559,   535,   563,
     568,   625,   573,   625,   578,   535,   583,   535,     0,   533,
     487,     0,   462,   464,   474,   468,   476,   217,   398,   614,
       0,   396,   395,     0,   625,     0,   274,     0,    87,    81,
       0,     0,     0,     0,     0,     0,   429,    65,     0,     0,
     432,     0,     0,   427,    63,   625,   349,   287,   625,   625,
     441,   625,   352,   625,   354,   312,   353,   315,     0,     0,
     318,   607,   293,   614,   603,   604,     0,     0,   527,     0,
       0,   110,   111,   114,   614,     0,   614,   550,     0,     0,
       0,   250,   417,    57,   249,     0,   126,   598,   269,   259,
       0,     0,   432,     0,     0,   625,   614,    11,     0,   246,
      91,    94,     0,   372,   363,   365,   614,   361,   614,     0,
       0,     0,   542,   562,     0,   531,   588,   572,     0,   532,
       0,   545,   582,     0,   547,   586,   488,   490,   491,   492,
     485,   493,   394,   614,     0,   557,   379,   565,   566,   625,
     625,   576,   379,   379,   377,   400,     0,     0,     0,     0,
       0,   272,    79,   199,     0,    40,   205,    39,   206,    66,
     424,   617,     0,    37,   203,    38,   204,    64,   422,   442,
     443,   625,   444,     0,   625,   357,     0,     0,   355,     0,
       0,     0,   317,     0,     0,   432,     0,   325,     0,     0,
     432,   328,   591,   614,     0,   529,   332,   418,   419,   201,
       0,   254,   302,    20,   614,     0,   370,     0,   558,     0,
       0,     0,   409,   574,   534,   560,   535,   535,   569,   625,
     587,   535,   579,   535,   557,   535,     0,     0,   397,     0,
     385,   387,     0,   564,     0,   375,   376,     0,   390,     0,
     392,     0,   436,   434,     0,   415,   273,   241,    36,   202,
       0,     0,   446,   358,     0,    12,   448,     0,   309,   310,
       0,     0,   268,   625,   320,     0,   526,   323,   528,   330,
     550,   362,   373,     0,   368,   364,   410,     0,     0,     0,
     538,     0,   540,   530,     0,   546,     0,   543,   548,     0,
     399,   575,   378,   379,   379,   294,   428,   567,   625,   379,
     577,   379,   379,   404,   401,   402,   405,    59,     0,   445,
       0,   101,   102,   109,     0,   447,     0,   313,   316,   438,
     439,   437,     0,     0,     0,     0,   371,     0,   366,   413,
     412,   535,   535,   535,   535,   489,     0,   382,     0,   384,
     607,   293,   374,     0,   391,     0,   388,   393,     0,   108,
     428,   625,   426,   625,   625,     0,   326,     0,   369,     0,
     539,     0,   536,   541,   544,   379,   379,   379,   379,   403,
     607,   107,   614,   603,   604,   440,   356,   321,   333,   367,
     535,   383,     0,   380,   386,   389,   432,   537,   379,   381
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -807,  -807,  -807,  -376,  -807,    50,  -807,  -547,   -45,  -807,
     530,  -807,    23,  -807,  -294,   -49,   -66,   -37,  -807,  -183,
    -807,   749,    -5,   907,  -157,    15,   -71,  -807,  -400,     6,
    1710,  -315,   909,   -43,  -807,   -24,  -807,  -807,     8,  -807,
    1076,  -807,  2063,  -807,   -69,   290,  -327,    91,   -21,  -807,
    -407,  -203,    21,  -807,  -316,   -47,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,    82,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -119,  -344,  -553,   -15,  -644,  -807,
    -790,  -786,   239,   323,   175,  -807,  -398,  -807,  -664,  -807,
       2,  -807,  -807,  -807,  -807,  -807,  -807,   265,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   -96,  -807,  -807,  -550,  -807,
       9,  -807,  -807,  -807,  -807,  -807,  -807,   923,  -807,  -807,
    -807,  -807,   731,  -807,  -807,  -807,  -807,  -807,  -807,   823,
     975,  -807,  -106,  -807,  -807,  -807,  -807,  -807,    34,  -807,
      52,  -807,    17,  1298,  1611,   942,  1781,  1804,  -807,  -807,
      96,  -470,   194,  -385,  -794,   179,  -718,   101,  -150,   256,
     137,  -807,  -807,  -807,  -529,  -712,  -806,   148,   266,  -807,
    -601,  -807,  -530,  -615,  -807,  -807,  -807,    56,  -405,  -807,
    -325,  -807,   650,   -22,    -7,  -178,  -586,  -221,   -25,    14,
      -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    68,    69,    70,   240,   570,   571,   256,
     257,   450,   258,   441,    72,    73,   361,    74,    75,   512,
     694,   247,    77,    78,   259,    79,    80,    81,   470,    82,
     213,   380,   381,   195,   196,   197,   198,   608,   559,   200,
      84,   443,   215,   264,   232,   752,   430,   431,   229,   230,
     217,   417,   432,   518,   519,    85,   359,   263,   456,   629,
     363,   850,   364,   851,   736,   992,   740,   737,   935,   597,
     599,   750,   940,   249,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   717,   573,   725,   847,   848,   372,
     774,   775,   776,   962,   901,   803,   690,   691,   804,   974,
     975,   282,   283,   475,   779,   662,   882,   323,   513,    97,
      98,   715,   708,   568,   560,   321,   510,   509,   580,   991,
     719,   841,   921,   925,    99,   100,   101,   102,   103,   104,
     105,   294,   488,   106,   298,   107,   108,   296,   300,   290,
     288,   292,   480,   681,   680,   796,   896,   800,   109,   289,
     110,   111,   112,   220,   221,   115,   222,   223,   592,   739,
     748,   884,   782,   749,   665,   894,   667,   668,   669,   670,
     808,   809,   671,   672,   673,   674,   811,   812,   675,   676,
     677,   678,   679,   785,   399,   598,   269,   433,   225,   118,
     633,   562,   402,   307,   427,   428,   710,   461,   574,   367,
     261
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     119,   233,   403,   262,   238,   663,   255,   319,   277,   614,
     328,   212,   212,   529,   287,   212,   199,   614,   575,   621,
     236,   425,   239,   362,   727,    71,   365,    71,   728,   302,
     563,   561,   762,   569,   277,   524,   199,   218,   218,   360,
     360,   218,   201,   360,   308,   463,   277,   277,   277,   465,
     745,   267,   271,   397,   120,   320,   436,   621,   789,   771,
     202,   276,   201,   885,   589,   199,   260,   308,   631,  -101,
     366,   642,   224,   224,   265,   844,   224,   603,   892,   849,
     202,   455,   301,   309,    86,   457,    86,   945,   813,   942,
     664,   724,     3,   618,   561,   317,   569,   451,   219,   219,
     317,   970,   219,  -293,   199,  -102,   880,   216,   226,   266,
     270,   227,   693,   400,   879,   695,   491,   976,   476,  -338,
     438,   699,   634,   -95,   356,   235,   658,  -105,  -109,   663,
     497,   439,   440,    86,   219,   -73,   459,   278,  -108,   897,
     234,  -104,   305,   460,   306,   235,   645,   855,   219,   634,
     659,  -293,  -293,   241,   572,  -604,   -87,   996,   860,   814,
     810,   255,   401,   278,   477,   492,   478,  -338,  -338,   520,
     219,   219,   357,   358,   219,   371,   382,   382,   319,   498,
     887,   -92,   885,   590,   482,   435,   485,   437,   489,   893,
     881,   663,   489,   859,   905,   906,   445,  -107,   682,  -105,
     970,   864,   318,   251,   469,   945,   305,   318,   306,   255,
    -106,  1028,   322,   231,   -95,   572,   418,   -93,   614,   614,
    -104,   621,   418,   212,   976,   212,   212,   293,   277,   434,
     425,   308,  -106,  -512,   453,   -95,   885,   892,   -95,   -96,
    -100,  -603,   -95,  1049,   502,   503,   504,   505,   622,   218,
     -99,   218,   624,   -95,   890,   889,   733,   627,   890,   634,
     768,   360,   360,   360,   360,   466,   507,   508,   744,   260,
     454,   634,  -103,   637,   953,   449,   778,   663,   639,   743,
     277,   255,  -512,   305,   224,   306,   224,   515,    86,   989,
    -520,   468,   525,  -520,   295,   885,   818,   576,   577,   964,
     822,  -103,   591,   934,   688,  -511,   971,   482,   -97,   -98,
     219,  -604,   219,   219,   360,   360,   219,  -101,   219,   426,
    -101,   429,   -97,    86,   305,  -603,   306,  -513,  -105,   586,
    -105,  -521,    71,   522,    86,  -514,    86,   506,   -92,   853,
     308,   260,   698,   578,   305,   517,   306,   689,  1002,  -104,
     517,  -104,   212,  1012,  -511,   434,   593,   278,  -102,   501,
     587,  -106,   863,  -106,   588,   462,   567,  -516,   604,   606,
     814,   810,   460,   419,   890,   968,  -513,   814,   810,   814,
     810,   297,   683,   990,  -514,   854,   299,  -600,   993,   683,
     324,    86,   219,   219,   219,   219,    86,   219,   219,   -97,
     469,  -103,   840,  -103,   446,  1036,   219,   524,    86,   278,
     567,   219,   759,   -94,   472,   212,  -516,   628,   434,   769,
     -97,   420,   421,   -97,   277,   315,   316,   -97,   325,   567,
     418,   418,  -515,   648,  -601,   649,   650,   651,   652,   219,
    -517,    86,   119,   315,   316,   219,   219,  1027,  -506,   199,
     469,  -607,   420,   447,   329,   567,  1056,   843,    58,   579,
     219,   730,   473,   474,   614,  -518,   621,    71,   212,   405,
     663,   434,   615,   407,   277,   201,   814,   810,   814,   810,
     653,  -515,   567,   814,   810,   814,   810,   219,   219,  -517,
     423,   706,   654,   202,  -600,  -509,  -506,  -506,  -432,   713,
    -600,   648,   219,   649,   650,   651,   652,   692,   692,   234,
     448,   692,  -607,  -518,  -518,   640,   330,  -109,   875,  -521,
     657,   658,   814,   810,   829,   409,    86,  -519,   721,   414,
     723,   837,   235,   415,   751,   416,    86,  -108,   703,   807,
     707,  -601,  -506,  -509,  -509,   659,  -102,  -601,   714,   746,
    -509,   726,   726,   278,   422,   219,   709,   424,  -607,  -432,
    -607,  -607,   759,   442,  -603,   738,   330,   -93,   862,   720,
     770,   476,   353,   354,   355,  -519,  -519,   984,   212,   476,
     766,   434,   753,   986,   756,   444,   997,   476,   872,   228,
     212,  -506,   567,   434,   277,   476,   846,   843,   878,  -509,
     729,   754,   452,   278,   567,  -432,   231,  -432,  -432,   852,
     406,   709,   330,   418,   -72,   458,   199,   477,   464,   478,
     351,   352,   353,   354,   355,   477,   861,   478,   481,   469,
     609,   467,   471,   477,   119,   478,   479,  -109,   709,   830,
    -284,   477,   201,   478,   481,   816,   751,   330,   817,   763,
     819,   685,   486,   277,   666,    86,   867,    86,  -100,    71,
     202,   582,   343,   344,   525,   219,   594,   825,   827,   786,
     856,   786,   499,   858,   833,   835,  -104,   219,   490,    86,
     219,   765,   815,   476,   493,   938,  -294,   360,  -284,  -284,
     360,   511,   692,   764,  1042,   476,   941,   634,   348,   349,
     350,   351,   352,   353,   354,   355,   870,   866,   496,   583,
     584,   219,   857,   754,   595,   596,   842,   845,    86,   845,
    -106,   845,   448,   278,   865,   523,   709,   500,   928,   477,
     929,   478,   483,  -103,  -294,  -294,   966,   709,   579,   517,
     937,   477,   581,   478,   487,   939,   623,   585,   625,  -108,
     807,    76,   626,    76,   807,  1020,   632,   807,   199,   807,
     277,   636,   711,   418,   -87,    76,    76,   641,   476,    76,
     -99,   815,    86,   914,   684,    86,  -266,    86,   666,   686,
     927,   697,   278,   219,   595,   596,   219,   219,   700,  -104,
     806,   701,  -423,   219,   219,   918,   815,   360,   923,   712,
      76,    76,   832,  1021,  1022,   930,   931,   786,   786,   933,
     -95,   987,   988,   716,   477,    76,   478,   494,   219,   718,
     722,   219,    86,   767,   780,   781,  -106,   784,   330,  -103,
      86,   726,   787,   936,   777,   947,   948,    76,    76,   922,
     666,    76,   926,   343,   344,   792,   788,   -97,   790,   476,
     -94,   959,   277,   484,   793,  -267,   807,   795,   807,   824,
     831,   330,   843,   807,   871,   807,   873,   877,   805,   791,
     899,   794,   898,   277,  1026,   900,   343,   344,   911,   985,
     904,   350,   351,   352,   353,   354,   355,   786,   912,   903,
     907,   891,   909,   913,   895,   477,   915,   478,  -268,   920,
      86,   924,   807,   943,   946,   949,  1047,   648,  1048,   649,
     650,   651,   652,   951,   219,   351,   352,   353,   354,   355,
     310,   311,   312,   313,   314,    86,   666,   954,   219,   956,
     965,   845,    86,    86,   960,   977,    86,   797,   798,  1023,
     799,  1024,   999,  -269,  1000,   995,   772,  1025,    46,    47,
    1005,   777,   876,  1006,   648,    76,   649,   650,   651,   652,
     666,  1008,    86,    86,  1013,  1015,   786,  1018,   648,   666,
     649,   650,   651,   652,   653,  1019,  1029,    76,    86,    76,
      76,   961,  1031,    76,   638,    76,   654,   908,   910,  -603,
      76,  -604,   648,   772,   649,   650,   651,   652,  1052,   773,
     369,    76,   980,    76,   386,   838,    86,   655,   969,  1046,
     972,   874,   802,   656,   657,   658,   212,    86,   868,   434,
    1039,   720,   845,   973,   404,   649,   650,   651,   652,   495,
     567,   772,  1045,   413,   291,   709,   994,   944,   398,   659,
     888,   967,   660,    41,    42,    43,    44,   886,   963,   600,
    1001,     0,  1003,     0,   777,   661,   777,  1004,    76,    76,
      76,    76,    76,    76,    76,    76,    86,     0,    86,     0,
       0,     0,     0,    76,    86,    76,    86,     0,    76,   805,
     950,   952,     0,     0,     0,   955,   805,   957,     0,   958,
       0,     0,   214,   214,     0,     0,   214,     0,     0,     0,
       0,     0,     0,   219,     0,     0,    76,  1035,    76,  1037,
       0,     0,    76,    76,     0,     0,  1038,     0,     0,   666,
       0,     0,   777,   998,   248,   250,     0,    76,   666,   214,
     214,   648,  1050,   649,   650,   651,   652,   653,  1007,  1009,
       0,     0,   303,   304,  1014,     0,  1016,  1017,     0,   654,
       0,     0,     0,  1058,    76,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
     655,     0,     0,     0,   777,     0,   777,   657,   658,     0,
       0,     0,     0,     0,     0,   805,     0,     0,     0,     0,
       0,     0,     0,    76,     0,  1030,  1032,  1033,  1034,     0,
       0,     0,   659,    76,     0,     0,     0,     0,   777,     0,
    1051,  1053,  1054,  1055,     0,     0,     0,     0,     0,     0,
       0,  -625,    76,     0,     0,     0,     0,     0,     0,  -625,
    -625,  -625,     0,  1059,  -625,  -625,  -625,     0,  -625,     0,
       0,     0,     0,     0,  1057,     0,     0,  -625,  -625,   648,
       0,   649,   650,   651,   652,   653,     0,     0,  -625,  -625,
       0,  -625,  -625,  -625,  -625,  -625,     0,   654,     0,     0,
       0,   648,     0,   649,   650,   651,   652,   653,     0,     0,
     214,     0,     0,   214,   214,   214,     0,   303,   655,   654,
       0,     0,     0,     0,   656,   657,   658,     0,     0,     0,
     113,     0,   113,     0,   214,     0,   214,   214,  -625,     0,
     655,     0,     0,     0,     0,     0,   656,   657,   658,     0,
     659,     0,    76,   660,    76,     0,     0,     0,     0,     0,
       0,  -625,    76,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   659,     0,    76,   660,    76,    76,     0,   113,
       0,     0,     0,   279,  -625,  -625,     0,  -625,   747,     0,
     231,  -625,     0,  -625,     0,  -625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,   279,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,   373,   383,   383,   383,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,   527,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,     0,   214,     0,     0,     0,     0,     0,    76,
       0,     0,    76,     0,    76,     0,     0,     0,     0,     0,
      76,     0,     0,    76,    76,     0,     0,     0,     0,     0,
      76,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     755,   605,   607,     0,     0,    76,     0,     0,    76,    76,
     610,   214,   214,     0,     0,     0,   214,    76,   605,   607,
     214,     0,     0,     0,   113,     0,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   630,
       0,   343,   344,     0,   635,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,   214,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     113,     0,   113,   345,     0,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,     0,     0,    76,     0,     0,
       0,     0,     0,   279,     0,   687,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,    76,     0,     0,    76,     0,     0,     0,    76,
      76,     0,     0,    76,     0,     0,     0,   113,     0,     0,
       0,     0,   113,   114,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   279,     0,     0,     0,    76,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,   113,     0,   214,
       0,     0,   114,     0,     0,     0,   280,     0,     0,     0,
       0,   214,     0,    76,     0,     0,   648,     0,   649,   650,
     651,   652,   653,     0,    76,   214,     0,     0,   214,     0,
       0,     0,   280,     0,   654,     0,     0,     0,     0,     0,
       0,   214,   214,     0,   374,   384,   384,   384,     0,     0,
       0,     0,    83,     0,    83,   655,     0,     0,     0,     0,
       0,   656,   657,   658,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,     0,    76,     0,     0,     0,     0,
       0,    76,   113,    76,     0,   214,     0,   659,     0,     0,
     660,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,   279,
      76,     0,     0,   214,     0,     0,     0,   610,   823,     0,
     826,   828,     0,   116,     0,   116,     0,   834,   836,     0,
       0,     0,     0,     0,   214,     0,     0,     0,     0,     0,
       0,     0,     0,   370,     0,     0,   117,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   869,   116,     0,     0,     0,   826,   828,     0,   834,
     836,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,   117,   214,     0,     0,   281,
       0,     0,     0,   114,     0,   114,     0,     0,     0,     0,
       0,   113,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   280,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   214,   375,   385,   385,
     917,     0,     0,     0,     0,     0,     0,     0,   919,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
     114,     0,     0,     0,     0,   114,     0,     0,     0,   214,
       0,     0,     0,     0,   113,     0,     0,   114,   280,   279,
       0,     0,     0,     0,     0,     0,   919,   214,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    83,     0,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   113,     0,
       0,   113,     0,   113,     0,     0,     0,     0,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,   116,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   116,    83,     0,   113,   526,
       0,     0,     0,     0,     0,   117,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   117,     0,   117,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,    83,
       0,   330,   331,   332,   333,   334,   335,   336,   337,   281,
     339,   340,   280,     0,     0,     0,   343,   344,     0,     0,
     116,     0,     0,     0,     0,   116,     0,   214,     0,     0,
       0,     0,     0,     0,     0,   383,     0,   116,     0,     0,
       0,     0,     0,   117,     0,     0,   113,   268,   117,     0,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     117,   281,   280,     0,     0,     0,     0,     0,     0,     0,
     116,   113,     0,     0,     0,     0,     0,     0,   113,   113,
       0,     0,   113,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,   117,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   113,
       0,     0,     0,     0,   114,     0,   114,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,   383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   981,     0,
       0,     0,   113,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,   113,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   117,     0,
       0,     0,   280,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,   408,     0,     0,
     410,   411,   412,     0,     0,   281,     0,     0,     0,     0,
       0,     0,   113,    83,   113,    83,     0,     0,     0,     0,
     113,     0,   113,     0,     0,     0,   556,   557,     0,     0,
     558,   114,     0,     0,   114,     0,   114,    83,     0,     0,
       0,   280,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   174,   175,   281,     0,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,     0,     0,     0,    83,     0,     0,     0,
       0,   114,     0,     0,   116,     0,   116,     0,     0,   114,
       0,     0,     0,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,     0,   117,   116,   117,
       0,     0,   194,     0,     0,     0,     0,   516,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
      83,   117,     0,    83,     0,    83,     0,     0,     0,     0,
       0,   526,     0,     0,     0,     0,     0,   116,   384,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,   281,     0,     0,     0,     0,
      83,     0,     0,     0,   114,     0,     0,     0,    83,     0,
       0,   114,   114,     0,     0,   114,     0,     0,     0,     0,
       0,   116,     0,     0,   116,     0,   116,     0,   611,   613,
       0,     0,     0,     0,     0,   801,     0,   268,     0,     0,
       0,   114,   114,     0,   117,     0,     0,   117,     0,   117,
       0,     0,     0,     0,   281,     0,     0,   114,     0,     0,
     384,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   613,     0,     0,   268,     0,     0,    83,   116,
       0,   982,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   114,     0,     0,     0,
       0,     0,   117,    83,     0,     0,     0,     0,     0,     0,
      83,    83,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   696,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    83,     0,     0,     0,   114,     0,   114,     0,   116,
       0,     0,     0,   114,     0,   114,    83,     0,     0,     0,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,   116,     0,     0,     0,     0,     0,
     979,   116,   116,     0,    83,   116,     0,     0,     0,     0,
       0,     0,   528,     0,     0,    83,     0,   117,     0,     0,
       0,     0,     0,     0,   117,   117,     0,     0,   117,     0,
       0,   116,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   757,     0,     0,   758,     0,   116,     0,     0,
       0,     0,     0,     0,   117,   117,     0,     0,   613,   268,
       0,     0,     0,     0,    83,     0,    83,     0,     0,     0,
     117,     0,    83,   385,    83,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,   983,     0,     0,     0,   117,     0,
       0,     0,   783,     0,     0,     0,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     821,     0,     0,     0,     0,   116,     0,   116,     0,     0,
       0,     0,     0,   116,     0,   116,     0,     0,     0,     0,
       0,   839,     0,     0,     0,     0,     0,     0,   117,     0,
     117,     0,     0,     0,     0,     0,   117,     0,   117,  -625,
       4,     0,     5,     6,     7,     8,     9,     0,     0,     0,
      10,    11,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,   883,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   916,     0,     0,     0,    50,     0,     0,
      51,    52,     0,    53,    54,     0,    55,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,  -607,
       0,     0,     0,     0,     0,     0,   932,  -607,  -607,  -607,
       0,     0,  -607,  -607,  -607,     0,  -607,     0,    65,    66,
      67,   702,     0,     0,   268,  -607,  -607,  -607,  -607,     0,
       0,  -625,     0,  -625,     0,     0,  -607,  -607,     0,  -607,
    -607,  -607,  -607,  -607,     0,     0,     0,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
       0,     0,   343,   344,     0,     0,     0,     0,     0,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,     0,     0,  -607,  -607,  -607,     0,   760,  -607,
       0,     0,     0,     0,   345,  -607,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,     0,     0,     0,  -607,
       0,     0,  -607,     0,  -243,  -105,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,     0,     0,
       0,     0,  -607,  -607,  -607,  -607,  -607,  -506,     0,  -607,
    -607,  -607,     0,  -607,     0,  -506,  -506,  -506,     0,     0,
    -506,  -506,  -506,     0,  -506,     0,     0,     0,     0,   702,
       0,     0,  -506,     0,  -506,  -506,  -506,     0,     0,     0,
       0,     0,     0,     0,  -506,  -506,     0,  -506,  -506,  -506,
    -506,  -506,     0,     0,     0,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,     0,     0,
     343,   344,     0,     0,     0,     0,     0,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
       0,     0,  -506,  -506,  -506,     0,  -506,  -506,     0,     0,
       0,     0,   345,  -506,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,     0,     0,     0,  -506,     0,     0,
    -506,     0,     0,  -506,  -506,  -506,  -506,  -506,  -506,  -506,
    -506,  -506,  -506,  -506,  -506,  -506,     0,     0,     0,     0,
       0,  -506,  -506,  -506,  -506,  -509,     0,  -506,  -506,  -506,
       0,  -506,     0,  -509,  -509,  -509,     0,     0,  -509,  -509,
    -509,     0,  -509,     0,     0,     0,     0,     0,     0,     0,
    -509,     0,  -509,  -509,  -509,     0,     0,     0,     0,     0,
       0,     0,  -509,  -509,     0,  -509,  -509,  -509,  -509,  -509,
       0,     0,     0,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,     0,     0,   343,   344,
       0,     0,     0,     0,     0,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,     0,     0,
    -509,  -509,  -509,     0,  -509,  -509,     0,     0,     0,     0,
     345,  -509,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,     0,     0,     0,  -509,     0,     0,  -509,     0,
       0,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,     0,     0,     0,     0,     0,  -509,
    -509,  -509,  -509,  -608,     0,  -509,  -509,  -509,     0,  -509,
       0,  -608,  -608,  -608,     0,     0,  -608,  -608,  -608,     0,
    -608,     0,     0,     0,     0,     0,     0,     0,     0,  -608,
    -608,  -608,  -608,     0,     0,     0,     0,     0,     0,     0,
    -608,  -608,     0,  -608,  -608,  -608,  -608,  -608,     0,     0,
       0,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,  -626,  -626,     0,     0,   343,   344,     0,     0,
       0,     0,     0,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,     0,     0,  -608,  -608,
    -608,     0,     0,  -608,     0,     0,     0,     0,     0,  -608,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
       0,     0,     0,  -608,     0,     0,  -608,     0,     0,     0,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,     0,     0,     0,     0,  -608,  -608,  -608,  -608,
    -608,  -609,     0,  -608,  -608,  -608,     0,  -608,     0,  -609,
    -609,  -609,     0,     0,  -609,  -609,  -609,     0,  -609,     0,
       0,     0,     0,     0,     0,     0,     0,  -609,  -609,  -609,
    -609,     0,     0,     0,     0,     0,     0,     0,  -609,  -609,
       0,  -609,  -609,  -609,  -609,  -609,     0,     0,     0,   330,
    -626,  -626,  -626,  -626,   335,   336,     0,     0,  -626,  -626,
       0,     0,     0,     0,   343,   344,     0,     0,     0,     0,
       0,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,     0,     0,  -609,  -609,  -609,     0,
       0,  -609,     0,     0,     0,     0,     0,  -609,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,     0,     0,
       0,  -609,     0,     0,  -609,     0,     0,     0,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
       0,     0,     0,     0,  -609,  -609,  -609,  -609,  -609,  -293,
       0,  -609,  -609,  -609,     0,  -609,     0,  -293,  -293,  -293,
       0,     0,  -293,  -293,  -293,     0,  -293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -293,  -293,  -293,     0,
       0,     0,     0,     0,     0,     0,  -293,  -293,     0,  -293,
    -293,  -293,  -293,  -293,     0,     0,     0,   330,   331,   332,
     333,   334,   335,   336,     0,     0,   339,   340,     0,     0,
       0,     0,   343,   344,     0,     0,     0,     0,     0,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,     0,     0,  -293,  -293,  -293,     0,   761,  -293,
       0,     0,     0,     0,     0,  -293,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,     0,     0,     0,  -293,
       0,     0,  -293,     0,     0,  -107,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,     0,     0,
       0,     0,     0,  -293,  -293,  -293,  -293,  -431,     0,  -293,
    -293,  -293,     0,  -293,     0,  -431,  -431,  -431,     0,     0,
    -431,  -431,  -431,     0,  -431,     0,     0,     0,     0,     0,
       0,     0,     0,  -431,  -431,  -431,     0,     0,     0,     0,
       0,     0,     0,     0,  -431,  -431,     0,  -431,  -431,  -431,
    -431,  -431,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
       0,     0,  -431,  -431,  -431,     0,     0,  -431,     0,     0,
       0,     0,     0,  -431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -431,     0,     0,
       0,     0,     0,     0,  -431,     0,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,     0,     0,     0,     0,
    -431,  -431,  -431,  -431,  -431,  -285,   231,  -431,  -431,  -431,
       0,  -431,     0,  -285,  -285,  -285,     0,     0,  -285,  -285,
    -285,     0,  -285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -285,  -285,  -285,     0,     0,     0,     0,     0,
       0,     0,  -285,  -285,     0,  -285,  -285,  -285,  -285,  -285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,     0,     0,
    -285,  -285,  -285,     0,     0,  -285,     0,     0,     0,     0,
       0,  -285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -285,     0,     0,  -285,     0,
       0,     0,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,     0,     0,     0,     0,     0,  -285,
    -285,  -285,  -285,  -421,     0,  -285,  -285,  -285,     0,  -285,
       0,  -421,  -421,  -421,     0,     0,  -421,  -421,  -421,     0,
    -421,     0,     0,     0,     0,     0,     0,     0,     0,  -421,
    -421,  -421,     0,     0,     0,     0,     0,     0,     0,     0,
    -421,  -421,     0,  -421,  -421,  -421,  -421,  -421,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,     0,     0,  -421,  -421,
    -421,     0,     0,  -421,     0,     0,     0,     0,     0,  -421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -421,     0,     0,     0,     0,     0,     0,
    -421,     0,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,     0,     0,     0,     0,  -421,  -421,  -421,  -421,
    -421,  -300,  -421,  -421,  -421,  -421,     0,  -421,     0,  -300,
    -300,  -300,     0,     0,  -300,  -300,  -300,     0,  -300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -300,  -300,
       0,     0,     0,     0,     0,     0,     0,     0,  -300,  -300,
       0,  -300,  -300,  -300,  -300,  -300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,     0,     0,  -300,  -300,  -300,     0,
       0,  -300,     0,     0,     0,     0,     0,  -300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -300,     0,     0,     0,     0,     0,     0,  -300,     0,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
       0,     0,     0,     0,     0,  -300,  -300,  -300,  -300,  -607,
     228,  -300,  -300,  -300,     0,  -300,     0,  -607,  -607,  -607,
       0,     0,     0,  -607,  -607,     0,  -607,     0,     0,     0,
       0,     0,     0,     0,     0,  -607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -607,  -607,     0,  -607,
    -607,  -607,  -607,  -607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,     0,     0,  -607,  -607,  -607,     0,   704,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -607,
       0,     0,     0,     0,     0,  -105,  -607,     0,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,     0,     0,
       0,     0,  -607,  -607,  -607,  -607,   -96,  -293,     0,  -607,
       0,  -607,     0,  -607,     0,  -293,  -293,  -293,     0,     0,
       0,  -293,  -293,     0,  -293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -293,  -293,     0,  -293,  -293,  -293,
    -293,  -293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
       0,     0,  -293,  -293,  -293,     0,   705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -293,     0,     0,
       0,     0,     0,  -107,  -293,     0,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,     0,     0,     0,     0,
       0,  -293,  -293,  -293,   -98,     0,     0,  -293,     0,  -293,
     252,  -293,     5,     6,     7,     8,     9,  -625,  -625,  -625,
      10,    11,     0,     0,  -625,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,    29,   253,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
      51,    52,     0,    53,    54,     0,    55,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -625,   252,  -625,     5,     6,     7,     8,     9,     0,
       0,  -625,    10,    11,     0,  -625,  -625,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,   253,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -625,   252,  -625,     5,     6,     7,     8,
       9,     0,     0,  -625,    10,    11,     0,     0,  -625,    12,
    -625,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
     253,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,     0,
      55,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -625,   252,  -625,     5,     6,
       7,     8,     9,     0,     0,  -625,    10,    11,     0,     0,
    -625,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,    29,   253,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    51,    52,     0,    53,
      54,     0,    55,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,     5,     6,     7,     8,     9,     0,
    -625,  -625,    10,    11,    65,    66,    67,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,  -625,     0,  -625,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,   253,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      65,    66,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,  -625,     0,  -625,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,   253,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,   254,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,  -625,     0,  -625,
     252,  -625,     5,     6,     7,     8,     9,     0,     0,     0,
      10,    11,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,    29,   253,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
      51,    52,     0,    53,    54,     0,    55,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,  -625,
       0,  -625,   252,  -625,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,   253,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,     0,     0,  -625,     4,     0,     5,     6,
       7,     8,     9,  -625,     0,  -625,    10,    11,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    51,    52,     0,    53,
      54,     0,    55,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,     0,     0,  -625,
       0,     0,     0,     0,     0,     0,     0,  -625,   252,  -625,
       5,     6,     7,     8,     9,     0,     0,  -625,    10,    11,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,   253,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,    65,    66,    67,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,  -625,
       0,  -625,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
     253,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,     0,
      55,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,  -625,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,    65,    66,    67,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,  -625,     0,  -625,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,    29,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   204,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
     206,    52,     0,    53,    54,     0,   207,   208,   209,    56,
      57,   210,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     9,     0,     0,     0,    10,    11,    65,   211,
      67,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,   235,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,   206,    52,     0,    53,
      54,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     9,     0,
       0,     0,    10,    11,    65,    66,    67,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,   305,     0,   306,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,    52,     0,    53,    54,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      65,    66,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,   235,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,    53,    54,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,    65,    66,    67,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,   500,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
     253,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,     0,
      55,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   500,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   145,   146,   147,   387,   388,   389,   390,
     152,   153,   154,     0,     0,     0,     0,     0,   155,   156,
     157,   158,   391,   392,   393,   394,   163,    37,    38,   395,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   174,   175,     0,     0,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,     0,     0,     0,     0,     0,
       0,   194,   396,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   284,   285,   164,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,   174,
     175,     0,     0,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,     0,     0,     0,     0,     0,     0,   194,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     237,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,   174,   175,     0,     0,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,    57,     0,     0,
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
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,     0,     0,     0,     0,     0,     0,
     194,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,     0,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,   174,   175,     0,
       0,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
       5,     6,     7,     0,     9,     0,   194,     0,    10,    11,
       0,     0,     0,    12,     0,    13,    14,    15,   242,   243,
      18,    19,     0,     0,     0,     0,     0,   244,   245,   246,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,   272,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,     0,     0,   206,    52,
       0,    53,    54,     0,     0,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,     0,     0,     0,    12,   274,    13,    14,    15,
     242,   243,    18,    19,   275,     0,     0,     0,     0,   244,
     245,   246,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   272,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,     0,     0,
     206,    52,     0,    53,    54,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,     0,     0,     0,    12,   274,    13,
      14,    15,    16,    17,    18,    19,   521,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,    53,    54,     0,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,    66,    67,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   204,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   207,   208,   209,    56,    57,   210,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,    65,   211,    67,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,    53,    54,     0,
      55,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,    65,    66,    67,    12,     0,    13,    14,    15,
     242,   243,    18,    19,     0,     0,     0,     0,     0,   244,
     245,   246,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,    29,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   204,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
     206,    52,     0,    53,    54,     0,   612,   208,   209,    56,
      57,   210,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     9,     0,     0,     0,    10,    11,    65,   211,
      67,    12,     0,    13,    14,    15,   242,   243,    18,    19,
       0,     0,     0,     0,     0,   244,   245,   246,    23,    24,
      25,    26,     0,     0,   203,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   204,    41,    42,    43,    44,     0,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,   206,    52,     0,    53,
      54,     0,   207,   208,     0,    56,    57,   210,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     9,     0,
       0,     0,    10,    11,    65,   211,    67,    12,     0,    13,
      14,    15,   242,   243,    18,    19,     0,     0,     0,     0,
       0,   244,   245,   246,    23,    24,    25,    26,     0,     0,
     203,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   204,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,    52,     0,    53,    54,     0,     0,   208,
     209,    56,    57,   210,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   211,    67,    12,     0,    13,    14,    15,   242,   243,
      18,    19,     0,     0,     0,     0,     0,   244,   245,   246,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   204,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   612,   208,     0,    56,    57,   210,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       9,     0,     0,     0,    10,    11,    65,   211,    67,    12,
       0,    13,    14,    15,   242,   243,    18,    19,     0,     0,
       0,     0,     0,   244,   245,   246,    23,    24,    25,    26,
       0,     0,   203,     0,     0,     0,     0,     0,     0,    29,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   204,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,   206,    52,     0,    53,    54,     0,
       0,   208,     0,    56,    57,   210,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,    65,   211,    67,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,    29,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
     206,    52,     0,    53,    54,     0,   514,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     9,     0,     0,     0,    10,    11,    65,   211,
      67,    12,     0,    13,    14,    15,   242,   243,    18,    19,
       0,     0,     0,     0,     0,   244,   245,   246,    23,    24,
      25,    26,     0,     0,   203,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,   206,    52,     0,    53,
      54,     0,   207,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     9,     0,
       0,     0,    10,    11,    65,   211,    67,    12,     0,    13,
      14,    15,   242,   243,    18,    19,     0,     0,     0,     0,
       0,   244,   245,   246,    23,    24,    25,    26,     0,     0,
     203,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,    52,     0,    53,    54,     0,   820,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   211,    67,    12,     0,    13,    14,    15,   242,   243,
      18,    19,     0,     0,     0,     0,     0,   244,   245,   246,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   206,    52,
       0,    53,    54,     0,   514,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       9,     0,     0,     0,    10,    11,    65,   211,    67,    12,
       0,    13,    14,    15,   242,   243,    18,    19,     0,     0,
       0,     0,     0,   244,   245,   246,    23,    24,    25,    26,
       0,     0,   203,     0,     0,     0,     0,     0,     0,    29,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,   206,    52,     0,    53,    54,     0,
     612,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,    65,   211,    67,    12,     0,    13,    14,    15,
     242,   243,    18,    19,     0,     0,     0,     0,     0,   244,
     245,   246,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,    29,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
     206,    52,     0,    53,    54,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     9,     0,     0,     0,    10,    11,    65,   211,
      67,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,   206,    52,     0,    53,
      54,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     9,     0,
       0,     0,    10,    11,    65,    66,    67,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
     203,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,    52,     0,    53,    54,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      65,   211,    67,    12,     0,    13,    14,    15,   242,   243,
      18,    19,     0,     0,     0,     0,     0,   244,   245,   246,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,   272,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,     0,     0,   326,    52,
       0,    53,    54,     0,   327,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,     0,     0,     0,    12,   274,    13,    14,    15,
     242,   243,    18,    19,     0,     0,     0,     0,     0,   244,
     245,   246,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   272,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   368,     0,     0,
      51,    52,     0,    53,    54,     0,    55,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     9,     0,
       0,     0,    10,    11,     0,     0,     0,    12,   274,    13,
      14,    15,   242,   243,    18,    19,     0,     0,     0,     0,
       0,   244,   245,   246,    23,    24,    25,    26,     0,     0,
     203,     0,     0,     0,     0,     0,     0,   272,     0,     0,
      32,    33,    34,   376,    36,    37,    38,   377,    40,     0,
      41,    42,    43,    44,     0,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   378,     0,     0,   379,
       0,     0,   206,    52,     0,    53,    54,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       9,     0,     0,     0,    10,    11,     0,     0,     0,    12,
     274,    13,    14,    15,   242,   243,    18,    19,     0,     0,
       0,     0,     0,   244,   245,   246,    23,    24,    25,    26,
       0,     0,   203,     0,     0,     0,     0,     0,     0,   272,
       0,     0,    32,    33,    34,   376,    36,    37,    38,   377,
      40,     0,    41,    42,    43,    44,     0,    45,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   379,     0,     0,   206,    52,     0,    53,    54,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     9,     0,     0,     0,    10,    11,     0,     0,
       0,    12,   274,    13,    14,    15,   242,   243,    18,    19,
       0,     0,     0,     0,     0,   244,   245,   246,    23,    24,
      25,    26,     0,     0,   203,     0,     0,     0,     0,     0,
       0,   272,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,    45,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,     0,     0,   326,    52,     0,    53,
      54,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
       0,     0,     0,    12,   274,    13,    14,    15,   242,   243,
      18,    19,     0,     0,     0,     0,     0,   244,   245,   246,
      23,    24,    25,    26,     0,     0,   203,     0,     0,     0,
       0,     0,     0,   272,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   902,     0,     0,   206,    52,
       0,    53,    54,     0,     0,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     0,     9,     0,     0,     0,
      10,    11,     0,     0,     0,    12,   274,    13,    14,    15,
     242,   243,    18,    19,     0,     0,     0,     0,     0,   244,
     245,   246,    23,    24,    25,    26,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   272,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,     0,    45,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   978,     0,     0,
     206,    52,     0,    53,    54,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,   564,   565,     0,     0,   566,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   601,   565,     0,     0,   602,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   616,   557,     0,     0,   617,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   619,   565,     0,     0,   620,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   643,   557,     0,     0,   644,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   646,   565,     0,     0,   647,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   731,   557,     0,     0,   732,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   734,   565,     0,     0,   735,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   741,   557,     0,     0,   742,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,  1010,   557,     0,     0,  1011,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,  1040,   557,     0,     0,  1041,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,  1043,   565,     0,     0,  1044,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,     0,     0,   343,   344,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,   345,     0,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235
};

static const yytype_int16 yycheck[] =
{
       2,    22,    98,    52,    28,   475,    51,    76,    55,   416,
      81,    16,    17,   329,    57,    20,     8,   424,   362,   424,
      27,   224,    29,    89,   577,     2,    92,     4,   578,    66,
     357,   356,   618,   358,    81,   329,    28,    16,    17,    88,
      89,    20,     8,    92,    69,   266,    93,    94,    95,   270,
     597,    53,    54,    96,     4,    76,   234,   462,   673,   645,
       8,    55,    28,   781,   379,    57,    51,    92,   444,    25,
      92,   471,    16,    17,    53,   719,    20,   402,   790,   723,
      28,   259,    65,    69,     2,   263,     4,   877,   689,   875,
     475,    27,     0,   420,   419,    26,   421,   254,    16,    17,
      26,   907,    20,    87,    96,    25,    29,    16,    17,    53,
      54,    20,   510,    87,   778,   513,    63,   911,    63,    87,
      54,   521,   447,    25,    87,   144,    99,    25,    25,   599,
      63,    65,    66,    51,    52,   116,   137,    55,    25,   803,
     139,    25,   142,   144,   144,   144,   473,   733,    66,   474,
     123,   135,   136,   133,    13,   139,   137,   943,   744,   689,
     689,   206,   136,    81,   109,   112,   111,   135,   136,   326,
      88,    89,   135,   136,    92,    93,    94,    95,   247,   112,
     781,   137,   900,     1,   290,   234,   292,   236,   294,   790,
     113,   661,   298,   740,   809,   810,   241,    25,   143,    13,
    1006,   748,   133,    56,   275,   995,   142,   133,   144,   254,
      25,   997,    28,   139,   116,    13,   218,   137,   625,   626,
      13,   626,   224,   228,  1018,   230,   231,   143,   275,   231,
     433,   256,    13,    87,   256,   137,   954,   949,   140,   137,
     137,   139,   144,  1029,   310,   311,   312,   313,   426,   228,
     137,   230,   430,   137,   784,   784,   583,   435,   788,   584,
     636,   310,   311,   312,   313,   272,   315,   316,   595,   254,
     256,   596,    13,   451,   889,   252,   661,   747,   456,   594,
     327,   326,   136,   142,   228,   144,   230,   324,   206,   933,
      89,   274,   329,    89,   143,  1013,   694,   363,   364,   900,
     700,    25,   120,   856,    78,    87,   907,   413,    25,   137,
     228,   139,   230,   231,   363,   364,   234,   116,   236,   228,
     116,   230,   137,   241,   142,   139,   144,    87,   142,   378,
     144,    89,   309,   327,   252,    87,   254,   314,   137,   137,
     365,   326,   520,   365,   142,   324,   144,   121,   949,   142,
     329,   144,   357,   968,   136,   357,   381,   275,   116,   309,
      52,   142,   747,   144,    56,   137,   358,    87,   405,   406,
     900,   900,   144,    87,   904,   904,   136,   907,   907,   909,
     909,   143,   488,   933,   136,   729,   143,    26,   935,   495,
     116,   309,   310,   311,   312,   313,   314,   315,   316,   116,
     471,   142,   718,   144,    87,  1006,   324,   701,   326,   327,
     402,   329,   615,   137,    87,   420,   136,   441,   420,   640,
     137,   135,   136,   140,   471,    37,    38,   144,   137,   421,
     432,   433,    87,    52,    26,    54,    55,    56,    57,   357,
      87,   359,   444,    37,    38,   363,   364,   994,    87,   441,
     521,    26,   135,   136,   116,   447,  1042,    15,   102,    17,
     378,   580,   135,   136,   871,    87,   871,   444,   473,    89,
     940,   473,   416,   137,   521,   441,  1006,  1006,  1008,  1008,
      58,   136,   474,  1013,  1013,  1015,  1015,   405,   406,   136,
      89,   560,    70,   441,   133,    87,   135,   136,    26,   568,
     139,    52,   420,    54,    55,    56,    57,   509,   510,   139,
      89,   513,    87,   135,   136,   459,    70,   116,   137,    89,
      98,    99,  1052,  1052,   707,    56,   444,    87,   573,   116,
     575,   714,   144,    90,   603,   137,   454,   116,   545,   689,
     561,   133,    87,   135,   136,   123,   116,   139,   569,   598,
      87,   576,   577,   471,    89,   473,   563,   137,   133,    87,
     135,   136,   765,   139,   139,   590,    70,   137,   746,   571,
     641,    63,   126,   127,   128,   135,   136,   921,   583,    63,
     629,   583,   603,   927,   608,   133,   137,    63,   766,   139,
     595,   136,   584,   595,   641,    63,    14,    15,   776,   136,
     579,   603,   140,   521,   596,   133,   139,   135,   136,   728,
      89,   618,    70,   615,   116,   141,   608,   109,   134,   111,
     124,   125,   126,   127,   128,   109,   745,   111,   112,   700,
     114,    56,   137,   109,   636,   111,   112,   116,   645,   708,
      87,   109,   608,   111,   112,   690,   715,    70,   693,    89,
     695,   143,   112,   700,   475,   573,   752,   575,   137,   636,
     608,    87,    85,    86,   701,   583,    87,   704,   705,   671,
     736,   673,    70,   739,   711,   712,   116,   595,   112,   597,
     598,   625,   689,    63,   112,   863,    87,   736,   135,   136,
     739,    96,   694,    89,  1021,    63,   874,  1022,   121,   122,
     123,   124,   125,   126,   127,   128,    89,   750,   112,   135,
     136,   629,   737,   715,   135,   136,   718,   719,   636,   721,
     116,   723,    89,   641,   749,   137,   733,   142,   847,   109,
     849,   111,   112,   116,   135,   136,    87,   744,    17,   718,
     859,   109,    56,   111,   112,   864,   140,    25,   137,   116,
     900,     2,   137,     4,   904,    87,   134,   907,   750,   909,
     807,   133,    89,   765,   137,    16,    17,   137,    63,    20,
     137,   778,   690,   818,   143,   693,   137,   695,   599,   143,
     846,   137,   700,   701,   135,   136,   704,   705,   137,   116,
     689,   116,   139,   711,   712,   832,   803,   846,   843,    89,
      51,    52,    89,   135,   136,   850,   851,   809,   810,   854,
     137,   930,   931,    10,   109,    66,   111,   112,   736,     8,
      13,   739,   740,   134,   116,   137,   116,   137,    70,   116,
     748,   856,    52,   858,   655,   880,   881,    88,    89,   841,
     661,    92,   844,    85,    86,    52,   137,   137,   137,    63,
     137,   896,   899,    67,   137,   137,  1006,    52,  1008,   118,
     141,    70,    15,  1013,   137,  1015,   134,   137,   689,   675,
     116,   677,   121,   920,   993,   137,    85,    86,   142,   924,
     137,   123,   124,   125,   126,   127,   128,   889,    10,   807,
     137,   790,   137,   134,   793,   109,    10,   111,   137,    90,
     818,     9,  1052,   137,   140,   137,  1025,    52,  1027,    54,
      55,    56,    57,   137,   832,   124,   125,   126,   127,   128,
      40,    41,    42,    43,    44,   843,   747,   137,   846,   137,
      56,   933,   850,   851,   121,   134,   854,    54,    55,   984,
      57,   986,    10,   137,   134,   137,    91,   992,    65,    66,
     110,   772,   773,   137,    52,   206,    54,    55,    56,    57,
     781,   137,   880,   881,   137,   137,   968,   137,    52,   790,
      54,    55,    56,    57,    58,    56,   137,   228,   896,   230,
     231,   899,   137,   234,   454,   236,    70,   812,   813,   139,
     241,   139,    52,    91,    54,    55,    56,    57,   137,    97,
      93,   252,   920,   254,    95,   715,   924,    91,   907,  1024,
     909,   772,   689,    97,    98,    99,  1021,   935,   753,  1021,
    1018,  1023,  1024,    52,   101,    54,    55,    56,    57,   298,
    1022,    91,  1023,   210,    59,  1042,   940,    97,    96,   123,
     784,   904,   126,    59,    60,    61,    62,   781,   900,   399,
     949,    -1,   951,    -1,   875,   139,   877,   956,   309,   310,
     311,   312,   313,   314,   315,   316,   984,    -1,   986,    -1,
      -1,    -1,    -1,   324,   992,   326,   994,    -1,   329,   900,
     886,   887,    -1,    -1,    -1,   891,   907,   893,    -1,   895,
      -1,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,  1021,    -1,    -1,   357,  1006,   359,  1008,
      -1,    -1,   363,   364,    -1,    -1,  1015,    -1,    -1,   940,
      -1,    -1,   943,   944,    48,    49,    -1,   378,   949,    53,
      54,    52,  1031,    54,    55,    56,    57,    58,   963,   964,
      -1,    -1,    66,    67,   969,    -1,   971,   972,    -1,    70,
      -1,    -1,    -1,  1052,   405,   406,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      91,    -1,    -1,    -1,   995,    -1,   997,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,  1006,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,    -1,  1001,  1002,  1003,  1004,    -1,
      -1,    -1,   123,   454,    -1,    -1,    -1,    -1,  1029,    -1,
    1035,  1036,  1037,  1038,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,   473,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    -1,  1058,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,  1050,    -1,    -1,    26,    27,    52,
      -1,    54,    55,    56,    57,    58,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    -1,    70,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    57,    58,    -1,    -1,
     204,    -1,    -1,   207,   208,   209,    -1,   211,    91,    70,
      -1,    -1,    -1,    -1,    97,    98,    99,    -1,    -1,    -1,
       2,    -1,     4,    -1,   228,    -1,   230,   231,    87,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
     123,    -1,   573,   126,   575,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   123,    -1,   595,   126,   597,   598,    -1,    51,
      -1,    -1,    -1,    55,   133,   134,    -1,   136,   139,    -1,
     139,   140,    -1,   142,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   629,    81,
      -1,    -1,    -1,    -1,    -1,   636,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,    -1,   357,    -1,    -1,    -1,    -1,    -1,   690,
      -1,    -1,   693,    -1,   695,    -1,    -1,    -1,    -1,    -1,
     701,    -1,    -1,   704,   705,    -1,    -1,    -1,    -1,    -1,
     711,   712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,   405,   406,    -1,    -1,   736,    -1,    -1,   739,   740,
     414,   415,   416,    -1,    -1,    -1,   420,   748,   422,   423,
     424,    -1,    -1,    -1,   206,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   443,
      -1,    85,    86,    -1,   448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   459,    -1,    -1,   462,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,
     252,    -1,   254,   117,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,   818,    -1,    -1,
      -1,    -1,    -1,   275,    -1,   499,    -1,    -1,    -1,    -1,
      -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     514,    -1,   843,    -1,    -1,   846,    -1,    -1,    -1,   850,
     851,    -1,    -1,   854,    -1,    -1,    -1,   309,    -1,    -1,
      -1,    -1,   314,     2,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   326,   327,    -1,    -1,    -1,   880,
     881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,    -1,   359,    -1,   583,
      -1,    -1,    51,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,   595,    -1,   924,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    -1,   935,   609,    -1,    -1,   612,    -1,
      -1,    -1,    81,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,   625,   626,    -1,    93,    94,    95,    96,    -1,    -1,
      -1,    -1,     2,    -1,     4,    91,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   984,    -1,   986,    -1,    -1,    -1,    -1,
      -1,   992,   444,   994,    -1,   669,    -1,   123,    -1,    -1,
     126,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,
    1021,    -1,    -1,   697,    -1,    -1,    -1,   701,   702,    -1,
     704,   705,    -1,     2,    -1,     4,    -1,   711,   712,    -1,
      -1,    -1,    -1,    -1,   718,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,     2,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,   521,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   755,    51,    -1,    -1,    -1,   760,   761,    -1,   763,
     764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    51,   780,    -1,    -1,    55,
      -1,    -1,    -1,   252,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   573,    -1,   575,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,   820,    93,    94,    95,
     824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     309,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,   853,
      -1,    -1,    -1,    -1,   636,    -1,    -1,   326,   327,   641,
      -1,    -1,    -1,    -1,    -1,    -1,   870,   871,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   690,    -1,
      -1,   693,    -1,   695,    -1,    -1,    -1,    -1,   700,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,
      -1,    -1,   241,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   252,    -1,   254,   326,    -1,   740,   329,
      -1,    -1,    -1,    -1,    -1,   241,   748,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   444,   252,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,   359,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   275,
      79,    80,   471,    -1,    -1,    -1,    85,    86,    -1,    -1,
     309,    -1,    -1,    -1,    -1,   314,    -1,  1021,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   807,    -1,   326,    -1,    -1,
      -1,    -1,    -1,   309,    -1,    -1,   818,    54,   314,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     326,   327,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   843,    -1,    -1,    -1,    -1,    -1,    -1,   850,   851,
      -1,    -1,   854,    -1,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   359,   454,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   880,   881,
      -1,    -1,    -1,    -1,   573,    -1,   575,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   896,    -1,    -1,   899,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   920,    -1,
      -1,    -1,   924,    -1,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   935,    -1,   454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,   444,    -1,
      -1,    -1,   641,    -1,    -1,    -1,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
     207,   208,   209,    -1,    -1,   471,    -1,    -1,    -1,    -1,
      -1,    -1,   984,   573,   986,   575,    -1,    -1,    -1,    -1,
     992,    -1,   994,    -1,    -1,    -1,    52,    53,    -1,    -1,
      56,   690,    -1,    -1,   693,    -1,   695,   597,    -1,    -1,
      -1,   700,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,   521,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,   636,    -1,    -1,    -1,
      -1,   740,    -1,    -1,   573,    -1,   575,    -1,    -1,   748,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,    -1,   573,   597,   575,
      -1,    -1,   138,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     690,   597,    -1,   693,    -1,   695,    -1,    -1,    -1,    -1,
      -1,   701,    -1,    -1,    -1,    -1,    -1,   636,   807,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   818,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     636,    -1,    -1,    -1,    -1,   641,    -1,    -1,    -1,    -1,
     740,    -1,    -1,    -1,   843,    -1,    -1,    -1,   748,    -1,
      -1,   850,   851,    -1,    -1,   854,    -1,    -1,    -1,    -1,
      -1,   690,    -1,    -1,   693,    -1,   695,    -1,   415,   416,
      -1,    -1,    -1,    -1,    -1,   681,    -1,   424,    -1,    -1,
      -1,   880,   881,    -1,   690,    -1,    -1,   693,    -1,   695,
      -1,    -1,    -1,    -1,   700,    -1,    -1,   896,    -1,    -1,
     899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   740,   459,    -1,    -1,   462,    -1,    -1,   818,   748,
      -1,   920,    -1,    -1,    -1,   924,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   740,    -1,   935,    -1,    -1,    -1,
      -1,    -1,   748,   843,    -1,    -1,    -1,    -1,    -1,    -1,
     850,   851,    -1,    -1,   854,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     880,   881,    -1,    -1,    -1,   984,    -1,   986,    -1,   818,
      -1,    -1,    -1,   992,    -1,   994,   896,    -1,    -1,    -1,
      -1,   807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   818,    -1,   843,    -1,    -1,    -1,    -1,    -1,
     920,   850,   851,    -1,   924,   854,    -1,    -1,    -1,    -1,
      -1,    -1,   579,    -1,    -1,   935,    -1,   843,    -1,    -1,
      -1,    -1,    -1,    -1,   850,   851,    -1,    -1,   854,    -1,
      -1,   880,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   609,    -1,    -1,   612,    -1,   896,    -1,    -1,
      -1,    -1,    -1,    -1,   880,   881,    -1,    -1,   625,   626,
      -1,    -1,    -1,    -1,   984,    -1,   986,    -1,    -1,    -1,
     896,    -1,   992,   899,   994,   924,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   935,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   920,    -1,    -1,    -1,   924,    -1,
      -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,   935,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     697,    -1,    -1,    -1,    -1,   984,    -1,   986,    -1,    -1,
      -1,    -1,    -1,   992,    -1,   994,    -1,    -1,    -1,    -1,
      -1,   718,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,
     986,    -1,    -1,    -1,    -1,    -1,   992,    -1,   994,     0,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,   780,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   820,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,     0,
      -1,    -1,    -1,    -1,    -1,    -1,   853,     8,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    17,    -1,   129,   130,
     131,    44,    -1,    -1,   871,    26,    27,    28,    29,    -1,
      -1,   142,    -1,   144,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    86,    87,    -1,    89,    90,
      -1,    -1,    -1,    -1,   117,    96,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   110,
      -1,    -1,   113,    -1,   137,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,     0,    -1,   140,
     141,   142,    -1,   144,    -1,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    86,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    86,    87,    -1,    89,    90,    -1,    -1,
      -1,    -1,   117,    96,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   110,    -1,    -1,
     113,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,     0,    -1,   140,   141,   142,
      -1,   144,    -1,     8,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    86,    87,    -1,    89,    90,    -1,    -1,    -1,    -1,
     117,    96,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,
      -1,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,     0,    -1,   140,   141,   142,    -1,   144,
      -1,     8,     9,    10,    -1,    -1,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    86,
      87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,     0,    -1,   140,   141,   142,    -1,   144,    -1,     8,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   110,    -1,    -1,   113,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,     0,
      -1,   140,   141,   142,    -1,   144,    -1,     8,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    86,    87,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   110,
      -1,    -1,   113,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,     0,    -1,   140,
     141,   142,    -1,   144,    -1,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    86,    87,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,     0,   139,   140,   141,   142,
      -1,   144,    -1,     8,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    86,    87,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,     0,    -1,   140,   141,   142,    -1,   144,
      -1,     8,     9,    10,    -1,    -1,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    86,
      87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,     0,   139,   140,   141,   142,    -1,   144,    -1,     8,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,     0,
     139,   140,   141,   142,    -1,   144,    -1,     8,     9,    10,
      -1,    -1,    -1,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,     0,    -1,   140,
      -1,   142,    -1,   144,    -1,     8,     9,    10,    -1,    -1,
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
      -1,    -1,    -1,   116,   117,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,   142,
       1,   144,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    16,    -1,    18,    19,    20,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,     1,   144,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,     1,   144,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
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
      -1,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,     1,   144,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,   129,   130,   131,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,   142,    -1,   144,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
     129,   130,   131,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,   142,    -1,   144,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,
       1,   144,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,   142,     1,   144,     3,     4,     5,     6,     7,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,    -1,    -1,   134,     1,    -1,     3,     4,
       5,     6,     7,   142,    -1,   144,    11,    12,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,     1,   144,
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
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,   129,   130,   131,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,   142,
      -1,   144,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      97,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,   129,   130,   131,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,   142,    -1,   144,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,   129,   130,
     131,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,   144,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,   129,   130,   131,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,   142,    -1,   144,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
     129,   130,   131,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,   144,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,   129,   130,   131,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,   142,
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
      -1,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,     3,     4,     5,     6,     7,
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
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
       3,     4,     5,    -1,     7,    -1,   138,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,   129,    18,    19,    20,
      21,    22,    23,    24,   137,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,   129,    18,
      19,    20,    21,    22,    23,    24,   137,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     129,   130,   131,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,   129,   130,   131,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      97,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,   129,   130,   131,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,   129,   130,
     131,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    97,    98,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,   129,   130,   131,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     129,   130,   131,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,    -1,    -1,    11,    12,   129,   130,   131,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,   129,   130,   131,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,   129,   130,
     131,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,   129,   130,   131,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     129,   130,   131,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,    -1,    -1,    11,    12,   129,   130,   131,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      97,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,   129,   130,   131,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,   129,   130,
     131,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,   129,   130,   131,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     129,   130,   131,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,   129,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,   129,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    91,    92,    -1,    94,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
     129,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    92,    -1,    94,    95,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,   129,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    -1,    94,
      95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,   129,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      -1,    94,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,   129,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    94,    95,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    52,    53,    -1,    -1,    56,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    85,    86,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   146,   147,     0,     1,     3,     4,     5,     6,     7,
      11,    12,    16,    18,    19,    20,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    59,    60,    61,    62,    64,    65,    66,    68,    69,
      88,    91,    92,    94,    95,    97,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   129,   130,   131,   148,   149,
     150,   157,   159,   160,   162,   163,   166,   167,   168,   170,
     171,   172,   174,   175,   185,   200,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   254,   255,   269,
     270,   271,   272,   273,   274,   275,   278,   280,   281,   293,
     295,   296,   297,   298,   299,   300,   301,   302,   334,   345,
     150,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    56,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    79,    80,    83,    84,    85,    86,
      97,    98,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   130,   131,   138,   178,   179,   180,   181,   183,
     184,   293,   295,    39,    58,    88,    91,    97,    98,    99,
     102,   130,   167,   175,   185,   187,   192,   195,   197,   218,
     298,   299,   301,   302,   332,   333,   192,   192,   139,   193,
     194,   139,   189,   193,   139,   144,   339,    54,   180,   339,
     151,   133,    21,    22,    30,    31,    32,   166,   185,   218,
     185,    56,     1,    47,    91,   153,   154,   155,   157,   169,
     170,   345,   160,   202,   188,   197,   332,   345,   187,   331,
     332,   345,    46,    88,   129,   137,   174,   200,   218,   298,
     299,   302,   246,   247,    54,    55,    57,   178,   285,   294,
     284,   285,   286,   143,   276,   143,   282,   143,   279,   143,
     283,   297,   162,   185,   185,   142,   144,   338,   343,   344,
      40,    41,    42,    43,    44,    37,    38,    26,   133,   189,
     193,   260,    28,   252,   116,   137,    91,    97,   171,   116,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    85,    86,   117,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    87,   135,   136,   201,
     160,   161,   161,   205,   207,   161,   338,   344,    88,   168,
     175,   218,   234,   298,   299,   302,    52,    56,    85,    88,
     176,   177,   218,   298,   299,   302,   177,    33,    34,    35,
      36,    49,    50,    51,    52,    56,   139,   178,   300,   329,
      87,   136,   337,   260,   272,    89,    89,   137,   187,    56,
     187,   187,   187,   284,   116,    90,   137,   196,   345,    87,
     135,   136,    89,    89,   137,   196,   192,   339,   340,   192,
     191,   192,   197,   332,   345,   160,   340,   160,    54,    65,
      66,   158,   139,   186,   133,   153,    87,   136,    89,   157,
     156,   169,   140,   338,   344,   340,   203,   340,   141,   137,
     144,   342,   137,   342,   134,   342,   339,    56,   297,   171,
     173,   137,    87,   135,   136,   248,    63,   109,   111,   112,
     287,   112,   287,   112,    67,   287,   112,   112,   277,   287,
     112,    63,   112,   112,   112,   277,   112,    63,   112,    70,
     142,   150,   161,   161,   161,   161,   157,   160,   160,   262,
     261,    96,   164,   253,    97,   162,   187,   197,   198,   199,
     169,   137,   174,   137,   159,   162,   175,   185,   187,   199,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,    52,    53,    56,   183,
     259,   335,   336,   191,    52,    53,    56,   183,   258,   335,
     152,   153,    13,   230,   343,   230,   161,   161,   338,    17,
     263,    56,    87,   135,   136,    25,   160,    52,    56,   176,
       1,   120,   303,   343,    87,   135,   136,   214,   330,   215,
     337,    52,    56,   335,   162,   185,   162,   185,   182,   114,
     185,   187,    97,   187,   195,   332,    52,    56,   191,    52,
      56,   333,   340,   140,   340,   137,   137,   340,   180,   204,
     185,   148,   134,   335,   335,   185,   133,   340,   155,   340,
     332,   137,   173,    52,    56,   191,    52,    56,    52,    54,
      55,    56,    57,    58,    70,    91,    97,    98,    99,   123,
     126,   139,   250,   306,   308,   309,   310,   311,   312,   313,
     314,   317,   318,   319,   320,   323,   324,   325,   326,   327,
     289,   288,   143,   287,   143,   143,   143,   185,    78,   121,
     241,   242,   345,   241,   165,   241,   187,   137,   340,   173,
     137,   116,    44,   339,    89,    89,   189,   193,   257,   339,
     341,    89,    89,   189,   193,   256,    10,   229,     8,   265,
     345,   153,    13,   153,    27,   231,   343,   231,   263,   197,
     229,    52,    56,   191,    52,    56,   209,   212,   343,   304,
     211,    52,    56,   176,   191,   152,   160,   139,   305,   308,
     216,   189,   190,   193,   345,    44,   180,   187,   187,   196,
      89,    89,   341,    89,    89,   332,   160,   134,   148,   342,
     171,   341,    91,    97,   235,   236,   237,   310,   308,   249,
     116,   137,   307,   187,   137,   328,   345,    52,   137,   328,
     137,   307,    52,   137,   307,    52,   290,    54,    55,    57,
     292,   302,   238,   240,   243,   310,   312,   313,   315,   316,
     319,   321,   322,   325,   327,   339,   153,   153,   241,   153,
      97,   187,   173,   185,   118,   162,   185,   162,   185,   164,
     189,   141,    89,   162,   185,   162,   185,   164,   190,   187,
     199,   266,   345,    15,   233,   345,    14,   232,   233,   233,
     206,   208,   229,   137,   230,   341,   161,   343,   161,   152,
     341,   229,   340,   308,   152,   343,   178,   260,   252,   185,
      89,   137,   340,   134,   237,   137,   310,   137,   340,   243,
      29,   113,   251,   187,   306,   311,   323,   325,   314,   319,
     327,   312,   320,   325,   310,   312,   291,   243,   121,   116,
     137,   239,    88,   218,   137,   328,   328,   137,   239,   137,
     239,   142,    10,   134,   153,    10,   187,   185,   162,   185,
      90,   267,   345,   153,     9,   268,   345,   161,   229,   229,
     153,   153,   187,   153,   231,   213,   343,   229,   340,   229,
     217,   340,   236,   137,    97,   235,   140,   153,   153,   137,
     307,   137,   307,   328,   137,   307,   137,   307,   307,   153,
     121,   218,   238,   322,   325,    56,    87,   315,   319,   312,
     321,   325,   312,    52,   244,   245,   309,   134,    88,   175,
     218,   298,   299,   302,   230,   153,   230,   229,   229,   233,
     263,   264,   210,   152,   305,   137,   236,   137,   310,    10,
     134,   312,   325,   312,   312,   110,   137,   239,   137,   239,
      52,    56,   328,   137,   239,   137,   239,   239,   137,    56,
      87,   135,   136,   153,   153,   153,   229,   152,   236,   137,
     307,   137,   307,   307,   307,   312,   325,   312,   312,   245,
      52,    56,   191,    52,    56,   265,   232,   229,   229,   236,
     312,   239,   137,   239,   239,   239,   341,   307,   312,   239
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   145,   147,   146,   148,   149,   149,   149,   149,   150,
     151,   150,   152,   153,   154,   154,   154,   154,   155,   156,
     155,   158,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   159,   159,   160,   160,   160,
     160,   160,   160,   161,   162,   162,   163,   163,   165,   164,
     166,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   177,   177,   177,   178,   178,   178,   178,   178,
     179,   179,   180,   180,   181,   182,   181,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   186,
     185,   185,   185,   187,   188,   188,   188,   188,   189,   190,
     190,   191,   191,   191,   191,   191,   192,   192,   192,   192,
     192,   194,   193,   195,   196,   196,   197,   197,   197,   197,
     198,   198,   199,   199,   199,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   201,   200,   202,   200,
     203,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   204,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   205,   206,   200,   207,   208,   200,   200,   200,   209,
     210,   200,   211,   200,   212,   213,   200,   214,   200,   215,
     200,   216,   217,   200,   200,   200,   200,   200,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   230,   230,   231,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   238,   238,   238,   238,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   241,   242,   242,   242,
     243,   243,   244,   244,   245,   245,   247,   248,   249,   246,
     250,   250,   251,   251,   253,   252,   254,   254,   254,   254,
     255,   256,   255,   257,   255,   255,   258,   255,   259,   255,
     255,   255,   255,   261,   260,   262,   260,   263,   264,   264,
     265,   265,   266,   266,   266,   267,   267,   268,   268,   269,
     269,   269,   270,   271,   271,   271,   272,   273,   274,   275,
     275,   276,   276,   277,   277,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   284,   285,
     285,   286,   286,   287,   288,   287,   289,   290,   291,   287,
     292,   292,   292,   292,   293,   294,   294,   294,   294,   295,
     296,   296,   297,   297,   297,   297,   298,   298,   298,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   304,   303,   303,   305,   305,
     306,   306,   306,   306,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   309,   309,   309,   309,   310,   310,   311,   311,   312,
     312,   313,   314,   314,   315,   315,   316,   316,   317,   317,
     318,   318,   319,   319,   320,   321,   322,   322,   323,   323,
     324,   324,   325,   325,   326,   326,   327,   328,   328,   329,
     330,   329,   331,   331,   332,   332,   333,   333,   333,   333,
     334,   334,   334,   335,   335,   335,   335,   336,   336,   336,
     337,   337,   338,   338,   339,   339,   340,   341,   342,   342,
     342,   343,   343,   344,   344,   345
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
       0,     4,     1,     2,     1,     3,     3,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     1,     2,     2,     0,     1,
       1,     1,     1,     1,     2,     0
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
#line 580 "grammar.y" /* yacc.c:1646  */
    {
                    lex_state = EXPR_BEG;
                    local_push(0);
                    class_nest = 0;
                  }
#line 4590 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 586 "grammar.y" /* yacc.c:1646  */
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
#line 4612 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 606 "grammar.y" /* yacc.c:1646  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4621 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 613 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4629 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 617 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4637 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 621 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4645 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 625 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4653 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 632 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single) {
                      yy_error("BEGIN in method");
                    }
                  }
#line 4663 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 638 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_PREEXE((yyvsp[-1].node));
                  }
#line 4671 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 647 "grammar.y" /* yacc.c:1646  */
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
#line 4693 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 667 "grammar.y" /* yacc.c:1646  */
    {
                    void_stmts((yyvsp[-1].node));
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 4702 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 674 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4710 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 678 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = newline_node((yyvsp[0].node));
                  }
#line 4718 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 682 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = block_append((yyvsp[-2].node), newline_node((yyvsp[0].node)));
                  }
#line 4726 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 686 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = remove_begin((yyvsp[0].node));
                  }
#line 4734 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 692 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4742 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 696 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("BEGIN is permitted only at toplevel");
                  }
#line 4750 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 700 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4758 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 705 "grammar.y" /* yacc.c:1646  */
    {lex_state = EXPR_FNAME;}
#line 4764 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 706 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ALIAS((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4772 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 710 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 4780 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 714 "grammar.y" /* yacc.c:1646  */
    {
                    char buf[2];
                    buf[0] = '$';
                    buf[1] = (char)(yyvsp[0].node)->nd_nth;
                    (yyval.node) = NEW_VALIAS((yyvsp[-1].id), parser_intern2(buf, 2));
                  }
#line 4791 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 721 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("can't make alias for the number variables");
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4800 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 726 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 4808 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 730 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4817 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 735 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[0].node)), remove_begin((yyvsp[-2].node)), 0);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 4826 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 740 "grammar.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4838 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 748 "grammar.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
                    } else {
                      (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
                    }
                  }
#line 4850 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 756 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *resq = NEW_RESBODY(0, remove_begin((yyvsp[0].node)), 0);
                    (yyval.node) = NEW_RESCUE(remove_begin((yyvsp[-2].node)), resq, 0);
                  }
#line 4859 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 761 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single) {
                      rb_warn("END in method; use at_exit");
                    }

                    (yyval.node) = NEW_POSTEXE(NEW_NODE(NODE_SCOPE,
                            0 /* tbl */, (yyvsp[-1].node) /* body */, 0 /* args */));
                  }
#line 4872 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 771 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 4882 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 777 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4891 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 782 "grammar.y" /* yacc.c:1646  */
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
#line 4912 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 799 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4921 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 804 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4930 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 809 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4939 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 814 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 4948 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 819 "grammar.y" /* yacc.c:1646  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 4957 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 824 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4966 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 829 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[-2].node)->nd_value = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 4975 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 837 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4984 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 842 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 4993 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 850 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5001 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 854 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5009 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 858 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5017 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 862 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 5025 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 869 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 5035 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 882 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5043 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 888 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 5052 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 895 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 5062 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 903 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                    nd_set_line((yyval.node), tokline);
                  }
#line 5071 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 910 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                 }
#line 5080 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 915 "grammar.y" /* yacc.c:1646  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[-2].node)->nd_args = (yyvsp[-1].node);
                    (yyvsp[0].node)->nd_iter = (yyvsp[-2].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-2].node));
                 }
#line 5092 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 923 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5101 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 928 "grammar.y" /* yacc.c:1646  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                 }
#line 5112 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 935 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 5121 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 940 "grammar.y" /* yacc.c:1646  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 5132 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 947 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5141 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 952 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_yield((yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 5150 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 957 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_RETURN(ret_args((yyvsp[0].node)));
                  }
#line 5158 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 961 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_BREAK(ret_args((yyvsp[0].node)));
                  }
#line 5166 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 965 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_NEXT(ret_args((yyvsp[0].node)));
                  }
#line 5174 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 972 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5182 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 979 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(NEW_LIST((yyvsp[-1].node)), 0);
                  }
#line 5190 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 985 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 5198 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 989 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(list_append((yyvsp[-1].node), (yyvsp[0].node)), 0);
                  }
#line 5206 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 993 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5214 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 997 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5222 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1001 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-1].node), -1);
                  }
#line 5230 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1005 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5238 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1009 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(0, (yyvsp[0].node));
                  }
#line 5246 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1013 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyvsp[-2].node), (yyvsp[0].node)));
                  }
#line 5254 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1017 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 5262 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1021 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 5270 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1028 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 5278 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1034 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[-1].node));
                  }
#line 5286 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1038 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 5294 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1044 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 5302 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1048 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5310 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1054 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5318 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1058 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 5326 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1062 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5334 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1066 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5342 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1070 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5350 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1074 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5358 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1078 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5368 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1084 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5378 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1090 "grammar.y" /* yacc.c:1646  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5387 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1097 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5396 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1102 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    if(!(yyval.node)) (yyval.node) = NEW_BEGIN(0);
                  }
#line 5405 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1107 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
                  }
#line 5413 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1111 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5421 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1115 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5429 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1119 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5437 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1123 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
                  }
#line 5447 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1129 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single)
                      yy_error("dynamic constant assignment");
                    (yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
                  }
#line 5457 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1135 "grammar.y" /* yacc.c:1646  */
    {
                    rb_backref_error((yyvsp[0].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5466 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1142 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("class/module name must be CONSTANT");
                  }
#line 5474 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1149 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 5482 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1153 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON2(0, (yyval.node));
                  }
#line 5490 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1157 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 5498 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1166 "grammar.y" /* yacc.c:1646  */
    {
                    lex_state = EXPR_ENDFN;
                    (yyval.id) = convert_op((yyvsp[0].id));
                  }
#line 5507 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1171 "grammar.y" /* yacc.c:1646  */
    {
                    lex_state = EXPR_ENDFN;
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 5516 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1182 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 5524 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1189 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_UNDEF((yyvsp[0].node));
                  }
#line 5532 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1192 "grammar.y" /* yacc.c:1646  */
    {lex_state = EXPR_FNAME;}
#line 5538 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1193 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = block_append((yyvsp[-3].node), NEW_UNDEF((yyvsp[0].node)));
                  }
#line 5546 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1198 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '|'; }
#line 5552 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1199 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '^'; }
#line 5558 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1200 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '&'; }
#line 5564 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1201 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tCMP; }
#line 5570 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1202 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tEQ; }
#line 5576 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1203 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tEQQ; }
#line 5582 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1204 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tMATCH; }
#line 5588 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1205 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tNMATCH; }
#line 5594 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1206 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '>'; }
#line 5600 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1207 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tGEQ; }
#line 5606 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1208 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '<'; }
#line 5612 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1209 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tLEQ; }
#line 5618 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1210 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tNEQ; }
#line 5624 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1211 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tLSHFT; }
#line 5630 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1212 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tRSHFT; }
#line 5636 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1213 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '+'; }
#line 5642 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1214 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '-'; }
#line 5648 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1215 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '*'; }
#line 5654 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1216 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '*'; }
#line 5660 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1217 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '/'; }
#line 5666 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1218 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '%'; }
#line 5672 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1219 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tPOW; }
#line 5678 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1220 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tDSTAR; }
#line 5684 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1221 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '!'; }
#line 5690 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1222 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '~'; }
#line 5696 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1223 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tUPLUS; }
#line 5702 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1224 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tUMINUS; }
#line 5708 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1225 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tAREF; }
#line 5714 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1226 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = tASET; }
#line 5720 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1227 "grammar.y" /* yacc.c:1646  */
    { (yyval.id) = '`'; }
#line 5726 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1245 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5735 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1250 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    (yyval.node) = node_assign((yyvsp[-4].node), (yyvsp[-2].node));
                  }
#line 5745 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1256 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5754 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1261 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[-2].node));
                    (yyvsp[-2].node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0, (yyvsp[0].node), 0), 0);
                    new_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].node));
                  }
#line 5764 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1267 "grammar.y" /* yacc.c:1646  */
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
#line 5789 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1288 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5798 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1293 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5807 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1298 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5816 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1303 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-4].node), (yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5825 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1308 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[-2].id));
                    (yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 5834 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1313 "grammar.y" /* yacc.c:1646  */
    {
                    rb_backref_error((yyvsp[-2].node));
                    (yyval.node) = NEW_BEGIN(0);
                  }
#line 5843 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1318 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT2((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5853 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1324 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[-2].node));
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_DOT3((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 5863 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1330 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '+', (yyvsp[0].node));
                  }
#line 5871 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1334 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '-', (yyvsp[0].node));
                  }
#line 5879 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1338 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '*', (yyvsp[0].node));
                  }
#line 5887 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1342 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '/', (yyvsp[0].node));
                  }
#line 5895 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1346 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '%', (yyvsp[0].node));
                  }
#line 5903 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1350 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node));
                  }
#line 5911 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1354 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL(call_bin_op((yyvsp[-2].node), tPOW, (yyvsp[0].node)), tUMINUS, 0);
                  }
#line 5919 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1358 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUPLUS);
                  }
#line 5927 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1362 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), tUMINUS);
                  }
#line 5935 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1366 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '|', (yyvsp[0].node));
                  }
#line 5943 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1370 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '^', (yyvsp[0].node));
                  }
#line 5951 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1374 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '&', (yyvsp[0].node));
                  }
#line 5959 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1378 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tCMP, (yyvsp[0].node));
                  }
#line 5967 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1382 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '>', (yyvsp[0].node));
                  }
#line 5975 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1386 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tGEQ, (yyvsp[0].node));
                  }
#line 5983 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1390 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), '<', (yyvsp[0].node));
                  }
#line 5991 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1394 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLEQ, (yyvsp[0].node));
                  }
#line 5999 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1398 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQ, (yyvsp[0].node));
                  }
#line 6007 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1402 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tEQQ, (yyvsp[0].node));
                  }
#line 6015 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1406 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNEQ, (yyvsp[0].node));
                  }
#line 6023 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1410 "grammar.y" /* yacc.c:1646  */
    {
                    /* TODO */
                    (yyval.node) = match_op((yyvsp[-2].node), (yyvsp[0].node));
                    /*
                    if(nd_type($1) == NODE_LIT && TYPE($1->nd_lit) == T_REGEXP) {
                      $$ = reg_named_capture_assign($1->nd_lit, $$);
                    }
                    */
                  }
#line 6037 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1420 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tNMATCH, (yyvsp[0].node));
                  }
#line 6045 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1424 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[0].node)), '!');
                  }
#line 6053 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1428 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op((yyvsp[0].node), '~');
                  }
#line 6061 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1432 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tLSHFT, (yyvsp[0].node));
                  }
#line 6069 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1436 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_bin_op((yyvsp[-2].node), tRSHFT, (yyvsp[0].node));
                  }
#line 6077 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1440 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6085 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1444 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6093 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1447 "grammar.y" /* yacc.c:1646  */
    {in_defined = 1;}
#line 6099 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1448 "grammar.y" /* yacc.c:1646  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[0].node));
                  }
#line 6108 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1453 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[-5].node));
                    (yyval.node) = NEW_IF(cond((yyvsp[-5].node)), (yyvsp[-3].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-5].node));
                  }
#line 6118 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1459 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6126 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1465 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6136 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1474 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6144 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1478 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6152 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1482 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6160 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1488 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6168 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1500 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6176 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1504 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                  }
#line 6184 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1508 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                  }
#line 6192 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1514 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6201 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1519 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = arg_blk_pass((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 6209 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1523 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6218 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1528 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
                    (yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
                  }
#line 6227 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1535 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.val) = cmdarg_stack;
                    CMDARG_PUSH(1);
                  }
#line 6236 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1540 "grammar.y" /* yacc.c:1646  */
    {
                    /* CMDARG_POP() */
                    cmdarg_stack = (yyvsp[-1].val);
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6246 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1548 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_BLOCK_PASS((yyvsp[0].node));
                  }
#line 6254 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1554 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6262 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1558 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 6270 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1564 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6278 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1568 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6286 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1572 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6299 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1581 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *n1;
                    if((nd_type((yyvsp[0].node)) == NODE_ARRAY) && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6312 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1596 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *n1;
                    if((n1 = splat_array((yyvsp[-2].node))) != 0) {
                      (yyval.node) = list_append(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
                    }
                  }
#line 6325 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1605 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *n1;
                    if(nd_type((yyvsp[0].node)) == NODE_ARRAY && (n1 = splat_array((yyvsp[-3].node))) != 0) {
                      (yyval.node) = list_concat(n1, (yyvsp[0].node));
                    } else {
                      (yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
                    }
                  }
#line 6338 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1614 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_SPLAT((yyvsp[0].node));
                  }
#line 6346 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1630 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
                  }
#line 6354 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1634 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].val) = cmdarg_stack;
                    cmdarg_stack = 0;
                    (yyval.num) = sourceline;
                  }
#line 6364 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1641 "grammar.y" /* yacc.c:1646  */
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
#line 6381 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1653 "grammar.y" /* yacc.c:1646  */
    {lex_state = EXPR_ENDARG;}
#line 6387 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1654 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 6395 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1657 "grammar.y" /* yacc.c:1646  */
    {lex_state = EXPR_ENDARG;}
#line 6401 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1658 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 6409 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1662 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6417 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1666 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
                  }
#line 6425 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1670 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_COLON3((yyvsp[0].id));
                  }
#line 6433 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1674 "grammar.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].node) == 0) {
                      (yyval.node) = NEW_ZARRAY(); /* zero length array*/
                    } else {
                      (yyval.node) = (yyvsp[-1].node);
                    }
                  }
#line 6445 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1682 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_HASH((yyvsp[-1].node));
                  }
#line 6453 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1686 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_RETURN(0);
                  }
#line 6461 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1690 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_yield((yyvsp[-1].node));
                  }
#line 6469 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1694 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6477 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1698 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_YIELD(0, Qfalse);
                  }
#line 6485 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 1701 "grammar.y" /* yacc.c:1646  */
    {in_defined = 1;}
#line 6491 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1702 "grammar.y" /* yacc.c:1646  */
    {
                    in_defined = 0;
                    (yyval.node) = NEW_DEFINED((yyvsp[-1].node));
                  }
#line 6500 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1707 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op(cond((yyvsp[-1].node)), '!');
                  }
#line 6508 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 1711 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = call_uni_op(cond(NEW_NIL()), '!');
                  }
#line 6516 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 1715 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyvsp[0].node)->nd_iter, (yyvsp[0].node));
                  }
#line 6526 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 1722 "grammar.y" /* yacc.c:1646  */
    {
                    block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-1].node));
                  }
#line 6537 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 1729 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6545 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 1736 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6554 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 1744 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_UNLESS(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6563 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 1748 "grammar.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 6569 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 1748 "grammar.y" /* yacc.c:1646  */
    {COND_POP();}
#line 6575 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 1751 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_WHILE(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6584 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 1755 "grammar.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 6590 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 1755 "grammar.y" /* yacc.c:1646  */
    {COND_POP();}
#line 6596 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 1758 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_UNTIL(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 6605 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 1765 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CASE((yyvsp[-3].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 6614 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 1770 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CASE(0, (yyvsp[-1].node));
                  }
#line 6622 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 1774 "grammar.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 6628 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 1776 "grammar.y" /* yacc.c:1646  */
    {COND_POP();}
#line 6634 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 1779 "grammar.y" /* yacc.c:1646  */
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
#line 6652 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 1793 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single)
                      yy_error("class definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6664 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 1802 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CLASS((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-3].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6675 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 1809 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = in_def;
                    in_def = 0;
                  }
#line 6684 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 1814 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = in_single;
                    in_single = 0;
                    class_nest++;
                    local_push(0);
                  }
#line 6695 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 1822 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_SCLASS((yyvsp[-5].node), (yyvsp[-1].node));
                    fixpos((yyval.node), (yyvsp[-5].node));
                    local_pop();
                    class_nest--;
                    in_def = (yyvsp[-4].num);
                    in_single = (yyvsp[-2].num);
                  }
#line 6708 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 1831 "grammar.y" /* yacc.c:1646  */
    {
                    if(in_def || in_single)
                      yy_error("module definition in method body");
                    class_nest++;
                    local_push(0);
                    (yyval.num) = sourceline;
                  }
#line 6720 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 1840 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MODULE((yyvsp[-3].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-2].num));
                    local_pop();
                    class_nest--;
                  }
#line 6731 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 1847 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.id) = cur_mid;
                    cur_mid = (yyvsp[0].id);
                    in_def++;
                    local_push(0);
                  }
#line 6742 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 1856 "grammar.y" /* yacc.c:1646  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFN((yyvsp[-4].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
                    nd_set_line((yyval.node), (yyvsp[-5].num));
                    local_pop();
                    in_def--;
                    cur_mid = (yyvsp[-3].id);
                  }
#line 6755 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 1864 "grammar.y" /* yacc.c:1646  */
    {lex_state = EXPR_FNAME;}
#line 6761 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 1865 "grammar.y" /* yacc.c:1646  */
    {
                    in_single++;
                    lex_state = EXPR_ENDFN; /* force for args */
                    local_push(0);
                  }
#line 6771 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 1873 "grammar.y" /* yacc.c:1646  */
    {
                    NODE* body = remove_begin((yyvsp[-1].node));
                    (yyval.node) = NEW_DEFS((yyvsp[-7].node), (yyvsp[-4].id), (yyvsp[-2].node), body);
                    nd_set_line((yyval.node), (yyvsp[-8].num));
                    local_pop();
                    in_single--;
                  }
#line 6783 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 1881 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_BREAK(0);
                  }
#line 6791 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 1885 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_NEXT(0);
                  }
#line 6799 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 1889 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_REDO();
                  }
#line 6807 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 1893 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_RETRY();
                  }
#line 6815 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 1899 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 6825 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 1907 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("begin");
                  }
#line 6833 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 1913 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("if");
                  }
#line 6841 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 1919 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("unless");
                  }
#line 6849 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 1925 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("while");
                  }
#line 6857 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 1931 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("until");
                  }
#line 6865 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 1937 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("case");
                  }
#line 6873 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 1943 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("for");
                  }
#line 6881 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 1949 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("class");
                  }
#line 6889 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 1955 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("module");
                  }
#line 6897 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 1961 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_push("def");
                    (yyval.num) = sourceline;
                  }
#line 6906 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 1968 "grammar.y" /* yacc.c:1646  */
    {
                    token_info_pop("end");
                  }
#line 6914 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 1986 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_IF(cond((yyvsp[-3].node)), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 6923 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 1994 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 6931 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2004 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 6939 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2008 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 6947 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2014 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 6955 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2018 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 6963 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2024 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
                  }
#line 6971 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2028 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-3].node), (yyval.node));
                  }
#line 6980 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2033 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN((yyvsp[-5].node), NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 6989 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2038 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-2].node), -1);
                  }
#line 6997 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2042 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7005 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2046 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                    (yyval.node) = NEW_MASGN(0, (yyval.node));
                  }
#line 7014 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2051 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[-2].id), 0);
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyval.node), (yyvsp[0].node)));
                  }
#line 7023 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2056 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(0, -1);
                  }
#line 7031 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2060 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1, (yyvsp[0].node)));
                  }
#line 7039 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2066 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7047 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2070 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 7055 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2074 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 7063 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2078 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 7071 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2084 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7079 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2088 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 7087 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2094 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7095 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2098 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7103 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2102 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7111 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2106 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7119 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2110 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7127 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2114 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 1, 0, new_args_tail(0, 0, 0));
                  }
#line 7135 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2118 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7143 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2122 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 7151 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2126 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7159 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2130 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7167 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2134 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 7175 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2138 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7183 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2142 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 7191 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2146 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7199 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2150 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 7207 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2157 "grammar.y" /* yacc.c:1646  */
    {
                    command_start = TRUE;
                  }
#line 7215 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2163 "grammar.y" /* yacc.c:1646  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX(0, (yyvsp[-1].node)) : 0;
                  }
#line 7224 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2168 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7232 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2172 "grammar.y" /* yacc.c:1646  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[-1].node) ? NEW_ARGS_AUX((yyvsp[-2].node), (yyvsp[-1].node)) : (yyvsp[-2].node);
                  }
#line 7241 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2179 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7249 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2183 "grammar.y" /* yacc.c:1646  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7258 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2190 "grammar.y" /* yacc.c:1646  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7267 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2195 "grammar.y" /* yacc.c:1646  */
    {
                    // This is deliberately different than MRI.
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 7276 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2202 "grammar.y" /* yacc.c:1646  */
    {
                    new_bv(get_id((yyvsp[0].id)));
                    // This is deliberately different than MRI.
                    (yyval.node) = NEW_LIT(ID2SYM(get_id((yyvsp[0].id))));
                  }
#line 7286 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2208 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7294 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2213 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.vars) = bv_push();
                  }
#line 7302 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2216 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = lpar_beg;
                    lpar_beg = ++paren_nest;
                  }
#line 7311 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2221 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7319 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2225 "grammar.y" /* yacc.c:1646  */
    {
                    lpar_beg = (yyvsp[-3].num);
                    (yyval.node) = NEW_LAMBDA((yyvsp[-2].node), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7330 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2234 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 7338 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2238 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7346 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2244 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7354 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2248 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7362 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2254 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7371 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2261 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7381 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2269 "grammar.y" /* yacc.c:1646  */
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
#line 7396 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2280 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
                  }
#line 7404 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2284 "grammar.y" /* yacc.c:1646  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7415 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2291 "grammar.y" /* yacc.c:1646  */
    {
                    block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
                    (yyvsp[0].node)->nd_iter = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
                    (yyval.node) = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[-4].node));
                  }
#line 7426 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2300 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    (yyval.node)->nd_args = (yyvsp[0].node);
                    fixpos((yyval.node), (yyvsp[0].node));
                  }
#line 7436 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2306 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7444 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2310 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7453 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2315 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7461 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2319 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7470 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2324 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].id), 0);
                  }
#line 7478 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2328 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7486 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2332 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7495 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2337 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = sourceline;
                  }
#line 7503 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2341 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_CALL((yyvsp[-3].node), parser_intern("call"), (yyvsp[0].node));
                    nd_set_line((yyval.node), (yyvsp[-1].num));
                  }
#line 7512 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2346 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_SUPER((yyvsp[0].node));
                  }
#line 7520 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2350 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ZSUPER();
                  }
#line 7528 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2354 "grammar.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-3].node) && nd_type((yyvsp[-3].node)) == NODE_SELF) {
                      (yyval.node) = NEW_FCALL(tAREF, (yyvsp[-1].node));
                    } else {
                      (yyval.node) = NEW_CALL((yyvsp[-3].node), tAREF, (yyvsp[-1].node));
                    }
                    fixpos((yyval.node), (yyvsp[-3].node));
                  }
#line 7541 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2365 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7550 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2371 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7560 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2377 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].vars) = bv_push();
                    (yyval.num) = sourceline;
                  }
#line 7569 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2383 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ITER((yyvsp[-2].node), (yyvsp[-1].node));
                    nd_set_line((yyval.node), (yyvsp[-3].num));
                    bv_pop((yyvsp[-4].vars));
                  }
#line 7579 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2393 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_WHEN((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7587 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2405 "grammar.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-3].node)) {
                      /* TODO NEW_ERRINFO() */
                      (yyvsp[-3].node) = node_assign((yyvsp[-3].node), NEW_GVAR(parser_intern("$!")));
                      (yyvsp[-1].node) = block_append((yyvsp[-3].node), (yyvsp[-1].node));
                    }
                    (yyval.node) = NEW_RESBODY((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[0].node));
                    fixpos((yyval.node), (yyvsp[-4].node) ? (yyvsp[-4].node) : (yyvsp[-1].node));
                  }
#line 7601 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 2418 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIST((yyvsp[0].node));
                  }
#line 7609 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 2422 "grammar.y" /* yacc.c:1646  */
    {
                    if(!((yyval.node) = splat_array((yyvsp[0].node)))) (yyval.node) = (yyvsp[0].node);
                  }
#line 7617 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 2429 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7625 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 2436 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 7633 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 2444 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
                  }
#line 7641 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 2451 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *node = (yyvsp[0].node);
                    if(!node) {
                      node = NEW_STR(STR_NEW0());
                    } else {
                      node = evstr2dstr(node);
                    }
                    (yyval.node) = node;
                  }
#line 7655 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 2465 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7663 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2471 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7671 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2477 "grammar.y" /* yacc.c:1646  */
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
#line 7695 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2499 "grammar.y" /* yacc.c:1646  */
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
#line 7757 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2559 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7765 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2563 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7773 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2569 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7781 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2573 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), evstr2dstr((yyvsp[-1].node)));
                  }
#line 7789 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2580 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7797 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2586 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7805 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2590 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7813 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 2596 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7821 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2600 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].node) = evstr2dstr((yyvsp[-1].node));
                    nd_set_type((yyvsp[-1].node), NODE_DSYM);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7831 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2608 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7839 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2612 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7847 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2618 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = NEW_ZARRAY();
                  }
#line 7855 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2622 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 7863 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2628 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7871 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2632 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7879 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2638 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7887 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2642 "grammar.y" /* yacc.c:1646  */
    {
                    VALUE lit;
                    lit = (yyvsp[-1].node)->nd_lit;
                    (yyvsp[-1].node)->nd_lit = ID2SYM(parser_intern_str(lit));
                    nd_set_type((yyvsp[-1].node), NODE_LIT);
                    (yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
                  }
#line 7899 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2652 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7907 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2656 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7915 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2662 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7923 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 2666 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 7931 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2672 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 7939 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2676 "grammar.y" /* yacc.c:1646  */
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
#line 7964 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2700 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                    lex_state = EXPR_BEG;
                  }
#line 7974 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2706 "grammar.y" /* yacc.c:1646  */
    {
                    lex_strterm = (yyvsp[-1].node);
                    (yyval.node) = NEW_EVSTR((yyvsp[0].node));
                  }
#line 7983 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2711 "grammar.y" /* yacc.c:1646  */
    {
                    (yyvsp[0].val) = cond_stack;
                    (yyval.val) = cmdarg_stack;
                    cond_stack = 0;
                    cmdarg_stack = 0;
                  }
#line 7994 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2717 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = lex_strterm;
                    lex_strterm = 0;
                    lex_state = EXPR_BEG;
                  }
#line 8004 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2722 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.num) = brace_nest;
                    brace_nest = 0;
                  }
#line 8013 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2727 "grammar.y" /* yacc.c:1646  */
    {
                    cond_stack = (yyvsp[-5].val);
                    cmdarg_stack = (yyvsp[-4].val);
                    lex_strterm = (yyvsp[-3].node);
                    brace_nest = (yyvsp[-2].num);

                    if((yyvsp[-1].node)) (yyvsp[-1].node)->flags &= ~NODE_FL_NEWLINE;
                    (yyval.node) = new_evstr((yyvsp[-1].node));
                  }
#line 8027 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2738 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NEW_GVAR((yyvsp[0].id));}
#line 8033 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2739 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NEW_IVAR((yyvsp[0].id));}
#line 8039 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2740 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = NEW_CVAR((yyvsp[0].id));}
#line 8045 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2745 "grammar.y" /* yacc.c:1646  */
    {
                    lex_state = EXPR_END;
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8054 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2758 "grammar.y" /* yacc.c:1646  */
    {
                    lex_state = EXPR_END;
                    (yyval.node) = dsym_node((yyvsp[-1].node));
                  }
#line 8063 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2766 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = negate_lit((yyvsp[0].node));
                  }
#line 8071 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 2784 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword_nil;}
#line 8077 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 2785 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword_self;}
#line 8083 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 2786 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword_true;}
#line 8089 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 2787 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword_false;}
#line 8095 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 2788 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword__FILE__;}
#line 8101 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 2789 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword__LINE__;}
#line 8107 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 2790 "grammar.y" /* yacc.c:1646  */
    {(yyval.id) = keyword__ENCODING__;}
#line 8113 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 2794 "grammar.y" /* yacc.c:1646  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8123 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 2800 "grammar.y" /* yacc.c:1646  */
    {
                    if(!((yyval.node) = gettable((yyvsp[0].id)))) {
                      (yyval.node) = NEW_BEGIN(0);
                    }
                  }
#line 8133 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 2808 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8141 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 2812 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), 0);
                  }
#line 8149 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 2822 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = 0;
                  }
#line 8157 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 2826 "grammar.y" /* yacc.c:1646  */
    {
                    lex_state = EXPR_BEG;
                    command_start = TRUE;
                  }
#line 8166 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 2831 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8174 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 2835 "grammar.y" /* yacc.c:1646  */
    {
                    yyerrok;
                    (yyval.node) = 0;
                  }
#line 8183 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 2842 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    lex_state = EXPR_BEG;
                    command_start = TRUE;
                  }
#line 8193 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 2848 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                    lex_state = EXPR_BEG;
                    command_start = TRUE;
                  }
#line 8203 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 2856 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8211 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 2860 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail((yyvsp[-1].node), 0, (yyvsp[0].id));
                  }
#line 8219 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 2864 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, (yyvsp[-1].id), (yyvsp[0].id));
                  }
#line 8227 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 2868 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, 0, (yyvsp[0].id));
                  }
#line 8235 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 2874 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8243 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 2878 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                  }
#line 8251 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 2884 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8259 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 2888 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8267 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 2892 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8275 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 2896 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8283 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 2900 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-3].node), 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8291 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 2904 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-5].node), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8299 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 2908 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args((yyvsp[-1].node), 0, 0, 0, (yyvsp[0].node));
                  }
#line 8307 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 2912 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8315 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 2916 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8323 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 2920 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].node));
                  }
#line 8331 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 2924 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8339 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 2928 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].node));
                  }
#line 8347 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 2932 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node));
                  }
#line 8355 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 2936 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].node));
                  }
#line 8363 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 2940 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_args_tail(0, 0, 0);
                    (yyval.node) = new_args(0, 0, 0, 0, (yyval.node));
                  }
#line 8372 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 2947 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("formal argument cannot be a constant");
                    (yyval.id) = 0;
                  }
#line 8381 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 2952 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("formal argument cannot be an instance variable");
                    (yyval.id) = 0;
                  }
#line 8390 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 2957 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("formal argument cannot be a global variable");
                    (yyval.id) = 0;
                  }
#line 8399 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 2962 "grammar.y" /* yacc.c:1646  */
    {
                    yy_error("formal argument cannot be a class variable");
                    (yyval.id) = 0;
                  }
#line 8408 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 2970 "grammar.y" /* yacc.c:1646  */
    {
                    formal_argument(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8417 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 2977 "grammar.y" /* yacc.c:1646  */
    {
                    arg_var(get_id((yyvsp[0].id)));
                    (yyval.node) = NEW_ARGS_AUX((yyvsp[0].id), 1);
                  }
#line 8426 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 2982 "grammar.y" /* yacc.c:1646  */
    {
                    ID tid = internal_id();
                    arg_var(tid);
                    (yyvsp[-1].node)->nd_value = NEW_LVAR(tid);
                    (yyval.node) = NEW_ARGS_AUX(tid, 1);
                    (yyval.node)->nd_next = (yyvsp[-1].node);
                  }
#line 8438 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 560:
#line 2993 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-2].node);
                    (yyval.node)->nd_plen++;
                    (yyval.node)->nd_next = block_append((yyval.node)->nd_next, (yyvsp[0].node)->nd_next);
                  }
#line 8448 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 3001 "grammar.y" /* yacc.c:1646  */
    {
                    arg_var(formal_argument(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8457 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 562:
#line 3008 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8466 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 3013 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8475 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 564:
#line 3020 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node));
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8484 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 565:
#line 3025 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = assignable((yyvsp[0].id), NEW_REQ_KW);
                    (yyval.node) = NEW_KW_ARG(0, (yyval.node));
                  }
#line 8493 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 566:
#line 3032 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8501 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 567:
#line 3036 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while (kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8514 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 568:
#line 3047 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8522 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 569:
#line 3051 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *kws = (yyvsp[-2].node);
                    while (kws->nd_next) {
                      kws = kws->nd_next;
                    }
                    kws->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8535 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 572:
#line 3066 "grammar.y" /* yacc.c:1646  */
    {
                    shadowing_lvar(get_id((yyvsp[0].id)));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8544 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 573:
#line 3071 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.id) = internal_id();
                  }
#line 8552 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 3077 "grammar.y" /* yacc.c:1646  */
    {
                    arg_var(get_id((yyvsp[-2].id)));
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8562 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 3085 "grammar.y" /* yacc.c:1646  */
    {
                    arg_var(get_id((yyvsp[-2].id)));
                    (yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node));
                    (yyval.node) = NEW_OPT_ARG(0, (yyval.node));
                  }
#line 8572 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 3093 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8580 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 577:
#line 3097 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8593 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 578:
#line 3108 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                  }
#line 8601 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 579:
#line 3112 "grammar.y" /* yacc.c:1646  */
    {
                    NODE *opts = (yyvsp[-2].node);
                    while(opts->nd_next) {
                      opts = opts->nd_next;
                    }
                    opts->nd_next = (yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                  }
#line 8614 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 582:
#line 3127 "grammar.y" /* yacc.c:1646  */
    {
                    if(!is_local_id((yyvsp[0].id))) {
                      yy_error("rest argument must be local variable");
                    }
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8626 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 3135 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.id) = internal_id();
                    arg_var((yyval.id));
                  }
#line 8635 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 3146 "grammar.y" /* yacc.c:1646  */
    {
                    if(!is_local_id((yyvsp[0].id)))
                      yy_error("block argument must be local variable");
                    else if(!in_block() && local_id((yyvsp[0].id)))
                      yy_error("duplicate block argument name");
                    arg_var(shadowing_lvar(get_id((yyvsp[0].id))));
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8648 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 587:
#line 3157 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.id) = (yyvsp[0].id);
                  }
#line 8656 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 588:
#line 3161 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.id) = 0;
                  }
#line 8664 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 589:
#line 3167 "grammar.y" /* yacc.c:1646  */
    {
                    value_expr((yyvsp[0].node));
                    (yyval.node) = (yyvsp[0].node);
                    if(!(yyval.node)) (yyval.node) = NEW_NIL();
                  }
#line 8674 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 590:
#line 3172 "grammar.y" /* yacc.c:1646  */
    {lex_state = EXPR_BEG;}
#line 8680 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 591:
#line 3173 "grammar.y" /* yacc.c:1646  */
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
#line 8706 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 593:
#line 3198 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[-1].node);
                  }
#line 8714 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 595:
#line 3205 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_concat((yyvsp[-2].node), (yyvsp[0].node));
                  }
#line 8722 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 596:
#line 3211 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append(NEW_LIST((yyvsp[-2].node)), (yyvsp[0].node));
                  }
#line 8730 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 597:
#line 3215 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append(NEW_LIST(NEW_LIT(ID2SYM((yyvsp[-1].id)))), (yyvsp[0].node));
                  }
#line 8738 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 598:
#line 3219 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append(NEW_LIST(dsym_node((yyvsp[-2].node))), (yyvsp[0].node));
                  }
#line 8746 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 599:
#line 3223 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = list_append(NEW_LIST(0), (yyvsp[0].node));
                  }
#line 8754 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 621:
#line 3267 "grammar.y" /* yacc.c:1646  */
    {yyerrok;}
#line 8760 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 624:
#line 3272 "grammar.y" /* yacc.c:1646  */
    {yyerrok;}
#line 8766 "grammar.cpp" /* yacc.c:1646  */
    break;

  case 625:
#line 3275 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = 0;}
#line 8772 "grammar.cpp" /* yacc.c:1646  */
    break;


#line 8776 "grammar.cpp" /* yacc.c:1646  */
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
#line 3277 "grammar.y" /* yacc.c:1906  */


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
  if(c == '~') {
    c = nextc();
    func = STR_FUNC_INDENT;
  }
  // HERE - tomkad
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
  int label;
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
      if(token == tSTRING_END && (lex_strterm->nd_func & STR_FUNC_LABEL)) {
        if(((lex_state_p(EXPR_BEG | EXPR_ENDFN) && !COND_P()) || IS_ARG()) && IS_LABEL_SUFFIX(0)) {
          nextc();
          token = tLABEL_END;
        }
      }
      if(token == tSTRING_END || token == tREGEXP_END || token == tLABEL_END) {
        lex_strterm = 0;
        lex_state = token == tLABEL_END ? EXPR_BEG : EXPR_END;
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
    label = IS_LABEL_POSSIBLE() ? str_label : 0;
    lex_strterm = NEW_STRTERM(str_dquote | label, '"', 0);
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
    label = IS_LABEL_POSSIBLE() ? str_label : 0;
    lex_strterm = NEW_STRTERM(str_squote | label, '\'', 0);
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
