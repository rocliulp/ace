#include <stdlib.h>
#include <stdio.h>
#include <error_codes.h>
#include <tree_node.h>
#include <stack.h>
#include <error.h>

static int main_error_delete_tree_node (struct tree_node * p_tn) {
  tree_delete ( (tree_t *) p_tn);
  return EC_OK;
}

static int main_error_delete_stack (struct stack * p_stack) {
  if (p_stack == NULL) return EC_NULL_POINTER;
  stack_delete (p_stack);
  return EC_OK;
}

int main (int argc, char * argv []) {
  char string [1024] = {'\0'};
  int ret = 0;
  int i = 0;
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
      main_error_delete_stack (p_stack);
      return error_print (ret);
    }

    if (string [i] == '*' || string [i] == '+') {
      ret = stack_pop (p_stack, & p_s);
      if (ret != EC_OK) {
        main_error_delete_tree_node (p_tn);
        main_error_delete_stack (p_stack);
        return error_print (ret);
      }
      p_tn -> p_r = (struct tree_node *) p_s;

      ret = stack_pop (p_stack, & p_s);
      if (ret != EC_OK) {
        main_error_delete_tree_node (p_tn);
        main_error_delete_stack (p_stack);
        return error_print (ret);
      }
      p_tn -> p_l = (struct tree_node *) p_s;
    }
    
    ret = stack_push (p_stack, p_tn);
    if (ret != EC_OK) {
      main_error_delete_tree_node (p_tn);
      main_error_delete_stack (p_stack);
      return error_print (ret);
    }
  }

  ret = stack_pop (p_stack, p_tn);
  if (ret != EC_OK) {
    main_error_delete_stack (p_stack);
    return error_print (ret);
  }
  ret = stack_is_empty (p_stack, & i);
  if (ret != EC_OK) {
    main_error_delete_stack (p_stack);
    return error_print (ret);
  }
  if (i != 1) {
    main_error_delete_stack (p_stack);
    return error_print (ret);
  }
  stack_delete (p_stack);

  ret = tree_print ((tree_t *)p_tn);
  if (ret != EC_OK) {
  }
  tree_delete ((tree_t *)p_tn);

  return EC_OK;
}
