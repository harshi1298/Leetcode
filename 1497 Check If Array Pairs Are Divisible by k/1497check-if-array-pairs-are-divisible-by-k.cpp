class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        multiset<int> st;
        for(int x : arr) {
            int mod = ((x % k) + k) % k;
            if(mod == 0) {
                auto it = st.find(0);
                if(it != st.end()) {
                    st.erase(it);
                    continue;
                }
            } else {
                int complement = k - mod;
                auto it = st.find(complement);
                if(it != st.end()) {
                    st.erase(it);
                    continue;
                }
            }
            st.insert(mod);
        }
        return st.empty();
    }
};
