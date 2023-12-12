#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "DFA.h"



// Implementation 1: implement the DFA(NFA nfa) function in this file
// implemented the NFA2DFA using the newly defined data structure
// 转移得到下一个NFAvector之后, 先判定这个NFAvector是否已经出现过, 如果出现过, 就不用再创建一个新的DFA节点了
// 如果没有出现过, 就创建一个新的DFA节点(创建的时候就编号), 并且把这个NFAvector压入栈中, 并且记录这个DFA节点下一步可以吸收的字符到DFA_NODE_NEXT_STRINGS中
// 在确定压栈之前, 再给这个DFA节点分配一个编号, 并且把他能够吸收的字符记录下来(新建DFA节点的时候就已经完成了)
// 这里存在一点问题就是初始化的时候, 传入什么
DFA::DFA(NFA nfa)
{
	DFA_node_index = 0;
	stack <DFA_node*> DFA_waiting_stack;
	vector<NFA_node*> start_NFA_node_set = nfa.get_init_NFAvec();
	DFA_node* start_DFA_node = new_DFA_node_from_NFAvec(nfa, start_NFA_node_set);
	// new_DFA_node_from_NFAvec(start_NFA_node_set);

	DFA_waiting_stack.push(start_DFA_node);
	while (!DFA_waiting_stack.empty())
	{
		DFA_node* p = DFA_waiting_stack.top();
		DFA_waiting_stack.pop();
		for (int i = 0; i < DFA_node_next_strings[p->n].size(); i++)
		{
			vector<NFA_node*> next_NFA_node_set = nfa.get_new_NFAvec(p->NFA_node_set, DFA_node_next_strings[p->n][i]);
			bool found = false;
			for (int j = 0; j < DFA_nodes_list.size(); j++)
			{
				if (nfa.compare_NFA_vec(next_NFA_node_set, DFA_nodes_list[j]->NFA_node_set))
				{
					found = true;
					break;
				}
			}
			if (found) continue;
			DFA_node* q = new_DFA_node_from_NFAvec(nfa, next_NFA_node_set);
			DFA_waiting_stack.push(q);
			//	add the trans 
			DFA_trans_list[p->n].push_back(make_pair(DFA_node_next_strings[p->n][i], q->n));
		}
	}
	
}


// implementation 3: implement the local functions in this file

// 新建一个节点
// 创建这个节点之前, 已经确定了这个节点之前没有出现过, 所以可以直接给这个节点分配一个编号
// 在创建这个节点的时候, 就把这个节点下一步可以吸收的字符记录下来

DFA_node* DFA::new_DFA_node_from_NFAvec(NFA nfa, std::vector<NFA_node*> NFAvec)
{
	DFA_node *p = new DFA_node;
	p->n = DFA_node_index ++;
	p->NFA_node_set = NFAvec;
	p->isend = false;

	// Determine if the node is a final state
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
	DFA_node_next_strings.push_back(nfa.get_NFAvec_next_strings(NFAvec));
	return p;

}


void DFA::pretty_printing_DFA()
{
	
}
