class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        long long ans=0;
        int n=bl.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=bl[i][0],y1=bl[i][1],x3=tr[i][0],y3=tr[i][1];
                int x2=bl[j][0],y2=bl[j][1],x4=tr[j][0],y4=tr[j][1];
                int maxx1=max(x1,x2),maxy1=max(y1,y2);
                int minx1=min(x3,x4),miny1=min(y3,y4);
                int l=minx1-maxx1,b=miny1-maxy1;
                long long temp=min(l,b);
                if(temp<0)continue;
                temp*=temp;
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};