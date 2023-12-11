#include "PreProcess/input.h"
#include "LangAnalysis/analysis.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <string>



int main(int argc, char* argv[]) {
    char ret[3000];
    std::string filename = "LangAnalysis/sample_src00.jtl";
    char* file = new char[filename.length() + 1];
    strcpy(file, filename.c_str());
    get_abstract_syntax_tree(file, ret);
    std::cout << ret << std::endl;
   
    return 0;
}