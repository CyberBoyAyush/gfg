//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> mpp; // To store elements and their counts
        
        for (int i = 0; i < arr.size(); ++i) {
            // If the current element already exists in the map and is within distance k, return true
            if (mpp[arr[i]] > 0) {
                return true;
            }

            // Add the current element to the map
            mpp[arr[i]]++;

            // Remove the element that is out of the window (i - k distance away)
            if (i >= k) {
                mpp[arr[i - k]]--;
                if (mpp[arr[i - k]] == 0) {
                    mpp.erase(arr[i - k]);
                }
            }
        }

        return false; // No duplicates within k distance
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
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends