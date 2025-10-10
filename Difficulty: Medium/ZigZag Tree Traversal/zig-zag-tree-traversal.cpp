/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue< Node* > q;
    	
    	vector< int > ans;
    	
    	q.push( root );
    	
    	bool leftToRight = true;
    	
    	while( !q.empty() )
    	{
    	    int node_count = q.size();
    	    
    	    vector< int > temp( node_count );
    	    for(int i = 0; i < node_count; i++ )
    	    {
    	        Node* curr = q.front();
    	        q.pop();
    	        
    	        int index = leftToRight ? i : node_count - i - 1;
    	        temp[index] = curr -> data;
    	        
    	        if( curr -> left )
    	        {
    	            q.push( curr -> left );
    	        }
    	        
    	        if( curr -> right )
    	        {
    	            q.push( curr -> right );
    	        }
    	    }
    	    
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i: temp )
    	    {
    	        ans.push_back( i );
    	    }
    	    
    	}
    	
    	return ans;
    }
};