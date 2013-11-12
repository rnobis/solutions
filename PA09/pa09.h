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

#endif

