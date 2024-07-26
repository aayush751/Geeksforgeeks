//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector< int > freq(26, 0);
        int space_counter = 0;
        
        for(int i = 0; i < str.size(); i++ )
        {
            if( str[i] >= 97 and str[i] <= 122 )
            {
                freq[str[i] - 'a']++;
            }
            else
            {
                space_counter++;
            }
        }
        
        // cout<< str.size() << endl;
        
        int missingCounter = 0;
        
        for(int i = 0; i < 26; i++ )
        {
            if( freq[i] == 0 )
            {
                missingCounter++;
            }
        }
        
        int size = str.size() - space_counter;
        
        if( size < 26 or missingCounter > k )
        {
            return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends