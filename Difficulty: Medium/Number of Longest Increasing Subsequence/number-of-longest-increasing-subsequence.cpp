//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < dp[j] + 1){
                        // update dp
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j] + 1 == dp[i]){
                        // increase count in count arr
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int maxVal = *max_element(dp.begin(),dp.end());
        int finalCount = 0;

        for(int i = 0; i< n ; i++){
            if(dp[i] == maxVal){
                finalCount += cnt[i];
            }
        }

        return finalCount;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends