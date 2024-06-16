//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void findFactorialNumbers(long long N, long long currentFactorial, int i, vector<long long>& result) {
    // Base case: if the current factorial is 
    //greater than N, stop recursion
    if (currentFactorial > N) {
        return;
    }
    
    // Add the current factorial to the result vector
    result.push_back(currentFactorial);
    
    // Calculate the next factorial and recurse
    findFactorialNumbers(N, currentFactorial * (i + 1), i + 1, result);
}

vector<long long> factorialNumbers(long long N) {
    vector<long long> result;
    findFactorialNumbers(N, 1, 1, result); // Start with 1! = 1 and i = 1
    return result;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends