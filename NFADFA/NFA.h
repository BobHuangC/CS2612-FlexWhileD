#ifndef NFA_H
#define NFA_H

#include "RE.h"
#define EPSILON u8"\u03B5" // the epsilon edge

using namespace std;
// TODO BEGIN
// delete the declaration of using namespace std;
// TODO END


// TODO BEGIN
class NFA
{
private:
public:

};

// build a class of NFA(finish the below class and corresponding functions)
// Implement the following functions


// input a vec of epsilon closure NFA nodes, 
// output a vec of strings that this closure NFA nodes can absorb
// these strings must be different
std::vector<std::string> get_NFAvec_next_strings(NFA nfa, const std::vector<NFA_node*> ClosNFAvec);


// input 2 vec of NFA node(epsilon closure),
// output a bool value to determine if these 2 vec are the same
bool compare_NFA_vec(NFA nfa, const std::vector<NFA_node*> NFAv1, const std::vector<NFA_node*> NFAv2);


// input a vector of NFA nodes(epsilon closure), and a string, the NFA vec absorb the string, 
// output the epsilon closure of the new NFA vec, the new NFA vec was the epsilon closure of the NFA vec absorb the string
std::vector<NFA_node*> get_new_NFAvec(NFA nfa, std::vector<NFA_node*> NFAvec, string str);


// output the init epsilon closure of the NFA
std::vector<NFA_node*> get_init_NFAvec(NFA nfa);
	

// TODO END

// The structure of nodes in NFA
struct NFA_node
{
	int n;          // serial number of NFA node
	bool isend;     // true if the node is a final state in NFA
	string endinfo; // returned information when isend=true
	int priority;   // returned priority of the endinfo when isend=true
					// The smaller the number, the higher the priority
};

// Adjacency list used for NFA
// head_NFA_node -> list_NFA_node -> list_NFA_node -> ...
struct list_NFA_node
{
	string edge_info; // value of the edge
	int node;         // the current node
	list_NFA_node *next;
};

struct head_NFA_node
{
	NFA_node *node;
	list_NFA_node *next; 
};

static vector<head_NFA_node*> NFA_list;

// Two stacks are used for construct the NFA
static stack<NFA_node*> st;
static stack<NFA_node*> en;

// Functions
// Merge all NFAs and return the overall NFA_list
vector<head_NFA_node*> merge_nodes();

// Transform the RE tree into an NFA
void Tree2NFA(tree_node *root, string end_info, int priority);

// Calculate all nodes that can be reached through epsilon edges from current node
vector<NFA_node*> epsilon_closure(NFA_node *current_node);

// Compare if two vectors are equal
bool compare_vectors(vector<NFA_node*> v1, vector<NFA_node*> v2); 

// Pretty printing for NFA
void pretty_printing_NFA(vector<head_NFA_node*> NFA_list);

#endif
