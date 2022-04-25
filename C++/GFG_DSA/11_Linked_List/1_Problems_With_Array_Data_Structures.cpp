// Fixed sized array
// ( allocated in stack )
// int arr[100]
// int arr[n]

// Dynamic sized array
// ( allocated in heap )
// int *arr = new int[n]
// vector <int> v;


// Problem with array:

// 1) Either size is fixed or prelocated

// 2) In fixed and variable sized array  
// , worst case insertion at the end is O(n)

// 3) Insetion in the middle is costly (from beginning)

// 4) Deletion in the middle is costly (from beginning)

// 5) Implementation of the data structures 
// with queue and deque is costly

// Example :
// when we see say 'x' replcae it with 5 'y'
// d e a x q r x p y
// answer is::
// d e a y y y y y q r y y y y y p y

// with Array , it will take lot of time:
// with Linked List , it will not take lot of time:


