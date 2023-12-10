#include "input.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <cassert>

int countSubstring(const std::string& str, const std::string& sub);

// Count the number of substrings in a string
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
    // SyntaxLeftRightBraceDiff represents the difference between the number of left braces(syntax) and the number of right braces(syntax)
    int SyntaxLeftRightBraceDiff = 0;
    std::string line;
    rule tmp_r;
    // ProcessSyntax Represents whether the syntax of the rule is being read
    bool ProcessSyntax = false;

    while(std::getline(file, line)) {
        if (line.find("%%") != std::string::npos) {
            DoublePercentCount++;
            // erase the %% in line, special processing
            line = line.erase(line.find("%%"), 2);
        }

        // begin to process the rule part of the .l file
        if (DoublePercentCount==1){
            if (ProcessSyntax == true){

                tmp_r.syntax += line + "\n";
                SyntaxLeftRightBraceDiff += countSubstring(line, "{") - countSubstring(line, "\\{");
                SyntaxLeftRightBraceDiff -= countSubstring(line, "}") - countSubstring(line, "\\}");
                
                // If the number of left braces and the number of right braces are equal, it means that this rule has been read
                if (SyntaxLeftRightBraceDiff == 0){
                    rules.push_back(tmp_r);
                    tmp_r.regex = "";
                    tmp_r.syntax = "";
                    ProcessSyntax = false;
                }
            }

            // read in a line, judge whether this line is the beginning of a rule
            else{
                if (std::all_of(line.begin(), line.end(), [](unsigned char c){return std::isspace(c);})) {
                    // this line is an empty line or a line with only whitespace
                    continue;
                }

                else{
                    // syntax_left_brace_count represents the number of {(syntax) in this line
                    // thus the case of \{ should be excluded
                    // if syntax_left_brace_count == 0, it means that this line only contains the regular expression part of the rule
                    int syntax_left_brace_count = countSubstring(line, "{") - countSubstring(line, "\\{");
                    if (syntax_left_brace_count == 0){
                        tmp_r.regex += line;
                    }

                    else{
                        // syntax_left_brace_count != 0, it means that this line contains the regular expression part and the syntax part of the rule
                        // regex to store the regular expression part of the line
                        // syntax to store the syntax part of the line

                        // find the first { that is not \{ and then use the part before this { as regex and the part after this { as syntax
                        size_t pos = 0;
                        while(pos < line.size()){
                            pos = line.find("{", pos);
                            if (pos == 0 || line[pos - 1] != '\\'){
                                break;
                            }
                            pos++;
                        }
                        assert(line[pos] == '{');

                        tmp_r.regex += line.substr(0, int(pos - 1));

                        // delete the whitespace at the end of regex
                        while (tmp_r.regex.back() == ' '){
                            tmp_r.regex.pop_back();
                        }

                        tmp_r.syntax += line.substr(pos, line.size() - pos + 1);
                        tmp_r.syntax += "\n";
                        SyntaxLeftRightBraceDiff += countSubstring(line, "{") - countSubstring(line, "\\{");
                        SyntaxLeftRightBraceDiff -= countSubstring(line, "}") - countSubstring(line, "\\}");
                        ProcessSyntax = true;
                    }
                }
            }
        }
    }
    file.close();
    
    return rules;
}
