#include <stdlib.h>
#include <stdio.h>

#include <error_codes.h>
#include <error.h>
#include <TNode.h>

static inline int main_Fail (int ret, Tree * pTree) {
  Tree_Delete (pTree);
  return error_print (ret);
}

int main (int argc, char * argv []) {
  int ret = 0;
  Tree * pTree = NULL;
  int path = -1;

  ret = Tree_New (& pTree);
  if (ret != 0) return error_print (ret);

  ret = Tree_Print ((Tree const *) pTree);
  if (ret != 0) {
    Tree_Delete (pTree);
    return error_print (ret);
  }

  printf ("\n\r");

  ret = Tree_Position (pTree, 0, 0, 65536, 65536);
  if (ret != 0) {
    Tree_Delete (pTree);
    return error_print (ret);
  }

  ret = Tree_Print ((Tree const *) pTree);
  if (ret != 0) {
    Tree_Delete (pTree);
    return error_print (ret);
  }

  printf ("\n\r");

  ret = Tree_GetExternalPath (pTree, & path);
  if (ret != EC_OK) return main_Fail (ret, pTree);
  printf ("Tree external path: %d\n\r", path);
  ret = Tree_Print ((Tree const *) pTree);
  if (ret != 0) return main_Fail (ret, pTree);

  printf ("\n\r");
  
  path = 0;
  ret = CTree_GetExternalPath (pTree, & path);
  if (ret != EC_OK) return main_Fail (ret, pTree);
  printf ("Common tree external path: %d\n\r", path);
  ret = Tree_Print ((Tree const *) pTree);
  if (ret != 0) return main_Fail (ret, pTree);

  Tree_Delete (pTree);
  return 0;
}
