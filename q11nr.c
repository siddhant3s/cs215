#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void swap(int A[], int key1, int key2);				/* swaps two array elements */
int partition( int A[], int left, int right);			/* partition an array such that: lower_part<= higher part. */
void quicksort_nr( int A[], int left, int right);			/* uses partition to sort the array */

const int MAX=20;
size_t ARRAY_SIZE;

int main() {  
  int A[MAX];

  printf("How many elements? (MAX: %i)",MAX);

  scanf("%i",&ARRAY_SIZE);
  int i; 
  printf("Enter the Elements:\n");
  for (i=0; i<ARRAY_SIZE; ++i)
    scanf("%i",A+i);
  
  quicksort_nr( A, 0, ARRAY_SIZE - 1);

  printf("\n\nSorted array is:  ");
  for(i = 0; i < ARRAY_SIZE; ++i)
    printf(" %d ", A[i]);
  printf("\n");
}

void swap(int A[], int key1, int key2){
  int tmp; 
  tmp = A[key2];
  A[key2] = A[key1];
  A[key1] = tmp;	
}

int partition( int A[], int left, int right) {
  int pivot; 
  pivot = A[right];									
  while(1){
    while( A[right] > pivot){			// while the elements starting from right are > than the last element
      right--;				// divide the problem
    }
    while( A[left] < pivot){			// while the elements starting from left are < than the last element
      left++;					// divide the problem (A[] considered becomes smaller)
    }
    if( left < right ){								
      swap(A,left,right);			// swap the elements OR
    }else{
      return left;				// return a new left "pointer" 							
    }
  }
}
void quicksort_nr(int A[], int l, int r) 
{ 
  struct Stack* S = stack_new();
  stack_push(S,l); stack_push(S,r); 
  while (!stack_empty(S)) 
    { 
      r = stack_pop(S); l = stack_pop(S); 
      if (r <= l) continue; 
      int i = partition(A, l, r); 
      if (i-l > r-i) { stack_push(S,l); stack_push(S,i-1); } 
      stack_push(S,i+1); stack_push(S,r); 
      if (r-i >= i-l) { stack_push(S,l); stack_push(S,i-1); } 
    } 
  free(S);
}  
