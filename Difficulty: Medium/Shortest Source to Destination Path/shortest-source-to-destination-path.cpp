//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int delRow[4] = {1,-1,0,0};
    int delCol[4] = {0,0,1,-1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // Edge cases
        if(X == 0 && Y == 0)    return 0; // source is the dest
        if(A[0][0]==0)  return -1; //no path exists
        
        // Queue for bfs traversal
        queue<pair<int,pair<int,int>>> q; // {row,{col,distance}}
        
        vector<vector<int>> visited(N , vector<int>(M,0)); 
        
        q.push({0,{0,0}});
        
        visited[0][0] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();
            
            // Checking the neighbours -> L,R,U,D
            for(int i = 0 ; i<4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                // Condt check
                if(nrow>=0 && nrow < N && ncol >= 0 && ncol < M
                && A[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    
                    // If we reached our dest
                    if(nrow == X and ncol == Y){
                        return steps + 1;
                    }
                    
                    visited[nrow][ncol] = 1;
                    q.push({nrow , {ncol,steps+1}});
                }
            }
            
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends