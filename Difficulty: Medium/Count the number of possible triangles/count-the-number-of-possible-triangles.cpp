//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        sort( begin(arr), end(arr) );
        
        int n = arr.size();
        
        int ans = 0;
        
        for(int i = n - 1; i >= 0; i-- )
        {
            int start = 0, end = i - 1;
            
            while( start < end )
            {
                if( arr[start] + arr[end] > arr[i] )
                {
                    ans += end - start;
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        
        return ans;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends