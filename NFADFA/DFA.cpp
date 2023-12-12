#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "DFA.h"

// The state of DFA is the epison closure of NFA states

// Declaration 1: declare those functions imported from NFA.h, the functions are all based on epsilon closure

// input a vec of epsilon closure NFA nodes, 
// output a vec of strings that this closure NFA nodes can absorb
// these strings must be different
vector<std::string> get_NFAvec_next_strings(const std::vector<NFA_node*> ClosNFAvec);


// input 2 vec of NFA node(epsilon closure),
// output a bool value to determine if these 2 vec are the same
bool compare_NFA_vec(const std::vector<NFA_node*> NFAv1, const std::vector<NFA_node*> NFAv2);


// input a vector of NFA nodes(epsilon closure), and a string, the NFA vec absorb the string, 
// output the epsilon closure of the new NFA vec, the new NFA vec was the epsilon closure of the NFA vec absorb the string
std::vector<NFA_node*> get_new_NFAvec(std::vector<NFA_node*> NFAvec, string str);


// input a vector of NFA nodes(epsilon closure),
// 
std::vector<NFA_node*> get_init_NFAvec(std::vector<head_NFA_node*> NFA_list);


// Declaration 2: declare the global variables declared in NFA.h

// DFA_index to record the index of DFA node
int DFA_index = 0;
// DFA_node_next_strings to record the strings that the DFA node can absorb
// DFA[i] stores all the strings that DFA_node i can absorb
vector<vector<string>> DFA_node_next_strings;


// Declaration 3: declare the local functions in this file

// 新建一个节点
// 创建这个节点之前, 已经确定了这个节点之前没有出现过, 所以可以直接给这个节点分配一个编号
// 在创建这个节点的时候, 就把这个节点下一步可以吸收的字符记录下来
DFA_node *create_new_DFA_node(vector<NFA_node*> NFAvec)
{
	DFA_node *p = new DFA_node;
	p->n = DFA_series++;
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
	DFA_node_next_strings.push_back(get_next_strings(NFAvec));
	
	return p;
}


// Connect two nodes
// 处理方法就是新建一个结构体, 表示DFA节点转换时的字符
// 然后把这个结构体放到一个vector里面
void connect_DFA_nodes(DFA_node *p, string str, DFA_node *q)
{
	DFA_relation_node p_relation;
	p_relation.node = p->n;
	p_relation.edge_info = str;
	p_relation.next_node = q->n;
	DFA_relation.push_back(p_relation);
}


// implemented the NFA2DFA using the newly defined data structure
// 转移得到下一个NFAvector之后, 先判定这个NFAvector是否已经出现过, 如果出现过, 就不用再创建一个新的DFA节点了
// 如果没有出现过, 就创建一个新的DFA节点(创建的时候就编号), 并且把这个NFAvector压入栈中, 并且记录这个DFA节点下一步可以吸收的字符到DFA_NODE_NEXT_STRINGS中
// 在确定压栈之前, 再给这个DFA节点分配一个编号, 并且把他能够吸收的字符记录下来(新建DFA节点的时候就已经完成了)
vector<DFA_node*> NFA2DFA(vector<head_NFA_node*> NFA_list)
{
	stack <DFA_node*> DFA_waiting_stack;
	vector<NFA_node*> start_NFA_node_set = epsilon_closure(NFA_list[0]->node);
	DFA_node *start_DFA_node = create_new_DFA_node(start_NFA_node_set);
	DFA_waiting_stack.push(start_DFA_node);
	while (!DFA_waiting_stack.empty())
	{
		DFA_node *p = DFA_waiting_stack.top();
		DFA_waiting_stack.pop();
		for (int i = 0; i < DFA_node_next_strings[p->n].size(); i++)
		{
			vector<NFA_node*> next_NFA_node_set = get_new_NFAvec(p->NFA_node_set, DFA_node_next_strings[p->n][i]);
			bool found = false;
			for (int j = 0; j < DFA_list.size(); j++)
			{
				if (compare_NFA_vec(next_NFA_node_set, DFA_list[j]->NFA_node_set))
				{
					found = true;
					break;
				}
			}
			if (found) continue;
			DFA_node *q = create_new_DFA_node(next_NFA_node_set);
			DFA_waiting_stack.push(q);
			connect_DFA_nodes(p, DFA_node_next_strings[p->n][i], q);
		}
	
	}
	return DFA_list;

}


// Pretty printing for DFA
void pretty_printing_DFA(vector<DFA_node*> DFA_list)
{
	
}