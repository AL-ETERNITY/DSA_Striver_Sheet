// function to solve the problem of counting prime numbers less than a given integer n
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int count = 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; ++i) {
            if (prime[i]) ++count;
        }

        return count;
    }
};