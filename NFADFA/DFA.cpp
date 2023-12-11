#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "DFA.h"
using namespace std;

int DFA_series = 0; // the global serial number

// Create a new DFA node using the sets of NFA nodes
DFA_node *create_new_DFA_node(vector<NFA_node*> vec)
{
	DFA_node *p = new DFA_node;
	p->n = DFA_series++;
	p->NFA_node_set = vec;
	p->isend = false;
	
	// Determine if the node is a final state
	for (int k = 0; k < vec.size(); k++)
	{
		int priority = INF;
		if (vec[k]->isend)
		{
			p->isend = true;
			if (vec[k]->priority < priority)
			{
				p->endinfo = vec[k]->endinfo;
				priority = vec[k]->priority;
			}
		}
	}
	
	head_DFA_node *head = new head_DFA_node;
	head->node = p;
	head->next = NULL;
	DFA_list.push_back(head);
	
	return p;
}

// Connect two nodes
void connect_DFA_nodes(DFA_node *p, string str, DFA_node *q)
{
	list_DFA_node *p_next = new list_DFA_node;
	p_next->edge_info = str;
	p_next->node = q->n;
	p_next->next = DFA_list[p->n]->next;
	
	DFA_list[p->n]->next = p_next;
}

// Compare if two vectors are equal
bool compare_vectors(vector<NFA_node*> v1, vector<NFA_node*> v2)
{
	if (v1.size() != v2.size()) return false;
	
	for (int i = 0; i < v1.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j]) 
			{
				found = true;
				break;
			}
		}
		if (!found) return false;
	}
	return true;
}

// Transform the NFA into a DFA
vector<head_DFA_node*> NFA2DFA(vector<head_NFA_node*> NFA_list)
{
	
}

// Pretty printing for DFA
void pretty_printing_DFA(vector<head_DFA_node*> DFA_list)
{
	
}
