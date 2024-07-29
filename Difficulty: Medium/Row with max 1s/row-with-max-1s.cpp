//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int one_count = 0;
        int idx = -1;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            int temp = count( arr[i].begin(), arr[i].end() , 1 );
            
            if( temp > one_count )
            {
                one_count = temp;
                idx = i;
            }   
        }
        
        return ( idx == -1 ) ? -1 : idx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends