#ifndef _POINT_H_
#define _POINT_H_

struct point2d;
struct point3d;

#ifdef _GEO_2D_
typedef struct point2d point;
#else
typedef struct point3d point;
#endif

#endif
