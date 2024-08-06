//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        
        // check kro ki string valid hai ya nhi
        if( str.size() > 15 or str.empty() ) 
        {
            return false;
        }
        
        vector< string > parts;
        string temp;
        
        for(int i = 0; i < str.size(); i++ )
        {
            if( str[i] != '.' )
            {
                temp += str[i];
            }
            else
            {
                parts.push_back( temp );
                temp = "";
            }
        }
        parts.push_back( temp );
        
        // parts wala vector ka size agr 4 se aage piche hain toh false return kro
        if( parts.size() != 4 )
        {
            return false;
        }
        
        // ab har part ko check kro
        for( string& part: parts )
        {
            if( part.empty() or part.size() > 3 )
            {
                return false;
            }
            
            if( part.size() > 1 and part[0] == '0' )
            {
                return false;
            }
            
            // check kro ki wo string me valid input hai ya nhi..mtlb sirf digit hai hi hai nh koe alphabest toh nhi hai nh
            for( char ch: part )
            {
                if( !isdigit(ch) )
                {
                    return false;
                }
            }
            
            int value = stoi( part );
            if( value < 0 or value > 255 )
            {
                return false;
            }
        }
        return true;
    }
    
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends