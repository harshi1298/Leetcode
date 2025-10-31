class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n = h.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[i] <= h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int height = h[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            ans = max(ans, height * width);
        }

        return ans;
    }
};
