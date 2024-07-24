//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int row = hospital.size();
        int col = hospital[0].size();
        
        // queue for BFS Traversal
        queue<pair<int,int>> q;
        
        //pushing value with infected patients in queue
        for(int i = 0; i<row;i++){
            for(int j = 0; j<col;j++){
                if(hospital[i][j]==2){
                    //infected patient
                    q.push(make_pair(i,j));
                }
            }
        }
        
        // now bfs traversal
        int timer = 0; // final ans 
        while(!q.empty()){
            timer++;
            int curr_patients = q.size();
            while(curr_patients--){
                int i = q.front().first; // row
                int j = q.front().second; // col
                
                q.pop();
                
                // top
                if(i-1>=0 && hospital[i-1][j]==1){
                    hospital[i-1][j] = 2;
                    q.push(make_pair(i-1,j));
                }
                
                // bottom
                if(i+1<row && hospital[i+1][j]==1){
                    hospital[i+1][j]=2;
                    q.push(make_pair(i+1,j));
                }
                
                // left
                if(j-1>=0 && hospital[i][j-1]==1){
                    hospital[i][j-1]=2;
                    q.push(make_pair(i,j-1));
                }
                
                //right
                if(j+1< col && hospital[i][j+1]==1){
                    hospital[i][j+1]=2;
                    q.push(make_pair(i,j+1));
                }
            }
        }
        
        // check if any patient left
        for(int i = 0; i<row;i++){
            for(int j = 0; j<col;j++){
                if(hospital[i][j]==1){
                    return -1;
                }
            }
        }
        return timer-1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends