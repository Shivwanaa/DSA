class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int s=0;
        unordered_map<int,int>m;
        for(int j=0;j<nums.size();j++){
            s=s+nums[j];
            if(s==goal){
                ans++;
            }
            if(m.find(s-goal)!=m.end()){
                ans=ans+m[s-goal];
            }
            m[s]++;
        }
        return ans;
    }
};