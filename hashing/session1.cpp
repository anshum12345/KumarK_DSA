// Question==>>  Check if there are any two Equal numbers in an array at a distance less than or equal to k

// 1)Brute-force

#include <vector>
#include <unordered_set>

bool containsNearbyDuplicateBruteForce(const std::vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && j <= i + k; ++j) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}





