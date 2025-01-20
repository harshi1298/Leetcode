class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        vector<int>arr1(row,col);
        vector<int>arr2(col,row);
        unordered_map<int,pair<int,int>>mapp;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mapp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<row*col;i++){
            int x=mapp[arr[i]].first;
            int y=mapp[arr[i]].second;
            arr1[x]--;arr2[y]--;
            if(!arr1[x] || !arr2[y])return i;
        }
        return 0;
    }
};