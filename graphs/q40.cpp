// function to solve the problem of finding the number of connected components in a graph using union-find (disjoint set union) algorithm.
#include <bits/stdc++.h>
using namespace std;

int find(int par[], int x) {
    if(par[x] == x)
    return x;
    
    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    int a = find(par, x);
    int b = find(par, z);
    
    par[a] = b;
}