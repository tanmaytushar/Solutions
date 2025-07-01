class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1,n = word.size();
        for(int i = 0;i<n;i++){
            char current = word[i];
            int count  = 0;
            while(i < n && word[i] == current){
                count++,i++;
            }
            ans += (count - 1);
            i--;
        }
        return ans;
    }
};
