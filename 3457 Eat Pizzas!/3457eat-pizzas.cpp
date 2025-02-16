class Solution {
public:
    long long maxWeight(vector<int>& p) {
        sort(p.begin(),p.end());
        long long ans=0;
        int size=p.size();
        int o_c=((size/4+1)/2);
        for(int i=0;i<o_c;i++){
            ans=ans+p[size-i-1];
        }
        for(int i=1;i<=(size/4)-o_c;i++){
            ans+=(p[size-o_c-(2*i)]);
        }
        return ans;
    }
};