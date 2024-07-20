// Question==========>>>>>>>>>>>>>>.............2657. Find the Prefix Common Array of Two Arrays
//leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

// 1)Brute-Force

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> ans;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= i; k++) {
                    if (A[j] == B[k]) 
                        count++;
                }
            }

            ans.push_back(count);
            count = 0;
        }
        
        return ans;
    }
};

// explaination===>>

// ### Example Walkthrough

// Let's walk through an example with `A = {1, 2, 3, 4}` and `B = {3, 4, 5, 6}` to see how the function works:

// - **Iteration 1 (`i = 0`)**:
//   - `j, k = 0`: Compare `A[0] = 1` and `B[0] = 3`. No common elements. `count = 0`.

// - **Iteration 2 (`i = 1`)**:
//   - `j, k = 0`: Compare `A[0] = 1` and `B[0] = 3`. No common elements. `count = 0`.
//   - `j, k = 1`: Compare `A[1] = 2` and `B[1] = 4`. No common elements. `count = 0`.

// - **Iteration 3 (`i = 2`)**:
//   - `j, k = 0`: Compare `A[0] = 1` and `B[0] = 3`. No common elements. `count = 0`.
//   - `j, k = 1`: Compare `A[1] = 2` and `B[1] = 4`. No common elements. `count = 0`.
//   - `j, k = 2`: Compare `A[2] = 3` and `B[2] = 5`. One common element. `count = 1`.

// - **Iteration 4 (`i = 3`)**:
//   - `j, k = 0`: Compare `A[0] = 1` and `B[0] = 3`. No common elements. `count = 0`.
//   - `j, k = 1`: Compare `A[1] = 2` and `B[1] = 4`. No common elements. `count = 0`.
//   - `j, k = 2`: Compare `A[2] = 3` and `B[2] = 5`. One common element. `count = 1`.
//   - `j, k = 3`: Compare `A[3] = 4` and `B[3] = 6`. No common elements. `count = 0`.

// - **Final `ans` Vector**:
//   - `ans = {0, 0, 1, 0}`.

// ### Conclusion

// The provided function calculates the number of common elements between prefix arrays `A` and `B` for each prefix length and stores these counts in a vector. However, it has high time complexity O(n^3) due to the nested loops, which makes it inefficient for large input sizes. Optimization could be achieved by using more efficient algorithms such as two-pointer technique or hashmap for counting common elements.

// 2)Optimal Solution

#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> c(n);
        unordered_map<int , int> mp;
        int prevsum=0;
        for(int i=0;i<n;i++)
        {
            if(mp[A[i]] || mp[B[i]] || (A[i]==B[i]))
            {
                if(A[i]==B[i])
                {
                   c[i]=prevsum+mp[A[i]]+mp[B[i]]+1; 
                }
                else
                {
                    c[i]=prevsum+mp[A[i]]+mp[B[i]];
                }
                
            }
            else
            {
                c[i]=0+prevsum;
            }
            prevsum=c[i];
            mp[A[i]]=1;
            mp[B[i]]=1;
            
        }
        return c;    
    }
};

