/* PROGRAM TO CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION USING STACK */
#include<stdio.h>
#include<string.h>

/* MACRO FUNCTION TO CHECK WHETHER GIVEN CHARACTER IS AN OPERAND OR NOT */
#define operand(x) (x>='a' && x<='z' || x>='A' && x<='Z' || x>='0' && x<='9')
char infix[30],postfix[30],stack[30];
int top,i=0;

/* FUNCTION TO INITIALIZE THE STACK */
void init()
{
  top=-1;
}

/* FUNCTION TO PUSH AN OPERATOR ON TO THE STACK */
void push(char x)
{
  stack[++top]=x;
}

/* FUNCTION TO POP A CHARACTER STORED ONTO THE STACK */
char pop()
{
  return(stack[top--]);
}

/* FUNCTION TO RETURN IN STACK PRIORITY OF A CHARACTER */
int isp(char x)
{
  int y;
  y=(x=='('?0:x=='^'?4:x=='*'?2:x=='/'?2:x=='+'?1:x=='-'?1:x==')'?6:-1);
  return y;
}

/* FUNCTION TO RETURN INCOMING CHARACTER'S PRIORITY */
int icp(char x)
{
  int y;
  y=(x=='('?4:x=='^'?4:x=='*'?2:x=='/'?2:x=='+'?1:x=='-'?1:x==')'?6:-1);
  return y;
}

/* FUNCTION TO CONVERT THE GIVEN INFIX TO PREFIX EXPRESSION */
void infixtopostfix()
{
  int j,l=0;
  char x,y;
  stack[++top]='\0';
  for (j=0; (x=infix[i++])!='\0'; j--)
    if (operand(x))
      postfix[l++]=x;
    else
      if (x==')')
	while ((y=pop())!='(')
	  postfix[l++]=y;
      else
	{
	  while (isp(stack[top])>=icp(x))
	    postfix[l++]=pop();
	  push(x);
	}
  while (top>=0)
    postfix[l++]=pop();
}

/* MAIN PROGRAM */
int main()
{
  init();
  printf("Enter an infix expression :\n");
  scanf("%s",infix);
  infixtopostfix();
  printf("The resulting postfix expression is %s",postfix);
  return 0;
} // End of main
