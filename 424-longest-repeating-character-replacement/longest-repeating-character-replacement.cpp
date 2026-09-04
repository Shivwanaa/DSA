class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        unordered_map<char,int>m;
        int l=0;
        int ans=0;
        for(int j=0;j<s.size();j++){
            m[s[j]]++;
            l=max(l,m[s[j]]);
            while(i<j && j-i+1-l>k){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};