class Node{
    public:
      vector<Node*>tree;
      bool flag;
      Node(){
        tree.resize(26,nullptr);
        flag=false;
      }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string &it){
        Node* temp=root;
        for(auto &c: it){
            if(!temp->tree[c-'a']){
                temp->tree[c-'a']=new Node();
            }
            temp=temp->tree[c-'a'];
        }
        temp->flag=true;
    }

    bool search(string &it){
        Node* temp=root;
        for(auto &c: it){
            if(temp->tree[c-'a']){
                temp=temp->tree[c-'a'];
                if(temp->flag)return true;
            }
            else return false;
        }
        return false;
    }
};
class StreamChecker {
private:
    Trie tree;
    string t="";
    int maxLen = 0;
public:
    StreamChecker(vector<string>& words) {
        for(auto it: words){
            reverse(it.begin(),it.end());
            maxLen = max(maxLen, (int)it.size()); 
            tree.insert(it);
        }
    }
    
    bool query(char letter) {
        t=letter+t;
        if (t.size() > maxLen) t.pop_back();
        return tree.search(t);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */