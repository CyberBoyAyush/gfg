//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void DFS(int node, int parent,vector<int>adj[],vector<bool> &artPoint,vector<int> &disc
    ,vector<int> &low,vector<bool> &visited, int &timer){
        
        visited[node] = 1;
        disc[node] = low[node] = timer;
        int child = 0; // keep tarck of child for edge case of root node
        
        // now looking neighbour
        for(auto v : adj[node]){
            int neig = v;
            
            if(neig == parent) continue;
            
            else if(visited[neig]){
                low[node] = min(low[node] , disc[neig]);
            }
            
            else{
                child++; // found a new child
                timer++;
                DFS(neig,node,adj,artPoint,disc,low,visited,timer);
                
                // check Articulation Point condt
                if(disc[node] <= low[neig] & parent != -1){
                    // Articulation Point mil gaya
                    artPoint[node] = 1;
                }
                
                // update low
                low[node] = min(low[node],low[neig]);
            }
        }
        
        if(child > 1 && parent == -1){
            artPoint[node] = 1;
        }
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> artPoint(V,0); // keeps track which node is Articulation Point
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V,0);
        
        int timer = 0; // used to fill low and disc
        
        // call dfs
        DFS(0,-1,adj,artPoint,disc,low,visited,timer);
        
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (artPoint[i]) {
                ans.push_back(i);
            }
        }
            
        if(ans.size()==0){
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends