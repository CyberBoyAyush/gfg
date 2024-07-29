//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int,pair<int,int>> P;

    vector<vector<int>> directions{{0,1} , {-1,0} , {0,-1} , {1,0}};
    int MinimumEffort(int m, int n, vector<vector<int>> &heights) {
        vector<vector<int>> res(m , vector<int>(n,INT_MAX));

        priority_queue<P, vector<P> , greater<P>> pq; // minheap

        // Applying dijkstra's Algorithm
        res[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            int row = coord.first;
            int col = coord.second;

            pq.pop();

            for(auto dir : directions){
                int nrow = row + dir[0];
                int ncol = col +dir[1];

                //check condt -> inbound
                if(nrow >= 0 && nrow<m && ncol >= 0 && ncol < n ){
                    int absDiff = abs(heights[row][col] - heights[nrow][ncol]);
                    int maxDiff = max(diff,absDiff);

                    if(res[nrow][ncol] > maxDiff){
                       res[nrow][ncol] = maxDiff;
                       pq.push({res[nrow][ncol] , {nrow,ncol}}) ;
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends