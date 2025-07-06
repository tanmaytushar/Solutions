/*
A simple variation of 2 Sum 
*/
class FindSumPairs {
    int n,m;vector<int> a,b;
    map<int,int> f1,f2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(),m = nums2.size();
        a = nums1,b = nums2;
        for(auto &it : nums1) f1[it]++;
        for(auto &it : nums2) f2[it]++;
    }
    
    void add(int index, int val) {
        f2[b[index]]--;
        b[index] += val;
        f2[b[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0;i<n;i++){
            int required = tot - a[i];
            ans += f2[required];
        }
        return ans;
    }
};
