// input.h
#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

// rule
// rule is a data structure that contains a regular expression and a syntax and an abstract syntax tree 
// each rule corresponds to a rule of the .l rule parts
class rule
{
    public:
        // regular expression
        std::string regex;
        // syntax in WhileDeref
        std::string syntax;
        // The AST of the syntax
        std::string ast;
};


// processFlexFile
// input: 
//      filename: the path of the input .l file
// output:
//      rules: a vector of rules, while rule is a data structure that contains a regular expression and a syntax and an abstract syntax tree corresponding to a rule of .l rule part
std::vector<rule> processFlexFile(const std::string& filename);

#endif // INPUT_H