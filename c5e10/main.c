#include <stdlib.h>
#include <stdio.h>
#include <error_codes.h>
#include <error.h>

static int gcd (int u, int v) {
  int ret = 0;
  if (u < 1) return EC_OK;
  if (v < 1) return EC_OK;

  if (u < 2) {
    printf ("u: %d, v: %d\n\r", u, v);
    return EC_OK;
  }

  if (u < v) {
    int t = v;
    v = u;
    u = t;
  }
  u = u - v;
  printf ("u: %d, v: %d\n\r", u, v);
  ret = gcd (u, v);
  if (ret != EC_OK) return ret;
  return EC_OK;
}

int main (int argc, char * argv []) {
  int u = 461952;
  int v = 116298;
  int ret = gcd (u, v);
  if (ret != EC_OK) return error_print (ret);
  return EC_OK;
}
