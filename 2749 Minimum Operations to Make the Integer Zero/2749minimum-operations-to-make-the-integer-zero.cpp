class Solution {
private:
    bool count(long long num,long long c){
        if(num<0)return false;
        // cout<<num<<" ";
        long long count1=0,count2=0;
        while(num){
            if(num&1)count2++;
            num/=2;
            count1++;
        }
        return c<=count1 && c>=count2;
    }
    long long bits(long long num){
        long long count=0;
        cout<<num<<endl;
        while(num){

            count+=(num&1);
            num>>=1;
        }
        return count;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        // for(long long i=0;i<61;i++){
        //     if(count(num1-(num2*i),i)){
        //         return i;
        //     }
        // }
        // return -1;
        if(num1==0) return 0;
        long long num=0;
        long long count=1;
        while(num<=num1){
            num+=num2;
            long long maxi=num1-num;
            if(maxi<0) continue;
            long long mini=bits(maxi);
            if(count>=mini && count<=maxi) return count;
            // if(count>maxi) break;
            count++;
        }
        return -1;
    }
};