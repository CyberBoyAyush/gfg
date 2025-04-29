//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}


// } Driver Code Ends

class Solution {
    static Node segregate(Node head) {
        // code here
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        
        Node temp = head;
        while(temp != null){
            if(temp.data == 0){
                count_0++;
            }
            else if(temp.data == 1){
                count_1++;
            }
            else{
                count_2++;
            }
            
            temp = temp.next;
        }
        
        Node dummy = new Node(-1);
        temp = dummy;
        for(int i=0; i<count_0; i++){
            temp.next = new Node(0);
            temp = temp.next;
        }
        
        for(int i=0; i<count_1; i++){
            temp.next = new Node(1);
            temp = temp.next;
        }
        
        for(int i=0; i<count_2; i++){
            temp.next = new Node(2);
            temp = temp.next;
        }
        
        return dummy.next;
    }
}



//{ Driver Code Starts.

class GFG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine().trim();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }

            Node head = null;
            if (!arr.isEmpty()) {
                head = new Node(arr.get(0));
                Node tail = head;
                for (int i = 1; i < arr.size(); i++) {
                    tail.next = new Node(arr.get(i));
                    tail = tail.next;
                }
            }
            head = new Solution().segregate(head);
            printList(head);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends