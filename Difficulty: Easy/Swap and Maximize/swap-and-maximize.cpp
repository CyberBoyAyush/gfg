//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>narr(n);
        int i=0;
        int j=n-2;
        int count=0;
        while(i<=j){
            if(count%2==0){
                narr[count]=arr[i];
                i++;
            }
            else{
                narr[count]=arr[j];
                j--;
            }
            count++;
        }
        
        narr[count]=arr[n-1];
        
        long long sum=0;
        for(int k=1;k<n;k++){
            sum+=abs(narr[k]-narr[k-1]);
        }
        sum+=abs(narr[n-1]-narr[0]);
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends