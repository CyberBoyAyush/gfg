class Solution {
  public:
    int CollectCoins(vector<vector<int>> &mat, int row,int col, vector<vector<int>> &dp){
        if(row >= mat.size() or col>=mat[0].size()){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        int TopRight = CollectCoins(mat, row-1, col+1, dp);
        int Right = CollectCoins(mat, row, col+1, dp);
        int BottomRight = CollectCoins(mat, row+1, col+1, dp);
        
        return dp[row][col] = max(TopRight, max(Right, BottomRight)) + mat[row][col];
    }
    int maxGold(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(),-1));
        
        int Sol = 0;
        for(int i = 0;i<mat.size();i++){
            Sol = max(Sol, CollectCoins(mat, i, 0, dp));
        }
        
        return Sol;
    }
};