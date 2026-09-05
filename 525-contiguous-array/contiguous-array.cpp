class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int s=0,ans=0;
        int j=0;
        
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==1){
                s=s+1;
            }
            else{
                s=s-1;
            }
            cout<<s<<endl;
            if(m.find(s)!=m.end()){
                ans=max(ans, i-m[s]);
            }
            else
            m[s]=i;
        }
        return ans;
    }
};