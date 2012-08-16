#include <stdio.h>

#define N 1024

static int stack[N] = {0};
static int top = -1;

static int stackInit () {
  top = -1;
  return 0;
}

static int push (int v) {
  if (++top < N) {
    stack[top] = v;
  } else {
    return 1;
  }
  return 0;
}

static int pop (int* v) {
  if (top > -1) {
    *v = stack[top];
  } else {
    return 2;
  }
  --top;
  return 0;
}

static int isEmtpy () {
  if (top > -1) return 0;
  else return 1;
}

static int printStack () {
  int i = -1;
  char c = '\0';
  while (++i < top + 1) {
    c = stack[i];
    printf ("%c", c);
  }
  printf ("\n\r%d\n\r", top + 1);
  return 0;
}

static int ErrorExit (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  char string[1024] = {'\0'};
  int i = -1;
  int ret = 0;
  int c = 0;

  scanf ("%s", string);

  while (string[++i] != '\0') {
    if (string[i] == '*') {
      ret = pop (&c);
      if (ret != 0) return ErrorExit (ret);
    } else {
      ret = push (string[i]);
      if (ret != 0) return ErrorExit (ret);
    }
    printStack ();
  }

  return 0;
}
