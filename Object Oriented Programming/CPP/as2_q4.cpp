#include<iostream>

using namespace std;

//Class to define a node
class Node
{
	int value;
	int priority;
	Node* next;

public:
	Node(int v=0,int p=0)  //Constructor
	{
		value=v;
		priority=p;
		next=NULL;
	}
	void displayNode()  //Function to display a node
	{
		cout<<"Value: "<<value<<"\tPriority: "<<priority<<endl;
	}
	friend class priorityQueue;
};


class priorityQueue
{
	Node* head;

public:
	priorityQueue(){  //constructor
		head=NULL;
	}
	void enqueue(int v,int p){  //function to push an element
		Node* n;
		n=new Node;
		n->value=v;
		n->priority=p;
		//If head has lower priority
		if(head!=NULL)
		{
			if(head->priority<p)
			{
				n->next=head;
				head=n;
			}
			else
			{
				Node* temp=head;
				while((temp->next!=NULL) && (temp->next->priority)>=p)
				{
					temp=temp->next;
				}
				n->next=temp->next;
				temp->next=n;
			}
		}
		else
		{
			head=n;
		}

	}
	void dequeue(){  //Function to pop an element
		Node* temp=head;
		cout<<"Node being deleted is: ";
		temp->displayNode();
		head=head->next;
		delete temp;
	}
	int peek(){  //Function to see the head element
		return head->value;
	}
	void display(){
		Node* temp;
		temp=head;
		cout<<"--------------------------------------------------\n";
		while(temp!=NULL)
		{
			temp->displayNode();
			temp=temp->next;
		}
		cout<<"--------------------------------------------------\n";
	}
};

int main()
{
	int ch,c=0;
	int v,p;
	priorityQueue queue;
	do
	{
	    cout<<"\n---------------------------------------------------"<<endl;
		cout<<"1. Enter elements into priority queue"<<endl;
		cout<<"2. Pop element from the priority queue having highest priority"<<endl;
		cout<<"3. Print the current queue"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			cout<<"Enter a value and its priority"<<endl;
			cin>>v;
			cin>>p;
			c++;
			queue.enqueue(v,p);
			break;

			case 2:
			if(c==0)
			{
				cout<<"Queue empty"<<endl;
				break;
			}
			queue.dequeue();
			c--;
			break;

			case 3:
			if(c==0)
			{
				cout<<"Queue empty"<<endl;
				break;
			}
			queue.display();
			break;

			case 4:
			cout<<"Logged out."<<endl;
			break;

			default:
			cout<<"Invalid choice"<<endl;

		}

	}
	while(ch!=4);
	return 0;
}
