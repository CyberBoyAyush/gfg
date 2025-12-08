class Solution {
  public:
    // pos[l][r] will store the split index i that gave optimal cost for range (l,r)
    int solve(vector<int> &arr, int l, int r, vector<vector<int>> &dp, vector<vector<int>> &pos){
        if (l + 1 >= r) return 0;
        if (dp[l][r] != INT_MAX) return dp[l][r];

        int cost = INT_MAX;
        for (int i = l + 1; i <= r - 1; ++i) {
            int left = solve(arr, l, i, dp, pos);
            int right = solve(arr, i, r, dp, pos);
            int val = left + right + arr[l] * arr[i] * arr[r];
            if (val < cost) {
                cost = val;
                pos[l][r] = i;
            }
        }
        return dp[l][r] = cost;
    }

    // build parenthesization string for matrices between indices [l, r)
    string buildString(int l, int r, vector<vector<int>> &pos) {
        if (l + 1 == r) {
            // single matrix A_l
            string s;
            s.push_back('A' + l);
            return s;
        }
        
        int k = pos[l][r];
        
        // safety: if pos not filled (shouldn't happen for valid input), return grouped sequence
        if (k == -1) {
            // fallback: concatenate matrices in sequence with parentheses
            string s = "(";
            for (int i = l; i < r; ++i) {
                s.push_back('A' + i);
            }
            s.push_back(')');
            return s;
        }
        
        string left = buildString(l, k, pos);
        string right = buildString(k, r, pos);
        
        return "(" + left + right + ")";
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return "";              // no matrices
        // dp over indices 0..n-1, we consider ranges (l,r) where matrices are between l and r: single matrix when r==l+1
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> pos(n, vector<int>(n, -1));

        // compute minimum cost and fill pos table
        solve(arr, 0, n - 1, dp, pos);

        // build and return parenthesization for range (0, n-1)
        return buildString(0, n - 1, pos);
    }
};

