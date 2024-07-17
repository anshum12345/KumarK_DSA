// Question==========>>>>>>>>>>>>>>>>..Count All ((i,j) pairs such that b[i] - b[j] == k (count of such pairs.) [i<j] 

// 1)brute-Force

#include <iostream>
#include <vector>
 
int countPairsBruteForce(const std::vector<int>& b, int k) {
    int count = 0;
    int n = b.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (b[i] - b[j] == k) {
                ++count;
            }
        }
    }
    return count;
}
 
int main() {
    std::vector<int> b = {1, 5, 3, 4, 2};
    int k = 2;
    std::cout << "Count of pairs: " << countPairsBruteForce(b, k) << std::endl;
    return 0;
}
// Output -> 2(because the count pair is 2 when i<j ans if when we doing abs of this then the output may be 3)

// 2)Optimal-Solution

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;  

int countPairsBruteForce(const vector<int>& arr, int k) {
  int count = 0;
  unordered_map<int, int> mp;
  int n = arr.size();
  
  for (int i = 0; i < n; ++i) {
    int target = arr[i] + k;
    if (mp.find(target) != mp.end()) {
      count += mp[target];
    }
    mp[arr[i]]++;
  }
  
  return count;
}


