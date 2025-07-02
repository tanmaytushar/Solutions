/*
a difficult questions 
k <= 2000 so rather then counting all the possible string for alteast k count for atmost k - 1 and then subtract from total
once we have this we realise 2000 is small it allows us to do a freq * 2000 dp -> 
-> look at the recursive code first you realise a couple of things from there dp[i][j] only depends on dp[i-1] this allows you to optimise space 
-> also for the sum loop we can optimise it using prefix sum 
*/

class Solution {
public:
    const int mod = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> freq;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int total = 1;
        for (auto &f : freq)
            total = (1LL * total * f) % mod;

        if (freq.size() >= k) // -> if the size of freq is more then k then all the string are of len >= k
            return total;
        
        int m = freq.size();
        vector<int> prev(k, 0), curr(k, 0);
        prev[0] = 1;

        for (int i = 0; i < m; ++i) {
            vector<int> prefix(k, 0);
            prefix[0] = prev[0];
            for (int j = 1; j < k; ++j)
                prefix[j] = (prefix[j - 1] + prev[j]) % mod;

            for (int len = 0; len < k; ++len) {
                int l = len - freq[i]; // -> when we take all of the current f
                int r = len - 1; // -> when we take min possible i.e 1
                if (r < 0) {
                    curr[len] = 0;
                    continue;
                }
                int sum = prefix[r];
                if (l > 0)
                    sum = (sum - prefix[l - 1] + mod) % mod;
                curr[len] = sum;
            }
            swap(prev, curr);
        }

        int invalid = 0;
        for (int len = 1; len < k; ++len)
            invalid = (invalid + prev[len]) % mod;

        return (total - invalid + mod) % mod;
    }
};

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> freq;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int total = 1;
        for (auto &i : freq)
            total = (1LL * total * i) % mod;

        int m = freq.size();
        vector<vector<int>> dp(m, vector<int>(k, -1));

        function<int(int, int)> f = [&](int i, int j) -> int {
            // Base cases
            if (i < 0 && j == 0) return 1;
            if (i < 0 || j < 0) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = 0;
            for (int t = 1; t <= freq[i]; ++t) {
                ans = (ans + f(i - 1, j - t)) % mod;
            }
            return dp[i][j] = ans;
        };
        int invalid = 0;
        for (int len = 1; len < k;len++) {
            invalid = (invalid + f(m - 1, len)) % mod;
        }
        return (total - invalid + mod) % mod;
    }

private:
    static const int mod = 1000000007;
};
