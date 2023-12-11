#include "analysis.h"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <string>

extern struct cmd * root;
int yyparse();

int main() {
    char ret[3000] = {'\0'};
    std::string filename = "sample_src01.jtl";
    char* file = new char[filename.length() + 1];
    strcpy(file, filename.c_str());
    get_abstract_syntax_tree(file, ret);
    std::cout << ret << std::endl;
    return 0;
}