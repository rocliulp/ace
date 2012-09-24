struct tree_node {
  void const * p_void;
  struct tree_node * p_l;
  struct tree_node * p_r;
}

int tree_node_new (struct tree_node * * p_tree_node) {
  return EC_OK;
}

int tree_node_delete (struct tree_node * p_tree_node) {
  return EC_OK;
}

typedef struct tree_node t_tree;

int tree_delete (t_tree * p_tree) {
  return EC_OK;
}

int tree_print (t_tree * p_tree) {
  return EC_OK;
}
