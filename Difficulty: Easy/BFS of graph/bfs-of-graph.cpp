//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // we need queue for traversal and visited arr
        queue<int> q;
        vector<bool> visited(V,0);
        
        // as we know that graph starts from 0 -> given in ques
        q.push(0);
        visited[0]=1;
        
        //for ans
        vector<int>ans;
        
        int node;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            ans.push_back(node);
            
            //pushing the connected nodes in queue
            for(int j = 0; j < adj[node].size() ; j++){
                // chekcing for condition
                if(!visited[adj[node][j]]){
                    // node is good to take
                    q.push(adj[node][j]);
                    visited[adj[node][j]] = 1;
                }
            }   
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends