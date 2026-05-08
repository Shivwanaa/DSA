class Solution {
public:
vector<vector<int>>ans;
    void check(vector<int>& nums,vector<int>tp,unordered_map<int,int>&m){
        if(tp.size()==nums.size()){
            ans.push_back(tp);
            return;
        }
        //1-2
        //2-1
        for(auto &i:m){
            if(i.second==0){
                continue;
            }
            tp.push_back(i.first);
            m[i.first]--;
            check(nums,tp,m);
            tp.pop_back();
            m[i.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>tp;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        // vector<int>freq(nums.size(),0);
        check(nums,tp,m);
        return ans;
    }
};