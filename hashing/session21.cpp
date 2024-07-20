// Question===>>>>>>>..Longest Sub-Array with Sum K
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <unordered_map>
using namespace std;

class Solution {
public:
  int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> mp;
        int sum=0, maxlen=0;
        
        for(int i=0;i<N;i++){
            sum += A[i];
            
            if(sum==K) maxlen=max(maxlen, i+1);
            
            int target=sum-K;
            
            if(mp.find(target) != mp.end()){
                int len = i - mp[target];
                maxlen = max(maxlen, len);
            }
            
            if (mp.find(sum) == mp.end()) 
                mp[sum]= i;
        
        }
        return maxlen;
    } 
};