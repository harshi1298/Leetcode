class Solution {
public:
    vector<int> countServers(int h, vector<vector<int>>& logs, int x, vector<int>& queries) {
        unordered_map<int,int>mapp;
        sort(logs.begin(),logs.end(),[&](auto a,auto b){
            return a[1]<b[1];
        });
        vector<vector<int>>q;
        int l=0,r=0,n=queries.size();
        for(int i=0;i<n;i++){
            q.push_back({queries[i],i});
        }
        vector<int>ans(n);
        sort(q.begin(),q.end());
        for(int i=0;i<n;i++){
           while(r<logs.size() && logs[r][1]<=q[i][0]){
            mapp[logs[r][0]]++;
            r++;
           }
           while(l<logs.size() && logs[l][1]<q[i][0]-x){
            mapp[logs[l][0]]--;
            if(mapp[logs[l][0]]==0)mapp.erase(logs[l][0]);
            l++;
           }
           ans[q[i][1]]=(h-mapp.size());
        }
        return ans;
    }
};