class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<int>s;
        vector<int>e;
        
        for(auto i:intervals){
            s.push_back(i[0]);
            e.push_back(i[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i=0,j=0,c=0;
        while(i<s.size() && j<e.size()){
            if(s[i]<e[j]){
                i++;
                c++;
            }
            else{
                c--;
                j++;
            }
            if(c>1){
                return false;
            }
        }
        // if(c>1){
        //     return false;
        // }
        return true;
    }
};