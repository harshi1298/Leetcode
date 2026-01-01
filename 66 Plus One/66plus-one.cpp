class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int k=digits.size();
      k=k-1;
      for(int i=k;i>=0;i--){
          if(digits[i]<10){
            digits[i]+=1;
            if(digits[i]!=10)
            break;}
        if(digits[i]==10){
            digits[i]=0;
            if(i==0){
                digits.insert(digits.begin(),1);
            }
        }
         }
      return digits; 
    }
};