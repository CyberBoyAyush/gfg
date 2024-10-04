//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (!head || head->next == head) return head;

        Node *prev = NULL, *curr = head, *next = NULL;
        
        // Use a while loop to reverse the list
        while (true) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            // Stop when we complete the circle
            if (curr == head) break;
        }

        // Reconnect the head and tail
        head->next = prev;
        head = prev;

        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* curr=head;
        if(curr==head->next && curr->data == key)
        {
            delete head;
            return NULL;
        }
        
        Node* prev=NULL;
        
        while(curr!=NULL)
        {
            prev=curr;
            curr=curr->next;
            if(curr==head)
            {
                break;
            }
        }
        
        while(curr!=NULL)
        {
            if(curr->data == key)
            {
                    if(curr==head)
                {
                    prev->next=curr->next;
                    curr->next=NULL;
                    delete curr;
                    return prev->next;
                }
                prev->next=curr->next;
                curr->next=NULL;
                Node *del = curr;
                curr=prev->next;
                delete del;
                return head;
            }
            else
            {
                prev=curr;
                curr=curr->next;          
            }
            
            if(curr==head)
            {
                break;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends