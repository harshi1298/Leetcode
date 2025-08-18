class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
      int total=x+y;
      vector<int>vis(total+1,0);
      vector<int>dx({x,-x,y,-y});
      queue<int>que;
      que.push(0);
      vis[0]=1;
      while(!que.empty()){
        int k=que.front();
        que.pop();
        if(k==target)return true;
        for(auto it : dx){
            int nx=k+it;
            if(nx>=0 && nx<=total && !vis[nx]){
                vis[nx]=1;
                que.push(nx);
            }
        }
      }
      return false;
    }
};