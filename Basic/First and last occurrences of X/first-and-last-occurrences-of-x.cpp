//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
    int first_Occur( vector<int> &arr, int n, int x )
    {
        int low = 0, high = n - 1;
        int mid = low + ( high - low ) / 2;
        int ans = -1;
        
        while( low <= high )
        {
            if( arr[mid] == x )
            {
                ans = mid;
                high = mid - 1;
            }
            else if( arr[mid] > x )
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + ( high - low ) / 2;
        }
        
        return ans;
    }
    
    
    int last_Occur( vector<int> &arr, int n, int x )
    {
        int low = 0, high = n - 1;
        int mid = low + ( high - low ) / 2;
        int ans = -1;
        
        while( low <= high )
        {
            if( arr[mid] == x )
            {
                ans = mid;
                low = mid + 1;
            }
            else if( arr[mid] > x )
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + ( high - low ) / 2;
        }
        
        return ans;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int first_occurence = first_Occur( arr, n, x );
        int last_occurence = last_Occur( arr, n, x );
        
        if( first_occurence == -1 and last_occurence == -1 )
        {
            return { -1 };
        }
        
        return { first_occurence, last_occurence };
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends