class Solution {
public:
static bool  comp(vector<int>a , vector<int>b){
            if(a[1]<b[1] ||(a[1]==b[1] && a[2]<b[2])){
                return true;
            }
            return false;
        };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //at a single point of time only cap people shld be there
        sort(trips.begin(),trips.end(),comp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int curr=0;
        for(int i=0;i<trips.size();i++){
            while(!q.empty() && q.top().first<=trips[i][1]){
                curr=curr-q.top().second;
                q.pop();
            }
            if(trips[i][0]>capacity){
                return false;
            }
            q.push({trips[i][2],trips[i][0]});
            curr=curr+trips[i][0];
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};