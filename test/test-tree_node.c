#include <stdlib.h>
#include <stdio.h>
#include <error_codes.h>
#include <tree_node.h>
#include <stack.h>
#include <error.h>

int main (int argc, char * argv []) {
  char string [1024] = {'\0'};
  int ret = 0;
  int i = -1;
  struct tree_node * p_tn = NULL;
  struct tree_node * p_s = NULL;
  struct stack * p_stack = NULL;

  scanf ("%s", string);
  printf ("%s\n\r", string);

  ret = stack_new (& p_stack, 10);
  if (ret != EC_OK) return error_print (ret);

  while (string [++i] != '\0') {
    ret = tree_node_new (& p_tn, (string + i));
    if (ret != EC_OK) {
      stack_delete (p_stack);
      return error_print (ret);
    }

    if (string [i] == '*' || string [i] == '+') {
      ret = stack_pop (p_stack, (void const * *) (& p_s));
      if (ret != EC_OK) {
        tree_delete (p_tn);
        stack_delete (p_stack);
        return error_print (ret);
      }
      ret = tree_node_set_right (p_tn, p_s);
      if (ret != EC_OK) {
        tree_delete (p_tn);
        stack_delete (p_stack);
        return error_print (ret);
      }

      ret = stack_pop (p_stack, (void const * *)(& p_s));
      if (ret != EC_OK) {
        tree_delete (p_tn);
        stack_delete (p_stack);
        return error_print (ret);
      }
      ret = tree_node_set_left (p_tn, p_s);
      if (ret != EC_OK) {        
        tree_delete (p_tn);
        stack_delete (p_stack);
        return error_print (ret);
      }
    }
    
    ret = stack_push (p_stack, p_tn);
    if (ret != EC_OK) {
      tree_delete (p_tn);
      stack_delete (p_stack);
      return error_print (ret);
    }
  }

  ret = stack_pop (p_stack, (void const * *) (& p_tn));
  if (ret != EC_OK) {
    stack_delete (p_stack);
    return error_print (ret);
  }
  ret = stack_is_empty (p_stack, & i);
  if (ret != EC_OK) {
    stack_delete (p_stack);
    return error_print (ret);
  }
  if (i != 1) {
    stack_delete (p_stack);
    return error_print (ret);
  }
  stack_delete (p_stack);

  printf ("Tree print:\n\r");
  ret = tree_print ((tree_t *)p_tn);
  if (ret != EC_OK) {
    tree_delete ((tree_t *)p_tn);
    return error_print (ret);
  }

  printf ("Tree preoder traverse:\n\r");
  ret = tree_preorder_traverse (p_tn);
  if (ret != EC_OK) {
    tree_delete (p_tn);
    return error_print (ret);
  }

  printf ("Tree inorder traverse:\n\r");
  ret = tree_inorder_traverse (p_tn);
  if (ret != EC_OK) {
    tree_delete (p_tn);
    return error_print (ret);
  }

  printf ("Tree post order travers:\n\r");
  ret = tree_postorder_traverse (p_tn);
  if (ret != EC_OK) {
    tree_delete (p_tn);
    return error_print (ret);
  }

  tree_delete ((tree_t *)p_tn);

  return EC_OK;
}
