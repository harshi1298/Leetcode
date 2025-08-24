class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mw) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;){
            int j=i,len=0;
            while(j<n && len+words[j].size()+(j-i)<=mw){
                len+=words[j].size();
                j++;
            }
            int gap=j-i-1;
            string line;
            if(gap==0 || j==n){
                line=words[i];
                for(int k=i+1;k<j;k++){
                    line+=(" "+words[k]);
                }
                int rem=mw-line.size();
                while(rem>0){
                    line.push_back(' ');
                    rem--;
                }
            }
            else{
                int exsp=mw-len;
                int hs=exsp/gap;
                int ls=exsp%gap;
                line=words[i];
                for(int k=i+1;k<j;k++){
                    line+=string(hs,' ');
                    if(ls){
                       ls--;
                       line.push_back(' ');
                    }
                    line+=words[k];
                }
            }
            i=j;
            cout<<line.size()<<" ";
            ans.push_back(line);
        }
        return ans;
    }
};