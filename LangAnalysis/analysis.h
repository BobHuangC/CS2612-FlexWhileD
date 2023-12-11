#ifndef __ANALYSIS_H__
#define __ANALYSIS_H__


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "lang.h"
#include "lexer.h"
#include "parser.h"
#include "string.h"

// get_abstract_syntax_tree: get the syntax tree of the file
// file_name is the name of the file to be parsed
// ret is the string to be stored and returned
// void get_abstract_syntax_tree(char* file_name, char* ret);
void get_abstract_syntax_tree(const char* syntax, char* ret);

#ifdef __cplusplus
}
#endif

#endif