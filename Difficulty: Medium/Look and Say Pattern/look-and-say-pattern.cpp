//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
         if (n == 1) {                              
            return "1";
        }

        string say = countAndSay(n - 1);                          
        // Processing:
        string result = "";                                       

        for (int i = 0; i < say.length(); i++) {                  
            char ch    = say[i];                                 
            int  count = 1;                                       

            while (i < say.length() - 1 && say[i] == say[i + 1]) { 
                count++;                                          
                i++;                                              
            }

            result += to_string(count) + string(1, ch);    
        }

        return result;  
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends