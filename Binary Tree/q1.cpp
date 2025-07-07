// function to count the number of nodes at a given level in a binary tree
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNodes(int i) {
        return pow(2,i-1);
    }
};