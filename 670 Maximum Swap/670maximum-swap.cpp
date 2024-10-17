class Solution {
public:
    int maximumSwap(int num) {
        vector<int>number;
      while(num){
        number.push_back((num%10));
        num/=10;
      }
      for(int i=0,j=number.size()-1;i<j;i++,j--){
        swap(number[i],number[j]);
      }
      int flag=1;
      for(int i=0;i<number.size()-1 && flag ;i++){
        flag=1;
        int k=-1,l=-1;
        for(int j=number.size()-1;j>i;j--){
           if(number[i]<number[j]){
            if(flag){
               k=i;
               l=j;
               swap(number[i],number[j]);
            }
            else{
                swap(number[k],number[l]);
               k=i;
               l=j;
               swap(number[i],number[j]);
            }
            flag=0;
           }
        }
      }
      int ans=0;
        for(auto i: number){
            ans=ans*10+i;
        }
      return ans;
    }
};