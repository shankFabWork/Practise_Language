// CPP program to check if k-th bit 
// of a given number is set or not 
#include <iostream> 
using namespace std; 

// I/P
// n=5,k=1
// O/P
// yes

// I/P
// n=8,k=2
// O/P
// no

// Method 1 (Using Left Shift) (Learn Only This)
void isKthBitSet_left(int n, int k) 
{ 
	if (n & (1 << (k - 1) ) ) 
		cout << "SET"; 
	else
		cout << "NOT SET"; 
} 

// rotate 1 and << and rotate equation

// Method 2 (Using Right Shift)
void isKthBitSet_right(int n, int k) 
{ 
	if ( (n >> (k - 1) ) & 1) 
		cout << "SET"; 
	else
		cout << "NOT SET"; 
} 

// Driver code 
int main() 
{ 
	int n = 5, k = 1; 
	isKthBitSet_left(n, k);
    // Time Complexity: O(1) 
    // Space Complexity: O(1). 

	cout<<endl;

	n=13;
	k=3;
	isKthBitSet_right(n,k);
    // Time Complexity: O(1) 
    // Space Complexity: O(1). 

	return 0; 
} 

// n=5 
// k=3
// yes