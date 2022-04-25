// Time complexity in Hoare and Lomuto are same
// Naive Partitoning algorithm takes more extra space


// Time Complexity::
// Worst complexity : n^2
// Average complexity : n*log(n)
// Best complexity : n*log(n)

// Space Complexity::
// Quick sort
//     naive partition -> O(n)  -> (not inplace)
//     lomuto partition -> O(1) -> (inplace)
//     hoare partition -> O(1) -> (inplace)

// requires space for the stack due to recursion
// as recursion stores data in recusion call stack
// it means most of the space is in the cache