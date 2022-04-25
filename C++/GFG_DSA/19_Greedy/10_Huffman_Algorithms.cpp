#include <bits/stdc++.h>

using namespace std;

class Huff
{
    public:
    char data;
    int freq;
    Huff *left;
    Huff *right;

    Huff(char data,int freq,Huff *l = NULL,Huff *r = NULL)
    {
        this->data = data;
        this->freq = freq;
        this->left = l;
        this->right = r;
    }
};

struct myComp
{
    bool operator()(Huff* h1,Huff* h2)
    {
        return (h1->freq > h2->freq);
    } 
};


void print_val(Huff* root,string str)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data != '$')
    {
        cout<<root->freq<<" "<<str<<endl;
    }
    print_val(root->left,str+'0');
    print_val(root->right,str+'1');
}

void printHcodes(char arr[],int freq[],int size)
{
    // max heap on the basis of frequency
    priority_queue <Huff*,vector<Huff*>,myComp> h;
    for(int i=0;i<size;i++)
    {
        h.push(new Huff(arr[i],freq[i]) );
    }
    while(h.size() > 1)
    {
        Huff* l = h.top();
        h.pop();
        Huff* r = h.top();
        h.pop();
        Huff* temp = new Huff('$',l->freq+r->freq,l,r);
        h.push(temp);
    }
    print_val(h.top(),"");

} 

int main()
{
    char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printHcodes(arr, freq, size);
    return 0;
}