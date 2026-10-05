class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int i=0,ans=0,maxi=0;
        for(int j=0;j<s.size();j++){
            m[s[j]]++;
            maxi=max(maxi,m[s[j]]);
            while(j-i+1-maxi>k){
                m[s[i]]--;
                // maxi=max(maxi,m[s[j]]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};