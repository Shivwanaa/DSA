class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int l=0;
        int r=1;
        vector<int>prev=intervals[0];
        vector<int>curr=intervals[1];
        for(int r=1;r<intervals.size();r++){
            curr=intervals[r];
            if(prev[1]>=curr[0]){
                l++;
                prev[1]=max(prev[1],curr[1]);
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