#include<iostream>
#include<string>
const int MAX_SIZE=20;

class Stack
{
  int data[MAX_SIZE];
  unsigned int top;
 public:
  void push(int);
  int pop();
  int peek();
  int isfull();
  int isempty();
  void display();
  Stack()
  {
    top=0;
  }
};

int Stack::isfull()
{
  if (top<MAX_SIZE) return 0;
  return 1;
}
int Stack::isempty()
{
  if (top==0) return 1;
  return 0;
}
void Stack::push(int d)
{
  if (!isfull())
    data[top++]=d;
  else{
    std::cout<<"Stack is FULL\n";
  }
}
int Stack::pop()
{
  if(!isempty())
    return data[--top];
  else{
    std::cout<<"Stack is Empty\n";
    return -1;
  }
}
void Stack::display()
{
  for(int i=0;i<top;++i)
    std::cout<<data[i]<< ' ';
}
int Stack::peek()
{
  if(!isempty())
    return data[top-1];
  else
    std::cout<<"Stack is Empty\n";
}

int main()
{
  Stack s;
  do
    {
      std::cout<<"Static Stack Implementation. Maximum stack size is "<<MAX_SIZE<<std::endl;
      std::cout<<				\
	"Menu\n"
	"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit";
      int opt;
      std::cin>>opt;
      switch(opt)
	{
	case 1:
	  std::cout<<"Enter an element to push: ";
	  int e;
	  std::cin>>e;
	  s.push(e);
	  break;
	case 2:
	  std::cout<<"The poped element is:"<<s.pop();break;
	case 3:
	  std::cout<<"The Peeked elementis:"<<s.peek();break;
	case 4:
	  std::cout<<std::endl;
	  s.display();
	  break;
	case 5: return 0;
	default:
	  std::cout<<"Enter a valid input\n";
	}
    }while(1);
}
