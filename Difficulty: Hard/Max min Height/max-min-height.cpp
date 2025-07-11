class Solution {
  public:
  
     bool possible(int n,vector<int> a,int k,int w,int mid){
        for(int i=0;i<n;i++){
            if(a[i]<mid){
                int temp = mid-a[i];
                if(temp>k)return false;
                k-=temp;
                a[i]=mid;
                for(int j=i+1;j<n and j<i+w;j++){
                    a[j]+=temp;
                }
            }
        }
        return true;
    }
  
    
    
    
    int maxMinHeight(vector<int> &a, int k, int w) {
        // code here
         int mn=INT_MAX,mx;
         int n = a.size();
        for(int i=0;i<n;i++)mn=min(mn,a[i]);
        mx=mn+k;
        int ans;
        while(mn<=mx){
            int mid = (mn+mx)/2;
            if(possible(n,a,k,w,mid)){
                ans=mid;
                mn=mid+1;
            }
            else mx=mid-1;
        }
        return ans;
    }
};