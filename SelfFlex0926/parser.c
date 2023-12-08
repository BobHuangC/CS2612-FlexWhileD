/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"

	// this part is copied to the beginning of the parser 
	#include <stdio.h>
	#include "lang.h"
	#include "lexer.h"
	void yyerror(char *);
	int yylex(void);
        struct glob_item_list * root;

#line 81 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TM_NAT = 3,                     /* TM_NAT  */
  YYSYMBOL_TM_INT_TYPE = 4,                /* TM_INT_TYPE  */
  YYSYMBOL_TM_CHAR_TYPE = 5,               /* TM_CHAR_TYPE  */
  YYSYMBOL_TM_ENUM_TYPE = 6,               /* TM_ENUM_TYPE  */
  YYSYMBOL_TM_STRUCT_TYPE = 7,             /* TM_STRUCT_TYPE  */
  YYSYMBOL_TM_UNION_TYPE = 8,              /* TM_UNION_TYPE  */
  YYSYMBOL_TM_TYPEDEF_TYPE = 9,            /* TM_TYPEDEF_TYPE  */
  YYSYMBOL_TM_DEREFERENCE = 10,            /* TM_DEREFERENCE  */
  YYSYMBOL_TM_COMMA = 11,                  /* TM_COMMA  */
  YYSYMBOL_TM_LEFT_BRACE = 12,             /* TM_LEFT_BRACE  */
  YYSYMBOL_TM_RIGHT_BRACE = 13,            /* TM_RIGHT_BRACE  */
  YYSYMBOL_TM_LEFT_PAREN = 14,             /* TM_LEFT_PAREN  */
  YYSYMBOL_TM_RIGHT_PAREN = 15,            /* TM_RIGHT_PAREN  */
  YYSYMBOL_TM_LEFT_BRACKET = 16,           /* TM_LEFT_BRACKET  */
  YYSYMBOL_TM_RIGHT_BRACKET = 17,          /* TM_RIGHT_BRACKET  */
  YYSYMBOL_TM_SEMICOL = 18,                /* TM_SEMICOL  */
  YYSYMBOL_TM_IDENT = 19,                  /* TM_IDENT  */
  YYSYMBOL_YYACCEPT = 20,                  /* $accept  */
  YYSYMBOL_NT_WHOLE = 21,                  /* NT_WHOLE  */
  YYSYMBOL_NT_GLOB_ITEM_LIST = 22,         /* NT_GLOB_ITEM_LIST  */
  YYSYMBOL_NT_ARGUMENT_TYPE_LIST_inner = 23, /* NT_ARGUMENT_TYPE_LIST_inner  */
  YYSYMBOL_NT_ARGUMENT_TYPE_LIST = 24,     /* NT_ARGUMENT_TYPE_LIST  */
  YYSYMBOL_NT_ENUM_ELE_LIST = 25,          /* NT_ENUM_ELE_LIST  */
  YYSYMBOL_NT_FIELD_LIST = 26,             /* NT_FIELD_LIST  */
  YYSYMBOL_NT_ANNON_RIGHT_TYPE_EXPR = 27,  /* NT_ANNON_RIGHT_TYPE_EXPR  */
  YYSYMBOL_NT_NAMED_RIGHT_TYPE_EXPR = 28,  /* NT_NAMED_RIGHT_TYPE_EXPR  */
  YYSYMBOL_NT_LEFT_TYPE = 29,              /* NT_LEFT_TYPE  */
  YYSYMBOL_NT_GLOB_ITEM = 30               /* NT_GLOB_ITEM  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  20
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    74,    78,    85,    93,    94,    98,   102,
     106,   114,   118,   127,   130,   140,   144,   148,   152,   156,
     160,   170,   174,   178,   182,   186,   199,   203,   207,   212,
     216,   220,   225,   229,   233,   238,   242,   246,   257,   261,
     266,   270,   275,   279,   284,   289
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TM_NAT",
  "TM_INT_TYPE", "TM_CHAR_TYPE", "TM_ENUM_TYPE", "TM_STRUCT_TYPE",
  "TM_UNION_TYPE", "TM_TYPEDEF_TYPE", "TM_DEREFERENCE", "TM_COMMA",
  "TM_LEFT_BRACE", "TM_RIGHT_BRACE", "TM_LEFT_PAREN", "TM_RIGHT_PAREN",
  "TM_LEFT_BRACKET", "TM_RIGHT_BRACKET", "TM_SEMICOL", "TM_IDENT",
  "$accept", "NT_WHOLE", "NT_GLOB_ITEM_LIST",
  "NT_ARGUMENT_TYPE_LIST_inner", "NT_ARGUMENT_TYPE_LIST",
  "NT_ENUM_ELE_LIST", "NT_FIELD_LIST", "NT_ANNON_RIGHT_TYPE_EXPR",
  "NT_NAMED_RIGHT_TYPE_EXPR", "NT_LEFT_TYPE", "NT_GLOB_ITEM", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,   -71,   -71,    -9,    45,    47,    43,   -71,     8,   -71,
      44,     9,     7,    12,    43,    60,    43,    61,    48,    49,
      58,    44,   -71,    44,    44,   -71,    66,   -71,    28,    75,
       7,   -71,    92,    44,    43,   -71,    93,    43,   -71,    62,
      74,    95,    67,    26,    85,    43,   105,   -71,   -71,     7,
     -71,    96,   -71,    73,    97,   -71,    98,     7,    43,    43,
     -71,   -71,    99,    82,   100,   -71,    94,    43,   101,   102,
     103,   108,   109,   -71,    84,    43,    27,   -71,    -7,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,    55,   -71,    88,
      43,   110,   -71,   -71,   -71,   106,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    35,    36,     0,     0,     0,     0,    37,     0,     2,
       0,     3,     0,    34,    13,    28,    13,    31,     0,     0,
       0,     0,     1,     0,     0,    22,     0,     4,    11,     0,
       0,    43,     0,     0,    13,    39,     0,    13,    41,    34,
      28,    31,     0,    23,     0,     6,     0,    45,    25,     0,
      33,     0,    27,     0,     0,    30,     0,     0,    13,    13,
      44,    21,     0,    10,     0,    12,    32,    13,    26,    29,
       0,     0,     0,     5,    17,     6,     6,    20,     9,    24,
      42,    14,    38,    40,    32,    26,    29,    16,     8,     0,
       6,     0,    19,    15,     7,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   104,   -51,   -70,   -28,   -15,    21,    32,     0,
     -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    48,    62,    29,    32,    78,    26,    33,
      11
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      10,    36,    51,    12,    90,    88,    21,    45,    22,    91,
      13,    10,    77,     1,     2,     3,     4,     5,     6,    54,
      94,    65,    56,    77,    30,    77,    28,    92,     7,    70,
      31,     1,     2,    18,    19,    20,    92,    74,    92,    49,
      45,    76,    46,    71,    72,    63,     7,     1,     2,    18,
      19,    20,    81,    42,    23,    43,    44,    14,    24,    16,
      12,    14,     7,    25,    15,    53,    17,    39,    40,    45,
      16,    91,    34,    37,    57,    63,    63,    41,    35,    38,
      45,    45,    46,    46,    47,    60,    58,    45,    50,    46,
      63,    67,    74,    75,    74,    87,    76,    89,    76,    45,
      61,    46,    45,    93,    91,    52,    55,    59,    64,    66,
      68,    69,    80,    95,    73,    27,    84,    79,     0,    82,
      83,    85,    86,    96
};

static const yytype_int8 yycheck[] =
{
       0,    16,    30,    12,    11,    75,     6,    14,     0,    16,
      19,    11,    63,     4,     5,     6,     7,     8,     9,    34,
      90,    49,    37,    74,    12,    76,    19,    78,    19,    57,
      18,     4,     5,     6,     7,     8,    87,    10,    89,    11,
      14,    14,    16,    58,    59,    45,    19,     4,     5,     6,
       7,     8,    67,    21,    10,    23,    24,    12,    14,    12,
      12,    12,    19,    19,    19,    33,    19,    19,    19,    14,
      12,    16,    12,    12,    12,    75,    76,    19,    18,    18,
      14,    14,    16,    16,    18,    18,    12,    14,    13,    16,
      90,    18,    10,    11,    10,    74,    14,    76,    14,    14,
      15,    16,    14,    15,    16,    13,    13,    12,     3,    13,
      13,    13,    18,     3,    15,    11,    13,    17,    -1,    18,
      18,    13,    13,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    19,    21,    22,
      29,    30,    12,    19,    12,    19,    12,    19,     6,     7,
       8,    29,     0,    10,    14,    19,    28,    22,    19,    25,
      12,    18,    26,    29,    12,    18,    26,    12,    18,    19,
      19,    19,    28,    28,    28,    14,    16,    18,    23,    11,
      13,    25,    13,    28,    26,    13,    26,    12,    12,    12,
      18,    15,    24,    29,     3,    25,    13,    18,    13,    13,
      25,    26,    26,    15,    10,    11,    14,    23,    27,    17,
      18,    26,    18,    18,    13,    13,    13,    27,    24,    27,
      11,    16,    23,    15,    24,     3,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    20,    21,    22,    22,    23,    24,    24,    24,    24,
      24,    25,    25,    26,    26,    27,    27,    27,    27,    27,
      27,    28,    28,    28,    28,    28,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    30,    30,
      30,    30,    30,    30,    30,    30
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     0,     4,     3,     2,
       1,     1,     3,     0,     4,     3,     2,     1,     4,     2,
       1,     3,     1,     2,     4,     2,     5,     4,     2,     5,
       4,     2,     5,     4,     2,     1,     1,     1,     6,     3,
       6,     3,     6,     3,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* NT_WHOLE: NT_GLOB_ITEM_LIST  */
