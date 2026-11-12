class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>pm(26,0);
        vector<int>sm(26,0);
        for(auto i:p){
            pm[i-'a']++;
        }
        int i=0;
        vector<int>ans;
        for(int j=0;j<s.size();j++){
            sm[s[j]-'a']++;
            if(j-i+1==p.size()){
                if(sm==pm){
                    ans.push_back(i);
                }
                sm[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};