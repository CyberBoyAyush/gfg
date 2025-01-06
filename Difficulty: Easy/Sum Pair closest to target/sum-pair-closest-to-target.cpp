//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
       vector<int> ans;
        if(arr.size()<2)  return ans;
        sort(arr.begin(),arr.end());
        int start=0,end=arr.size()-1,diff=INT_MAX;
        while(start<end){
            int sump=arr[start]+arr[end];
            int cdiff=abs(target-sump);
            if(cdiff<diff){
                ans={arr[start],arr[end]};
                diff=cdiff;
            }
            if(sump>target)  end--;
            else    start++;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends