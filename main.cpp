#include "NFADFA/NFA.h"
#include "NFADFA/DFA.h"
#include "PreProcess/input.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>

// Main funtion
int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_regex_file> <output_syntax_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    // redirect output to file  
    std::string string_result = filename+"-result.txt";
    std::cout<<"The result will be written in "<<string_result<<"."<<std::endl; 
    freopen(string_result.c_str(), "w", stdout);


    std::vector<rule> rules;

    rules = processFlexFile(filename);

	NFA nfa(rules);
	
	std::cout << "--------------------------------------------" << std::endl;
	nfa.pretty_printing_NFA();
    std::cout << "\n\n\n\n\n\n\n\n\n\n"<<std::endl;
    std::cout << "The following is the pretty printing of the DFA." << std::endl;

	DFA dfa(nfa);

	dfa.pretty_printing_DFA(nfa);
    fclose(stdout);
    
	
	return 0;
} 
