class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int arr[26]={0};
        int brr[26]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
            brr[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=brr[i])return false;
        }
        return true;
    }
};