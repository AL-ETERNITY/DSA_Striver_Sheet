// function to solve the problem of finding maximum XOR between two numbers in an array;
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node -> containsKey(bit)){
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node -> containsKey(1 - bit)){
                maxNum |= (1 << i); 
                node = node -> get(1 - bit);
            } else {
                node = node -> get(bit);
            }
        }
        return maxNum;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto& it:nums){
            t.insert(it);
        }

        int maxAns = 0;
        for(auto& it:nums){
            maxAns = max(maxAns, t.getMax(it));
        }

        return maxAns;
    }
};