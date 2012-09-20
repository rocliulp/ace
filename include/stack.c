/*
 * @author Paul Liu
 * @summary Implementation of class stack.
 */
#include <stdlib.h>
#include <error_codes.h>

struct stack {
  int capacity;
  void * p_array;
};

int stack_new (struct stack ** pp_stack, int capacity) {
  if (pp_stack == NULL) return EC_NULL_POINTER;
  if (capacity < 1) return EC_INVALID_PARAMETER;

  struct stack * p_stack = malloc (sizeof (struct stack));
  if (p_stack == NULL) return EC_OUT_OF_MEMORY;

  void * p_void = malloc (capacity * sizeof (void *));
  if (p_void == NULL) {
    free (p_stack);
    return EC_OUT_OF_MEMORY;
  }

  p_stack -> capacity = capacity;
  p_stack -> p_array = p_void;

  *pp_stack = p_stack;

  return EC_OK;
}

int stack_delete (struct stack * p_stack) {
  if (p_stack == NULL) return EC_NULL_POINTER;
  
  if (p_stack -> p_array != NULL) free (p_stack -> p_array);
  free (p_stack);

  return EC_OK;
}

int stack_pop (struct stack * p_stack, void const * p_obj) {
  return EC_OK;
}

int stack_push (struct stack * p_stack, void const * p_obj) {
  return EC_OK;
}

int stack_is_empty (struct stack const * p_stack, int * empty) {
  return EC_OK;
}
