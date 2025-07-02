// function to solve the problem of counting the number of undirected graphs with n nodes.
// The max number of edge in an undirected graph is nC2. i.e number of ways to connect 2 nodes in n nodes.
// Now every edge between 2 nodes can either exist or not exists.

// So ideally if every node is connected to every other node in that the option given to an edge either to exist or not exists will create all the permutation of the possible undirected graphs.

// there is 2 choice for each edge either exist or not exist. 
// 2x2x2x......(no.edges possible)

// pow(2, total number of edges possible) = pow(2, nC2)

// 1 liner:
// return (1LL << ((n*(n-1))/2));

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long count(int n) {
        return pow(2, n* (n - 1) / 2);
    }
};