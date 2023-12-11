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

// Adjacency list used for DFA
// head_DFA_node -> list_DFA_node -> list_DFA_node -> ...
struct list_DFA_node
{
	string edge_info; // value of the edge
	int node;         // the current node
	list_DFA_node *next;
};

struct head_DFA_node
{
	DFA_node *node;
	list_DFA_node *next; 
};

static vector<head_DFA_node*> DFA_list;

// Functions
// Transform the NFA into a DFA
vector<head_DFA_node*> NFA2DFA(vector<head_NFA_node*> NFA_list);

// Pretty printing for DFA
void pretty_printing_DFA(vector<head_DFA_node*> DFA_list);

#endif
