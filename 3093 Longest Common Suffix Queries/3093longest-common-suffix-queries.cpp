class Trie {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    Trie() {
        trie.push_back(Node()); // root
    }

    void insert(string &s, int id) {

        int node = 0;

        if (trie[node].idx == -1)
            trie[node].idx = id;

        for (char ch : s) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1) {

                trie[node].child[c] = trie.size();

                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if (trie[node].idx == -1)
                trie[node].idx = id;
        }
    }

    int search(string s) {

        reverse(s.begin(), s.end());

        int node = 0;

        int ans = trie[node].idx;

        for (char ch : s) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1)
                return ans;

            node = trie[node].child[c];

            ans = trie[node].idx;
        }

        return ans;
    }
};

class Solution {
public:

    vector<int> stringIndices(vector<string>& wc,
                              vector<string>& wq) {

        vector<pair<string,int>> arr;

        int n = wc.size();

        for (int i = 0; i < n; i++) {

            reverse(wc[i].begin(), wc[i].end());

            arr.push_back({wc[i], i});
        }

        sort(arr.begin(), arr.end(),
        [&](auto &a, auto &b){

            if (a.first.length() == b.first.length())
                return a.second < b.second;

            return a.first.length() < b.first.length();
        });

        Trie trie;

        for (auto &it : arr) {
            trie.insert(it.first, it.second);
        }

        vector<int> ans;

        for (auto &q : wq) {
            ans.push_back(trie.search(q));
        }

        return ans;
    }
};