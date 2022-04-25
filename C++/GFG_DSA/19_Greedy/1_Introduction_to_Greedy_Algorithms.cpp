// Greedy Algo is used for 
// Optimization problem

// Greedy is an algorithmic that 
// builds up a  solution piece 
// by piece, always choosing 
// the next piece that offers 
// the best solution

// we have infinite supply of coins

// greedy algorithm may not work all
// the time
// coins[] = {18,1,10}
// amount = 20
// greedy algo will say 18+1+1 is the
// optimal solution
// but optimal solution is two 10 coins
// 10+10

// 5,10,2,1
// make it descending order
// 10,5,2,1
// amount to pay - 52
// now , we will start with largest element
// answer is - 
// 5 - 10 rs. coin
// 1 - 2 rs. coin

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int minCoins(int coins[],int amount,int n)
{
    int res = 0;
    sort(coins,coins+n,greater<int>());
    for(int i = 0;i<n;i++)
    {
        if(coins[i] <= amount)  
        {
            int c = floor(amount/coins[i]);
            res = res + c;
            amount = amount - c*coins[i];
        }
        if(amount == 0)
        {
            break;
        }
    }
    return res;
}

int main()
{

    int amount = 57;
    int coins[] = {5,10,2,1};
    int n = sizeof(coins)/sizeof(int);
    int res = minCoins(coins,amount,n);
    cout<<res<<" ";

    return 0;
}



// ==> Applications of Greedy Algorithm

// Finding Optimal Solution
// Activity Selection
// Fractional Knapsack
// Job Sequencing
// Prim's Algorithm
// Krushkal's Algorithm
// Dijkstra's Algorithm
// Huffman coding

// Finding close to optimal solution
// for NP harder problems . Like 
// Travelling Salesman Problem 