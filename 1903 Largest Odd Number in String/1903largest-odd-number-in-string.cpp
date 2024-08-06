class Solution {
public:
    string largestOddNumber(string num) {
        int k=num.length()-1;
        while(k>=0 && (num[k]-'0')%2==0)k--;
        string ans="";
        for(int i=0;i<=k;i++)ans+=num[i];
        return ans;
    }
};