class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occ, int fs, int fe) {
        vector<vector<int>>ans;
        sort(occ.begin(),occ.end());
        ans.push_back(occ[0]);
        int n=occ.size();
        for(int i=1;i<n;i++){
            if(ans.back()[1]+1>=occ[i][0]){
                ans.back()[1]=max(ans.back()[1],occ[i][1]);
            }
            else{
                ans.push_back(occ[i]);
            }
        }
        vector<vector<int>>temp;
        for(auto it : ans){
            int l=it[0],r=it[1];
            if(l<=fs && r>=fe){
                if(fs-1>=l)
                temp.push_back({l,fs-1});
                if(fe+1<=r)
                temp.push_back({fe+1,r});
            }
            else if(l>fe || r<fs){
                temp.push_back({l,r});
            }
            else  if(fs<=l && fe>=r)continue;
            else if(l<fs && r>=fs){
                temp.push_back({l,fs-1});
            }
            else if(l<=fe){
                temp.push_back({fe+1,r});
            }
        }
        return temp;
    }
};