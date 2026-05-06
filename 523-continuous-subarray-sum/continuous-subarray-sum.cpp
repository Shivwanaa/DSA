class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int s=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            s=(s+nums[i])%k;
            if(s==0 && i){
                return true;
            }
            if(m.find(s)!=m.end()){
                if(i-m[s]>=2){
                    return true;
                }
            }
            else{
            m[s]=i;
            }
        }
        return false;
    }
};