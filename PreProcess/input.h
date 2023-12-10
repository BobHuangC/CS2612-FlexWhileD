// input.h
#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

class rule
{
    public:
        // regular expression
        std::string regex;
        // syntax in WhileDeref
        std::string syntax;
};

// 输入一个字符串流(.l文件), 然后返回一个vector, vector中的每一个元素都是一个rule
// 一个是正则表达式, 一个是语法规则
std::vector<rule> processFlexFile(const std::string& filename);

#endif // INPUT_H