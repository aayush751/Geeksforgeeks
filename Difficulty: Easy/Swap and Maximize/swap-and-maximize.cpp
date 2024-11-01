//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort( begin(arr), end(arr) );
        
        vector< int > size;
        
        int i = 0, j = arr.size() - 1;
        
        while( i < j )
        {
            size.push_back( arr[j--] );
            size.push_back( arr[i++] );
        }
        
        if( arr.size() % 2 == 1 ) // if array size is odd then insert any of the index value
        {
            size.push_back( arr[j] );
        }
        
        i = 0, j = 1;
        long long sum = 0;
        
        while( j < arr.size() )
        {
            sum += abs( size[i++] - size[j++] );
        }
        
        sum += abs( size[0] - size[size.size() - 1] );
        
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends