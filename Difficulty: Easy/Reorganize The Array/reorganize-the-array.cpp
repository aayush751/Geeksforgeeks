//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int n = arr.size();
    // Create a result vector initialized with -1
    vector<int> result(n, -1);
    
    // Traverse the input array
    for (int i = 0; i < n; i++) {
        // Place arr[i] at index arr[i] if it is within the range [0, n-1]
        if (arr[i] >= 0 && arr[i] < n) {
            result[arr[i]] = arr[i];
        }
    }
    
    // Return the result array
    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends