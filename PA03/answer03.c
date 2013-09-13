
#include "pa03.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numberOfIntegers: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek".
 * 
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * The allocated memory will be released in pa03.c. You do not need to
 * worry about releasing memory.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readIntegers(const char * filename, int * numberOfIntegers)
{
  FILE * fptr;      //creates file pointer variable
  int * arr;        //creates array
  int counter = 0;  //counter for counting elements in the array
  int val;          //temp variable for storing values of array elements
  int i = 0;        //counter for cycling through array elements
  
  fptr = fopen(filename, "r");
  
  if (fptr == NULL)
    {
      return NULL;
    }
  
  while(fscanf(fptr, "%d", &val) == 1)
    {
      counter++;
    }
  
  * numberOfIntegers = counter;
  arr = malloc(counter * sizeof(int));
  
  fseek(fptr, 0, SEEK_SET);
  
  while(fscanf(fptr, "%d", & val) == 1)
    {
      arr[i] = val;
      i++;
    }
  
  fclose(fptr);
  return arr;
}

/**
 * Sort an (ascending) array of integers
 *
 * Arguments:
 * arr    The array to search
 * length Number of elements in the array
 *
 * Uses "quicksort" to sort "arr".  Use the first element of the array
 * as the pivot.  
 *
 * Your solution MUST use recursive function (or functions)
 * 
 * quicksort works in the following way: 
 * 
 * find an element in the array (this element is called the
 * pivot). 
 *
 * rearrange the array's elements into two parts: the part smaller
 * than this pivot and the part greater than this pivot; make the pivot
 * the element between these two parts
 * 
 * sort the first and the second parts separately by repeating the 
 * procedure described above
 * 
 * You will receive no point if you use any other sorting algorithm.
 * You cannot use selection sort, merge sort, or bubble sort.
 * 
 * Some students are fascinated by the name of bubble sort.  In
 * reality, bubble sort is rarely used because it is slow.  It is a
 * mystery why some students (or even professors) like bubble sort.
 * Other than the funny name, bubble sort has nothing special and is
 * inefficient, in both asymptotic complexity and the amount of data
 * movement.  There are many algorithms much better than bubble sort.
 * You would not lose anything if you do not know (or forget) bubble
 * sort.
 *
 */
void sort(int * arr, int length)
{
  //adds "first" variable to function to allow simpler recursion using divide and conquer
  void quicksort(int * arr, int first, int last);
  
  quicksort(arr, 0, length - 1);
}
/**
 *This function performs the quicksort algorithm. The pivot is set to
 *be the first value. The counters are then set to be the beginning,
 *and end of array.
 *The values begin counting up and down, until their conditions are met
 *(i.e. a value smaller and larger than the pivot are found before
 * the counters meet) and these values are swapped.
 *
 *Once i and j meet, the value at the pivot is swapped with the value at j.
 *
 *Then, the quicksort function is ran again, using the values higher and
 *smaller than the array, as two smaller arrays.
 *This runs recursively, until the entire array is sorted.
 **/
void quicksort(int * arr, int first, int last)
{
  int i;       //variable to store counter for shifting from the left
  int j;       //variable to store counter for shifting from the right
  int pivot;   //variable for the pivot to quicksort around
  int temp;    //temporary variable to swap array values

  if (first < last)
    {
      pivot = first;
      i = first;
      j = last;

      while(i < j)
	{
	  while(arr[i] <= arr[pivot] && i < last)
	    {
	      i++;
	    }
	  while(arr[j] > arr[pivot])
	    {
	      j--;
	    }
	  if(i < j)
	    {
	      temp = arr[i];
	      arr[i] = arr[j];
	      arr[j] = temp; 
	    }
	}
      temp = arr[pivot];
      arr[pivot] = arr[j];
      arr[j] = temp;
      quicksort(arr, first, j - 1);
      quicksort(arr, j + 1, last);
   }
}
/**
 * Use binary search to find 'key' in a sorted array of integers
 *
 * Arguments:
 * 
 * arr The array to search. Must be sorted ascending.  You do not need
 *        to check. This array is from the result of your sort
 *        function. Make sure your sort function is correct before you
 *        start writing this function.
 *
 * length Number of elements in the array
 * key    Value to search for in arr
 *
 * Returns:
 * The index of 'key', or -1 if key is not found.
 *
 * Since the array is sorted, you can quickly discard many elements by
 * comparing the key and the element at the center of the array. If
 * the key is the same as this element, you have found the index.  If
 * the key is greater than this element, you can discard the first
 * half of the array.  If the key is smaller, you can discard the
 * second half of the array.  Now you have only half of the array to
 * search.  Continue this procedure until either you find the index or
 * it is impossible to find a match.
 * 
 * Your solution MUST use recursive function (or functions)
 *
 * Don't forget that arrays are 'zero-indexed'. Also, you must
 * use a binary search to pass this question.
 * 
 * You will receive no point if you do the following because it is not
 * binary search.  This is called linear search because it checks
 * every element.
 *
 * int ind;
 * for (ind = 0; ind < length; ind ++)
 * {
 *    if (arr[ind] == key)
 *    {
 *       return ind;
 *    }
 * }
 * return -1;
 */
int search(int * arr, int length, int key)
{
  //fucntion to help perform binary search recursively
  int searchhelper(int * arr, int low, int high, int key);
  
  return searchhelper(arr, 0, length - 1, key);
}
/**
 *This function takes the value of the where in the arry to start searching,
 *where in the array to stop searching, the array itself, and the key.
 *
 *Using these values, the binary search is performed, and a -1 is returned
 *if there is an error (i.e. low > high)
 *If the key turns out to be the middle of the array, then that value is 
 *returned directly.
 *
 *Otherwise, if the value of the key is greater than the location, then
 *the array is recentered with that as the starting point, and the 
 *end of the array as the end.
 *
 *If the key is less than the value, the beginning of the array remains
 *unchanged, and that point is now the end of the searching area.
 *
 *Using recursion the searching area continues to shring until the value
 *is found.
 **/ 
int searchhelper(int * arr, int low, int high, int key)
{
  if(low > high)
    {
      return -1;
    }

  int ind = (low + high) / 2;

  if (arr[ind] == key)
    {
      return ind;
    }
  if (arr[ind] > key)
    {
      return searchhelper(arr, low, ind - 1, key);
    }

  return searchhelper(arr, ind + 1, high, key);
}


