//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        
        int count1 = 0, count2 = 0;
        int maj1 = -1, maj2 = -1;
        
        for(int i = 0; i < n; i++ )
        {
            if( maj1 == arr[i] )
            {
                count1++;
            }
            else if( maj2 == arr[i] )
            {
                count2++;
            }
            else if( count1 == 0 )
            {
                maj1 = arr[i];
                count1++;
            }
            else if( count2 == 0 )
            {
                maj2 = arr[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        int freq1 = 0;
        int freq2 = 0;
        vector< int > result;
        
        for(int &num: arr )
        {
            if( num == maj1 )
            {
                freq1++;
            }
            else if( num == maj2 )
            {
                freq2++;
            }
        }
        
        if( freq1 > floor( n / 3 ) )
        {
            result.push_back( maj1 );
        }
        
        if( freq2 > floor( n / 3 ) )
        {
            result.push_back( maj2 );
        }
        
        if( result.size() == 2 and result[0] > result[1] )
        {
            swap( result[0], result[1] );
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends