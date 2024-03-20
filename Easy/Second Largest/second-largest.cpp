//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    priority_queue< int > qp;
	    
	    if( n == 1 )
	    {
	        return -1;
	    }
	    
	    for(int i = 0; i < n; i++ )
	    {
	        if( qp.empty() or qp.top() != arr[i] )
	        {
	            qp.push( arr[i] );
	        }
	    }
	    
        
        if( qp.size() > 1 )
        {
            qp.pop();
        }
        else if( qp.size() == 1 )
        {
            return -1;
        }
        
        
	    return qp.top();
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends