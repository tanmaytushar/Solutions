/*
Like LIS -> dp[i][k] -> max len of subsequence that ends that index i and the the (sub[t] + sub[t+1])%k is same for all t in the subsequence;
                */
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(k,0));
        int ans = 2;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                int rem = (nums[i] + nums[j]) % k;
                dp[i][rem] = (dp[j][rem] > 0 ? dp[j][rem] + 1 : 2);
                ans = max(dp[i][rem],ans);
            }
        }
        return ans;
    }
};
