class Solution {
    public:
        int n;
  
    int check(int t, vector<int>&arr, int k, int w){
        int ops=0;
        vector<int>diff(n+1, 0);
        for(int i=0; i<n; i++){
            if(i!=0) diff[i]+=diff[i-1];
            int curr=diff[i]+arr[i];
            if(curr<t){
                ops+=(t-curr);
                diff[i]+=(t-curr);
                if(i+w<n){
                    diff[i+w]-=(t-curr);
                }
            }
        }
        
        return ops<=k;
    }
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        n=arr.size();
        int maxi=*max_element(arr.begin(), arr.end());
        
        int lo=1, hi=maxi+k;
        int ans=-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid, arr, k, w)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        
        return ans;
    }
};