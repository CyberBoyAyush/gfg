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
};*/
class Solution {
public:

// Iterative Way Tc and Sc O(n)
    // vector<int> inOrder(Node* root)
    // {
    //     //we will be using two stacks in this
    //     stack<Node*>st;
    //     stack<bool>v; //tracks if we have visited it before
    //     vector<int>ans;
        
    //     st.push(root);
    //     v.push(0);
        
    //     while(!st.empty()){
    //         Node* temp = st.top();
    //         st.pop();
    //         bool vis = v.top();
    //         v.pop();
            
    //         if(vis == 0){
    //             if(temp->right){
    //                 st.push(temp->right);
    //                 v.push(0);
    //             }
                
    //             st.push(temp);
    //             v.push(1);
                
    //             if(temp->left){
    //                 st.push(temp->left);
    //                 v.push(0);
    //             }
    //         }
    //         else{
    //             ans.push_back(temp->data);
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    // Morris Traversal 
    // TC - O(N) Sc O(1)
    vector<int> inOrder(Node* root){
        //vector for ans
        vector<int> ans;
        
        while(root){ // run loop until root is not null
            // left does not exists
            if(!root->left){
                ans.push_back(root->data);
                root = root->right; // go to right part
            }
            
            // if left exists
            else{
                Node * curr = root-> left;
                
                //traverse curr in right side for link creation
                while(curr->right && curr-> right!= root){
                    curr = curr->right;
                }
                
                // checking if we have traversed in left subtree
                if(curr->right == nullptr){
                    // not traversed
                    curr->right = root;
                    root = root->left;
                }
                
                else{
                    // left subtree traversed
                    curr->right = nullptr;
                    ans.push_back(root->data);
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
        ans = ob.inOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends