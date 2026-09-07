class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        if(intervals.size()<=1){
            return intervals;
        }
        vector<int>prev=intervals[0];
        vector<int>curr=intervals[1];
        int l=0;
        for(int r=1;r<intervals.size();r++){
            curr=intervals[r];
            if(prev[1]>=curr[0]){
                prev[1]=max(prev[1],curr[1]);
                l++;
            }
            else{
                ans.push_back(prev);
                l++;
                prev=intervals[l];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};