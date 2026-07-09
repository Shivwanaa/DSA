class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=i+1;
        if(intervals.size()==0||intervals.size()==1){
            return intervals;
        }
        vector<int>prev=intervals[i];
        vector<int>curr=intervals[j];
        
        while(j<intervals.size()){
            curr=intervals[j];
            if(prev[1]>=curr[0]){
                prev={prev[0],max(prev[1],curr[1])};
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