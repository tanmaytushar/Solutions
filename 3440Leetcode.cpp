/*
Move the current event either to the left or right if there is space big enough to accomodate it 
ow slide it either to the left or right of the current gap
*/
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        int n = startTime.size();
        for(int i = 0;i<n;i++){
            int currentgap = (i-1 >= 0 ? startTime[i] - endTime[i-1] : startTime[i] - 0);
            gaps.push_back(currentgap);
        }
        gaps.push_back(eventTime - endTime[n-1]);
        vector<int> prefixmax,suffixmax;
        int mx = 0;
        for(int i = 0;i<gaps.size();i++){
            mx = max(mx,gaps[i]);
            prefixmax.push_back(mx);
        }
        mx = 0;
        for(int j = gaps.size()-1;j>=0;j--){
            mx = max(mx,gaps[j]);
            suffixmax.push_back(mx);
        }
        reverse(suffixmax.begin(),suffixmax.end());
        int ans = 0;
        for(int i = 0;i<n;i++){
            int currentsize = endTime[i] - startTime[i];
            int mxleft = (i-1 >= 0 ? prefixmax[i-1] : 0),mxright = (i+2 < suffixmax.size() ? suffixmax[i+2] : 0);
            if(mxleft >= currentsize || mxright >= currentsize){
                int temp = abs((i-1 >= 0 ? endTime[i-1] : 0) - (i+1 < n ? startTime[i+1] : eventTime));
                ans = max(temp,ans);
            }else{
                int temp = abs((i-1 >= 0 ? endTime[i-1] : 0) - (i+1 < n ? startTime[i+1] : eventTime)) - currentsize;
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
