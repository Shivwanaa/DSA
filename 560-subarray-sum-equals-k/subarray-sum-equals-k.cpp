class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans=0,s=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
            if(m.find(s-k)!=m.end()){
                ans=ans+m[s-k];
            }
            
            m[s]++;
            
        }
        return ans;
    }
};