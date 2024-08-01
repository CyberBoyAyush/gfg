//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int delRow[4] = {1,-1,0,0};
    int delCol[4] = {0,0,1,-1};
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        // BFS 
        queue<pair<int,int>> q;
        
        // Finding the source
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< n ;j++){
                if(grid[i][j] == 1){
                    // Pushing source in queue
                    q.push({i,j});
                    // making in visityyed
                    grid[i][j] = 0;
                    
                    // edge case
                }
            }
        }
        
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0 ; i< 4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
            
                
                // check condt
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    
                    if(grid[nrow][ncol] == 2) return true;
                    
                    if(grid[nrow][ncol] != 0){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] == 0;
                    }
                }
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends