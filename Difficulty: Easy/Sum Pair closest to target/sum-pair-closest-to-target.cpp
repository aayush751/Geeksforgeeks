//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort( begin(arr), end(arr) );
        vector< int > result;
        int n = arr.size();
        
        int closestDiff = INT_MAX;
        
        int start = 0, end = n -1;
        
        while( start < end )
        {
            int pairSum = arr[start] + arr[end];
            int currentDiff = abs( target - pairSum );
            
            if( currentDiff < closestDiff )
            {
                closestDiff = min( closestDiff, currentDiff );
                result = { arr[start], arr[end] };
            }
            
            if( pairSum > target )
            {
                end--;
            }
            else if( pairSum < target )
            {
                start++;
            }
            else
            {
                return result;
            }
            
        }
        
        return result;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends