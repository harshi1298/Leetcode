class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({endTime[i],startTime[i]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<pair<int,int>> pq;
        int prev=0,idx=-1;
        for(int i=0;i<n;i++){
            pq.push({vec[i].second-prev,idx});
            idx++;
            prev=vec[i].first;
        }
        pq.push({eventTime-prev,idx});
        int maxi=0,ans=vec[0].second;
        prev=0;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().second<=i) pq.pop();
            int start=i==0?0:vec[i-1].first;
            int end=i==n-1?eventTime:vec[i+1].second;
            if(!pq.empty() && pq.top().first>=vec[i].first-vec[i].second){
                ans=max(ans,end-start);
            }
            else if(maxi>=vec[i].first-vec[i].second){
                ans=max(ans,end-start);
            }
            ans=max(ans,end-start-vec[i].first+vec[i].second);
            maxi=max(maxi,vec[i].second-prev);
            prev=vec[i].first;
        }
        return ans;
    }
};