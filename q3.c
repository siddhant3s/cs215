/*
3. Write a C program for 
i. Adding two polynomials where a polynomial is implemented by an array of records.
ii. Multiplying two polynomials where a polynomial is implemented by an array of records.
*/
#include <stdio.h>

/*The Polynomial is represented by an array of its cofficient on the respective
Position of the exponent:
Say we have a Polynomial P(x): 14x^3 + 62x^2 + 41x + 79
It should be represented in the array as 
       +----+----+----+----+
       |  0 |  1 |  2 |  3 | <---Array Subscript
       |--------------------
       | 79 | 41 | 62 | 14 | <---Coffecients
       +-------------------+
*/

void add_poly(int *a, size_t dega, int *b, size_t degb, int *c)
{
  size_t maxdeg,mindeg;
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
  
  size_t i;
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
  while(1)
    {
      printf(" +%iX^%i",a[deg],deg);
      if(deg) deg--;/*TODO: ADD COMMENT*/
      else
      {
	break;
      }
    }
  printf("\n");
}

	
int main()
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
