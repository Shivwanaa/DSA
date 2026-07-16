class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        unordered_map<char,int>m;
        int ans=0;
        for(int j=0;j<s.size();j++){
            while(i<j && m.find(s[j])!=m.end()){
                m.erase(s[i]);
                i++;
            }
            m[s[j]]++;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};