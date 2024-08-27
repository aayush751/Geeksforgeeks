//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int size = arr.size();
        vector< int > left( size );
        vector< int > right( size );
        
        stack<int> s;

    // Fill left array
    for (int i = 0; i < size; i++) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(arr[i]);
    }

    // Clear stack to reuse for right array
    while (!s.empty()) {
        s.pop();
    }

    // Fill right array
    for (int i = size - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(arr[i]);
    }

    // Calculate max difference
    int maxDiff = INT_MIN;
    for (int i = 0; i < size; i++) {
        maxDiff = max(maxDiff, abs(left[i] - right[i]));
    }

    return maxDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends