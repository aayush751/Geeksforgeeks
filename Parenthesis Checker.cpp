//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> ans;
        
        for(int i = 0; i < x.size(); i++ )
        {
            if( ans.empty() )
            {
                ans.push(x[i]);
            }
            else if( ans.top() == '[' and x[i] == ']' or ans.top() == '(' and x[i] == ')' or ans.top() == '{' and x[i] == '}')
            {
                ans.pop();
            }
            else
            {
                ans.push(x[i]);
            }
        }
        
        if( ans.size() == 0 )
        {
            return true;
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
