class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        unordered_map<char,int>m;
        int ans=0;
        int n=s.size()-1;
        for(int j=0;j<s.size();j++){
            m[s[j]]++;
            while(m.size()==3){
                ans+=n-j+1;
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};