//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
     int dp[101][10001];
    bool solve(vector<int> arr, int index , int sum){
        if(sum == 0)    return true;
        if(index == 0) return(arr[0]==sum);
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool notTake = solve(arr,index-1,sum);
        bool take = false;
        if(arr[index] <= sum){
            take = solve(arr,index-1,sum-arr[index]);
        }
        
        return dp[index][sum] = notTake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr, n-1, sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends