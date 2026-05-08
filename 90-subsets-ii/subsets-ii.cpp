class Solution {
public:
vector<vector<int>>ans;
    void check(vector<int>& nums,vector<int>tp,int i){
        if(i==nums.size()){
            ans.push_back(tp);
            return;
        }
        tp.push_back(nums[i]);
        check(nums,tp,i+1);
        tp.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        check(nums,tp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>tp;
        sort(nums.begin(),nums.end());
        check(nums,tp,0);
        return ans;
    }
};