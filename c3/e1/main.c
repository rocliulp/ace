#include <stdio.h>

#include <gcd.h>

#define N 1000

int main (int argc, char* argv[]) {
  int array[N][N] = {0};
  int i = -1;
  int j = -1;
  int value = 0;
  int ret = 0;
  
  while (++i < N) {
    while (++j < N) {
      ret = gcd (&value, i, j);
      if (value == 1) {
        array[i][j] = 1;
      }
    }
  }

  i = -1;
  j = -1;
  while (++i < N) {
    while (++j < N) {
      printf ("array[%d][%d] = %d;\t", i, j, array[i, j]);
    }
  }
  printf ("\n\r");

  return 0;
}
