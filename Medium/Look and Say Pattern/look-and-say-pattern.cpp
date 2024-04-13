//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
       string a = "1";
        int cnt = 1;
        n = n - 1;
        string res;
        while(n--)
        {
            for(int i=0; i<a.size(); i++)
            {
                if(a[i] == a[i+1])
                {
                    cnt++;
                }
                else
                {
                    res += (cnt + '0');
                    res = res + a[i];
                    cnt = 1;
                }
            }
            a = "";
            a = res;
            res = "";
        }
          return a;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends