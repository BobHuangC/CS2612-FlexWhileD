#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include "DFA.h"
#include <cassert>

// after transfer to the next NFA vector, 
// first determine whether this NFA vector has appeared before,
// if it has appeared, there is no need to create a new DFA node
// if it has not appeared, create a new DFA node (numbered when created),
// before enqueueing, give this DFA node a number, and record the characters it can absorb (this has been done when creating a new DFA node)
DFA::DFA(NFA nfa)
{
	DFA_node_index = 0;
	queue <DFA_node*> DFA_waiting_queue;
	vector<NFA_node*> start_NFA_node_set = nfa.get_init_NFAvec();

	DFA_node* start_DFA_node = new_DFA_node_from_NFAvec(nfa, start_NFA_node_set);

	// add the start node to the list before entering the queue
	DFA_nodes_list.push_back(start_DFA_node);
	DFA_waiting_queue.push(start_DFA_node);

	int tmp_cnt = 0;
	DFA_node* p;
	while (!DFA_waiting_queue.empty())
	{
		p = DFA_waiting_queue.front();
		DFA_waiting_queue.pop();

		// iterate over all strings that can be absorbed from this node
		for (int i = 0; i < DFA_node_next_strings[p->n].size(); i++)
		{
			// calculate the next NFA vector of this node after absorbing the string
			vector<NFA_node*> next_NFA_node_set = nfa.get_new_NFAvec(p->NFA_node_set, DFA_node_next_strings[p->n][i]);

			// new_NFA_vec represents whether this NFA vector has appeared before
			bool new_NFA_vec = false;
			// found_index is the index of the node in the list(if it is found)
			int new_NFA_vec_index = -1;
			int j;
			for (j = 0; j < DFA_nodes_list.size(); j++)
			{	
				if (nfa.compare_NFA_vec(next_NFA_node_set, DFA_nodes_list[j]->NFA_node_set))
				{
					new_NFA_vec = true;
					new_NFA_vec_index = j;
					break;
				}
			}
			
			if (new_NFA_vec)
			{
				assert(new_NFA_vec_index != -1);
				bool already_exist_relation = false;
				for (int k = 0; k < DFA_trans_list[p->n].size(); k++)
					if (DFA_trans_list[p->n][k].second == new_NFA_vec_index)
					{
						already_exist_relation = true;
						DFA_trans_list[p->n][k].first.push_back(DFA_node_next_strings[p->n][i]);
						break;
					}
				if (!already_exist_relation){
					DFA_trans_list[p->n].push_back(make_pair(vector<string>{DFA_node_next_strings[p->n][i]}, new_NFA_vec_index));
				}

				continue;
			}
			
			
			// if not found, create a new DFA node
			DFA_node* q = new_DFA_node_from_NFAvec(nfa, next_NFA_node_set);
			// add the node to the list
			DFA_nodes_list.push_back(q);
			// add the node to the queue
			DFA_waiting_queue.push(q);
			// add the trans
			std::vector<string> v = {DFA_node_next_strings[p->n][i]};
			DFA_trans_list[p->n].push_back(make_pair(v, q->n));
		}
	}
}


// new a DFA node from a NFA vector
// before creating this node, it has been determined that this node has not appeared before, 
// so you can directly assign a number to this node
// when creating this node, record the characters that this node can absorb next
DFA_node* DFA::new_DFA_node_from_NFAvec(NFA nfa, std::vector<NFA_node*> NFAvec)
{
	DFA_node *p = new DFA_node;
	p->n = DFA_node_index++;
	p->NFA_node_set = NFAvec;
	p->isend = false;

	// Determine if the node is a final state and set the priority to mark the corresponding processing syntax
	for (int k = 0; k < NFAvec.size(); k++)
	{
		int priority = INF;
		if (NFAvec[k]->isend)
		{
			p->isend = true;
			if (NFAvec[k]->priority < priority)
			{
				p->endinfo = NFAvec[k]->endinfo;
				priority = NFAvec[k]->priority;
				p->ast = NFAvec[k]->ast;
			}
		}
	}
	
	// record the characters that this node can absorb next
	std::vector<std::string> tmp = nfa.get_NFAvec_next_strings(NFAvec);
	
	DFA_node_next_strings.push_back(tmp);
	DFA_trans_list.push_back(vector<pair<std::vector<string>, int>>());
	return p;
}


// Pretty printing for DFA
void DFA::pretty_printing_DFA(NFA nfa)
{
	for (int i = 0; i < DFA_nodes_list.size(); i++)
	{
		std::cout << "-------------- DFA node " << i << " --------------" << std::endl;
		std::cout << "The NFA node set: {";
		for (NFA_node* nfa_node : DFA_nodes_list[i]->NFA_node_set)
			std::cout << " " << nfa_node->n;	
		std::cout << " }" << std::endl;
		std::cout << "The transitions:" << std::endl;
		for (std::pair<std::vector<string>, int> dfa_trans : DFA_trans_list[i])
			std::cout << i << " ----> " << dfa_trans.second << "   " << nfa.set2str(dfa_trans.first) << std::endl;
		if (DFA_nodes_list[i]->isend)
			std::cout << "This DFA node is a final state. Endinfo:\n" << DFA_nodes_list[i]->endinfo
					  << "The AST of the endinfo:\n" << DFA_nodes_list[i]->ast;
		else
			std::cout << "This DFA node is not a final state." << std::endl;
		std::cout << std::endl;
	}
}
