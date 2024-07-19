// Question===========>>>>>>>>>>>>>>>.. Two Sum
// https://leetcode.com/problems/two-sum/description/

// 1)Brute-Force(Two pointer)

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
       for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
       }
       return { };
    }
};

// 2)Optimal Solution(Map)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if complement exists in the map
            if (mp.find(complement) != mp.end()) {
                // Found the pair
                result.push_back(mp[complement]);  // index of complement
                result.push_back(i);               // current index
                return result;
            }
            
            // Add current number to map with its index
            mp[nums[i]] = i;
        }
        
        // If no such pair found, return an empty vector
        return result;
    }
};


