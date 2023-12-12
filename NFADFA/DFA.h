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



class DFA
{
private:
public:
	// Declare the global variables declared in NFA.h
	// DFA_index to record the index of DFA node
	int DFA_node_index = 0;
	
	// store all the strings that DFA_node can absorb
	// DFA_node_next_strings[i][j] represents the jth string that the ith DFA node can absorb
	std::vector<vector<string>> DFA_node_next_strings;
	DFA(){
		DFA_node_index = 0;
	}

	DFA(NFA nfa);

	// input a epsilon closure NFA node, 
	// output a DFA_node built from this NFA node
	DFA_node new_DFA_node_from_NFAvec(NFA nfa, std::vector<NFA_node*> NFAvec);

};





vector<vector<string>> DFA_node_next_strings;


DFA::DFA(NFA nfa)
{
	DFA_node_index = 0;
}












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





// Pretty printing for DFA
void pretty_printing_DFA(vector<DFA_node*> DFA_list);







#endif
