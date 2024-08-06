//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	// Appraoch 1 : Prim's Algorithm
// 	typedef pair<int,pair<int,int>> P;
// 	//Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         // Priroty_queue
//         priority_queue<P, vector<P> , greater<P>> pq; // minheap
//         vector<bool> isMST(V,0);
//         vector<int> Parent(V); // temp not needed
        
//         int cost = 0;
        
//         // psuhing details in pq
//         pq.push({0,{0,-1}});
        
//         while(!pq.empty()){
//             auto p = pq.top();
//             pq.pop();
            
//             int wt = p.first;
//             int node = p.second.first;
//             int par = p.second.second;
            
//             if(!isMST[node]){
//                 isMST[node] = 1;
//                 cost += wt;
//                 Parent[node] = par;
                
//                 // going in neighbours
//                 for(auto &v:adj[node]){
//                     int neighbour = v[0];
//                     int weight = v[1];
//                     // if the neighbour is not apart of out mst then we push it ij queue
//                     if(!isMST[neighbour]){
//                         pq.push({weight,{neighbour,node}});
//                     }
//                 }
//             }
//         }
//         return cost;
//     }

    // Approach 2 -> Krushkal's Algorithm
    
    // find Parent Function
    int findParent(int u , vector<int> &parent){
        if(u==parent[u]){
            return u;
        }
        
        // Asiigning for path compression
        return parent[u] = findParent(parent[u], parent);
    }
    
    // union by rank for check and merge
    void unionByRank(int u, int v , vector<int> &parent,vector<int> &rank){
        // Finding ultimate parent of u and v
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);
        
        // Rank or merge
        if(rank[pu] > rank[pv]){
            parent[pv] = pu; // pv pu me merge hoga
        }
        
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv; // pu pv me merge hoga
        }
        
        else{
            // kisi ko bhi merge kardo
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    typedef pair<int,pair<int,int>> P;
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<int> parent(V);
        vector<int> rank(V,0);
        
        // Marking parent of every node itself
        for(int i = 0 ; i< V ; i++){
            parent[i] = i;
        }
        
        // Priority Queue
        // {wt , {u,v} }
        priority_queue<P , vector<P> , greater<P>> pq;
        
        // Pushing details in pq
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j][0];
                int wt = adj[i][j][1];
                pq.push({wt, {i, v}});
            }
        }
        
        int cost = 0;
        int edges = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            // Check if they are in same or diff set
            if(findParent(u,parent) != findParent(v,parent)){
                cost += wt;
                unionByRank(u,v,parent,rank);
                edges ++;
            }
            
            if(edges == V-1){
                break;
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