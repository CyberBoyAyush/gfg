//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        int res = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){ // same
                    dp[i][j] = 1 + dp[i-1][j-1]; // add 1 to prev same
                    res = max(res, dp[i][j]);
                }
                else{ // now same
                    dp[i][j] = 0;
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends