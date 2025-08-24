class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int count=0;
        vector<int>color(n);
        int k=queries.size();
        vector<int>ans;
        for(auto it : queries){
            int idx=it[0],c=it[1];
            if(idx-1>=0 && color[idx]!=c&& color[idx-1]==c){
               count++;
            }
            if(idx+1<n&& color[idx]!=c&& color[idx+1]==c){
               count++;
            }
            if(idx-1>=0 && color[idx]!=c&& color[idx-1]==color[idx] && color[idx-1] && color[idx]){
               count--;
            }
            if(idx+1<n && color[idx]!=c&& color[idx+1]==color[idx] &&  color[idx+1] && color[idx]){
               count--;
            }
            ans.push_back(count);
            color[idx]=c;
        }
        return ans;
    }
};