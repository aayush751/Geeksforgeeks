//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        sort( arr.begin(), arr.end() );
        
        int initialDiff = arr[n -1] - arr[0];
        int minHeight = arr[0] + k;
        int maxHeight = arr[n - 1] - k;
        
        int result = initialDiff;
        
        for(int i = 0; i < n - 1; i++ )
        {
            int currMin = min( minHeight, arr[i + 1] - k );
            int currMax = max( maxHeight, arr[i] + k );
            
            result = min( result, currMax - currMin );
        }
        
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends