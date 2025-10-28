class Solution {
public:
    long long countStableSubarrays(vector<int>& v) {
        map<pair<long long ,long long >,long long >m;
        long long cnt=0;
        long long sum=0;
        pair<long long,long long> prev=make_pair(LLONG_MIN,0);
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(m.find({v[i],sum-1LL*2*v[i]})!=m.end()){
                cnt+=m[{v[i],sum-2*v[i]}];
            }
            m[prev]++;
            prev=make_pair(v[i],sum);
        }
        return cnt;
        
    }
};