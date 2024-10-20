//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // Custom comparator for the priority queue
    auto cmp = [](DLLNode* o1, DLLNode* o2) {
        return o1->data > o2->data; // Min-heap behavior
    };

    // Priority queue to store DLLNodes based on their data values
    priority_queue<DLLNode*, vector<DLLNode*>, decltype(cmp)> pq(cmp);

    DLLNode* cur_head = head;
    DLLNode* ans = nullptr;
    DLLNode* cur_ans = nullptr;

    // Traverse through the doubly linked list
    while (cur_head != nullptr) {
        pq.push(cur_head);

        if (pq.size() == k + 1) {
            DLLNode* pop = pq.top();
            pq.pop();

            if (ans == nullptr) {
                ans = pop;
                cur_ans = pop;
            } else {
                cur_ans->next = pop;
                pop->prev = cur_ans;
                cur_ans = cur_ans->next;
            }
        }

        cur_head = cur_head->next;
    }

    // Process remaining nodes in the priority queue
    while (!pq.empty()) {
        DLLNode* pop = pq.top();
        pq.pop();

        if (ans == nullptr) {
            ans = pop;
            cur_ans = pop;
        } else {
            cur_ans->next = pop;
            pop->prev = cur_ans;
            cur_ans = cur_ans->next;
        }
    }

    // Set the final pointers to null
    if (ans != nullptr) ans->prev = nullptr;
    if (cur_ans != nullptr) cur_ans->next = nullptr;

    return ans;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends