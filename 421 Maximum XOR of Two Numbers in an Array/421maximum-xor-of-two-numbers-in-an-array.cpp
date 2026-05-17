class Node{
public:
    vector<Node *>child;
    Node(){
        child.resize(2);
        child[0]=child[1]=NULL;
    }
};
class Trie{
public:
   Node* root;
   Trie(){
     root=new Node;
   }
   void insert(int a){
    Node* temp=root;
    for(int i=31;i>=0;i--){
        int bit= a>>i &1;
        if(!temp->child[bit])temp->child[bit]=new Node();
        temp=temp->child[bit];
    }
   }
   int findmax(int a){
    int ans=0;
    Node* temp=root;
    for(int i=31;i>=0;i--){
        int rbit=!(a>>i &1);
        if(temp->child[rbit]){
            ans |= 1<<i;
            temp=temp->child[rbit];
        }
        else {
            temp=temp->child[1-rbit];
        }
    }
    return ans;
   }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int  ans=0;
        Trie trie;
        trie.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            ans=max(ans,trie.findmax(nums[i]));
            trie.insert(nums[i]);
        }
        return ans;
    }
};