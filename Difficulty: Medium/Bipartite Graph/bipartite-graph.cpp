//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool BFS(int node,vector<int>adj[],vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node] = 0; // initial colour as 0
        
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            
            for(int &v:adj[vertex]){
                // colour not assigned
                if(color[v]==-1){
                    color[v] = (color[vertex] + 1) % 2;
                    q.push(v);
                }
                // color assigned
                if(color[v]==color[vertex]){
                    return 0;
                }
            }
        }
        return 1;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i = 0; i<V;i++){
            if(color[i]==-1){
                if(!BFS(i,adj,color))    return 0;
            }
	    }
	    return 1;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends