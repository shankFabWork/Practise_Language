// C++ program for Huffman Coding with STL
#include <bits/stdc++.h>
using namespace std;

struct Node {

	char data;

	unsigned freq;

	Node *left, *right;

	Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL)
	{
		this->left = l;
		this->right = r;
		this->data = data;
		this->freq = freq;
	}
};

struct compare 
{
	bool operator()(Node* l, Node* r)
	{
		return (l->freq > r->freq);	
	}
};

void printCodes(struct Node* root, string str)
{
	if(root == NULL)
	{
		return;
	}

	if(root->data != '$')
	{
		cout << root->data << ": " << str << "\n";
	}

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void printHcodes(char arr[], int freq[], int size)
{
    // By Default priority queue is max heap 
    // on the basis on first element 
    // in this it will sort lexiographically
    // in order to make it min heap we have to apply
    // vector <Node*> while declaration
    // compare is the comparator in c++
    // which do comparision on the basis of
    // on the basis of frequency in ascending order
	priority_queue<Node*, vector<Node*>, compare> h;
	for (int i = 0; i < size; ++i)	
	{
		h.push(new Node(arr[i], freq[i]));
	}

	// Iterate while size of heap doesn't become 1
	while (h.size() > 1) 
    {
		Node *l = h.top();
        h.pop();
		Node *r = h.top();
        h.pop();
		Node *top = new Node('$', l->freq + r->freq, l, r);

		h.push(top);
	}

	printCodes(h.top(), "");
}

int main()
{

	char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };
	// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    // int freq[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printHcodes(arr, freq, size);

	return 0;
}

