//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector< long long > left(n);
        vector< long long > right(n);
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        
        for(int i = 1; i < n; i++ )
        {
            if( arr[i] > left[i - 1] )
            {
                left[i] = arr[i];
            }
            else
            {
                left[i] = left[i - 1];
            }
        }
        
        for(int i = n - 2; i > -1; i-- )
        {
            if( arr[i] > right[i + 1] )
            {
                right[i] = arr[i];
            }
            else
            {
                right[i] = right[i + 1];
            }
        }
        
        long long ans = 0;
        
        for(int i = 1; i < n - 1; i++ )
        {
            if( arr[i] < left[i - 1] and arr[i] < right[i + 1] )
            {
                ans = ans + min( left[i - 1] - arr[i], right[i + 1] - arr[i] );
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends