#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <error_codes.h>

struct Point {
  int x;
  int y;
};

static int CalculatePoints (struct Point * pStart, struct Point * pEnd) {
  int ret = 0;
  float dis = 0.0;
  float xPower = 0.0;
  float yPower = 0.0;
  struct Point point = {-1, -1};

  if (pStart == NULL) return EC_NULL_POINTER;
  if (pEnd == NULL) return EC_NULL_POINTER;

  xPower = pStart -> x - pEnd -> x;
  xPower = pow (xPower, 2);

  yPower = pStart -> y - pEnd -> y;
  yPower = pow (yPower, 2);

  dis = xPower + yPower;
  if (dis > 3) {
    point.x = (pStart -> x + pEnd -> x) / 2;
    point.y = (pStart -> y + pEnd -> y) / 2;
    printf ("(%d, %d) ", point.x, point.y);

    ret = CalculatePoints (pStart, & point);
    if (ret != EC_OK) return ret;

    ret = CalculatePoints (& point, pEnd);
    if (ret != EC_OK) return ret;
    printf ("\n\r");
  }

  return EC_OK;
}

int main (int argc, char * argv []) {
  int ret = 0;
  struct Point start;
  struct Point end;

  start.x = 0;
  start.y = 0;

  end.x = 100;
  end.y = 100;

  printf ("start: (%d, %d)\n\r", start.x, start.y);
  printf ("end: (%d, %d)\n\r", end.x, end.y);
  ret = CalculatePoints (& start, & end);
  if (ret != EC_OK) return error_print (ret);

  return EC_OK;
}
