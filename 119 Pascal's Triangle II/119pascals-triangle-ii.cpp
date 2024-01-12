class Solution {
public:
int facts(int c,int d){
    long long e=1;
    while(c>d){
       e=e*c;
       c--;
    }
    return e;
}
    int fact(int a,int b){
        long long l=1;
        int m=a-b;
        int y=1;
        while(a>b){
            l=l*a;
            if(m>y){
                if(l%m==0){
                    l=l/m;
                    m--;
                }
            }
            if(m>y){
                if(l%(y+1)==0){
                    l=l/(y+1);
                    y++;
                }
            }
            a--;
        }
        return l/facts(m,y);
    }
    vector<int> getRow(int n) {
        vector<int>pascal;
        for(int i=0;i<=n;i++){
            pascal.push_back(fact(n,i));
        }
        return pascal;
    }
};