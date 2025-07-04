/*
It better to think about this from the end we figure first in which half it is then 
using that we can check if the ith operation was applied or not 
we can collect all the operations and then start from a and apply all the operations
*/
class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        long long current = 1;
        int n = ops.size(), i = 0;
        for (; i < n && current < k; i++) {
            current *= 2;
        }
        n = i - 1;
        vector<int> order;
        for (int j = n; j >= 0; j--) {
            long long mid = current / 2;
            if (k > mid) {
                order.push_back(ops[j]);
                k -= mid;
            }
            current = mid;
        }
        char ans = 'a';
        for (int i = order.size() - 1; i >= 0; i--) {
            if (order[i] == 1) {
                ans = ((ans - 'a' + 1) % 26) + 'a';
            }
        }
        return ans;
    }
};
