/*
Take No Take if we do attend an events we can only attend events start after the current one ends 
We can binary search for that index 
TC : (n*k*logN)
SC : (n*k)
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int K) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, -1));

        sort(events.begin(), events.end(), [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0];
        });

        auto bs = [&](int target, int left) -> int {
            int right = n - 1, ans = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (events[mid][0] >= target) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return ans;
        };

        auto f = [&](int index, int left, auto&& rec) -> int {
            if (index >= n || left <= 0) return 0;
            if (dp[index][left] != -1) return dp[index][left];
            int start = events[index][0], end = events[index][1], value = events[index][2];
            int notTake = rec(index + 1, left, rec);
            int take = value + rec(bs(end+1,index+1), left - 1, rec);
            return dp[index][left] = max(take, notTake);
        };

        return f(0, K, f);
    }
};
