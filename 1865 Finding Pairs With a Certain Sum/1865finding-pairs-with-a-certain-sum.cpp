class FindSumPairs {
private:
    unordered_map<int,int>mapp1,mapp2;
    vector<int>nums1,nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it : nums1){
            mapp1[it]++;
        }
        for(auto it : nums2){
            mapp2[it]++;
        }
        this->nums1=nums1;
        this->nums2=nums2;
    }
    
    void add(int index, int val) {
        mapp2[nums2[index]]--;
        mapp2[nums2[index]+val]++;
        nums2[index]+=val;
    }
    
    int count(int tot) {
        int count=0;
        for(auto [a,b]: mapp1){
           count+=(b*mapp2[tot-a]);
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */