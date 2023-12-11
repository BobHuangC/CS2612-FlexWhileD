#include <stdio.h>
#include "lang.h"
#include "lexer.h"
#include "parser.h"
#include "string.h"
#include "analysis.h"

extern struct cmd * root;
int yyparse();

// file_name is the name of the file to be parsed
// ret is the string to be returned
void get_syntax_tree(char* file_name, char* ret) {
    FILE *file = fopen(file_name, "r");
    yyin = file;
    yyparse();
    get_cmd(root, ret);
}
