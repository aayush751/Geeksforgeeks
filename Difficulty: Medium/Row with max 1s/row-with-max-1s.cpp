// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int one_count = 0;
        int idx = -1;
        
        for(int i = 0; i < arr.size(); i++ )
        {
            int temp = count( arr[i].begin(), arr[i].end() , 1 );
            
            if( temp > one_count )
            {
                one_count = temp;
                idx = i;
            }   
        }
        
        return ( idx == -1 ) ? -1 : idx;
    }
};