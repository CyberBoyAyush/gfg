//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // Creating adj list
        vector<pair<int,int>> adj[V+1]; // v+1 bcz 1 based indexing
        // neighbour weight
        
        //pushing values in adj list
        for(int i = 0 ; i<m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        // Dijkstra Algorithm
        vector<bool> Explored(V+1,0);
        vector<int> dist(V+1,INT_MAX);
        vector<int> parent(V+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        dist[1] = 0;
        parent[1] = -1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(Explored[node] == 1) continue;
            
            Explored[node] = 1; //mark it visited
            
            // relax the edges
            for(auto &v:adj[node]){
                int neighbour = v.first;
                int weight = v.second;
                
                // condt check
                if(!Explored[neighbour] &&
                weight + dist[node] < dist[neighbour]){
                    
                    // updating min weight
                    dist[neighbour] = weight + dist[node];
                    
                    //pushing in pq
                    pq.push({dist[neighbour] , neighbour});
                    
                    // updating parent
                    parent[neighbour] = node; // node will be parent for neighbour
                    
                }
            }
        }
        
        // path creation -> final ans
        vector<int> path;
        if(parent[V] == -1){
            // no path exists
            path.push_back(-1);
            return path;
        }
        int dest = V;
        
        while(dest != -1){
            path.push_back(dest);
            dest = parent[dest];
        }
        
        path.push_back(dist[V]);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends