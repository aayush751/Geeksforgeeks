//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int size = arr.size();
        vector< int > positive;
        vector< int > negative;
        
        for(auto i: arr )
        {
            if( i < 0 )
            {
                negative.push_back( i );
            }
            else
            {
                positive.push_back( i );
            }
        }
        
        int n = positive.size();
        int m = negative.size();
        
        int i = 0, j = 0;
        int idx = 0;
        while( i < n and j < m )
        {
            arr[idx++] = positive[i];
            arr[idx++] = negative[j];
            i++;
            j++;
        }
        
        while( i < n )
        {
            arr[idx++] = positive[i];
            i++;
        }
        
        while( j <  m )
        {
            arr[idx++] = negative[j];
            j++;
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends