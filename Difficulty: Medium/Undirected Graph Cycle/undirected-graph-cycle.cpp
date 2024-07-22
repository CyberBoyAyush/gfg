//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detectCycle(int node, int parent, vector<int> adj[], vector<bool> &visited){
        // mark the node as visited
        visited[node] = 1;
        
        // traverse in other nodes
        for(auto i : adj[node]){
            // parent node
            if(parent == i){
                continue;
            }
            
            // visited node dubara visit hua
            if(visited[i]){
                return 1; // loop mil gya
            }
            
            // not visited
            // recursive call 
            if(!visited[i]){
                if (detectCycle(i, node, adj, visited)) {
                return true;
                }
            }
        }
        return 0;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,0);
        
        for(int i = 0; i<V;i++){
            if(!visited[i] && detectCycle(i,-1,adj,visited)){
                return 1;
            }
        }
        return 0;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends