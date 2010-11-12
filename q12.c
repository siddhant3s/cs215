#include <stdio.h>
void heapSort(int [], int);
void siftDown(int [], int, int);
int main()
{
  const int MAX=20;
  int a[MAX];
  /* int a[]={5,1,4,88,82,1,42,1,4,5,14,74,5,4,48}; */
  /* size_t size=(sizeof a)/(sizeof *a); */
  printf("How many elements? (MAX: %i)",MAX);
  size_t size;
  scanf("%i",&size);
  int i; 
  printf("Enter the Elements:\n");
  for (i=0; i<size; ++i)
    scanf("%i",a+i);
  
  heapSort(a,size);

  for(i=0; i<size; ++i)
    printf("[%i]",a[i]);
  printf("\n");
  return 0;
}

void heapSort(int numbers[], int array_size)
{
  int i, temp;

  for (i = (array_size / 2)-1; i >= 0; i--)
    siftDown(numbers, i, array_size);

  for (i = array_size-1; i >= 1; i--)
    {
      temp = numbers[0];
      numbers[0] = numbers[i];
      numbers[i] = temp;
      siftDown(numbers, 0, i-1);
    }
}


void siftDown(int numbers[], int root, int bottom)
{
  int done, maxChild, temp;

  done = 0;
  while ((root*2 <= bottom) && (!done))
    {
      if (root*2 == bottom)
	maxChild = root * 2;
      else if (numbers[root * 2] > numbers[root * 2 + 1])
	maxChild = root * 2;
      else
	maxChild = root * 2 + 1;

      if (numbers[root] < numbers[maxChild])
        {
          temp = numbers[root];
          numbers[root] = numbers[maxChild];
          numbers[maxChild] = temp;
          root = maxChild;
        }
      else
	done = 1;
    }
}

