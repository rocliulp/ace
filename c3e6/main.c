#include <stdio.h>

#define N 9

int key [N] = {0};
int next [N] = {0};

int head = 0;
int x = 1;

int stack_push (int v) {
  int p = 0;
  if (x == N) return 1;

  p = next [head];

  key [x] = v;
  next [x] = p;
  next [head] = x;  

  ++x;

  return 0;
}

int stack_pop (int * v) {
  if (x == 1) return 1;

  int p = next [head];
  * v = key [p];
  key [p] = 0;
  x = p;
  next [head] = next[p];

  return 0;
}

int stack_is_empty (int * e) {
  * e = 0;
  if (x == 1) * e = 1;
  return 0;
}

int stack_print () {
  int i = -1;
  while (++i < N) {
    printf ("%c -> ", key [i]);
  }
  printf ("\n\r");
  return 0;
}

int error_exit (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}

int main (int argc, char * argv []) {
  char string [1024] = {0};
  int i = 0;
  int ret = 0;
  int c = 0;

  scanf ("%s", string);
  printf ("%s\n\r", string);

  i = -1;
  while (string [++i] != '\0') {
    if (string [i] == '*') {
      ret = stack_pop (&c);
      if (ret != 0) return error_exit (ret);      
    } else {
      ret = stack_push (string [i]);
      if (ret != 0) return error_exit (ret);
    }

    ret = stack_print ();
    if (ret != 0) return error_exit (ret);
  }

  return 0;
}
