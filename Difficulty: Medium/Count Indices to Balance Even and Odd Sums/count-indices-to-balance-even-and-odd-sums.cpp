class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>sum_left_odd(n, 0), sum_left_even(n, 0);
        vector<int>sum_right_odd(n, 0), sum_right_even(n, 0);
        int sum_even = 0, sum_odd = 0;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                sum_even += arr[i];
            }
            else
            {
                sum_odd += arr[i];
            }
            sum_left_odd[i] = sum_odd;
            sum_left_even[i] = sum_even;
        }
        sum_even = 0, sum_odd = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(i % 2 == 0)
            {
                sum_even += arr[i];
            }
            else
            {
                sum_odd += arr[i];
            }
            sum_right_even[i] = sum_even;
            sum_right_odd[i] = sum_odd;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            sum_even = sum_left_even[i];
            sum_odd = sum_left_odd[i];
            
            sum_even += sum_right_odd[i];
            sum_odd += sum_right_even[i];
            
            if(sum_even == sum_odd)ans += 1;
            
        }
        return ans;
    }
};