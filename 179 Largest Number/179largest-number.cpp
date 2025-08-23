class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),[&](auto a,auto b){
            return a+b>b+a;
        });
        string res="";
        for(auto it:v)res+=it;
        reverse(res.begin(),res.end());
        while(res.length()>1 && res.back()=='0')res.pop_back();
        reverse(res.begin(),res.end());
        return res;
        
    }
};