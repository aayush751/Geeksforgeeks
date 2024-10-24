//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        
        if( n == 1 )
        {
            return arr;
        }
        
        vector< int > ans;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            if( arr[i] == 0 )
            {
                // ans.push_back( arr[i] );
                continue;
            }
            else
            {
                if( i + 1 < n )
                {
                    if( arr[i] == arr[i + 1] )
                    {
                        arr[i] = 2 * arr[i];
                        arr[i + 1] = 0;
                    }
                }
            }
        }
        
        int cnt = 0;
        
        for( int num: arr )
        {
            if( num != 0 )
            {
                ans.push_back( num );
            }
            else
            {
                cnt++;
            }
        }
        
        while( cnt-- )
        {
            ans.push_back( 0 );
        }
        
        if( ans.size() == 0 ) return arr;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends