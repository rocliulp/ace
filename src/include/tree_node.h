#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

struct tree_node;
int tree_node_new (struct tree_node * * p_tree_node);
int tree_node_delete (struct tree_node * p_tree_node);

typedef struct tree_node t_tree;
int tree_delete (t_tree * p_tree);
int tree_print (t_tree * p_tree);

#endif
