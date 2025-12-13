class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int n = (int)mat.size();
        for(int i = 0; i<n; ++i) {
            int temp = mat[i][i];
            mat[i][i] = mat[i][n-i-1];
            mat[i][n-i-1] = temp;
        }
    }
};