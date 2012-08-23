#include <stdio.h>

#include <gcd.h>

#define N 10

int main (int argc, char* argv[]) {
  int array[N][N];
  int i = -1;
  int j = -1;
  int value = 0;
  int ret = 0;

  i = -1;
  while (++i < N) {
    j = -1;
    while (++j < N) {
      array[i][j] = 0;
    }
  }

  i = 0;
  while (++i < N) {
    j = 0;
    while (++j < N) {
      ret = gcd (&value, i, j);
      if (ret != 0) {
        printf ("Error: i = %d, j = %d\n", i, j);       
      } else {
        if (value == 1) {
          array[i][j] = 1;
        }
      }
    }
  }

  i = -1;
  while (++i < N) {
    j = -1;
    while (++j < N) {
      printf ("array[%d][%d]=%d; ", i, j, array[i][j]);
    }
    printf ("\n\r");
  }
  printf ("\n\r");

  return 0;
}