#line 67 "lang.y"
  {
    (yyval.e) = (yyvsp[0].e);
    root = (yyval.e);
  }
#line 1161 "parser.c"
    break;

  case 3: /* NT_GLOB_ITEM_LIST: NT_GLOB_ITEM  */
#line 75 "lang.y"
  {
    (yyval.e) = TGCons((yyvsp[0].e), TGNil());
  }
#line 1169 "parser.c"
    break;

  case 4: /* NT_GLOB_ITEM_LIST: NT_GLOB_ITEM NT_GLOB_ITEM_LIST  */
#line 79 "lang.y"
  {
    (yyval.e) = TGCons((yyvsp[-1].e), (yyvsp[0].e));
  }
#line 1177 "parser.c"
    break;

  case 5: /* NT_ARGUMENT_TYPE_LIST_inner: TM_LEFT_PAREN NT_ARGUMENT_TYPE_LIST TM_RIGHT_PAREN  */
#line 86 "lang.y"
    {
        (yyval.e) = (yyvsp[-1].e);
    }
#line 1185 "parser.c"
    break;

  case 6: /* NT_ARGUMENT_TYPE_LIST: %empty  */
#line 93 "lang.y"
    {(yyval.e) = TTNil();}
#line 1191 "parser.c"
    break;

  case 7: /* NT_ARGUMENT_TYPE_LIST: NT_LEFT_TYPE NT_ANNON_RIGHT_TYPE_EXPR TM_COMMA NT_ARGUMENT_TYPE_LIST  */
