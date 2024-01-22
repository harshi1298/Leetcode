class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int k=nums.size();
        int a=0,b=0;
        int arr[10000]={0};
        for(int i=0;i<k;i++){
            arr[nums[i]-1]++;
        }
        for(int i=0;i<10000;i++){
            if(arr[i]==0)
             a=(i+1);
            else if(arr[i]>1)
             b=(i+1);
            if(a>0&&b>0)
             break;
        }
        return {b,a} ; 
    }
};