class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mapp;
        for (char c : s) {
            mapp[c]++;
        }
        stack<char> st;
        unordered_set<char> vis;

        for (char c : s) {
            mapp[c]--;
            if (vis.find(c) != vis.end()) {
                continue;
            }
            while (!st.empty() &&st.top() > c && mapp[st.top()] > 0) {
                vis.erase(st.top());
                st.pop();
            }
            st.push(c);
            vis.insert(c);
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};