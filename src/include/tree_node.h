#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

struct tree_node;
int tree_node_new (struct tree_node * * pp_tn, void const * p_void);
int tree_node_delete (struct tree_node * p_tn);

int tree_node_set_left (struct tree_node * p_tn, struct tree_node * p_l);
int tree_node_set_right (struct tree_node * p_tn, struct tree_node * p_r);

typedef struct tree_node tree_t;
int tree_delete (tree_t * p_tree);
int tree_print (tree_t * p_tree);

int tree_preorder_traverse (tree_t * p_tree);
int tree_inorder_traverse (tree_t * p_tree);
int tree_postorder_traverse (tree_t * p_tree);
int tree_level_traverse (tree_t * p_tree);

int forest_level_traverse (tree_t * p_tree);

#endif
