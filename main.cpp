#include "PreProcess/input.h"
#include "LangAnalysis/analysis.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_regex_file> <output_syntax_file>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::vector<rule> rules;

    rules = processFlexFile(filename);
    



    
    return 0;
}
