#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "RE.h"
#include "NFA.h"

int main()
{
	std::string RE1, RE2;
	std::cin >> RE1 >> RE2;
	
	//tree_node *t = RE2Tree(RE);
	
	//pretty_printing_RE_tree(t);
	
	//std::vector<char> res = str2set(RE);
	std::vector<std::string> str_vec;
	str_vec.push_back(RE1);
	str_vec.push_back(RE2);
	//std::vector<std::string> res = split_str_set(str_vec);
	
	//for(std::string c : res)
	//	std::cout << c << " ";
		
	NFA nfa;
	
	//std::cout << std::endl << set2str(res); 
	
	return 0;
}
