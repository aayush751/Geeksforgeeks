//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   bool isNumber(const string& str) {
        for (char ch : str) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        return true;
    }
    long long ExtractNumber(string s ) {

        // code here
        istringstream ss(s);
        
        string word;
        
        vector< string > words;
        
        while( ss >> word )
        {
            words.push_back( word );
        }
        
        long long largestNumber = -1;
        
        for (const string& word : words) {
            
            if (isNumber(word) && word.find('9') == string::npos) {
                
                long long num = stoll(word);
                largestNumber = max(largestNumber, num);
            }
        }

        return largestNumber;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends