// function to solve the problem of xor , checking the ith bit is set or not and setting the ith bit
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int XOR(int n, int m) {
        return n^m;
    }

    int check(int a, int b) {
        return ((b >> (a - 1)) & 1);
    }

        
    int setBit(int c, int d) {
        return d | (1 << c);
    }
};