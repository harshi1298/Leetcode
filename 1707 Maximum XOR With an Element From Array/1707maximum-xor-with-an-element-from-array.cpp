class Node{
public:
    vector<Node*> child;

    Node(){
        child.resize(2, NULL);
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(int a){
        Node *temp = root;

        for(int i = 31; i >= 0; i--){
            int bit = (a >> i) & 1;

            if(!temp->child[bit]){
                temp->child[bit] = new Node();
            }

            temp = temp->child[bit];
        }
    }

    int findans(int x){
        Node *temp = root;

        int ans = 0;

        for(int i = 31; i >= 0; i--){

            int bit = (x >> i) & 1;
            int want = 1 - bit;

            if(temp->child[want]){
                ans |= (1 << i);
                temp = temp->child[want];
            }
            else{
                temp = temp->child[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> q;

        for(int i = 0; i < queries.size(); i++){
            int x = queries[i][0];
            int m = queries[i][1];

            q.push_back({m, x, i});
        }

        sort(q.begin(), q.end());

        Trie trie;

        int j = 0;
        int n = nums.size();

        vector<int> ans(queries.size());

        for(auto &it : q){

            int m = it[0];
            int x = it[1];
            int idx = it[2];

            while(j < n && nums[j] <= m){
                trie.insert(nums[j]);
                j++;
            }

            if(j == 0){
                ans[idx] = -1;
            }
            else{
                ans[idx] = trie.findans(x);
            }
        }

        return ans;
    }
};