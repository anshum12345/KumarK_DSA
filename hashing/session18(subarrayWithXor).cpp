// Question==========>>>>>>>>>>>>>>>>>..Count the number of subarrays having a given XOR
//www.geeksforgeeks.org/count-number-subarrays-given-xor/

// 1)Brute-Force

#include <bits/stdc++.h>
using namespace std;
 
// Simple function that returns count of subarrays
// of arr with XOR value equals to m
long long subarrayXor(int arr[], int n, int m){
  long long count = 0;

  for(int i=0;i<n;i++){
    long long Xor_Sum = 0;
    for(int j=i;j<n;j++){
      Xor_Sum = Xor_Sum ^ arr[j];
      if(Xor_Sum == m){
        count++;
      }
    }
    return count;
  }
}

// 2)Optimal-Solution

#include<unordered_map>
using namespace std;

long long subarrayXor(int arr[], int n, int m){
unordered_map<int,int>mp;
int Xor_sum = 0;
int count = 0;

for(int i=0;i<n;i++){
      Xor_sum = Xor_sum ^ arr[i];
      if(Xor_sum==m){
        count++;
      }

  int target = Xor_sum ^ m;
   if(mp.find(target)!=mp.end()){
       count+=mp[target];
   }
   mp[Xor_sum]++;
}
return count;
}


