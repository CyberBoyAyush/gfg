//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        int low = 0, high = n - 1;  // Initialize low and high pointers
        int ans = INT_MAX;  // Initialize answer with maximum value
        
        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the middle index
            
            // Update the current minimum value
            ans = min(ans, arr[mid]);
            
            // Check if the left segment is sorted
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);  // Compare with the start of the left segment
                low = mid + 1;  // Move to the right segment
            } 
            // Otherwise, the right segment is sorted
            else {
                ans = min(ans, arr[mid + 1]);  // Compare with the start of the right segment
                high = mid - 1;  // Move to the left segment
            }
        }
        
        return ans;  // Return the minimum element found
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends