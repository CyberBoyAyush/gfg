//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int idx,int W, int val[], int wt[]){
        // Base case
        if (idx == 0) {
            if (wt[0] <= W) {
                return (W / wt[0]) * val[0];  // Only pick if wt[0] fits in W
            } else {
                return 0;  // If wt[0] is too large, no value can be picked
            }
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int notPick = 0 + solve(idx-1,W,val,wt);
        int pick = INT_MIN;
        if(wt[idx] <= W){
            pick = val[idx] + solve(idx,W-wt[idx],val,wt);
        }
        
        return dp[idx][W] = max(pick,notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(N-1,W,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends