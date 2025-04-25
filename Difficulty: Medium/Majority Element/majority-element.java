//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().majorityElement(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int majorityElement(int arr[]) {
        // code here
        int n = arr.length;
        int times=n/2;
       HashMap<Integer,Integer> hm = new HashMap<>();
       for(int i : arr)
       {
           hm.put(i,hm.getOrDefault(i,0)+1);
       }
       for(int i : hm.keySet())
       {
           if(hm.get(i)>times)
           return i;
       }
       return -1;
    }
}