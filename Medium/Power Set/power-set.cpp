//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    void solve(string s,int index, string curr , vector<string> &ans){
	        if(index == s.length()){
	            ans.push_back(curr);
	            return;
	        }
	        
	        //include
	        solve(s,index+1,curr + s[index],ans);
	        // exclude
	        solve(s,index+1,curr,ans);
	        
	        
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    int index = 0;
		    string curr = "";
		    solve(s,index,curr,ans);
		    sort(ans.begin(),ans.end());
		    ans.erase(ans.begin());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends