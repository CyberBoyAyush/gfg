class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
           stack<int>st;
           vector<int>ans(arr.size(),0);
           for(int i=0;i<arr.size();++i){
               
            // ---- TIME COMPLEXITY EXPLANATION ----
            // Each index 'i' is pushed once into stack.
            // Each index can be popped only once.
            // So even though this while loop looks heavy,
            // total pops across the entire program = n.
            // Hence amortized O(1) work per iteration.
            // Overall TC = O(n).

            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();   // This pop will not happen again for this index.
            }

               
               if(st.empty()) ans[i] = i+1;
               else ans[i] = (i-st.top());
               
               st.push(i);
               
           }
           return ans;
    }
};