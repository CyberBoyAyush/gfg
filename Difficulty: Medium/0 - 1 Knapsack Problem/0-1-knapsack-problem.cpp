//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(int idx, int W, vector<int>& wt, vector<int>& val){
      if(idx == 0){
          if(wt[idx] <= W) return val[0];
          else{
              return 0;
          }
      }
      
      int notTake = 0 + solve(idx-1, W, wt, val);
      int Take = INT_MIN;
      if(wt[idx]<=W){
          Take = val[idx] + solve(idx-1,W-wt[idx],wt,val);
      }
      
      return max(Take,notTake);
  }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        return solve(n-1,W,wt,val);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends