//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        long long total_pairs = 0;

    // Count the occurrences of 1, 2, 3, and 4 in brr
    int count_1 = count(brr.begin(), brr.end(), 1);
    int count_2 = count(brr.begin(), brr.end(), 2);
    int count_3 = count(brr.begin(), brr.end(), 3);
    int count_4 = count(brr.begin(), brr.end(), 4);

    // Sort brr to apply binary search
    vector<int> sorted_brr = brr;
    sort(sorted_brr.begin(), sorted_brr.end());

    for (int x : arr) {
        if (x == 1) {
            continue;  // 1^y is never > y^1 for any y > 1
        }

        // Find the first y in sorted_brr where y > x using binary search
        auto pos = upper_bound(sorted_brr.begin(), sorted_brr.end(), x);
        total_pairs += (sorted_brr.end() - pos);

        if (x == 2) {
            // Special handling for x = 2
            total_pairs -= (count_3 + count_4);  // Subtract cases where y=3 or y=4
            total_pairs += count_1;  // Add cases where y=1, as 2^1 > 1^2
        }

        if (x == 3) {
            // Special handling for x = 3
            total_pairs += count_1 + count_2;  // Add cases where y=1,2
        } else if (x > 3) {
            // For x > 3, add cases where y=1
            total_pairs += count_1;
        }
    }

    return total_pairs;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends