
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode * TreeNode_create(int value)
{
    TreeNode * node = malloc(sizeof(TreeNode));
    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

TreeNode * Tree_insert(TreeNode * node, int value)
{
    if(node == NULL)
	return TreeNode_create(value);
    if(value < node -> value)
	node -> left = Tree_insert(node -> left, value);
    if(value > node -> value)
	node -> right = Tree_insert(node -> right, value);
    // If they're equal, then we have nothing to do...
    return node;
}

TreeNode * Tree_build(int * array, int len)
{
    TreeNode * root = NULL;
    int i;
    for(i = 0; i < len; ++i)
	root = Tree_insert(root, array[i]);
    return root;
}

void Tree_destroy(TreeNode * node)
{
    if(node == NULL)
	return;
    Tree_destroy(node -> left);
    Tree_destroy(node -> right);
    free(node);
}

void Tree_printShapeHelper(TreeNode * node)
{
    if(node == NULL)
	return;
    if(node -> left != NULL) {
	printf("(");
	Tree_printShapeHelper(node -> left);
	printf(")");
    }
    printf("%d", node -> value);
    if(node -> right != NULL) {
	printf("(");
	Tree_printShapeHelper(node -> right);
	printf(")");
    }
}

/**
 * This function is given to you:
 */
void Tree_printShape(TreeNode * node)
{
    Tree_printShapeHelper(node);
    printf("\n");
}

