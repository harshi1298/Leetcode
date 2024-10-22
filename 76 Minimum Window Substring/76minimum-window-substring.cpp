#include <unordered_map>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        unordered_map<char, int> mapp1; 
        unordered_map<char, int> mapp2; 
        for (char c : t) {
            mapp1[c]++;
        }
        int l = 0, r = 0, required = mapp1.size();
        int formed = 0;
        int ansLen = INT_MAX;
        int ansLeft = 0;
        
        while (r < s.length()) {
            char c = s[r];
            mapp2[c]++;
            if (mapp1.find(c) != mapp1.end() && mapp2[c] == mapp1[c]) {
                formed++;
            }
            while (l <= r && formed == required) {
                char leftChar = s[l];
                if (r - l + 1 < ansLen) {
                    ansLen = r - l + 1;
                    ansLeft = l;
                }
                mapp2[leftChar]--;
                if (mapp1.find(leftChar) != mapp1.end() && mapp2[leftChar] < mapp1[leftChar]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ansLen == INT_MAX ? "" : s.substr(ansLeft, ansLen);
    }
};
