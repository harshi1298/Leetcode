class Node{
public:
    vector<Node *>child;
    bool leaf;
    Node():child(26,nullptr),leaf(false){}
};

class Trie{
private:
      Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string k){
        Node* curr=root;
        for(auto c: k){
            int idx=c-'0';
            if(curr->child[idx]==nullptr){
               Node *newnode=new Node();
               curr->child[idx]=newnode;
            }
            curr=curr->child[idx];
        }
        curr->leaf=true;
    }

    int search(string k){
        Node* curr=root;
        int l=0;
        for(auto c: k){
            int idx=c-'0';
            if(curr->child[idx]==nullptr){
               return l;
            }
            curr=curr->child[idx];
            l++;
        }
        return l;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* tree=new Trie();
        for(auto it : arr2){
            tree->insert(to_string(it));
        }
        int ans=0;
        for(auto it: arr1){
            ans=max(ans,tree->search(to_string(it)));
        }
        return ans;
    }
};