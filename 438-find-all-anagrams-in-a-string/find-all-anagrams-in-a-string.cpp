class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>m;
        for(auto i:p){
            m[i]++;
        }
        unordered_map<char,int>mp;
        int i=0,j=0;
        for( j=0;j<s.size();j++){
            mp[s[j]]++;
            if(j-i+1==p.size()){
                if(mp==m){
                ans.push_back(i);
                }
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        if(j-i+1==p.size()){
    if(mp==m){
        ans.push_back(i);
    }
    mp[s[i]]--;
    if(mp[s[i]]==0){
        mp.erase(s[i]);
        i++;
    }
}
        return ans;
    }
};