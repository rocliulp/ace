/*
 * @author Paul Liu
 * @summary Implementation of TNode
 */

#include <stdio.h>
#include <stdlib.h>
#include <error_codes.h>

struct TNode {
  struct TNode * pLeft;
  struct TNode * pRight;
  int x;
  int y;
};

int TNode_New (struct TNode * * ppNode) {
  if (ppNode == NULL) return EC_NULL_POINTER;
  TNode * pNode = malloc (sizeof (TNode));
  if (pNode == NULL) {
    return EC_OUT_OF_MEMORY;
  }
  pNode -> pLeft = NULL;
  pNode -> pRight = NULL;
  pNode -> x = 0;
  pNode -> y = 0;

  * ppNode = pNode;
  
  return 0;
}

int TNode_Delete (struct TNode * pNode) {
  if (pNode == NULL) return EC_NULL_POINTER;
  free (pNode);
  return 0;
}

int TNode_Print (struct TNode * pNode) {
  if (pNode == NULL) return EC_NULL_POINTER;
  printf ("(%d, %d)\n\r", pNode -> x, pNode -> y);
  return 0;
}

typedef TNode Tree;
int Tree_New (Tree * * ppTree) {
  if (ppTree == NULL) return EC_NULL_POINTER;

  return 0;
}

int Tree_Delete (Tree * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree -> pLeft != NULL) {
    ret = TNode_Delete (pTree -> pLeft);
    if (ret != 0) return ret;
  }
  if (pTree -> pRight != NULL) {
    ret = TNode_Delete (pTree -> pRight);
    if (ret != 0) return ret;
  }
  ret = TNode_Delete (pTree);
  if (ret != 0) return ret;
  return 0;
}

int Tree_Print (Tree * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree -> pLeft != NULL) {
    ret = TNode_Print (pTree -> pLeft);
    if (ret != 0) return ret;
  }
  ret = TNode_Print (pTree);
  if (ret != 0) return ret;
  if (pTree -> pRight != NULL) {
    ret = TNode_Print (pTree -> pRight);
    if (ret != 0) return ret;
  }
  return 0;
}

int Tree_Position (Tree * pTree, int x, int y, int width, int height) {
  return 0;
}
