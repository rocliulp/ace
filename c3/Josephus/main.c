#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int key;
  struct _node * next;  
} node;

node * head = 0;
node * z = 0;
node * t = 0;

int listInitialize () {
  head = malloc (sizeof (node));
  z = malloc (sizeof (node));
  head -> next = z;
  return 0;
}

int deleteNext (node * t) {
  node * p = t -> next;
  node * v = p -> next;
  t -> next = v;
  free (p);
  return 0;
}

int insertAfter (int v, node * t) {
  node * p = t -> next;
  node * x = malloc (sizeof (node));
  x -> key = v;
  x -> next = p;
  t -> next = x;
  return 0;
}

int main (int argc, char* argv[]) {
  int i = 0;
  int M = 0;
  int N = 0;

  node * t = 0;
  node * x = 0;
  node * n = 0;

  scanf ("%d %d", &N, &M);

  t = malloc (sizeof (node));
  t -> key = 1;
  t -> next = 0;

  x = t;

  i = 1;
  while (++i < N + 1) {
    n = malloc (sizeof (node));
    n -> key = i;
    n -> next = 0;

    t -> next = n;
    t = n;
  }

  t -> next = x;

  while (t != t -> next) {
    i = 0;
    while (++i < M) {
      t = t -> next;
    }

    x = t -> next;
    t -> next = x -> next;
    printf ("%d\n\r", x -> key);

    free (x);
  }

  printf ("%d\n\r", t -> key);
  free (t);

  return 0;
}
