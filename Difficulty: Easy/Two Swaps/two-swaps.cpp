//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int count = 0;
        bool flag = false;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != i + 1) {
                count++;
                if(i + 1 == arr[arr[i] - 1]) {
                    flag = true;
                }
            }
        }
        
        return (count == 0 || count == 3 || (count == 4 && flag));
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends