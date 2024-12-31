//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set< int > st;
        
        for( auto ele: arr )
        {
            st.insert( ele );
        }
        
        int size = 1;
        int maxi = 0;
        for(int i = 0; i < arr.size(); i++ )
        {
            int minusOne = arr[i] - 1;
            
            if( st.find( minusOne ) != st.end() )
            {
                continue;
            }
            else
            {
                int value = arr[i] + 1;
                while( st.find(value) != st.end() )
                {
                    size++;
                    value++;
                }
            }
            
            maxi = max( maxi, size );
            size = 1;
        }
        
        return maxi;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends