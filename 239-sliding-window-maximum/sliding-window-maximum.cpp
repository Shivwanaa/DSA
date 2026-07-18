class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0;
        priority_queue<pair<int,int>>q;
        if(k==1){
            return nums;
        }
        for(int j=0;j<nums.size();j++){
            q.push({nums[j],j});
            if(j-i+1==k){
                while(q.size() && q.top().second<i){
                q.pop();
            }
                ans.push_back(q.top().first);
                i++;
            }
            
        }
        return ans;
    }
};