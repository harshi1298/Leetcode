class Solution {
private:
    bool check(int temp,vector<int>arr){
        vector<int>t(32,0);
        for(int i=0;i<32;i++){
            t[i]=(temp%2);
            temp/=2; 
        }
        for(int i=0;i<32;i++){
            if(t[i]>0 && arr[i]<=0)return false;
        }
        return true;
    }
    void subtract(vector<int>&arr,int temp){
        vector<int>t(32,0);
        for(int i=0;i<32;i++){
            t[i]=(temp%2);
            temp/=2; 
        }
        for(int i=0;i<32;i++){
            arr[i]-=t[i];
        }
    }
    void update(vector<int>&arr,int temp){
        vector<int>t(32,0);
        for(int i=0;i<32;i++){
            t[i]=(temp%2);
            temp/=2; 
        }
        for(int i=0;i<32;i++){
            arr[i]+=t[i];
        }
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>temp(n);
        temp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=temp[i+1] | nums[i];
        }
        vector<int>arr(32,0);
        int l=0;
        for(int r=0;r<n;r++){
            update(arr,nums[r]);
            while(l<=r && check(temp[l],arr)){
                subtract(arr,nums[l]);
                ans[l]=(r-l+1);
                l++;
            }
        }
        return ans;
    }
};