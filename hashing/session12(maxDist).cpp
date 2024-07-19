// Question========>>>>>>>>>>>>>>>>..Maximum distance between two occurrences of same element in array
// https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/

// 1)optimal-Force

#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    // your task is to complete this function
  int maxDistance(int arr[], int n)  {
    unordered_map<int, int> pos;
    int m = 0;
    for(int i=0; i<n; i++) {
        if(pos.find(arr[i]) == pos.end())
            pos[arr[i]] = i;
        else
            m = max(m, i - pos[arr[i]]);
    }
    return m;

    }
};