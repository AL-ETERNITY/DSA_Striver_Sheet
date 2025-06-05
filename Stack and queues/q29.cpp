// implemented LRU Cache using doubly linked list and hashmap
#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this -> key = key;
        this -> val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    int capacity;
    Node* latest;
    Node* oldest;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = latest->prev;
        Node* next = latest;
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        latest = new Node(-1,-1);
        oldest = new Node(-1,-1);
        oldest -> next = latest;
        latest -> prev = oldest;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > capacity) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
