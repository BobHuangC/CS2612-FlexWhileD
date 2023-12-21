#include <iostream>
#include <string>
#include <stack>
#include "RE.h"

// The special sizes for these stacks
int node_stack_size = 0;
int op_stack_size = 0; // not include '(' !

// To simplify the following codes, several functions are implemented
// Push a node of RE tree into node_stack
void push_node_stack(tree_node *t)
{
	node_stack.push(t);
	node_stack_size++;
}

// Push an operator into op_stack
void push_op_stack(char ch)
{
	op_stack.push(ch);
	op_stack_size += (ch == LEFT_PAREN ? 0 : 1);
}

// Return and pop the top value of node_stack 
tree_node *pop_node_stack()
{
	tree_node *t = node_stack.top();
	node_stack.pop();
	node_stack_size--;
	return t;
}

// Return and pop the top value of op_stack 
char pop_op_stack()
{
	char ch = op_stack.top();
	op_stack.pop();
	op_stack_size -= (ch == LEFT_PAREN ? 0 : 1);
	return ch;
}

// Turn a char into a same string
std::string char2str(char ch)
{
	std::string str = "";
	str.push_back(ch);
	return str;
}

// Create a new node for RE tree
tree_node *create_new_tree_node(std::string v, tree_node *l, tree_node *r)
{
	tree_node *new_node = new tree_node;
	new_node->value = v;
	new_node->left = l;
	new_node->right = r;
	return new_node;
}

// Merge two RE tree nodes into a new tree node
void merge_two_nodes()
{
	char top_char = pop_op_stack();
	tree_node *r = pop_node_stack();
	tree_node *l = pop_node_stack();
	tree_node *t = create_new_tree_node(char2str(top_char), l, r);
	push_node_stack(t);
}

// Merge RE tree nodes as possible as we can according to the operator
void merge_nodes(char ch)
{
	switch (ch)
	{
		case VERTICAL_BAR:
			while (!op_stack.empty() && (op_stack.top() == PLUS || op_stack.top() == VERTICAL_BAR))
				merge_two_nodes();
			break;
			
		case PLUS:
			while (!op_stack.empty() && (op_stack.top() == PLUS))
				merge_two_nodes();
			break;
		
		case RIGHT_PAREN:
			while (op_stack.top() != LEFT_PAREN)
				merge_two_nodes();
	}
}

// Functions that can be called
// Transform the orignial RE into a RE tree and return the root
tree_node *RE2Tree(std::string RE, bool isstr)
{
	tree_node *t;
	for (int i = 0; i < RE.size(); i++)
	{
		int j;
		switch (RE[i])
		{
			case LEFT_PAREN:
				if (!isstr)
				{
					if (node_stack_size - op_stack_size >= 1)
					{
						merge_nodes(PLUS);
						push_op_stack(PLUS);
					}
					push_op_stack(RE[i]);
					break;
				}
				
			case RIGHT_PAREN:
				if (!isstr)
				{
					merge_nodes(RIGHT_PAREN);
					op_stack.pop();
					break;	
				}
				
			case VERTICAL_BAR:
				if (!isstr)
				{
					merge_nodes(VERTICAL_BAR);
					push_op_stack(VERTICAL_BAR);
					break;	
				}
				
			case STAR:
				if (!isstr)
				{
					t = create_new_tree_node(char2str(STAR), pop_node_stack(), NULL);
					push_node_stack(t);
					break;	
				}
				
			case DOUBLE_QUOTA:
				if (!isstr)
				{
					std::string str = "";
					while (true)
					{
						if (RE[++i] == DOUBLE_QUOTA)
						{
							int count = 0;
							for (int k = str.length() - 1; str[k] == '\\' && k >= 0; k--)
								count++;
							if (count % 2 == 0) break;
						}
						str.push_back(RE[i]);
					}
						
					if (node_stack_size - op_stack_size >= 1)
					{
						merge_nodes(PLUS);
						push_op_stack(PLUS);
					}
					
					t = RE2Tree(str, true);
					push_node_stack(t);
					break;	
				}
				
				
			default:
				std::string str = "";
				
				if (RE[i] == LEFT_BRACK && !isstr)
					while (true)
					{
						if (RE[++i] == RIGHT_BRACK)
						{
							int count = 0;
							for (int k = str.length() - 1; str[k] == '\\' && k >= 0; k--)
								count++;
							if (count % 2 == 0) break;
						}
						str.push_back(RE[i]);
					}
				
				else if (RE[i] == '\\' && isstr)
				{
					str.push_back(RE[i]);
        			str.push_back(RE[++i]);
				}
				
				else
					str.push_back(RE[i]);
			
				if (node_stack_size - op_stack_size >= 1)
				{
					merge_nodes(PLUS);
					push_op_stack(PLUS);
				}
				
				t = create_new_tree_node(str, NULL, NULL);
				push_node_stack(t);
		}
	}
	
	while (node_stack_size > 1)
		merge_two_nodes();
	
	return pop_node_stack();
}

tree_node *RE2Tree(std::string RE)
{
	return RE2Tree(RE, false);
}

// Print the RE tree in a pretty form
void pretty_printing_RE_tree(std::string prefix, tree_node *t, bool isBottom)
{
	if(!t) return;
	
    std::cout << prefix << (isBottom ? "\u2514\u2500\u2500  " : "\u251C\u2500\u2500  " ) << t->value << std::endl;

    // enter the next tree level - left and right branch
    if (t->value == char2str(STAR))
    {
    	pretty_printing_RE_tree(prefix + (isBottom ? "      " : "\u2502     "), t->left, true);
    	return;
	}
	pretty_printing_RE_tree(prefix + (isBottom ? "      " : "\u2502     "), t->left, false);
    pretty_printing_RE_tree(prefix + (isBottom ? "      " : "\u2502     "), t->right, true);
}

void pretty_printing_RE_tree(tree_node *t)
{
    pretty_printing_RE_tree("", t, true);    
}
