#define pr pair<char,int>
class Solution {
private:
    struct cmp {
        bool operator()(const pr &a, const pr &b) const {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second; 
        }
    };
public:
    string clearStars(string s) {
        int n = s.length();
        unordered_set<int> st;
        priority_queue<pr, vector<pr>, cmp> pq;

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                st.insert(pq.top().second);
                pq.pop();
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (st.find(i) == st.end() && s[i] != '*') {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
