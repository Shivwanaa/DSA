class Solution {
public:
vector<vector<int>>ans;
set<vector<int>>pans;
    void check(int i,vector<int>& nums,vector<int>t,vector<int>v){
        if(t.size()==nums.size()){
            pans.insert(t);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(v[j]==0){
            v[j]=1;
            t.push_back(nums[j]);
            check(i,nums,t,v);
            t.pop_back();
            v[j]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>t;
        vector<int>v(nums.size(),0);
        check(0,nums,t,v);
        for(auto i:pans){
            ans.push_back(i);
        }
        return ans;
    }
};