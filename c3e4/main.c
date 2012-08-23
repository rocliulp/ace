#include <stdio.h>

#define N 9
#define M 5

int main (int argc, char* argv[]) {
  int len = N;
  int array[N] = {0};
  int i = -1;
  int gap = 0;
  int plus = M - 1;
  
  while (++i < N) {
    array[i] = i + 1;
  }

  i = 0;
  while (len > 0) {
    if (i + plus == len - 1) {
      i = i + plus;
      printf ("%d ", array[i]);
      i = 0;
      --len;
    } else {
      if (i + plus > len -1) {
        gap = plus - (len -1 - i);
        i = 0 + gap - 1;
      } else {
        i = i + plus;
      }

      printf ("%d ", array[i]);

      gap = i;
      while (gap < len - 1) {
        array[gap] = array[gap + 1];
        ++gap;
      }
      --len;
    }
  }

  return 0;
}
