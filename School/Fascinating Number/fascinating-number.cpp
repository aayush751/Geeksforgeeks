//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	bool fascinating(int n) {
	    // code here
	    int twice = n * 2;
	    int triple = n * 3;
	    
	    string s = to_string( n ) + to_string( twice ) + to_string( triple );
	    
	    vector< int > ans( 10, 0 );
	    
	    for(int i = 0; i < s.size(); i++ )
	    {
	        ans[s[i] - '0']++;
	    }
	    
	   
	   if( ans[0] > 1 )
	   {
	       return 0;
	   }
	   
	   for(int i = 1; i < ans.size(); i++ )
	   {
	       if( ans[i] > 1 or ans[i] == 0 )
	       {
	           return 0;
	       }
	   }
	    
	    return 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.fascinating(n);
        if (ans) {
            cout << "Fascinating\n";
        } else {
            cout << "Not Fascinating\n";
        }
    }
    return 0;
}
// } Driver Code Ends