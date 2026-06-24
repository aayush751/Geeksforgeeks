class Solution {
  public:
  
 bool solveMaze(int r, int c, const vector<vector<int>>& mat, vector<vector<int>>& sol, vector<vector<int>>& memo, int n) {
        // Base Case: मंज़िल (Bottom-Right) पर पहुँच गए
        if (r == n - 1 && c == n - 1) {
            sol[r][c] = 1;
            return true;
        }

        // चेक करें कि सेल वैलिड है और क्या हम पहले ही इसे 'Dead End' (-1) घोषित तो नहीं कर चुके
        if (r >= 0 && r < n && c >= 0 && c < n && mat[r][c] != 0 && memo[r][c] != -1) {
            
            sol[r][c] = 1; // रास्ते में शामिल करें
            int max_jump = mat[r][c];

            // सबसे छोटे जंप (1) से शुरुआत करें
            for (int step = 1; step <= max_jump; ++step) {
                
                // Priority 1: दाएँ (Right) जाएँ
                if (c + step < n) {
                    if (solveMaze(r, c + step, mat, sol, memo, n)) return true;
                }
                
                // Priority 2: नीचे (Down) जाएँ
                if (r + step < n) {
                    if (solveMaze(r + step, c, mat, sol, memo, n)) return true;
                }
            }

            // अगर यहाँ तक आ गए, मतलब इस सेल से कोई रास्ता मंज़िल तक नहीं जाता
            // Backtrack करें और इस सेल को हमेशा के लिए 'Dead End' (-1) मार्क कर दें
            sol[r][c] = 0;
            memo[r][c] = -1; // MEMOIZATION MAGIC 🪄 (TLE बचाने के लिए)
            return false;
        }
        
        return false;
    }
  
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        // code here
       int n = mat.size();
        
        vector<vector<int>> sol(n, vector<int>(n, 0));
        
        // एक memo मैट्रिक्स बनाएँ जो याद रखेगा कि कौन सा सेल बेकार है
        vector<vector<int>> memo(n, vector<int>(n, 0));

        // अगर शुरुआत ही ब्लॉक है
        if (mat[0][0] == 0 && n > 1) {
            return {{-1}};
        }

        if (solveMaze(0, 0, mat, sol, memo, n)) {
            return sol;
        }

        // कोई रास्ता नहीं मिला
        return {{-1}};
    }
};