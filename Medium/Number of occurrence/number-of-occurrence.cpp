//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		
	int first( int arr[], int n, int x )
	{
	    int start = 0, end = n - 1;
	    int mid = start + ( end - start ) / 2;
	    
	    int ans = -1;
	    
	    while( start <= end )
	    {
	        if( arr[mid] == x )
	        {
	            ans = mid;
	            end = mid - 1;
	        }
	        else if( arr[mid] < x )
	        {
	            start = mid + 1;
	        }
	        else
	        {
	            end = mid - 1;
	        }
	        mid = start + ( end - start ) / 2;
	    }
	    
	    return ans;
	}
	
	int last( int arr[], int n, int x )
	{
	    int start = 0, end = n - 1;
	    int mid = start + ( end - start ) / 2;
	    
	    int ans = -1;
	    
	    while( start <= end )
	    {
	        if( arr[mid] == x )
	        {
	            ans = mid;
	            start = mid + 1;
	        }
	        else if( arr[mid] < x )
	        {
	            start = mid + 1;
	        }
	        else
	        {
	            end = mid - 1;
	        }
	        mid = start + ( end - start ) / 2;
	    }
	    
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int start = first( arr, n, x );
	    int end = last( arr, n, x );
	    
	    if( start == -1  and end == -1 )
	    {
	        return 0;
	    }
	    
	    return end - start + 1;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends