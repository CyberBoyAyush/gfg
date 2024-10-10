//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> dp(n, 1);    // dp[i] stores the length of LIS ending at index i
        vector<int> hash(n);     // hash[i] stores the index of the previous element in LIS
        
        int maxLen = 1;          // Stores the length of the longest LIS found
        int lastIdx = 0;         // Stores the last index of the LIS

        // Initialize the hash vector with each element pointing to itself
        for(int i = 0; i < n; i++) {
            hash[i] = i;
        }

        // Calculate dp values and maintain the hash for LIS reconstruction
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;  // Mark j as the previous element of i in the LIS
                }
            }
            // Update the maximum length and last index of the LIS
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        // Reconstruct the LIS from the hash and lastIdx
        vector<int> temp;
        temp.push_back(nums[lastIdx]);  // Push the last element of the LIS
        
        while(hash[lastIdx] != lastIdx) {  // Trace back using the hash array
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);  // Push the corresponding element
        }
        
        reverse(temp.begin(), temp.end());  // Reverse the sequence to get the correct order
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends