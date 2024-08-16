//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int maxRemove(vector<vector<int>>& stones, int n) {
        parent.resize(n);
        rank.resize(n);

        // parent and rank intiialization
        for(int i = 0 ; i< n ; i++){ 
            parent[i] = i;
            rank[i] = 0;
        }


        // creating components (groups)
        for(int i = 0 ; i<n ; i++){
            for(int j = i+ 1; j<n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j);
                }
            }
        }

        // finding groups creater (number)

        int groups = 0;
        for(int i = 0 ; i< n ; i++){
            if(parent[i] == i) groups++;
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