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
  printf ("%d: (%d, %d)\n\r", pNode -> id, pNode -> x, pNode -> y);
  return 0;
}

typedef struct TNode Tree;

static int TreeNewFail (int ret, Tree * pTree, struct queue * pQueue) {
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pQueue == NULL) return EC_NULL_POINTER;
  Tree_Delete (pTree);
  queue_delete (pQueue);
  return ret;
}

int Tree_New (Tree * * ppTree) {
  int ret = 0;
  struct queue * pQueue = NULL;
  int total = -1;
  struct TNode * pNd = NULL;

  if (ppTree == NULL) return EC_NULL_POINTER;

  ret = TNode_New (& pNd, ++ total);
  if (ret != 0) return ret;
  * ppTree = pNd;
  
  ret = queue_new (& pQueue);
  if (ret != 0) {
    Tree_Delete (* ppTree);
    return ret;
  }

  ret = queue_put (pQueue, pNd);
  if (ret != 0) {
    Tree_Delete (* ppTree);
    return ret;
  }

  while (total < 15) {
    ret = queue_get (pQueue, & pNd);
    if (ret != 0) return TreeNewFail (ret, * ppTree, pQueue);

    ret = TNode_New (& (pNd -> pLeft), ++ total);
    if (ret != 0) return TreeNewFail (ret, * ppTree, pQueue);
    ret = queue_push (pQueue, pNd -> pLeft);
    if (ret != 0) return TreeNewFail (ret, * ppTree, pQueue);

    ret = TNode_New (& (pNd -> pRight), ++ total);
    if (ret != 0) return TreeNewFail (ret, * ppTree, pQueue);
    ret = queue_push (pQueue, pNd -> pRight);
    if (ret != 0) return TreeNewFail (ret, * ppTree, pQueue);
  }

  queue_delete (pQueue);
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
