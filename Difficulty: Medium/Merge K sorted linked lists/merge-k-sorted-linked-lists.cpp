//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    // custom comapre func
    class Compare{
        public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data; // heap ke case me ulta hota h -> minheap
        }
    };
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        // create a min heap
        priority_queue<Node*, vector<Node*>, Compare> pq(arr, arr+k); // custom sort min heap
        
        // creating some pointer nodes
        Node* dummyNode = new Node(-1);
        Node* tail = dummyNode; // traverse in LL and points to tail
        
        Node* temp; // we push values from min heap in it
        
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next)  pq.push(temp->next);
        }
        return dummyNode->next;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends