class Solution {
private:
    string numtobin(int num){
        string ans="";
        while(num){
            ans.push_back(num%2+'0');
            num/=2;
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
    bool ispal(string k){
        for(int i=0,j=k.length()-1;i<j;i++,j--){
            if(k[i]!=k[j])return false;
        }
        return true;
    }
    int solve(int num){
        int mini=num,maxi=num;
        while(mini>=num/2){
            if(ispal(numtobin(mini)))break;
            mini--;
        }
        while(maxi<=num*2){
             if(ispal(numtobin(maxi)))break;
             maxi++;
        }
        return min(abs(mini-num),abs(maxi-num));
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans.push_back(solve(nums[i]));
        }
        return ans;
    }
};