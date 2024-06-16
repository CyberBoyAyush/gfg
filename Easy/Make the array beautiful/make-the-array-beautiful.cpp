//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(st.empty()){
                st.push(arr[i]);
            }
            // +ve handling
            else if(arr[i]>=0){
                if(st.top()>=0){
                    st.push(arr[i]);
                }
                else{
                    st.pop();
                }
            }
            
            //-ve handling
            else{
                if(st.top()<0){
                    st.push(arr[i]);
                }
                else{
                    st.pop();
                }
            }
            
        }
        
        vector<int> res(st.size());
        int i =0;
        while(!st.empty()){
            res[i] = st.top();
            st.pop();
            i++;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends