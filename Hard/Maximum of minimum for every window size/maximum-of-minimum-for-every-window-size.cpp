//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n, 0);
        stack<int> st;
        vector<int> right(n, n); // Default next smaller to the right is n
        vector<int> left(n, -1); // Default next smaller to the left is -1

        // Finding next smaller to the right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // Clearing the stack for reuse
        while (!st.empty()) st.pop();
        
        // Finding next smaller to the left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Fill the ans array using left[] and right[]
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }

        // Fill remaining entries
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends