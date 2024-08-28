//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    
    // bool compare( pair< int, int > a, pair< int, int > b )
    // {
    //     if( a.first == b.first )
    //     {
    //         return a.second < b.second;
    //     }
        
    //     return a.first > b.first;
    // }
    
    
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map< int, int > mp;
        
        for(auto i: arr )
        {
            mp[i]++;
        }
        
        vector< pair< int, int > > vp;
        
        for(auto& i: mp )
        {
            vp.push_back( {i.second, i.first} );
        }
        
        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) 
        {
            if (a.first == b.first) 
            {
                return a.second < b.second; //agr kisi do ka freq same ho toh uske value ko check kro
            }
            
            return a.first > b.first;  // freq k according sort kro
        });
        
        vector<int> result;
        
        for (auto& pair : vp) 
        {
            for (int i = 0; i < pair.first; i++) 
            {
                result.push_back(pair.second);
            }
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends