//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int> suffixMax( n, 0 );
        vector<int> prefixMin( n, 0 );
        
        int maxi = a[n -1];
        
        for(int i = n - 1; i >= 0; i-- )
        {
            maxi = max( maxi, a[i] );
            suffixMax[i] = maxi;
        }
        
        int mini = a[0];
        
        for(int i = 0; i < n; i++ )
        {
            mini = min( mini, a[i] );
            prefixMin[i] = mini;
        }
        
        int i = 0, j = 0;
        
        int ans = -1;
        
        while( i < n and j < n )
        {
            if( prefixMin[i] <= suffixMax[j] )
            {
                ans = max( ans, j - i );
                j++;
            }
            else
            {
                i++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends