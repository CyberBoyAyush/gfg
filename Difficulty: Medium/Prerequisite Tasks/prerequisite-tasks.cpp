//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // create adj list and indegree arr
	    vector<int> inDeg(N,0);
	    vector<int> adj[N];
	    
	    for(int i = 0 ;i<P; i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        inDeg[prerequisites[i].first]++;
	    }
	    
	    // apply Kahn's Algo
	    
	    queue<int> q;
	    int cnt = 0;
	    
	    // pushing all indegree 0 el in queue
	    for(int i = 0 ; i<N; i++){
	        if(!inDeg[i])
	            q.push(i);
	    }
	    
	    // traversal
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        
	        // traversing th eneighbours
	        for(auto &v:adj[node]){
	            inDeg[v]--;
	            if(!inDeg[v]){
	                q.push(v);
	            }
	        }
	    }
	    
	    return cnt == N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends