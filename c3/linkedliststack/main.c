#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node * next;
};

int stackInit (struct node * head) {
  if (head != 0) {
    return 1;
  }
  head = malloc (sizeof (struct node));
  head -> key = -1;
  head -> next = 0;
  return 0;
}

int stackRemove (struct node * head) {
  if (head == 0) return 1;
  while (head != 0) {
    struct node * i = head -> next;
    free (head);
    head = i;
  }
  return 0;
}

int push (int v, struct node * head) {
  if (head == 0) return 1;
  if (v < 0) return 1;
  struct node * t = malloc (sizeof (struct node));
  t -> key = v;
  t -> next = 0;

  struct node * i = head -> next;
  head -> next = t;
  if (i != 0) {
    t -> next = i;
  }

  return 0;
}

int pop (int * v, struct node * head) {
  if (head == 0) return 1;
  if (v == 0) return 1;
  if (emptyStack (head)) return 1;

  struct node * i = head -> next;
  *v = i -> key;

  head -> next = i -> next;

  free (i);

  return 0;
}

int emptyStack (struct node * head) {
  if (head == 0) {
    return 1;
  }

  if (head -> next == 0) return 1;
  return 0;
}

int main (int argc, char* argv[]) {
  char c = '\0';
  struct node * head = 0;
  stackInit (head);
  while (scanf("%1s", &c) != EOF) {
    if (c == '(') {
      printf (" ");
    } else if (c == '+') {
      push (c, head);
    } else if (c == '*') {
      push (c, head);
    } else if (c == ')') {
      while (!emptyStack(head)) {
        pop (&c, head);
        printf ("%c", c);
      }
    } else if (c > '0' && c < '9') {
      printf ("%1c", c);
    } else {
      printf (" ");
    }
  }

  stackRemove (head);
  printf ("\n\r");

  return 0;
}
