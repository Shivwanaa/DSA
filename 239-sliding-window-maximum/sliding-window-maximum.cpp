class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto comp=[](pair<int,int>a,pair<int,int>b){
            return a.second<b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>q(comp);
        unordered_set<int>fin;
        vector<int>ans;
        int i=0;
        for(int j=0;j<nums.size();j++){
            q.push({j,nums[j]});
            while(!q.empty() && fin.count(q.top().first)){
                q.pop();
            }
            if(j-i+1==k){
                ans.push_back(q.top().second);
                fin.insert(i);
                i++;
            }
        }
        return ans;
    }
};