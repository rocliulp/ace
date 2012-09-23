#include <stdio.h>

int error_print (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}
