/*
4. Write a C program for
   i.    Adding two sparse matrices and transposing a sparse matrix where a sparse matrix is implemented by an array of records.
*/
#include <stdio.h>

struct SparseNode
{
  int data;
  size_t x;
  size_t y;
};

/*
A sparse matrix is represented as an array with all the Non-zero listed. Each element of
the array is basically a SparseNode which contains the actual data and the position of the
element as x and y.

|---------------------------------+-----+-----+-----+------+-----+-----+-----|
| Position in the Sparse Array => |   0 |   1 |   2 |    3 |   4 |   5 |   6 |
|---------------------------------+-----+-----+-----+------+-----+-----+-----|
| The actual data in the Matrix   | 845 | 475 | 486 | 1475 | 518 | 654 | 843 |
|---------------------------------+-----+-----+-----+------+-----+-----+-----|
| X Position of the Data          |   0 |   2 |   4 |    3 |   2 |   1 |   3 |
|---------------------------------+-----+-----+-----+------+-----+-----+-----|
| Y Position of the Data          |   2 |   5 |   4 |    2 |   6 |   2 |   7 |
|---------------------------------+-----+-----+-----+------+-----+-----+-----|
Above is the Array representation of a sparse Matrix containing 7 non-zero elements
*/
struct SparseNode* sparse_node_at_xy(struct SparseNode A[], size_t size, size_t x, size_t y)
{
  size_t i;
  for (i=0; i < size; i++)
    if( A[i].x==x && A[i].y==y)
      return A+i;
  return NULL;
}
size_t sparse_add(struct SparseNode A[], size_t sizeA, struct SparseNode B[], size_t sizeB, struct SparseNode result[])
{
  /* result[] is assumed to have a length at least sizeA+sizeB */
  size_t i;
  for (i=0; i< sizeA; i++)
    result[i]=A[i];
  size_t j, sizeC=sizeA;
  for (j=0; j < sizeB; j++)
    {
      struct SparseNode* currentnode= sparse_node_at_xy(result, sizeA, B[j].x, B[j].y);
      if (currentnode)
	currentnode->data += B[j].data;
      else
	{
	  result[i+j]=B[j];
	  sizeC++;
	}
    }
  return sizeC;
}
void sparse_transpose(struct SparseNode A[], size_t size)
{
  while(size--)
    {
      size_t t= A[size].x;
      A[size].x=A[size].y;
      A[size].y=t;
    }
}
size_t sparse_input(struct SparseNode A[], size_t max)
{

  size_t size;
  printf("Enter the number of non-zero elements (Maximum non zero elements must not exceed %i)",max);
  scanf("%u",&size);
  //  printf("You entered a size %u",size);
  if(size>max)
    {
      fprintf(stderr,"ERROR. The number of non-zero element exceeded %u. Can't input.",max);
      return 0;
    }
      
  size_t i;
  for(i=0; i < size; i++)
    {
      size_t x,y;
      int data;
      printf("Enter the Data:");
      scanf(" %i", &data);
      //  printf("You entered %i\n",data);
      printf("Enter its position in Matrix as x and y (zero-based) separated by space");
      scanf("%u%u",&x,&y);
      struct SparseNode node={data,x,y};
      A[i]=node;
    }
  return i;
}
void sparse_output(struct SparseNode A[],size_t size, size_t x, size_t y)
{
  size_t i;
  for(i=0; i<x; i++)
    {
      size_t j;
      for( j=0; j<y ;j++)
	{
	  struct SparseNode *node=sparse_node_at_xy(A,x*y,i,j);
	  printf("%i\t",  (node!=NULL)? node->data : 0);
	}
      printf("\n");
    }
}
void sparse_dump(struct SparseNode A[], size_t size)
{
  size_t i;
  for(i=0; i<size; i++)
    printf("%u[%i,%u,%u]--",i,A[i].data,A[i].x,A[i].y);
}
int main()
{
  const MAX = 50;
  struct SparseNode A[MAX],B[MAX],C[2*MAX];
  size_t sizeA=0,sizeB=0,sizeC=0;
  printf("This program implements Addition and transposition of Sparse Matrix\n");
  do
    {
      printf("Please choose one of the following operations:\n"
	     "1. Enter the Sparse Matrix A (Maximum non zero elements must not exceed %i\n"
	     "2. Enter the Sparse Matrix B (Maximum non zero elements must not exceed %i\n"
	     "3. Add Sparse Matrix A and B to C\n"
	     "4. Transpose Matrix A, B or C\n"
	     "5. Display Matrix A, B and C as Two dimensional figure\n"
	     "6. Exit\n"
	     "Enter an option:", MAX, MAX);
      char ch;
      ch=getchar();
      switch(ch)
	{
	case '1':
	  sizeA=sparse_input(A,MAX);
	  break;
	case '2':
	  sizeB=sparse_input(B,MAX);
	  break;
	case '3':
	  sizeC=sparse_add(A,sizeA, B,sizeB, C); 
	  printf("Added Matrix A and B to C");
	  break;
	case '4':
	  printf("Which Sparse Martix do you want to transpose? Enter A, B or C : ");
	  scanf(" %c",&ch);
	  switch(ch)
	    {
	    case 'A':  sparse_transpose(A,sizeA); break;
	    case 'B':  sparse_transpose(B,sizeB); break;
	    case 'C':  sparse_transpose(C,sizeC); break;
	    default : printf("There is no such Matrix as %c. Matrix Names are case-sensitive. Transpose not done.",ch);
	    } 
	  break;
	case '5':
	  {
	    size_t xassume,yassume;
	    printf("Enter the Dimension of matrix which needs to be assumed while displaying, separented by a space:");
	    scanf("%u%u", &xassume, &yassume);

	    printf("\nPrinting A:\n");
	    sparse_output(A,sizeA,xassume, yassume);
	    //sparse_dump(A,sizeA);
	    printf("\nPrinting B:\n");
	    sparse_output(B,sizeB,xassume, yassume);
	    //sparse_dump(B,sizeB);
	    printf("\nPrinting C:\n");
	    sparse_output(C,sizeC,xassume, yassume);
	    //sparse_dump(C,sizeC);
	  }
	  break;
	case '6':
	  return 0;
	default :
	  printf("Wrong Choice! Try Again\n");
	}
    }while(1);
  return 0;
}
