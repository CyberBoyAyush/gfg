//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ 
    public: 
    void computeLPS(string pat, vector<int> &LPS, int M){
        int len = 0;
        LPS[0] = 0;
        
        int i = 1;
        
        while(i<M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            
            else{
                if(len!=0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
        vector <int> search(string pat, string txt)
        {
            int N = txt.length();
            int M = pat.length();
            
            vector<int> result;
            
            vector<int> LPS(M,0);
            computeLPS(pat,LPS,M); // yeh boii LPS bana do
            
            int i = 0;
            int j = 0;
            while(i<N){
                if(pat[j] == txt[i]){ // match horela hai
                    i++;
                    j++;
                }
                
                if(j==M){ // string match hogya yehhhh
                    result.push_back(i-j+1); // 1 Based Indexing hai isliye i-j+1
                    j = LPS[j-1]; // it is possible ki pat 1 see jada baar present ho toh dubara check kro agar txt string bachi hai toh
                }
                
                else if(pat[j] != txt[i]){
                    if(j!=0){
                        j = LPS[j-1]; // j pointer ko pichle wale lps pe khiskha do
                    }
                    else{
                        i++; //upar wale step se bhi kuch nahi hua
                    }
                }
            }
            return result;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends