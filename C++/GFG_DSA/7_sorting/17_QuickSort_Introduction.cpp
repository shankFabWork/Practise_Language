// 1) Divide and conquere algorithm

// 2) key part is partitoning -> (Naive , Lomuto ,Hoare )
// Hoare , Lomuto are not stable

// Naive are stable
//but requires auxilary space

// 3) worst case time complexity is O(n^2)

// 4) inspite of its high worst case 
// it is preffered over another algorithm
// due to the following reasons :

// a) tail recursion

// b) in - place (need an auxilary array to merge )

// c) cache friendly
// u do not need new array to partition 
// so most of your data is in the cache

// d) average case O(n.log(n) ) 

// for linked list , merge case  is preffered
// but for array , quick sort is preffered 