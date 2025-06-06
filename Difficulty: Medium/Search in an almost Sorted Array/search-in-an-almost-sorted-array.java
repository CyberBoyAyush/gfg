//{ Driver Code Starts
// Initial Template for Java
import java.util.*;


// } Driver Code Ends

class Solution {
    public int findTarget(int arr[], int target) {
        // code here
        int n = arr.length;
        int low = 0;
        int high = n-1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == target) {
                return mid;
            } else if(mid-1 >= low && arr[mid-1] == target) {
                return mid - 1;
            } else if(mid+1 <= high && arr[mid+1] == target) {
                return mid + 1;
            } else if(arr[mid] > target) {
                high = mid - 2;
            } else {
                low = mid+2;
            }
        }
        
        return -1;
    }
}


//{ Driver Code Starts.

public class GFG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String temp[] = sc.nextLine().trim().split(" ");
            int n = temp.length;
            int arr[] = new int[n];
            int target = sc.nextInt();
            if (sc.hasNextLine()) sc.nextLine();
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(temp[i]);
            Solution sln = new Solution();
            int ans = sln.findTarget(arr, target);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends