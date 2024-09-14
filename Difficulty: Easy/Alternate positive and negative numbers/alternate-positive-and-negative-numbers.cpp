//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> pos;
        vector<int> neg;
        
        for(auto it:arr){
            if(it>0 || it == 0){
                // pos
                pos.push_back(it);
            }
            else neg.push_back(it);
        }
        
        vector<int> res;
        
        int i = 0;
        int j = 0;
        bool flag = true;
        while(i<pos.size() && j<neg.size()){
            if(flag){
                res.push_back(pos[i]); 
                i++;
                
            }
            else{
                res.push_back(neg[j]); 
                j++;
                
            }
                
            flag = !flag;
        }
        
        while(i<pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        while(j<neg.size()){
            res.push_back(neg[j]);
            j++;
        }
        
        for(int idx = 0; idx<arr.size(); idx++){
            arr[idx] = res[idx];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends