//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countWays(string &digits) {
        int n = digits.size();
        
        // Edge Case: Check for invalid '0's
        for(int i = 0; i < n; ++i) {
            if(digits[i] == '0') {
                // A '0' is only valid if it's preceded by '1' or '2'
                if(!(i > 0 && (digits[i-1] == '1' || digits[i-1] == '2'))) {
                    return 0; // Invalid string
                }
            }
        }
        
        // DP array to store the number of ways to decode the string up to each index
        vector<int> dp(n + 1, -1);
        dp[n] = 1; // Base case: one way to decode an empty string
        
        // Iterate from the end of the string to the beginning
        for(int idx = n - 1; idx >= 0; --idx) {
            int ans = 0;
            
            // Consider single-digit and double-digit possibilities
            for(int i = 1; i <= 2; ++i) {
                if(idx + i <= digits.size()) {
                    int num = stoi(digits.substr(idx, i)); // Extract the number
                    
                    // If the number is 0, break (invalid)
                    if(num == 0) break;
                    
                    // If the number is between 1 and 26, it's a valid character
                    if(num >= 1 && num <= 26) {
                        ans += dp[idx + i]; // Add the number of ways from the next index
                    }
                }
            }
            
            dp[idx] = ans; // Store the result in the DP array
        }
        
        return dp[0]; // The answer is the number of ways to decode the entire string
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends