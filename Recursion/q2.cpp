// function to solve the problem of calculating x raised to the power n (x^n) using recursion.
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    double recur (long long N, double x) {
        if(N == 0) return 1.0;

        if (N % 2 == 1) {
            return x * recur(N - 1, x);
        } else {
            return recur(N / 2, x * x);
        }
    }
public:
    double myPow(double x, int n) {
        long long N = n;  // Use long long to handle INT_MIN safely
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        // Recursive 
        return recur (N, x);
    }
};