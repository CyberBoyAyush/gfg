//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  // Recursive Way Same TC AND SC but segmentation fault (GFG Test cases are trash
    // void BST(int *arr,int &idx,int low,int high, int N){
    //     if(idx == N || arr[idx]<low || arr[idx]>high){
    //         return;
    //     }
        
    //     //LNR
    //     int val = arr[idx++];
    //     BST(arr,idx,low,val,N);
    //     BST(arr,idx,val,high,N);
    // }
    // int canRepresentBST(int arr[], int N) {
    //     int idx = 0;
    //     BST(arr,idx,INT_MIN,INT_MAX,N);
    //     return idx == N;
    // }
    
    // Iterative Way using 2 Stacks
    int canRepresentBST(int arr[], int N){
        stack<int> lower,upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        
        int left, right;
        
        for(int i = 0;i<N;i++){
            if(arr[i]<lower.top()){
                return 0;
            }
            
            while(arr[i]>upper.top()){
                upper.pop();
                lower.pop();
            }
            
            // range me h
            left = lower.top();
            right = upper.top();
            upper.pop();
            lower.pop();
            
            //right side
            lower.push(arr[i]);
            upper.push(right);
            
            //left side
            lower.push(left);
            upper.push(arr[i]);
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends