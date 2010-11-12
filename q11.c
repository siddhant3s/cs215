#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int key1, int key2);				/* swaps two array elements */
int partition( int A[], int left, int right);			/* partition an array such that: lower_part<= higher part. */
void quicksort( int A[], int left, int right);			/* uses partition to sort the array */

/*void print();							*//* auxiliary: to print the array */


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

void quicksort( int A[], int left, int right){
  int m;
  if( left < right ) {					// make sure that we are trying to sort a subarray
    m = partition( A, left, right);			// divide and conquer
    quicksort( A, left, m-1);			// sort both subarrays
    quicksort( A, m+1, right);
  }	
}

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
  

  quicksort( A, 0, ARRAY_SIZE - 1);

  printf("\n\nSorted array is:  ");
  for(i = 0; i < ARRAY_SIZE; ++i)
    printf(" %d ", A[i]);
  printf("\n");
}
/*
void print(int A[]){
  int i;
  for(i = 0; i < ARRAY_SIZE; ++i)
    printf(" %d ", A[i]);
  printf("\n");
}
*/
