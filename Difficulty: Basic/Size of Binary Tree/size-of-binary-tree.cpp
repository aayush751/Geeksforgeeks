/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if (root == nullptr) {
            return 0;
        }
        
        // Recursive step: 1 (the current node) + size of left subtree + size of right subtree.
        return 1 + getSize(root->left) + getSize(root->right);
    }
};