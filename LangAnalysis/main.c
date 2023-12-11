#include <stdio.h>
#include "lang.h"
#include "lexer.h"
#include "parser.h"
#include "string.h"
#include "analysis.h"

extern struct cmd * root;
int yyparse();


int main(int argc, char **argv) {

    char ret[3000];
    get_abstract_syntax_tree("sample_src00.jtl", ret);

    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
    printf("%s\n", ret);
}
