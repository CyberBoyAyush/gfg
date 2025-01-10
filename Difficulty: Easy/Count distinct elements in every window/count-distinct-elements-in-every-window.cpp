//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
    unordered_map<int, int> mpp;

    // Count distinct elements in the first window
    for (int i = 0; i < k; i++) {
        mpp[arr[i]]++;
    }
    ans.push_back(mpp.size());

    // Slide the window across the array
    for (int i = k; i < arr.size(); i++) {
        int elem = arr[i - k];  // Element to remove from the window

        // Remove the element going out of the window
        mpp[elem]--;
        if (mpp[elem] == 0) {
            mpp.erase(elem);  // Erase element if its count becomes zero
        }

        // Add the new element in the window
        mpp[arr[i]]++;

        // Store the count of distinct elements for this window
        ans.push_back(mpp.size());
    }

    return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends