#ifndef NFA_H
#define NFA_H

#include "RE.h"
#define EPSILON u8"\u03B5" // the epsilon edge

using namespace std;

// The structure of nodes in NFA
struct NFA_node{
	int n;          // serial number of the node
	bool isend;     // true if the node is a final state in NFA
	string endinfo; // returned information when isend=true
};

// Adjacency list used for NFA
// head_node -> list_node -> list_node -> ...
struct list_node
{
	string edge_info; // value of the edge
	int node;         // the current node
	list_node *next;
};

struct head_node
{
	NFA_node *node;
	list_node *next; 
};

static vector<head_node*> NFA_list;

// Two stacks are used for construct the NFA
static stack<NFA_node*> st;
static stack<NFA_node*> en;

// Functions
// Merge all NFAs and return the overall NFA_list
vector<head_node*> merge_nodes();

// Transform the RE tree into an NFA
void Tree2NFA(tree_node *root, string end_info);

// Pretty printing for NFA
void pretty_printing_NFA(vector<head_node*> NFA_list);

#endif
