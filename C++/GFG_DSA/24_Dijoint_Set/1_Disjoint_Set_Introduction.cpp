// Simpe Solution ::
// -----------------
// Use Adjacency List or Adjacency Matrix
// Representation ::::
// Adjacency List :
// makeFriends() and areFriends() are O(n)
// Adjacency Matrix :
// makeFriends() is O(n) and areFriends() are O(1)

// Better Solution :
// Disjoint set data structure
// find(x) : return a representation of x's set
// union(x) : combine sets of x and y

// I/P
// n=4
// makeFriends(0,1) , makeFriends(1,3) ,areFriends(0,2)
// ,areFriends(0,1) ,areFriends(0,3) 
// O/P
// NO YES YES


// I/P
// n=5  
// makeFriends(2,3) , makeFriends(0,2) ,areFriends(0,3)
// ,areFriends(0,4) ,makeFriends(3,4) ,areFriends(0,4)
// O/P
// YES NO YES

