class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int t=1;
        string tmp=to_string(n);
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<31;i++){
            string temp=to_string(t);
            t=t<<1;
            sort(temp.begin(),temp.end());
            if(tmp==temp)return true;
        }
        return false;
    }
};