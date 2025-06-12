// fuucntion to solve the problem of checking if the k-th bit of an integer n is set (1) or not (0).
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        vector<int> bits;
        while (n != 0) {
            bits.push_back(n % 2);
            n = n / 2;
        }

        if (k >= bits.size()) {
            return false;
        }

        return bits[k] == 1;
    }
};

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
};
