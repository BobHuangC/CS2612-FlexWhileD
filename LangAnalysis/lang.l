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

"+" {
    return TM_PLUS;
}

"-" {
    return TM_MINUS;
}

"*" {
    return TM_TIMES_OR_DEREFERENCE;
}

"/" {
    return TM_DIVIDE;
}

"%" {
    return TM_MOD;
}

"<" {
    return TM_LT;
}

"<=" {
    return TM_LE;
}

"==" {
    return TM_EQ;
}

"!=" {
    return TM_NE;
}

">=" {
    return TM_GE;
}

">" {
    return TM_GT;
}

"&&" {
    return TM_AND;
}

"||" {
    return TM_OR;
}

"!" {
    return TM_NOT;
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
