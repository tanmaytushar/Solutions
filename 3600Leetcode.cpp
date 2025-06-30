/* 
Greedy include all the necessary edges then include all the optional edges sorted by weight
use k operations to improve the smalles edges that can be upgraded
*/
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> must,optional;
        for(auto &it : edges){
            if(it[3] == 1) must.push_back(it);
            else optional.push_back(it);
        }
        UnionFind dsu(n);
        multiset<int> all;
        bool cycles = false;
        for(auto &it : must){
            if(dsu.findSet(it[1]) != dsu.findSet(it[0])) dsu.unionSet(it[1],it[0]);
            else{
                cycles = true;
                break;
            }
            all.insert(it[2]);
        }
        if(cycles) return -1;
        bool flag = true;
        for(int i = 1;i<n;i++){
            if(dsu.findSet(i) != dsu.findSet(0)) flag = false;
        }
        if(flag) return *all.begin();
        multiset<int> newall;
        sort(optional.begin(),optional.end(),[](vector<int> &v1,vector<int> &v2){
            return v1[2] > v2[2]; 
        });
        for(auto &it : optional){
            if(dsu.findSet(it[1]) != dsu.findSet(it[0])) dsu.unionSet(it[1],it[0]);
            else continue;
            newall.insert(it[2]);   
        }
        flag = true;
        for(int i = 1;i<n;i++){
            if(dsu.findSet(i) != dsu.findSet(0)) flag = false;
        }
        if(!flag) return -1;
        multiset<int> afterupgrades;
        while(k-- && newall.size()){
            int mn = *newall.begin();
            newall.erase(newall.begin());
            afterupgrades.insert(mn * 2);
        }
        for(auto &it : newall) afterupgrades.insert(it);
        int left = all.size() == 0 ? INT_MAX : *all.begin();
        int right = afterupgrades.size() == 0 ? INT_MAX : *afterupgrades.begin();
        return min(left,right);
    }
};
