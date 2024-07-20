// Question===>>>>>>>>>>>>>..Subarrays with sum K
//www.geeksforgeeks.org/problems/subarrays-with-sum-k/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:
    int findSubArraySum(int nums[], int N, int k)
    {
        // code here
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0,count=0;
        for(int i=0;i<N;i++)
        {
            sum += nums[i];
            int rem = sum-k;
            if(mp.find(rem) != mp.end())
            {
                count += mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};