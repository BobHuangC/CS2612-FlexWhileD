// input.h
#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

class rule
{
    public:
        std::string regex;
        std::string syntax;
};

std::vector<rule> processFlexFile(const std::string& filename);

#endif // INPUT_H