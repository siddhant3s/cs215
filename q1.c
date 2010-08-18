/*
1. Suppose that an ordered list of numbers is implemented by means of an array, Write a C program using separate functions to 
   i.      Insert a number
   ii.     Delete an element
   iii.    Reverse the lis
*/
#include <stdio.h>

void array_print(int *a, size_t size)
{
  while(size--)
    printf("%i ",*a++);
}

int array_insert(int *a, size_t size, int element, size_t position)
/* Inserts the `element to the array `a', of size `size' in the `position'.
The `size' should be the size of the array upto which it was filled.
The function will check if the position specified is within the size specified.
Specifying the `position' as i will cause a[i] to have the value `element'.
It returns a positive integer if the insertion was successful else returns a false
with the error printed on stderr*/
{
  if (position >=size)
    {
      fprintf(stderr,"\narray_insert: The specified position %i is not less than the"
	      " size of the array which is %i\n",position,size);
      return 0;
    }
  int *p=a+position;//the pointer to the location where the new element will get inserted
  a=a+size;//a points to one past the last element of original array
  while(a!=p)
    *(a--)=*(a-1);
  *a=element;
  return 1;
}
int main()
{
  int a[10]={5,4,1,2,5};
  size_t s=(sizeof a)/(sizeof *a);
  //printf("Size:%i",s);
  array_print(a,s);
  array_insert(a,5,121,5);
  array_print(a,s);
  return 0;
}
