#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

struct tree_node;
int tree_node_new (struct tree_node * * pp_tn, void const * p_void);
int tree_node_delete (struct tree_node * p_tn);
int tree_node_print (struct tree_node * p_tn);

typedef struct tree_node tree_t;
int tree_delete (tree_t * p_tree);
int tree_print (tree_t * p_tree);

#endif
