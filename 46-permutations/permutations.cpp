class Solution {
public:
vector<vector<int>>ans;
    void check(int i,vector<int>& nums,vector<int>t,vector<bool>v){
        if(t.size()==nums.size()){
            ans.push_back(t);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!v[j]){
            t.push_back(nums[j]);
            v[j]=true;
            check(j,nums,t,v);
            t.pop_back();
            v[j]=false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>t;
        vector<bool>v(nums.size(),false);
        check(0,nums,t,v);
        return ans;
    }
};