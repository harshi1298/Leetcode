class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int i=-1,j=0;
        while(s[j]=='0')j++;
        i=j-1;
        for(;j<s.length();j++){
           if(s[j]=='0'){
            i++;
             ans=ans+j-i;
            swap(s[i],s[j]);      
           }
        }
        return ans;
    }
};