class TreeAncestor {
public:
    vector<vector<int>>temp;
    int l;
    TreeAncestor(int n, vector<int>& parent) {
        l=log2(n)+1;
        temp.resize(l,vector<int>(n));
        for(int i=0;i<n;i++){
            temp[0][i]=parent[i];
        }
        for(int i=1;i<l;i++){
            for(int j=0;j<n;j++){
                int prev=temp[i-1][j];
                if(prev==-1){
                    temp[i][j]=-1;
                }
                else{
                    temp[i][j]=temp[i-1][prev];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=l-1;i>=0;i--){
            if (node == -1)
                return -1;
            if((k >> i) & 1){
                node=temp[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */