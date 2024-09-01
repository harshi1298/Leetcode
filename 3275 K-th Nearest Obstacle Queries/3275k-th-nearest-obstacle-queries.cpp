class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int>ans;
        priority_queue<int> prior;
        for(int i=0;i<queries.size();i++){
            int a= abs(queries[i][0])+abs(queries[i][1]);
            prior.push(a);
            while(prior.size()>k){
                prior.pop();
            }
            if(prior.size()<k){
                ans.push_back(-1);
            }
            else{
                ans.push_back(prior.top());
            }
        }
        return ans;
    }
};