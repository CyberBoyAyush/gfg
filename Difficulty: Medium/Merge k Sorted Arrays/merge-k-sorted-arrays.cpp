//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<pair<int,pair<int,int>>> temp;
        for(int i = 0; i<K;i++){
            temp.push_back(make_pair(arr[i][0] , make_pair(i,0)));
        }
        //min heap
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());
        
        
        vector<int> ans; // final answer vector
        pair<int,pair<int,int>> element; // for retrival of top
        int i,j;
        while(!pq.empty()){
            element = pq.top();
            pq.pop();
            ans.push_back(element.first);
            i = element.second.first; // row 
            j = element.second.second; // col 
            
            if(j+1<K){ // checking index range
                pq.push(make_pair(arr[i][j+1] , make_pair(i,j+1)));
            } 
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends