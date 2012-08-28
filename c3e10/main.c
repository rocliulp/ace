#include <stdio.h>
#include <stdlib.h>

#define N 1024

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
  int empty = 0;
  int ret = 0;
  if (q == 0) return 1;
  
  n = malloc (sizeof (struct node));
  n -> value = value;
  n -> next = 0;

  ret = queue_is_empty (&empty, q);
  if (ret != 0) return 1;
  if (empty) {
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
  int empty = 0;
  int ret = 0;

  if (q == 0) return 1;
  ret = queue_is_empty (&empty, q);
  if (ret != 0) return 1;
  if (empty) return 1;
  p = q -> head;
  if (q -> head == q -> tail) {
    q -> head = 0;
    q -> tail = 0;
  } else {
    q -> head = p -> next;
  }
  *value = p -> value;
  free (p);

  return 0;
}

int queue_is_empty (int* empty, struct queue * q) {
  *empty = 0;
  if (q == 0) return 1;
  if (q -> head == 0 && q -> tail == 0) {
    *empty = 1;
    return 0;
  } else if (q -> head == 0 && q -> tail != 0) {
    return 1;
  } else if (q -> head != 0 && q -> tail == 0) {
    return 1;
  } else if (q -> head !=0 && q -> tail != 0) {
    *empty = 0;
    return 0;
  } else {
    return 1;
  }
  
  return 1;
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
    printf ("%c -> ", n -> value);
    n = n -> next;
  }

  printf ("\n\r");
  return 0;
}

int error_exit (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  struct queue * q = 0;
  char string[N] = {'\0'};
  int i = 0;
  int ret = 0;
  int c = 0;

  scanf ("%s", string);

  q = malloc (sizeof(struct queue));
  q -> head = 0;
  q -> tail = 0;

  i = -1;
  while (string[++i] != '\0') {
    printf ("%d\n\r", i);

    if (string[i] == '*') {
      ret = queue_get (&c, q);
      if (ret != 0) return error_exit (ret);
    } else {
      ret = queue_put (q, string[i]);
      if (ret != 0) return error_exit (ret);
    }

    queue_print (q);
  }

  free (q);

  return 0;
}
