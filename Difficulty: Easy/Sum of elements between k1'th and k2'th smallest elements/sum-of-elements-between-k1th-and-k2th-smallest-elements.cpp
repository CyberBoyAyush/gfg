//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // max heap for k1 elemnts and k2-1 elemnts
        priority_queue<long long> p1; // for k1 elements
        priority_queue<long long> p2; // for k2-1 elements
        
        // pushing the k1 values in p1
        for(long long i = 0;i<K1;i++){
            p1.push(A[i]);
        }
        // pushing the k2-1 values in p1
        for(long long i = 0;i<K2-1;i++){
            p2.push(A[i]);
        }
        
        // no finding k1 smallest elemnts
        for(long long i = K1;i<N;i++){
            if(A[i]<p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        
        // no finding k2-1 smallest elemnts
        for(long long i = K2-1;i<N;i++){
            if(A[i]<p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        
        // finding the sum of k1 el
        long long sum1 = 0, sum2= 0;
        while(!p1.empty()){
            sum1+=p1.top();
            p1.pop();
        }
        // finding sum of k2-1 el
        while(!p2.empty()){
            sum2+=p2.top();
            p2.pop();
        }
        
        return sum2-sum1;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends