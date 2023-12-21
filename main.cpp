#include "NFADFA/NFA.h"
#include "NFADFA/DFA.h"
#include "PreProcess/input.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

// Main funtion
int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_regex_file> <output_syntax_file>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::vector<rule> rules;

    rules = processFlexFile(filename);

	NFA nfa(rules);
	
	std::cout << "--------------------------------------------" << std::endl;
	nfa.pretty_printing_NFA();


	DFA dfa(nfa);

	dfa.pretty_printing_DFA(nfa);
	
	return 0;
} 
