// Question========>>>>>>>>>>>>>>.. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/description/

// Solution) Using Map

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
          mp[s[i]]++;
        }
        for(int i =0;i<n;i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};