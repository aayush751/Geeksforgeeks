//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        
        // code here
         int n = arr.size();
    
    // If the array has less than 2 elements, return -1
    if (n < 2) {
        return -1;
    }
    
    int maxSum = -1; // Initialize the maximum sum
    
    // Traverse the array and compare adjacent elements
    for (int i = 0; i < n - 1; i++) {
        int first = arr[i];
        int second = arr[i + 1];
        
        // Calculate the sum of the smallest and second smallest in the adjacent pair
        int currentSum = first + second;
        
        // Update the maximum sum
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    
    return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends