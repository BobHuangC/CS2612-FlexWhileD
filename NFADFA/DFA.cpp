#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "DFA.h"
using namespace std;

int DFA_series = 0; // the global serial number


// 新建一个节点
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


// 输入一个DFA节点, 输出这个DFA节点下一步可以吸收的字符
// 不一定正确, 假设完成了
vector<string> get_next_strings(DFA_node *p)
{
	vector<string> result;
	for (int i = 0; i < p->NFA_node_set.size(); i++)
	{
		list_NFA_node *p_list = NFA_list[p->NFA_node_set[i]->n]->next;
		while (p_list != NULL)
		{
			if (p_list->edge_info != EPSILON)
			{
				bool found = false;
				for (int j = 0; j < result.size(); j++)
				{
					if (result[j] == p_list->edge_info)
					{
						found = true;
						break;
					}
				}
				if (!found) result.push_back(p_list->edge_info);
			}
			p_list = p_list->next;
		}
	}
	return result;
}





// Transform the NFA into a DFA
vector<DFA_node*> NFA2DFA(vector<head_NFA_node*> NFA_list)
{	
	// 等待处理的DFA节点
	stack <DFA_node*> DFA_waiting_stack;
	// 新建一个DFA节点, 用来表示起始节点
	// 先根据NFA的起始状态，找到从初始状态出发, 经过epsilon边所有可以到达的状态, 构造起始DFA节点
	// 上述两个步骤, 可以通过epsilon_closure函数实现
	vector<NFA_node*> start_NFA_node_set = epsilon_closure(NFA_list[0]->node);
	
	// 计算起始DFA节点下一步可以吸收的字符
	DFA_node_next_strings.push_back(get_next_strings(create_new_DFA_node(start_NFA_node_set)));

	// 初始化一个栈, 将起始DFA节点压入栈中
	DFA_waiting_stack.push(create_new_DFA_node(start_NFA_node_set));

	// while 栈不为空
	while(!DFA_waiting_stack.empty())
	{
		// 从栈中弹出一个DFA节点, 对这个节点进行处理
		DFA_node *p = DFA_waiting_stack.top();
		DFA_waiting_stack.pop();
		// 对这个节点下一步可以吸收的字符, 依次进行处理
		for (int i = 0; i < DFA_node_next_strings[p->n].size(); i++){
			// 对于每一个字符, 计算这个字符下一步可以到达的状态集合
			vector<NFA_node*> next_NFA_node_set;
			for (int j = 0; j < p->NFA_node_set.size(); j++)
			{
				list_NFA_node *p_list = NFA_list[p->NFA_node_set[j]->n]->next;
				while (p_list != NULL)
				{
					if (p_list->edge_info == DFA_node_next_strings[p->n][i])
					{
						next_NFA_node_set.push_back(NFA_list[p_list->node]->node);
					}
					p_list = p_list->next;
				}
			}
			// 如果这个状态集合出现过, 就continue
			bool found = false;
			for (int j = 0; j < DFA_list.size(); j++)
			{
				if (compare_vectors(next_NFA_node_set, DFA_list[j]->NFA_node_set))
				{
					found = true;
					break;
				}
			}
			if (found) continue;
			// 如果这个状态集合没有出现过, 就创建一个新的DFA节点, 并且记录这个状态下一步可以吸收的字符
			DFA_node *q = create_new_DFA_node(next_NFA_node_set);
			DFA_node_next_strings.push_back(get_next_strings(q));
			// 将这个新的DFA节点压入栈中
			DFA_waiting_stack.push(q);
			// 将这个新的DFA节点与原来的DFA节点连接起来
			connect_DFA_nodes(p, DFA_node_next_strings[p->n][i], q);
		}

	}


	// 
}

// Pretty printing for DFA
void pretty_printing_DFA(vector<DFA_node*> DFA_list)
{
	
}
