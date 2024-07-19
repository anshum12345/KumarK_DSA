// Question=========>>>>>>>>>>>>>>>..Find the Frequency
// https://www.geeksforgeeks.org/problems/find-the-frequency/1

// 1)Brute-FOrce

#include<vector>
using namespace std;
int findFrequency(vector<int> Arr, int X){
    // Your code here
    int count = 0;
    int n = Arr.size();
    
    for(int i=0;i<n;i++){
       
        if(Arr[i]==X) count++;
    }
    return count;
}

// 2)Optimal-Solution

#include <vector>
#include <unordered_map>
using namespace std;

int findFrequency(vector<int> Arr, int X){
    unordered_map<int, int> mp;
    
    // Count frequencies of each element in Arr
    for (int i = 0; i < Arr.size(); ++i) {
        mp[Arr[i]]++;
    }
    
    // Retrieve the frequency of X from the map
    return mp[X];
}

// explaination==>> isme hm log ek map create kr rhe h unordered_map (mp) naam ka aur isme saari values jo bhi array me h vo rakh rhe h aur uske baad jab frequency store ho gyi then mp[X] kr denge because hme X find krna h kitne time usi se answer aa jayega
