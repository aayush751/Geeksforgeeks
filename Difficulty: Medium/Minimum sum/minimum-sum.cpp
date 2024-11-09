//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
         int n = arr.size();
        sort(arr.begin(),arr.end());
        string num1="",num2="";
        for(int i=0;i<n;i++){
            if(i%2)num1+='0'+arr[i];
            else num2+='0'+arr[i];
        }
        n=num1.size();
        int m = num2.size(),i=n-1,j=m-1,carry=0;
        string ans="";
        while(i>-1 || j>-1 || carry){
            int temp1=i>-1?num1[i]-'0':0;
            int temp2=j>-1?num2[j]-'0':0;
            int num = temp1+temp2+carry;
            ans+='0'+num%10;
            carry=num/10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        for(i=0;i<ans.length();i++){
            if(ans[i]!='0')break;
        }
        return ans.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends