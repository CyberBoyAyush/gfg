//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int solve(int i, int j, int arr[]){
        // base case
        if(i == j){
            // it means there is only 1 matrix
            return 0;
        }
        
        // DP call
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mini = INT_MAX; // stores the final answer
        
        // we create partitions for further call
        // k = i -> j-1 => (i,k) , (k+1,j)
        for(int k = i; k<=j-1; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) +
                        solve(i,k,arr) + solve(k+1,j,arr);
                        
            mini = min(mini,steps);
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(1, N-1, arr); 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends