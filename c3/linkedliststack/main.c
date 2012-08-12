#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node * next;
};

static struct node * head = 0;
static struct node * z = 0;
static struct node * t = 0;

int stackInit () {
  head = malloc (sizeof (struct node));
  z = malloc (sizeof (struct node));
  head -> next = z;
  head -> key = 0;
  z -> next = z;

  return 0;
}

int push (int v) {
  t = malloc (sizeof (struct node));
  t -> key = v;

  struct node * i = head -> next;
  t -> next = i;
  head -> next = t;

  return 0;
}

int pop (int * v) {
  struct node * i = head -> next;
  *v = i -> key;

  head -> next = i -> next;

  free (i);

  return 0;
}

int emptyStack () {
  if (head -> next == z) return 1;
  return 0;
}

int main (int argc, char* argv[]) {
  return 0;
}
