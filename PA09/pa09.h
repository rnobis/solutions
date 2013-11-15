#ifndef PA09_H
#define PA09_H

typedef struct _huffnode {
    int value; 
    struct _huffnode * left;
    struct _huffnode * right;
} HuffNode;

typedef struct _stack {
    struct _stack * next; 
    HuffNode * node; //data
} Stack;

Stack * Stack_push(Stack * st, HuffNode * h);
Stack * Stack_pop(Stack * st);
Stack * Stack_create(HuffNode * h);
HuffNode * HuffNode_create(int val);
int isCharFile(char * filename);
HuffNode * HuffNode_CharBuild(char * filename);
HuffNode * HuffNode_BitBuild(char * filename);
void Huffman_destroy(HuffNode * h);
int StackCount(Stack * st, int counter);


#endif

