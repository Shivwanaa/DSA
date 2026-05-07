class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        unordered_set<char>m;
        int l=0;
        int ans=0;
        for(int j=0;j<s.size();j++){
            while(m.count(s[j])){
                m.erase(s[i]);
                i++;
            }
            m.insert(s[j]);
            l=j-i+1;
            ans=max(ans,l);
        }
        return ans;
    }
};