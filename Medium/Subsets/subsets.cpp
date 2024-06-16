//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans){

        // BAse Case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        solve(nums,output,index+1,ans);

        // include
        output.push_back(nums[index]);
        solve(nums,output,index+1,ans);
        output.pop_back();

    }
  public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums,output,index,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends