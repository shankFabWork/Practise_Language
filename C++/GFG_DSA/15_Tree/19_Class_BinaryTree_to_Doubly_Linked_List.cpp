#include <iostream> 
using namespace std; 

/* A binary tree Node  has data, and left and right pointers */
class Node  
{ 
    public:
        int data; 
        Node * left; 
        Node * right; 

        Node(int d)
        {
            data = d;
            left = right = NULL;
        }
}; 

void BinaryTree2DoubleLinkedList(Node* root, Node*& head) 
{ 
	// static can be put anywhere
	static Node * prev = NULL; 
	if (root == NULL)
    {
        return;
    }
	BinaryTree2DoubleLinkedList(root->left, head); 
	if(prev == NULL) 
    {
        head = root; 
    }
	else
	{ 
		// prev - root
		root->left = prev; 
		prev->right = root; 
	} 
	prev = root; 
	BinaryTree2DoubleLinkedList(root->right, head); 
} 

void printList(Node  *Node) 
{ 
	while (Node !=NULL) 
	{ 
		cout << Node ->data << " "; 
		Node  = Node ->right; 
	} 
} 

int main() 
{ 
	Node  *root	 = new Node(10); 
	root->left	 = new Node(12); 
	root->right	 = new Node(15); 
	root->left->left = new Node(25); 
	root->left->right = new Node(30); 
	root->right->left = new Node(36); 

	Node *head = NULL; 
	BinaryTree2DoubleLinkedList(root,head); 

	printList(head); 

	return 0; 
} 
