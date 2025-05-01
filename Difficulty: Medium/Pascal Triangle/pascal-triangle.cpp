//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
     vector<int> nthRowOfPascalTriangle(int n) {
      if( n == 1 ) return {1} ;
      vector< vector< int >>dp( n , vector<int >( n , 0 )) ;
       for( int i = 1 ; i < n; i++ )
       {
           for( int j = 0 ; j < i+1 ; j++ )
           {
               if( j == 0 ) dp[i][j] = 1 ;
               else if( j == i ) dp[i][j] = 1 ;
               else  dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ;
           }
       }
       
       return dp[n-1] ;
    }


};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends