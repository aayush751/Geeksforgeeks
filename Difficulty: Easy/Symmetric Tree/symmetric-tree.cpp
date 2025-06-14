/*
Structure of the node of the tree is as
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
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not++++
    
    bool isMirror( Node* left, Node* right )
    {
        if( left == nullptr and right == nullptr )
        {
            return true;
        }
        
        if( left == nullptr or right == nullptr )
        {
            return false;
        }
        
        return ( left -> data == right -> data ) and isMirror( left -> left, right -> right ) and isMirror( left -> right, right -> left );
    }
    
    
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if( root == nullptr )
	    {
	        return true;
	    }
	    
	    return isMirror( root -> left, root -> right );
    }
};
