class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<vector<long long>>w(m+1,vector<long long>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                w[i][j]=max(w[i-1][j]+skill[j-1]*mana[i-1],w[i][j-1]+skill[j-1]*mana[i-1]);
            }
            for(int l=n-1;l>0;l--){
                w[i][l]=w[i][l+1]-skill[l]*mana[i-1];
            }
        }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<w[i][j]<< " ";
        //     }
        //     cout<<endl;
        // }
        return w[m][n];
    }
};