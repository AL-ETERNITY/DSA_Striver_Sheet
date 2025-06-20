// function to solve the problem of constructing a doubly linked list from an array of integers
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            if(head == NULL) {
                head = tail = newNode;
            } 
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        return head;
    }
};
