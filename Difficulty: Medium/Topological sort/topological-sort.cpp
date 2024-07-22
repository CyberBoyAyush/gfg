//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public: 
	void DFS(int node,vector<int> adj[], vector<bool> &visited, stack<int> &st){
	    // amrking node as visited
	    visited[node] = 1;
	    
	    // traversal
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            DFS(i,adj,visited,st);
	        }
	    }
	    
	   // pushing value in stack as backtrack
	   st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // visited arr
	    vector<bool> visited(V,0);
	    
	   // stack for storing th elements
	   stack<int> st;
	   
	   // for univisted check
	   for(int i = 0; i<V; i++){
	       if(!visited[i]){
	           DFS(i,adj,visited,st);
	       }
	   }
	   
	   // pushing value of stack in the answer arr
	   vector<int> ans;
	   while(!st.empty()){
	       ans.push_back(st.top());
	       
	       st.pop();
	   }
	   
	   return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends