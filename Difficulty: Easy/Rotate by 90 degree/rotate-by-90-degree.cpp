//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int iRow = mat.size();      //size of arr(Row, Column)
        int arr[iRow][iRow];        //data backup purpose    
        
        for(int i = 0;i < iRow;i++)     //Copy all element's
        {
            for(int j = 0;j < iRow;j++)
            {
                arr[i][j] = mat[i][j];
            }
        }
        
        for(int i = 0;i < iRow;i++)     //Paste all element in previous array.
        {
            for(int j = 0;j < iRow;j++)
            {
                mat[iRow-j-1][i] = arr[i][j];
            }
        }

        return;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends