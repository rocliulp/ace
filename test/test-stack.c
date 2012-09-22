#include <stdio.h>
#include <stdlib.h>
#include <error_codes.h>
#include <stack.h>

int main (int argc, char * argv []) {
  char string [1024] = {'\0'};
  int ret = 0;

  scanf ("%s", string);
  printf ("%s\n\r", string);

  return EC_OK;
}
