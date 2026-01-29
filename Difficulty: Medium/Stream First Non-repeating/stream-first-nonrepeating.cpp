class Solution {
  public:
    string firstNonRepeating(string &A) {
        // code here
         queue< char > q;
		    
		    unordered_map< char, int > mp;
		    string ans;
		    
		    for(int i=0; i<A.size(); i++)
		    {
		        mp[A[i]]++;
		        
		        
		        q.push(A[i]);
		        
		        
		        while( !q.empty() )
		        {
		            if( mp[q.front()] > 1 )
		            {
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if( q.empty() )
		        {
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
    }
};