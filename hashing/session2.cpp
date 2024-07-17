// Question================>>>>>>>>>>>>>>>>>>. Count all the (i,j) Pairs such that b[i] + b[j] == k (count of such pairs.) [i<j] 

// 1)Brute-Force

#include <iostream>
#include <vector>
using namespace std;
 
int bruteForceCountPairs(vector<int>& arr, int k) {
    int count = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == k) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 6;
    cout << "Count of pairs: " << bruteForceCountPairs(arr, k) << endl;
    return 0;
}
//  Output->2

// 2)Optimal-solution

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countpairs(vector<int>& arr, int k){
  unordered_map<int,int>mp;
  int count = 0;
  int n = arr.size();

  for(int i = 0; i<n; i++){
    int complement = k-arr[i];
    if(mp.find(complement)!=mp.end()){
      count = count + mp[complement];
    }

    mp[arr[i]]++;
  }
  return count;
}
int main() {
    std::vector<int> arr = {1, 5, 7, -1, 5};
    int k = 6;
    std::cout << "Count of pairs: " << countpairs(arr, k) << std::endl;
    return 0;
}


