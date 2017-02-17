#include<iostream>
#include<typeinfo>
using namespace std;

struct Node 
{
	char data;
	Node* next;
};

Node* head;

void pop()
{
	if(head == NULL)
		return;
	
	Node* temp = head;
	head = head->next;
	delete temp;
	
}

char top()
{
	return head->data;
}
void push(char data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void printStack()
{
	if(head == NULL)
		cout<<"The stack is empty"<<endl;
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
bool isempty()
{
	if (head != NULL)
		return false;
	return true;
}

bool check_valid(char data)
{
	switch(data)
	{
		case '}':
			if(top() == '{')
			return true;
			else return false;
		case ')':
			if(top() == '(')
			return true;
			else return false;
		case ']':
			if(top() == '[')
			return true;
			else return false;
		default:
			return false;
	}
	
	
}

int main()
{
	string expression;
	cout<<"Please input a parenthesis expression"<<endl;
	getline(cin,expression);
	
	
	for(int i = 0;i<expression.length();i++)
	{
		if(expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
			push(expression[i]);
		if(expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
		{
			if(isempty() || !check_valid(expression[i]))
				return false;
			else
			{
			pop();
			}
		}
	}
	
	if(isempty())
		cout<<"The expression is valid"<<endl;
	else 
		cout<<"The expression is invalid"<<endl;

}
