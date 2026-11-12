class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>pm;
        unordered_map<char,int>sm;
        for(auto i:p){
            pm[i]++;
        }
        int i=0;
        vector<int>ans;
        for(int j=0;j<s.size();j++){
            sm[s[j]]++;
            if(j-i+1==p.size()){
                if(sm==pm){
                    ans.push_back(i);
                }
                sm[s[i]]--;
                if(sm[s[i]]==0){
                    sm.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};