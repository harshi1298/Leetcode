class Node{
public:
   vector<Node* >child;
   int flag;
   Node(){
    child.resize(26);
    for(int i=0;i<26;i++)child[i]=NULL;
    flag=false;
   }
};
class Trie{
public:
  Node* root;
  vector<string>ans;
  Trie(){
    root=new Node();
  }
  void insert(string word){
    Node* temp=root;
    for(auto it : word){
        if(!temp->child[it-'a']){
            temp->child[it-'a']=new Node();
        }
        temp=temp->child[it-'a'];
    }
    temp->flag=true;
  }
  void search(string t1,string t2,int i){
      int n=t1.length();
      Node * temp=root;
      if(i>=n){
        t2.pop_back();
        ans.push_back(t2);
        return ;
      }
      for(int j=i;j<n;j++){
        char it=t1[j];
        if(!temp->child[it-'a'])return ;
        t2.push_back(t1[j]);
        temp=temp->child[it-'a'];
        if(temp->flag){
            string t=t2;
            t.push_back(' ');
            search(t1,t,j+1);
        }
      }
  }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie *trie=new Trie();
        for(auto it : wordDict){
            trie->insert(it);
        }
        trie->search(s,"",0);
        return trie->ans;
    }
};