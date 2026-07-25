class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=i+1;
        if(intervals.size()==1){
            return intervals;
        }
        vector<int>prev=intervals[i];
        vector<int>curr=intervals[j];
        while(j<intervals.size()){
            curr=intervals[j];
            if(prev[1]>=curr[0]){
                prev={prev[0],max(prev[1],curr[1])};
                cout<<"yes1";
                i++;
            }
            else{
                ans.push_back(prev);
                i++;
                prev=intervals[i];
            }
            j++;
        }
        ans.push_back(prev);
        return ans;
    }
};