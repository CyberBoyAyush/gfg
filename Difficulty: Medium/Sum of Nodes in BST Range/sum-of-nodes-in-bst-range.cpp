class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (root == NULL) return 0;

        // If current node is within the range, include its value
        if (root->data >= l && root->data <= r) {
            return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
        }

        // If node value is smaller than l, check only right subtree
        else if (root->data < l) {
            return nodeSum(root->right, l, r);
        }

        // If node value is greater than r, check only left subtree
        else {
            return nodeSum(root->left, l, r);
        }
    }
};