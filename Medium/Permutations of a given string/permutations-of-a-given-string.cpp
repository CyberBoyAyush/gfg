//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void solve(string S, int index , vector<string> &ans){
        if(index>=S.length()){
            ans.push_back(S);
            return ;
        }

        for(int j = index;j<S.length();j++){
            swap(S[index],S[j]);
            solve(S,index+1,ans);
            //backtrack
            swap(S[index],S[j]);
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		vector<string> ans;
        int index = 0;
        solve(S,index,ans);
         sort(ans.begin(),ans.end());
         ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends