#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;
Node* tail;


void enqueue(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head == NULL && tail == NULL)
	{
		head = tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void dequeue()
{
	if(head == NULL && tail == NULL)
		return;

	Node* temp = head;
	head = head->next;
	delete temp;
}

void printQueue()
{
	Node* temp = head;
	while(temp != NULL)
	{
	 	cout<<temp->data<<endl;
	 	temp = temp->next;
	}
	
	
}
void peekHead()
{
	cout<<head->data<<endl;
}

void peekTail()
{
	cout<<tail->data<<endl;
}
int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	printQueue();
	cout<<"------------x-------------------"<<endl;
	dequeue();
	dequeue();
	dequeue();
	printQueue();
	cout<<"------------x-------------------"<<endl;
	peekHead();
	peekTail();
}
