// Question============>>>>>>>>>>>....Find the length of largest subarray with 0 sum
//www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

// 1)Brute-Force
// T.C=>O(N^2)

#include<vector>
using namespace std;

int maxLen(int arr[], int N){
  int maxi = 0;
  for(int i=0;i<N;i++){
    int current_Sum = 0;
    for(int j=i;j<N;j++){
      current_Sum+=arr[j];
      if(current_Sum==0){
        maxi = max(maxi,j-i+1);
      }
    }
    return maxi;
  }
}


// 2)Optimal-Solution
// T.C=>O(N)

#include<vector>
#include<unordered_map>
using namespace std;

// Returns Length of the required subarray
int maxLen(int arr[], int N)
{
    // Map to store the previous sums
    unordered_map<int, int> presum;

    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result

    // Traverse through the given array
    for (int i = 0; i < N; i++) {

        // Add current element to sum
        sum += arr[i];
        if (sum == 0)
            max_len = i + 1;

        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end()) {

            // If this sum is seen before, then update
            // max_len
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            // Else insert this sum with index
            // in hash table
            presum[sum] = i;
        }
    }

    return max_len;
}

