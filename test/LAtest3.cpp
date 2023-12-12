#include "../LangAnalysis/analysis.h"
# include <iostream>
# include <string>


int main()
{
    // char* syntax;
    // syntax = "n = 100;  m = 10;  m = - n * n; m = * n - 1";
    char syntax[] = "n = 100;  m = 10;  m = - n * n; m = * n - 1";

    char ret[3000] = "\0";
    get_abstract_syntax_tree(syntax, ret);
    std::cout << ret << std::endl;
}