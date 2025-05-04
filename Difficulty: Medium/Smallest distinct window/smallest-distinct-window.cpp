//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        
        int n = str.length() ;
        int ans = n ;
        
        int distinct = 0 ;
        for(char ch : str){
            distinct = distinct | (1 << (ch - 'a')) ;
        }
        int i = 0 ; 
        int j = 0 ; 
        
        vector<int>alph(26 , 0) ;
        int present = 0 ;
        while(i < n){
            int ch = str[i] - 'a' ; 
            alph[ch] ++ ;
            present = present | (1 << ch) ;
            
            while(j <= i && present == distinct){
                ans = min(i - j + 1 , ans) ;
                int temp = str[j] - 'a' ;
                alph[temp] -- ;
                if(alph[temp] == 0) present = present & (~(1 << temp)) ;
                j ++ ;
            }
            
            i ++ ;
        }
        return ans ;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends