/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int sum = 0;

    void transformTree(Node *root) {
        if (!root) return;

        // Traverse right subtree first (greater values)
        transformTree(root->right);

        // Update current node value
        int originalVal = root->data;
        root->data = sum;
        sum += originalVal;

        // Traverse left subtree
        transformTree(root->left);
    }
};