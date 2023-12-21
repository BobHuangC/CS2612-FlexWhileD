#ifndef __ANALYSIS_H__
#define __ANALYSIS_H__


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "lang.h"
#include "../lexer.h"
#include "../parser.h"
#include "string.h"

// get_abstract_syntax_tree: get the syntax tree of the input syntax
// syntax is a whileDereference program
// ret is the char* to store and returne
void get_abstract_syntax_tree(const char* syntax, char* ret);

#ifdef __cplusplus
}
#endif

#endif