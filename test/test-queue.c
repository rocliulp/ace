#include <stdlib.h>
#include <stdio.h>
#include <queue.h>
#include <error.h>
#include <error_codes.h>

static int error_exit (int ret, struct queue * p_queue) {
  if (ret == EC_OK) return ret;
  if (p_queue == NULL) return EC_NULL_POINTER;
  queue_delete (p_queue);
  return ret;
}

int main (int argc, char * argv []) {
  int ret = 0;
  char string [1024] = {'\0'};
  int i = -1;
  char * p_c = NULL;
  struct queue * p_queue = NULL;

  scanf ("%s", string);
  printf ("%s\n\r", string);

  ret = queue_new (& p_queue, 10);
  if (ret != EC_OK) return error_print (ret);

  while (string [++i] != '\0') {
    if (string [i] == '*') {
      ret = queue_get (p_queue, (void const * *)(& p_c));
      if (ret != EC_OK) return error_exit (ret, p_queue);
    } else {
      ret = queue_put (p_queue, (void const *)(string + i));
      if (ret != EC_OK) return error_exit (ret, p_queue);
    }
    ret = queue_print (p_queue);
    if (ret != EC_OK) return error_exit (ret, p_queue);
  }

  queue_delete (p_queue);
  return EC_OK;
}
