class Solution {
private:
   pair<int,string> binary(int n){
    string str="";
    int count=0;
    while(n){
        if(!(n&1))count++;
       str=(char)((n&1)+'0')+str;
       n=n/2;
    }
    
    return {count,str};
   }
public:
    int maxGoodNumber(vector<int>& nums){
        vector<pair<int,string>>str;
        for(int i=0;i<nums.size();i++){
            str.push_back(binary(nums[i]));
        }
        sort(str.begin(), str.end(), [](const auto& a, const auto& b) {
            return a.second+b.second>b.second+a.second;
        });
        string temp="";
         for (int i = 0; i < min(3, (int)str.size()); i++) {
            temp += str[i].second;
        }
        for(int i=0;i<temp.length();i++)cout<<temp[i];
        int ans=0;
        for(int i=0;i<temp.length();i++){
            ans=ans+pow(2,i)*((int)(temp[temp.length()-i-1]-'0'));
        }
        return ans;
    }
};