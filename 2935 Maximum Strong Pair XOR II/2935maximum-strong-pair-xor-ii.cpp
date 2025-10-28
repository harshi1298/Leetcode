class Node{
  public:
    Node *child[2];
    int count;
    Node(){
        child[0]=child[1]=NULL;
        count=0;
    }
};

class Trie{
    Node* root;
  public:
    Trie(){
        root=new Node();
    }

    void insert(int a){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int t = (a >> i) & 1;
            if(!temp->child[t]){
                temp->child[t]=new Node();
            }
            temp=temp->child[t];
            temp->count++;
        }
    }

    void erase(int a){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int t = (a >> i) & 1;
            temp=temp->child[t];
            temp->count--;
        }
    }

    int findmax(int a){
        int ans=0;
        Node* temp=root;
        for(int i=31;i>=0;i--){
           int t = 1 - ((a >> i) & 1);
            if(temp->child[t] && temp->child[t]->count>0){
                ans|=(1<<i);
                temp=temp->child[t];
            }
            else{
                temp=temp->child[1-t];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int ans=0;
        Trie trie;
        for(int r=0;r<n;r++){
           trie.insert(nums[r]);
           while(nums[r]>2*nums[l]){
            trie.erase(nums[l]);
            l++;
           }
           ans=max(ans,trie.findmax(nums[r]));
        }
        return ans;
    }
};