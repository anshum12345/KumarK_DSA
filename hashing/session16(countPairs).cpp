// Question=====>>>>>>>>>>>>>...2006. Count Number of Pairs With Absolute Difference K
//leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

// 1)Brute-Force(two pointer)
// T.C=>O(N^2)

#include <vector>
#include <cmath> // Include cmath for abs function
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k) { // Corrected condition
                    count++;
                }
            }
        }
        return count;
    }
};

// 2)Optimal Soolution(use maps)
// T.C=>O(N)

#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int target1 = nums[i]-k;
            int target2 = nums[i]+k;

            if(mp.find(target1)!=mp.end()){
               count+=mp[target1];
            }
            if(mp.find(target2)!=mp.end()){
               count+=mp[target2];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};

// expaination=>>

// Let's go through the example `{3, 1, 4, 1, 5}` and `k = 2` step-by-step to see how the function works:

// 1. **Iteration 1 (`nums[i] = 3`)**:
//    - Calculate `target1 = 3 - 2 = 1` and `target2 = 3 + 2 = 5`.
//    - Update `mp[3]` to `1`.
//    - Neither `target1` nor `target2` exists in `mp`, so no pairs are counted.

// 2. **Iteration 2 (`nums[i] = 1`)**:
//    - Calculate `target1 = 1 - 2 = -1` and `target2 = 1 + 2 = 3`.
//    - Update `mp[1]` to `1`.
//    - `target2` is `3` and exists in `mp` with a frequency of `1`. Add `1` to `count`.

// 3. **Iteration 3 (`nums[i] = 4`)**:
//    - Calculate `target1 = 4 - 2 = 2` and `target2 = 4 + 2 = 6`.
//    - Update `mp[4]` to `1`.
//    - `target1` is `2` and exists in `mp` with a frequency of `1`. Add `1` to `count`.

// 4. **Iteration 4 (`nums[i] = 1`)**:
//    - Calculate `target1 = 1 - 2 = -1` and `target2 = 1 + 2 = 3`.
//    - Update `mp[1]` to `2`.
//    - `target1` is `-1` and exists in `mp` with a frequency of `2`. Add `2` to `count`.

// 5. **Iteration 5 (`nums[i] = 5`)**:
//    - Calculate `target1 = 5 - 2 = 3` and `target2 = 5 + 2 = 7`.
//    - Update `mp[5]` to `1`.
//    - `target1` is `3` and exists in `mp` with a frequency of `1`. Add `1` to `count`.

// 6. **Final Count**:
//    - `count` accumulates the total number of valid pairs `(nums[i], nums[j])` such that `|nums[i] - nums[j]| = 2`.
//    - In this case, the count should be `4`, as we found pairs `(3, 1)`, `(1, 3)`, `(4, 2)`, and `(5, 3)`.

// ### Conclusion

// The function `countKDifference` efficiently solves the problem of counting pairs with a specified absolute difference using an unordered map to track frequencies and leveraging two-pass checks to avoid double-counting. This approach ensures that the solution is both effective and efficient for large inputs.