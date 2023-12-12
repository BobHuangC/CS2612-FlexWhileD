#include "../PreProcess/input.h"
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
    
    // 遍历rules, 在控制台输出rules
    for (auto r : rules){
        std::cout << r.regex << std::endl;
        std::cout << r.syntax << std::endl; 
        std::cout << r.ast << std::endl;
        std::cout << '\n';
        std::cout << '\n';
    }
    
    return 0;
}
