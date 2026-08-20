/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
  int res = INT_MIN;
  int solve(Node* root) {
      if (!root->left && !root->right)
          return root->data;
      if (!root->left) {
          int low = solve(root->right);
          res = max(res, root->data - low);
          return min(low, root->data);
      }
      if (!root->right) {
          int low = solve(root->left);
          res = max(res, root->data - low);
          return min(low, root->data);
      }
      int l1 = solve(root->left);
      int l2 = solve(root->right);
      res = max({res, root->data - l1, root->data - l2});
      return min({l1, l2, root->data});
  }
    int maxDiff(Node* root) {
        // code here
        solve(root);
        return res;
    }
};