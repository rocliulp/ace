#ifndef _TNODE_H_
#define _TNODE_H_

struct TNode;

int TNode_New (struct TNode * * ppNode);
int TNode_Delete (struct TNode * pNode);
int TNode_Print (struct TNode * pNode);

typedef TNode Tree;
int Tree_New (Tree * * ppTree);
int Tree_Delete (Tree * pTree);
int Tree_Print (Tree * pTree);
int Tree_Position (Tree * pTree, int x, int y, int width, int height);

#endif
