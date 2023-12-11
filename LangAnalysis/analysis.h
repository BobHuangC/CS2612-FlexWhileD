#include <stdio.h>
#include "lang.h"
#include "lexer.h"
#include "parser.h"
#include "string.h"

// get_syntax_tree: get the syntax tree of the file
// file_name is the name of the file to be parsed
// ret is the string to be stored and returned
void get_syntax_tree(char* file_name, char* ret);