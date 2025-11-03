class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int n=heights.size();
        int sum=0;
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                sum+=heights[i]-heights[i-1];
                pq.push(heights[i]-heights[i-1]);
                if(sum>bricks && ladders<=0)return i-1;
                if(sum>bricks){
                    sum-=pq.top();
                    pq.pop();
                    ladders--;
                }
            }
        }
        return n-1;
    }
};