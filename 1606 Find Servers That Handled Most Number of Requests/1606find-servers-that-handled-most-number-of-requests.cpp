#define pr pair<int,int>
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& load) {
        set<int>st;
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        int n=arr.size();
        vector<int>countr(k);
        for(int i=0;i<k;i++)st.insert(i);
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().first<=arr[i]){
                st.insert(pq.top().second);
                pq.pop();
            }
            int num=i%k;
            if(st.empty())continue;
            auto it =st.lower_bound(num);
            if(it==st.end()){
                num=*st.begin();
            }
            else num=*it;
            st.erase(num);
            countr[num]++;
            pq.push({arr[i]+load[i],num});
        }
        int maxi=*max_element(countr.begin(),countr.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(maxi==countr[i])ans.push_back(i);
        }
        return ans;
    }
};