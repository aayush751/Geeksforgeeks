class Solution {
  public:
  
  
   static string help(int i,int j,vector<vector<int>> &brackets){
        if(i==j){
            char a = 'A'+i-1;
            string temp="";
            temp+=a;
            return temp;
        }
        return '('+ help(i,brackets[i][j],brackets)+help(brackets[i][j]+1,j,brackets) +')';
    }
    string matrixChainOrder(vector<int> &p) {
        // code here
        int n = p.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        vector<vector<int>> brackets(n,vector<int>(n,0));
        for(int i=0;i<n;i++)dp[i][i]=0;
        for(int i=2;i<n;i++){
            for(int j=1;j<n-i+1;j++){
                int end = j+i-1;
                for(int k=j;k<end;k++){
                    int total = dp[j][k]+dp[k+1][end]+p[j-1]*p[k]*p[end];
                    if(total<dp[j][end]){
                        dp[j][end]=total;
                        brackets[j][end]=k;
                    }
                }
            }
        }
        return help(1,n-1,brackets);
    }
};