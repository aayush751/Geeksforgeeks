class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st;

    // Insert elements of first array
    for (int x : a) {
        st.insert(x);
    }

    // Insert elements of second array
    for (int x : b) {
        st.insert(x);
    }

    // Move set elements to result vector
    vector<int> result(st.begin(), st.end());

    return result; 
    }
};