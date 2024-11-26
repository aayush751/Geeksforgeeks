//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int maxKadane = INT_MIN;
        int sum = 0;
        
        for( int i = 0; i < arr.size(); i++ )
        {
            sum += arr[i];
            maxKadane = max( sum, maxKadane );
            
            if( sum < 0 )
            {
                sum = 0;
            }
        }
        
        sum = 0;
        int minKadane = INT_MAX;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            sum += arr[i];
            minKadane = min( sum, minKadane );
            
            if( sum > 0 )
            {
                sum = 0;
            }
        }
        
        int totalSum = accumulate( arr.begin(), arr.end(), 0 );
        
        int maxCircularSum = totalSum - minKadane;
        
        if( maxKadane < 0 ) return maxKadane;
        
        return max( maxCircularSum, maxKadane );
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
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends