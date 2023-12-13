#ifndef NFA_H
#define NFA_H

#include <string>
#include <stack>
#include <vector>

#include "RE.h"
#define EPSILON u8"\u03B5" // the epsilon edge

// The structure of nodes in NFA
struct NFA_node
{
	int n;          // serial number of NFA node
	bool isend;     // true if the node is a final state in NFA
	std::string endinfo; // returned information when isend=true
	int priority;   // returned priority of the endinfo when isend=true
					// The smaller the number, the higher the priority
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

static std::vector<head_NFA_node*> NFA_list;

// Two stacks are used for construct the NFA
static std::stack<NFA_node*> st;
static std::stack<NFA_node*> en;

std::vector<char> str2set(const std::string str);
std::string set2str(const std::vector<char> &char_vec);

class NFA
{
private:
public:
	// build a class of NFA(finish the below class and corresponding functions)
	// Implement the following functions


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
	
	NFA(){}
};

// Functions
// Merge all NFAs and return the overall NFA_list
std::vector<head_NFA_node*> merge_nodes(std::vector<head_NFA_node*> NFA_list);

// Transform the RE tree into an NFA
std::vector<head_NFA_node*> Tree2NFA(tree_node *root, std::string end_info, int priority);

// Pretty printing for NFA
void pretty_printing_NFA(std::vector<head_NFA_node*> NFA_list);

#endif
