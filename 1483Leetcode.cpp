/*
Store the 2 ^ j ancestor for every node
now Kth parent can be found out since every number can be broken down into powers of 2
*/
class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 20;
        up.assign(n,vector<int>(LOG,-1));
        for(int i = 0;i<n;i++) up[i][0] = parent[i];
        for(int j=1;j<LOG;j++){
            for(int i = 0;i<n;i++){
                if(up[i][j-1] != -1) up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for(int i = 0;i<LOG;i++){
            if(k&(1<<i)){
                node = up[node][i];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};
