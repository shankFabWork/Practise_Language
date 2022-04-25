// used for solving strongly 
// connected components

// if "a" can reach "b"
// then "b" can also reach "a"

// just explaination of Kosaraju's algorithm

// step 1 -> Find topologial sorting DFS and 
//           push it into the stack
// step 2 -> Transpose
// step 3 -> DFS of new Graph