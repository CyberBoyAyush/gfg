class Solution {
public:
    using ll = long long;
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
       
       int n = arr1.size(), m = arr2.size();
       
       int lo = arr1[0] + arr2[0], hi = arr1[n-1] + arr2[m-1], ans = hi;
       
       auto check = [&](ll target) -> bool {
           
           ll cnt = 0;
           
           for(ll i=0; i<n; i++)
           {
               ll num = arr1[i];
               cnt += upper_bound(arr2.begin(), arr2.end(), target - num) - arr2.begin();
           }
           return cnt >= k;
       };
       
       while(lo <= hi)
       {
            ll mid = lo + (hi - lo) / 2;
            
            if(check(mid))
            {
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
            
       }
       
       
       vector<vector<int>>res;
            
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr1[i] + arr2[j] <= ans)
                {
                    res.push_back({arr1[i], arr2[j]});
                }else break;
            }
        }
        
        sort(res.begin(), res.end(), [&](auto &a, auto &b)
        {
            return a[0] + a[1] < b[0] + b[1];  
        });
        
        while((int)res.size() > k) res.pop_back();
        
        return res;
        
       }
};