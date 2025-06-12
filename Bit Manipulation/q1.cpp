// function to solve the problem of getting, setting, and clearing the i-th bit of a number.
#include <iostream>
using namespace std;

class Solution {
public:
    void bitManipulation(int num, int i) {
        int mask = 1 << (i - 1);  // 1-based index

        int get = (num & mask) ? 1 : 0;  // Get i-th bit
        int set = num | mask;           // Set i-th bit
        int clear = num & ~mask;        // Clear i-th bit

        cout << " " << get << " " << set << " " << clear;
    }
};
