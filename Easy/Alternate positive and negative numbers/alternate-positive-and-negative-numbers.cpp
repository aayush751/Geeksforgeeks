//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int N) {
	    // code here
	    vector< int > p,n;
	    
	    for(int i = 0; i < N; i++ )
	    {
	        if( arr[i] >= 0 )
	        {
	            p.push_back( arr[i] );
	        }
	        else
	        {
	            n.push_back( arr[i]);
	        }
	    }
	    
	    
	    int size_p = p.size();
	    int size_n = n.size();
	    int i = 0, j = 0;
	    
	    int k = 0;
	    
	    while( i < size_p and j < size_n )
	    {
	        arr[k++] = p[i++];
	        arr[k++] = n[j++];
	    }
	    
	    while( i < size_p )
	    {
	        arr[k++] = p[i++];
	    }
	    
	    while( j < size_n )
	    {
	        arr[k++] = n[j++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends