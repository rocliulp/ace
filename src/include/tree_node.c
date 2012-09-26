#include <stdlib.h>
#include <stdio.h>
#include <error_codes.h>
#include <stack.h>

struct tree_node {
  void const * p_void;
  struct tree_node * p_l;
  struct tree_node * p_r;
};

int tree_node_new (struct tree_node * * pp_tn, void const * p_void) {
  struct tree_node * p_tn = NULL;
  if (pp_tn == NULL) return EC_NULL_POINTER;
  p_tn = malloc (sizeof (struct tree_node));
  p_tn -> p_void = p_void;
  p_tn -> p_l = NULL;
  p_tn -> p_r = NULL;
  if (p_tn == NULL) return EC_OUT_OF_MEMORY;
  * pp_tn = p_tn;
  return EC_OK;
}

int tree_node_delete (struct tree_node * p_tn) {
  if (p_tn == NULL) return EC_NULL_POINTER;
  free (p_tn);
  return EC_OK;
}

static int tree_node_print (struct tree_node * p_tn) {
  char * p_char = NULL;
  if (p_tn == NULL) return EC_NULL_POINTER;
  if (p_tn -> p_void == NULL) return EC_NULL_POINTER;
  p_char = (char *) (p_tn -> p_void);
  putchar (* p_char);
  printf ("\n\r");
  return EC_OK;
}

int tree_node_set_left (struct tree_node * p_tn, struct tree_node * p_l) {
  if (p_tn == NULL) return EC_NULL_POINTER;
  if (p_l == NULL) return EC_NULL_POINTER;
  p_tn -> p_l = p_l;
  return EC_OK;
}

int tree_node_set_right (struct tree_node * p_tn, struct tree_node * p_r) {
  if (p_tn == NULL) return EC_NULL_POINTER;
  if (p_r == NULL) return EC_NULL_POINTER;
  p_tn -> p_r = p_r;
  return EC_OK;
}

typedef struct tree_node tree_t;

int tree_delete (tree_t * p_tree) {
  tree_t * p_l = NULL;
  tree_t * p_r = NULL;
  if (p_tree == NULL) return EC_NULL_POINTER;
  p_l = (tree_t *) (p_tree -> p_l);
  p_r = (tree_t *) (p_tree -> p_r);
  
  if (p_l != NULL) {
    tree_delete (p_l);
  }
  tree_node_delete ((struct tree_node *)p_tree);
  if (p_r != NULL) {
    tree_delete (p_r);
  }
  
  return EC_OK;
}

int tree_print (tree_t * p_tree) {
  tree_t * p_l = NULL;
  tree_t * p_r = NULL;
  if (p_tree == NULL) return EC_NULL_POINTER;
  p_l = (tree_t *) (p_tree -> p_l);
  p_r = (tree_t *) (p_tree -> p_r);
  
  tree_node_print ((struct tree_node *)p_tree);
  tree_print (p_l);
  tree_print (p_r);

  return EC_OK;
}

int tree_preorder_traverse (tree_t * p_tree) {
  struct stack * p_stack = NULL;
  int ret = 0;
  int empty = 0;
  struct tree_node * p_tn = NULL;
  if (p_tree == NULL) return EC_NULL_POINTER;
  
  ret = stack_new (& p_stack, 10);
  if (ret != EC_OK) return error_print (ret);
  ret = stack_push (p_stack, p_tree);
  if (ret != EC_OK) {
    stack_delete (p_stack);
    return error_print (ret);
  }
  ret = stack_is_empty (p_stack, & empty);
  if (ret != EC_OK) {
    stack_delete (p_stack);
    return error_print (ret);
  }
  while (empty != 1) {
    ret = stack_pop (p_stack, (void const * *) (& p_tn));
    if (ret != EC_OK) {
      stack_delete (p_stack);
      return error_print (ret);
    }
    ret = tree_node_print (p_tn);
    if (ret != EC_OK) {
      stack_delete (p_stack);
      return error_print (ret);
    }
    if (p_tn -> p_r != NULL) {
      ret = stack_push (p_stack, p_tn -> p_r);
      if (ret != EC_OK) {
        stack_delete (p_stack);
        return error_print (ret);
      }
    }
    if (p_tn -> p_l != NULL) {
      ret = stack_push (p_stack, p_tn -> p_l);
      if (ret != EC_OK) {
        stack_delete (p_stack);
        return error_print (ret);
      }
    }

    ret = stack_is_empty (p_stack, & empty);
    if (ret != EC_OK) {
      stack_delete (p_stack);
      return error_print (ret);
    }
  }
  stack_delete (p_stack);
  return EC_OK;
}
