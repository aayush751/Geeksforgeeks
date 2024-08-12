//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        int newSize = n + m;
        int i = 0, j = 0;
        int middleFirst = newSize / 2;
        int middleSecond = newSize / 2 + 1;
        int cnt = 0;
        int sum = 0;
        
        while( i < n and j < m )
        {
            int value;
            
            if( arr1[i] <= arr2[j] )
            {
                value = arr1[i++];
            }
            else
            {
                value = arr2[j++];
            }
            
            cnt++;
            if( cnt == middleFirst or cnt == middleSecond )
            {
                sum += value;
            }
        }
        
        while (i < n) 
        {
            cnt++;
            if ( cnt == middleFirst || cnt == middleSecond ) 
            {
                sum += arr1[i];
            }
            i++;
        }
        

    // If there are remaining elements in arr2
        while (j < m) 
        {
            cnt++;
            if (cnt == middleFirst || cnt == middleSecond) 
            {
                sum += arr2[j];
            }
            j++;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends