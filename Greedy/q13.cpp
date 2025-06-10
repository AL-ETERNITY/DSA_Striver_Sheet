//function to solve the page fault problem using LRU cache
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        
        Node(int data){
            this -> data = data;
            prev = NULL;
            next = NULL;
        }
};

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        int faults = 0;
        unordered_map<int,Node*> cache;
        int count = 0;
        Node* head = NULL;
        Node* tail = NULL;
        
        for(int i = 0;i<N;i++){
            int page = pages[i];
            if(cache.count(page)){
                Node* curr = cache[page];
                if(curr != tail){
                    if(curr->prev) curr->prev->next = curr->next;
                    if(curr->next) curr->next->prev = curr->prev;
                    
                    if(curr == head){
                        head = curr->next;
                    }
                    
                    curr->prev = tail;
                    curr->next = NULL;
                    tail->next = curr;
                    tail = curr;
                }
                continue;
            }
            
            faults++;
            
            Node* newNode = new Node(page);
            cache[page] = newNode;

            if(count<C){
                count++;
                if(!head){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    newNode->prev = tail;
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            else {
                // Remove LRU (head)
                cache.erase(head->data);

                Node* temp = head;
                head = head->next;
                if (head) head->prev = nullptr;
                delete temp;

                // Add newNode at tail
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        return faults;
    }
};