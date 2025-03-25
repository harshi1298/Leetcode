class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>h,b;
        for(auto it :rectangles){
            h.push_back({it[1],it[3]});
            b.push_back({it[0],it[2]});
        }
        sort(h.begin(),h.end());
        sort(b.begin(),b.end());
        int count=0;
        for(int i=1;i<h.size();i++){
            if(h[i-1][1]<=h[i][0])count++;
            h[i][1]=max(h[i][1],h[i-1][1]);
            
        if(count>=2)return true;
        }
        count=0;
        for(int i=1;i<b.size();i++){
            if(b[i-1][1]<=b[i][0])count++;
            b[i][1]=max(b[i][1],b[i-1][1]);
            if(count>=2)return true;
        }
        
        return false;
    }
};