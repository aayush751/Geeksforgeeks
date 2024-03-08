//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    bool allSame( vector< int > &freq )
    {
        int curr = -1;
        for(auto i: freq )
        {
            if( i == 0 )
            {
                continue;
            }
            else if( curr == -1 )
            {
                curr = i;
            }
            else if( curr != i )
            {
                return false;
            }
        }
        
        return true;
    }
	bool sameFreq(string s)
	{
	    int size = s.size();
	    
	    vector< int > freq( 26, 0 );
	    for(int i = 0; i < s.size(); i++ )
	    {
	        freq[s[i] - 'a']++;
	    }
	    
	    if( allSame( freq) )
	    {
	        return true;
	    }
	    
	    for(int i = 0; i < freq.size(); i++ )
	    {
	        if( freq[i] != 0 )
	        {
	            freq[i]--;
	            if( allSame( freq ) )
	            {
	                return  true;
	            }
	            
	            freq[i]++;
	        }
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends