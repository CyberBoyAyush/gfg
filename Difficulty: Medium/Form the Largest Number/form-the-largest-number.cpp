class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Convert all integers to strings for easy concatenation
        vector<string> nums;
        for(int x : arr){
            nums.push_back(to_string(x));
        }
        
        // Custom sorting: Compare a+b vs b+a to decide order
        sort(nums.begin(), nums.end(), [&](string &a, string &b) -> bool {
            return (a + b) > (b + a); // If a+b is larger, a comes first
        });
        
        // Concatenate all sorted strings
        string ans = "";
        for(string x : nums) ans += x;
        
        // Handle leading zeros (e.g., ["0","0"] → "00" → return "0")
        int idx = 0;
        while(idx < ans.size() and ans[idx] == '0'){
            ++idx;
        }
        string newAns = ans.substr(idx);
        
        // If all were zeros, return "0"
        return (newAns.size() == 0 ? "0" : newAns);
    }
};