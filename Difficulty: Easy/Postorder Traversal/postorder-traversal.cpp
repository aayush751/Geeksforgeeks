/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  
  void traversal( Node* node, vector<int> &res )
{
    if( node == nullptr )
    {
        return;
    }
    
    traversal( node -> left , res );
    traversal( node -> right, res );
    res.push_back( node -> data );
}
    vector<int> postOrder(Node* root) {
        // code here
        vector< int > res;
  traversal( root, res );
  return res;
    }
};