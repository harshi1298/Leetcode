class Solution {
public:
    int titleToNumber(string c) {
        int s=c.length();
        long long k=1;
        long long l=0;
        for(int i=0;i<s;i++){
            l=l+(int(c[s-1-i])-64)*k;
            k=k*26;
        }
        return l;
    }
};