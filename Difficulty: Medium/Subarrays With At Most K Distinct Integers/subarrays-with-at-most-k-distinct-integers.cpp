class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        map<int, int> mp;  // To store frequency of elements in the current window
        int ans = 0;       // To store the total count of valid subarrays
        int prev = 0;      // Left boundary of the sliding window

        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++;  // Include current element in the window

            // If distinct elements ≤ k, all subarrays ending at 'i' are valid
            if (mp.size() <= k) {
                int cnt = i - prev + 1;  // Number of new valid subarrays
                ans += cnt;
            }

            // If distinct elements exceed k, shrink the window from the left
            while (mp.size() > k) {
                mp[arr[prev]]--;        // Decrement count of leftmost element
                if (mp[arr[prev]] == 0) // If count drops to zero, remove it
                    mp.erase(arr[prev]);
                prev++;                 // Move the left boundary

                // After shrinking, check if condition is satisfied again
                if (mp.size() <= k) {
                    int cnt = i - prev + 1;  // New valid subarrays after shrinking
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};