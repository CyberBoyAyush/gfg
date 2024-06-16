//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, noOfBouqets = 0;
        for(int i = 0; i<n; i++){
            if(bloomDay[i]<=day){
                cnt ++;
            }
            else{
                noOfBouqets += cnt/k;
                cnt = 0;
            }
        }
        noOfBouqets += cnt/k;
        //return noOfBouqets >= m;
        if(noOfBouqets>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(int m, int k, vector<int> &bloomDay){
              // Edge case
        long long val=m*1ll*k*1ll;
        int n=bloomDay.size();
        if(val>n){
            return -1;
        }
        int low = INT_MAX , high = INT_MIN , ans = 0;
        for(int i=0 ;i<n;i++){
            low = min(bloomDay[i],low);
            high = max(bloomDay[i],high);
        }
        if((m*k)>n){
            return -1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay , mid, m, k)){
                ans = mid;
                high = mid -1; // we need minimum so we go to the left part of the array
            }
            else{
                low = mid + 1;
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends