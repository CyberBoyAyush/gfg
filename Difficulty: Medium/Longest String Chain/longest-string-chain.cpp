//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
  
    int longestStringChain(vector<string>& words) 
    {
        
        sort(words.begin(), words.end(), comp);
        unordered_map<string,int> mp;
        int ans = 1;
        for(string &w : words)
        {
            int length = 1;
            for(int i = 0; i < w.size(); i++)
            {
                string pred = w.substr(0,i) + w.substr(i+1);
                if(mp.find(pred) != mp.end())
                {
                    length = max(length,mp[pred]+1);
                }
            }
            mp[w]=length;
            ans = max(ans,length);
        }
        return ans;
        // Code here
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends