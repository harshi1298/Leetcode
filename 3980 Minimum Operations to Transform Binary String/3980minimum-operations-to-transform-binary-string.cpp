class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.length();
        if (s1 == "1" && s2 == "0") {
            return -1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
              if(s1[i]=='1'){
                if(i+1<n){
                    if(s1[i+1]=='1')ans++;
                    else ans+=2;
                    s1[i+1]='0';
                }
                else ans+=2;
              }
              else ans++;
            }
        }
        return ans;
    }
};