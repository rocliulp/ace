#include <stdio.h>

struct node {
  int value;
  struct node * previous;
  struct node * next;
};

struct queue {
  struct node * head;
  struct node * tail;
};

int quee_init
int queue_put (struct queue * q, int value) {
  return 0;
}

int queue_get (int* value, struct queue * q) {
  return 0;
}

int queue_is_empty (struct queue * q) {
  return 0;
}

int main (int argc, char* argv[]) {
  return 0;
}
