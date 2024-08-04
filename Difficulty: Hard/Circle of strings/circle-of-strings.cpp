//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = 1;
        
        for(int &v:adj[node]){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // Creating edges on the basis of first nad last char
        
        // Adj list adn finding inDeg and outDeg 
        vector<int> adj[26];
        vector<int> inDeg(26,0);
        vector<int> outDeg(26,0);
        for(int i = 0 ; i<N ; i++){
            string temp = A[i];
            int u = temp[0] - 'a'; // converting in int
            int v = temp[temp.size()-1] - 'a';
            adj[u].push_back(v);
            outDeg[u]++;
            inDeg[v]++;
        }
        
        // Checking for eulerian circuit
        for(int i = 0 ; i<26; i++){
            if(inDeg[i] != outDeg[i]){
                return 0; // EC not present
            }
        }
        
        // Check for all edges aprt of single components
        vector<bool> visited(26,0);
        int node = A[0][0] - 'a'; // sending first node
        DFS(node,adj,visited);
        
        for(int i = 0 ; i<26 ; i++){
            if(inDeg[i] != 0 && visited[i] == 0){
                return 0 ; // ec does not exists
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends