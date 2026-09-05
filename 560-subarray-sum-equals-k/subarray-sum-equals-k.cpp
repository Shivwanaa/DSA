class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0;
        int ans=0;
        int s=0;
        
        unordered_map<int,int>m;
        m[0]=1;
        for(int j=0;j<nums.size();j++){
            s=s+nums[j];
            if(m.find(s-k)!=m.end()){
                ans=ans+m[s-k];
            }
            m[s]++;
        }
        return ans;
    }
};