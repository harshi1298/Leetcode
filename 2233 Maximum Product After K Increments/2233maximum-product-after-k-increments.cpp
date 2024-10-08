class Solution {
    int modulo=1e9+7;
public:
    int maximumProduct(vector<int>& nums, int k) {
      priority_queue<int,vector<int>,greater<int>>pq;
      for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
      }  
      while(k){
        int tmp=pq.top()+1;
        pq.pop();
        pq.push(tmp);
        k--;
      }
      long long ans=1;
      while(!pq.empty()){
         ans=(ans*(pq.top()))%modulo;
         pq.pop();
      }
      return ans;
    }
};