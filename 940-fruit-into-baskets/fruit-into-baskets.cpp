class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int ans=0;
        int i=0;
        unordered_map<int,int>m;
        for(int j=0;j<nums.size();j++){
            m[nums[j]]++;
            if(m.size()>2){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            cout<<j<<" "<<i<<endl;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};