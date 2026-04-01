class Node{
public:
    Node* child[26]; 
    int count;
    Node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        count=0;
    }
};
class Trie{
public:
    Node * root=NULL;
    Trie(){
        root=new Node();
    }
    void insert(string a){
        Node* temp=root;
        for(auto it : a){
            if(!(temp->child[it-'a'])){
                temp->child[it-'a']=new Node();
            }
            temp=temp->child[it-'a'];
            temp->count++;
        }
    }
    int search(string a){
        int ans=0;
        Node* temp=root;
        for(auto it : a){
            if(!(temp->child[it-'a']))return ans;
            temp=temp->child[it-'a'];
            ans+=temp->count;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto it : words){
            trie.insert(it);
        }
        vector<int>ans;
        for(auto it : words){
            ans.push_back(trie.search(it));
        }
        return ans;
    }
};