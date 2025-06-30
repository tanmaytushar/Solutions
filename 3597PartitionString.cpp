// Implmentation 
class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();
        set<string> s1;vector<string> ans;
        string current = "";
        for(int i = 0;i<n;i++){
            current += s[i];
            if(s1.find(current) == s1.end()){
                s1.insert(current);
                ans.push_back(current);
                current = "";
            }
        }
        return ans;
    }
};
