//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(int n , vector<int>& arr, int& k, vector<int> &dp){
        if (n == 0) return 0;
        if(dp[n] != -1)  return dp[n];
        int mmSteps = INT_MAX;
        for(int j = 1 ; j<=k ; j++){
            if(n - j >= 0){
                int jump = solve(n-j , arr,k,dp) + abs(arr[n] - arr[n-j]);
                mmSteps = min(mmSteps,jump);
            }
            
        }
        return dp[n] = mmSteps;
    }
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(n-1,arr,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends