class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
         int n=mat.size();
        for(int i=0;i<n;i++){
            int j=n-1-i;
            
            swap(mat[i][i],mat[i][j]);
        }
    }
};
