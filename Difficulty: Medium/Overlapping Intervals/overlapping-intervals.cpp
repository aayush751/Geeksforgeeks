//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector< vector< int > > result;
        
        sort( begin(arr), end(arr) );
        
        result.push_back( arr[0] );
        
        for(int i = 1; i < arr.size(); i++ )
        {
            if( result.back()[1] >= arr[i][0] )
            {
                result.back()[1] = max( result.back()[1], arr[i][1] );
            }
            else
            {
                result.push_back( arr[i] );
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends