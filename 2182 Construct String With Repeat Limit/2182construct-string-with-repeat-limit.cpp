class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> str(26, 0); 
        for (char ch : s) {
            str[ch - 'a']++;
        }
        string ans;
        int count = 0; 
        while (true) {
            bool found = false;
            for (int i = 25; i >= 0; i--) {
                if (str[i] > 0) {
                    if (!ans.empty() && ans.back() == (char)(i + 'a')) {
                        if (count == repeatLimit) {
                            continue; 
                        }
                        count++;
                    } else {
                        count = 1;
                    }
                    ans.push_back((char)(i + 'a'));
                    str[i]--; 
                    found = true; 
                    break; 
                }
            }
            if (!found) {
                break;
            }
        }
        return ans;
    }
};
