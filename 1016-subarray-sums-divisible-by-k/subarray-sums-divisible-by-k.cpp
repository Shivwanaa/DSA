class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int s=0;
        int ans=0;
        int a;
        for(int i=0;i<nums.size();i++){
            s=(s+nums[i])%k;
            if(s<0){
                a=k+s;
            }
            else{
                a=s;
            }
            if(m.find(a)!=m.end()){
                ans=ans+m[a];
                m[a]++;
            }
            else{
                m[a]=1;
            }
            
        }
        return ans;
    }
};