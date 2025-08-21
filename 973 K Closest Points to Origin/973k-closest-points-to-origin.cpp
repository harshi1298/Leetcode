#define pr pair<int,int>
int solve(int a,int b){
    return (int)(pow(a,2)+pow(b,2));
    }
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pr>pq;
        int n=p.size();
        for(int i=0;i<n;i++){
            pq.push(make_pair(solve(p[i][0],p[i][1]),i));
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        for(int i=0;i<k && !pq.empty();i++){
            auto [_,idx]=pq.top();
            pq.pop();
            ans.push_back(p[idx]);
        }
        return ans;
    }
};