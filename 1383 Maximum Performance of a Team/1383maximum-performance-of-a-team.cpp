class Solution {
private:
    int mod=1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({efficiency[i],speed[i]});
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(arr.rbegin(), arr.rend());
        long long sum=0,ans=0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            }
            pq.push(arr[i].second);
            sum+=1ll*arr[i].second;
            ans=max(ans,sum*arr[i].first);
        }
        return ans%mod;
    }
};