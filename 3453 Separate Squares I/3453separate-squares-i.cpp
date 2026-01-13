class Solution {
private:
    bool solve(vector<vector<int>>& squares,double &mid,double &total){
        double ans=0;
        for(auto &it : squares){
            double x=it[0],y=it[1],l=it[2];
            if(y<mid){
                ans+=(min(mid,y+l)-y)*l;
            }
        }
        return ans>=total/2;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double start=0,end=0;
        double total=0;
        for(auto &it : squares){
            end=max(end,(double)it[1]+it[2]);
            total+=((double)it[2]*(double)it[2]);
        }
        while(abs(start-end)>1e-5){
            double mid=(start+end)/2;
            if(solve(squares,mid,total)){
                end=mid;
            }
            else start=mid;
        }
        return start;
    }
};