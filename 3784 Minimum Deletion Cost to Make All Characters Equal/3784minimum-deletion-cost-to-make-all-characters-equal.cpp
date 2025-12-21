class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_set<char>st;
        for(auto it : s){
            st.insert(it);
        }
        long long ans=LLONG_MAX;
        int n=cost.size();
        for(auto c: st){
            long long count=0;
            for(int i=0;i<n;i++){
                if(s[i]!=c)count+=1ll*cost[i];
            }
            ans=min(ans,count);
        }
        return ans;
    }
};