#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
const int MOD = 1e9 + 7;
const int INF = 1e18;

class Solution {
  public:
    vi dp;
    int helper(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int mini=1e9;
        for(int i=1;i*i<=n;i++){
            int cnt=1+helper(n-(i*i));
            mini=min(mini,cnt);
        }
        return dp[n]=mini;
    }
  
    int minSquares(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};