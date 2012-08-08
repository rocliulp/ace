#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary (char bin[], int len, int value) {
  int quotient = 0;
  int remainder = 0;
  int i = len;
  int j = -1;
  char ch = '\0';

  quotient = value;  
  while (quotient > 0) {
    remainder = quotient % 2;
    if (remainder == 1) {
      bin[--i] = '1';
    } else {
      bin[--i] = '0';
    }
    quotient = quotient / 2;
  }

  remainder = quotient % 2;
  if (remainder == 1) {
    bin[--i] = '1';
  } else {
    bin[--i] = '0';
  }

  j = i;
  while (j < len) {
    bin[j - i] = bin[j];
    ++j;
  }
  j = len - i;
  while (j < len) {
    bin [j] = '\0';
    ++j;
  }

  return 0;
}

int main (int argc, char* argv[]) {
  int number = 0;
  int ret = 0;
  char bin[1024] = {'\0'};

  while (scanf ("%d", &number) != EOF) {
    printf ("input number: %d\n\r", number);
    ret = binary (bin, 1024, number);
    printf("my convert bin: %s\n\r", bin);

    memset (bin, '\0', 1024);
  }


  return 0;
}
