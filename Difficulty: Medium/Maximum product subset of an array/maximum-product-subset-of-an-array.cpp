//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        
        int n = arr.size();
        
        if( n == 1 )
        {
            return arr[0];
        }
        
        long long int ans = 1, mod = 1e9 + 7;
        int maxNegative = INT_MIN;
        int zero_cnt = 0;
        int nega_cnt = 0;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            if( arr[i] == 0 )
            {
                zero_cnt++;
                continue;
            }
            else if( arr[i] < 0 )
            {
                maxNegative = max( maxNegative, arr[i] );
                nega_cnt++;
            }
            
            ans = ( ans * arr[i] ) % mod;
        }
        
        if( zero_cnt == n )
        {
            return 0;
        }
        
        if( nega_cnt == 1 and zero_cnt == n - 1 )
        {
            return 0;
        }
        
        
        
        if( nega_cnt & 1 )
        {
            return ans / maxNegative;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends