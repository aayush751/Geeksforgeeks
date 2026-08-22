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
}; */

class Solution {
    
    private:
    // Helper function to find the Lowest Common Ancestor (LCA)
    Node* findLCA(Node* root, int p, int q) {
        if (!root || root->data == p || root->data == q) {
            return root;
        }
        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    // DFS to count direction changes from a node down to the target node
    bool countTurns(Node* root, int target, bool isLeft, int turns, int& totalTurns) {
        if (!root) return false;

        if (root->data == target) {
            totalTurns = turns;
            return true;
        }

        // Moving left: turn count increases if coming from right
        if (root->left) {
            int nextTurns = turns + (!isLeft ? 1 : 0);
            if (countTurns(root->left, target, true, nextTurns, totalTurns)) {
                return true;
            }
        }

        // Moving right: turn count increases if coming from left
        if (root->right) {
            int nextTurns = turns + (isLeft ? 1 : 0);
            if (countTurns(root->right, target, false, nextTurns, totalTurns)) {
                return true;
            }
        }

        return false;
    }

    // Calculates turns required to reach target from an ancestor node
    int getTurnsFromNode(Node* node, int target) {
        if (!node || node->data == target) return 0;

        int totalTurns = 0;
        if (node->left && countTurns(node->left, target, true, 0, totalTurns)) {
            return totalTurns;
        }
        if (node->right && countTurns(node->right, target, false, 0, totalTurns)) {
            return totalTurns;
        }

        return 0;
    }
  public:
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;

        int turns = 0;

        if (lca->data == p) {
            // Case 1: p is ancestor of q
            turns = getTurnsFromNode(lca, q);
        } else if (lca->data == q) {
            // Case 2: q is ancestor of p
            turns = getTurnsFromNode(lca, p);
        } else {
            // Case 3: p and q are in different subtrees of LCA
            int turnsP = getTurnsFromNode(lca, p);
            int turnsQ = getTurnsFromNode(lca, q);
            // +1 for the turn required at the LCA node itself
            turns = turnsP + turnsQ + 1;
        }

        // If total turns is 0, it means the path is straight; return -1 as required
        return (turns == 0) ? -1 : turns;
    }
};