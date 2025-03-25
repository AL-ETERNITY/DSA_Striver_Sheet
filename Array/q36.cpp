#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<m+n;j++)
                {
                    if(nums1[j]==0)
                    {
                        nums1[j]=nums2[i];
                        break;
                    }
                }
            }
            for (int i=1;i<m+n;i++)
            {
                int temp = nums1[i];
                int j=i-1;
                for (;j>=0;j--)
                {
                    if (nums1[j]>temp)
                    {
                        nums1[j+1]=nums1[j];
                    }
                    else
                    {
                        break;
                    }
                }
                nums1[j+1]=temp;
            }
        }
    };