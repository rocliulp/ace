#include <error_codes.h>
#include <error.h>

struct point2d {
  int x;
  int y;
};

struct point3d {
  struct point2d _;
  int z;
};


