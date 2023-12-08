%option noyywrap yylineno
%option outfile="lexer.c" header-file="lexer.h"
%{
#include "lang.h"
#include "parser.h"
%}

%%

0|[1-9][0-9]* {
    yylval.n = build_nat(yytext, yyleng);
    return TM_NAT;
}

"int" {
    return TM_INT_TYPE;
}

"char" {
    return TM_CHAR_TYPE;
}

"enum" {
    return TM_ENUM_TYPE;
}

"struct" {
    return TM_STRUCT_TYPE;
}

"union" {
    return TM_UNION_TYPE;
}

"typedef" {
    return TM_TYPEDEF_TYPE;
}

"*" {
    return TM_DEREFERENCE;
    }

"," {
    return TM_COMMA;
    }

"(" {
    return TM_LEFT_PAREN;
    }

")" {
    return TM_RIGHT_PAREN;
    }

"{" {
    return TM_LEFT_BRACE;
    }

"}" {
    return TM_RIGHT_BRACE;
    }

"[" {
    return TM_LEFT_BRACKET;
    }

"]" {
    return TM_RIGHT_BRACKET;
    }

";" {
    return TM_SEMICOL;
    }

[_A-Za-z][_A-Za-z0-9]* {
    yylval.i = new_str(yytext, yyleng);
    return TM_IDENT;
}

[ \t\n\r]    { };

.   {printf("%s",yytext);
     return -1; }
%%
