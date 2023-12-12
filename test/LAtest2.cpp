#include "../LangAnalysis/analysis.h"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <string>

extern struct cmd * root;
int yyparse();

int main(int argc, char* argv[]) {
    // 通过main函数的参数获取文件名
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    std::string filename = argv[1];

    // std::string filename = "sample_src02.jtl";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // 使用content
    file.close();

    // 将content转化为char*
    char* char_content = new char[content.length() + 1];
    std::strcpy(char_content, content.c_str());
    

    char ret[3000] = {'\0'};
    get_abstract_syntax_tree(char_content, ret);
    std::cout << ret << std::endl;
    return 0;
}

void get_abstract_syntax_tree(const char* syntax, char* ret);