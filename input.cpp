#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>



// 输入一个字符串流(.l文件), 然后返回两个字符串流
// 一个是正则表达式, 一个是语法规则
void processFlexFile(
    const std::string& filename, 
    const std::string& outputRegexFilename, 
    const std::string& outputSyntaxFilename){


    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int DoublePercentCount = 0;

    // 根据outputRegexFilename和outputSyntaxFilename创建两个文件
    std::ofstream regexFile(outputRegexFilename);
    std::ofstream syntaxFile(outputSyntaxFilename);

    int leftBraceCount = 0;


    std::string line;
    while(std::getline(file, line)) {
        if (line.find("%%") != std::string::npos) {
            DoublePercentCount++;
        }

        if (DoublePercentCount==1){
            if (leftBraceCount > 0){
                // 如果line中有左括号, 那么就要计算左括号的数量
                // 如果line中有右括号, 那么就要计算右括号的数量
                // 如果左括号的数量和右括号的数量相等, 那么就可以结束了
                // 如果左括号的数量和右括号的数量不相等, 那么就要继续读取下一行
                syntaxFile << line << std::endl;
                leftBraceCount += std::count(line.begin(), line.end(), '{');
                leftBraceCount -= std::count(line.begin(), line.end(), '}');
            }

            if (leftBraceCount == 0){
                if (std::count(line.begin(), line.end(), '{') > 0){

                    // regexgile 输入line的开头一直到第一个左括号
                    // syntaxFile 输入line的剩余部分
                    std::istringstream iss(line);
                    std::string word;

                    std::size_t found = std::string::npos;

                    syntaxFile << "\n";
                    while(found == std::string::npos){
                        regexFile << word << " ";
                        iss >> word;
                        found = word.find("{");
                    }
                    regexFile << '\n';
                    syntaxFile << word << " ";

                    std::string rest;
                    std::getline(iss, rest);
                    syntaxFile << rest << std::endl;

                    leftBraceCount += std::count(line.begin(), line.end(), '{');
                    leftBraceCount -= std::count(line.begin(), line.end(), '}');
                }
            }

        }
    }
    file.close();
    regexFile.close();
    syntaxFile.close();
    return;

}

int main() {
    std::string filename = "input_file.l"; // 替换为你的 Flex 文件名
    std::string outputRegexFilename = "regex.txt";
    std::string outputSyntaxFilename = "syntax.txt";
    processFlexFile(filename, outputRegexFilename, outputSyntaxFilename);
    return 0;
}
