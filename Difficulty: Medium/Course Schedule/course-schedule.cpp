//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
               vector<int> inDeg(N,0);
	    vector<int> adj[N];
	    
	    for(int i = 0 ;i<P; i++){
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	        inDeg[prerequisites[i][0]]++;
	    }
	    
	    // apply Kahn's Algo
	    
	    queue<int> q;
	    vector<int> ans;
	    
	    // pushing all indegree 0 el in queue
	    for(int i = 0 ; i<N; i++){
	        if(!inDeg[i])
	            q.push(i);
	    }
	    
	    // traversal
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        // traversing th eneighbours
	        for(auto &v:adj[node]){
	            inDeg[v]--;
	            if(!inDeg[v]){
	                q.push(v);
	            }
	        }
	    }
	    
        vector<int> temp; // null array
	    return ans.size() == N ? ans : temp;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends