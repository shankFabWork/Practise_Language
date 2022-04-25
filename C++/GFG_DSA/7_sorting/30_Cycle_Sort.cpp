// Cycle sort is an in-place sorting Algorithm, unstable
// sorting algorithm, a comparison sort that is 
// theoretically optimal (best or most favourable) 
// in terms of the total number of writes
// to the original array.

// It is optimal in terms of number of memory writes. 
// It minimizes the number of memory writes to sort
// (Each value is either written zero times, 
// if it’s already in its correct position, or
// written one time to its correct position.)

// It is based on the idea that array to be sorted 
// can be divided into cycles. Cycles can be visualized
// as a graph. We have n nodes and an edge directed
// from node i to node j if the element at i-th index 
// must be present at j-th index in the sorted array.

// Time Complexity : O(n^2)
// Worst Case : O(n^2)
// Average Case: O(n^2)
// Best Case : O(n^2)
// Space Complexity : O(1)

// This sorting algorithm is best suited for situations 
// where memory write or swap operations are costly.

// I/P
// 20 40 50 10 30 
// item = 20
// O/P
// 10 20 30 40 50 

// item = 20 (elements are smaller than 20) 10 (1) 
// 20 40 50 10 30 
//    20

// item = 40 (elements are smaller than 40) 10 30 20 (3) 
// 20 40 50 10 30 
//    20    40  

// item = 10 (elements are smaller than 10) (0) 
// 20 40 50 10 30 
// 10 20    40  

// item = 20 (elements are smaller than 10) (0) 
// 20 40 50 10 30 
// 10 20    40  
// 20 is at its orignal position
// so the new array is 
// 10 20 50 40 30 

// 10 20 50 40 30 
// we were at 20 now we move to 50
// item = 50 (elements are smaller than 50) 10 20 40 30 (4) 
// 10 20 50 40 30 
//             50

// item = 30 (elements are smaller than 30) 10 20 (2) 
// 10 20 50 40 30 
//       30    50

// item = 50 (elements are smaller than 50) 10 20 40 30 (4) 
// 10 20 50 40 30 
//       30    50
// 50 is already in its correct position    


// we are assuming that array do not contains any duplications
#include <iostream>

using namespace std;


// u can try 
// as it is very difficult for me to understand
// so i haven't done that