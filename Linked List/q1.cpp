// function to solve the problem of constructing a linked list from an array of integers
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head = NULL;
        Node* tail = NULL;
        for(int i=0;i<arr.size();i++){
            Node* newNode = new Node(arr[i]);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
};