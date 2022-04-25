// I/P
// abdabcbabc
// abc
// O/P
// 3 7

// I/P
// aaaaa
// aaa
// O/P
// 012

// I/P
// abcd
// xyz
// O/P
// Not Found

// 1) Like naive algorithm, silde the 
// pattern one by one
// 2) Compare Hash values of pattern and current 
// text window . if hash values matches ,
// then compae individual character

#include <iostream>

using namespace std;


// P -> Hash Value of pattern
// T -> Hash value of current window of text

// ----------------------------
// a:1
// b:2
// c:3
// d:4
// e:5
// a b d a b c b a b c
// 1 2 4 1 2 3 2 1 2 3

// p = (1+2+3) = 6
// i=0:t=(2+4+1) = 7
// i=1:t=(4+1+2) = 7
// i=2:t=(1+2+3) = 6 (Match)
// i=3:t=(2+3+2) = 7
// i=4:t=(3+2+1) = 6 (Spurious Hit)
// i=5:t=(2+1+2) = 5
// i=6:t=(1+2+3) = 6 (Match)

// Simple Hash -> sum of values
// Problem -> Spurious Hit


// ----------------------------
// a:1
// b:2
// c:3
// d:4
// e:5
// a b d a b c b a b c
// 1 2 4 1 2 3 2 1 2 3


// t(i+1) = d*(t(i) - txt[i]*t^m-1) + txt[i+m]

// pat = "abc"
// p = 1*5^2 + 2*5 + 3*1 = 38

// t0 = 1*5^2 + 2*5^1 + 4*5^1 = 39
// t1 = 5*(t0 - 1*5^2) + 1 = 71
// t2 = 5*(t1 - 2*5^2) + 2 = 107
// t3 = 5*(t2 - 4*5^2) + 2 = 38 (match)

// "q" is primary number taken as
//  big as possible in order to
//  avoid spurious hits
// in this case
// const int q=101;











// NO IMPORTANT 
// not in 
// Must Do Coding Questions
// Practice for cracking any coding interview
// 300+ Must Do Coding Questions
