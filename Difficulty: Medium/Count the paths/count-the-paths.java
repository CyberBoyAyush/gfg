class Solution {
    private void initdp(int[] arr){
        for(int i=0;i<arr.length;i++){
            arr[i]=-1;
        }
    }
    private int dfs(ArrayList<ArrayList<Integer>> adjls,int node,
    int dest,int[] dp){
        if(node==dest){
            return 1;
        }
        if(dp[node]!=-1){
            return dp[node];
        }
        int cnt=0;
        for(int i=0;i<adjls.get(node).size();i++){
            int it=adjls.get(node).get(i);
            cnt+=dfs(adjls,it,dest,dp);
        }
        return dp[node]=cnt;
    }
    public int countPaths(int[][] edges,int vertex,
    int src, int dest){
        int n=edges.length;
        ArrayList<ArrayList<Integer>> adjls=new ArrayList<>();
        for(int i=0;i<vertex;i++){
            adjls.add(new ArrayList<>());
        }
        for(int[] it:edges){
            int u=it[0];
            int v=it[1];
            adjls.get(u).add(v);
        }
        int[] dp=new int[vertex+1];
        initdp(dp);
        int ans=dfs(adjls,src,dest,dp);
        return ans;
    }
}