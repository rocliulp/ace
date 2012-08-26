#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node * next;
};

struct queue {
  struct node * head;
  struct node * tail;
};

int queue_put (struct queue * q, int value) {
  struct node * n = 0;  
  if (q == 0) return 1;
  
  n = malloc (sizeof (struct node));
  n -> value = value;
  n -> next = 0;

  if (queue_is_empty (q)) {
    q -> head = n;
    q -> tail = n;
  } else {
    q -> tail -> next = n;
    q -> tail = n;
  }

  return 0;
}

int queue_get (int* value, struct queue * q) {
  struct node * p = 0;
  if (q == 0) return 1;
  if (queue_is_empty (q)) return 1;
  p = q -> head;
  q -> head = p -> next;
  *value = p -> value;
  free (p);

  return 0;
}

int queue_is_empty (struct queue * q) {
  if (q == 0) return 1;
  if (q -> head == 0 && q -> tail == 0) return 1;
  
  return 0;
}

int queue_free (struct queue * q) {
  struct node * n;
  if (q == 0) return 0;

  while (q -> head != 0) {
    n = q -> head;
    q -> head = n -> next;
    free (n);
  }
  free (q);

  return 0;
}

int queue_print (struct queue * q) {
  struct node * n = 0;
  if (q == 0) return 0;

  n = q -> head;
  while (n != 0) {
    printf ("%d -> ", n -> value);
    n = n -> next;
  }

  printf ("\n\r");
  return 0;
}

int error_exit (int ret) {
  printf ("Error: %d", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  struct queue * q = malloc (sizeof(struct queue));
  q -> head = 0;
  q -> tail = 0;


  return 0;
}
