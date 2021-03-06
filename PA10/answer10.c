
#include "pa10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/**
 * Returns a pointer to a new empty stack.
 */
Stack * Stack_create()
{
	Stack * st = malloc(sizeof(Stack));
	st->list = NULL;
    
	return st;
}

/**
 * Frees all memory associated with the stack. 
 * Don't forget that you _must_ free the entire contained linked-list.
 * Also, you must safely to _nothing_ if stack == NULL. 
 */
void Stack_destroy(Stack * stack)
{
	if(stack == NULL)
	{
		return;
	}
	
	free(stack->list);
	free(stack);
}

/**
 * Returns TRUE (something other than zero) if the stack is empty.
 */
int Stack_isEmpty(Stack * stack)
{
	if(stack->list == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * Pop the front 'value' from the stack.
 *
 * More precisely, this function must do two things:
 * (1) Return the value of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 */
int Stack_pop(Stack * stack)
{
	int value;
	ListNode * ln = stack->list; 	
	
	value = stack->list->value;
	stack->list = stack->list->next;
	free(ln);
	printf("\nPOP %d\n",value);

	return value;	
}

/**
 * Push an 'value' onto the front of the stack.
 *
 * More precisely, this function must:
 * (1) Create a new ListNode with 'value' for it's value.
 * (2) Push that new ListNode onto the front of the stack's list.
 */
void Stack_push(Stack * stack, int value)
{
	ListNode * ln = malloc(sizeof(ListNode));

	ln->value = value;
	printf("\nPUSH %d\n",value);
	ln->next = stack->list;
	stack->list = ln;
}

/**
 * Sort 'array' of length 'len' using Donald Knuth's "StackSort"
 *
 * To do this, you must implement the following pseudo-code:
 * (1) Maintain a 'write_index'. This is where you'll write values to
 *     as you sort them. It starts off as zero.
 * (2) Initialize an empty stack
 * (3) For each input value 'x':
 *     (3.a) While the stack is nonempty and 'x' is larger than the 
 *           front 'value' on the stack, pop 'value' and:
 *           (3.a.i) Write 'value' to array[write_index], and 
 *                   increment write_index.
 *     (3.b) Push x onto the stack.
 * (4) While the stack is nonempty, pop the front 'value' and follow
 *     step (3.a.i).
 *
 * The output should be a sorted array if, and only if, the array
 * is stack-sortable. You can find files full of stack-sortable and
 * stack-unsortable arrays in the 'expected' folder.
 */
void stackSort(int * array, int len)
{
	int write_index = 0;
	int i;
	Stack * st = Stack_create();
	Stack * cp = st;

	for(i=0;i < len;i++)
	{
		while(!Stack_isEmpty(st) && (array[i] > st->list->value))
		{
			array[write_index] = Stack_pop(st);
			printf("\n write index array[%d] = %d\n",write_index,array[write_index]);
			write_index++;	
		}
		Stack_push(st,array[i]);
		printf("\narray[%d] = %d\n",i,array[i]);
	}
	while(!Stack_isEmpty(st))
	{
		//printf("\n %d %d %d \n",st->list->value,st->list->next->value,st->list->next->next->value);
		array[write_index] = Stack_pop(st);
		printf("\n write index array[%d] = %d\n",write_index,array[write_index]);
		
		write_index++;
	}
	Stack_destroy(cp);

}

/**
 * Return TRUE (1) if the 'array' of length 'len' is stack-sortable.
 *
 * To do this you must:
 * (1) If 'len' is less than 3, return TRUE.
 * (2) Find the maximum value in 'array'.
 * (3) Partition array into two parts: left of max, and right of max.
 * (4) The maximum value in left must be smaller than the minimum
 *     value in right. (Otherwise return FALSE.)
 * (5) Return TRUE if both left and right are stack-sortable.
 *
 * The 'expected' directory contains files for all sortable and 
 * unsortable sequences of length len. You must return TRUE for every
 * sequence in the sortable files, and you must return FALSE for every
 * sequence in the unsortable files.
 */
int isStackSortable(int * array, int len)
{
	int StackSortMax(int * array, int len);
	int StackSortMin(int * array, int len);
	int max = array[0];
	int i,j = 0;
	int position = 0; //position of max
	int maxL,minR;    //values for max and min of left and right of the array
	
	if(len < 3)
	{
		return TRUE;
	}

	for(i=0;i < len;i++)
	{
		if(array[i] > max)
		{
			max = array[i];
			position = i;
		}
	}

	maxL = StackSortMax(array, position );
	
	if(len-position-1 != 0)
	{
		int * arrayR = malloc(sizeof(int) * (len-position-1));
	
		for(i=position+1;i < len;i++)
		{
			arrayR[j] = array[i];
			j++;
		}
		minR = StackSortMin(arrayR, j);
		free(arrayR);
	}
	else
	{
		minR = max;
	}
	
	if(maxL < minR)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}
//returns max of the array
int StackSortMax(int * array, int len)
{
	int i;	
	int max = array[0];

	for(i=0;i < len;i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	
	return max;
}
//returns the min of the array
int StackSortMin(int * array, int len)
{
	int i;
	int min = array[0];

	for(i=0;i < len;i++)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
	}

	return min;
}	

/** * Generates (and prints) all the unique binary tree shapes of size k
 *
 * To do this, you must:
 * (1) Create an array with the elements [0..k-1] inclusive.
 * (2) Find all the permutations of this array.
 * (3) In the base-case of your permute function, you must test if the
 *     permutation is "stack-sortable"
 * (4) If the permutation is "stack-sortable", then build a binary
 *     tree, and print it using the "Tree_printShape(...)" function.
 *
 * Your genShapes() function must NOT produce duplicate tree shapes.
 * The correct outputs for sizes [1..9] are in the 'expected' 
 * directory.
 */
void genShapes(int k)
{

}




