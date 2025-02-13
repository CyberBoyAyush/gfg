//{ Driver Code Starts
// Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.math.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}

class GFG {
    static Node buildTree(String str) {
        // Corner Case
        if (str.length() == 0 || str.equals('N')) return null;
        String[] s = str.split(" ");

        Node root = new Node(Integer.parseInt(s[0]));
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);

        // Starting from the second element
        int i = 1;
        while (!q.isEmpty() && i < s.length) {
            // Get and remove the front of the queue
            Node currNode = q.remove();

            // Get the current node's value from the string
            String currVal = s[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                q.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= s.length) break;
            currVal = s[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                q.add(currNode.right);
            }

            i++;
        }

        return root;
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);

            int target = Integer.parseInt(br.readLine().trim());

            Solution T = new Solution();
            boolean ans = T.findTarget(root, target);
            if (ans)
                System.out.println(1);
            else
                System.out.println(0);
            t--;

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


/*
class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}
*/
class Solution {
    // Inorder traversal to store node values in a sorted list
    void inorder(Node root, ArrayList<Integer> arr) {
        if (root == null) return; // Base case: if the node is null, return
        inorder(root.left, arr);  // Traverse the left subtree
        arr.add(root.data);      // Add the current node's value to the list
        inorder(root.right, arr); // Traverse the right subtree
    }

    // Function to find if a pair exists that sums up to the target
    boolean findTarget(Node root, int target) {
        ArrayList<Integer> arr = new ArrayList<>(); // Create a list to store sorted values
        inorder(root, arr); // Perform inorder traversal to populate the list

        // Initialize two pointers: one at the start (i) and one at the end (j)
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            int curr = arr.get(i) + arr.get(j); // Calculate the current sum
            if (curr == target) return true;   // If the sum equals the target, return true
            if (curr > target) --j;            // If the sum is greater, move the right pointer left
            else ++i;                          // If the sum is smaller, move the left pointer right
        }

        return false; // If no pair is found, return false
    }
}
