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
  size_t i, j;
  for (i=0; i<=dega; i++) c[i] = a[i];
  for (j=i; j<=degb; j++) c[j] = b[j];
  for (j=0; j<i && j<=degb; j++) c[j] += b[j];
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

/* This function tests the add_poly() function, it does this by 
   creating pairs of arrays holding polynomials, and running the 
   add_poly() function on these. Before each addition the two 
   polynomials are printed on the screen by a call to the 
   print_pol() function. After the addition of the two polynomials, 
   the result is printed on the screen together with the expected result.
   If the result computed by add_poly() didn't match the expected result, 
   then there's most likely a bug in the add_poly() function.
   
   NOTE:: This function is not C89 compliant.
*/
void test_add_poly(void)
{
  /* Assume two polynomials ``poly_a' and ``poly_b', then at
     least three cases have to be tested for addition:
     case 1: degree(poly_a) == degree(poly_b)
     case 2: degree(poly_a) <  degree(poly_b)
     case 3: degree(poly_a) >  degree(poly_b)
  */
  
  /* Testcase 1: degree(poly_a) == degree(poly_b) */
  int poly_a[] = {2, -3, 5};  /* +5X^2-3X+2 */
  int deg_a = (sizeof(poly_a) / sizeof(*poly_a)) - 1;
  
  int poly_b[] = {-1, 6, -9};  /* -9X^2+6X-1 */
  int deg_b = (sizeof(poly_b) / sizeof(*poly_b)) - 1;
  
  int poly_c[3];
  
  printf("\nTestcase 1: degree(poly_a) == degree(poly_b)\n");
  printf("poly_a: "); print_pol(poly_a, deg_a);
  printf("poly_b: "); print_pol(poly_b, deg_b);
  printf("poly_a + poly_b: ");
  
  add_poly(poly_a, deg_a, poly_b, deg_b, poly_c);
  print_pol(poly_c, 2);
  printf("Expected: -4X^2+3X+1\n");
  
  /* Testcase 2: degree(poly_d) <  degree(poly_e) */
  int poly_d[] = {-6, 0, 4};  /* +4X^2-6 */
  int deg_d = (sizeof(poly_d) / sizeof(*poly_d)) - 1;
  
  int poly_e[] = {1, 0, -2, 3};  /* +3X^3-2X^2+1 */
  int deg_e = (sizeof(poly_e) / sizeof(*poly_e)) - 1;
  
  int poly_f[4];
  
  printf("\nTestcase 2: degree(poly_d) <  degree(poly_e)\n");
  printf("poly_d: "); print_pol(poly_d, deg_d);
  printf("poly_e: "); print_pol(poly_e, deg_e);
  printf("poly_d + poly_e: ");
  
  add_poly(poly_d, deg_d, poly_e, deg_e, poly_f);
  print_pol(poly_f, 3);
  printf("Expected: +3X^3+2X^2-5\n");
  
  /* Testcase 3: degree(poly_g) >  degree(poly_h) */
  int poly_g[] = {-5, 3, -1, 7, -12};  /* -12X^4+7X^3-X^2+3X-5 */
  int deg_g = (sizeof(poly_g) / sizeof(*poly_g)) - 1;
  
  int poly_h[] = {0, -3, 5};  /* +5X^2-3X */
  int deg_h = (sizeof(poly_h) / sizeof(*poly_h)) - 1;
  
  int poly_i[5];
  
  printf("\nTestcase 3: degree(poly_g) >  degree(poly_h)\n");
  printf("poly_g: "); print_pol(poly_g, deg_g);
  printf("poly_h: "); print_pol(poly_h, deg_h);
  printf("poly_g + poly_h: ");
  
  add_poly(poly_g, deg_g, poly_h, deg_h, poly_i);
  print_pol(poly_i, 4);
  printf("Expected: -12X^4+7X^3+4X^2-5\n");
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
