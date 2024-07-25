//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,unordered_map<int,vector<int>> &adj,vector<bool>& vis){
        vis[node] = 1;

        // traversal
        for(int &v : adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> isConnected, int n) {
        int cnt = 0; // stores the cnt
        // make adj list from matrix
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,0);

        // dfs call
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends