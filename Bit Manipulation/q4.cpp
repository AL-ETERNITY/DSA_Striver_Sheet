// function to solve the problem of checking if a number is a power of two
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 and (n&(n-1)) == 0;
    }
};