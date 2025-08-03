class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        int maxi=0,n=w.size();
        int ans=0;
        for(int i=0;i<n;i++){
           maxi=max(maxi,w[i]);
           if(maxi>w[i]){
            ans++;
            maxi=0;
           }
        }
        return ans;
    }
};