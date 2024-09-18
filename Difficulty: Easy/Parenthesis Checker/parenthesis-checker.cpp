//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
         stack <char> S;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') S.push(s[i]);
            else {
                if(S.empty()) return false;
                if ((s[i] == ')' && S.top() != '(') ||
                    (s[i] == '}' && S.top() != '{') ||
                    (s[i] == ']' && S.top() != '[')) {
                    return false;
                }
                S.pop();
            }
        }
        if(S.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends