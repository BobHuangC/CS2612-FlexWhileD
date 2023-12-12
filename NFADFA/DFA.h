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


// 新建一个结构体, 表示DFA节点转换时的字符
struct DFA_relation_node
{
	int node; // 当前节点
	string edge_info; // 转换字符
	int next_node; // 下一个节点
};


// DFA节点之间的关系
vector<DFA_relation_node> DFA_relation;


// DFA_list to record all the DFA nodes
vector<DFA_node*> DFA_list;

// struct head_DFA_node
// {
// 	DFA_node *node;
// 	list_DFA_node *next; 
// };

// static vector<head_DFA_node*> DFA_list;

// Functions
// Transform the NFA into a DFA
vector<DFA_node*> NFA2DFA(vector<head_NFA_node*> NFA_list);

// Pretty printing for DFA
void pretty_printing_DFA(vector<DFA_node*> DFA_list);


// 保存每一个DFA节点下一步可以吸收的字符
// DFA_node_next_char[i][j]表示第i个DFA节点, 下一步可以吸收的第j个字符
vector<vector<string>> DFA_node_next_strings;




#endif
