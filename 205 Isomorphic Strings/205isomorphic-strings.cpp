class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char>m;
        unordered_map<char,char>n;
        for(int i=0;i<s.length();i++){
            char sChar = s[i];
            char tChar = t[i];
            if(m.find(sChar)==m.end()) m[sChar]=tChar;
            else {
                if(m[sChar]!=tChar)return false;
            }
            if(n.find(tChar)==n.end()) n[tChar]=sChar;
            else {
                if(n[tChar]!=sChar)return false;
            }
        }
        return true;
    }
};