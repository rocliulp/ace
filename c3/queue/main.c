#include <stdio.h>

#define N 10

static int queue[N] = {0};
static int head = -1;
static int tail = -1;

static int queueInit () {
  tail = -1;
  head = -1;
  return 0;
}

static int put (int v) {
  return 0;
}

static int get (int* v) {
  return 0;
}

static int isEmtpy () {
  return 0;
}

static int printQueue () {
  return 0;
}

static int ErrorExit (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  int i = -1;
  int v = 0;
  int ret = 0;
  char string[1024] = {'\0'};

  scanf ("%s", string);

  while (string[++i] != '\0') {
    if (string[i] == '*') {
      ret = get (&v);
      if (ret != 0) return ErrorExit (ret);
    } else {
      ret = put (string[i]);
      if (ret != 0) return ErrorExit (ret);
    }
    printQueue();
  }
  return 0;
}
