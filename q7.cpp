#include <iostream>
using namespace std;
int queue[10];
void add(int &f,int &r)
{
    if (r==-1 && f==-1)
    {
        f=r=0;
        cout<<"\nEnter the element:";
        cin>>queue[r];
    }
    else
    {
        if (r==9)
            cout<<"\nQueue is full!";
        else
        {
            r++;
            cout<<"\nEnter the element:";
            cin>>queue[r];
        }
    }
    cout<<"\n";
}

void del(int &f,int &r)
{
    if (f==-1 && r==-1)
        cout<<"\nQueue is empty!";
    else
    {
        if (f==0 && r==0)
        {
            cout<<"\nDeleted element:"<<queue[f];
            f=r=-1;
        }
        else
        {
            if (f!=0 && r!=0 && f==r)
            {
                cout<<"\nDeleted element:"<<queue[f];
                f=r=-1;
            }
            else
            {
                cout<<"\nDeleted element:"<<queue[f];
                f++;
            }
        }
    }
    cout<<"\n";
}

void display(int &f,int &r)
{
    int i;
    if (r==-1 && f==-1)
        cout<<"\nQueue is empty!";
    else
    {
        if (f==0 && r==0)
            cout<<"\n"<<queue[r];
        if (f!=0 && r!=0 && f==r)
            cout<<"\n"<<queue[r];
        if (f!=r)
        {
            cout<<"\nQueue(Front...to...Rear)\n";
            for (i=f;i<r;i++)
                cout<<queue[i]<<" <- ";
            cout<<queue[r];
        }
    }
    cout<<"\n";
}

int main()
{
    int choice,front,rear;
    front=rear=-1;
    do
    {
        cout<<"\n***************QUEUE***************"
            <<"\n1.Add an element"
            <<"\n2.Delete an element"
            <<"\n3.Display the queue"
            <<"\n4.Exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            add(front,rear);
            break;
        case 2:
            del(front,rear);
            break;
        case 3:
            display(front,rear);
            break;
        default:
	  return 0;
        }
    }
    while (choice!=4);
   
}
