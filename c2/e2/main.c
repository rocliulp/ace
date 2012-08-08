#include <stdio.h>

int main (int argc, char * argv []) {
  int u = 0;
  int v = 0;
  int w = 0;
  printf ("Provide [u], [v]: \n\r");
  scanf ("%d %d", &u, &v);
  w = u % v;
  printf ("%d %% %d = %d", u, v, w);
  return 0;
}
