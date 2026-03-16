/*
class Node {
  public:
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
  
  
   void solve( Node* root, int &count, unordered_map< int, int > &mp, int currentSum, int k )
  {
      if( !root ) return;
      
      currentSum += root -> data;
      
      if( currentSum == k ) count++;
      
      if( mp.find( currentSum - k ) != mp.end() )
      {
          count += mp[currentSum - k];
      }
      
      mp[currentSum]++;
      
      solve( root -> left, count, mp, currentSum, k );
      solve( root -> right, count, mp, currentSum, k );
      
      mp[currentSum]--;
  }
    int countAllPaths(Node *root, int k) {
        // code here
         unordered_map< int, int > mp;
        int count = 0;
        
        solve( root, count, mp, 0, k );
        return count;
    }
};