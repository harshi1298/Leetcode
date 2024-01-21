class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr[1001]={0};
        int brr[1001]={0};
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
          arr[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
          brr[nums2[i]]++;
          for(int i=0;i<1001;i++){
              if(arr[i]>0&&brr[i]>0)
                ans.push_back(i);
          }
          return ans;
    }
};