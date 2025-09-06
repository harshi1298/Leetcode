class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>arr;
        int n=profits.size();
        for(int i=0;i<n;i++){
            arr.push_back({capital[i],i});
        }
        sort(arr.begin(),arr.end());
        priority_queue<int>pq;
        int ans=0,i=0;
        while(k>0){
          while(i<n && arr[i].first<=w){
            pq.push(profits[arr[i].second]);
            i++;
          }
          if(pq.empty())break;
          w+=pq.top();
          pq.pop();
          k--;
        }
        return w;
    }
};