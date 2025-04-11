class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
           string t=to_string(i);
           if(t.length()%2)continue;
           else if(t.length()==2){
            if(t[0]==t[1])ans++;
           }
           else{
              if(t[0]+t[1]==t[2]+t[3])ans++;
           }
        }
        return ans;
    }
};