//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // take a stack and store k elements in stacks
        stack<int> st;
        while(k--){
            st.push(q.front());
            q.pop();
        }
        
        // ab size nikalo queue ka 
        int n = q.size();
        
        // now push elements from stack in queue (int will insert in reverse order)
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        // now we will push n elements in queue from queue and we will get the result
        while(n--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends