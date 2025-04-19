class Solution {
private:
    vector<int>tree;
    void update(int i){
        while(i<tree.size()){
            tree[i]+=1;
            i+=(i&-i);
        }
    }
    long long query(int i){
        long long ans=0;
        while(i>0){
            ans+=tree[i];
            i-=(i&-i);
        }
        return ans;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=nums1[i]-nums2[i];
        }
        int maxi=*max_element(arr.begin(),arr.end());
        int mini=*min_element(arr.begin(),arr.end());
        int k=diff>0?diff:-diff;
        tree.resize(maxi-mini+2*k+2);
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            long long t=query(arr[i]+diff-mini+1);
            update(arr[i]-mini+1);
            ans+=(t);
        }
        return ans;
    }
};