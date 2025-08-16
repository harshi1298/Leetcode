class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int n=pos.size();
        int ans=n+1;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
               temp+=(abs(pos[i]-pos[j])%2);
            }
            ans=min(ans,temp);
        }
        return ans;
    }
};