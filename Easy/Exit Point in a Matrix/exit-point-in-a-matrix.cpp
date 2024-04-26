//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        
        int r = 0, c = 0;
        int dir = 0;
        
        
        while( r >= 0 and r < n and c >= 0 and c < m )
        {
            
            if( matrix[r][c] )
            {
                dir = ( dir + matrix[r][c] ) % 4;
                
                matrix[r][c] = 0;
                
                if( dir == 0 )
                {
                    c++;
                }
                else if( dir == 1 )
                {
                    r++;
                }
                else if( dir == 2 )
                {
                    c--;
                }
                else
                {
                    r--;
                }
            }
            else
            {
                dir = ( dir + matrix[r][c] ) % 4;
                
                // matrix[r][c] = 0;
                
                if( dir == 0 )
                {
                    c++;
                }
                else if( dir == 1 )
                {
                    r++;
                }
                else if( dir == 2 )
                {
                    c--;
                }
                else
                {
                    r--;
                }
            }
        }
        
        if( r < 0 )
        {
            r++;
        }
        if( r == n )
        {
            r--;
        }
        if( c < 0 )
        {
            c++;
        }
        if( c == m )
        {
            c--;
        }
        
        return {r, c};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends