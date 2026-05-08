class Solution {
public:
vector<vector<int>>ans;
    void check(vector<int>& nums,vector<int>tp,int i,vector<int>fr){
        if(tp.size()==nums.size()){
            ans.push_back(tp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!fr[j]){
            tp.push_back(nums[j]);
            fr[j]=1;
            check(nums,tp,j,fr);
            tp.pop_back();
            fr[j]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>tp;
        vector<int>fr(nums.size(),0);
        check(nums,tp,0,fr);
        return ans;
    }
};