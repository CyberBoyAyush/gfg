//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        
        int cnt=0;
        unordered_map<int, int>mpp;
        
        for(int i=0; i<n; i++){
            if(mpp.find(target-arr[i])!=mpp.end()){
                cnt+=mpp[target-arr[i]];
            }
            mpp[arr[i]]++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends