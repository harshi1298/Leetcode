class Solution {
public: 
int facts(int c, int e){
    long long x=1;
    while(c>e){
      x=x*c;
      c--;}
      return x;
}
int fact(int a,int b){
    int m=a-b;
    int y=1;
         long long l=1;
             while(a>b){
               l=l*a;
               if(m>y){
               if(l%m==0){
                   l=l/m;
                    m--;
               }}
               if(m>y){
               if(l%(y+1)==0){
                   l=l/(y+1);
                   y++;
               }}
               
               a--;}
            return l/facts(m,y);

        }
        int comb(int c,int d){
            return fact(c,d);

        }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>pascal(n); 
        int k;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
            if(j>i-j)
              k=j;
            else
              k=i-j;
                 pascal[i].push_back(comb(i,k));
            }
        }
      return pascal;  
    }
};