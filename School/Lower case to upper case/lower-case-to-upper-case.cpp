//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;
 
string to_upper(string in);
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		cout << to_upper(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends

#include<string.h>

string to_upper(string str){
    // int n = strlen(str);

    for(int i = 0; i<str.size(); i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return str;
    
}