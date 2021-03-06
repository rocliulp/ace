#ifndef _TNODE_H_
#define _TNODE_H_

struct TNode;
typedef struct TNode Tree;

int Tree_New (Tree * * ppTree);
int Tree_Delete (Tree * pTree);
int Tree_Print (Tree const * pTree);
int Tree_Position (Tree * pTree, int x, int y, int width, int height);
int Tree_GetExternalPath (Tree * pTree, int * pPath);

typedef struct TNode CTree;
int CTree_GetExternalPath (CTree * pCTree, int * pPath);

#endif
