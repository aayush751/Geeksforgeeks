//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        
        unordered_set<char> sp;
        
        for(int i = 0; i < s.size(); i++ )
        {
            if( (s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122) )
            {
                if( isupper(s[i]) )
                {
                    s[i] = s[i] + 32;
                    sp.insert(s[i]);
                }
                else
                {
                    sp.insert(s[i]);
                }
            }
        }
        
        if( sp.size() == 26 )
        {
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends