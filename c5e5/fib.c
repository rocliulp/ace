#include <stdio.h>

int fibonacci (int N) {
  if (N <= 1) return 1;
  return fibonacci (N - 1) + fibonacci (N - 2);
}

int fib (int N) {
  int f0 = 1;
  int f1 = 1;
  int sum = 0;
  int i = -1;
  while (++ i < N + 1) {
    if (i == 0) {
      sum = f0;
    }
    else if (i == 1) {
      sum = f1;
    }
    else {
      sum = f0 + f1;
      f0 = f1;
      f1 = sum;
    }
  }
  return sum;
}

int main (int argc, char * argv []) {

  printf ("fibonacci (10): %d\n\r", fibonacci (10));
  printf ("fib (10): %d\n\r", fib (10));
  return 0;
}
