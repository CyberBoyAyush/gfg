//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    
  // vector 
  vector<pair<int,pair<int,int>>> temp;
  
  //pushing values of first column in vector
  for(int i = 0; i<n; i++){
      temp.push_back(make_pair(mat[i][0] , make_pair(i,0)));
  }
  
  // creating min heap (values,location in pair) in O(N) time
  priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());
  
  int ans;
  pair<int,pair<int,int>>element;
  int i , j;
  while(k--){
      element = pq.top();
      pq.pop();
      ans = element.first; // value
      i = element.second.first; // accessing the row
      j = element.second.second; // accessing the col
      
      // pushing the next value in row
      if(j+1 < n){
          pq.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
      }
  }
  return ans;
}
