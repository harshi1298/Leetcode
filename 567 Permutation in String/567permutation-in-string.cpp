class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mapp;
        for(int i=0;i<s1.length();i++){
            mapp[s1[i]]++;
        }
        int left=0,right=0,rlength=s1.length();
        while(right<s2.length()){
          if(mapp[s2[right]]>0){
            rlength--;
          }
          mapp[s2[right]]--;
          right++;
          if(rlength==0)return true;
          if(right-left==s1.length()){
            if(mapp[s2[left]]>=0)rlength++;
             mapp[s2[left]]++;
             left++;
        }
        }
        return false;
    }
};








 