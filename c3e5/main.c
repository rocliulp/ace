#include <stdio.h>
#include <stdlib.h>

#define N 10

struct node {
  int value;
  struct node * previous;
  struct node * next;
};

int init_node (struct node * head) {
  if (head == 0) return 1;
  head -> value = -1;
  head -> previous = 0;
  head -> next = 0;
  return 0;
}

int del_node (struct node * t) {
  if (t == 0) return 1;
  
  struct node * p = t -> previous;
  struct node * n = t -> next;
  p -> next = n;
  n -> previous = p;

  free (t);

  return 0;
}

int ins_node (struct node * p, struct node * t) {
  if (p == 0) return 1;
  if (t == 0) return 1;

  t -> next = p -> next;
  t -> previous = p;
  p -> next = t;

  return 0;
}

int print_list (struct node * head) {
  if (head == 0) return 1;

  head = head -> next;
  while (head != 0) {
    printf ("%d -> ", head -> value);
    head = head -> next;
  }
  printf ("\n\r");
  return 0;
}

int remove_list (struct node * head) {
  if (head == 0) return 1;
  struct node * t = head -> next;
  while (t != 0) {
    head = t -> next;

    free (t);

    t = head;
  }
  return 0;
}

int get_node_by_value (struct node ** n, struct node * head, int value) {
  if (n == 0) return 1;
  if (head == 0) return 1;
  head = head -> next;
  while (head != 0) {
    if (head -> value == value) {
      *n = head;
      return 0;
    }
    head = head -> next;
  }
  return 2;
}

int error_exit (int ret) {
  printf ("Error: %d", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  struct node * head = 0;
  struct node * tail = 0;
  struct node * t = 0;
  int ret = 0;
  int i = 0;

  head = malloc (sizeof (struct node));
  ret = init_node (head);

  i = -1;
  tail = head;
  while (++i < N) {
    t = malloc (sizeof (struct node));
    t -> value = i;

    tail -> next = t;
    t -> previous = tail;

    tail = t;
  }
  print_list (head);

  ret = get_node_by_value (&t, head, 5);
  if (ret != 0) return error_exit (ret);
  ret = del_node (t);
  if (ret != 0) return error_exit (ret);
  print_list (head);

  tail = malloc (sizeof (struct node));
  tail -> value = 5;

  ret = get_node_by_value (&t, head, 2);
  if (ret != 0) return error_exit (ret);
  ret = ins_node (t, tail);
  if (ret != 0) return error_exit (ret);
  print_list (head);

  remove_list (head);

  return 0;
}
