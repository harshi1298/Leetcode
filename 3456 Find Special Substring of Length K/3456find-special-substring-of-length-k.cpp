class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int l=0;
        for(int r=0;r<s.length();){
            bool flag=0;
            while(s[r]==s[l]){
                r++;
                flag=1;
            }
            if(flag==0)r++;
            if(r-l==k)return true;
            l=r;
        }
        return false;
    }
};