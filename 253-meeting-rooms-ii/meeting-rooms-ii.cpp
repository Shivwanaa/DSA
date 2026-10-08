class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>s,e;
        if(intervals.size()==1){
            return 1;
        }
        for(auto i:intervals){
            s.push_back(i[0]);
            e.push_back(i[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i=0,j=0,c=0,ans=0;
        while(i<intervals.size() && j<intervals.size()){
            if(s[i]<e[j]){
                i++;
                c++;
            }
            else{
                j++;
                c--;
            }
            ans=max(c,ans);
        }
        return ans;
    }
};