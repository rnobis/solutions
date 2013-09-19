/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */
void partitionAll(int value)
{
  void partitionAllHelper(int * part, int ind, int left);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionAll %d\n", value);
  
  partitionAllHelper(arr, 0, value);
  free (arr);
}
//Function to assist in partitioning an entered number, takes in an array to store the values
//the index, and the value to be partitioned
void partitionAllHelper(int * part, int ind, int left)
{
  void printPartition(int * part, int length);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 1; val <= left; val++)
    {
      part[ind] = val;
      partitionAllHelper(part, ind + 1, left - val);
    }
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */
void partitionIncreasing(int value)
{
  void partitionIncHelper(int * part, int ind, int left, int previous);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionIncreasing %d\n", value);
  
  partitionIncHelper(arr, 0, value, 0);
  free (arr);
}
//Function to assist in partitioning an entered number, takes in an array to store the values
//the index, and the value to be partitioned
void partitionIncHelper(int * part, int ind, int left, int previous)
{
  void printPartition(int * part, int length);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 1; val <= left; val++)
    {
      if (val > previous)
	{
	  part[ind] = val;
	  partitionIncHelper(part, ind + 1, left - val, val);
	}
    }
}
//Function to print the partition takes in length of array, and array itself
/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */
void partitionDecreasing(int value)
{
  void partitionDecHelper(int * part, int ind, int left, int previous);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionDecreasing %d\n", value);
  
  partitionDecHelper(arr, 0, value, value + 1);
  free (arr);
}
void partitionDecHelper(int * part, int ind, int left, int previous)
{
  void printPartition(int * part, int length);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 1; val <= left; val++)
    {
      if (val < previous)
	{
	  part[ind] = val;
	  partitionDecHelper(part, ind + 1, left - val, val);
	}
    }
}
/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partitionOdd(int value)
{
  void partitionOddHelper(int * part, int ind, int left);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionOdd %d\n", value);
  
  partitionOddHelper(arr, 0, value);
  free (arr);
}
//Function to assist in partitioning an entered number, takes in an array to store the values
//the index, and the value to be partitioned
void partitionOddHelper(int * part, int ind, int left)
{
  void printPartition(int * part, int length);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 1; val <= left; val++)
    {
      if ((val % 2) == 1)
	{
	  part[ind] = val;
	  partitionOddHelper(part, ind + 1, left - val);
	}
    }
}
/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partitionEven(int value)
{
  void partitionEvenHelper(int * part, int ind, int left);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionEven %d\n", value);
  
  partitionEvenHelper(arr, 0, value);
  free (arr);
}
//Function to assist in partitioning an entered number, takes in an array to store the values
//the index, and the value to be partitioned
void partitionEvenHelper(int * part, int ind, int left)
{
  void printPartition(int * part, int length);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 2; val <= left; val+=2)
    {
	  part[ind] = val;
	  partitionEvenHelper(part, ind + 1, left - val);
    }
}
/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partitionOddAndEven(int value)
{
  void partitionOddEvenHelper(int * part, int ind, int left);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionOddAndEven %d\n", value);
  
  partitionOddEvenHelper(arr, 0, value);
  free (arr); 
}
//Function to assist in partitioning an entered number, takes in an array to store the values
//the index, and the value to be partitioned
void partitionOddEvenHelper(int * part, int ind, int left)
{
  void printPartition(int * part, int length);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 1; val <= left; val++)
    {
      if((val % 2 == 0 && (ind % 2 == 1)) || ((val % 2 == 1) && (ind % 2 == 0)))
	{
	  part[ind] = val;
	  partitionOddEvenHelper(part, ind + 1, left - val);
	}
    }
}
/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partitionPrime(int value)
{  
  void partitionPrimeHelper(int * part, int ind, int left, int value);
  int * arr;

  arr = malloc(value * sizeof(int));
  
  printf("partitionPrime %d\n", value);
  
  partitionPrimeHelper(arr, 0, value, value);
  free (arr); 
}
//Function to assist in partitioning an entered number, takes in an array to store the values
//the index, and the value to be partitioned
void partitionPrimeHelper(int * part, int ind, int left, int value)
{
  void printPartition(int * part, int length);
  int primeChecker(int value);
  int val; //current value to store in the array
  
  if (left == 0)
    {
      printPartition(part, ind);
      return;
    }
  for (val = 1; val <= left; val++)
    {
      if(primeChecker(val) && val != 1)
	{
	  part[ind] = val;
	  partitionPrimeHelper(part, ind + 1, left - val, value);
	}
    }
}
//function to check if a value is prime
//returns 0 if it is, and 1 if it is not
int primeChecker(int value)
{
  int i;
  
  for (i = 2; i < value;i++)
    {
      if(value % i == 0)
	{
	  return 0;
	}
    }
  return 1;
}
//Function to print partition, takes in array of partion variables and length
void printPartition(int * part, int length)
{
  int ind; 

  printf("= ");

  for(ind = 0;ind < length - 1;ind++)
    {
      printf("%d + ", part[ind]);
    }

  printf("%d\n", part[length - 1]);
}
