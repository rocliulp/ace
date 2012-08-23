#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node * next;
};

int init_node (struct node * head) {
  if (head == 0) return 1;
  head -> value = 0;
  head -> next = 0;

  return 0;
}

int move_next_to_front (struct node * head, struct node * t) {
  if (head == 0) return 1;
  if (t == 0) return 1;
  if (t -> next == 0) return 1;

  struct node * p = t -> next;
  t -> next = p -> next;

  struct node * o = head -> next;
  p -> next = o;
  head -> next = p;

  return 0;
}

int print_node (struct node * head) {
  struct node * p = 0;
  if (head != 0) {
    p = head -> next;
    while (p != 0) {
      printf ("%d -> ", p -> value);
      p = p -> next;
    }
  }

  printf ("\n\r");
  return 0;
}

int get_node_by_value (struct node * * p, struct node * head, int value) {
  if (head == 0) return 1;
  if (p == 0) return 1;

  head = head -> next;
  while (head != 0) {
    if (head -> value == value) {
      *p = head;
      return 0;
    }
    head = head -> next;
  }

  return 2;
}

int error_exit (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  int ret = 0;
  int i = 0;
  struct node * head = 0;
  struct node * tail = 0;
  struct node * m = 0;
  
  head = malloc (sizeof (struct node));
  ret = init_node (head);
  if (ret != 0) return error_exit (ret);

  tail = head;
  i = -1;
  while (++i < 10) {
    m = malloc (sizeof (struct node));
    m -> value = i;
    m -> next = 0;

    tail -> next = m;
    tail = m;
  }

  ret = print_node (head);
  if (ret != 0) return error_exit (ret);

  printf ("Select: ");
  scanf ("%d", &i);
  ret = get_node_by_value (&m, head, i);
  if (ret != 0) return error_exit (ret);

  ret = move_next_to_front (head, m);
  if (ret != 0) return error_exit (ret);

  ret = print_node (head);
  if (ret != 0) return error_exit (ret);  

  return 0;
}
