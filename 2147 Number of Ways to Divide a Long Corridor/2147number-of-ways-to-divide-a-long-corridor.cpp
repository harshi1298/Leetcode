class Solution {
int mod=1e9+7;
public:
    int numberOfWays(string c) {
        int n=c.length();
        vector<int>seat;
        for(int i=0;i<n;i++){
           if(c[i]=='S')seat.push_back(i);
        }
        n=seat.size();
        long long ans=1;
        if(n==0 || n%2!=0)return 0;
        for(int i=2;i<n;i+=2){
         ans*=(seat[i]-seat[i-1]);
         ans%=mod;
        }
        return ans;
    }
};