#ifndef TREE_H
#define TREE_H

// ----------------------------------- Binary Trees
typedef struct tree_node_t {
    int value;
    struct tree_node_t * left;
    struct tree_node_t * right;
} TreeNode;

TreeNode * TreeNode_create(int value);
TreeNode * Tree_insert(TreeNode * node, int value);
TreeNode * Tree_build(int * array, int len);
void Tree_destroy(TreeNode * node);
void Tree_printShape(TreeNode * node);

#endif
