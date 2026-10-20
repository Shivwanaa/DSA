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
        tp.pop_back();
        check(i+1,nums,tp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        check(0,nums,{});
        return ans;
    }
};