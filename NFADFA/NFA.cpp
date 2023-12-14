#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include "NFA.h"

// To simplify the following codes, several functions are implemented
// Return and pop the top value of node_stack 
NFA_node *pop(std::stack<NFA_node*> &s)
{
	NFA_node *p = s.top();
	s.pop();
	return p;
}

// Transform the abstract structure tree into a list by postorder 
void tree_analysis(tree_node *t, std::vector<std::string> &order, std::vector<bool> &isleaf)
{   
    if (!t) return;
    
    tree_analysis(t->left, order, isleaf);
    tree_analysis(t->right, order, isleaf);
    order.push_back(t->value);
    isleaf.push_back(((!t->left) && (!t->right)));
}

std::vector<std::string> tree_analysis(tree_node *t, std::vector<bool> &isleaf)
{
    std::vector<std::string> order;
    tree_analysis(t, order, isleaf);
    return order;
}


// Functions for Class NFA
// Constructor
NFA::NFA()
{
	std::vector<head_NFA_node*> NFA_vec;
	std::stack<NFA_node*> start, end;
	NFA_list = NFA_vec;
	st = start;
	en = end;
	NFA_series = 0;
}

// Create a new NFA node
NFA_node *NFA::create_new_NFA_node()
{
	NFA_node *p = new NFA_node;
	p->n = NFA_series++;
	p->isend = false;
	head_NFA_node *head = new head_NFA_node;
	head->node = p;
	head->next = NULL;
	NFA_list.push_back(head);
	
	return p;
}

// Connect two nodes
void NFA::connect_NFA_nodes(NFA_node *p, std::string str, NFA_node *q)
{
	list_NFA_node *p_next = new list_NFA_node;
	p_next->edge_info = str;
	p_next->n = q->n;
	p_next->next = NFA_list[p->n]->next;
	
	NFA_list[p->n]->next = p_next;
}

// Calculate all nodes that can be reached through epsilon edges from current node
std::vector<NFA_node*> NFA::epsilon_closure(NFA_node *current_node)
{
	std::vector<NFA_node*> closure;
	std::stack<NFA_node*> epsilon_stack;
	epsilon_stack.push(current_node);
	
	while (!epsilon_stack.empty())
	{
		NFA_node *q = pop(epsilon_stack);
		closure.push_back(q);
		
		list_NFA_node *q_next = NFA_list[q->n]->next;
		while (q_next)
		{
			if (q_next->edge_info == EPSILON)
				epsilon_stack.push(NFA_list[q_next->n]->node);
			q_next = q_next->next;
		}
	}
	return closure;
}

// Merge all NFAs and return the overall NFA_list
std::vector<head_NFA_node*> NFA::merge_nodes()
{
	NFA_node *init_node = NFA_list[0]->node;
	
	while (!st.empty())
		connect_NFA_nodes(init_node, EPSILON, pop(st));

	return NFA_list;
}

// Transform the RE tree into an NFA
std::vector<head_NFA_node*> NFA::Tree2NFA(tree_node *root, std::string end_info, int priority)
{
	std::vector<bool> isleaf;
	std::vector<std::string> order = tree_analysis(root, isleaf);
	
	if (NFA_series == 0) create_new_NFA_node();
	
	for (int i = 0; i < order.size(); i++)
	{
		if (order[i] == "|" && !isleaf[i])
		{
			NFA_node *s2 = pop(st);
			NFA_node *s1 = pop(st);
			NFA_node *e2 = pop(en);
			NFA_node *e1 = pop(en);
			NFA_node *s = create_new_NFA_node();
			NFA_node *e = create_new_NFA_node();
			connect_NFA_nodes(s, EPSILON, s1);
			connect_NFA_nodes(s, EPSILON, s2);
			connect_NFA_nodes(e1, EPSILON, e);
			connect_NFA_nodes(e2, EPSILON, e);
			st.push(s);
			en.push(e);
		}
		
		else if (order[i] == "+" && !isleaf[i])
		{
			NFA_node *s = pop(st);
			NFA_node *e2 = pop(en);
			NFA_node *e1 = pop(en);
			connect_NFA_nodes(e1, EPSILON, s);
			en.push(e2);
		}
			
		else if (order[i] == "*" && !isleaf[i])
		{
			NFA_node *s = st.top();
			NFA_node *e = pop(en);
			NFA_node *new_e = create_new_NFA_node();
			connect_NFA_nodes(e, EPSILON, s);
			connect_NFA_nodes(s, EPSILON, new_e);
			en.push(new_e);
		}
		
		else
		{
			NFA_node *p = create_new_NFA_node();
			NFA_node *q = create_new_NFA_node();
			connect_NFA_nodes(p, order[i], q);
			st.push(p);
			en.push(q);
		}
	}
	
	// deal with the final state
	NFA_node *en_top = en.top();
	en_top->isend = true;
	en_top->endinfo = end_info;
	en_top->priority = priority;

	return NFA_list;
}

