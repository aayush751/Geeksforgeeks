//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int row = -1;
        int zero_count = 0;
        int mini_one = INT_MIN;
        
        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < m; j++ )
            {
                if( a[i][j] == 0 )
                {
                    zero_count++;
                }
            }
            
            if( zero_count > mini_one )
            {
                mini_one = zero_count;
                row = i + 1;
            }
            zero_count = 0;
        }
        
        return row;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends