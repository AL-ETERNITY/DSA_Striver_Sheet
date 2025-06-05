// implemented celebrity problem using two pointer approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int rows = mat.size();
        int top = 0;
        int down = rows-1;
        while(top<down){
            if(mat[top][down] == 1){
               top++; 
            }
            else if(mat[down][top]==1){
                down--;
            }
            else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        else{
            for(int i=0;i<rows;i++){
                if (i==top) continue;
                if((mat[top][i] != 0) || (mat[i][top] != 1)){
                    return -1;
                }
            }
            return top;
        }
    }
};