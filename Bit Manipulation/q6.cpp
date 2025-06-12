#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        
        // To unset the rightmost set bit
        
        return n & n-1;
        
        // To set the rightmost unset bit
        
        return n | n + 1;
    }
};