class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>v;
        for(auto i:nums){
            v.insert(i);
        }
        int ans=0;
        int a=0;
        int l=0;
        for(auto i:v){
            if(!v.count(i-1)){
                a=i;
                l=0;
                while(v.count(a)){
                    l++;
                    a++;
                }
            }
            ans=max(ans,l);
        }
        return ans;
    }
};