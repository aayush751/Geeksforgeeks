/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void inorder(Node* root, vector<int>& elements) {
        if (root == NULL) return;
        inorder(root->left, elements);
        elements.push_back(root->data);
        inorder(root->right, elements);
    }

    int kthSmallest(Node* root, int k) {
        vector<int> elements;
        inorder(root, elements);
        return (k > 0 && k <= elements.size()) ? elements[k - 1] : -1;
    }
};
