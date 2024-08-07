//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution{
    public:
    
    // Iterative Way TC and SC O(N)
    
    // vector<int> preOrder(Node* root)
    // {
    //     // we can use stack for implementing this
    //     stack<Node*> st;
    //     st.push(root);
    //     vector<int>ans;
        
    //     while(!st.empty()){
    //         Node * temp = st.top();
    //         st.pop();
            
    //         ans.push_back(temp->data);
            
    //         //we go right first as we our using stack
    //         if(temp->right){
    //             st.push(temp->right);
    //         }
    //         if(temp->left){
    //             st.push(temp->left);
    //         }
    //     }
    //     return ans;
    // }
    
    //Morris Traversal 
    // TC - O(N) SC - O(1)
    
    vector<int> preOrder(Node* root){
        //vector for ans
        vector<int> ans;
        
        while(root){
            // check left part
            if(!root->left){
                ans.push_back(root->data);
                root = root->right;
            }
            
            else{
                Node* curr = root->left;
                
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                
                // left tree not traverse
                if(curr->right==nullptr){
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root->left;
                }
                
                else{
                    curr->right = nullptr; //removing link
                    root = root->right;
                }
            }
        }
        return ans;
        
    }
    
    
    
    
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.preOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends