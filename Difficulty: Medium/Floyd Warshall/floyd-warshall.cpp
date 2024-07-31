//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size(); // size of the matrix or nodes present
	    
	    // Converting all the -1 in matrix to INT_MAX for floyd algo
	    for(int i = 0; i<n ; i++){
	        for(int j = 0; j<n ; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = INT_MAX;
	            }
	        }
	    }
	    
	    // Applying Floyd Warshall ALgorithm
	    for(int via = 0 ; via<n ; via++){
	        // via is our intermediate node
	        for(int i = 0 ; i< n ; i++){
	            for(int j = 0 ; j< n ; j++){
	                // checking for edge case condt
	                if(matrix[i][via] == INT_MAX || matrix[via][j] == INT_MAX) continue;
	                
	                
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    // Now converting all remaning INT_MAX to -1 for final ans
	    for(int i = 0; i<n ; i++){
	        for(int j = 0; j<n ; j++){
	            if(matrix[i][j] == INT_MAX){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends