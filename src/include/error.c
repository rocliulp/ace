#include <stdio.h>

int error_print (int ret) {
  printf ("%c[%d;%d;%dmError: %d\n\r", 0x1B, 0, 31, 40, ret);
  return ret;
}
