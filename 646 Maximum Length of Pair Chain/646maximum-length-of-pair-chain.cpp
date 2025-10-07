class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](auto a,auto b){
            return a[1]<b[1];
        });
        int ans=0;
        int prev=-1001;
        for(auto it : pairs){
            if(it[0]>prev){
                ans++;
                prev=it[1];
            }
        }
        return ans;
    }
};