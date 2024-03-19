//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int N){
	    //code
	    int low = 0, end = N - 1;
	    
	    int mid = low + ( end - low ) / 2;
	    
	    while( low <= end )
	    {
	        if( low == end )
	        {
	            return arr[low];
	        }
	        else if( mid & 1 ) //if mid is odd
	        {
	            if( arr[mid] == arr[mid - 1] )
	            {
	                low = mid + 1;
	            }
	            else
	            {
	                end = mid - 1;
	            }
	        }
	        else if( mid % 2 == 0 )
	        {
	            if( arr[mid] == arr[mid + 1] )
	            {
	                low = mid + 2;
	            }
	            else
	            {
	                end = mid;
	            }
	        }
	        
	        mid = low + ( end - low ) / 2;
	    }
	    
	    return 0;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends