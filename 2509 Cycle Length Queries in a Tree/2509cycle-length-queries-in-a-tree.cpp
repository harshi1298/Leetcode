class Solution {
private: 
    int cal(int u,int v){
        int ans=0;
        while(u!=v){
            if(u>v)u/=2;
            else v/=2;
            ans++;
        }
        return ans;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it : queries){
            int u=it[0];
            int v=it[1];
            ans.push_back(cal(u,v)+1);
        }
        return ans;
    }
};