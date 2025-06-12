// function to solve the problem of counting set bits in an integer n
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int nearestPowerOfTwo(int n){
        int x = 0;
        while((1<<x) <= n) x++;
        return x-1;
    }
    int countSetBits(int n) {
        if(n==0) return 0;
        
        int x = nearestPowerOfTwo(n);
        int y = x * (1 << (x-1));
        int z = n - (1 << x);
        
        return y+z+1+countSetBits(z);
    }
};
