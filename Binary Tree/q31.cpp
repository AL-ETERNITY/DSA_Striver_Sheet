// function to check if it is possible to form a complete binary tree for given traversals inorder = 2 preorder = 1 and postorder = 3
#include <iostream>
using namespace std;
class Solution {
  public:
    bool isPossible(int a, int b) {
        if(a == 2 || b == 2) {
            if(a != 2 || b != 2) {
                return true;
            }
        }
        return false;
    }
};