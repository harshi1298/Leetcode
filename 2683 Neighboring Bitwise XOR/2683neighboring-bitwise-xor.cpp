class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count=0;
        for(auto it : derived){
            count+=it;
        }
        return count%2==0;
    }
};