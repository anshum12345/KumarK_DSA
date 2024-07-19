// question===============>>>>>>>>>>>..Longest Consecutive Sequence
// leetcode.com/problems/longest-consecutive-sequence/description/

// 1)Brute-Force

#include<vector>
using namespace std;
class Solution{
  public:
  int longestConsecutive(vector<int>& nums){

  if(nums.empty()) return 0;

  int longeststreak = 1;
  int currentstreak = 1;

  for(int i=1;i<nums.size();i++){
    if(nums[i]!=nums[i-1]) {

    if(nums[i]==nums[i-1]+1){
      currentstreak++;
    }
    else{
      longeststreak = max(longeststreak,currentstreak);
      currentstreak = 1;
    }
  }
  }
  longeststreak = max(longeststreak,currentstreak);
  return longeststreak;
  }
};


// 2)Optimal Solution(map)


