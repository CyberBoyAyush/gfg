//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //creating heaps
    priority_queue<int> LeftMaxHeap;
    priority_queue<int,vector<int>, greater<int>> RightMinHeap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        // left is empty
        if(LeftMaxHeap.empty()){
            LeftMaxHeap.push(x);
            return;
        }
        
        //comapring values
        if(x>LeftMaxHeap.top()){
            RightMinHeap.push(x);
        }
        else{
            LeftMaxHeap.push(x);
        }
        
        // calling balance heap func as asked in questions
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        // if right > left
        if(RightMinHeap.size()>LeftMaxHeap.size()){
            LeftMaxHeap.push(RightMinHeap.top());
            RightMinHeap.pop();
        }
        
        //difference should not be greater than 1
        if(RightMinHeap.size()+1<LeftMaxHeap.size()){
            RightMinHeap.push(LeftMaxHeap.top());
            LeftMaxHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        // if left size == right size
        if(LeftMaxHeap.size()==RightMinHeap.size()){
            double ans = LeftMaxHeap.top() + RightMinHeap.top();
            ans = ans/2;
            return ans;
        }
        else{
            // left + 1 = right
            return LeftMaxHeap.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends