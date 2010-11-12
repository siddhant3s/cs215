#include<stdio.h>
#include "bst.h"
int main()
{
  struct bst_tree *bst1=make_bst();
  
  do
    {
      printf("\n1. Create a binary search tree with initial elements\n"
	     "2. Search for an element in binary search tree\n"
	     "3. Insert an element in binary search tree\n"
	     "4. Delete an element in binary search tree\n"
	     "5. Display the binary search tree\n"
	     "6. Exit\n"
	     "Enter your Choice:");
      char ch;
      scanf("%c",&ch);
      switch(ch)
	{
	case '1':
	  {
	    size_t n;
	    printf("Enter the number of elements to start with: ");
	    scanf("%u",&n);
	    printf("Now enter the elements (separated by space):");
	    while(n--)
	      {
		int d;
		scanf("%i",&d);
		bst_insert(bst1,d);
	      }
	  }
	  break;
	case '2':
	  {
	    printf("Enter the element you need to search for:");
	    int d;
	    scanf("%i",&d);
	    if(bst_find (bst1,d))
	      printf("Item found.\n");
	    else
	      printf("Item not found.\n");
	  }
	  break;
	case '3':
	  {
	    printf("Enter an element to be inserted: ");
	    int d;
	    scanf("%i",&d);
	    bst_insert(bst1,d);
	    printf("Element inserted\n");
	  }
	  break;
	case '4':
	  {
	    printf("Enter an element to be removed: ");
	    int d;
	    scanf("%i",&d);
	    if(bst_remove(bst1,d))
	      printf("Element removed\n");
	    else
	      printf("Element Not removed. It might not be found in the tree.\n");
	  }
	  break;
	  
	case '5':
	  printf("Printing the Binary Search Tree\n");
	  bst_structure(bst1);
	  break;
	case '6':
	  free(bst1);
	  return 0;
	}
    }while(1);
  free(bst1);
  return 0;
}
		  
		
		
