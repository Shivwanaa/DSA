class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<points.size();i++){
            int d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            q.push({d,i});
            if(q.size()>k){
                q.pop();
            }
        }
        while(q.size()){
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};