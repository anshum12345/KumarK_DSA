// https://www.desiqna.in/16820/amazon-oa-sde-ctc-45lpa-coding-questions-2024-set-141

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int minOperationsToDestroyArray(vector<int>& arr) {
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }
 
    int minOperations = 0;
    for (auto& entry : freqMap) {
        int freq = entry.second;
        if (freq == 1) {
            return -1; // According to Tariquddin’s law
        } else {
            // According to Tanmai’s Law
            minOperations += freq / 3 + (freq % 3 != 0);
        }
    }
    return minOperations;
}
 
int main() {
    vector<int> arr = {1, 5, 5, 1, 1, 8, 8, 10, 10};
    int minOps = minOperationsToDestroyArray(arr);
    if (minOps == -1) {
        cout << "It's not possible to destroy the array" << endl;
    } else {
        cout << "Minimum number of operations to destroy the array-> " << minOps << endl;
    }
    return 0;
}

// Output==>>Minimum number of operations to destroy the array-> 4