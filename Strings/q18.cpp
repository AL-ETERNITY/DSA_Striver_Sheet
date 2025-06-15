// function to solve the problem of finding the minimum number of times a string A must be repeated
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int BASE = 1000000;
    int Rabin_Karp(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1; // 31 ^ m
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0; // hash of target
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
public:
    int repeatedStringMatch(string A, string B) {
        // A - abcd
        // Cases -
        // 1. A can be prefix & suffix -> prefix + n*a + suffix ==> cd(abcd)ab   --> ans = n + 2
        // 2. A can be suffix -> prefix + n*a ==> cd(abcd)                       --> ans = n + 1
        // 3. A can be prefix -> n*a + suffix ==> (abcd)ab                       --> ans = n + 1
        // 4. A can be B -> n*a  ==> (abcd)                                      --> ans = n
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        // 4. Case of ans = n
        if(source == B) return count;

        // 2,3. Case of ans = n + 1
        if(Rabin_Karp(source,B) != -1) return count;

        // 1. Case of ans = n + 2
        if(Rabin_Karp(source+A,B) != -1) return count+1;

        return -1;
    }
};