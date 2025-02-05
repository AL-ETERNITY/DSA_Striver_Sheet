#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();

        int startrow=0;
        int endrow=row-1;

        while (startrow<endrow)
        {
            for (int i=0;i<col;i++)
            {
                swap(matrix[startrow][i],matrix[endrow][i]);
            }
            startrow++;
            endrow--;
        } 

        int i=1;
        int j=1;
        int m=0;
        while (i<row && j<col)
        {
            int k=i;
            int l=j;
            while (k<row && l<col)
            {
                swap(matrix[m][l++],matrix[k++][m]);
            }
            i++;
            j++;
            m++;
        }
    }
};