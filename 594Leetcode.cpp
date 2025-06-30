/*
idea is simple we can either include nums[i] - 1 or nums[i] + 1 to subsequece
try both considering each index as the last element 
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        // n^2 i do a solution
        int n = nums.size();
        map<int,int> m1;
        int ans  = 0;
        for(int i = 0;i<n;i++){
            int toleftextra = m1[nums[i]+1];
            int toleftcurrent = m1[nums[i]];
            int toleftbelow = m1[nums[i]-1];
            if(toleftbelow){
                ans = max(ans,toleftbelow + toleftcurrent + 1);
            }
            if(toleftextra){
                ans = max(ans,toleftextra + toleftcurrent + 1);
            }
            m1[nums[i]]++;
        }
        return ans;
    }
};
