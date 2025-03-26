class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row=grid.size(),col=grid[0].size(),tot=row*col;
        vector<int> nums;
        for(int i=0;i<tot;i++){
            nums.push_back(grid[i/col][i%col]);
        }
        sort(nums.begin(),nums.end());
        int c=tot/2;
        int ans=0;
        for(int i=0;i<tot;i++){
            ans+=abs(grid[i/col][i%col]-nums[c])/x;
            if(abs(grid[i/col][i%col]-nums[c])%x) return -1;
        }
        return ans;
    }
};