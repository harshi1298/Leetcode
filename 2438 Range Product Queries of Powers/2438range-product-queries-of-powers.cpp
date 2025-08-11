class Solution {
public:
int mod = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long>arr;
        int powx=1,qt=queries.size();
        while(n){
            if(n&1){
                arr.push_back(powx);
            }
            n/=2;
            powx*=2;
        }
        
        vector<int>ans;
        for(auto it : queries){
           int st=it[0],ed=it[1];
           long long k = 1;
           for(int i=st;i<=ed;i++){
            k= (k%mod * arr[i]%(1000000007))%mod;
           }
           ans.push_back(k%(int)(1e9+7));
        }
        return ans;
    }
};