class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> a, b;
        int j = 0;

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] == '.') {
                a.push_back(stoi(v1.substr(j, i - j)));
                j = i + 1;
            }
        }
        a.push_back(stoi(v1.substr(j)));

        j = 0;
        for (int i = 0; i < v2.size(); i++) {
            if (v2[i] == '.') {
                b.push_back(stoi(v2.substr(j, i - j)));
                j = i + 1;
            }
        }
        b.push_back(stoi(v2.substr(j)));

        int n = max(a.size(), b.size());
        while (a.size() < n) a.push_back(0);
        while (b.size() < n) b.push_back(0);

        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) return -1;
            if (a[i] > b[i]) return 1;
        }

        return 0;
    }
};
