//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define ll long long

    int mod = 1003;

    long long solve(int i, int j, bool isTrue, string & exp, vector<vector<vector<ll>>> &dp){
        // base case
    
        if(i > j){
            return 0;
        }
    
        if(i == j){ // single element
            if(isTrue == 1){ // we need true
                return exp[i] == 'T';
            }
            else{ // we need false
                return exp[i] == 'F';
            }
        }
        
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
    
        long long ways = 0;
    
        for(int idx = i+1; idx<=j-1; idx = idx+2){
            ll lt = solve(i,idx-1,1,exp,dp);
            ll lf = solve(i,idx-1,0,exp,dp);
            ll rt = solve(idx+1,j,1,exp,dp);
            ll rf = solve(idx+1,j,0,exp,dp);
    
            if(exp[idx] == '&'){
                if(isTrue) ways = (ways + (lt * rt) % mod) % mod;
                else    ways = (ways + (lt * rf)% mod + (lf*rt) % mod + (lf * rf) % mod) % mod;
            }
            else if(exp[idx] == '|'){
                if(isTrue) ways = (ways + (lt * rt)% mod + (lf*rt) % mod + (lt * rf) % mod) % mod;
                else    ways = (ways + (lf * rf) % mod) % mod;
            }
            else{ // '^' xor
                if(isTrue){
                    ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else{
                    ways = (ways + (lt * rt) % mod + (lf * rf) % mod)%mod;
                }
            }
        }
    
        return dp[i][j][isTrue] = ways;
    
    }
    int countWays(int n, string s){
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return solve(0,n-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends