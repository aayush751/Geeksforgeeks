//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
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
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends