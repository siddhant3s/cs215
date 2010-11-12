#include <stdio.h>
#include <stdlib.h>
void merge ( int a[], int first, int mid, int last )
{
  int i = first, j = mid, k = 0;
  int *save = malloc ( ( last - first ) * sizeof *save );
  
  while ( i < mid && j < last ) {
    if ( a[i] <= a[j] )
      save[k++] = a[i++];
    else
      save[k++] = a[j++];
  }
 
  while ( i < mid )
    save[k++] = a[i++];
 
  while ( j < last )
    save[k++] = a[j++];
 
  for ( i = 0; i < ( last - first ); i++ )
    a[first + i] = save[i];
 
  free ( save );
}
void mergesort_r ( int a[], int first, int last )
{
  if ( first < last - 1 ) {
    int mid = ( first + last ) / 2;
    mergesort_r ( a, first, mid );
    mergesort_r ( a, mid, last );
    merge ( a, first, mid, last );
  }
}
 
void mergesort ( int a[], int n )
{
  mergesort_r ( a, 0, n );
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
  

  mergesort( A, ARRAY_SIZE );

  printf("\n\nSorted array is:  ");
  for(i = 0; i < ARRAY_SIZE; ++i)
    printf(" %d ", A[i]);
  printf("\n");
}
