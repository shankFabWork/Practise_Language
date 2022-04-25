#include <iostream>

using namespace std;

class Trie
{
    public:
    bool isEnd;
    Trie *children[26];
};

Trie *make_Trie()
{
    Trie* New = new Trie();
    New->isEnd = false;
    for(int i=0;i<26;i++)
    {
        New->children[i] = NULL;
    }
    return New;
}

void insert_in_Trie(Trie *root,string str)
{
    Trie *root_copy = root;
    for(int i=0;i<str.length();i++)
    {
        int index = str[i] - 'a';
        if(root_copy->children[index] == NULL)
        {
            root_copy->children[index] = make_Trie();
        } 
        root_copy = root_copy->children[index];
    }
    root_copy->isEnd = true;
}

bool search(Trie *root,string str)
{
    Trie *root_copy = root;
    for(int i=0;i<str.length();i++)
    {
        int index = str[i] - 'a';
        if(root_copy->children[index] == NULL)
        {
            return false;
        }
        root_copy = root_copy->children[index];
    }
    return (root_copy->isEnd == true);
}

bool isEmpty(Trie *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->children[i])
        {
            return false;
        }
    }
    return true;
}

Trie *remove(Trie *root,string key,int i)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(i == key.length())
    {
        root->isEnd = false;
        if(isEmpty(root) == true)
        {
            delete root;
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->children[index] = remove(root->children[index],key,i+1);
    if(isEmpty(root) && root->isEnd == false)
    {
        delete root;
        root = NULL;
    }
    return root;
}



int main()
{
    string keys[] = {"bad", "bat", "geek", "geeks", "cat", "cut"}; 
	
	int n = sizeof(keys)/sizeof(keys[0]); 

	Trie *root = make_Trie(); 

	for (int i = 0; i < n; i++) 
    {
		insert_in_Trie(root, keys[i]); 
        // TC - O(n)
        // SC - O(n)
        // Here n is the key length
    }

	cout<<(search(root, "bat")?"Yes\n":"No\n");
	cout<<(search(root, "gos")?"Yes\n":"No\n");
    // TC - O(n)
    // SC - O(1)

    root = remove(root,"bat",0); 
    // TC - O(n)
    // SC - O(1)

	cout<<(search(root, "bat")?"Yes\n":"No\n");

	return 0; 

}