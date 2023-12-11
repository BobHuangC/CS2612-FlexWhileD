%option noyywrap yylineno
%option outfile="lexer.c" header-file="lexer.h"
%{
#include "lang.h"
#include "parser.h"
#include "lib.h"
%}

%%
"struct" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"enum" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"union" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"typedef" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"int" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"char" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"*" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"[" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"]" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

"," {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

0|[1-9][0-9]* {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

[_A-Za-z][_A-Za-z0-9]* {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
}

";" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

"(" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

")" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

"\{" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

"\}" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }


[ \t\n\r]    { };

.   {  n = 100;
  m = 10;
  m = - n * n;
  m = * n - 1 }
    


%%
