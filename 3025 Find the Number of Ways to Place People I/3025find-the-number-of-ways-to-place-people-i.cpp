class Solution {
public:

    bool is_in(vector<vector<int>>&v,int i1,int j1,int x1,int y1,int x2,int y2){
        int n = v.size();
        for(int i=0;i<n;i++){
            int x = v[i][0];
            int y = v[i][1];
            if(i!=i1 and i!=j1 and x >= x1 and y<=y1 and x <= x2 and y>=y2) {
                // cout<<"YES";
                return true;
            }
        }
        return false;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
           for(int j=i+1;j<n;j++){
               int x2 = points[j][0];
               int y2 = points[j][1];
            //    cout<<is_in(points,i,j,x1,y1,x2,y2)<<" ";
               if((!is_in(points,i,j,x1,y1,x2,y2) and x1 <= x2 and y1 >= y2) || (!is_in(points,i,j,x2,y2,x1,y1) and x1 >= x2 and y1 <= y2)) count++;
           }
        }
    return count;
    }
};