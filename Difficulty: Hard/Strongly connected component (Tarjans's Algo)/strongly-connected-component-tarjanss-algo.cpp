//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
	void DFS(int node,vector<int> adj[],vector<bool> &visited,
	vector<int> &disc,vector<int> &low,stack<int> &st,
	vector<bool>&inStack,vector<vector<int>>&ans,int &timer){
	    
	    visited[node] = 1;
	    disc[node] = low[node] = timer;
	    st.push(node);
	    inStack[node] = 1;
	    
	    // go in neighbuors
	    for(auto &neig : adj[node]){
	        if(!visited[neig]){
	            timer++;
	            DFS(neig,adj,visited,disc,low,st,inStack,ans,timer);
	            low[node] = min(low[node],low[neig]);
	        }
	        else{
	            // neig already visited
	            // check 1 -> if it is present in stakc or not
	            if(inStack[neig]){
	                low[node] = min(low[node],disc[neig]);
	            }
	        }
	    }
	    
	    if(disc[node] == low[node]){
	        vector<int> temp;
	        while(!st.empty() && st.top() != node){
	            temp.push_back(st.top());
	            inStack[st.top()] = 0; // mark not in stack
	            st.pop();
	        }
	        
	        // now popping node elment outside stack
	        temp.push_back(node);
	        inStack[node] = 0;
	        st.pop();
	        
	        sort(temp.begin(),temp.end()); // it needs ans in sorted way
	        
	        ans.push_back(temp); // pushing in final ans
	    }
	}
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V,0);
        vector<bool> inStack(V,0);
        stack<int> st;
        
        int timer = 0;
        
        for(int i = 0; i<V ; i++){
            if(!visited[i]){
                DFS(i,adj,visited,disc,low,st,inStack,ans,timer);
            }
        }
        
        sort(ans.begin(),ans.end()); // we need ans in sorted
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends