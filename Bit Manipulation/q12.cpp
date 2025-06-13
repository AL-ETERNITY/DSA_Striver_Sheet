// function to solve the problem of finding the XOR of all numbers in a given range [l, r].
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int xorUpto (int n) {
        if(n % 4 == 0) return n;
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n + 1;
        if(n % 4 == 3) return 0;
    }
  public:
    int findXOR(int l, int r) {
        if(l == 1) return xorUpto (r);
        return xorUpto(l - 1) ^ xorUpto(r);
    }
};