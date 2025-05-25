class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // Step 1: Store all elements in a set for O(1) lookups
        set<int> st(arr.begin(), arr.end());
        
        // Step 2: Iterate possible values of i (c) and j (a)
        for(int i = 1; i <= 1e3; ++i) {
            for(int j = 1; j <= i; ++j) {
                // Check if both i and j exist in the set
                if(st.find(i) != st.end() && st.find(j) != st.end()) {
                    // Compute b² = i² - j²
                    int findd = i*i - j*j;
                    int sqrtt = sqrt(findd);  // Take integer sqrt
                    
                    // Check if sqrt(b²) is a perfect square and exists in set
                    if(sqrtt * sqrtt == findd && st.find(sqrtt) != st.end()) 
                        return true;  // Triplet found
                }
            }
        }
        
        // Step 3: No triplet found
        return false;
    }
};