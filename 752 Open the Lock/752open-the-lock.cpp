class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>vis;
        for(auto it : deadends){
            vis.insert(it);
        }
        if(vis.find("0000")!=vis.end())return -1;
        queue<pair<string,int>>que;
        que.push({"0000",0});
        vis.insert("0000");
        while(!que.empty()){
            auto[k,ans]=que.front();
            que.pop();
            if(k==target)return ans;
            for(int i=0;i<4;i++){
                string t=k;
                int l=t[i]-'0';
                t[i]=(l+1)%10+'0';
                if(vis.find(t)==vis.end()){
                    que.push({t,ans+1});
                    vis.insert(t);
                }
                l=(l+10-1)%10;
                t[i]=l+'0';
                if(vis.find(t)==vis.end()){
                    que.push({t,ans+1});
                    vis.insert(t);
                };
            }
        }
        return -1;
    }
};