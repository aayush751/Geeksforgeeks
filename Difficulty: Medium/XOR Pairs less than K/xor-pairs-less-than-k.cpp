class Solution {
    
    
    
     struct Trie {
        Trie* child[2];
        int cnt;
        Trie() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };
    
    
     long long countLess(int x, int k) {
        Trie* node = root;
        long long ans = 0;

        for (int i = 31; i >= 0; i--) {
            if (!node) break;

            int bitX = (x >> i) & 1;
            int bitK = (k >> i) & 1;

            if (bitK == 1) {
                // Add all nums where XOR bit becomes 0
                if (node->child[bitX])
                    ans += node->child[bitX]->cnt;

                // Move to branch where XOR bit becomes 1
                node = node->child[bitX ^ 1];
            }
            else {
                // Must keep XOR bit = 0
                node = node->child[bitX];
            }
        }
        return ans;
    }
    
    Trie* root;

    void insert(int num) {
        Trie* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new Trie();
            node = node->child[bit];
            node->cnt++;
        }
    }
  public:
    int cntPairs(vector<int>& arr, int k) {
        // code here
        root = new Trie();
        int result = 0;

        for (int x : arr) {
            result += countLess(x, k);
            insert(x);
        }

        return result;
    }
};