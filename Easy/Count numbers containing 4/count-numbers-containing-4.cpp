//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
    bool solve( int n )
    {
        while( n > 0 )
        {
            int ld = n % 10;
            
            if( ld == 4 )
            {
                return true;
            }
            
            n = n / 10;
        }
        
        return false;
    }
    
    
    int countNumberswith4(int n) {
        // code here
        int ans = 0;
        
        for(int i = 1; i <= n; i++ )
        {
            if( solve(i) )
            {
                ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends