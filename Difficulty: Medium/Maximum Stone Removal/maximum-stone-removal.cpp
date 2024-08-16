//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void dfs(int node, vector<bool> &visited, vector<vector<int>>& stones){
    visited[node] = 1;
    for(int i = 0 ; i<stones.size(); i++){
        int r = stones[node][0];
        int c = stones[node][1];
        if(!visited[i] && (stones[i][0] == r || stones[i][1] == c)){
            dfs(i,visited,stones);
        }
    }
}
    int maxRemove(vector<vector<int>>& stones, int n) {
        vector<bool> visited(n,0);

        int groups = 0; // keeps track of group

        // dfs on not visited
        for(int i = 0; i<n; i++){
            if(visited[i]){
               continue; 
            }
            dfs(i,visited,stones);
            groups++;
        }
        return n - groups;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends