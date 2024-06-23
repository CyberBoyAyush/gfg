//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int * nums1, int * nums2, int m, int n, int k)
    {
       // Ensure nums1 is smaller or equal in size compared to nums2
        if (m > n) {
            return kthElement(nums2, nums1, n, m, k);
        }
        
        // Binary search on nums1 array
        int low = max(0, k - n);
        int high = min(k, m);
        
        while (low <= high) {
            int mid1 = low + (high - low) / 2; // Partition in nums1
            int mid2 = k - mid1; // Corresponding partition in nums2
            
            // Get boundary values
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n) ? INT_MAX : nums2[mid2];
            
            // Check if partition is correct
            if (l1 <= r2 && l2 <= r1) {
                // Found the kth element
                return max(l1, l2);
            } else if (l1 > r2) {
                // Adjust binary search range
                high = mid1 - 1;
            } else {
                // Adjust binary search range
                low = mid1 + 1;
            }
        }
        
        // If not found (should not happen as per problem constraints)
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends