//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9 + 7;
    int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        // base case
        if (index == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || arr[0] == target)
                return 1;
            return 0;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        int notpick = solve(index - 1, target, arr, dp) % mod;
        int pick = 0;
        if (arr[index] <= target)
            pick = solve(index - 1, target - arr[index], arr, dp) % mod;
        return dp[index][target] = (pick + notpick) % mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        
        //Checking for edge cases
        if(totSum-d<0) return 0;
        if((totSum-d)%2==1) return 0;
        
        int s2 = (totSum-d)/2;
        
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return solve(n-1,s2,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends