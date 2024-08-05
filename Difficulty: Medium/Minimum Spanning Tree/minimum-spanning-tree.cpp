//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	typedef pair<int,pair<int,int>> P;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Priroty_queue
        priority_queue<P, vector<P> , greater<P>> pq; // minheap
        vector<bool> isMST(V,0);
        vector<int> Parent(V); // temp not needed
        
        int cost = 0;
        
        // psuhing details in pq
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second.first;
            int par = p.second.second;
            
            if(!isMST[node]){
                isMST[node] = 1;
                cost += wt;
                Parent[node] = par;
                
                // going in neighbours
                for(auto &v:adj[node]){
                    int neighbour = v[0];
                    int weight = v[1];
                    // if the neighbour is not apart of out mst then we push it ij queue
                    if(!isMST[neighbour]){
                        pq.push({weight,{neighbour,node}});
                    }
                }
            }
        }
        return cost;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends