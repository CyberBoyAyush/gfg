//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // craeting expolored and dist arr
        vector<bool> Explored(V,0); // bool vector for explore track
        vector<int> dist(V,INT_MAX); 
        dist[S] = 0; // dist from Source to source
        int count = V;
        while(count--){
            // selecting a node which is unexplored and its dist is minimum
            int node = -1; // initial node 
            int value = INT_MAX; // initial value
            
            for(int i = 0; i<V; i++){
                if(!Explored[i] && value > dist[i]){
                    // initializing the new values
                    node = i;
                    value = dist[i];
                }
            }
            
            Explored[node] = 1; // marking node as explored
            
            // relax the edges
            for(int v = 0 ; v < adj[node].size(); v++){
                int neighbour = adj[node][v][0];
                int weight = adj[node][v][1];
                
                // condition check
                if(!Explored[neighbour] &&
                weight + dist[node] < dist[neighbour]){
                    dist[neighbour] = weight + dist[node];
                }
            }
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends