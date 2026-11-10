class Solution {
public:
set<vector<int>>an;
    void check(vector<int>& nums,vector<int>tp,vector<int>vis){
        if(tp.size()==nums.size()){
            an.insert(tp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                tp.push_back(nums[i]);
                check(nums,tp,vis);
                tp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        check(nums,{},vis);
        vector<vector<int>>ans;
        for(auto i:an){
            ans.push_back(i);
        }
        return ans;
    }
};