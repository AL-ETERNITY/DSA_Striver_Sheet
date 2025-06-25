// function to solve the problem of finding a word in a 2D board
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int index, int i, int j) {
        if (index == word.length()) return true;

        // Left
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[index]) {
            visited[i][j - 1] = true;
            if (solve(board, visited, word, index + 1, i, j - 1)) return true;
            visited[i][j - 1] = false;
        }

        // Bottom
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[index]) {
            visited[i + 1][j] = true;
            if (solve(board, visited, word, index + 1, i + 1, j)) return true;
            visited[i + 1][j] = false;
        }

        // Right
        if (j < board[0].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[index]) {
            visited[i][j + 1] = true;
            if (solve(board, visited, word, index + 1, i, j + 1)) return true;
            visited[i][j + 1] = false;
        }

        // Top
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[index]) {
            visited[i - 1][j] = true;
            if (solve(board, visited, word, index + 1, i - 1, j)) return true;
            visited[i - 1][j] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char,int> count;
        for(char ch:word){
            count[ch]++;
        }

        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    if(solve(board, visited, word, 1, i, j)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};