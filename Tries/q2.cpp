// function to implement trie with insert word, cnt word end with, cnt words startwith and erase word
#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    Node* links[26];
    int ew;
    int cp;

    Node(){
        for(int i = 0; i<26; i++){
            links[i] = NULL;
        }
        ew = 0;
        cp = 0;
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void increasePrefix(){
        cp++;
    }

    void increaseEndWith(){
        ew++;
    }

    int getEnd(){
        return ew;
    }

    int getPrefix(){
        return cp;
    }

    void reducePrefix(){
        cp--;
    }

    void deleteEndWith(){
        ew--;
    }



};
class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node -> containsKey(word[i])){
                return 0;
            }
            node = node -> get(word[i]);
        }
        return node -> getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node -> containsKey(word[i])){
                return 0;
            }
            node = node -> get(word[i]);
        }
        return node -> getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node -> containsKey(word[i])){
                return;
            }
            node = node -> get(word[i]);
            node -> reducePrefix();
        }
        node -> deleteEndWith();
    }
};
