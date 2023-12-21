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
	// 遍历rules, 
	for (int i = 0; i < rules.size(); i++)
	{
		std::cout << "regex: " << rules[i].regex << std::endl;
		std::cout << "syntax: " << rules[i].syntax << std::endl;
		std::cout << "ast: " << rules[i].ast << std::endl;
		std::cout << " \n\n"<<std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}

	// NFA nfa;
    
    // for (int k = 0; k < rules.size(); k++)
	// {
	// 	tree_node *RE_tree_root = RE2Tree(rules[k].regex);
	// 	std::cout << "--------------------------------------------" << std::endl;
	// 	// pretty_printing_RE_tree(RE_tree_root);
	// 	std::vector<head_NFA_node*> NFA_list = nfa.Tree2NFA(RE_tree_root, rules[k].syntax, k);
	// 	// nfa.pretty_printing_NFA(NFA_list);
	// }


	// //std::cout << "WELL DONE 0.5" << std::endl;
	
	// std::vector<head_NFA_node*> NFA_vec = nfa.merge_nodes();
	
	// std::cout << "--------------------------------------------" << std::endl;
	// nfa.pretty_printing_NFA(NFA_vec);


	// DFA dfa(nfa);

	// dfa.pretty_printing_DFA(nfa);
	
	return 0;
} 
