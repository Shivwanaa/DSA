class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>>q;
        for(auto i:arr){
            q.push({abs(i-x),i});
            if(q.size()>k){
                q.pop();
            }
        }
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};