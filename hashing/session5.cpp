// Question=========>>>>>>>>>>>>>... Find Sum of Range  [l……….r] where(l<=r) using Prefix sum. 

// #include <iostream>
#include <vector>
 #include<iostream>
using namespace std;
 
int bruteForceSum(const vector<int>& nums, int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; ++i) {
        sum += nums[i];
    }
    return sum;
}
 
int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    int l = 3, r = 7; // Example range [l, r]
    // cout << "Brute Force Sum: " << bruteForceSum(nums, l, r) << endl;
 
    return 0;
}
