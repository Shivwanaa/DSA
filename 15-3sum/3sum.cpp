class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int h=nums.size()-1;
            while(l<h){
                int s=nums[i]+nums[l]+nums[h];
                if(s==0){
                    ans.push_back({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                    while(l<h && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(l<h && nums[h]==nums[h+1]){
                        h--;
                    }
                }
                else if(s>0){
                    h--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};