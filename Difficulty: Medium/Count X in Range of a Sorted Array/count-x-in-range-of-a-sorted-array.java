class Solution {
    public ArrayList<Integer> countXInRange(int[] arr, int[][] queries) {
        ArrayList<Integer> res = new ArrayList<>();

        HashMap<Integer, int[]> pos = new HashMap<>();

        // Step 1: Precompute first & last occurrence
        for (int i = 0; i < arr.length; i++) {
            if (!pos.containsKey(arr[i])) {
                pos.put(arr[i], new int[]{i, i});
            } else {
                pos.get(arr[i])[1] = i;
            }
        }

        // Step 2: Answer queries in O(1)
        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            if (!pos.containsKey(x)) {
                res.add(0);
                continue;
            }

            int first = pos.get(x)[0];
            int last  = pos.get(x)[1];

            int start = Math.max(first, l);
            int end   = Math.min(last, r);

            res.add(start > end ? 0 : end - start + 1);
        }

        return res;
    }
}
