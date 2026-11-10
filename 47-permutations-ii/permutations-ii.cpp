class Solution {
public:
vector<vector<int>>ans;
    void check(vector<int>& nums,vector<int>tp,vector<int>vis){
        if(tp.size()==nums.size()){
            ans.push_back(tp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i] || (i>0 && (nums[i]==nums[i-1] && !vis[i-1]))){
                continue;
            }
                vis[i]=1;
                tp.push_back(nums[i]);
                check(nums,tp,vis);
                tp.pop_back();
                vis[i]=0;
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        check(nums,{},vis);
        
        return ans;
    }
};