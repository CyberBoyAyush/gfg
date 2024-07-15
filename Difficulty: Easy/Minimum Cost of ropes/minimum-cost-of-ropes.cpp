//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // craeting minheap using priority queuue
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        
        //pushing values of arr to minheap
        for(int i = 0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        // now simualting the process
        while(pq.size()>1){
            long long rope = pq.top(); // first samllest rope part
            pq.pop(); 
            rope += pq.top(); // second smallest rope part
            pq.pop();
            
            cost += rope; // calculaing the cost
            pq.push(rope); // pushing the new combines cost in queue
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends