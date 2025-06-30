/*
  min max -> looks binary search but is not because of xor behavior
  constraints giveaway a big hit n*k*n can be done 
  n * k dp
*/
class Solution {
public:
    int minXor(vector<int>& nums, int K) {
        int n = nums.size();
        vector<int> rangeXor(n+1,0);
        for(int i = 0;i<n;i++){
            rangeXor[i+1] = rangeXor[i] ^ nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (K+1,-1));
        auto rec = [&](int i,int k,auto &&rec) -> int {
          if(k == 0 && i == n) return 0;
          if(k == 0 || i == n) return INT_MAX;
          if(dp[i][k] != -1) return dp[i][k];
          int ans = INT_MAX;
          for(int j = i;j<n;j++){
              int currentXor = rangeXor[j+1] ^ rangeXor[i];
              int next = rec(j+1,k-1,rec);
              ans = min(ans,max(currentXor,next));
          }
          return dp[i][k] = ans;
        };
        return rec(0,K,rec);
    }
};
