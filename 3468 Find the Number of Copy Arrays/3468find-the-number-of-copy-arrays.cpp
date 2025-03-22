class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
        int n=o.size(),m=b.size();
        vector<int>diff(n);
        for(int i=1;i<n;i++){
            diff[i]=o[i]-o[i-1];
        }
        int ans=INT_MAX;
        for(int i=1;i<m;i++){
            int temp1=b[i][0]-diff[i];
            int temp2=b[i][1]-diff[i];
            temp2=temp2>b[i-1][1]?b[i-1][1]:temp2;
            temp1=temp1<b[i-1][0]?b[i-1][0]:temp1;
            b[i][0]=temp1+diff[i];
            b[i][1]=temp2+diff[i];
            ans=min(ans,temp2-temp1+1);
        }
        return ans>0?ans:0;
    }
};