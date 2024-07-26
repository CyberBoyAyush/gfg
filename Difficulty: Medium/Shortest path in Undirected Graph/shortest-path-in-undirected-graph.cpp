//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // create adj list
            // map
        unordered_map<int,vector<int>> adj;
            // pushing data in it
        for(int i = 0 ; i< M ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            // mapping
            adj[u].push_back(v); // u->v
            adj[v].push_back(u); // v->u
        }    
        
        // creating visited arr and dist array
        vector<int> dist(N,-1);
        vector<bool> vis(N,0);
        
        // creating queue and pushing its value in it
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        dist[src] = 0;
        
        // bfs tarversal
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //go to neighbours
            for(int & v : adj[node]){
                // check if it is visited or not
                if(vis[v])  continue;
                
                vis[v] = 1;
                q.push(v);
                dist[v] = dist[node] + 1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends