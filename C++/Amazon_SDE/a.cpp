#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, * right;
};

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

Node* insertLevelOrder(int arr[], Node* root,
					int i, int n)
{
	if (i < n)
	{
		Node* temp = newNode(arr[i]);
		root = temp;

		root->left = insertLevelOrder(arr,
				root->left, 2 * i + 1, n);

		root->right = insertLevelOrder(arr,
				root->right, 2 * i + 2, n);
	}
	return root;
}

void preOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->data <<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	Node* root = insertLevelOrder(arr, root, 0, n);
	preOrder(root);
}

