#include <stdio.h>

#define N 10

static int queue[N] = {0};
static int head = -1;
static int tail = -1;

static int queueInit () {
  tail = -1;
  head = -1;
  return 0;
}

static int put (int v) {
  if (tail >= head) {
    ++tail;
    if (tail < N) {
      queue[tail] = v;
    } else {
      if (head > -1) {
        tail = 0;
        queue[tail] = v;
      } else {
        return 1;
      }
    }
  } else {
    ++tail;
    if (tail <= head) {
      queue[tail] = v;
    } else {
      return 1;
    }
  }
  return 0;
}

static int get (int* v) {
  if (head == tail) {
    return 2;
  } else if (head < tail) {
    ++head;
    *v = queue[head];
  } else {
    ++head;
    if (head < N) {
      *v = queue[head];
    } else {
      if (tail > -1) {
        head = 0;
        *v = queue[head];
      } else {
        return 2;
      }
    }
  }
  return 0;
}

static int isEmtpy () {
  if (head == tail) return 1;
  else return 0;
}

static int printQueue () {
  int i = 0;
  if (head == tail) {
  } else if (head < tail) {
    i = head;
    while (++i < tail + 1) {
      printf ("%c", queue[i]);
    }
  } else {
    i = head;
    while (++i < N) {
      printf ("%c", queue[i]);
    }
    i = -1;
    while (++i < tail + 1) {
      printf ("%c", queue[i]);
    }
  }
  printf ("\n\r");
  return 0;
}

static int ErrorExit (int ret) {
  printf ("Error: %d\n\r", ret);
  return ret;
}

int main (int argc, char* argv[]) {
  int i = -1;
  int v = 0;
  int ret = 0;
  char string[1024] = {'\0'};

  scanf ("%s", string);

  while (string[++i] != '\0') {
    if (string[i] == '*') {
      ret = get (&v);
      if (ret != 0) return ErrorExit (ret);
    } else {
      ret = put (string[i]);
      if (ret != 0) return ErrorExit (ret);
    }
    printQueue();
  }
  return 0;
}
