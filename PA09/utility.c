#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

//pushes node onto the stack
Stack * Stack_push(Stack * st, HuffNode * h)
{
  Stack * newnode = malloc(sizeof(Stack));
  topnode -> node = h;
  topnode -> next = st;
  return newnode;
}
//pops the node off the stack
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
//creates a stack node
Stack * Stack_create(HuffNode * h)
{
  Stack * st;
  st = malloc(sizeof(Stack));
  st -> node = h;
  st -> next = NULL;
  return st;
}
//creates a Huff Node
HuffNode * HuffNode_create(int val)
{
  HuffNode * h = malloc(sizeof(HuffNode));
  h -> value = val;
  h -> left = NULL;
  h -> right = NULL;
  return h;
}
//checks to see if file is character file or bit file
int isCharFile(char * filename)
{
  if(strstr(filename, "ch") != NULL)
    {
      return 1; //file is character file
    }
  else
    {
      return 0; //file is bit file
    }
}
//builds Huffman tree from character file
HuffNode * HuffNode_CharBuild(char * filename)
{
  FILE * fptr;
  char ch;
  HuffNode * h = NULL;
  HuffNode * a = NULL;
  HuffNode * b = NULL;
  Stack * top = NULL;

  fptr = fopen(filename, "r");
  
  ch = fgetc(fptr);
  
  while(ch != EOF)
    {
      if(ch == '1')
	{
	  ch = fgetc(fptr);
	  h = HuffNode_create(ch);
	  top = Stack_create(h);
	  top = Stack_push(top,h);
	}
      else
	{
	  a = top->node;         //store tree node at top of stack to a
	  top = Stack_pop(st);   //pop the stack
	  if(top == NULL)
	    {
	      h = a; //a becomes root
	    }
	  else
	    {
	      b = top->node;            //store treenode at top of stack to b
	      top = Stack_pop(top);     //pop the stack
	      h = HuffNode_create(0);   //create a new tree node
	      h->right = a;             
	      h->left = b;
	      top = Stack_push(top,h);  //push treenode to stack
	    }	  
	}
      ch = fgetc(fptr);
    }

  fclose(fptr);

  return h;
}
//builds Huffman tree from bit file
HuffNode * HuffNode_BitBuild(char * filename)
{
  FILE * fptr;
  HuffNode * h = NULL;
  HuffNode * a = NULL;
  HuffNode * b = NULL;
  Stack * top = NULL;

  fptr = fopen(filename, "r");

  unsigned char ch = fgetc(fptr); //one byte
  int cmdloc = 0;
  unsigned char masks[] = 
    { 0x80, 0x40, 0x20, 0x10,
      0x08, 0x04, 0x02, 0x01};
  
  unsigned char command = (ch & masks[cmdloc]);
  
  if(command != 0) //command is 1
    {
    }
}
//destroys Huffman tree
void Huffman_destroy(HuffNode * h)
{
  if(h == NULL)
    {
      return;
    }
  Huffman_destroy(h->left);
  Huffman_destroy(h->right);
  free(h);
}
//counts elements on the stack
int StackCount(Stack * st, int counter)
{  
  if(st == NULL)
    {
      return 0;
    }
  
  counter++;
  StackCount(Stack->next,counter);
  
  return counter;
}
