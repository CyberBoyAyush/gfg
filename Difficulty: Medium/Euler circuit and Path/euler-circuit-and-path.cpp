//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void DFS(int node, vector<int>adj[], vector<bool> &visited){
        visited[node] = 1; // marking it visited
        
        for(int &v : adj[node]){
            if(!visited[v])
                DFS(v,adj,visited);
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Finding the Degree of every node
	    vector<int> deg(V,0);
	    int oddDegCnt = 0;
	    for(int i = 0 ; i< V; i++){
	        // Calculating the degree
	        deg[i] = adj[i].size();
	        
	        // Calculating the odd deg nodes
	        if(deg[i] % 2 == 1){
	            oddDegCnt++; // if oddDegCnt is != 0 then it cant be a Eulers Circuit
	        }
	    }
	    
	    if(oddDegCnt!=0 && oddDegCnt!=2){
	        // it cant be euler's path also
	        return 0;
	    }   
	    
	    
	    // Now checking all Non Zero nodes should be connected
	    vector<bool> visited(V,0);
	    // DFS
	    for(int i = 0 ; i < V; i++){
	        if(deg[i]!=0){ // degree exists
	            DFS(i,adj,visited);
	            break;
	        }
	    }
	    
	    // if any node with non zero deg is not visited return 0 
	    // EP cant exists
	    for(int i = 0 ; i< V; i++){
	        if(visited[i]==0 && deg[i]!=0){
	            return 0;
	        }
	    }
	    
	    /// Any one of euleriacn cu=ircuit or path will exits
	    if(oddDegCnt==0){
	        return 2; // eulerian circuit
	    }
	    
	    else{
	        // Eulerian path
	        return 1;
	    }
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends