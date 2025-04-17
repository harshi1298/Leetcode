class Solution {
public:
    int maxOperations(string s) {
        int l=s.length();
        int ans=0;
        int count=0;
        int prev=0;
        for(int i=0;i<l;i++){
            if(s[i]=='1'){
                count++;
                prev=0;
            }
            if(s[i]=='0' && !prev){ans+=count;prev=1;}
        }
        return ans;
    }
};