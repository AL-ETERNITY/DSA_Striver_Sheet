// implemented LFU Cache using hashmap and doubly linked list
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Node {
public:
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->freq = 1; // frequency starts at 1
        prev = NULL;
        next = NULL;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> cache;                    // key -> node
    unordered_map<int, list<Node*>> freqList;           // freq -> list of nodes
    unordered_map<Node*, list<Node*>::iterator> pos;    // node -> iterator in freqList
    int capacity;
    int minFreq;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (cache.size() >= capacity) {
            Node* nodeToEvict = freqList[minFreq].back();
            cache.erase(nodeToEvict->key);
            pos.erase(nodeToEvict);
            freqList[minFreq].pop_back();
            delete nodeToEvict;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        freqList[1].push_front(newNode);
        pos[newNode] = freqList[1].begin();
        minFreq = 1;
    }

private:
    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq].erase(pos[node]);
        if (freqList[oldFreq].empty()) {
            freqList.erase(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }

        node->freq++;
        freqList[node->freq].push_front(node);
        pos[node] = freqList[node->freq].begin();
    }
};
