#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include "DFA.h"

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
	while (!DFA_waiting_queue.empty())
	{
		std::cout << "Iteration " << tmp_cnt++<<endl;
		DFA_node* p = DFA_waiting_queue.front();
		DFA_waiting_queue.pop();

		// iterate over all strings that can be absorbed from this node
		for (int i = 0; i < DFA_node_next_strings[p->n].size(); i++)
		{
			// calculate the next NFA vector of this node after absorbing the string
			vector<NFA_node*> next_NFA_node_set = nfa.get_new_NFAvec(p->NFA_node_set, DFA_node_next_strings[p->n][i]);
			for (int i = 0; i < next_NFA_node_set.size();i++){
				std::cout << next_NFA_node_set[i]->n<< " this is the next_NFA_node_set"<<endl;
			}
			std::cout << "\n"<<endl;

			// determine if this NFA vector has appeared before
			bool found = false;
			for (int j = 0; j < DFA_nodes_list.size(); j++)
			{	
				if (nfa.compare_NFA_vec(next_NFA_node_set, DFA_nodes_list[j]->NFA_node_set))
				{
					found = true;
					break;
				}
			}
			
			// std::cout << found << " This is found" << endl;
			if (found) continue;
			
			// if not found, create a new DFA node
			DFA_node* q = new_DFA_node_from_NFAvec(nfa, next_NFA_node_set);
			// add the node to the list
			DFA_nodes_list.push_back(q);
			// add the node to the queue
			DFA_waiting_queue.push(q);
			//	add the trans
			pair<string, int> tmp_pair = make_pair(DFA_node_next_strings[p->n][i], q->n);
			std::cout << "This transition begins with  " << p->n <<  endl;
			DFA_trans_list[p->n].push_back(tmp_pair);
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
			}
		}
	}
	
	// record the characters that this node can absorb next

	for (int _i = 0; _i <NFAvec.size(); _i++){
		cout << NFAvec[_i]->n << " this NFAnode in NFAvec"<<endl;
	}
	std::vector<std::string> tmp = nfa.get_NFAvec_next_strings(NFAvec);
	
	std::cout << tmp.size() <<" This is the size of nfa.get_NFAvec_next_strings" << endl;
	std::cout << "\n"<<endl;
	DFA_node_next_strings.push_back(tmp);
	// DFA_node_next_strings.push_back(nfa.get_NFAvec_next_strings(NFAvec));
	DFA_trans_list.push_back(vector<pair<string, int>>());
	return p;
}


void DFA::pretty_printing_DFA()
{
	// print the nodes
	for (int i = 0; i < DFA_nodes_list.size(); i++)
	{
		cout << "DFA node " << i << " : ";
		std::cout << "The NFA nodes of this DFA node are:" << endl;
		for (int j = 0; j < DFA_nodes_list[i]->NFA_node_set.size(); j++)
		{
			cout << DFA_nodes_list[i]->NFA_node_set[j]->n << " ";
		}
		cout << endl;
	}

	// print all the transitions
	// 遍历DFA_trans_list
	for (int i = 0; i < DFA_trans_list.size(); i++)
	{
		std::cout << "The transitions of DFA node " << i << " are:" << endl;
		for (int j = 0; j < DFA_trans_list[i].size(); j++){
			std::cout << i << " ---- " << DFA_trans_list[i][j].first << " ----- " << DFA_trans_list[i][j].second << endl;
		}
		std::cout << "\n"<<endl;
	}
}
