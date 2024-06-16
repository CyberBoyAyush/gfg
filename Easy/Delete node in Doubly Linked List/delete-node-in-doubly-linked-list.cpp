//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteHead(Node* head){
    if(head->next == nullptr || head == NULL){
        return nullptr;
    }
    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next= nullptr;
    delete prev;
    return head;
    }
    
    Node* deleteTail(Node* &head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    Node* tail = head;
    Node * p;

    while(tail->next!=NULL){
        tail = tail->next;
    }
    p = tail->prev;
    p->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head;

}
    
    Node* deleteNode(Node *head, int k)
    {
      if(head == nullptr){
        return nullptr;
    }

    int cnt = 0;
    Node* kNode = head;
    while(kNode!=nullptr){
        cnt++;
        if(cnt==k) break;
        kNode = kNode->next;
    }

    Node* p = kNode->prev;
    Node* f = kNode->next;

    if(p == nullptr && f==nullptr){
        return nullptr;
    } 
    else if(p== nullptr){
        // it means this is out 1st node and we need to delete head
        return deleteHead(head);
    }
    else if(f==nullptr){
        // this is our last node and we need to delete tail
        return deleteTail(head);
    }

    p->next = f;
    f->prev = p;
    kNode->prev = nullptr;
    kNode->next = nullptr;
    delete kNode;
    return head;
    }
};


//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}

// } Driver Code Ends