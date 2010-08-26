/*
3. Write a C program for 
i. Adding two polynomials where a polynomial is implemented by an array of records.
ii. Multiplying two polynomials where a polynomial is implemented by an array of records.
*/
#include <stdio.h>

/*The Polynomial is represented by an array of its coefficients on the respective
Position of the exponent:
Say we have a Polynomial P(x): 14x^3 + 62x^2 + 41x + 79
It should be represented in the array as 
       +----+----+----+----+
       |  0 |  1 |  2 |  3 | <---Array Subscript
       |--------------------
       | 79 | 41 | 62 | 14 | <---Coefficients
       +-------------------+
*/

void add_poly(int *a, size_t dega, int *b, size_t degb, int *c)
{
  size_t maxdeg,mindeg,i;
  int *maxpol,*minpol;
  if(dega>degb)
    {
      maxdeg=dega; mindeg=degb;
      maxpol=a;    minpol=b;
    }
  else
    {
      maxdeg=degb; mindeg=dega;
      maxpol=b;    minpol=b;
    }
  
  for(i=0; i <= mindeg ; i++)
    c[i]=a[i]+b[i];
  for(; i <= maxdeg ; i++)
    c[i]=maxpol[i];
}

void mul_poly(int *a, size_t dega, int *b, size_t degb, int *c)
{
  size_t i;
  for(i=0; i<=(dega+degb) ; i++)
    c[i]=0;
  
  for(i=0; i <= dega; i++)
    {
      size_t j;
      for(j=0; j<= degb; j++)
        {
          c[i+j]+=a[i]*a[j];
        }
    }
}

void print_pol(int *a, size_t deg)
{
  for (;; deg--)
  {
    if (!a[deg])             /* coefficient is zero,   */
      if (deg) continue;     /* nothing to be printed  */
      else break;
    
    /* print coefficient */
    if (deg != 0 && (a[deg] == -1 || a[deg] == 1))
      printf("%c", (a[deg] < 0 ? '-':'+'));
    else
      printf("%+d", a[deg]);
    
    if (deg != 0)   /* print variable? */
    {
      printf("X");
      
      if (deg != 1) /* print exponent? */
        printf("^%d", deg);
    }
    else    /* last term of polynomial */
      break;
  }
  
  printf("\n");
}

/* This function tests the print_pol() function, it does this by
   creating arrays holding polynomials, and running the print_pol()
   function on those arrays. After each call to print_pol(), the 
   expected result is printed. If the output from print_pol() didn't 
   match, then print_pol() doesn't work as desired.
*/
void test_print_pol(void)
{
  int test_case_0[] = {0, -8}; /* -8X */
  size_t deg0 = (sizeof(test_case_0) / sizeof(*test_case_0)) - 1;
  
  int test_case_1[] = {-8, -1}; /* -X-8 */
  size_t deg1 = (sizeof(test_case_1) / sizeof(*test_case_1)) - 1;
  
  int test_case_2[] = {-1, 0}; /* -1 */
  size_t deg2 = (sizeof(test_case_2) / sizeof(*test_case_2)) - 1;
  
  int test_case_3[] = {8, 1}; /* +X+8 */
  size_t deg3 = (sizeof(test_case_3) / sizeof(*test_case_3)) - 1;
  
  int test_case_4[] = {1, 8}; /* +8X+1 */
  size_t deg4 = (sizeof(test_case_4) / sizeof(*test_case_4)) - 1;
  
  int test_case_5[] = {5, -3, 9}; /* +9X^2-3X+5 */
  size_t deg5 = (sizeof(test_case_5) / sizeof(*test_case_5)) - 1;
  
  print_pol(test_case_0, deg0);
  printf("Expected: -8X\n");
  
  print_pol(test_case_1, deg1);
  printf("Expected: -X-8\n");
  
  print_pol(test_case_2, deg2);
  printf("Expected: -1\n");
  
  print_pol(test_case_3, deg3);
  printf("Expected: +X+8\n");
  
  print_pol(test_case_4, deg4);
  printf("Expected: +8X+1\n");
  
  print_pol(test_case_5, deg5);
  printf("Expected: +9X^2-3X+5\n");
}

int main(void)
{
  int pol1[]={1,1,2};
  size_t deg1=((sizeof pol1)/sizeof(*pol1))-1;

  int pol2[]={1,1};
  size_t deg2=((sizeof pol2)/sizeof(*pol2))-1;
  int pol3[7];
  add_poly(pol1,deg1,pol2,deg2,pol3);
  print_pol(pol3,2);

  mul_poly(pol1,deg1,pol2,deg2,pol3);
  print_pol(pol3,deg1+deg2);
  return 0;
}
