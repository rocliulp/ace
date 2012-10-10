#include <error_codes.h>
#include <tree_node.h>
#include <point.h>

struct drawn_tree_node {
  struct tree_node node_info;
  struct point2d point_info;
};

int drawn_tree_node_new (struct drawn_tree_node * * pp_tn) {
  return 0;
}

int drawn_tree_node_delete (struct drawn_tree_node * p_tn) {
  return 0;
}

int drawn_tree_node_GetLeft (struct drawn_tree_node * * pp_tn) {
  return 0;
}

int drawn_tree_node_SetLef (struct drawn_tree_node * p_tn) {
  return 0;
}

int drawn_tree_node_GetRight (struct drawn_tree_node * * pp_tn) {
  return 0;
}

int drawn_tree_node_SetRight (struct drawn_tree_node * p_tn) {
  return 0;
}

int drawn_tree_node_GetLocation (struct point * * pp_location) {
  return 0;
}

int drawn_tree_node_SetLocation (struct point * p_location) {
  return 0;
}
