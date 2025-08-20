// function to solve the problem of complete substring
#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
        flag = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool getEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    void checkPrefix(string word, string& largest) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i]) || !node->get(word[i])->getEnd()) {
                return;
            }
            node = node->get(word[i]);
        }
        if(word.length() > largest.length() || 
           (word.length() == largest.length() && word < largest)) {
            largest = word;
        }
    }
};

string completeString(int n, vector<string> &a) {
    Trie t;
    for(int i = 0; i < a.size(); i++) {
        t.insert(a[i]);
    }
    string largest = "";
    for(int i = 0; i < a.size(); i++) {
        t.checkPrefix(a[i], largest);
    }
    return (largest.size() != 0) ? largest : "None";
}
