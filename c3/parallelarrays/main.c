#include <stdio.h>

#define N 10

int key[N + 2] = {0};
int next[N + 2] = {0};

int head = 0;
int x = 0;
int z = 0;

int listInitialize () {
  head = 0;
  z = 1;
  x = 2;

  next[head] = z;
  next[z] = z;

  return 0;
}

int deleteNext (int t) {
  int i = next[t];
  next[t] = next[i];

  return 0;
}

int insertAfter (int v, int t) {
  key[x] = v;
  next[x] = next[t];

  next[t] = x;

  ++x;

  return 0;
}

int main (int argc, char* argv[]) {
  return 0;
}
