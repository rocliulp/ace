#include <stdio.h>
#include <math.h>

char digitals[10] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

int main (int argc, char* argv []) {
  int ch = '\0';
  char chDigitals[100] = {'\0'};
  int i = -1;
  int j = -1;
  int k = -1;

  ch = getchar ();
  while (ch != '\n' && ch != ' ') {
    chDigitals[++i] = ch;
    ch = getchar ();
  }

  printf ("%s\n\r", chDigitals);

  int value = 0;
  j = -1;
  while (++j < i + 1) {
    ch = chDigitals[j];
    k = -1;
    while (++k < 10) {
      if (ch == digitals[k]) {
        value = value + k * pow (10, i - j);
      }
    }
  }

  printf ("value is : %d", value);

  return 0;
}
