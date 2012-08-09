#include <stdio.h>

#define N 1000

int main (int argc, char* argv []) {
  int i = 0;
  int j = 0;
  int bound = 0;
  int edge = 0;
  int a[N + 1] = {0};

  a[1] = 0;
  i = 2;
  bound = N + 1;
  while (i < bound) {
    a[i] = 1;
    ++i;
  }

  i = 2;
  bound = N / 2 + 1;
  while (i < bound) {
    j = 2;
    edge = N / i + 1;
    while (j < edge) {
      a[i * j] = 0;
      ++j;
    }
    ++i;
  }

  i = 1;
  bound = N + 1;
  while (i < bound) {
    if (a[i] != 0) {
      printf ("%4d", i);
    }
    ++i;
  }

  printf ("\n\r");

  return 0;
}
