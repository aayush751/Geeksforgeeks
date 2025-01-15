//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map< int, int > mp;
        int current_sum = 0;
        int maxLength = 0;
        
        for( int i = 0; i < arr.size(); i++ )
        {
            current_sum += arr[i];
            
            if( current_sum == k )
            {
                maxLength = i + 1;
            }
            
            if( mp.find( current_sum - k ) != mp.end() )
            {
                maxLength = max( maxLength , i - mp[current_sum - k] );
            }
            
            if( mp.find( current_sum ) == mp.end() )
            {
                mp[current_sum] = i;
            }
        }
        
        
        return  maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends