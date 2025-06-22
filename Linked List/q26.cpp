// function to solve the problem of finding pairs with a given sum in a doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};
class Solution {
  private:
    Node* findtail(Node* head){
        Node* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        return curr;
    }

  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(!head || !head->next) return {};

        vector<pair<int,int>> ans;
        Node* first = head;
        Node* second = findtail(head);

        while(first && second && first != second && first->data < second->data) {
            int sum = first->data + second->data;
            if(sum == target) {
                ans.push_back({first->data, second->data});
                first = first->next;
                second = second->prev;
            } 
            else if (sum < target) {
                first = first->next;
            } 
            else {
                second = second->prev;
            }
        }

        return ans;
    }
};
