#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>

// 输入一个字符串流(.l文件), 然后返回一个vector, vector中的每一个元素都是一个rule
// 一个是正则表达式, 一个是语法规则

class rule
{
    private:
    public:
        std::string regex;
        std::string syntax;
};

int countSubstring(const std::string& str, const std::string& sub);
std::vector<rule> processFlexFile(const std::string&filename);


int countSubstring(const std::string& str, const std::string& sub) {
    std::size_t pos = 0;
    int count = 0;

    while ((pos = str.find(sub, pos)) != std::string::npos) {
        ++count;
        pos += sub.length();
    }
    return count;
}

std::vector<rule> processFlexFile(const std::string&filename){

    std::vector<rule> rules;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return rules;
    }

    int DoublePercentCount = 0;
    int SyntaxLeftBraceCount = 0;
    std::string line;

    // 新建一个rule
    rule tmp_r;
    // ProcessARule 表示是否正在读入, 处理一个rule
    bool ProcessARule = false;

    while(std::getline(file, line)) {
        if (line.find("%%") != std::string::npos) {
            DoublePercentCount++;
            // 将line中的%%删掉
            line = line.erase(line.find("%%"), 2);
        }

        // 进入.l文件的规则段
        if (DoublePercentCount==1){
            // processArule为true, 表示已经读入了regex, 正在读入syntax
            if (ProcessARule == true){
                // 如果line中有左括号, 那么就要计算左括号的数量
                // 如果line中有右括号, 那么就要计算右括号的数量
                // 如果左括号的数量和右括号的数量相等, 那么就可以结束了
                // 如果左括号的数量和右括号的数量不相等, 那么就要继续读取下一行
                tmp_r.syntax += line + "\n";
                SyntaxLeftBraceCount += countSubstring(line, "{") - countSubstring(line, "\\{");
                SyntaxLeftBraceCount -= countSubstring(line, "}") - countSubstring(line, "\\}");
                
                // 如果左括号的数量和右括号的数量相等, 就说明这个rule已经读完了
                if (SyntaxLeftBraceCount == 0){
                    rules.push_back(tmp_r);
                    tmp_r.regex = "";
                    tmp_r.syntax = "";
                    ProcessARule = false;
                }
            }


            // ProcessARule = False;
            // ProcessArule为false, 表示还没有读入regex
            // 正在读入line, 判断这个line是否是一个rule的开头
            else{
                if (std::all_of(line.begin(), line.end(), [](unsigned char c){return std::isspace(c);})) {
                    // this line is an empty line or a line with only whitespace
                    continue;
                }

                else{
                    // 如果这一行不为空, 并且这一行没有{, 那么这一行就是正则表达式
                    
                    int syntax_left_brace_count = countSubstring(line, "{") - countSubstring(line, "\\{");
                    if (syntax_left_brace_count == 0){
                        tmp_r.regex += line;
                    }

                    else{
                        // 如果这一行不为空, 并且这一行有不是\{ 的{, 那么这一行一定包括了正则表达式和语法规则
                        // regex读入这一行的正则表达式部分
                        // syntax读入这一行剩下的语法规则部分

                        // 算法思路, 找到第一个不是\{的{, 然后将这个{之前的部分作为regex, 将这个{之后的部分作为syntax

                        size_t pos = 0;
                        while(pos < line.size()){
                            pos = line.find("{", pos);
                            if (pos - 1 >= 0 &&  line[pos - 1] != '\\'){
                                break;
                            }
                            pos++;
                        }

                        tmp_r.regex += line.substr(0, pos);
                        tmp_r.regex += "\n";

                        tmp_r.syntax += line.substr(pos - 1, line.size() - pos + 1);
                        tmp_r.syntax += "\n";
                        SyntaxLeftBraceCount += countSubstring(line, "{") - countSubstring(line, "\\{");
                        SyntaxLeftBraceCount -= countSubstring(line, "}") - countSubstring(line, "\\}");
                        ProcessARule = true;
                    }
                }
            }
        }
    }
    file.close();
    
    return rules;
}



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
        std::cout << r.regex ;
        std::cout << r.syntax;
        std::cout << '\n';
        std::cout << '\n';
    }
    
    return 0;
}
