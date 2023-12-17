#ifndef DFA_H
#define DFA_H

#include "NFA.h"
#define INF 100000

using namespace std;


// The structure of nodes in DFA
struct DFA_node
{
	int n;          // serial number of DFA node
	vector<NFA_node*> NFA_node_set;  // original NFA nodes included in this DFA node
	bool isend;     // true if there exists a node in original NFA is a final state
	string endinfo; // returned information when isend=true
};



class DFA
{
private:
public:
	// Declare the global variables declared in NFA.h
	// DFA_index to record the index of DFA node
	int DFA_node_index = 0;
	
	// store all the strings that DFA_node can absorb
	// DFA_node_next_strings[i][j] represents the jth string that the ith DFA node can absorb
	std::vector<std::vector<string>> DFA_node_next_strings;

	// DFA_nodes_list to record all the DFA nodes
	std::vector<DFA_node*> DFA_nodes_list;

	// DFA_trans_list to record all the transitions of DFA
	// DFA_trans_list[i][j] is a pair of string and int,
	// means that the j-th transition rule of i-th DFA node is:
	// i-th DFA node absorb the string, and trans to the int-th node.
	std::vector<std::vector<std::pair<std::vector<string>, int>>> DFA_trans_list;
	

	DFA(){ DFA_node_index = 0; }

	DFA(NFA nfa);

	// input a epsilon closure NFA node, 
	// output a DFA_node built from this NFA node
	DFA_node* new_DFA_node_from_NFAvec(NFA nfa, std::vector<NFA_node*> NFAvec);
	
	// Pretty printing for DFA
	void pretty_printing_DFA(NFA nfa);

};

#endif
