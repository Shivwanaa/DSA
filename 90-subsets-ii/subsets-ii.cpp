class Solution {
public:
vector<vector<int>>ans;
    void check(int i,vector<int>& nums,vector<int>tp){
        if(i==nums.size()){
            ans.push_back(tp);
            return;
        }
        tp.push_back(nums[i]);
        check(i+1,nums,tp);
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        tp.pop_back();
        check(i+1,nums,tp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        check(0,nums,{});
        return ans;
    }
};