// implemented number of next greater elements using brute force approach
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        //Function to count the number of elements greater than the element at given index.
        int nextGreaterElements(vector<int>& a, int index){
            int count = 0, N = a.size();
            //iterating over the array elements after the given index.
            for (int i = index + 1; i < N; i++)
                //if element at current index is greater than the element at given index, increment count.
                if (a[i] > a[index])
                    count++;
         
            return count;
        }
    
        //Function to find the number of elements greater than the element at given indices.
        vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
            vector<int> ans;
            //iterating over the given indices.
            for(int i = 0;i<queries;i++){
                //calling nextGreaterElements function to get the count of elements greater than element at current index.
                ans.push_back(nextGreaterElements(arr,indices[i]));
            }
    
            return ans;
        }
};  