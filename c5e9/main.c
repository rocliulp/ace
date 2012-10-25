#include <stdio.h>
#include <stdlib.h>
#include <error_codes.h>
#include <error.h>

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

typedef struct LNode Link;
static int Link_New (Link * * ppLink) {
  int ret = 0;
  struct LNode * pLNode = NULL;
  if (ppLink == NULL) return EC_NULL_POINTER;

  pLNode = malloc (sizeof (struct LNode));
  if (pLNode == NULL) return EC_OUT_OF_MEMORY;
  pLNode -> id = -1;
  pLNode -> pNext = NULL;

  * ppLink = pLNode;

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
  if (pInsertNd == NULL) return EC_NULL_POINTER;

  if (pLNode == pLink) {
    pLNode -> pNext = pInsertNd;
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

static int Link_Josephus (Link * pLink, struct LNode * pLNode, int gap) {
  int ret = 0;
  int i = -1;
  if (pLink == NULL) return EC_NULL_POINTER;
  if (pLNode == NULL) return EC_NULL_POINTER;
  if (gap < 1) return EC_OUT_OF_RANGE;

  if (pLNode == pLNode -> pNext) {
    printf ("%d\n\r", pLNode -> id);
    return EC_OK;
  }

  while (++ i < gap - 1) {
    pLNode = pLNode -> pNext;
  }
  printf ("%d\n\r", pLNode -> pNext -> id);
  ret = Link_DeleteAfter (pLink, pLNode);
  if (ret != EC_OK) return ret;
  pLNode = pLNode -> pNext;
  ret = Link_Josephus (pLink, pLNode, gap);
  if (ret != EC_OK) return ret;

  return EC_OK;
}

static inline int main_CreateJosephusLink_Fail (int ret, Link * pLink) {
  Link_Delete (pLink);
  return ret;
}

static int main_CreateJosephusLink (Link * * ppLink) {
  int ret = 0;
  int i = -1;
  Link * pLink = NULL;
  struct LNode * pLNode = NULL;
  struct LNode * pNd = NULL;
  if (ppLink == NULL) return EC_NULL_POINTER;

  ret = Link_New (& pLink);
  if (ret != EC_OK) return ret;

  while (++ i < 15) {
    ret = LNode_New (& pNd, i);
    if (ret != EC_OK) return main_CreateJosephusLink_Fail (ret, pLink);
    if (pLNode == NULL) {
      pLink -> pNext = pNd;
    } else {
      pLNode -> pNext = pNd;
    }
    pLNode = pNd;
  }
  pLNode -> pNext = pLink -> pNext;

  * ppLink = pLink;
  return EC_OK;
}

static inline int main_Fail (int ret, Link * pLink) {
  Link_Delete (pLink);
  return error_print (ret);
}

int main (int argc, char * argv []) {
  Link * pLink = NULL;
  int ret = 0;
  ret = main_CreateJosephusLink (& pLink);
  if (ret != EC_OK) return main_Fail (ret, pLink);
  ret = Link_Josephus (pLink, pLink -> pNext, 5);
  if (ret != EC_OK) return main_Fail (ret, pLink);
  return EC_OK;
}
