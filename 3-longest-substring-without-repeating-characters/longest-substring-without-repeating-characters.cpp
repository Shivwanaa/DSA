class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>v;
        int i=0,ans=0;
        for(int j=0;j<s.size();j++){
            while(v.count(s[j])){
                v.erase(s[i]);
                i++;
            }
            v.insert(s[j]);
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};