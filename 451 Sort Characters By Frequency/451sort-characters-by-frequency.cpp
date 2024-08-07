class Solution {
public:
    string frequencySort(string s) {
        int arr[62]={0};
        for(int i=0;i<s.length();i++){
            if((s[i]-'A'>=0 )&& s[i]-'A'<=26)arr[s[i]-'A']++;
            else if((s[i]-'a'>=0 )&& s[i]-'a'<=26) arr[s[i]-'a'+26]++;
            else arr[s[i]-'0'+52]++;
        }
        cout<<arr[52];
        map<int,vector<char>> m;
        for(int i=0;i<62;i++){
           if(i<=25){
             if(arr[i]!=0)
             m[arr[i]].push_back((char)(i+'A'));
            }
            else if(i<=51){
               if(arr[i]!=0)
                 m[arr[i]].push_back((char)(i+'a'-26)); 
            }
            else{
                 if(arr[i]!=0)
                 m[arr[i]].push_back((char)(i+'0'-52));
            }
        }
        string ans="";
        for(auto it : m){
            int k=it.first;
            while(!it.second.empty()){
                int l=k;
                char c=it.second.back();
                it.second.pop_back();
                while(l--) ans.insert(0, 1, c);;
            }
        }
        return ans;
    }
};