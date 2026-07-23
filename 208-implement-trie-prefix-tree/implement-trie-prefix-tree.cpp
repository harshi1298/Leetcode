class Node{
public:
    vector<Node*>child;
    bool flag;
    Node(){
       child.resize(26);
       for(int i=0;i<26;i++)child[i]=nullptr;
       flag=false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(auto it : word){
            if(!temp->child[it-'a']){
               temp->child[it-'a']=new Node();
            }
            temp=temp->child[it-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(auto it : word){
            if(!temp->child[it-'a'])return false;
            temp=temp->child[it-'a'];
        }
        return temp->flag;
    }
    
    bool startsWith(string word) {
        Node* temp=root;
        for(auto it : word){
            if(!temp->child[it-'a'])return false;
            temp=temp->child[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */