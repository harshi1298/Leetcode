class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int i=0,j=0;
        unordered_map<int,int>mapp;
        while(i<n && j<n){
            if(nums1[i]==nums2[j]){
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                mapp[nums2[j]]++;
                j++;
            }
            else{
                mapp[nums1[i]]++;
                i++;
            }
        }
        while(i<n){
            mapp[nums1[i]]++;
            i++;
        }
        while(j<n){
            mapp[nums2[j]]++;
            j++;
        }
        int ans=0;
        for(auto [it,val]: mapp){
            if(val%2)return -1;
            ans+=val/2;
        }
        return ans/2;
    }
};