// Pretty printing for NFA
void NFA::pretty_printing_NFA(std::vector<head_NFA_node*> NFA_list)
{
	for (int k = 0; k < NFA_list.size(); k++)
	{
		if (NFA_list[k]->node->isend) std::cout << (k < 10 ? " " : "") << k << " is a final state. Endinfo: " 
										        << NFA_list[k]->node->endinfo << std::endl;
		list_NFA_node *p = NFA_list[k]->next;
		while (p)
		{
			std::cout << (k < 10 ? " " : "") << k << " ----> " << p->n << (p->n < 10 ? " " : "")
				      << "   " << p->edge_info << std::endl;
			p = p->next;
		}
	}
}

// Compare if two vectors are equal
bool NFA::compare_NFA_vec(std::vector<NFA_node*> NFAv1, std::vector<NFA_node*> NFAv2)
{
	if (NFAv1.size() != NFAv2.size()) return false;
	
	std::sort(NFAv1.begin(), NFAv1.end(), [](NFA_node* &a, NFA_node* &b){return a->n < b->n;});
	std::sort(NFAv2.begin(), NFAv2.end(), [](NFA_node* &a, NFA_node* &b){return a->n < b->n;});
	
	for (int i = 0; i < NFAv1.size(); i++)
	{
		if (NFAv1[i]->n != NFAv2[i]->n) return false;
	}
	return true;
}

// Transform a string(maybe a char or a char set) into a vector containing all chars
std::vector<char> NFA::str2set(const std::string str)
{
	std::vector<char> result;
    for (int k = 0; k < str.size(); k++)
	{
        if (str[k] == '-') 
            for (char i = str[k-1] + 1; i != str[k+1]; i++)
                result.push_back(i);
		else
            result.push_back(str[k]);
    }
    return result;
}

// Transform a vector containing some chars into a string
std::string NFA::set2str(const std::vector<char> &char_vec)
{
    if (char_vec.empty())
        return "";
    
    std::string result;
    char start = char_vec[0];
    char end = start;
    
    for (int i = 1; i < char_vec.size(); i++) {
        if (char_vec[i] == end + 1) {
            end = char_vec[i];
        } else {
            if (start == end) {
                result.push_back(start);
            } else {
                result.push_back(start);
				result.push_back('-');
				result.push_back(end);
            }
            start = char_vec[i];
            end = start;
        }
    }

    if (start == end) {
        result.push_back(start);
    } else {
        result.push_back(start);
		result.push_back('-');
		result.push_back(end);
    }

    return result;
}

// Split the original set of strings into pairwise disjoint sets of strings
std::vector<std::string> NFA::split_str_set(const std::vector<std::string> &str_vec)
{
	std::vector<std::string> split;
	for (int k = 0; k < str_vec.size(); k++)
	{
		std::vector<char> char_vec = str2set(str_vec[k]);
		for (char c : char_vec)
		{
			std::string s = "";
			s.push_back(c); 
			if (!count(split.begin(), split.end(), s))
				split.push_back(s);
		}
	}
	return split;	
}

// Merge two vectors and remove duplicate elements 
std::vector<NFA_node*> NFA::merge_vec(const std::vector<NFA_node*> &vec1, const std::vector<NFA_node*> &vec2)
{
	std::vector<NFA_node*> merged;
	merged.insert(merged.end(), vec1.begin(), vec1.end());
	merged.insert(merged.end(), vec2.begin(), vec2.end());
	std::sort(merged.begin(), merged.end(), [](NFA_node* &a, NFA_node* &b){return a->n < b->n;});
	merged.erase(unique(merged.begin(), merged.end(), [](NFA_node* &a, NFA_node* &b){return a->n == b->n;}), merged.end());
	return merged;
}

// Obtain the string set that the current epsilon closure can absorb
std::vector<std::string> NFA::get_NFAvec_next_strings(const std::vector<NFA_node*> ClosNFAvec)
{
	std::vector<std::string> str_set;
	for (int k = 0; k < ClosNFAvec.size(); k++)
	{
		list_NFA_node *q = NFA_list[ClosNFAvec[k]->n]->next;
		while (q)
		{
			if (q->edge_info != EPSILON)
				str_set.push_back(q->edge_info);
			q = q->next;
		}
	}
	
	return split_str_set(str_set);
}

// Get the epsilon closure that can be reached from the current epsilon closure after absorbing a string
std::vector<NFA_node*> NFA::get_new_NFAvec(std::vector<NFA_node*> NFAvec, std::string str)
{
	std::vector<NFA_node*> new_NFAvec;
	for (int k = 0; k < NFAvec.size(); k++)
	{
		list_NFA_node *q = NFA_list[NFAvec[k]->n]->next;
		while (q)
		{
			std::vector<char> edgeset = str2set(q->edge_info);
			std::vector<char> strset  = str2set(str);
			if (std::includes(edgeset.begin(), edgeset.end(), strset.begin(), strset.end()))
				new_NFAvec = merge_vec(new_NFAvec, epsilon_closure(NFA_list[q->n]->node));
			q = q->next;
		}
	}
	return new_NFAvec;
}

// Get the init epsilon closure of the NFA
std::vector<NFA_node*> NFA::get_init_NFAvec()
{
	return epsilon_closure(NFA_list[0]->node);
}
