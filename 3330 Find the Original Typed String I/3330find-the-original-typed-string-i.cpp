class Solution {
public:
    int possibleStringCount(string s) {
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])count++;
        }
       return count;
    }
};