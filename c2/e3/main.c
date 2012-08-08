#include <stdio.h>

typedef struct _fraction {
  int numerator;
  int demoninator;
} fraction;

int gcd (int* div, int numerator, int demoninator) {
  int t = 0;
  *div = 0;

  while (numerator > 0) {
    if (numerator < demoninator) {
      t = numerator;
      numerator = demoninator;
      demoninator = t;
    }
    *div = numerator;
    numerator = numerator - demoninator;
  }

  return 0;
}

int main (int argc, char* argv []) {
  int numerator = 0;
  int demoninator = 0;
  int div = 0;
  int ret = 0;
  while (scanf ("%d / %d", &numerator, &demoninator) != EOF) {
    ret = gcd (&div, numerator, demoninator);
    numerator = numerator / div;
    demoninator = demoninator / div;
    printf ("%d / %d\n\r", numerator, demoninator);
  }
  return 0;
}
