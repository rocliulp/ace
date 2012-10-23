#include <stdio.h>
#include <stdlib.h>
#include <error_codes.h>

struct LNode {
  int id;
  struct LNode * pNext;
};

static int LNode_New (struct LNode * * ppLNode, int id) {
  int ret = 0;
  struct LNode * pLNode = NULL;
  if (ppLNode == NULL) return EC_NULL_POINTER;
  if (id < 0) return EC_OUT_OF_RANGE;

  pLNode = malloc (sizeof (struct LNode));
  if (pLNode == NULL) return EC_OUT_OF_MEMORY;
  pLNode -> id = id;
  pLNode -> pNext = NULL;

  * ppLNode = pLNode;

  return EC_OK;
}

static int LNode_Delete (struct LNode * pLNode) {
  if (pLNode == NULL) return EC_NULL_POINTER;
  free (pLNode);
  return EC_OK;
}

typedef LNode Link;
static int Link_New (Link * * ppLink) {
  int ret = 0;
  struct LNode * pLNode = NULL;
  if (ppLink == NULL) return EC_NULL_POINTER;

  pLNode = malloc (sizeof (struct LNode));
  if (pLNode == NULL) return EC_OUT_OF_MEMORY;
  pLNode -> id = -1;
  pLNode -> pNext = NULL;

  * ppLink = plNode;

  return EC_OK;
}

static int Link_Delete (Link * pLink) {
  int ret = 0;
  struct LNode * pLNode = NULL;
  if (pLink == NULL) return EC_NULL_POINTER;
  
  pLNode = pLink -> pNext;
  while (pLNode != NULL) {
    struct LNode * pNd = pLNode;
    if (pLNode -> pNext != pLink -> pNext) {
      pLNode = pLNode -> pNext;
    } else {
      pLNode = NULL;
    }

    LNode_Delete (pNd);
  }

  LNode_Delete (pLink);

  return EC_OK;
}

static int Link_InsertAfter (Link * pLink, struct LNode * pLNode,
    struct LNode * pInsertNd) {
  if (pLink == NULL) return EC_NULL_POINTER;
  if (pLNode == NULL) return EC_NULL_POINTER;
  if (PInsertNd == NULL) return EC_NULL_POINTER;

  if (pLNode == pLink) {
    pLNode - > pNext = pInsertNd;
    pInsertNd -> pNext = pInsertNd;
  } else {
    struct LNode * pNd = pLNode -> pNext;
    pLNode -> pNext = pInsertNd;
    pInsertNd -> pNext = pNd;
  }

  return EC_OK;
}

static int Link_DeleteAfter (Link * pLink, struct LNode * pLNode) {
  struct LNode * pNd = NULL;
  if (pLink == NULL) return EC_NULL_POINTER;
  if (pLNode == NULL) return EC_NULL_POINTER;

  pNd = pLNode -> pNext;
  if (pNd == pLNode) return EC_OUT_OF_RANGE;
  if (pLink -> pNext == pNd) {
    pLink -> pNext = pNd -> pNext;
  }
  pLNode -> pNext = pNd -> pNext;
  LNode_Delete (pNd);

  int ret = 0;
}

static int Link_Josephus (Link * pLink, LNode * pLNode, int gap) {
  if (pLink == NULL) return EC_NULL_POINTER;

  return EC_NULL_POINTER;
}

int main (int argc, char * argv []) {
  return EC_OK;
}
