// Question=================>>>>>>>>>>>>>>>>>...Find count of number of subarrays with sum ==  k 

// 1)Brute-Force(Two-pointer)
// T.C => O(N^2)

#include <iostream>
#include <vector>
using namespace std;
 
int countSubarraysBruteForce(vector<int>& arr, int k) {
  int n = arr.size();
  int count = 0;
  for(int i = 0; i<n;i++){
    int sum = 0;
    for(int j = i;j<n;j++){
      sum = sum + arr[j];
      if(sum==k){
        count++;
      }
    }

  }
  return count;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Number of subarrays with sum " << k << ": " << countSubarraysBruteForce(arr, k) << endl;
    return 0;
}
// output::(Number of subarrays with sum 5: 2)

// 2)Optimal-Solution(using map)
// T.C => O(N)

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int countSubarraysOptimized(vector<int>& arr, int k) {

  unordered_map<int,int> mp;
  int count = 0;
  int sum = 0;
  int n = arr.size();
  mp[0] = 1;
  for(int i = 0;i<n;i++){
   sum = sum+arr[i];
   int x = sum - k;

   if(mp.find(x)!=mp.end()){
    count = count + mp[x]++;
   }
   mp[sum]++;
  }
  return count;
}

// explaination===>>
// Certainly! Let's dive deeper into the example with the array `arr = {1, 2, 3, 4, 5}` and `k = 5`, step by step, to understand how the `countSubarraysOptimized` function works and why `sum - k` is used.

// ### Given Example:

// #### Input:
// - `arr = {1, 2, 3, 4, 5}`
// - `k = 5`

// #### Step-by-Step Explanation:

// 1. **Initialization**:
//    - `unordered_map<int, int> mp;`: Initialize an unordered map `mp` to store cumulative sums and their frequencies.
//    - `int count = 0;`: Initialize `count` to zero to keep track of the number of subarrays found.
//    - `int sum = 0;`: Initialize `sum` to zero to accumulate the sum of elements as we iterate through the array.
//    - `int n = arr.size();`: Determine the size of the array `arr`, which is `5` in this case.
//    - `mp[0] = 1;`: Initialize the map with `mp[0]` set to `1`. This accounts for the case where the cumulative sum equals `k` itself.

// 2. **Iteration through Array**:
//    - **Iteration 1 (`i = 0`)**:
//      - `arr[0] = 1`
//      - `sum = sum + arr[0] = 0 + 1 = 1`
//      - Check `mp[1 - 5]`, which is `mp[-4]`. Not found.
//      - Add `sum` to map: `mp[1] = 1`.
//      - Explanation: The cumulative sum after the first element is `1`. Since `1 - 5 = -4` is not found in the map, no subarray with sum `5` is found yet.

//    - **Iteration 2 (`i = 1`)**:
//      - `arr[1] = 2`
//      - `sum = sum + arr[1] = 1 + 2 = 3`
//      - Check `mp[3 - 5]`, which is `mp[-2]`. Not found.
//      - Add `sum` to map: `mp[3] = 1`.
//      - Explanation: The cumulative sum after the second element is `3`. Since `3 - 5 = -2` is not found in the map, no subarray with sum `5` is found yet.

//    - **Iteration 3 (`i = 2`)**:
//      - `arr[2] = 3`
//      - `sum = sum + arr[2] = 3 + 3 = 6`
//      - Check `mp[6 - 5]`, which is `mp[1]`. Found.
//      - `count = count + mp[1] = 0 + 1 = 1`.
//      - Add `sum` to map: `mp[6] = 1`.
//      - Explanation: The cumulative sum after the third element is `6`. `6 - 5 = 1` is found in the map, indicating that there is one subarray from the first element to the third element (`{1, 2, 3}`) whose sum is `5`.

//    - **Iteration 4 (`i = 3`)**:
//      - `arr[3] = 4`
//      - `sum = sum + arr[3] = 6 + 4 = 10`
//      - Check `mp[10 - 5]`, which is `mp[5]`. Not found.
//      - Add `sum` to map: `mp[10] = 1`.
//      - Explanation: The cumulative sum after the fourth element is `10`. Since `10 - 5 = 5` is not found in the map, no new subarrays with sum `5` are found.

//    - **Iteration 5 (`i = 4`)**:
//      - `arr[4] = 5`
//      - `sum = sum + arr[4] = 10 + 5 = 15`
//      - Check `mp[15 - 5]`, which is `mp[10]`. Found.
//      - `count = count + mp[10] = 1 + 1 = 2`.
//      - Add `sum` to map: `mp[15] = 1`.
//      - Explanation: The cumulative sum after the fifth element is `15`. `15 - 5 = 10` is found in the map, indicating there is another subarray from the fourth element to the fifth element (`{4, 5}`) whose sum is `5`.

// 3. **Conclusion**:
//    - After iterating through the array, the function counts and returns `2`, which is the number of subarrays whose sum equals `5` (`{1, 2, 3}`, `{4, 5}`).

// ### Explanation of `sum - k`:

// - The expression `sum - k` is used to check if there exists a previously encountered cumulative sum in the map `mp` that, when subtracted from the current `sum`, equals `k`.
// - This check helps identify subarrays whose sum matches `k` efficiently:
//   - If `mp.find(sum - k) != mp.end()`, it means there exists a subarray ending at the current index whose sum is exactly `k`.
//   - By incrementing `count` with `mp[sum - k]`, we add the count of such subarrays found so far.

// ### Efficiency:

// - The function `countSubarraysOptimized` achieves linear time complexity `O(n)` where `n` is the size of the input array `arr`. This is because each element is processed once, and operations on the unordered map (insertion and lookup) average `O(1)` time complexity.
// - Space complexity is also `O(n)` in the worst case due to the storage of cumulative sums in the map.

// This optimized approach using a cumulative sum and an unordered map allows efficient counting of subarrays with a specified sum, making it suitable for large arrays and diverse input scenarios.