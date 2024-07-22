// Question===>>>>>>>>. AMAZON OA (INTERN 2024)
// https://leetcode.com/discuss/interview-question/3114099/AMAZON-OA-(INTERN-2024)

// 1)Brute-Force

#include<iostream>
using namespace std;

int calcRemovalCount(string &word, string &target) {
    int word_counts[26] = {0,}, target_counts[26] = {0,};
    for (char ch: word) {
        word_counts[ch - 'a'] += 1;
    }
    for (char ch: target) {
        target_counts[ch - 'a'] += 1;
    }
    int ans = INT_MAX;
    for (char ch: target) {
        ans = min(ans, word_counts[ch - 'a'] / target_counts[ch - 'a']);
    }
    return ans;
}

// 2)Optimal Solution

#include<unordered_map>
using namespace std;

int result(string s, string t) {
   unordered_map<int,int>mp;
   int n = s.size();
   int m = t.size();
   for(int i=0;i<n;i++){
    mp[s[i]]++;

    int mini = INT_MAX;
    for(int i=0;i<m;i++){
      mini = min(mini,mp[t[i]]);
    }
    return mini;
   }
}