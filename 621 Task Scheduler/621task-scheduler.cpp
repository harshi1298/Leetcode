class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     unordered_map<char,int>mapp;
     for(auto i:tasks){
        mapp[i]++;
     }
     priority_queue<int>pq;
      for(auto it: mapp){
        pq.push(it.second);
      } 
      int ans=0;
      while(!pq.empty()){
        int count=0;
        vector<int>temp;
        while(count!=n+1 && !pq.empty()){
            count++;
            temp.push_back(pq.top()-1);
            pq.pop();
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]>0)
            pq.push(temp[i]);}
        ans=ans+(pq.empty()?temp.size():n+1);
      } 
      return ans;
    }
};