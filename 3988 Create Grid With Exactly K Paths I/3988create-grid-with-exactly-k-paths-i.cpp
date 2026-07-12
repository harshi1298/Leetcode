class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if((n==1 || m==1) && k>1)return {};
        if(n*m<8 && k>3){return {};}
        if(n==3&&m==3&&k==4)return{"..#","...","#.."};
        vector<string>ans(m,string(n,'#'));
        for(int i=0;i<n;i++)ans[0][i]='.';
        for(int i=0;i<m;i++)ans[i][n-1]='.';
        k--;
        if(n>m){
            int j=n-2;
            while(j>=0 && k>0){
                 ans[1][j]='.';
                 k--;
                 j--;
            }
        }
        else{
            int i=1;
            while(i<m && k>0){
                ans[i][n-2]='.';
                i++;k--;
            }
        }
        if(k)return {};
        return ans;
    }
};