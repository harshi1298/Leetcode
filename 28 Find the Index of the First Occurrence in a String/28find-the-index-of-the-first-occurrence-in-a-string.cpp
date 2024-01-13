class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n= needle.length();
        for(int i=0;i<m-n+1;i++){
            int l=0;
            for(int j=0;j<n;j++){
                if(haystack[i+j]==needle[j]){
                    l++;
                }
                else
                break;
            }
            if(l==n){
                return i;
            }
        }
        return -1;
    }
};