#define tp tuple<int,int,bool,int>
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<tp>temp;
        int i=0;
        for(auto it : buildings){
            temp.push_back(make_tuple(it[0],it[2],0,i));
            temp.push_back(make_tuple(it[1],it[2],1,i));
            i++;
        }
        sort(temp.begin(), temp.end(), [](const tp &a, const tp &b) {
    if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b); // x ascending
    if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b); // start before end
    if (get<2>(a) == 0) return get<1>(a) > get<1>(b);         // higher start first
    return get<1>(a) < get<1>(b);                             // lower end first
});

        vector<vector<int>>ans;
        set<int>rem;
        int pre=0;
        priority_queue<pair<int,int>>pq;
        pq.push({0,-1});
        for(auto [x,y,b,id]: temp){
            if(b==0){
                pq.push({y,id});
            }
          else{
             rem.insert(id);
          }
          while(!pq.empty() && rem.find( pq.top().second)!=rem.end())pq.pop();
          if(pre!=pq.top().first){
            ans.push_back({x,pq.top().first});
            pre=pq.top().first;
          }
        }
        return ans;
    }
};