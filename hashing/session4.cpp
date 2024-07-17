// Question===============>>>>>>>>>>>>>>>...Count all i,j pairs where i<j and abs(b[i]-b[j]) = k [k>=0] 

// 1)Brute-Force

#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
int countPairs(vector<int>& arr, int k) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }
    return count;
}
 
int main() {
    vector<int> arr = {1, 7, 5, 9, 2, 12, 3};
    int k = 2;
    cout << "Number of pairs: " << countPairs(arr, k) << endl;
    return 0;
}
// output->3

// 2)Optimal SOlution

#include <iostream>
#include <vector>
#include <cmath>
#include<unordered_map>
 
using namespace std;
 
int countPairs(vector<int>& arr, int k) {
  unordered_map<int,int> mp;
  int count  = 0;
  int n = arr.size();

  for(int i=0;i<n;i++){
    int target1 = arr[i]+k;
    if(mp.find(target1)!=mp.end()){
      count+=mp[target1]++;
    }

    int target2 = arr[i]-k;
    if(mp.find(target2)!=mp.end()){
      count+=mp[target2]++;
    }

    mp[arr[i]]++;
  }
  return count;
}

// explaination=>>isme hm log arr[i]+k && arr[i]-k kr rhe h kyoki absolute h to ek baar i-j && ek bar j-i kr rhe h vhi map me likha h to do alag alag target bna liye aur count ko aage bdha diya.