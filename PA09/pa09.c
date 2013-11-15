#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

int main (int argc , char ** argv)
{
  HuffNode * h = NULL; //variable for Huffman tree to be stored
  
  //check arguments
  if (argc != 3)
    {
      printf("usage: ./pa09 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }
  
  //creates Huffman tree
  if(isCharFile(char * filename))
    {
      h = HuffNode_CharBuild(filename);
    }
  else
    {
      h = HuffNode_BitBuild(filename);
    }
  Huff_postOrderPrint(h, argv[2]);
  Huffman_destroy(h);
  
  fclose(fptr);
  return EXIT_SUCCESS;	
}
void Huff_postOrderPrint(HuffNode * tree)
{
  fopen(filename, "w");
  
  // Base case: empty subtree
  if (tree == NULL) 
    {
      return;
    }

  // Recursive case: post-order traversal
    
  // Visit left
  printf("Left\n");
  Huff_postOrderPrint(tree->left);
  printf("Back\n");
  // Visit right
  printf("Right\n");
  Huff_postOrderPrint(tree->right);
  printf("Back\n");
  // Visit node itself (only if leaf)
  if (tree->left == NULL && tree->right == NULL) 
    {
      printf("Leaf: %c\n", tree->value);
    }
}
