//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int delRow[8] = {2,2,-2,-2,1,-1,1,-1};
    int delCol[8] = {1,-1,1,-1,2,2,-2,-2};
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    
	    // making given values 0 based indexing
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]){
	        return 0;
	    }
	    // We do BFS Traversal in it
	    queue<pair<int,int>> q;
	    vector<vector<bool>> chess(N, vector<bool> (N,0));
	    
	    // Pushing the position of Knight in chess ans queue
	    q.push({KnightPos[0],KnightPos[1]});
	    chess[KnightPos[0]][KnightPos[1]] = 1; // visited marked
	    
	    int steps = 0;
	    
	    while(!q.empty()){
	        int size = q.size();
	        while(size --){
	            int row = q.front().first;
	            int col = q.front().second;
	            q.pop();
	            
	            // Going in neighbour directions 8
	            for(int i = 0 ; i<8; i++){
	                int nrow = row + delRow[i];
	                int ncol = col + delCol[i];
	                
	                if(nrow == TargetPos[0] && ncol == TargetPos[1]){
	                    return steps + 1;
	                }
	                
	                // Checking for valid and condt
	                if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < N
	                && !chess[nrow][ncol]){
	                    q.push({nrow,ncol}); //push in queue
	                    chess[nrow][ncol] = 1; // visited
	                }
	                
	            }
	        }
	        steps ++;
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends