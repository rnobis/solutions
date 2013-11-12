#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

Stack * Stack_push(Stack * st, HuffNode * h)
{
  Stack * topnode = malloc(sizeof(Stack));
  topnode -> node = h;
  topnode -> next = st;
  return topnode;
}

Stack * Stack_pop(Stack * st)
{
  if (st == NULL)
    {
      return NULL;
    }
  Stack * b = st -> next;
  free(st);
  return b;
}
Stack * Stack_create(HuffNode * h)
{
  Stack * st;
  st = malloc(sizeof(Stack));
  st -> node = h;
  st -> next = NULL;
  return st;
}
HuffNode * HuffNode_create(int val)
{
  HuffNode * h = malloc(sizeof(HuffNode));
  h -> value = val;
  h -> left = NULL;
  h -> right = NULL;
  return h;
}
int isLeaf (HuffNode * h)
{
  if(h == NULL)
    {
      return 1;
    }
  if((h -> left) != NULL)
    {
      return 0; //not a leaf node
    }
  if((h -> right) != NULL)
    {
      return 0; //not a leaf node
    }
  return 1;
}
