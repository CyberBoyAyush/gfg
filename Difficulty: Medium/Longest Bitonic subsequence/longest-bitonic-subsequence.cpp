//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (n == 1) return 0;  // Edge case when there's only one element.
        vector<int> dp1(n,1); // front inc
        vector<int> dp2(n,1); // back inc
        
        // filling dp1
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j<i ; j++){
                if(nums[i] > nums[j]){
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
                }
            }
        }
        
        // filling dp2
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = n-1; j>i ; j--){
                if(nums[i] > nums[j]){
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
                }
            }
        }
        
        // finding the max of both
        int maxi = 0;
        for(int i = 0; i< n ; i++){
            if(dp1[i]!=1 && dp2[i]!=1) 
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends