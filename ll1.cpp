
#include <iostream>
using namespace std;
class linklist
{
     private:

	     struct node
	 {
	      int data;
	    node *link;
	 }*p;

   public:

	 linklist();
         void append( int num );
         void add_as_first( int num );
	 int addafter( int c, int num );
	 int del( int num );
         void display();
         int count();
         ~linklist();
};

linklist::linklist()
{
     p=NULL;
}

void linklist::append(int num)
{
     node *q,*t;

   if( p == NULL )
   {
        p = new node;
      p->data = num;
      p->link = NULL;
   }
   else
   {
        q = p;
      while( q->link != NULL )
           q = q->link;

      t = new node;
      t->data = num;
      t->link = NULL;
      q->link = t;
   }
}

void linklist::add_as_first(int num)
{
     node *q;

   q = new node;
   q->data = num;
   q->link = p;
   p = q;
}

int linklist::addafter( int c, int num)
{
     node *q,*t;
   int i;
   for(i=0,q=p;i<c;i++)
   {
	q = q->link;
      if( q == NULL )
      {
	   cout<<"\nThere are less than "<<c<<" elements.";
	 return 0;
      }
   }

   t = new node;
   t->data = num;
   t->link = q->link;
   q->link = t;
   return 1;
}

int linklist::del( int num )
{
     node *q,*r;
   q = p;
   if( q->data == num )
   {
	p = q->link;
      delete q;
      return 1;
   }

   r = q;
   while( q!=NULL )
   {
	if( q->data == num )
      {
	   r->link = q->link;
	 delete q;
	 return 1;
      }

      r = q;
      q = q->link;
   }
   cout<<"\nElement "<<num<<" not Found.";
   return 0;
}

void linklist::display()
{
     node *q;
   cout<<endl;

   for( q = p ; q != NULL ; q = q->link )
	cout<<endl<<q->data;

}

int linklist::count()
{
     node *q;
   int c=0;
   for( q=p ; q != NULL ; q = q->link )
	c++;

   return c;
}

linklist::~linklist()
{
     node *q;
   if( p == NULL )
	return;

   while( p != NULL )
   {
	q = p->link;
      delete p;
      p = q;
   }
}

int main()
{  char ch;
   linklist ll;
do{


   //cout<<"No. of elements = "<<ll.count();
   cout	<<"\n\tMENU"
	<<"\n1.Create a Linked List"
	<<"\n2.Add Element At Last"
	<<"\n3.Add Element At First"
	<<"\n4.Add Element in  Between"
	<<"\n5.Delete a Element"
	<<"\n6.Display the List"
	<<"\nPress 0(zero) to exit";
	cin>>ch;
	switch(ch)
	{
	case '1':       int N,V;
			cout<<"\nEnter the the Number of Elements you want to start with:";
			cin>>N;
			cout<<"\nNow Enter the Elements(Press Enter after Each entry):";
			for(int i=0;i<N;i++)
			   {	cin>>V;
				ll.append(V);
			   }
			cout<<"\nThe following List has been Created:\n";
			ll.display();
			break;
	case '2':
			cout<<"\nEnter the Element to be added at Last:";
			cin>>V;
			ll.append(V);
			cout<<"\nThe Element has been Added at Last";
			break;
	case '3':
			cout<<"\nEnter the Element to be added at First:";
			cin>>V;
			ll.add_as_first(V);
			cout<<"\nThe Element has been Added at First";
			break;
	case '4':       cout<<"\nEnter a Position after which you want to add(1,2,3....):";
			cin>>N;
			cout<<"\nEnter the Element:";
			cin>>V;
			if(ll.addafter(N-1,V))
			cout<<"\nElement is been added after "<<N<<"th Position";
			break;
	case '5':
			cout<<"\nEnter the Element to be Deleted:";
			cin>>V;
			if(ll.del(V))
			cout<<"Deleted";
			break;
	case '6':	cout<<"\nDisplaying Linked List:\n";
			ll.display();
			break;
	case '0':	return 0;
    }
   cout<<"\nDo You want to Continue?(Y/N):";
   cin>>ch;
   }while(ch=='y'||ch=='Y');
   return 0;
}











                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
