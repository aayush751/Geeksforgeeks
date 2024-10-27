//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n = arr.size();
        
        sort( begin(arr), end(arr) );
        
        for( int i = 0; i < n; i++ )
        {
            int left = 0, right = n - 1;
            
            while( left < right )
            {
                if( left == i )
                {
                    left++;
                    continue;
                }
                
                if( right == i )
                {
                    right--;
                    continue;
                }
                
                int sum = arr[left] + arr[right];
                
                if( sum == arr[i] )
                {
                    return true;
                }
                else if( arr[left] + arr[right] < arr[i] )
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends