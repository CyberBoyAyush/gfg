//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int left=0, right=mat[0].size()-1; // last column
        int top=0, bottom=mat.size()-1; // last row
        vector<int>ans;
        while(left<=right && top<=bottom){
            //step1
           for(int i=left; i<=right; i++){
              ans.push_back(mat[top][i]);
           }
           top++;
            //step2
           for(int i=top;i<=bottom;i++){
               ans.push_back(mat[i][right]);
           }
           right--;
           if(top<=bottom){ //step3
               for(int i=right;i>=left;i--){
                   ans.push_back(mat[bottom][i]);
                }
               bottom--; 
            }
            if(left<=right){ //step4
              for(int i=bottom;i>=top;i--){
                  ans.push_back(mat[i][left]);
               }
               left++; 
            }
         }
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends