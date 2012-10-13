#include <stdlib.h>
#include <stdio.h>

#include <error_codes.h>
#include <error.h>
#include <TNode.h>

int main (int argc, char * argv []) {
  int ret = 0;
  Tree * pTree = NULL;

  ret = Tree_New (& pTree);
  if (ret != 0) return error_print (ret);

  ret = Tree_Print ((Tree const *) pTree);
  if (ret != 0) {
    Tree_Delete (pTree);
    return error_print (ret);
  }

  ret = Tree_Position (pTree, 0, 0, 65536, 65536);
  if (ret != 0) {
    Tree_Delete (pTree);
    return error_print (ret);
  }

  ret == Tree_Print ((Tree const *) pTree);
  if (ret != 0) {
    Tree_Delete (pTree);
    return error_print (ret);
  }

  Tree_Delete (pTree);
  return 0;
}
