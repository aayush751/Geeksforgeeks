class Solution {
    public ArrayList<ArrayList<Integer>> applyDiff2D(int[][] mat, int[][] opr) {
        // code here
           int n = mat.length;
        int m = mat[0].length;

                    
        int[][] diff = new int[n + 1][m + 1];  
 
        for (int[] op : opr) {
            int v = op[0];
            int r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];

            diff[r1][c1] += v;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= v;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= v;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }

        // Step 3: Convert diff to prefix sum matrix
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }
        // int sum=0;
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                // sum+=diff[i][j];
                row.add(mat[i][j] +diff[i][j]);
            }
            result.add(row);
        }

        return result;
    }
}