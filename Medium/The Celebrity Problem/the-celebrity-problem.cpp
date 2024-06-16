//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        // Push all people to the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // Narrow down to one candidate
        while (st.size() > 1) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            
            if (M[first][second]) {
                // If first knows second, first cannot be a celebrity
                st.push(second);
            } else {
                // If first does not know second, second cannot be a celebrity
                st.push(first);
            }
        }
        
        if (st.empty()) {
            return -1;
        }
        
        // Recheck if the remaining candidate is actually a celebrity
        int candidate = st.top();
        st.pop();
        
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                    return -1;
                }
            }
        }
        
        return candidate;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends