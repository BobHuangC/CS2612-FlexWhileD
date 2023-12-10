#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "NFA.h"
using namespace std;

int N = 0; // the global serial number

// To simplify the following codes, several functions are implemented
// Return and pop the top value of node_stack 
NFA_node *pop(stack<NFA_node*> &s)
{
	NFA_node *p = s.top();
	s.pop();
	return p;
}

// Transform the abstract structure tree into a list by postorder 
void tree_analysis(tree_node *t, vector<string> &order)
{   
    if (!t) return;
    
    tree_analysis(t->left, order);
    tree_analysis(t->right, order);
    order.push_back(t->value);
}

vector<string> tree_analysis(tree_node *t)
{
    vector<string> order;
    tree_analysis(t, order);
    return order;
}

// Create a new NFA node
NFA_node *create_new_NFA_node()
{
	NFA_node *p = new NFA_node;
	p->n = N++;
	p->isend = false;
	head_node *head = new head_node;
	head->node = p;
	head->next = NULL;
	NFA_list.push_back(head);
	
	return p;
}

// Connect two nodes
void connect_nodes(NFA_node *p, string str, NFA_node *q)
{
	list_node *p_next = new list_node;
	p_next->edge_info = str;
	p_next->node = q->n;
	p_next->next = NFA_list[p->n]->next;
	
	NFA_list[p->n]->next = p_next;
}

// Merge all NFAs and return the overall NFA_list
vector<head_node*> merge_nodes()
{
	NFA_node *init_node = create_new_NFA_node();
	
	while (!st.empty())
	{
		NFA_node *st_top_node = pop(st);
		connect_nodes(init_node, EPSILON, st_top_node);
	}
	return NFA_list;
}

// Transform the RE tree into an NFA
void Tree2NFA(tree_node *root, string end_info)
{
	vector<string> order = tree_analysis(root);
	
	for (int i = 0; i < order.size(); i++)
	{
		if (order[i] == "|")
		{
			NFA_node *s2 = pop(st);
			NFA_node *s1 = pop(st);
			NFA_node *e2 = pop(en);
			NFA_node *e1 = pop(en);
			NFA_node *s = create_new_NFA_node();
			NFA_node *e = create_new_NFA_node();
			connect_nodes(s, EPSILON, s1);
			connect_nodes(s, EPSILON, s2);
			connect_nodes(e1, EPSILON, e);
			connect_nodes(e2, EPSILON, e);
			st.push(s);
			en.push(e);
		}
		
		else if (order[i] == "+")
		{
			NFA_node *s = pop(st);
			NFA_node *e2 = pop(en);
			NFA_node *e1 = pop(en);
			connect_nodes(e1, EPSILON, s);
			en.push(e2);
		}
			
		else if (order[i] == "*")
		{
			NFA_node *s = st.top();
			NFA_node *e = pop(en);
			NFA_node *new_e = create_new_NFA_node();
			connect_nodes(e, EPSILON, s);
			connect_nodes(s, EPSILON, new_e);
			en.push(new_e);
		}
		
		else
		{
			NFA_node *p = create_new_NFA_node();
			NFA_node *q = create_new_NFA_node();
			connect_nodes(p, order[i], q);
			st.push(p);
			en.push(q);
		}
	}
	
	NFA_node *en_top = en.top();
	en_top->isend = true;
	en_top->endinfo = end_info;
}


// Pretty printing for NFA
void pretty_printing_NFA(vector<head_node*> NFA_list)
{
	for (int k = 0; k < NFA_list.size(); k++)
	{
		if (NFA_list[k]->node->isend) cout << (k < 10 ? " " : "") << k << " is a final state. Endinfo: " 
										   << NFA_list[k]->node->endinfo << endl;
		list_node *p = NFA_list[k]->next;
		while (p)
		{
			cout << (k < 10 ? " " : "") << k << " ----> " << p->node << (p->node < 10 ? " " : "")
				<< "   " << p->edge_info << endl;
			p = p->next;
		}
	}
}
