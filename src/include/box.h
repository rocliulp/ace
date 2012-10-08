#ifndef _BOX_H_
#define _BOX_H_

struct box2d;
struct box3d;

#ifdef _GEO_2D_
typedef box2d box;
#else
typedef box3d box;
#endif

#endif