#line 95 "lang.y"
  {
    (yyval.e) = TTCons((yyvsp[-3].e), (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1199 "parser.c"
    break;

  case 8: /* NT_ARGUMENT_TYPE_LIST: NT_LEFT_TYPE TM_COMMA NT_ARGUMENT_TYPE_LIST  */
#line 99 "lang.y"
  {
    (yyval.e) = TTCons((yyvsp[-2].e), TOrigType(""), (yyvsp[0].e));
  }
#line 1207 "parser.c"
    break;

  case 9: /* NT_ARGUMENT_TYPE_LIST: NT_LEFT_TYPE NT_ANNON_RIGHT_TYPE_EXPR  */
#line 103 "lang.y"
  {
    (yyval.e) = TTCons((yyvsp[-1].e), (yyvsp[0].e), TTNil());
  }
#line 1215 "parser.c"
    break;

  case 10: /* NT_ARGUMENT_TYPE_LIST: NT_LEFT_TYPE  */
#line 107 "lang.y"
  {
    (yyval.e) = TTCons((yyvsp[0].e), TOrigType(""), TTNil());
  }
#line 1223 "parser.c"
    break;

  case 11: /* NT_ENUM_ELE_LIST: TM_IDENT  */
#line 115 "lang.y"
  {
    (yyval.e) = TECons((yyvsp[0].i), TENil());
  }
#line 1231 "parser.c"
    break;

  case 12: /* NT_ENUM_ELE_LIST: TM_IDENT TM_COMMA NT_ENUM_ELE_LIST  */
#line 119 "lang.y"
  {
    (yyval.e) = TECons((yyvsp[-2].i), (yyvsp[0].e));
  }
#line 1239 "parser.c"
    break;

  case 13: /* NT_FIELD_LIST: %empty  */
#line 127 "lang.y"
  {
    (yyval.e) = TTNil();
  }
#line 1247 "parser.c"
    break;

  case 14: /* NT_FIELD_LIST: NT_LEFT_TYPE NT_NAMED_RIGHT_TYPE_EXPR TM_SEMICOL NT_FIELD_LIST  */
#line 131 "lang.y"
  {
    (yyval.e) = TTCons((yyvsp[-3].e), (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1255 "parser.c"
    break;

  case 15: /* NT_ANNON_RIGHT_TYPE_EXPR: TM_LEFT_PAREN NT_ANNON_RIGHT_TYPE_EXPR TM_RIGHT_PAREN  */
#line 141 "lang.y"
  {
    (yyval.e) = (yyvsp[-1].e);
  }
#line 1263 "parser.c"
    break;

  case 16: /* NT_ANNON_RIGHT_TYPE_EXPR: TM_DEREFERENCE NT_ANNON_RIGHT_TYPE_EXPR  */
#line 145 "lang.y"
  {
    (yyval.e) = TPtrType((yyvsp[0].e));
  }
#line 1271 "parser.c"
    break;

  case 17: /* NT_ANNON_RIGHT_TYPE_EXPR: TM_DEREFERENCE  */
#line 149 "lang.y"
{
    (yyval.e) = TPtrType(TOrigType(""));
}
#line 1279 "parser.c"
    break;

  case 18: /* NT_ANNON_RIGHT_TYPE_EXPR: NT_ANNON_RIGHT_TYPE_EXPR TM_LEFT_BRACKET TM_NAT TM_RIGHT_BRACKET  */
#line 153 "lang.y"
  {
    (yyval.e) = TArrayType((yyvsp[-3].e), (yyvsp[-1].n));
  }
#line 1287 "parser.c"
    break;

  case 19: /* NT_ANNON_RIGHT_TYPE_EXPR: NT_ANNON_RIGHT_TYPE_EXPR NT_ARGUMENT_TYPE_LIST_inner  */
#line 157 "lang.y"
  {
    (yyval.e) = TFuncType((yyvsp[-1].e), (yyvsp[0].e));
  }
#line 1295 "parser.c"
    break;

  case 20: /* NT_ANNON_RIGHT_TYPE_EXPR: NT_ARGUMENT_TYPE_LIST_inner  */
#line 161 "lang.y"
  {
    (yyval.e) = TFuncType(TOrigType(""), (yyvsp[0].e));
  }
#line 1303 "parser.c"
    break;

  case 21: /* NT_NAMED_RIGHT_TYPE_EXPR: TM_LEFT_PAREN NT_NAMED_RIGHT_TYPE_EXPR TM_RIGHT_PAREN  */
#line 171 "lang.y"
  {
    (yyval.e) = (yyvsp[-1].e);
  }
#line 1311 "parser.c"
    break;

  case 22: /* NT_NAMED_RIGHT_TYPE_EXPR: TM_IDENT  */
#line 175 "lang.y"
  {
    (yyval.e) = TOrigType((yyvsp[0].i));
  }
#line 1319 "parser.c"
    break;

  case 23: /* NT_NAMED_RIGHT_TYPE_EXPR: TM_DEREFERENCE NT_NAMED_RIGHT_TYPE_EXPR  */
#line 179 "lang.y"
  {
    (yyval.e) = TPtrType((yyvsp[0].e));
  }
#line 1327 "parser.c"
    break;

  case 24: /* NT_NAMED_RIGHT_TYPE_EXPR: NT_NAMED_RIGHT_TYPE_EXPR TM_LEFT_BRACKET TM_NAT TM_RIGHT_BRACKET  */
#line 183 "lang.y"
  {
    (yyval.e) = TArrayType((yyvsp[-3].e), (yyvsp[-1].n));
  }
#line 1335 "parser.c"
    break;

  case 25: /* NT_NAMED_RIGHT_TYPE_EXPR: NT_NAMED_RIGHT_TYPE_EXPR NT_ARGUMENT_TYPE_LIST_inner  */
#line 187 "lang.y"
  {
    (yyval.e) = TFuncType((yyvsp[-1].e), (yyvsp[0].e));
  }
#line 1343 "parser.c"
    break;

  case 26: /* NT_LEFT_TYPE: TM_STRUCT_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE  */
#line 200 "lang.y"
  {
    (yyval.e) = TNewStructType((yyvsp[-3].i), (yyvsp[-1].e));
  }
#line 1351 "parser.c"
    break;

  case 27: /* NT_LEFT_TYPE: TM_STRUCT_TYPE TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE  */
#line 204 "lang.y"
  {
    (yyval.e) = TNewStructType(NULL, (yyvsp[-1].e));
  }
#line 1359 "parser.c"
    break;

  case 28: /* NT_LEFT_TYPE: TM_STRUCT_TYPE TM_IDENT  */
#line 208 "lang.y"
  {
    (yyval.e) = TStructType((yyvsp[0].i)); 
  }
#line 1367 "parser.c"
    break;

  case 29: /* NT_LEFT_TYPE: TM_UNION_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE  */
#line 213 "lang.y"
  {
    (yyval.e) = TNewUnionType((yyvsp[-3].i), (yyvsp[-1].e));
  }
#line 1375 "parser.c"
    break;

  case 30: /* NT_LEFT_TYPE: TM_UNION_TYPE TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE  */
#line 217 "lang.y"
  {
    (yyval.e) = TNewUnionType(NULL, (yyvsp[-1].e));
  }
#line 1383 "parser.c"
    break;

  case 31: /* NT_LEFT_TYPE: TM_UNION_TYPE TM_IDENT  */
#line 221 "lang.y"
  {
    (yyval.e) = TUnionType((yyvsp[0].i));
  }
#line 1391 "parser.c"
    break;

  case 32: /* NT_LEFT_TYPE: TM_ENUM_TYPE TM_IDENT TM_LEFT_BRACE NT_ENUM_ELE_LIST TM_RIGHT_BRACE  */
#line 226 "lang.y"
  {
    (yyval.e) = TNewEnumType((yyvsp[-3].i), (yyvsp[-1].e));
  }
#line 1399 "parser.c"
    break;

  case 33: /* NT_LEFT_TYPE: TM_ENUM_TYPE TM_LEFT_BRACE NT_ENUM_ELE_LIST TM_RIGHT_BRACE  */
#line 230 "lang.y"
  {
    (yyval.e) = TNewStructType(NULL, (yyvsp[-1].e));
  }
#line 1407 "parser.c"
    break;

  case 34: /* NT_LEFT_TYPE: TM_ENUM_TYPE TM_IDENT  */
#line 234 "lang.y"
  {
    (yyval.e) = TEnumType((yyvsp[0].i));
  }
#line 1415 "parser.c"
    break;

  case 35: /* NT_LEFT_TYPE: TM_INT_TYPE  */
#line 239 "lang.y"
  {
    (yyval.e) = TIntType();
  }
#line 1423 "parser.c"
    break;

  case 36: /* NT_LEFT_TYPE: TM_CHAR_TYPE  */
#line 243 "lang.y"
  {
    (yyval.e) = TCharType();
  }
#line 1431 "parser.c"
    break;

  case 37: /* NT_LEFT_TYPE: TM_IDENT  */
#line 247 "lang.y"
  {
    (yyval.e) = TDefinedType((yyvsp[0].i));
  }
#line 1439 "parser.c"
    break;

  case 38: /* NT_GLOB_ITEM: TM_STRUCT_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE TM_SEMICOL  */
#line 258 "lang.y"
  {
    (yyval.e) = TStructDef((yyvsp[-4].i), (yyvsp[-2].e));
  }
#line 1447 "parser.c"
    break;

  case 39: /* NT_GLOB_ITEM: TM_STRUCT_TYPE TM_IDENT TM_SEMICOL  */
#line 262 "lang.y"
  {
    (yyval.e) = TStructDecl((yyvsp[-1].i));
  }
#line 1455 "parser.c"
    break;

  case 40: /* NT_GLOB_ITEM: TM_UNION_TYPE TM_IDENT TM_LEFT_BRACE NT_FIELD_LIST TM_RIGHT_BRACE TM_SEMICOL  */
#line 267 "lang.y"
  {
    (yyval.e) = TUnionDef((yyvsp[-4].i), (yyvsp[-2].e));
  }
#line 1463 "parser.c"
    break;

  case 41: /* NT_GLOB_ITEM: TM_UNION_TYPE TM_IDENT TM_SEMICOL  */
#line 271 "lang.y"
  {
    (yyval.e) = TUnionDecl((yyvsp[-1].i));
  }
#line 1471 "parser.c"
    break;

  case 42: /* NT_GLOB_ITEM: TM_ENUM_TYPE TM_IDENT TM_LEFT_BRACE NT_ENUM_ELE_LIST TM_RIGHT_BRACE TM_SEMICOL  */
#line 276 "lang.y"
  {
    (yyval.e) = TEnumDef((yyvsp[-4].i), (yyvsp[-2].e));
  }
#line 1479 "parser.c"
    break;

  case 43: /* NT_GLOB_ITEM: TM_ENUM_TYPE TM_IDENT TM_SEMICOL  */
#line 280 "lang.y"
  {
    (yyval.e) = TEnumDecl((yyvsp[-1].i));
  }
#line 1487 "parser.c"
    break;

  case 44: /* NT_GLOB_ITEM: TM_TYPEDEF_TYPE NT_LEFT_TYPE NT_NAMED_RIGHT_TYPE_EXPR TM_SEMICOL  */
#line 285 "lang.y"
  {
    (yyval.e) = TTypeDef((yyvsp[-2].e), (yyvsp[-1].e));
  }
#line 1495 "parser.c"
    break;

  case 45: /* NT_GLOB_ITEM: NT_LEFT_TYPE NT_NAMED_RIGHT_TYPE_EXPR TM_SEMICOL  */
#line 290 "lang.y"
  {
    (yyval.e) = TVarDef((yyvsp[-2].e), (yyvsp[-1].e));
  }
#line 1503 "parser.c"
    break;


#line 1507 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 300 "lang.y"


void yyerror(char* s)
{
    fprintf(stderr , "%s\n",s);
}
