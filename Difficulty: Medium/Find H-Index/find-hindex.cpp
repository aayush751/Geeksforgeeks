class Solution {
  public:
    int hIndex(vector<int>& arr ) {
        // code here
        sort(arr.begin(), arr.end());
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int num= n-i;
            ans=max(ans, min(num, arr[i]));
        }
        return ans;
    }
};