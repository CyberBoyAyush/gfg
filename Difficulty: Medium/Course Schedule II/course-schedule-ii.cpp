class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> pre) {
        // code here
        vector<int> adj[n];
        vector<int> ind(n,0);
        for( int i =0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int> q;
        for( int i =0;i<n;i++){
            if(ind[i]==0)
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int i = q.front();
            ans.push_back(i);
           q.pop();
           for(auto & k : adj[i]){
               ind[k]--;
               if(ind[k]==0)q.push(k);
           }
        }
        if(ans.size()==n) return ans;
        else return {};
    }
};

