//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(int idx,int N, int price[]){
        // base case
        if(idx == 0){
            return N * price[0];
        }
        
        if(dp[idx][N] != -1){
            return dp[idx][N];
        }
        
        // take and not take
        int notTake = 0 + solve(idx-1,N,price);
        int take = INT_MIN;
        int rodLength = idx+1; // as indexing is 0 based
        if(rodLength <= N){
            take = price[idx] + solve(idx,N-rodLength,price);
        }
        
        return dp[idx][N] = max(take,notTake);
    }
    int cutRod(int price[], int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n-1,n,price);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends