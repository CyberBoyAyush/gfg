//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void DFS(int node, vector<int> adj[] , vector<bool> &visited, vector<int> &ans){
        // make visited
        visited[node] = 1;
        ans.push_back(node);
        
        for(int j = 0; j < adj[node].size() ; j++){
            // checking if it is visited or not
            if(!visited[adj[node][j]]){
                // not present
                DFS(adj[node][j] , adj, visited, ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans; // for returning ans
        
        vector<bool> visited(V); // for keeping track of visited nodes
        
        DFS(0,adj,visited,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends