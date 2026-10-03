class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>ans;
        for(auto i:m){
            q.push({i.second,i.first});
            if(q.size()>k){
                q.pop();
            }
        }
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;

    }
};