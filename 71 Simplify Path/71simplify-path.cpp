class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.length();
        string t = "";
        
        for (int i = 0; i <= n; i++) {
            if (i < n && path[i] != '/') {
                t.push_back(path[i]);
            } else {
                if (!t.empty()) {
                    if (t == ".") {
                        // ignore
                    } else if (t == "..") {
                        if (!st.empty()) st.pop();
                    } else {
                        st.push(t);
                    }
                    t.clear();
                }
            }
        }
        vector<string> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        
        string ans = "/";
        for (int i = 0; i < temp.size(); i++) {
            ans += temp[i];
            if (i + 1 < temp.size()) ans += "/";
        }
        return ans;
    }
};
