/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to find median node value
void findMedianUtil(Node* root, int& count, int target, int& median) {
    if (!root) return;

    // Traverse left subtree
    findMedianUtil(root->left, count, target, median);

    count++;

    // For odd: position = (n+1)/2
    // For even: position = n/2
    if ((target % 2 == 1 && count == (target + 1) / 2) || 
        (target % 2 == 0 && count == target / 2)) {
        median = root->data;
        return;
    }

    // Traverse right subtree
    findMedianUtil(root->right, count, target, median);
}

// Main median function
int findMedian(Node* root) {
    int n = countNodes(root);
    int count = 0;
    int median = -1;
    findMedianUtil(root, count, n, median);
    return median;
}
};