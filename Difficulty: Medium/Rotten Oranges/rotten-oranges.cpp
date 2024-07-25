//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        /// queue for traversal
        queue<pair<int,int>> q; // {row,col}

        // pushing the rotten oranges at initial
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == 2){
                    // rotten found
                    q.push({i,j});
                }
            }
        }

        // for neighbours -> up | down | left | right
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};

        // traversal
        int timer = -1;
        while(!q.empty()){
            timer++;
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // traverse in neighbours -> up | down | left | right
                for(int k = 0; k<4; k++){
                    int nrow = row + delRow[k];
                    int ncol = col + delCol[k];

                    // check condition
                    if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m
                    && grid[nrow][ncol]==1){
                        // make it rotten
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        // check for any fresh left in grid -> edge case
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == 1){
                    // fresh found
                    return -1;
                }
            }
        }

        return timer < 0 ? 0:timer;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends