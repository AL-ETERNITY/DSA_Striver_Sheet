// function to solve the problem of finding all shortest transformation sequences from a begin word to an end word using a given word list.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    int size;

private:
    void dfs(string word, vector<string>& seq){
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for (int i = 0; i < size; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        b = beginWord;

        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);

        size = beginWord.size();
        while(!q.empty()){
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord) break;

            for(int i = 0; i<size; i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);

        }
        return ans;
    }
};