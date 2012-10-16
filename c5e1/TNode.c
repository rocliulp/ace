/*
 * @author Paul Liu
 * @summary Implementation of TNode
 */

#include <stdio.h>
#include <stdlib.h>
#include <error_codes.h>
#include <queue.h>

struct TNode {
  struct TNode * pLeft;
  struct TNode * pRight;
  struct TNode * pParent;
  int level;
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
  pNode -> pParent = NULL;
  int level = -1;
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

static int TNode_GetLevel (struct TNode const * pNode, int * pLevel) {
  if (pNode == NULL) return EC_NULL_POINTER;
  if (pLevel == NULL) return EC_NULL_POINTER;

  if (pNode -> level < 0) {
    if (pNode -> pParent == NULL) {
      if (pNode -> level < 0) {
        pNode -> level = 0;
      }
    } else {
      int ret = TNode_GetLevel (pNode -> pParent, pLevel);
      if (ret != EC_OK) return ret;
      pNode -> level = * pLevel + 1;
    }
  }

  * pLevel = pNode -> level;
  return EC_OK;
}

typedef struct TNode Tree;

static int Tree_New_Fail (int ret, Tree * pTree, struct queue * pQueue) {
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
  
  ret = queue_new (& pQueue, 10);
  if (ret != 0) {
    Tree_Delete (* ppTree);
    return ret;
  }

  ret = queue_put (pQueue, pNd);
  if (ret != 0) {
    Tree_Delete (* ppTree);
    return ret;
  }

  while (total < 10) {
    struct TNode * pNdEx = NULL;

    ret = queue_get (pQueue, (void const * *) (& pNd));
    if (ret != 0) return Tree_New_Fail (ret, * ppTree, pQueue);

    ret = TNode_New (& (pNdEx), ++ total);
    if (ret != 0) return Tree_New_Fail (ret, * ppTree, pQueue);
    pNd -> pLeft = pNdEx;
    pNdEx -> pParent = pNd;
    ret = queue_put (pQueue, pNdEx);
    if (ret != 0) return Tree_New_Fail (ret, * ppTree, pQueue);

    ret = TNode_New (& (pNdEx), ++ total);
    if (ret != 0) return Tree_New_Fail (ret, * ppTree, pQueue);
    pNd -> pRight = pNdEx;
    pNdEx -> pParent = pNd;
    ret = queue_put (pQueue, pNdEx);
    if (ret != 0) return Tree_New_Fail (ret, * ppTree, pQueue);
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
    ret = Tree_Print ((struct TNode const *) (pTree -> pLeft));
    if (ret != 0) return ret;
  }
  ret = TNode_Print ((struct TNode const *) pTree);
  if (ret != 0) return ret;
  if (pTree -> pRight != NULL) {
    ret = Tree_Print ((struct TNode const *) (pTree -> pRight));
    if (ret != 0) return ret;
  }
  return 0;
}

int Tree_Position (Tree * pTree, int x, int y, int width, int height) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (width < 1) return EC_OUT_OF_RANGE;
  if (height < 1) return EC_OUT_OF_RANGE;

  pTree -> x = x;
  pTree -> y = y;

  if (pTree -> pLeft != NULL) {
    int leftX = x - width / 4;
    ret = Tree_Position (pTree -> pLeft, leftX, y, width / 2, height / 2);
    if (ret != 0) return ret;
  }

  if (pTree -> pRight != NULL) {
    int rightX = x + width / 4;
    int rightY = y + height / 4;
    ret = Tree_Position (pTree -> pRight, rightX, rightY, width / 2,
        height / 2);
    if (ret != 0) return ret;
  }

  return 0;
}

static inline int Tree_GetExternalPath_Fail (int ret, queue * pQueue) {
  queue_delete (pQueue);
  return ret;
}

int Tree_GetExternalPath (Tree * pTree, int * pPath) {
  int ret = 0;
  queue * pQueue = NULL;
  TNode * pNode = NULL;
  int empty = 0;
  int level = -1;

  * pPath = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree == NULL) return EC_NULL_POINTER;

  ret = queue_new (& pQueue, 10);
  if (ret != EC_OK) return ret;

  ret = queue_put (pQueue, (void const * *) pTree);
  if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);
  ret = queue_is_empty (pQueue, & empty);
  if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);
  while (empty == 0) {
    ret = queue_get (pQueue, & pNode);
    if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);
    if (pNode -> pLeft == NULL && pNode -> pRight == NULL) {
      ret = TNode_GetLevel ((struct TNode const *) pNode, & levle);
      if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);
      * pPath += level;
    } else {
      if (pNode -> pLeft != NULL) {
        ret = queue_put (pQueue, pNode -> pLeft);
        if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);        
      }
      if (pNode -> pRight != NULL) {
        ret = queue_put (pQueue, pNode -> pRight);
        if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);
      }
    }

    ret = queue_is_empty (pQueue, & empty);
    if (ret != EC_OK) return Tree_GetExternalPath_Fail (ret, pQueue);
  }

  queue_delete (pQueue);
  return EC_OK;
}
