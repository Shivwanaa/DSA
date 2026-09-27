class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>v;
        for(auto i:nums){
            v.insert(i);
        }
        int ans=0;
        int l=1;
        for(auto element:v){
            l=1;
            if(!v.count(element-1)){
                int end=element;
                while(v.count(end+1)){
                    l++;
                    end=end+1;
                }
                ans=max(ans,l);
            }

        }
        return ans;
    }
};