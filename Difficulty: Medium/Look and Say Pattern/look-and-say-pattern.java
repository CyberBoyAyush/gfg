//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            System.out.println(ob.countAndSay(n));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Solution {
    public String countAndSay(int n) {
        // code here
        if(n<=1) return "1";
        String str=countAndSay(n-1);
        StringBuilder sb=new StringBuilder();
        int cnt=0;
        char ch=str.charAt(0);
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)!=ch)
            {
                sb.append(String.valueOf(cnt));
                sb.append(ch);
                ch=str.charAt(i);
                cnt=0;
            }
            cnt++;
        }
        sb.append(String.valueOf(cnt));
        sb.append(ch);
        return sb.toString();
    }
}
