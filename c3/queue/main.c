#include <stdio.h>

#define N 5

static int stack[N] = {0};
static int bottom = -1;
static int top = -1;

static int stackInit () {
  top = -1;
  bottom = -1;
  return 0;
}

static int push (int v) {
  if (bottom > top) {
    if (++bottom < N) {
      stack[bottom] = v;
    } else if (top == 0) {
      return 1;
    } else {
      bottom = 0;
      stack[bottom] = v;
    }
  } else if (bottom < top){
    if (++bottom < top) {
      stack[bottom] = v;      
    } else {
      return 1;
    }
  } else {
    stack[++bottom] = v;
  }

  return 0;
}

static int pop (int* v) {
  if (top < bottom) {
    *v = stack[++top];
    if (top == bottom) {
      top = -1;
      bottom -1;
    }
  } else if (top > bottom) {
    if (++top < N) {
      *v = stack[top];
    } else {
      top = 0;
      *v = stack[top];
      if (top == bottom) {
        top = -1;
        bottom = -1;
      }
    }
  } else {
    return 1;
  }
  return 0;
}

static int isEmtpy () {
  if (bottom == top) return 1;
  else return 0;
}

int main (int argc, char* argv[]) {
  return 0;
}
