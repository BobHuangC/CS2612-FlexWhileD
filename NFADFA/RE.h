#ifndef RE_H
#define RE_H

#include <string>
#include <stack>

#define VERTICAL_BAR '|'
#define PLUS '+'
#define STAR '*'
#define LEFT_PAREN '('
#define RIGHT_PAREN ')'
#define LEFT_BRACK '['
#define RIGHT_BRACK ']'
#define DOUBLE_QUOTA '\"'

// The structure of the nodes in RE tree
struct tree_node{
	std::string value;
	tree_node *left;
	tree_node *right;
};

// Two stacks for constructing RE tree
static std::stack<tree_node*> node_stack;
static std::stack<char> op_stack;

// Functions
// Turn a char into a same string
std::string char2str(char ch);

// Transform the orignial RE into a RE tree and return the root
tree_node *RE2Tree(std::string RE);

// Print the RE tree in a pretty form 
void pretty_printing_RE_tree(tree_node *t);

#endif
