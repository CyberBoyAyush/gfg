//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans;
       vector<int> dArr ;
       for(int i=0;i<n;i++){
       if(arr[i]!=0){
       dArr.push_back(arr[i]);
        }
       }
       
       int m = dArr.size();
       ans.push_back(dArr[0]);
       for(int i=1;i<m;i++){
       if(dArr[i]==ans[ans.size()-1] && dArr[i-1] == dArr[i] && dArr[i]!=0){
       ans[ans.size()-1] += dArr[i];
        }
       else{
            ans.push_back(dArr[i]);
            }
       }
       int s = n - ans.size();
       for(int i=0;i<s;i++){
        ans.push_back(0);
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends