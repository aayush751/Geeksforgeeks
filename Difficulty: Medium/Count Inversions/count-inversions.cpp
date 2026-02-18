class Solution {
  public:
  
  
  int merge( vector<int> &arr, int l, int m, int r )
    {
        int i = l, j = m + 1;
        
        vector<int> v;
        
        int cnt =  0;
        while( i <= m and j <= r )
        {
            if( arr[i] <=arr[j] )
            {
                v.push_back(arr[i++]);
            }
            else
            {
                v.push_back(arr[j++]);
                cnt += ( m - i ) + 1;
            }
        }
        
        while( i <= m )
        {
            v.push_back(arr[i++]);
        }
        
        while( j <= r )
        {
            v.push_back(arr[j++]);
        }
        
        for(int i=l; i<=r; i++)
        {
            arr[i] = v[i-l];
        }
        
        return cnt;
    }
    
    int mergeSort( vector<int> &arr,  int l, int r )
    {
        int mid = l + ( r - l )/2;
        
        int cnt = 0;
        
        if( l < r )
        {
            cnt += mergeSort(arr, l, mid );
            
            cnt += mergeSort(arr, mid + 1 , r );
            
            cnt += merge(arr, l, mid, r);
        }
        
        return cnt;
    }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    int inversionCount(vector<int> &arr) {
        // Code Here
          // Your Code Here
        int N = arr.size();
        int ans = mergeSort(arr, 0, N - 1);
        return ans;
    }
};