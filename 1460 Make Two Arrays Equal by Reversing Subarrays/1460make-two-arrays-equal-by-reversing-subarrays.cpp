class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> a;
        for(int i=0;i<target.size();i++)a[target[i]]++;
        for(auto i:arr){
             if(a.find(i)!=a.end()){
                if(a[i]==0) return 0;
                a[i]--;
            }
            else return 0;
        }
        return 1;
    }
};