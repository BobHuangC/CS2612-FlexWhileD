#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "RE.h"
#include "NFA.h"
using namespace std;

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
    
    for (int k = 0; k < rules.size(); k++)
	{
		tree_node *RE_tree_root = RE2Tree(rules[k].regex);
		cout << "--------------------------------------------" << endl;
		pretty_printing_RE_tree(RE_tree_root);
		Tree2NFA(RE_tree_root, rules[k].syntax);
	}
	
	vector<head_node*> NFA = merge_nodes();
	
	cout << "--------------------------------------------" << endl;
	pretty_printing_NFA(NFA);

	

	return 0;
} 
