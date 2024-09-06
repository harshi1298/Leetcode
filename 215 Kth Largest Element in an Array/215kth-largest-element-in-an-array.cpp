class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<size;i++){
            if(i<=(size-k)){
                pq.push(nums[i]);
            }
            else if(pq.top()>nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};