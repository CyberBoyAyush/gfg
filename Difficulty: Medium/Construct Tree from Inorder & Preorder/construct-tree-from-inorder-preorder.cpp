//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* solve(int preorder[], int inorder[], int start, int end, int &idx){
        //Base Case
        if(start>end){
            return nullptr;
        }

        int rootVal = preorder[idx];
        int i = start;
        for(; i<=end ; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }

        idx++;

        Node * root = new Node(rootVal);
        //recursive call
        root->left = solve(preorder,inorder,start,i-1,idx);
        root->right = solve(preorder,inorder,i+1,end,idx);
        return root;
    }
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        int idx = 0;

        return solve(preorder,inorder,0,n-1,idx);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends