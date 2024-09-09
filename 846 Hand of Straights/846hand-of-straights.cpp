class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gSize) {
        unordered_map<int,int>mapp;
        for(auto num :hand){
            mapp[num]=mapp[num]+1;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:mapp){
          pq.push({i.first,i.second});
        }
        while(!pq.empty()){
          int count=1;
          vector<pair<int,int>>temp;
          int l=pq.top().first;
          pair<int,int>a=pq.top();
           a.second=a.second-1;
           temp.push_back(a);
          pq.pop();
          while(count!=gSize){
             if(pq.empty() || pq.top().first!=l+count )return false;
             a=pq.top();
             a.second=a.second-1;
             temp.push_back(a);
             pq.pop();
             count++;
          }
          for(int i=0;i<temp.size();i++){
            if(temp[i].second>0)pq.push(temp[i]);
          }
        }
        return true;
    }
};