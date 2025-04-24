class MajorityChecker {
private:
   unordered_map<int,vector<int>>mapp;
public:
    int n;
    vector<int>temp;
    MajorityChecker(vector<int>& arr) {
        n=arr.size();
        for(int i=0;i<arr.size();i++){
            mapp[arr[i]].push_back(i);
        }
        temp=arr;
    }
    int query(int left, int right, int threshold) {
        for(int i=0;i<=20;i++){
             int randIndex = left + rand() % (right - left + 1);
            int value = temp[randIndex];
            int k=upper_bound(begin( mapp[value]),end( mapp[value]),right)-lower_bound(begin( mapp[value]),end( mapp[value]),left);
            if(k>=threshold)return value;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */