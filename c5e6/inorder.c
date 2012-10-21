#include <stdlib.h>
#include <stdio.h>
#include <error_codes.h>
#include <stack.h>
#include <queue.h>

struct TNode {
  struct TNode * pLeft;
  struct TNode * pRight;
  int visited;
  int id;
};

static int TNode_New (struct TNode * * ppTNode, int id) {
  struct TNode * pTNode = NULL;
  if (ppTNode == NULL) return EC_NULL_POINTER;

  pTNode = malloc (sizeof (struct TNode));
  if (pTNode == NULL) return EC_OUT_OF_MEMORY;
  pTNode -> id = id;
  pTNode -> visited = FALSE;
  pTNode -> pLeft = NULL;
  pTNode -> pRight = NULL;

  * ppTNode = pTNode;

  return EC_OK;
}

static int TNode_Delete (struct TNode * pTNode) {
  if (pTNode == NULL) return EC_NULL_POINTER;
  free (pTNode);
  return EC_OK;
}

static int TNode_Print (struct TNode const * pTNode) {
  if (pTNode == NULL) return EC_NULL_POINTER;

  printf ("%d\n\r", pTNode -> id);

  return EC_OK;
}

typedef struct TNode Tree;
static int Tree_Delete (Tree * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree -> pLeft != NULL) {
    ret = Tree_Delete (pTree -> pLeft);
    if (ret != EC_OK) return ret;
  }
  if (pTree -> pRight != NULL) {
    ret = Tree_Delete (pTree -> pRight);
    if (ret != EC_OK) return ret;
  }
  TNode_Delete (pTree);
  return EC_OK;
}

static inline int Tree_New_Fail (int ret, Tree * pTree, struct queue * pQueue) {
  Tree_Delete (pTree);
  queue_delete (pQueue);
  return ret;
}

static int Tree_New (Tree * * ppTree) {
  int ret = 0;
  int i = -1;
  int empty = 0;
  struct TNode * pTNode = NULL;
  struct TNode * pNd = NULL;
  struct queue * pQueue = NULL;

  if (ppTree == NULL) return EC_NULL_POINTER;
  ret = queue_new (& pQueue, 10);
  if (ret != EC_OK) return ret;
  ret = TNode_New (& pTNode, ++ i);
  if (ret != EC_OK) {
    queue_delete (pQueue);
    return ret;
  }
  * ppTree = pTNode;
  ret = queue_put (pQueue, pTNode);
  if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);

  while (i < 10) {
    ret = queue_is_empty (pQueue, & empty);
    if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);
    if (empty == TRUE) {
      return Tree_New_Fail (EC_IMPOSSIBLE_CASE, * ppTree, pQueue);
    }
    ret = queue_get (pQueue, (void const * *)(& pTNode));
    if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);

    ret = TNode_New (& pNd, ++ i);
    if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);
    pTNode -> pLeft = pNd;
    ret = queue_put (pQueue, pNd);
    if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);

    ret = TNode_New (& pNd, ++ i);
    if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);
    pTNode -> pRight = pNd;
    ret = queue_put (pQueue, pNd);
    if (ret != EC_OK) return Tree_New_Fail (ret, * ppTree, pQueue);
  }

  queue_delete (pQueue);
  return EC_OK;
}

static int Tree_ResetVisited (Tree * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree -> pLeft != NULL) {
    ret = Tree_ResetVisited (pTree -> pLeft);
    if (ret != EC_OK) return ret;
  }
  if (pTree -> pRight != NULL) {
    ret = Tree_ResetVisited (pTree -> pRight);
    if (ret != EC_OK) return ret;
  }
  pTree -> visited = FALSE;
  return EC_OK;
}

static int Tree_RecursionInOrder (Tree * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;

  if (pTree -> pLeft != NULL) {
    ret = Tree_RecursionInOrder (pTree -> pLeft);
    if (ret != EC_OK) return ret;
  }
  ret = TNode_Print (pTree);
  if (ret != EC_OK) return ret;
  if (pTree -> pRight != NULL) {
    ret = Tree_RecursionInOrder (pTree -> pRight);
    if (ret != EC_OK) return ret;
  }

  return EC_OK;
}

static inline int Tree_NoRecursionInOrder_Fail (int ret,
    struct stack * pStack) {
  stack_delete (pStack);
  return ret;
}

int Tree_NoRecursionInOrder (Tree * pTree) {
  int ret = 0;
  int empty = 0;
  struct stack * pStack = NULL;
  struct TNode * pTNode = NULL;
  struct TNode * pNd = NULL;

  if (pTree == NULL) return EC_NULL_POINTER;

  ret = stack_new (& pStack, 10);
  if (ret != EC_OK) return ret;

  pTNode = pTree;
  while (pTNode != NULL) {
    while (pTNode -> pLeft != NULL && pTNode -> pLeft -> visited == FALSE) {
      ret = stack_push (pStack, pTNode);
      if (ret != EC_OK) return Tree_NoRecursionInOrder_Fail (ret, pStack);

      pTNode = pTNode -> pLeft;
    }

    ret = TNode_Print (pTNode);
    if (ret != EC_OK) return Tree_NoRecursionInOrder_Fail (ret, pStack);
    pTNode -> visited = TRUE;

    if (pTNode -> pRight != NULL && pTNode -> pRight -> visited == FALSE) {
      pTNode = pTNode -> pRight;
    } else {
      ret = stack_is_empty (pStack, & empty);
      if (ret != EC_OK) return Tree_NoRecursionInOrder_Fail (ret, pStack);
      if (empty == FALSE) {
        ret = stack_pop (pStack, (void const * *) (& pTNode));
        if (ret != EC_OK) return Tree_NoRecursionInOrder_Fail (ret, pStack);
      } else {
        pTNode = NULL;
      }
    }
  }
  stack_delete (pStack);
  return EC_OK;
}

static int Tree_RecursionPostOrder (Tree * pTree) {
  int ret = 0;
  if (pTree == NULL) return EC_NULL_POINTER;
  if (pTree -> pLeft != NULL) {
    ret = Tree_RecursionPostOrder (pTree -> pLeft);
    if (ret != EC_OK) return ret;
  }
  if (pTree -> pRight != NULL) {
    ret = Tree_RecursionPostOrder (pTree -> pRight);
    if (ret != EC_OK) return ret;
  }
  ret = TNode_Print (pTree);
  if (ret != EC_OK) return ret;
  return EC_OK;
}

static inline int Tree_NoRecursionPostOrder_Fail (int ret, struct stack * pStack) {
  stack_delete (pStack);
  return ret;
}

static int Tree_NoRecursionPostOrder (Tree * pTree) {
  int ret = 0;
  struct stack * pStack = NULL;
  struct TNode * pTNode = NULL;
  int empty = 0;

  if (pTree == NULL) return EC_NULL_POINTER;

  ret = stack_new (& pStack, 10);
  if (ret != EC_OK) return ret;

  pTNode = pTree;
  while (pTNode != NULL) {
    if (pTNode -> pLeft != NULL && pTNode -> pLeft -> visited == FALSE) {
      ret = stack_push (pStack, pTNode);
      if (ret != EC_OK) return Tree_NoRecursionPostOrder_Fail (ret, pStack);
      pTNode = pTNode -> pLeft;
    } else if (pTNode -> pRight != NULL
        && pTNode -> pRight -> visited == FALSE) {
      ret = stack_push (pStack, pTNode);
      if (ret != EC_OK) return Tree_NoRecursionPostOrder_Fail (ret, pStack);
      pTNode = pTNode -> pRight;
    } else {    
      ret = TNode_Print (pTNode);
      if (ret != EC_OK) return Tree_NoRecursionPostOrder_Fail (ret, pStack);
      pTNode -> visited = TRUE;
      
      ret = stack_is_empty (pStack, & empty);
      if (ret != EC_OK) return Tree_NoRecursionPostOrder_Fail (ret, pStack);
      if (empty == FALSE) {
        ret = stack_pop (pStack, (void const * *)(& pTNode));
        if (ret != EC_OK) return Tree_NoRecursionPostOrder_Fail (ret, pStack);
      } else {
        pTNode = NULL;
      }
    }
  }

  stack_delete (pStack);
  return EC_OK;
}

static inline int main_Fail (int ret, Tree * pTree) {
  Tree_Delete (pTree);
  return ret;
}

int main (int argc, char * argv []) {
  int ret = 0;
  Tree * pTree = NULL;
  ret = Tree_New (& pTree);
  if (ret != EC_OK) return ret;
  
  printf ("Recursion In Order:\n\r");
  ret = Tree_RecursionInOrder (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  printf ("\n\r");
  ret = Tree_ResetVisited (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  printf ("No Recursion In Order:\n\r");
  ret = Tree_NoRecursionInOrder (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  printf ("\n\r");
  ret = Tree_ResetVisited (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  printf ("Recursion Post Order:\n\r");
  ret = Tree_RecursionPostOrder (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  printf ("\n\r");
  ret = Tree_ResetVisited (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  printf ("No Recursion Post Order:\n\r");
  ret = Tree_NoRecursionPostOrder (pTree);
  if (ret != EC_OK) return main_Fail (ret, pTree);

  Tree_Delete (pTree);
  return EC_OK;
}
