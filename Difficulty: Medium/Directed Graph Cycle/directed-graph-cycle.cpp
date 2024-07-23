//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // DFS Approach 1
    bool detectCycle(int node,vector<int> adj[],vector<bool> &path,vector<bool> &visited){
        // marking path and visited as 1
        path[node] = 1;
        visited[node] = 1;
        
        // traversal 
        for(int &v:adj[node]){
            // checking in path
            if(path[v]){
                // true
                return 1; // cycle detected
            }
            
            // visited for optimal code
            if(visited[v])  continue;
            
            if(detectCycle(v,adj,path,visited)){
                return 1;
            }
        }
        // bactracking me path ko remove krna h
        path[node] = 0;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> path(V,0);; //stores the path
        vector<bool> visited(V,0); // store the visited for optimal code
        
        for(int i = 0 ;i<V ; i++){
            if(!visited[i]){
                if(detectCycle(i,adj,path,visited))
                    return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends