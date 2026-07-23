class Node{
public:
    vector<Node*>child;
    int val;
    Node(){
        child.resize(26);
        for(int i=0;i<26;i++)child[i]=NULL;
        val=0;
    }
};
class Trie{
public:
   Node* root;
   Trie(){
    root=new Node();
   }
   void insert(string str,int val){
    Node * temp=root;
    for(auto it : str){
        if(!(temp->child[it-'a']))temp->child[it-'a']=new Node();
        temp=temp->child[it-'a'];
        temp->val+=val;
    }
   }
   int search(string str){
    Node * temp=root;
    for(auto it : str){
        if(!(temp->child[it-'a']))return 0;
        temp=temp->child[it-'a'];
    }
    return temp->val;
   }
   void removekey(string str,int val){
    Node* temp=root;
    for(auto it : str){
      temp=temp->child[it-'a'];
      temp->val-=val;
    }
   }
};
class MapSum {
public:
   Trie trie;
   unordered_map<string,int>mapp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(mapp.find(key)!=mapp.end()){
            trie.removekey(key,mapp[key]);
        }
        trie.insert(key,val);
        mapp[key]=val;
    }
    
    int sum(string prefix) {
        return trie.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */