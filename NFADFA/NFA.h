#ifndef NFA_H
#define NFA_H

#include <string>
#include <stack>
#include <vector>

#include "RE.h"
#include "../PreProcess/input.h"
#define EPSILON u8"\u03B5" // the epsilon edge

// The structure of nodes in NFA
struct NFA_node
{
	int n;          // serial number of NFA node
	bool isend;     // true if the node is a final state in NFA
	std::string endinfo; // returned information when isend=true
	int priority;   // returned priority of the endinfo when isend=true
					// The smaller the number, the higher the priority
	std::string ast;// the ast of the endinfo
};

// Adjacency list used for NFA
// head_NFA_node -> list_NFA_node -> list_NFA_node -> ...
struct list_NFA_node
{
	std::string edge_info; // value of the edge
	int n;                 // the current node
	list_NFA_node *next;
};

struct head_NFA_node
{
	NFA_node *node;        // the corresponding NFA node
	list_NFA_node *next;   // the list_NFA_node of this NFA node
};

class NFA
{
private:
	// the global serial number
	int NFA_series; 
	
	// Two stacks are used for construct the NFA
	std::stack<NFA_node*> st;
	std::stack<NFA_node*> en;
	
	// Create a new NFA node
	NFA_node *create_new_NFA_node();
	
	// Connect two nodes
	void connect_NFA_nodes(NFA_node *p, std::string str, NFA_node *q);
	
	// Calculate all nodes that can be reached through epsilon edges from current node
	std::vector<NFA_node*> epsilon_closure(NFA_node *current_node);
	
	// Transform a string(maybe a char or a char set) into a vector containing all chars
	std::vector<std::string> str2set(const std::string str);
	
	// Split the original set of strings into pairwise disjoint sets of strings
	std::vector<std::string> split_str_set(const std::vector<std::string> &str_vec);
	
	// Merge two vectors and remove duplicate elements 
	std::vector<NFA_node*> merge_vec(const std::vector<NFA_node*> &vec1, const std::vector<NFA_node*> &vec2); 
	
public:
	// Date structure for NFA
	std::vector<head_NFA_node*> NFA_list;
	
	// Declaration
	NFA(std::vector<rule> rules); 
	
	// Transform a vector containing some chars into a string
	std::string set2str(const std::vector<std::string> &char_vec);
	
	// Merge all NFAs and return the overall NFA_list
	std::vector<head_NFA_node*> merge_nodes();
	
	// Transform the RE tree into an NFA
	std::vector<head_NFA_node*> Tree2NFA(tree_node *root, std::string end_info, std::string ast, int priority);
	
	// Pretty printing for NFA
	void pretty_printing_NFA();


	// Functions for getting DFA
	// input a vec of epsilon closure NFA nodes, 
	// output a vec of strings that this closure NFA nodes can absorb
	// these strings must be different
	std::vector<std::string> get_NFAvec_next_strings(const std::vector<NFA_node*> ClosNFAvec);

	// input 2 vec of NFA node(epsilon closure),
	// output a bool value to determine if these 2 vec are the same
	bool compare_NFA_vec(std::vector<NFA_node*> NFAv1, std::vector<NFA_node*> NFAv2);

	// input a vector of NFA nodes(epsilon closure), and a string, the NFA vec absorb the string, 
	// output the epsilon closure of the new NFA vec, the new NFA vec was the epsilon closure of the NFA vec absorb the string
	std::vector<NFA_node*> get_new_NFAvec(std::vector<NFA_node*> NFAvec, std::string str);

	// output the init epsilon closure of the NFA
	std::vector<NFA_node*> get_init_NFAvec();
};

#endif
