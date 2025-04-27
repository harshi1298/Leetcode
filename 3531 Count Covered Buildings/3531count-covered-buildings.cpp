class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<vector<int>>row(n+1);
        vector<vector<int>>col(n+1);
         int ans=0;
        for(auto it:b ){
            row[it[0]].push_back(it[1]);
            col[it[1]].push_back(it[0]);
        }
        for(auto &it:row) sort(it.begin(),it.end());
        for(auto &it:col) sort(it.begin(),it.end());
        for(auto it:b ){
            int r=it[0],c=it[1];
            int l1=row[r].size(),l2=col[c].size();
            if(l1<=2 || l2<=2) continue;
            else if(row[r][0]==c || col[c][0]==r || row[r][l1-1]==c || col[c][l2-1]==r) continue;
            ans++;
        }
        return ans;
    }
};