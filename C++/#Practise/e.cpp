#include<cstdlib>
#include <iostream>

using namespace std;

class Queue
{
    public:
    int Data;
    Queue* Next=NULL;
}*Front=NULL,*Rear=NULL;

class Stack
{
    public:
    int Data;
    Stack* Next=NULL;
    Stack* Top=NULL;
};
void EnQueue (int x )
{
    Queue* temp=new Queue;
    temp->Data=x;
    if (Rear == NULL )
    {
        Front=Rear=temp;
    }
    else
    {
        Rear->Next=temp;
        Rear=temp;
    }
}
int Dequeue ( )
{
    Queue* temp=Front;
    int Data=temp->Data;
    if (Front == Rear )
    {
        Front=Rear=NULL;
    }
    else
    {
        Front=Front->Next;
    }
    delete temp;
    return Data;
}
void Push (Stack& s,int x )
{
    Stack* temp=new Stack;
    temp->Data=x;
    if (s.Top == NULL )
    {
        s.Top=temp;
    }
    else
    {
        temp->Next=s.Top;
        s.Top=temp;
    }
}
int Pop (Stack& s )
{
    Stack* temp=s.Top;
    int Data=temp->Data;
    s.Top=s.Top->Next;
    delete temp;
    return Data;
}
void Display (Queue& que,Stack& S1,Stack& S2 )
{
	if (Rear!=NULL )
	{
		Queue* temp=Front;
		while (temp!=Rear )
		{
			cout<<temp->Data<<" ";
			temp=temp->Next;
		}
		cout<<temp->Data<<endl;
	}
	if (S1.Top!=NULL )
	{
		Stack* temp=S1.Top;
		while (temp!=NULL )
		{
			cout<<temp->Data<<" ";
			temp=temp->Next;
		}
		cout<<endl;
	}
	if (S2.Top!=NULL )
	{
		Stack* temp=S2.Top;
		while (temp!=NULL )
		{
			cout<<temp->Data<<" ";
			temp=temp->Next;
		}
		cout<<endl;
	}
}
int main ( ) 
{
    Queue que;
	int Counter;
    int N,i,j;
    Stack S1,S2;
    cin>>N;
    int arr[N];
    for (i=0;i<N;++i ) 
	{
		cin>>arr[i];
	}
	for (i=0;i<N;++i )
    {
        if ( (S1.Top == NULL ) || (arr[i]<S1.Top->Data ) )
        {
			Push (S1,arr[i] );
			Display (que,S1,S2 );
        }
		else if ( (S2.Top == NULL ) || (arr[i]>S2.Top->Data ) )
        {
        	Push (S2,arr[i] );
        	Display (que,S1,S2 );
        }
		else
        {
        	if (abs ( ( (S1.Top->Data )-arr[i] ) ) < abs ( ( (S2.Top->Data )-arr[i] ) ) )
        	{
        		Counter=0;
        		while ( (S1.Top!=NULL )&& (S1.Top->Data<=arr[i] ) )
        		{
        			EnQueue (Pop (S1 ) );
        			++Counter;
				}
				Push (S1,arr[i] );
				Display (que,S1,S2 );
				while (Counter )
				{
					j=Counter;
					while (--j )
					{
						EnQueue (Dequeue ( ) );
					}
					Push (S1,Dequeue ( ) );     
					--Counter;
				}
			}
			else
			{
				Counter=0;
        		while ( (S2.Top!=NULL )&& (S2.Top->Data>=arr[i] ) )
        		{
        			EnQueue (Pop (S2 ) );
        			++Counter;
				}
				Push (S2,arr[i] );
				Display (que,S1,S2 );
				while (Counter )
				{
					j=Counter;
					while (--j )
					{
						EnQueue (Dequeue ( ) );
					}
					Push (S2,Dequeue ( ) );
					--Counter;
				}
			}
		}
    }
    Stack s3;
    while (S2.Top!=NULL )
    {
    	Push (s3,Pop (S2 ) );
	}
	S2.Top=s3.Top;
	while (N-- )
	{
		if ( (S1.Top!=NULL )&& (S2.Top!=NULL )&& (S1.Top->Data<S2.Top->Data ) )
		{
			EnQueue (Pop (S1 ) );
			Display (que,S1,S2 );
		}
		else if ( (S1.Top!=NULL )&& (S2.Top!=NULL )&& (S1.Top->Data>S2.Top->Data ) )
		{
			EnQueue (Pop (S2 ) );
			Display (que,S1,S2 );
		}
		else if (S1.Top!=NULL )
		{
			EnQueue (Pop (S1 ) );
			Display (que,S1,S2 );
		}
		else
		{
			EnQueue (Pop (S2 ) );
			Display (que,S1,S2 );
		}
	}
	return 0;
}