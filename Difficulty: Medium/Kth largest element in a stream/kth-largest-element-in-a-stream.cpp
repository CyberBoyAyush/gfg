//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
       priority_queue<int,vector<int>,greater<int>>p;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            p.push(arr[i]);
            if(p.size()<k)
            {
                ans.push_back(-1);
            }
            else
            {
                while(p.size()>k)
                p.pop();
                ans.push_back(p.top());
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends