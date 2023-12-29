//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long res_sum = 0;
        
        long temp = 0;
        
        
        for(int i = 0; i < K; i++ )
        {   
            temp += Arr[i];
        }
        
        res_sum = temp;
        
        long left = 0;
        
        for(int i = K; i < N; i++ )
        {
            temp += Arr[i];
            
            temp -= Arr[left++];
            
            
            if( temp > res_sum )
            {
                res_sum = temp;
            }
        }
        
        return res_sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
