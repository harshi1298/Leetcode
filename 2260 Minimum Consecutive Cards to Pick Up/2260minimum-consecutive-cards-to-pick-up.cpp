class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX,n=cards.size();
        unordered_map<int,int>mapp;
        for(int i=0;i<n;i++){
            if(mapp.find(cards[i])!=mapp.end()){
                ans=min(ans,1+i-mapp[cards[i]]);
            }
            mapp[cards[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};