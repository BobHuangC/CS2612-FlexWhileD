#ifndef RE_H
#define RE_H

#define VERTICAL_BAR '|'
#define PLUS '+'
#define STAR '*'
#define LEFT_PAREN '('
#define RIGHT_PAREN ')'
#define LEFT_BRACK '['
#define RIGHT_BRACK ']'
#define DOUBLE_QUOTA '\"'

using namespace std;

// The structure of the nodes in RE tree
struct tree_node{
	string value;
	tree_node *left;
	tree_node *right;
};

// Two stacks for constructing RE tree
static stack<tree_node*> node_stack;
static stack<char> op_stack;

// Functions
// Transform the orignial RE into a RE tree and return the root
tree_node *RE2Tree(string RE);

// Print the RE tree in a pretty form 
void pretty_printing_RE_tree(tree_node *t);

#endif
