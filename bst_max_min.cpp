#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node* right;
	Node* left;
};

Node* root = NULL;

Node* getNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

Node* insertNode(Node* root, int data)
{
	if (root == NULL)
		{
			root = getNewNode(data);
		}
	else if(data <= root->data)
		{
			root->left = insertNode(root->left,data);
		}
	else	{
			root->right = insertNode(root->right,data);
		}
	return root;
}

int min(Node* root)
{
	if(root->left == NULL)
		return root->data;
	else
		min(root->left);
}

int max(Node* root)
{
	if(root->right == NULL)
		return root->data;
	else
		return max(root->right);
}

int main()
{
	root = insertNode(root,55);
	root = insertNode(root,23);
	root = insertNode(root,100);
	root = insertNode(root,5);
	root = insertNode(root,1);
	root = insertNode(root,6);
	root = insertNode(root,50);
	root = insertNode(root,44444);
	cout<<min(root)<<endl;
	cout<<max(root)<<endl;
	
}
