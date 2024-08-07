class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> m,n;
         unordered_set<char> set1, set2;
        if(word1.length()!=word2.length()) return false;
        for(int i=0;i<word1.length();i++){
            m[word1[i]]++;
            n[word2[i]]++;
            set1.insert(word1[i]);
            set2.insert(word2[i]);
        }
        if(set1!=set2) return false;
        vector<int>fre1,fre2;
        for(auto it :m)fre1.push_back(it.second);
        for(auto it :n)fre2.push_back(it.second);
        sort(fre1.begin(),fre1.end());
        sort(fre2.begin(),fre2.end());
        return fre1==fre2;
    }
};