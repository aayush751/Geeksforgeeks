class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ce = 0, cf = 0;
        int cnt = 0;
        for(int i=0; i<=cf; i++)
        {
            cf = max( cf, arr[i]+i);
            
            if( ce == i )
            {
                cnt++;
                ce = cf;
            }
            
            if( ce >= (n-1))
            {
                return cnt;
            }
        }
        return -1;
    }
};
