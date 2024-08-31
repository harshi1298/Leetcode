class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<int>pq;
        int k=damage.size();
        for(int i=0;i<k;i++){
            pq.push_back(i);
        }
        sort(pq.begin(),pq.end(),[&] (auto a,auto b){
            int p=health[a]/power;
            if(health[a]%power) p++;
            int q=health[b]/power;
            if(health[b]%power) q++;
            return damage[a]*q>damage[b]*p;
        });
        int x=0;
        long long ans=0;
        for(int i=0;i<k;i++){
            int p=health[pq[i]]/power;
            if(health[pq[i]]%power)p++;
            x+=p;
            ans+=damage[pq[i]]*x;
        }
        return ans;
    }
};