//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        int n = arr.size();
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
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends