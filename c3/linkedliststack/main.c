#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node * next;
};

int stackInit (struct node ** head) {
  if (head == 0) {
    return 1;
  }
  *head = malloc (sizeof (struct node));
  (*head) -> key = -1;
  (*head) -> next = 0;
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

int ErrorExit(int ret) {
  printf ("Error code: %d", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  char c = '\0';
  struct node * head = 0;
  int ret = 0;
  int i = 0;
  int j = -1;
  int x = 0;
  char string[1024] = {'\0'};
  char express[1024] = {'\0'};
  
  scanf ("%s", string);

  ret = stackInit (&head);
  if (ret != 0) {
    return ErrorExit(ret);
  }

  i = 0;
  c = string[i];
  while (c != '\0') {
    if (c == '(') {
      printf (" ");
    } else if (c == '+') {
      ret = push (c, head);
      if (ret != 0) {
        return ErrorExit(ret);
      }
    } else if (c == '*') {
      ret = push (c, head);
      if (ret != 0) {
        return ErrorExit(ret);
      }
    } else if (c == ')') {
      if (!emptyStack(head)) {
        ret = pop ((int*)&c, head);
        if (ret != 0) {
          return ErrorExit(ret);
        }
        printf ("%c", c);
        express[++j] = c;
      } else {
        return ErrorExit (1);
      }
    } else if (c >= '0' && c <= '9') {
      printf ("%1c", c);
      express[++j] = c;
    } else {
      printf (" ");
    }
    
    c = string[++i];
  }

  if (emptyStack(head)) return 1;
  ret = pop((int*)(&c), head);
  if (ret != 0) {
    return ErrorExit(ret);
  }
  printf ("%c", c);
  express[++j] = c;

  ret = stackRemove (head);
  if (ret != 0) return ErrorExit (ret);
  printf ("\n\r\n\r");
  printf ("%s\n\r", express);

  ret = stackInit (&head);
  if (ret != 0) return ErrorExit (ret);

  i = -1;
  while (express[++i] != '\0') {
    c = express[i];
    j = 0;
    x = 0;
    if (c == '+') {
      ret = pop (&x, head);
      if (ret != 0) return ErrorExit (ret);

      ret = pop (&j, head);
      if (ret != 0) return ErrorExit (ret);

      x = x + j;
    } else if (c == '*') {
      ret = pop (&x, head);
      if (ret != 0) return ErrorExit (ret);

      ret = pop (&j, head);
      if (ret != 0) return ErrorExit (ret);

      x = x * j;
    } else if (c >= '0' && c <= '9') {
      x = c - '0';
    } else {
      return ErrorExit (1);
    }

    ret = push (x, head);
    if (ret != 0) return ErrorExit (ret);
  }

  printf ("%d\n\r", x);

  ret = stackRemove (head);
  if (ret != 0) return ErrorExit (ret);

  return 0;
}
