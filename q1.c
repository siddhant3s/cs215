/*
1. Suppose that an ordered list of numbers is implemented by means of an array, Write a C program using separate functions to 
   i.      Insert a number
   ii.     Delete an element
   iii.    Reverse the list
*/
#include <stdio.h>

void array_print(int *a, size_t size)
{
  while(size--)
    printf("%i ",*a++);
}

int array_insert(int *a, size_t size, int element, size_t position)
/* Inserts the `element' to the array `a'.The`size' denotes the number of current elements in the array. The `element' is inserted at a[position].
The `size' should not be the size of the array allocated.
The function will check if the position specified is within the size specified.
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
  a+=size;//a points to one past the last element of original array
  while(a>p)    *(a)=*(a-1),a--;
  *a=element;
  return 1;
}

int array_delete(int *a, size_t size, size_t position)
/*Removes the element a[position] from the array. The `size' denotes the  number of
  elements in the array before the removal. Returned zero if the deletion failed
else returns a positive integer.*/
{
  if (position >=size)
    {
      fprintf(stderr,"\narray_delete: The specified position %i is not less than the"
	      " size of the array which is %i\n",position,size);
      return 0;
    }
  int *last=a+size-1;// points to the last element
  a+=position;//a now points to the position of the deltetion
  while(a<last) *(a)=*(a+1),a++;
  return 1;
}

void array_reverse(int *a, size_t size)
/* Reverses the array `a'. The `size' represents the number of elements in `a'*/
{
  int i,t;
  for(i=0; i < size/2 ; i++)
    {
      t=a[i]; a[i]=a[size-i-1]; a[size-i-1]=t;
    }
}


int main()
{
  int a[10]={5,4,1,2,5};
  size_t s=(sizeof a)/(sizeof *a);
  //printf("Size:%i",s);
  array_print(a,s);
  array_insert(a,5,7,3);
  printf("\n");array_print(a,s);
  array_delete(a,6,2);
  printf("\n");array_print(a,s);
  array_reverse(a,5);
  printf("\n");array_print(a,s);
  
  return 0;
}
