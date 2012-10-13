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
  int id;
  int x;
  int y;
};

static int TNode_New (struct TNode * * ppNode, int id) {
  if (ppNode == NULL) return EC_NULL_POINTER;
  struct TNode * pNode = malloc (sizeof (struct TNode));
  if (pNode == NULL) {
    return EC_OUT_OF_MEMORY;
  }
  pNode -> pLeft = NULL;
  pNode -> pRight = NULL;
  pNode -> id = id;
  pNode -> x = 0;
  pNode -> y = 0;

  * ppNode = pNode;
  
  return 0;
}

static int TNode_Delete (struct TNode * pNode) {
  if (pNode == NULL) return EC_NULL_POINTER;
  free (pNode);
  return 0;
}

static int TNode_Print (struct TNode const * pNode) {
  if (pNode == NULL) return EC_NULL_POINTER;
  printf ("(%d, %d)\n\r", pNode -> x, pNode -> y);
  return 0;
}

typedef struct TNode Tree;
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

int Tree_Print (Tree const * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree -> pLeft != NULL) {
    ret = TNode_Print ((struct TNode const *) (pTree -> pLeft));
    if (ret != 0) return ret;
  }
  ret = TNode_Print ((struct TNode const *) pTree);
  if (ret != 0) return ret;
  if (pTree -> pRight != NULL) {
    ret = TNode_Print ((struct TNode const *) (pTree -> pRight));
    if (ret != 0) return ret;
  }
  return 0;
}

int Tree_Position (Tree * pTree, int x, int y, int width, int height) {
  return 0;
}
