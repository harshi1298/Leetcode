class Solution {
private:
    string bits(int n){
        string str;
        while(n>0){
            str.push_back('0'+n%2);
            n>>=1;
        }
        return str;
    }
public:
    int minimumOneBitOperations(int n) {
        string str=bits(n);
        int m=str.length();
        vector<int> dp(m+1,0);
        int prev=dp[0];
        for(int i=1;i<=m;i++){
            dp[i]=i+prev;
            prev+=dp[i];
        }
        int ans=0;
        int odd=1;
        for(int i=m;i>=1;i--){ 
            if(str[i-1]=='1'){
                ans+=(odd?1:-1)*dp[i];
                odd=1-odd;
            }
        
        }
        return ans;
    }
};