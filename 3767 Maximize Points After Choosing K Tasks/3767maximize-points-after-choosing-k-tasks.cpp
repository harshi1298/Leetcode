class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        long long ans=0;
        int n=t1.size();
        unordered_set<int>st;
        int count=0;
        for(int i=0;i<n;i++){
            if(t1[i]>=t2[i]){
                ans+=1ll*t1[i];
                count++;
                st.insert(i);
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        if(count<k){
            vector<int>arr;
            for(int i=0;i<n;i++){
                if(st.find(i)==st.end()){
                    pq.push({t2[i]-t1[i],i});
                }
            }
            while(count<k){
                ans+=t1[pq.top().second];
                st.insert(pq.top().second);
                pq.pop();
               count++; 
            }
        }
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()){
                ans+=t2[i];
            }
        }
        return ans;
    }
};