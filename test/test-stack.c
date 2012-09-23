#include <stdio.h>
#include <stdlib.h>
#include <error_codes.h>
#include <stack.h>

int main (int argc, char * argv []) {
  char string [1024] = {'\0'};
  int ret = 0;
  int i = -1;
  char c = '\0';
  void const * p_void = NULL;

  scanf ("%s", string);
  printf ("%s\n\r", string);

  struct stack * p_stack;
  ret = stack_new (& p_stack, 10);
  if (ret != EC_OK) return error_print (ret);

  while (string[++i] != '\0') {
    if (string[i] == '*') {
      ret = stack_pop (p_stack, &c);
      if (ret != EC_OK) {
        stack_delete (p_stack);
        return error_print (ret);
      }
    } else {
      p_void = ((void const *) string) + i;
      ret = stack_push (p_stack, p_void);
      if (ret != EC_OK) {
        stack_delete (p_stack);
        return error_print (ret);
      }
    }
    stack_print (p_stack);
  }

  stack_delete (p_stack);

  return EC_OK;
}
