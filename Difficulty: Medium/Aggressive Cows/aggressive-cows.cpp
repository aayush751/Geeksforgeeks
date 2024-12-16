//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool check(vector<int> &v, int mid , int cows)
    {
        int c_count = 1;
        int last = v[0];
        
        for(int i = 1; i < v.size(); i++ )
        {
            if( v[i] - last >= mid )
            {
                c_count++;
                last = v[i];
                if( c_count == cows )
                {
                    return true;
                }
            }
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k ) {
    
        // Write your code here
        int n = stalls.size();
        
        sort(begin(stalls), end(stalls));
        int s = 0;
        int e = stalls[n-1] - stalls[0];
        
        int mid = s + ( e - s )/2;
        int result = 0;
        while( s <= e )
        {
            int ans = check(stalls, mid, k );
            if( ans == 1 )
            {
                result = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + ( e - s )/2;
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends