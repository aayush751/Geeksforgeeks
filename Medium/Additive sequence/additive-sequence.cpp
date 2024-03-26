//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
// User function template for C++
class Solution {
  public:
  string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;

        string ans;
        
        int carry= 0;
        while( n1 >= 0 or n2 >= 0 )
        {
            if( n1 < 0 )
            {
                ans.push_back( ((num2[n2] - 48 + carry) % 10) + 48 );
                carry = (carry + num2[n2] - 48) / 10;
                n2--;
            }
            else if( n2 < 0 )
            {
                ans.push_back( ((num1[n1] - 48 + carry) % 10) + 48 );
                carry = (carry + num1[n1] - 48) / 10;
                n1--;
            }
            else
            {
                ans.push_back( ((num1[n1] - 48 + num2[n2] - 48 + carry) % 10) + 48 );
                carry = ((num1[n1] - 48 + num2[n2] - 48 + carry) / 10);
                n1--;
                n2--;
            }
        }

        if( carry )
        {
            ans.push_back( carry + 48 );
        }

        reverse( begin(ans) , end( ans ) );

        return ans;

    }
    bool isAdditiveSequence(string num) {
        // Your code here
        int n=num.length();
        if(n<3) return false;
        for(int i=1;i<=n/2;i++){
            for(int j=1;max(i,j)<=n-i-j;j++){
                string first=num.substr(0,i);
                string second=num.substr(i,j);
                
                if(first.length()>1 && first[i]=='0'){
                    break;
                }
                if(second.length()>1 && second[i]=='0'){
                    break;
                }
                
                int start=i+j;
                string sum;
                while(start<n){
                    sum=addStrings(first, second);
                    if(start+sum.length()>n || sum!=num.substr(start, sum.length())){
                        break;
                    }
                    first=second;
                    second=sum;
                    start+=sum.length();
                }
                if(start==n){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends