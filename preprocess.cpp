// in preprocess.c, we input a .l file, and preprocess it to 2 stream,  regex and 
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream inputFile("input_file.l");

    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件\n";
        return 1;
    }

    std::string line;
    std::string regexContent;
    std::string syntaxContent;
    bool regexSection = false;
    bool syntaxSection = false;

    while (std::getline(inputFile, line)) {
        if (line.find("%%") != std::string::npos) {
            regexSection = !regexSection;
            continue;
        }

        if (regexSection) {
            regexContent += line + "\n";
        } else if (syntaxSection) {
            syntaxContent += line + "\n";
        }
    }

    inputFile.close();

    std::ofstream regexFile("正则表达式.txt");
    if (regexFile.is_open()) {
        regexFile << regexContent;
        regexFile.close();
    } else {
        std::cerr << "无法创建正则表达式文件\n";
        return 1;
    }

    std::ofstream syntaxFile("语法处理程序.txt");
    if (syntaxFile.is_open()) {
        syntaxFile << syntaxContent;
        syntaxFile.close();
    } else {
        std::cerr << "无法创建语法处理程序文件\n";
        return 1;
    }

    std::cout << "提取完成\n";
    return 0;
}
