#include "lang.h"
#include "lexer.h"
#include "parser.h"
#include "string.h"
#include "analysis.h"
#include <stdio.h>


extern struct cmd * root;
int yyparse();


void get_abstract_syntax_tree(const char* syntax, char* ret)
{
    yy_scan_string(syntax);
    yyparse();
    get_cmd(root, ret);
}