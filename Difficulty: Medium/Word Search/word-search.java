//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt(); // Number of test cases
        while (tc-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char[][] mat = new char[n][m];

            // Reading the matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = sc.next().charAt(0);
                }
            }

            String word = sc.next();
            Solution obj = new Solution();
            boolean ans = obj.isWordExist(mat, word);
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends

class Solution {
    static boolean[][] visited;
    static String fword;
    static int[] diri={-1,0,1,0};
    static int[] dirj={0,-1,0,1};
    static int m, n;
    static public boolean helper(char[][] mat, int ind, int i, int j)
    {
        if(i>=m || i<0 || j>=n || j<0 || visited[i][j]) return false;
        if(fword.charAt(ind)!=mat[i][j]) return false;

        if(ind==fword.length()-1) return true;
        visited[i][j]=true;

        for(int z=0;z<4;z++)
        {
            if(helper(mat,ind+1,i+diri[z], j+dirj[z])) return true;
        }
        visited[i][j]=false;
        return false;
    }
    static public boolean isWordExist(char[][] mat, String word) {
        // Code here
        m=mat.length;
        n=mat[0].length;
        visited=new boolean[m][n];
        fword=word;
        char firstletter=word.charAt(0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(firstletter==mat[i][j])
                {
                    if(helper(mat,0,i,j))
                        return true;
                }
                
            }
        }
        return false;
    }
}