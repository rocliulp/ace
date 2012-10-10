#ifndef _DRAWN_TREE_NODE_H_
#define _DRAWN_TREE_NODE_H_

struct drawn_tree_node;

int drawn_tree_node_new (struct drawn_tree_node * * pp_tn);
int drawn_tree_node_delete (struct drawn_tree_node * p_tn);

int drawn_tree_node_GetLeft (struct drawn_tree_node * * pp_tn);
int drawn_tree_node_SetLef (struct drawn_tree_node * p_tn);

int drawn_tree_node_GetRight (struct drawn_tree_node * * pp_tn);
int drawn_tree_node_SetRight (struct drawn_tree_node * p_tn);

int drawn_tree_node_GetLocation (struct point * * pp_location);
int drawn_tree_node_SetLocation (struct point * p_location);

#endif
